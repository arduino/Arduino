package cc.ArduinoClassGenerator;

/** Name: Jacob Smith
Date: May 12 2019
Assignment: Personal study, allows the user to ecreate the cpp file given necessary information
using an inheritance schem to save code
Email: jsmith2021@brandeis.edu
Rights: Copyright (C) 2019 Jacob Smith
  		License is GPL-3.0, included in License.txt of this github project
*/

public class ArduinoClassCpp extends ArduinoClassMaster{
	
	/**
	* Loads an example class into memory with hardcoded date
	* and parses it into header comment, methods, header file
	*/
	public ArduinoClassCpp(String className,String author,String organization,boolean hardCodeDate,String headerComments,String supportedBoards,String variables,String privateMethods,String publicMethods){
		super(className,author,organization,hardCodeDate,headerComments,supportedBoards);
		init(className,supportedBoards,variables,publicMethods,privateMethods);
		
	}
	
	/**
	* Loads an example class into memory with automatic date
	* and parses it into header comment, methods, header file
	*/
	public ArduinoClassCpp(String className,String author,String organization,String headerComments,String supportedBoards,String variables,String privateMethods,String publicMethods){
		super(className,author,organization,headerComments,supportedBoards);
		init(className,supportedBoards,variables,publicMethods,privateMethods);
		
	}
	
	/**
	 * Helper method to intialize class specific methods and allow date to be hardcoded
	 */
	private void init(String className,String supportedBoards,String variables,String publicMethods, String privateMethods){
		arduinoClass+=super.generateBoardDefInitial(supportedBoards);
		arduinoClass+=super.startLibraryIncludes(variables, className)+"\n";
		publicMethods=generateConstructor(className,variables)+publicMethods;
		arduinoClass+=generateMethods(className,publicMethods,true);
		arduinoClass+=generateMethods(className,privateMethods,false);	
		arduinoClass+=generateBoardDefFinal();
	}
		
	/**
	 * Generates the body of the class constructor
	 * @return the formatted method of a constructor
	 */
	private String generateConstructor(String className,String variables) {
		//add an automatic comment for the constructor
		String constructor="|"+className+"||Creates a new "+className+" object|\n";
		MiniScanner varReader=new MiniScanner();
		MiniScanner valReader=new MiniScanner();
		varReader.prime(variables, "\n");
		String varLine;
		String name;
		String comment;
		String val;
		while(varReader.hasNext()) {
			varLine=varReader.next();
			valReader.prime(varLine,"|");
			//consumer type
			valReader.next("type");
			name=valReader.next("name");
			comment=valReader.next("comment");
			//if there is no variable value, use enum to generate to do message
			if(valReader.hasNext()) {
				val=valReader.next();
			}else {
				val=TODOs.VariableValue.toString();
			}
			
			if(val.equals("")) {
				val="0";
			}
			//if there is no comment, generate the todo comment from enum
			if(comment.equals("")) {
				comment=TODOs.Variable.toString();
			}
			constructor+="//"+comment+"\n"+name+" = "+val+";\n";
			
		}
		return constructor;
		
	}
	

	/*Generates a method given the dataType, methodName, parameters (which can be blank) comment, and body*/
	protected String genMethod(String className,String []methodParts,boolean isPublic){
		String methodString="";
		methodString+="//"+methodParts[3]+"\n";//comment
		methodString+=methodParts[0];//data type
		//remove extra space for constructor
		if(!methodParts[0].equals("")) {
			methodString+=" ";
		}
		methodString+=className+"::"+methodParts[1]+"("+methodParts[2]+") {";//name
		methodString+=ArduinoParser.insertTabs(methodParts[4],1,false);//body
		methodString+="\n}\n\n";
		return methodString;
		
	}
	
	/** Generates the final board definition which generates errors if the wrong board is used*/
	private String generateBoardDefFinal(){
		return "#endif";
	}
	/**
	* Shows an example file with this class
	*/
	public static void main (String [] args){
		// This example generates a class represented as a string
		// The user can decide how these string will be inputted
		// These fields are the minimum required to generate an arudino class

		ArduinoClassCpp template = new ArduinoClassCpp(ArduinoClassExample.CLASSNAME.toString(),
			ArduinoClassExample.AUTHOR.toString(),
			ArduinoClassExample.ORGANIZATION.toString(), 
			true,
			ArduinoClassExample.HEADERCOMMENTS.toString(), 
			ArduinoClassExample.SUPPORTEDBOARDS.toString(),
			ArduinoClassExample.VARIABLES.toString(),
			ArduinoClassExample.PRIVATEMETHODS.toString(),
			ArduinoClassExample.PUBLICMETHODS.toString());
			//get the String representation of the   cpp file
		System.out.println(template);
		
	}
		
}