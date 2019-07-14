/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 23, 2019
  *Assignment:Personla Study, converts a string representation
  *of a method into fields like name, body, and location [private,public,example]
  *Bugs:
  *Sources:https://stackoverflow.com/questions/9260126/what-are-the-differences-between-char-literals-n-and-r-in-java
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class ParsedMethod {

	/**
	 * fields relevent to creating a method
	 */
	private String comment;
	private String returnType;
	private String methodName;
	private String parameters;
	private String body;
	
	/**
	 * creates a new ParsedMethod object
	 * @param methodRep a string representation of a method as it would
	 * appear in an Arduino Sketch
	 */
	public ParsedMethod(String methodRep) {
		//setup lineReader Scanner
		MiniScanner lineReader=setupScanner(methodRep);
		//load fields into memory
		loadComment(lineReader);
		MiniScanner wordReader=loadReturnType(lineReader);
		loadMethodName(wordReader);
		loadParameters(wordReader);
		loadBody(lineReader);
	}
	
	/**
	 * Sets up a MiniScanner depending on the newline character
	 * @return a MiniScanner that will iterate over the method line by line
	 */
	private MiniScanner setupScanner(String methodRep) {
		//create a scanner to iterate over line readers
		MiniScanner lineReader=new MiniScanner();
		//replace the r newlince character with the n newline character
		//otherwise the line iterator and unit test won't pass
		String cleanedMethod=methodRep.replaceAll("\r", "\n");
		//prime the MiniScanner to iterate line by line
		lineReader.prime(cleanedMethod, "\n");
		//return the lineReader object to be used by helper methods
		return lineReader;
	}
	
	/**
	 * @param lineReader the MiniScanner object that can iterate over the method
	 * Loads the comment into memory
	 */
	private void loadComment(MiniScanner lineReader) {
		//load the comment into memory
		comment=lineReader.next("comment");
		//remove slashes from comment
		comment=comment.replaceAll("/", "");
	}
	/**
	 * Prepare the scanners and iterate and go over the method header
	 * @param lineReader a scanner that iterates over hte method object
	 * @return a wordReader object capable of reading the rest of themethod header 
	 */
	private MiniScanner loadReturnType(MiniScanner lineReader) {
		//create scanner to get the next word
		MiniScanner wordReader=new MiniScanner();
		String line;
		//get the first line of the method
		line=lineReader.next("header");
		//trim spaces from the first line
		wordReader.prime(line.trim(), " ");
		//load the return type into memory
		returnType=wordReader.next("returnType");
		return wordReader;
	}
	
	/**
	 * loads the method name into memory
	 * @param wordReader the MiniScanner object to iterate over the method 
	 */
	private void loadMethodName(MiniScanner wordReader) {
		//get the rest of the method header for parsing, name and parameters
		String temp=wordReader.getRest();	
		//set up the scanner to get the first part of the header
		wordReader.prime(temp, "(");
		//load the method name into memory
		methodName=wordReader.next("methodName");
	}
	
	/*
	 * Loads the parameters of the method into memory
	 * @param wordReader a MiniScanner object that iterates over the method
	 */
	private void loadParameters(MiniScanner wordReader) {
		//get the rest of the method header which is parameters
		String temp=wordReader.getRest();
		//get the leftMost close paren for paremeters in case there is an extra paren in parameters
		int lastIndex=temp.lastIndexOf(")");
		//load the parameters into memory
		parameters=temp.substring(0, lastIndex);
	}
	
	/**
	 * Loads the method body into memory
	 * @param lineReader the MiniScanner object that will iterate over the method
	 */
	private void loadBody(MiniScanner lineReader) {
		//load the body into memory
		body=lineReader.getRest();
		//remove the closing bracket of the method
		int lastIndex=body.lastIndexOf("}");
		body=body.substring(0,lastIndex);
		//remove tab and extra whitespace characters from body
		body=ArduinoParser.removeWhiteSpace(body);
		//remove extra newline characters from the body
		body=body.replaceAll("\n\n", "\n");
	}
	
	/**
	 * @return a string representation of the object
	 * the tostring is formatted in the correct format
	 * that the arduino class generator needs
	 */
	public String toString() {
		return returnType+"|"+methodName+"|"+parameters+"|"+comment+"|\n"
				+body+"\n\n";
	}
	
	/**
	 * Shows the capabilites of the ParsedMethod class
	 * see ParsedMethod Unit test for more information
	 * @param args not used
	 */
	public static void main (String[]args) {
		System.out.println("Creating a string representation of the method:");
		String methodRep=
				 "//a test method to average two numbers\n"
				+"int average(int a, int b) {\n"
				+"  int sum=a+b;\n"
				+"  int average=sum/2;\n"
				+"  return average;\n"
		        +"}";
		System.out.println(methodRep);
		
		System.out.println("Creating a ParsedMethod object");
		ParsedMethod p=new ParsedMethod(methodRep);
		System.out.println(p);
	}

}
