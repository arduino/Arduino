/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: Jul 5, 2019
  *Assignment:Personal Study, a class to hold the optional fields
  *when creating an Arduino library. This class allows fewer parameters to be used in the
  *ArduinoClassContainer method call
  *Bugs:
  *Sources:
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class libraryOptionalFields {
	/** fields of libraryOptionalFields class
	 * */
	private String author;
	private String organization;
	private boolean hardCodeDate;
	private String supportedBoards;
	
	/**
	 * creates a new libraryOptionalFields object
	 * @param author the author of the Arduino library
	 * @param organization the organization that the author belongs to
	 * @param hardCodeDate whether the date of the library should be hardcoded for testing purposes
	 * @param supportedBoards the boards that the class is designed to work for
	 */
	public libraryOptionalFields(String author,String organization, boolean hardCodeDate,String supportedBoards) {
		this.author=author;
		this.organization=organization;
		this.hardCodeDate=hardCodeDate;
		this.supportedBoards=supportedBoards;
	}
	
	/**
	 * @return the author String
	 */
	public String getAuthor() {
		return author;
	}
	/**
	 * @return the organization String
	 */
	public String getOrganization() {
		return organization;
	}
	/**
	 * @return the hardcodedate boolean
	 */
	public boolean getHardCodeDate() {
		return hardCodeDate;
	}
	/**
	 * @return the supportedBoards String
	 */
	public String getSupportedBoards() {
		return supportedBoards;
	}
	
	/**
	 * return a String representation of the class
	 */
	public String toString() {
		String s="";
		s+="Author         :"+author+"\n";
		s+="Organization   :"+organization+"\n";;
		s+="HardCodeDate   :"+hardCodeDate+"\n";;
		s+="SupportedBoards:"+supportedBoards+"\n";
		return s;
	}
	/**
	 * demonstrates toString of class
	 * @param args not used
	 */
	public static void main (String []args) {
		libraryOptionalFields fields=new libraryOptionalFields("Jacob Smith","Brandeis Univeristy",true,"ALL");
		System.out.println(fields.toString());
	}
}