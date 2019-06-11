/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 31, 2019
  *Assignment:	Personal Study, integrates the Arduino Class Generator project into the Arduino IDE
  *Bugs: This hasn't been tested on other computers, mine is windows 10
  *Sources: https://stackoverflow.com/questions/615948/how-do-i-run-a-batch-file-from-my-java-application
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project	
 */
package processing.app;

//classes to do input/output with arduino IDE
import processing.app.SketchController;
import processing.app.EditorTab;
import processing.app.SketchFile;
//classes to create arduino library from sketch
import cc.ArduinoClassGenerator.ArduinoClassContainer;
import cc.ArduinoClassGenerator.SketchParser;

import static processing.app.I18n.tr;

//import static processing.app.I18n.tr;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;

public class ClassGeneratorInterface {

	/**
	 * Reads the file name and contents of the current sketch, and creates a body
	 * file, header file, keywords, and example file
	 */
	public static void generateLibrary(SketchController controller, EditorTab tab, SketchFile sketchFile,
			ArrayList<EditorTab> tabs, EditorStatus status) {
		// create private LibHandler Class so graphics will be updated
		class LibHandler implements Runnable {
			@Override
			/**
			 * generates library files and display status messages
			 */
			public void run() {
				// get the file name and contents of the sketch
				String[] sketchInfo = getNameContentsPath(tab, sketchFile);
				String className = sketchInfo[0];
				String contents = sketchInfo[1];
				String filepath = sketchInfo[2];
				//give user the chance to provide a new className
				//status.edit("Please enter name of class", sketchInfo[0]);
				//try{Thread.sleep(5000);}catch(Exception e){}
				//compile sketch to check for errors
				status.progressNotice(tr("Compiling sketch..."));
				if (failedToCompile(controller)) {
					return;
				}
				// parse the sketch into format used to generate arduino classes
				status.progressNotice(tr("Creating Library Files..."));
				status.progressUpdate(50);
				status.clearState();
				SketchParser parser = new SketchParser(contents);
				ArduinoClassContainer cont = parser.getContainer(className, false);
				// create the files with strings
				status.progressNotice(tr("Creating Tabs..."));
				setLibraryTabs(className, cont.getBody(), cont.getExample(), cont.getHeader(), cont.getKeywords(), tabs,
						controller);
				status.progressUpdate(100);
				status.unprogress();
				status.progressNotice(tr(""));
			}
		}
		// see private handleRun method of Editor class, try line 1632
		new Thread(new LibHandler()).start();
	}

	/**
	 * compiles the sketch before arduino class is generated to force the user to
	 * submit a correct class
	 * 
	 * @return true if class failed to compile
	 */
	private static boolean failedToCompile(SketchController controller) {
		System.out.println("Compiling sketch to check for errors...");
		String output = "failed";
		try {
			output = controller.build(true, false);
		} catch (Exception e) {
		}
		if (output.equals("failed")) {
			System.out.println("Error, the sketch failed to compile, exiting sketch generator");
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Reads a sketch for Arduino Class Generation
	 * 
	 * @return the name, contents, and file path of the sketch
	 */
	private static String[] getNameContentsPath(EditorTab currentTab, SketchFile sketchFile) {
		// create array to return sketch information in
		String[] sketchInfo = new String[3];
		// load sketch file name
		String fileName = sketchFile.getFile().getName();
		// remove extension from fileName
		sketchInfo[0] = fileName.replaceAll(".ino", "");
		// load sketch contents
		sketchInfo[1] = currentTab.getText();
		// load sketch path
		sketchInfo[2] = sketchFile.getFile().getPath();
		return sketchInfo;
	}

	/**
	 * Creates and saves tabs of an rduino sketch with the arudino libary files for
	 * Arduino library generation
	 * 
	 * @param className
	 *            the name of the class
	 * @param body
	 *            the body file of class
	 * @param example
	 *            the example file of class
	 * @param header
	 *            the header file of the class
	 * @param keywords
	 *            the keywords file of the class
	 */
	private static void setLibraryTabs(String className, String body, String example, String header, String keywords,
			ArrayList<EditorTab> tabs, SketchController controller) {

		// create and set text of all tabs
		// the name of every tab starts with className, because tabs are alphabetized
		// create body tab
		controller.nameCode(className + ".cpp");
		// get the tab from the tabs field because nameCode doesn't return the tab
		// these indexes get complicated because of alphabetization
		tabs.get(1).setText(body);
		// create header tab
		controller.nameCode(className + ".h");
		tabs.get(2).setText(header);
		// create example tab
		controller.nameCode(className + "Example.ino");
		tabs.get(3).setText(example);
		// create keywords tab
		controller.nameCode(className + "keywords.txt");
		tabs.get(4).setText(keywords);
	}

	/**
	 * Builds and Runs the Arduino IDE by running batch Script RunArduino.bat
	 * 
	 * @param args
	 *            not used
	 */
	public static void main(String[] args) {
		try {
			Runtime.getRuntime().exec("cmd /c start RunArduino.bat");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}