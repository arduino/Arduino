package cc.arduinoclassmaker;

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
	public ArduinoClassCpp(String className,libraryOptionalFields fields,String headerComments,String variables,String privateMethods,String publicMethods){
		super(className,fields,headerComments);
		init(className,fields.getSupportedBoards(),variables,publicMethods,privateMethods);
		
	}
	
	/**
	* Loads an example class into memory with automatic date
	* and parses it into header comment, methods, header file
	*/
	public ArduinoClassCpp(String className,String author,libraryOptionalFields fields,String headerComments,String variables,String privateMethods,String publicMethods){
		super(className,fields,headerComments);
		init(className,fields.toString(),variables,publicMethods,privateMethods);
		
	}
	
	/**
	 * Helper method to intialize class specific methods and allow date to be hardcoded
	 */
	private void init(String className,String supportedBoards,String variables,String publicMethods, String privateMethods){
		arduinoClass+=super.generateBoardDefInitial(supportedBoards);
		arduinoClass+=super.startLibraryIncludes(variables, className)+"\n";
		String publicMethodsWithHeader=generateConstructorandBegin(className,variables)+publicMethods;
		arduinoClass+=generateMethods(className,publicMethodsWithHeader,true);
		arduinoClass+=generateMethods(className,privateMethods,false);	
		arduinoClass+=generateBoardDefFinal(supportedBoards);
	}
		
	/**
	 * Generates the body of the class constructor
	 * @return the formatted method of a constructor
	 */
	private String generateConstructorandBegin(String className,String variables) {
		//add an automatic comment for the constructor
		String constructorAndBegin=super.getConstructorAndBegin(className);
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
			
			if("".equals(val)) {
				val="0";
			}
			//if there is no comment, generate the todo comment from enum
			if("".equals(comment)) {
				comment=TODOs.Variable.toString();
			}
			constructorAndBegin+="//"+comment+"\n"+name+" = "+val+";\n";
			
		}
		return constructorAndBegin;
		
	}
	

	/*Generates a method given the dataType, methodName, parameters (which can be blank) comment, and body*/
	protected String genMethod(String className,String []methodParts,boolean isPublic){
		String methodString="";
		methodString+="//"+methodParts[3]+"\n";//comment
		methodString+=methodParts[0];//data type
		//remove extra space for constructor
		if(!"".equals(methodParts[0])) {
			methodString+=" ";
		}
		methodString+=className+"::"+methodParts[1]+"("+methodParts[2]+") {";//name
		methodString+=ArduinoParser.insertTabs(methodParts[4],1,false);//body
		methodString+="\n}\n\n";
		return methodString;
		
	}
	
	/** Generates the final board definition which generates errors if the wrong board is used
	 * param supportedBoards needed endif clause*/
	private String generateBoardDefFinal(String supportedBoards){
		if("ALL".equals(supportedBoards)|supportedBoards==null) {
			return "";
		}
		return "#endif";
	}
	/**
	* Shows an example file with this class
	*/
	public static void main (String [] args){
		// This example generates a class represented as a string
		// The user can decide how these string will be inputted
		// These fields are the minimum required to generate an arudino class
		//create new object to contain fields
		libraryOptionalFields fields=new libraryOptionalFields(ArduinoClassExample.AUTHOR.toString(),
				ArduinoClassExample.ORGANIZATION.toString(),true,ArduinoClassExample.SUPPORTEDBOARDS.toString());
		
		ArduinoClassCpp template = new ArduinoClassCpp(ArduinoClassExample.CLASSNAME.toString(),
			fields, 
			ArduinoClassExample.HEADERCOMMENTS.toString(), 
			ArduinoClassExample.VARIABLES.toString(),
			ArduinoClassExample.PRIVATEMETHODS.toString(),
			ArduinoClassExample.PUBLICMETHODS.toString());
			//get the String representation of the   cpp file
		System.out.println(template);
		
	}
		
}