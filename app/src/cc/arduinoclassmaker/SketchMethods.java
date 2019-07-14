/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: Jun 3, 2019
  *Assignment: Personal Study, provides static methods useful in parsing an
  *Arduino Sketch into a format useful to create an Arduino Class
  *Bugs:
  *Sources:
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class SketchMethods {
	/**
	 * Parses a one line comment in the sketch
	 * @param temp the line of the sketch that could be a comment
	 * @param scanner the MiniScanner that iterates over the sketch
	 * @return the comment string or blank if temp wasn't a comment
	 */
	public static String[] checkForComment(String temp,MiniScanner scanner) {
		//make array to hold comment and temp string
		String []commentTemp=new String[2];
		//if temp is a comment, parse it and make temp the next line
		if(temp.contains("//")) {
			//remove comment characters and add to comment
			commentTemp[0]=temp.substring(2, temp.length());
			//update the temp with the next input
			commentTemp[1]=scanner.next().replaceAll("\n", "");
		//otherwise make the common string blank, and the temp string is the same
		}else {
			commentTemp[0]="";
			commentTemp[1]=temp;
		}	
		//return the array of comment and temp strings
		return commentTemp;
	}
	
	/**
	 * Parses the header comment
	 * @param temp the string containing the first 
	 * @param scanner the Scanner object that iterates over the class
	 * @return the header comment String
	 */
	public static String parseHeaderComment(String temp,MiniScanner scanner) {
		String headerComment="";
		String tempCleaned=ArduinoParser.removeSpecialChars(temp);
		//keep adding the comment until the temp file is contained
		while(!tempCleaned.contains("*/")) {
			headerComment+=tempCleaned+"\n";
			tempCleaned=scanner.next().replaceAll("\n", "");
		}
		//add the last comment
		tempCleaned=ArduinoParser.removeSpecialChars(tempCleaned);
		headerComment+=tempCleaned;
		//remove formatting characters from header comment
		headerComment=ArduinoParser.removeWhiteSpace(headerComment);
		return headerComment;
	}
	
	/**
	 * Parses a method from sketch String and returns formatted method string
	 * @param temp the first line of the method
	 * @param scanner the MiniScanner object that iterates over the sketch
	 * @return a String representation of the method formatted for Arduino Class
	 * Generator
	 */
	public static String consumeAndFormatMethod(String temp, MiniScanner scanner) {
		//get the method into a string
		String methodBody=consumeMethod(temp,scanner);
		//format the method to be easily parsable
		return formatMethod(methodBody);
	}
	
	/**
	 * Returns the method iterated over
	 * @param temp the string containing the line
	 * @param scanner the scanner which iterates over the sketch
	 * @return the method represented as a string
	 */
	public static String consumeMethod(String temp,MiniScanner scanner) {
		//a string of methods, used here as return and also to search for brackets
		String method=temp;
		//loop as long as the closing index isn't found yet
		while(ArduinoParser.getClosingIndex(method, 0)==-1) {
			//get a new string to search
			temp=scanner.next();
			//add the temp string to the method string
			method+="\n"+temp;
		}
		//add last line
		temp=temp.replaceAll("\r","");
		//duck tape fix for extra bracket
		temp=temp.replaceAll("}", "");
		method+=temp;
		return method;
	}
	
	/**
	 * 
	 * @param methodString a string representation of the method
	 * @return a formatted version of the method suitable for Arduino class generator
	 */
	public static String formatMethod(String methodString) {
		//create a parsed method object to format the method string
		ParsedMethod p=new ParsedMethod(methodString);
		//retunr the tostring of parsedMethod object
		return p.toString();
	}
	
	/**helper method to remove problem characters
	 * @return the variables with problem characters removed
	 */
	public static String cleanVariables(String variables) {
		return variables.replaceAll("\r","").replaceAll(";", "").replaceAll("\r\r\r", "");
	}
}
