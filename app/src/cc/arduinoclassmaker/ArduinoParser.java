package cc.arduinoclassmaker;

import cc.arduinoclassmaker.MiniScanner;

/** Name: Jacob Smith
 *  Email:jsmith2021@brandeis.edu
 *  Assignment:  Personal Study, provides methods relevent to parsing an Arduino Class
 *  	This is a seperate class to keep classes short and to allow client to access there server methods for input validation
 *  Date: May 15, 2019
 *  Sources: 
 *  Bugs:
 *  Rights: Copyright (C) 2019 Jacob Smith
 *  		License is GPL-3.0, included in License.txt of this github project
 */

public class ArduinoParser {
	
	/**Insert internal tabs into a string separated by newline characters
	 * @param firstLine whether to insert a tab into the first line*/
	public static String insertTabs(String base, int numTabs,boolean firstLine){
		//check edge cases if base string is null
		//if user wants to tab first line, return a tab plus the base
		if(base==null && firstLine){
			   return genTab(numTabs)+base;	
		}
		//if user doens't want to tab first line, just return base
		if(base==null && !firstLine){
			return base;
		}
		
		//set up sacnner to iterate over base string
		MiniScanner reader=new MiniScanner();
		reader.prime(base,"\n");
		String withTabs="";
		String line;
		//if there is no next string, return the base
		if(!reader.hasNext()){return base;}
		//if firstLine is meant to be tabbed, insert one
		if(firstLine){withTabs+=genTab(numTabs);}
		//add the next character, previous if statement confirme there will be a next character
		withTabs+=reader.next()+"\n";
		while(reader.hasNext()){
			line=reader.next();
			withTabs+=genTab(numTabs)+line+"\n";
		}
		return withTabs;
		
	}
	/** Generates a tab of the specified depth
	 * */
	private static String genTab(int numTabs){
		String tab="";
		for(int i=1;i<=numTabs;i++){
			tab+="    ";
		}
		return tab;
	}
	
	/**
	 * Helper method for parsing methods from a sketch
	 * @param base the string to iterate over
	 * @param startIndex the index to start at
	 * @return the index of the closing bracket or -1 if not found
	 */
	public static int getClosingIndex(String base,int startIndex) {
		//start off index at argument
		int index=startIndex;
		//loop exit variable, whether closing bracket was found
		boolean found=false;
		//character and counter variables
		char c;
		int numOpen=0;
		int numClose=0;
		//loop through the string
		while(!found && index<base.length()) {
			//get the next character
			c=base.charAt(index);
			//update bracket counters
			if(c=='}') {
				numClose++;
			}else if (c=='{') {
				numOpen++;
			}  
			//if found open bracket, exit loop, which can only happen if there is an open bracket
			if(numClose==numOpen && numOpen>0) {
				found=true;
			//otherwise, increment index
			}else {
				index++;
			}
		}
		//return the index of closinig bracket or -1 if not found
		if(found) {
			//return the index of the closing bracket
			return index;
		}else {
			return -1;
		}
		
	}
	
	/**Helper method for cleaning text input of special characters
	 * @return a string with special characters removed
	 */
	public static String removeSpecialChars(String temp) {
		//remove comment characters
		return temp.replace("/","").replace("*","").replace("\\","");
	}
	
	/**
	 * Helper method to remove formatting characters from a string
	 * @param base the string to be cleaned
	 * @return the cleaned string
	 */
	public static String removeWhiteSpace(String base) {
		//trim any tab characters or extra spaces from comment 
		//the newline character ensures that  nested brackets won't be flattened
		//trim whitespace from comment
		return base.replaceAll("\n  ","\n").replaceAll("\n\t","\n").trim();
	}
	
	/**
	 * Helper parsing method, replaces literal sequences instead of regular expressions
	 * @param base the string to itrate over
	 * @param toReplace the unwanted sequence
	 * @param replaceWith the wanted sequence
	 * @return the base string with the unwanted pattern replaced with the wanted pattern
	 * @throws InterruptedException 
	 */
	public static String replaceAllSimple(String base,String toReplace,String replaceWith) {
		String temp;
		//iterate along base string
		for(int i=0;i<base.length()-toReplace.length();i++) {
			//get string of same length as toReplace
			temp=base.substring(i, i+toReplace.length());
			//if there is match, replace toreplace with replace with
			if(temp.equals(toReplace)) {
				base=base.substring(0,i)+replaceWith+base.substring(i+toReplace.length(),base.length());
				//advance index 
				i+=toReplace.length();
			}
		}
		//return the edited base string
		return base;
	}
}