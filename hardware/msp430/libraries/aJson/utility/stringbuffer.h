/*
 * aJson
 * stringbuffer.h
 *
 *  http://interactive-matter.org/
 *
 *  This file is part of aJson.
 *
 *  aJson is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  aJson is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with aJson.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Created on: 14.10.2010
 *      Author: marcus
 */

#ifndef STRINGBUFFER_H_
#define STRINGBUFFER_H_

typedef struct
{
  char* string;
  unsigned int memory;
  unsigned int string_length;
} string_buffer;

#ifdef __cplusplus
extern "C"
{
#endif

  string_buffer*
  stringBufferCreate(void);

  char
  stringBufferAdd(char value, string_buffer* buffer);

  char*
  stringBufferToString(string_buffer* buffer);

  void
  stringBufferFree(string_buffer* buffer);

#ifdef __cplusplus
}
#endif
#endif /* STRINGBUFFER_H_ */
