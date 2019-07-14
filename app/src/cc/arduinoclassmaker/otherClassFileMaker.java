/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: Jul 10, 2019
  *Assignment:	Personal Study, creates other optional files to an Arduino class,
  *	like the library.properties file. Adds a TODO message for any uncompleted fields
  *Bugs:
  *Sources:
  *Rights:  Copyright (C) 2019 Jacob Smith
  *  		License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class otherClassFileMaker {
	/**
	 * Creates files for the Arduino class not opened in IDE
	 * long parameter list, but having container would add dependency
	 * @param className
	 *            name of class
	 * @param parentPath
	 *            directory to make folders in
	 * @param cont
	 *            container holding text of files
	 */
	public static void createClassFiles(String className, String parentPath, String examples, String keyWords) {
		// create example sketch in folder
		createExampleSketch(className, parentPath, examples);
		// create keywords file
		Files.createFile(parentPath, "keywords.txt", keyWords);
		//create .gtioignore file
		Files.createFile(parentPath, ".gtignore",
				"# this file lists what to ignore in a github repository\n.development/");
		//create .development file
		Files.createFile(parentPath, ".development",
				"this file lets you edit example files");
		//create library.properties file
		String libProp="";
		libProp+="name="+className+"\n";
		libProp+="version=1.0.0\n";
		//use an array and for loop to populate the rest of the properties fields
		String []propFields= {"author","maintainer","sentence","paragraph","category","url","includes",
				"architectures"};
		for(int i=0;i<propFields.length;i++) {
			libProp+=propFields[i]+"= "+TODOs.PropertiesField.toString()+"\n";
		}
		//create the file
		Files.createFile(parentPath, "library.properties",
				libProp);
		}

	/**
	 * Creates example sketch file in examples folder
	 * 
	 * @param className
	 *            the name of the arudino class
	 * @param parentPath
	 *            the path of the library param exampleText the text of the example
	 *            sketch
	 */
	private static void createExampleSketch(String className, String parentPath, String exampleText) {
		// creates example folder
		Files.createFolder(parentPath, "examples");
		// creates folder for specific example sketch
		Files.createFolder(parentPath + "\\examples", className + "Example");
		// creates example sketch with text
		Files.createFile(parentPath + "\\examples\\" + className + "Example", className + "Example.ino", exampleText);
	}
}
