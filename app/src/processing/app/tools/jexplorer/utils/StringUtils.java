/*******************************************************************************
 * Copyright (c) 2020 Ricardo JL Rufino
 *
 * This library is distributed under  MIT License. See the included
 * LICENSE file for details.
 *******************************************************************************/
package processing.app.tools.jexplorer.utils;

import java.util.StringTokenizer;

public class StringUtils {
    
    // used by split, all the standard whitespace chars
    // (also includes unicode nbsp, that little bostage)

    static final String WHITESPACE = " \t\n\r\f\u00A0";
    
    /**
     * Split the provided String at wherever whitespace occurs. Multiple
     * whitespace (extra spaces or tabs or whatever) between items will count as a
     * single break.
     * <P>
     * The whitespace characters are "\t\n\r\f", which are the defaults for
     * java.util.StringTokenizer, plus the unicode non-breaking space character,
     * which is found commonly on files created by or used in conjunction with Mac
     * OS X (character 160, or 0x00A0 in hex).
     * 
     * <PRE>
     * i.e. splitTokens("a b") -> { "a", "b" }
     *      splitTokens("a    b") -> { "a", "b" }
     *      splitTokens("a\tb") -> { "a", "b" }
     *      splitTokens("a \t  b  ") -> { "a", "b" }
     * </PRE>
     */
    static public String[] splitTokens( String what ) {
        return splitTokens(what, WHITESPACE);
    }

    /**
     * Splits a string into pieces, using any of the chars in the String 'delim'
     * as separator characters. For instance, in addition to white space, you
     * might want to treat commas as a separator. The delimeter characters won't
     * appear in the returned String array.
     * 
     * <PRE>
     * i.e. splitTokens("a, b", " ,") -> { "a", "b" }
     * </PRE>
     * 
     * To include all the whitespace possibilities, use the variable WHITESPACE,
     * found in PConstants:
     * 
     * <PRE>
     * i.e. splitTokens("a   | b", WHITESPACE + "|");  ->  { "a", "b" }
     * </PRE>
     */
    static public String[] splitTokens( String what , String delim ) {
        StringTokenizer toker = new StringTokenizer(what, delim);
        String pieces[] = new String[toker.countTokens()];

        int index = 0;
        while (toker.hasMoreTokens()) {
            pieces[index++] = toker.nextToken();
        }
        return pieces;
    }
}
