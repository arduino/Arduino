package cc.ArduinoClassGenerator;

/** Name: Jacob Smith
 *  Email:jsmith2021@brandeis.edu
 *  Assignment: Personal Study, an enum class of example fields used to generate the
 *  hardCoded correct examples of cpp,h, and keywords files
 *  Date: May 16, 2019
 *  Sources: https://docs.oracle.com/javase/tutorial/java/javaOO/enum.html
 *  Bugs:
 *  notes: enum has nice automatic toString, naem field
 *  Need to have variable enforceMent for if supportedBoards is all, 
 *  and if a field is null,and ask for variables,privateMethods,and public methods one
 *  at a time
 *  Rights: Copyright (C) 2019 Jacob Smith
 *  	License is GPL-3.0, included in License.txt of this github project
 */

public enum ArduinoClassExample {
	
    CLASSNAME 		("Timer"),
    AUTHOR   		("Jacob Smith"),
    ORGANIZATION   	("Brandeis Robotics Club"),
    HEADERCOMMENTS 	("A timer class to allow the user to create loops and maintain program control"),
    SUPPORTEDBOARDS	("ARDUINO_AVR_UNO ESP8266_WEMOSD1R1"),
    VARIABLES  		("long|initTime|the beginning time of the interval\n" + 
    		"Apple|test|a test variable for the parser"),
    PRIVATEMETHODS  ("null"),
    PUBLICMETHODS 	("initTime=millis();\n\n"+
    		"long|resetTime||resets the Initial Time|\n"+
    		"initTime=millis();\nreturn getTime();\n\n"+
    		"long|getTime||returns the current time|\n"+
    		"return millis()-initTime;\n\n"+
    		"long|getAndResetTime||returns the current time and the initial time|\n"+
    		"long curTime=getTime();\nresetTime();\nreturn curTime;\n");
	
    private String example;
    
    /** A private constructor to create an enum with prompt and format
     * */
    ArduinoClassExample(String example) {
    
    	//load the example string
    	this.example=example;    
    }
   
    /**
     * @return the example of correct input
     */
    public String getExample() {
    	return example;
    }
    
    /**Displays capabilities of the enum
     * */
    public static void main(String[] args) {
        System.out.println("Prints out the different enums, prompts, and formatting contained in this class");
        String field;
        for (ArduinoClassExample a : ArduinoClassExample.values()){
        	//print name of enum
        	System.out.println(a.name()+":");
        	//print field of enum with tabs for nice printing
        	field=a.toString();
        	field=ArduinoParser.insertTabs(field, 1, true);
        	System.out.println(field);
        }

    }
    
    /**returns a string representation of the enum, with name, prompt, and format
     * */
    public String toString(){
    	return example;
    }
}