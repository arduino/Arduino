/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 21, 2019
  *Assignment:	Personal Study, Loads an Arduino Sketch to convert it to an arduino class
  *This would support recommended workflow
  *Bugs:
  *Sources:https://stackoverflow.com/questions/15633228/how-to-remove-all-white-spaces-in-java/36444332
  * https://docs.oracle.com/javase/6/docs/api/java/util/regex/Pattern.html#quote(java.lang.String)
  * https://stackoverflow.com/questions/17462146/java-patternsyntaxexception-illegal-repetition-on-string-substitution
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class SketchParser {
	private String sketchMethods;
	private String headerComment;
	private String libraries;
	private String variables;
	private String publicMethods;
	private String privateMethods;
	
	/**
	 * creates a new sketchParser object
	 * @param contents a string representing the sketch file to convert
	 */
	public SketchParser(String contents) {
		String cleanedContents=clean(contents);
		String unsortedMethods=evaluate(cleanedContents);
		variables=SketchMethods.cleanVariables(variables);
		libraries=libraries.replaceAll("\r", "");
		sortMethods(unsortedMethods);
		//add newline for constructor later, duck tape
		publicMethods="\n"+publicMethods;
		
	}
	
	/**
	 * Replaces problem characters in string such as inline bracket style 
	 * @param contents the sketch as inputted
	 * @return the sketch removed of problem characters
	 */
	private String clean(String contents) {
		//replace rs with newlines
		String cleanedContents=contents.replaceAll("\r\n", "\n");
		//allow for one line header comment
		//contents=ArduinoParser.replaceAllSimple(contents,"*/", "\n*/");
		//contents=ArduinoParser.replaceAllSimple(contents,"\n\n*/", "\n*/");
		//replace the newLine bracket style with inline
		//can't be done later because the scanner would read the bracket and header as different lines
		cleanedContents=ArduinoParser.replaceAllSimple(cleanedContents,")\n{","){");
		return cleanedContents;
	}
	
	/**
	 * reads sketch line by line, searching for tokens to divide and parse elements like variables and methods
	 * @param contents the sketch with problem characters removed
	 * @return the unsorted methods for further processing
	 */
	private String evaluate(String contents) {
		MiniScanner scanner=new MiniScanner();
		scanner.prime(contents,"\n");
		libraries="";
		variables="";
		String temp;
		String unsortedMethods="";
		sketchMethods="";
		headerComment="";
		//variable to show user where error was created
		String errorCode=null;
		while(scanner.hasNext()) {
			//get next line, and make sure it doens't have a newline character
			temp=scanner.next().replaceAll("\n+", "");
			//parse a one line comment
			String[]commentTemp=SketchMethods.checkForComment(temp,scanner);
			//add the code element to the correct field
			//if the line is not whitespace, save it for reporting an error
			if(commentTemp[1].trim().length()>0 ||errorCode==null) {
				errorCode=commentTemp[1];
				System.out.println(commentTemp[1]);
			}
			//if there is a parsing error report it to the user and halt the program
			try {
				unsortedMethods+=metaCircleEvaluate(commentTemp[0],commentTemp[1],scanner);
			}catch(Exception e) {
				System.out.println("Error could not convert your sketch into a class, got hung up at :"+errorCode);
			}

			
		
		}
		return unsortedMethods;
	}
	
	/**
	 * determines which kind of element the code is and adds to a field 
	 * @param comment an explanation of the code
	 * @param temp the first line of a code element
	 * @param scanner the scanner which iterates over the sketch, for multiline code elements
	 * @return a an unsortedMethod to be sorted
	 */
	private String metaCircleEvaluate(String comment,String temp,MiniScanner scanner) {
	
		String unsortedMethods="";
		//look for start of header comment
		if(temp.contains("/*")) {
			headerComment+=SketchMethods.parseHeaderComment(temp,scanner);
		//look for library	
		} else if(temp.contains("#include")) {
			libraries+=comment.trim()+"|"+temp.trim();
		//check for sketch methods
		}else if (temp.contains("void setup()") |temp.contains("void loop()")) {
			sketchMethods+=SketchMethods.consumeAndFormatMethod(comment+"\n"+temp,scanner);
		//look for method, second clause is to rule out array declaration
		}else if (temp.contains("{") && !temp.contains(";")) {
			unsortedMethods+=SketchMethods.consumeAndFormatMethod(comment+"\n"+temp,scanner);
		//do nothing if character is a newline
		//assume whatever is left is a variable because there are hard to stop
		}else if(!("\r".equals(temp) && "".equals(temp))){
			//use variableParser class to reformat the variable
			VariableParser p=new VariableParser(comment,temp);
			variables+=p.toString();
		}	
		return unsortedMethods;
	}
	
	/**Sorts all the methods into public and private based on whether they are referred to in
	 * setup and loop methods
	 * must be called after setup and loop methods are parsed
	 * @param unsortedMethods a parsed format of all the methods in the sketch
	 */
	private void sortMethods(String unsortedMethods) {
		MiniScanner methodReader=new MiniScanner();
		MiniScanner nameReader=new MiniScanner();
		String method;
		publicMethods="";
		privateMethods="";
		String name;
		methodReader.prime(unsortedMethods,"\n\n");
		while(methodReader.hasNext()) {
			method=methodReader.next();
			nameReader.prime(method,"|");
			//ignore the data type
			nameReader.next("Data Type");
			name=nameReader.next("methodName");
			if(sketchMethods.contains(name)) {
				publicMethods+=method+"\n\n";
			}else {
				privateMethods+=method+"\n\n";
			}				
		}
	}
	
	/**
	 * Reads a sketch from computer memory, and parses it into
	 * the necessary fields to generate an arduino class 
	 * @param args not used
	 */
	public static void main(String[] args) {
	
		System.out.println("Example of SketchParser Class");
		System.out.println("Getting Contents of example sketch\n__________________");
		String contents = ExampleSketch.MORSECODESKETCH.toString();
		System.out.println(contents);
		
		System.out.println("Parse the Sketch into relevant fields for a library\n__________________");
		SketchParser parser=new SketchParser(contents);
		System.out.println(parser);
		System.out.println("Generate body,header,class,and example sketch files from parsed input\n__________________");
		ArduinoClassContainer cont=parser.getContainer("Morse",false);
		System.out.println(cont);
	}
	
	/**
	 * @return a string representation of the class
	 */
	public String toString() {
		String s= "\nHEADER: "+headerComment
				+"\nLIBRARIES: "+libraries
				+"\nSKETCHMETHODS: "+sketchMethods
				+"\nPUBLICMETHODS: "+publicMethods
				+"\nPRIVATEMETHODS: "+privateMethods
				+"\nVARIABLES: "+variables;
		//make sure toString ends in newline, duct tape solution to pass test
		if ("".equals(variables)) {
			s+="\n";
		}
		return s;
	}
	
	/**
	 * used to generate arduino files
	 * @return an ArduinoClassCounter capable of generating resulting methods
	 */
	public ArduinoClassContainer getContainer(String className,boolean hardCodeDate) {
		libraryOptionalFields fields=new libraryOptionalFields(null,null,hardCodeDate,"ALL");
		return new ArduinoClassContainer(className, 
				headerComment,fields, variables,
				privateMethods, publicMethods,sketchMethods);
	}
}