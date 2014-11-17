/*
  LibMorseConf.h - Morse library configuration file.
  Created by Gilles De Vos, December 10, 2013.
  Released into the public domain.
*/

#ifndef LIBMORSECONF_H
#define LIBMORSECONF_H


#define LIB_MORSE_UNIT		100	//!< Time duration (ms) of elementary Morse code

// International Morse code elements
#define LIB_MORSE_DOT_DURATION	LIB_MORSE_UNIT	//!< Time duration (ms) of a dot
#define LIB_MORSE_DASH_DURATION	3*LIB_MORSE_UNIT	//!< Time duration (ms) of a dash
#define LIB_MORSE_INTR_CHAR_GAP	LIB_MORSE_UNIT	//!< Time duration (ms) between the dots and dashes within a character
#define LIB_MORSE_SHORT_GAP	3*LIB_MORSE_UNIT	//!< Time duration (ms) between characters
#define LIB_MORSE_MEDIUM_GAP	7*LIB_MORSE_UNIT	//!< Time duration (ms) between words

#define LIB_MORSE_ALPHABET_AVAILABLE  //!< Encoded characters are available

#endif //LIBMORSECONF_H