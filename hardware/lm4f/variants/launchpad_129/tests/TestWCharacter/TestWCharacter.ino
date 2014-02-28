/* TestWCharacter
  Runs all the functions in WCharacter
*/

void setup() {
  int c;
  Serial.begin(9600);
  Serial.println("\nTestWCharacter setup");

  
  Serial.print("isAlpha             ");
  c = 'a';
  Serial.print(isAlpha(c));
  c = '1';
  Serial.print(isAlpha(c));
  Serial.println();

  Serial.print("isAlphaNumeric      ");
  c = '1';
  Serial.print(isAlphaNumeric(c));
  c = '$';
  Serial.print(isAlphaNumeric(c));
  Serial.println();

  Serial.print("isAscii             ");
  c = 79;
  Serial.print(isAscii(c));
  c = 7779;
  Serial.print(isAscii(c));
  Serial.println();

  Serial.print("isControl           ");
  c = '\t';
  Serial.print(isControl(c));
  c = 'a';
  Serial.print(isControl(c));
  Serial.println();

  Serial.print("isDigit             ");
  c = '0';
  Serial.print(isDigit(c));
  c = 'a';
  Serial.print(isDigit(c));
  Serial.println();

  Serial.print("isGraph             ");
  c = 'F';
  Serial.print(isGraph(c));
  c = ' ';
  Serial.print(isGraph(c));
  Serial.println();

  Serial.print("isHexadecimalDigit  ");
  c = 'F';
  Serial.print(isHexadecimalDigit(c));
  c = 'G';
  Serial.print(isHexadecimalDigit(c));
  Serial.println();

  Serial.print("isLowerCase         ");
  c = 'g';
  Serial.print(isLowerCase(c));
  c = 'G';
  Serial.print(isLowerCase(c));
  Serial.println();

  Serial.print("isPrintable         ");
  c = 'a';
  Serial.print(isPrintable(c));
  c = 199;
  Serial.print(isPrintable(c));
  Serial.println();

  Serial.print("isPunct             ");
  c = '!';
  Serial.print(isPunct(c));
  c = 'a';
  Serial.print(isPunct(c));
  Serial.println();

  Serial.print("isSpace             ");
  c = ' ';
  Serial.print(isSpace(c));
  c = 'a';
  Serial.print(isSpace(c));
  Serial.println();

  Serial.print("isUpperCase         ");
  c = 'G';
  Serial.print(isUpperCase(c));
  c = 'g';
  Serial.print(isUpperCase(c));
  Serial.println();

  Serial.print("isWhitespace        ");
  c = ' ';
  Serial.print(isWhitespace(c));
  c = 'G';
  Serial.print(isWhitespace(c));
  Serial.println();



/*
inline int toAscii(
inline int toLowerCase(
inline int toUpperCase(
*/

}


void loop() {
}

