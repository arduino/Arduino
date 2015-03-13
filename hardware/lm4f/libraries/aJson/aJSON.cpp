/*
 Copyright (c) 2001, Interactive Matter, Marcus Nowotny

 Based on the cJSON Library, Copyright (C) 2009 Dave Gamble

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

// aJSON
// aJson Library for Arduino.
// This library is suited for Atmega328 based Arduinos.
// The RAM on ATmega168 based Arduinos is too limited

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <ctype.h>
#include <avr/pgmspace.h>

#include "aJSON.h"
#include "utility/stringbuffer.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/
//Default buffer sizes - buffers get initialized and grow acc to that size
#define BUFFER_DEFAULT_SIZE 4

//how much digits after . for float
#define FLOAT_PRECISION 5


bool
aJsonStream::available()
{
  if (bucket != EOF)
    return true;
  while (stream()->available())
    {
      /* Make an effort to skip whitespace. */
      int ch = this->getch();
      if (ch > 32)
       {
	 this->ungetch(ch);
	 return true;
       }
    }
  return false;
}

int
aJsonStream::getch()
{
  if (bucket != EOF)
    {
      int ret = bucket;
      bucket = EOF;
      return ret;
    }
  // In case input was malformed - can happen, this is the
  // real world, we can end up in a situation where the parser
  // would expect another character and end up stuck on
  // stream()->available() forever, hence the 500ms timeout.
  unsigned long i= millis()+500;
  while ((!stream()->available()) && (millis() < i)) /* spin with a timeout*/;
  return stream()->read();
}

void
aJsonStream::ungetch(char ch)
{
  bucket = ch;
}

size_t
aJsonStream::write(uint8_t ch)
{
  return stream()->write(ch);
}

size_t
aJsonStream::readBytes(uint8_t *buffer, size_t len)
{
  for (size_t i = 0; i < len; i++)
    {
      int ch = this->getch();
      if (ch == EOF)
	{
	  return i;
	}
      buffer[i] = ch;
    }
  return len;
}


int
aJsonClientStream::getch()
{
  if (bucket != EOF)
    {
      int ret = bucket;
      bucket = EOF;
      return ret;
    }
  while (!stream()->available() && stream()->connected()) /* spin */;
  if (!stream()->available()) // therefore, !stream()->connected()
    {
      stream()->stop();
      return EOF;
    }
  return stream()->read();
}

bool
aJsonStringStream::available()
{
  if (bucket != EOF)
    return true;
  return inbuf_len > 0;
}

int
aJsonStringStream::getch()
{
  if (bucket != EOF)
    {
      int ret = bucket;
      bucket = EOF;
      return ret;
    }
  if (!inbuf || !inbuf_len)
    {
      return EOF;
    }
  char ch = *inbuf++;
  inbuf_len--;
  return ch;
}

size_t
aJsonStringStream::write(uint8_t ch)
{
  if (!outbuf || outbuf_len <= 1)
    {
      return 0;
    }
  *outbuf++ = ch; outbuf_len--;
  *outbuf = 0;
  return 1;
}


// Internal constructor.
aJsonObject*
aJsonClass::newItem()
{
  aJsonObject* node = (aJsonObject*) malloc(sizeof(aJsonObject));
  if (node)
    memset(node, 0, sizeof(aJsonObject));
  return node;
}

// Delete a aJsonObject structure.
void
aJsonClass::deleteItem(aJsonObject *c)
{
  aJsonObject *next;
  while (c)
    {
      next = c->next;
      if (!(c->type & aJson_IsReference) && c->child)
        {
          deleteItem(c->child);
        }
      if ((c->type == aJson_String) && c->valuestring)
        {
          free(c->valuestring);
        }
      if (c->name)
        {
          free(c->name);
        }
      free(c);
      c = next;
    }
}

// Parse the input text to generate a number, and populate the result into item.
int
aJsonStream::parseNumber(aJsonObject *item)
{
  int i = 0;
  int sign = 1;

  int in = this->getch();
  if (in == EOF)
    {
      return EOF;
    }
  // It is easier to decode ourselves than to use sscnaf,
  // since so we can easier decide between int & double
  if (in == '-')
    {
      //it is a negative number
      sign = -1;
      in = this->getch();
      if (in == EOF)
        {
          return EOF;
        }
    }
  if (in >= '0' && in <= '9')
    do
      {
        i = (i * 10) + (in - '0');
        in = this->getch();
      }
    while (in >= '0' && in <= '9'); // Number?
  //end of integer part � or isn't it?
  if (!(in == '.' || in == 'e' || in == 'E'))
    {
      item->valueint = i * (int) sign;
      item->type = aJson_Int;
    }
  //ok it seems to be a double
  else
    {
      double n = (double) i;
      int scale = 0;
      int subscale = 0;
      char signsubscale = 1;
      if (in == '.')
        {
          in = this->getch();
          do
            {
              n = (n * 10.0) + (in - '0'), scale--;
              in = this->getch();
            }
          while (in >= '0' && in <= '9');
        } // Fractional part?
      if (in == 'e' || in == 'E') // Exponent?
        {
          in = this->getch();
          if (in == '+')
            {
              in = this->getch();
            }
          else if (in == '-')
            {
              signsubscale = -1;
              in = this->getch();
            }
          while (in >= '0' && in <= '9')
            {
              subscale = (subscale * 10) + (in - '0'); // Number?
              in = this->getch();
            }
        }

      n = sign * n * powf((double)10.0,double(((double) scale + (double) subscale
          * (double) signsubscale))); // number = +/- number.fraction * 10^+/- exponent
        

      item->valuefloat = n;
      item->type = aJson_Float;
    }
  //preserve the last character for the next routine
  this->ungetch(in);
  return 0;
}

// Render the number nicely from the given item into a string.
int
aJsonStream::printInt(aJsonObject *item)
{
  if (item != NULL)
    {
      return this->print(item->valueint, DEC);
    }
  //printing nothing is ok
  return 0;
}

int
aJsonStream::printFloat(aJsonObject *item)
{
  if (item != NULL)
    {
      double d = item->valuefloat;
      if (d<0.0) {
	  this->print("-");
          d=-d;
      }
      //print the integer part
      unsigned long integer_number = (unsigned long)d;
      this->print(integer_number, DEC);
      this->print(".");
      //print the fractional part
      double fractional_part = d - ((double)integer_number);
      //we do a do-while since we want to print at least one zero
      //we just support a certain number of digits after the '.'
      int n = FLOAT_PRECISION;
      fractional_part += 0.5/pow(10.0, FLOAT_PRECISION);
      do {
          //make the first digit non fractional(shift it before the '.'
          fractional_part *= 10.0;
          //create an int out of it
          unsigned int digit = (unsigned int) fractional_part;
          //print it
	  this->print(digit, DEC);
          //remove it from the number
          fractional_part -= (double)digit;
          n--;
      } while ((fractional_part!=0) && (n>0));
    }
  //printing nothing is ok
  return 0;
}

// Parse the input text into an unescaped cstring, and populate item.
int
aJsonStream::parseString(aJsonObject *item)
{
  //we do not need to skip here since the first byte should be '\"'
  int in = this->getch();
  if (in != '\"')
    {
      return EOF; // not a string!
    }
  item->type = aJson_String;
  //allocate a buffer & track how long it is and how much we have read
  string_buffer* buffer = stringBufferCreate();
  if (buffer == NULL)
    {
      //unable to allocate the string
      return EOF;
    }
  in = this->getch();
  if (in == EOF)
    {
      stringBufferFree(buffer);
      return EOF;
    }
  while (in != EOF)
    {
      while (in != '\"' && in >= 32)
        {
          if (in != '\\')
            {
              stringBufferAdd((char) in, buffer);
            }
          else
            {
              in = this->getch();
              if (in == EOF)
                {
                  stringBufferFree(buffer);
                  return EOF;
                }
              switch (in)
                {
              case '\\':
                stringBufferAdd('\\', buffer);
                break;
              case '\"':
                stringBufferAdd('\"', buffer);
                break;
              case '/':
                stringBufferAdd('/', buffer);
                break;
              case 'b':
                stringBufferAdd('\b', buffer);
                break;
              case 'f':
                stringBufferAdd('\f', buffer);
                break;
              case 'n':
                stringBufferAdd('\n', buffer);
                break;
              case 'r':
                stringBufferAdd('\r', buffer);
                break;
              case 't':
                stringBufferAdd('\t', buffer);
                break;
              default:
                //we do not understand it so we skip it
                break;
                }
            }
          in = this->getch();
          if (in == EOF)
            {
              stringBufferFree(buffer);
              return EOF;
            }
        }
      //the string ends here
      item->valuestring = stringBufferToString(buffer);
      return 0;
    }
  //we should not be here but it is ok
  return 0;
}

// Render the cstring provided to an escaped version that can be printed.
int
aJsonStream::printStringPtr(const char *str)
{
  this->print("\"");
  char* ptr = (char*) str;
  if (ptr != NULL)
    {
      while (*ptr != 0)
        {
          if ((unsigned char) *ptr > 31 && *ptr != '\"' && *ptr != '\\')
            {
	      this->print(*ptr);
              ptr++;
            }
          else
            {
	      this->print('\\');
              switch (*ptr++)
                {
              case '\\':
		this->print('\\');
                break;
              case '\"':
		this->print('\"');
                break;
              case '/':
		this->print('/');
                break;
              case '\b':
		this->print('b');
                break;
              case '\f':
		this->print('f');
                break;
              case '\n':
		this->print('n');
                break;
              case '\r':
		this->print('r');
                break;
              case '\t':
		this->print('t');
                break;
              default:
                break; // eviscerate with prejudice.
                }
            }

        }
    }
  this->print('\"');
  return 0;
}

// Invote print_string_ptr (which is useful) on an item.
int
aJsonStream::printString(aJsonObject *item)
{
  return this->printStringPtr(item->valuestring);
}

// Utility to jump whitespace and cr/lf
int
aJsonStream::skip()
{
  int in = this->getch();
  while (in != EOF && (in <= 32))
    {
      in = this->getch();
    }
  if (in != EOF)
    {
      this->ungetch(in);
      return 0;
    }
  return EOF;
}

// Utility to flush our buffer in case it contains garbage
// since the parser will return the buffer untouched if it
// cannot understand it.
int
aJsonStream::flush()
{
  int in = this->getch();
  while(in != EOF)
  {
    in = this->getch();
  }
  return EOF;
}


// Parse an object - create a new root, and populate.
aJsonObject*
aJsonClass::parse(char *value)
{
  aJsonStringStream stringStream(value, NULL);
  aJsonObject* result = parse(&stringStream);
  return result;
}

// Parse an object - create a new root, and populate.
aJsonObject*
aJsonClass::parse(aJsonStream* stream)
{
  return parse(stream, NULL);
}

// Parse an object - create a new root, and populate.
aJsonObject*
aJsonClass::parse(aJsonStream* stream, char** filter)
{
  if (stream == NULL)
    {
      return NULL;
    }
  aJsonObject *c = newItem();
  if (!c)
    return NULL; /* memory fail */

  stream->skip();
  if (stream->parseValue(c, filter) == EOF)
    {
      deleteItem(c);
      return NULL;
    }
  return c;
}

// Render a aJsonObject item/entity/structure to text.
int
aJsonClass::print(aJsonObject* item, aJsonStream* stream)
{
  return stream->printValue(item);
}

char*
aJsonClass::print(aJsonObject* item)
{
  char* outBuf = (char*) malloc(PRINT_BUFFER_LEN); /* XXX: Dynamic size. */
  if (outBuf == NULL)
    {
      return NULL;
    }
  aJsonStringStream stringStream(NULL, outBuf, PRINT_BUFFER_LEN);
  print(item, &stringStream);
  return outBuf;
}

// Parser core - when encountering text, process appropriately.
int
aJsonStream::parseValue(aJsonObject *item, char** filter)
{
  if (this->skip() == EOF)
    {
      return EOF;
    }
  //read the first byte from the stream
  int in = this->getch();
  if (in == EOF)
    {
      return EOF;
    }
  this->ungetch(in);
  if (in == '\"')
    {
      return this->parseString(item);
    }
  else if (in == '-' || (in >= '0' && in <= '9'))
    {
      return this->parseNumber(item);
    }
  else if (in == '[')
    {
      return this->parseArray(item, filter);
    }
  else if (in == '{')
    {
      return this->parseObject(item, filter);
    }
  //it can only be null, false or true
  else if (in == 'n')
    {
      //a buffer to read the value
      char buffer[] =
        { 0, 0, 0, 0 };
      if (this->readBytes((uint8_t*) buffer, 4) != 4)
        {
          return EOF;
        }
      if (!strncmp(buffer, "null", 4))
        {
          item->type = aJson_NULL;
          return 0;
        }
      else
        {
          return EOF;
        }
    }
  else if (in == 'f')
    {
      //a buffer to read the value
      char buffer[] =
        { 0, 0, 0, 0, 0 };
      if (this->readBytes((uint8_t*) buffer, 5) != 5)
        {
          return EOF;
        }
      if (!strncmp(buffer, "false", 5))
        {
          item->type = aJson_Boolean;
          item->valuebool = false;
          return 0;
        }
    }
  else if (in == 't')
    {
      //a buffer to read the value
      char buffer[] =
        { 0, 0, 0, 0 };
      if (this->readBytes((uint8_t*) buffer, 4) != 4)
        {
          return EOF;
        }
      if (!strncmp(buffer, "true", 4))
        {
          item->type = aJson_Boolean;
          item->valuebool = true;
          return 0;
        }
    }

  return EOF; // failure.
}

// Render a value to text.
int
aJsonStream::printValue(aJsonObject *item)
{
  int result = 0;
  if (item == NULL)
    {
      //nothing to do
      return 0;
    }
  switch (item->type)
    {
  case aJson_NULL:
    result = this->print("null");
    break;
  case aJson_Boolean:
    if(item->valuebool){
      result = this->print("true");
    }
    else{
      result = this->print("false");
    }
    break;
  case aJson_Int:
    result = this->printInt(item);
    break;
  case aJson_Float:
    result = this->printFloat(item);
    break;
  case aJson_String:
    result = this->printString(item);
    break;
  case aJson_Array:
    result = this->printArray(item);
    break;
  case aJson_Object:
    result = this->printObject(item);
    break;
    }
  return result;
}

// Build an array from input text.
int
aJsonStream::parseArray(aJsonObject *item, char** filter)
{
  int in = this->getch();
  if (in != '[')
    {
      return EOF; // not an array!
    }

  item->type = aJson_Array;
  this->skip();
  in = this->getch();
  //check for empty array
  if (in == ']')
    {
      return 0; // empty array.
    }
  //now put back the last character
  this->ungetch(in);
  aJsonObject *child;
  char first = -1;
  while ((first) || (in == ','))
    {
      aJsonObject *new_item = aJsonClass::newItem();
      if (new_item == NULL)
        {
          return EOF; // memory fail
        }
      if (first)
        {
          item->child = new_item;
          first = 0;
        }
      else
        {
          child->next = new_item;
          new_item->prev = child;
        }
      child = new_item;
      this->skip();
      if (this->parseValue(child, filter))
        {
          return EOF;
        }
      this->skip();
      in = this->getch();
    }
  if (in == ']')
    {
      return 0; // end of array
    }
  else
    {
      return EOF; // malformed.
    }
}

// Render an array to text
int
aJsonStream::printArray(aJsonObject *item)
{
  if (item == NULL)
    {
      //nothing to do
      return 0;
    }
  aJsonObject *child = item->child;
  if (this->print('[') == EOF)
    {
      return EOF;
    }
  while (child)
    {
      if (this->printValue(child) == EOF)
        {
          return EOF;
        }
      child = child->next;
      if (child)
        {
          if (this->print(',') == EOF)
            {
              return EOF;
            }
        }
    }
  if (this->print(']') == EOF)
    {
      return EOF;
    }
  return 0;
}

// Build an object from the text.
int
aJsonStream::parseObject(aJsonObject *item, char** filter)
{
  int in = this->getch();
  if (in != '{')
    {
      return EOF; // not an object!
    }

  item->type = aJson_Object;
  this->skip();
  //check for an empty object
  in = this->getch();
  if (in == '}')
    {
      return 0; // empty object.
    }
  //preserve the char for the next parser
  this->ungetch(in);

  aJsonObject* child;
  char first = -1;
  while ((first) || (in == ','))
    {
      aJsonObject* new_item = aJsonClass::newItem();
      if (new_item == NULL)
        {
          return EOF; // memory fail
        }
      if (first)
        {
          first = 0;
          item->child = new_item;
        }
      else
        {
          child->next = new_item;
          new_item->prev = child;
        }
      child = new_item;
      this->skip();
      if (this->parseString(child) == EOF)
        {
          return EOF;
        }
      this->skip();
      child->name = child->valuestring;
      child->valuestring = NULL;

      in = this->getch();
      if (in != ':')
        {
          return EOF; // fail!
        }
      // skip any spacing, get the value.
      this->skip();
      if (this->parseValue(child, filter) == EOF)
        {
          return EOF;
        }
      this->skip();
      in = this->getch();
    }

  if (in == '}')
    {
      return 0; // end of array
    }
  else
    {
      return EOF; // malformed.
    }
}

// Render an object to text.
int
aJsonStream::printObject(aJsonObject *item)
{
  if (item == NULL)
    {
      //nothing to do
      return 0;
    }
  aJsonObject *child = item->child;
  if (this->print('{') == EOF)
    {
      return EOF;
    }
  while (child)
    {
      if (this->printStringPtr(child->name) == EOF)
        {
          return EOF;
        }
      if (this->print(':') == EOF)
        {
          return EOF;
        }
      if (this->printValue(child) == EOF)
        {
          return EOF;
        }
      child = child->next;
      if (child)
        {
          if (this->print(',') == EOF)
            {
              return EOF;
            }
        }
    }
  if (this->print('}') == EOF)
    {
      return EOF;
    }
  return 0;
}

// Get Array size/item / object item.
unsigned char
aJsonClass::getArraySize(aJsonObject *array)
{
  aJsonObject *c = array->child;
  unsigned char i = 0;
  while (c)
    i++, c = c->next;
  return i;
}
aJsonObject*
aJsonClass::getArrayItem(aJsonObject *array, unsigned char item)
{
  aJsonObject *c = array->child;
  while (c && item > 0)
    item--, c = c->next;
  return c;
}
aJsonObject*
aJsonClass::getObjectItem(aJsonObject *object, const char *string)
{
  aJsonObject *c = object->child;
  while (c && strcasecmp(c->name, string))
    c = c->next;
  return c;
}

// Utility for array list handling.
void
aJsonClass::suffixObject(aJsonObject *prev, aJsonObject *item)
{
  prev->next = item;
  item->prev = prev;
}
// Utility for handling references.
aJsonObject*
aJsonClass::createReference(aJsonObject *item)
{
  aJsonObject *ref = newItem();
  if (!ref)
    return 0;
  memcpy(ref, item, sizeof(aJsonObject));
  ref->name = 0;
  ref->type |= aJson_IsReference;
  ref->next = ref->prev = 0;
  return ref;
}

// Add item to array/object.
void
aJsonClass::addItemToArray(aJsonObject *array, aJsonObject *item)
{
  aJsonObject *c = array->child;
  if (!item)
    return;
  if (!c)
    {
      array->child = item;
    }
  else
    {
      while (c && c->next)
        c = c->next;
      suffixObject(c, item);
    }
}
void
aJsonClass::addItemToObject(aJsonObject *object, const char *string,
    aJsonObject *item)
{
  if (!item)
    return;
  if (item->name)
    free(item->name);
  item->name = strdup(string);
  addItemToArray(object, item);
}
void
aJsonClass::addItemReferenceToArray(aJsonObject *array, aJsonObject *item)
{
  addItemToArray(array, createReference(item));
}
void
aJsonClass::addItemReferenceToObject(aJsonObject *object, const char *string,
    aJsonObject *item)
{
  addItemToObject(object, string, createReference(item));
}

aJsonObject*
aJsonClass::detachItemFromArray(aJsonObject *array, unsigned char which)
{
  aJsonObject *c = array->child;
  while (c && which > 0)
    c = c->next, which--;
  if (!c)
    return 0;
  if (c->prev)
    c->prev->next = c->next;
  if (c->next)
    c->next->prev = c->prev;
  if (c == array->child)
    array->child = c->next;
  c->prev = c->next = 0;
  return c;
}
void
aJsonClass::deleteItemFromArray(aJsonObject *array, unsigned char which)
{
  deleteItem(detachItemFromArray(array, which));
}
aJsonObject*
aJsonClass::detachItemFromObject(aJsonObject *object, const char *string)
{
  unsigned char i = 0;
  aJsonObject *c = object->child;
  while (c && strcasecmp(c->name, string))
    i++, c = c->next;
  if (c)
    return detachItemFromArray(object, i);
  return 0;
}
void
aJsonClass::deleteItemFromObject(aJsonObject *object, const char *string)
{
  deleteItem(detachItemFromObject(object, string));
}

// Replace array/object items with new ones.
void
aJsonClass::replaceItemInArray(aJsonObject *array, unsigned char which,
    aJsonObject *newitem)
{
  aJsonObject *c = array->child;
  while (c && which > 0)
    c = c->next, which--;
  if (!c)
    return;
  newitem->next = c->next;
  newitem->prev = c->prev;
  if (newitem->next)
    newitem->next->prev = newitem;
  if (c == array->child)
    array->child = newitem;
  else
    newitem->prev->next = newitem;
  c->next = c->prev = 0;
  deleteItem(c);
}
void
aJsonClass::replaceItemInObject(aJsonObject *object, const char *string,
    aJsonObject *newitem)
{
  unsigned char i = 0;
  aJsonObject *c = object->child;
  while (c && strcasecmp(c->name, string))
    i++, c = c->next;
  if (c)
    {
      newitem->name = strdup(string);
      replaceItemInArray(object, i, newitem);
    }
}

// Create basic types:
aJsonObject*
aJsonClass::createNull()
{
  aJsonObject *item = newItem();
  if (item)
    item->type = aJson_NULL;
  return item;
}

aJsonObject*
aJsonClass::createItem(bool b)
{
  aJsonObject *item = newItem();
  if (item){
    item->type = aJson_Boolean;
    item->valuebool = b;
  }
    
  return item;
}

aJsonObject*
aJsonClass::createItem(char b)
{
  aJsonObject *item = newItem();
  if (item)
    {
      item->type = aJson_Boolean;
      item->valuebool = b ? -1 : 0;
    }
  return item;
}

aJsonObject*
aJsonClass::createItem(int num)
{
  aJsonObject *item = newItem();
  if (item)
    {
      item->type = aJson_Int;
      item->valueint = (int) num;
    }
  return item;
}

aJsonObject*
aJsonClass::createItem(double num)
{
  aJsonObject *item = newItem();
  if (item)
    {
      item->type = aJson_Float;
      item->valuefloat = num;
    }
  return item;
}

aJsonObject*
aJsonClass::createItem(const char *string)
{
  aJsonObject *item = newItem();
  if (item)
    {
      item->type = aJson_String;
      item->valuestring = strdup(string);
    }
  return item;
}

aJsonObject*
aJsonClass::createArray()
{
  aJsonObject *item = newItem();
  if (item)
    item->type = aJson_Array;
  return item;
}
aJsonObject*
aJsonClass::createObject()
{
  aJsonObject *item = newItem();
  if (item)
    item->type = aJson_Object;
  return item;
}

// Create Arrays:
aJsonObject*
aJsonClass::createIntArray(int *numbers, unsigned char count)
{
  unsigned char i;
  aJsonObject *n = 0, *p = 0, *a = createArray();
  for (i = 0; a && i < count; i++)
    {
      n = createItem(numbers[i]);
      if (!i)
        a->child = n;
      else
        suffixObject(p, n);
      p = n;
    }
  return a;
}

aJsonObject*
aJsonClass::createFloatArray(double *numbers, unsigned char count)
{
  unsigned char i;
  aJsonObject *n = 0, *p = 0, *a = createArray();
  for (i = 0; a && i < count; i++)
    {
      n = createItem(numbers[i]);
      if (!i)
        a->child = n;
      else
        suffixObject(p, n);
      p = n;
    }
  return a;
}

aJsonObject*
aJsonClass::createDoubleArray(double *numbers, unsigned char count)
{
  unsigned char i;
  aJsonObject *n = 0, *p = 0, *a = createArray();
  for (i = 0; a && i < count; i++)
    {
      n = createItem(numbers[i]);
      if (!i)
        a->child = n;
      else
        suffixObject(p, n);
      p = n;
    }
  return a;
}

aJsonObject*
aJsonClass::createStringArray(const char **strings, unsigned char count)
{
  unsigned char i;
  aJsonObject *n = 0, *p = 0, *a = createArray();
  for (i = 0; a && i < count; i++)
    {
      n = createItem(strings[i]);
      if (!i)
        a->child = n;
      else
        suffixObject(p, n);
      p = n;
    }
  return a;
}

void
aJsonClass::addNullToObject(aJsonObject* object, const char* name)
{
  addItemToObject(object, name, createNull());
}

void
aJsonClass::addBooleanToObject(aJsonObject* object, const char* name, bool b)
{
  addItemToObject(object, name, createItem(b));
}

void
aJsonClass::addNumberToObject(aJsonObject* object, const char* name, int n)
{
  addItemToObject(object, name, createItem(n));
}

void
aJsonClass::addNumberToObject(aJsonObject* object, const char* name, double n)
{
  addItemToObject(object, name, createItem(n));
}

void
aJsonClass::addStringToObject(aJsonObject* object, const char* name,
    const char* s)
{
  addItemToObject(object, name, createItem(s));
}

//TODO conversion routines btw. float & int types?

aJsonClass aJson;
