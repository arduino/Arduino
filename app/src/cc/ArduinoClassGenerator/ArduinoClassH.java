package cc.ArduinoClassGenerator;

/** Name: Jacob Smith
 Date: May 13 2019
 Assignment: Personal study, creates an h header file from minimum required information  
 Email: jsmith2021@brandeis.edu
 Notes: Nested parsing
 Rights: Copyright (C) 2019 Jacob Smith
   		 License is GPL-3.0, included in License.txt of this github project
 */

public class ArduinoClassH extends ArduinoClassMaster {

	// a String representation of the keywords .txt file
	private String keywords;

	/**
	 * Loads an example class into memory and parses it into header comment,
	 * methods, header file
	 */

	/**
	 * Creates a new ArduinoClassH object from necessary strings containing
	 * information like supported boards and author name
	 * */
	public ArduinoClassH(String className, String author, String organization,
			String headerComments, String supportedBoards, String variables,
			String privateMethods, String publicMethods) {
		// call super constructor to create header comment
		super(className, author, organization, headerComments, supportedBoards);
		initKeywords(className);
		init(className, supportedBoards, variables, privateMethods,
				publicMethods);
	}

	/**
	 * Creates a new ArduinoClassH object from necessary strings containing
	 * information like supported boards and author name with hardcoded date for
	 * testing purposes
	 * */
	public ArduinoClassH(String className, String author, String organization,
			boolean hardCodeDate, String headerComments,
			String supportedBoards, String variables, String privateMethods,
			String publicMethods) {
		// call super constructor to create header comment
		super(className, author, organization, hardCodeDate, headerComments,
				supportedBoards);
		initKeywords(className);
		init(className, supportedBoards, variables, privateMethods,
				publicMethods);
	}

	/**
	 * Helper method to initialize class and allow more flexibility with
	 * constructors
	 */
	private void init(String className, String supportedBoards,
			String variables, String privateMethods, String publicMethods) {
		arduinoClass += setupHeader(className);
		arduinoClass += generateBoardDefInitial(supportedBoards);
		arduinoClass += findLibraryIncludes(variables, className);
		arduinoClass += "class " + className + "{\n";
		arduinoClass += "  private:\n";
		arduinoClass += generateVariables(variables);
		arduinoClass += generateMethods(className, privateMethods, false);
		// add an automatic comment for the constructor
		publicMethods = "|" + className + "||Creates a new " + className
				+ " object|\n" + publicMethods;
		arduinoClass += "  public:\n";
		arduinoClass += generateMethods(className, publicMethods, true);
		arduinoClass += "};\n";
		arduinoClass += generateBoardDefFinal(className,supportedBoards);
	}

	/* Sets up the list of keywords with a comment and keyword for class */
	private void initKeywords(String className) {
		keywords = "//Generates ARDUINO KEYWORDS for " + className + " class\n";
		keywords += className + "\tKEYWORD1\n";
	}

	/** generates the definitions of the header file */
	private String setupHeader(String className) {
		String define = "";
		define += "//sets up the " + className + " Header file\n";
		define += "#ifndef " + className + "_h\n";
		define += "#define " + className + "_h\n\n";
		return define;
	}

	/**
	 * Determines what libraries should be included by analyzing the type of
	 * variables
	 */
	private String findLibraryIncludes(String variables, String className) {
		String type;
		// add comment and include for header file
		String includes = "//includes the libraries of code necessary to make this one work\n";
		includes += "#include <" + className + ".h>\n";
		reader.prime(variables, "\n");
		while (reader.hasNext()) {
			type = getDataType(reader.next());
			// if the type is not supported, create a new librayr entry
			if (!this.contains(supportedTypes, type)) {
				includes += "#include <" + type + ".h>\n";
			}

		}
		includes += "\n";
		return includes;
	}

	/**
	 * gets the data type from the varibale entry
	 */
	private String getDataType(String variables) {
		MiniScanner reader = new MiniScanner();
		reader.prime(variables, "|");
		if (!reader.hasNext()) {
			throw new IllegalArgumentException("Parsing Error with variables");
		}
		return reader.next();
	}

	/** Generates a method given the dataType, methodName, comment, and body */
	protected String generateVariables(String variables) {
		reader.prime(variables, "\n");
		String vars = "";
		String line;
		while (reader.hasNext()) {
			line = reader.next();
			vars += parseVariable(line);
		}
		return vars;

	}

	/** parses a variable into dataType, name, and comment */
	protected String parseVariable(String line) {
		String varLine = "";
		MiniScanner readerB = new MiniScanner();
		readerB.prime(line, "|");
		varLine += "    " + readerB.next("data type") + " ";// data type
		varLine += readerB.next("var name") + ";\n";// var Name
		String comment=readerB.next("comment");
		//generate to do message if there is no variable comment
		if(comment.equals("")) {
			comment=TODOs.Variable.toString();
		}
		varLine = "    //" + comment + "\n" + varLine;// comment
		return varLine;

	}

	/** Generates a method given the dataType, methodName, comment, and body */
	protected String genMethod(String className, String[] methodParts,
			boolean isPublic) {
		String methodString = "";
		//add comment
		methodString += "    //" + methodParts[3] + "\n";// comment
		if (!methodParts[0].equals("")) {
			methodString += " ";
		}
		// use this spot in parsing to generate keywords list of public methods
		// except the keyword for the class name will be handled in keyword init
		if (isPublic && !methodParts[1].equals(className)) {// only add keyword
															// if method is
															// public and isn't
															// a constructor
			keywords += methodParts[1] + "\tKEYWORD2\n";
		}
		methodString += "   " + methodParts[0] + " " + methodParts[1] + "("+methodParts[2]+");\n";// data
																				// type,name
		return methodString;

	}

	/**
	 * Generates the final board definition which generates errors if the wrong
	 * board is used
	 */
	private String generateBoardDefFinal(String className,String supportedBoards) {
		// if className is all, just close the normal class end if and return
		if (supportedBoards.equals("ALL")) {
			return "#endif";
		}
		// otherwise, return the moer complicated error handling definitions
		String finalDef = "";
		finalDef += "#elif defined (DONT_NEED_" + className.toUpperCase()
				+ ")\n";
		finalDef += "  #warning : May lead to error: '"
				+ className
				+ "' does not name a type ; Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html\n";
		finalDef += "#else\n";
		finalDef += "  #error : Program to Board Incompatibility ; One of the libraries you are using will not work with your board ; Quick fix: add <#define DONT_NEED_"
				+ className.toUpperCase()
				+ "> to top ; For more information, go to cse230.artifice.cc/lecture/splitting-code.html\n";
		finalDef += "#endif\n#endif";
		return finalDef;
	}

	/**
	 * Returns whether the key string exists in the array
	 */
	private boolean contains(String[] array, String key) {
		for (int i = 0; i < array.length; i++) {
			if (array[i].equals(key)) {
				return true;
			}
		}
		return false;
	}

	/** Returns a String representation of the header file */
	public String getHeader() {
		return arduinoClass;
	}

	/** Returns a String representation of the keywords file */
	public String getKeywords() {
		return keywords;
	}

	/**
	 * Shows an example file with this class
	 */
	public static void main(String[] args) {
		// This example generates a class represented as a string
		// The user can decide how these string will be inputted
		// These fields are the minimum required to generate an arudino class

		ArduinoClassH template = new ArduinoClassH(
				ArduinoClassExample.CLASSNAME.toString(),
				ArduinoClassExample.AUTHOR.toString(),
				ArduinoClassExample.ORGANIZATION.toString(), true,
				ArduinoClassExample.HEADERCOMMENTS.toString(),
				ArduinoClassExample.SUPPORTEDBOARDS.toString(),
				ArduinoClassExample.VARIABLES.toString(),
				ArduinoClassExample.PRIVATEMETHODS.toString(),
				ArduinoClassExample.PUBLICMETHODS.toString());

		System.out.println(template.getHeader());
		System.out.println(template.getKeywords());

	}
}