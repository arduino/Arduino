package cc.arduinoclassmaker;

/**
 * Name: Jacob Smith Date: May 12 2019 Assignment: Personal study, allows the
 * user to create an Arduino Class sketch given necesary information Email:
 * jsmith2021@brandeis.edu Rights: Copyright (C) 2019 Jacob Smith License is
 * GPL-3.0, included in License.txt of this github project
 */

public class ArduinoClassExampleSketch extends ArduinoClassMaster {

	/*
	 * a list of public methods for editing method calls
	 */
	private String[] publicMethodNames;

	/**
	 * Loads an example class into memory with hardcoded date and parses it into
	 * header comment, methods, header file
	 */
	public ArduinoClassExampleSketch(String className, libraryOptionalFields fields, String headerComments,
			String sketchMethods, String publicMethods) {
		super(className, fields, headerComments);
		publicMethodNames = getPublicMethodNames(className, publicMethods);
		init(className, sketchMethods);

	}

	/**
	 * Helper method to intialize class specific methods and allow date to be
	 * hardcoded
	 */
	private void init(String className, String sketchMethods) {
		arduinoClass += super.startLibraryIncludes(null, className) + "\n";
		arduinoClass += genVariable(className);
		arduinoClass += generateMethods(className, sketchMethods, true);
	}

	/**
	 * @param publicMethods
	 *            a formatted string of all the public methods
	 * @return a list of the names of all the public methods for cross checking
	 */
	private String[] getPublicMethodNames(String className, String publicMethods) {
		//if there are no public Methods, return null
		if("".equals(publicMethods.trim())){
			return null;
		}
		
		String methodNames = "";
		MiniScanner methodReader = new MiniScanner();
		MiniScanner nameReader = new MiniScanner();
		methodReader.prime(publicMethods, "\n\n");
		// consume first method, which could be constructor
		String method = methodReader.next("constructor/firstPublicMethod");
		nameReader.prime(method, "|");
		nameReader.next("type");
		String name = "";
		if (nameReader.hasNext()) {
			name = nameReader.next() + " ";
		}
		// if method isn't constructor add it to list of public methods
		if (!name.equals(className) && !"".equals(name)) {
			methodNames += name;
		}
		while (methodReader.hasNext()) {
			method = methodReader.next();
			nameReader.prime(method, "|");
			nameReader.next("type");
			methodNames += nameReader.next("name") + " ";
		}
		return methodNames.split(" ");
	}

	/**
	 * creates the class initialization and comment
	 * 
	 * @param className
	 *            the name of the class
	 * @return the object used to interface with the class
	 */
	protected String genVariable(String className) {
		String var = "//The object used to interfact with the class\n";
		var += className + " " + this.genObjectName(className) + "();\n\n";
		return var;
	}

	/**
	 * a method to standardize name of class to avoid redundnacy
	 * 
	 * @param className
	 *            the name of this Arduino class
	 * @return the object name of class
	 */
	protected String genObjectName(String className) {
		return className.toLowerCase();
	}

	/**
	 * Generates a method given the dataType, methodName, parameters (which can be
	 * blank) comment, and body
	 */
	protected String genMethod(String className, String[] methodParts, boolean isPublic) {
		String methodString = "";
		methodString += "//" + methodParts[3] + "\n";// comment
		methodString += methodParts[0];// data type
		methodString += " " + methodParts[1] + "(" + methodParts[2] + ") {";// name and parameters
		// check if method is setup, and if so add begin method
		if ("setup".equals(methodParts[1])) {
			methodString += "\n    //sets up the class\n    " + this.genObjectName(className) + ".begin();";
		}
		// insert the object name to public method invocations
		String methodBody = insertObject(className, methodParts[4]);
		methodString += ArduinoParser.insertTabs(methodBody, 1, false);// body
		methodString += "\n}\n\n";
		return methodString;

	}

	/**
	 * Converts global methods into class invocations
	 * 
	 * @param methodBody
	 *            the body of the sketch methods
	 * @return the body of the method with the object inserted
	 */
	protected String insertObject(String className, String methodBody) {
		//if there are no public methods, there is no work to do
		if (publicMethodNames==null) {
			return methodBody; 
		}
		String methodName;
		// the method body with class methods replaced with object calls
		String methodBodyUpdated = methodBody;
		// iterate along public method names array
		for (int i = 0; i < publicMethodNames.length; i++) {
			// store the method name
			methodName = publicMethodNames[i];
			// replace occurences of that method name with the method name and object
			methodBodyUpdated = methodBodyUpdated.replaceAll(methodName,
					this.genObjectName(className) + "." + methodName);
		}
		// remove duplicate object method calls, in case user entered correct method
		// call initially
		methodBodyUpdated = methodBodyUpdated.replaceAll(
				this.genObjectName(className) + "." + this.genObjectName(className) + ".",
				this.genObjectName(className) + ".");
		return methodBodyUpdated;
	}

	/**
	 * Shows an example file with this class
	 */
	public static void main(String[] args) {
		// create a libraryOptional fields object to hold parameters
		libraryOptionalFields fields = new libraryOptionalFields(ArduinoClassExample.AUTHOR.toString(),
				ArduinoClassExample.ORGANIZATION.toString(), true, ArduinoClassExample.SUPPORTEDBOARDS.toString());
		// create an ArduinoClassExampleSketch object using hardcoded example fields
		ArduinoClassExampleSketch template = new ArduinoClassExampleSketch(ArduinoClassExample.CLASSNAME.toString(),
				fields, ArduinoClassExample.HEADERCOMMENTS.toString(),
				ExampleSketch.SKETCHMETHODS.toString().trim() + "\nresetTime();",
				ArduinoClassExample.PUBLICMETHODS.toString());
		// print the generated example sketch
		System.out.println(template);
	}
}