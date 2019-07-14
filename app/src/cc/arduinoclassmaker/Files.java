/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: Jul 9, 2019
  *Assignment:	Personal Study, some wrapper methods for creating new files
  *Bugs:
  *Sources:
  *Rights:  Copyright (C) 2019 Jacob Smith
  *  		License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

import java.io.File;
import java.io.PrintStream;

public class Files {

	/**
	 * Creates a folder with given path and name
	 * @param path the location of folder
	 * @param name the name of folder
	 * @return an error message if folder not created, blank stirng otherwise
	 */
	public static String createFolder(String path, String name) {
		try {
			// creates new folder
			File folder = new File(path + "\\" + name);
			folder.mkdir();
		} catch (Exception e) {
			// if file text failed, return error message
			return "Error, folder not created";
		}
		return "";
	}

	/**
	 * Creates a file with specified path, name, and text
	 * @param path location of file
	 * @param name name of file (with extension)
	 * @param text contents of file
	 * @return error message if file not created, blank string otherwise
	 */
	public static String createFile(String path, String name, String text) {

		try {
			// create file
			File file = new File(path + "\\" + name);
			file.createNewFile();
			// populate file with text string
			PrintStream output = new PrintStream(file);
			output.print(text);
			output.close();

		} catch (Exception e) {
			// if file text failed, return error message
			return "Error, file not created";
		}
		return "";
	}
	

	public static void main(String[]args) {
		System.out.println("Making test file and folder");
		String path="C:\\Users\\jsmit\\Documents\\ArduinoClassMaker";
		System.out.println(createFolder(path,"testFolder"));
		File folder=new File(path+"\\testFolder");
		System.out.println(folder.exists());
		System.out.println(createFile(path,"testFile.txt",""));
		File folder2=new File(path+"\\testFile.txt");
		System.out.println(folder2.exists());
		
		
	}
}
