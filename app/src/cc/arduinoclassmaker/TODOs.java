/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 29, 2019
  *Assignment:	Personal Study, convenient place to put 
  *TODO messages generated when user doesn't enter a rewuired field
  *Bugs:
  *Sources:
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public enum TODOs {
	/**
	 * hardcoded message fields
	 */
	HeaderComment("TODO: EXPLAIN WHAT PROGRAM IS FOR AND GIVE YOUR NAME AND WHO CAN USE THIS PROGRAM"), Method(
			"TODO: EXPLAIN WHAT METHOD DOES"), PropertiesField("TODO: SET THIS LIBRARY PROPERTIES FIELD"), Variable(
					"TODO: EXPLAIN WHAT VARIABLE IS FOR"), VariableValue("TODO: SET INITIAL VARIABLE VALUE");
	/**
	 * the message to be displayed
	 */
	private String message;

	/**
	 * creates a new TODO object
	 * 
	 * @param message
	 *            the message to be displayed
	 */
	private TODOs(String message) {
		this.message = message;
	}

	/**
	 * demonstrates the enums available
	 * 
	 * @param args
	 *            not used
	 */
	public static void main(String[] args) {
		TODOs[] messages = TODOs.values();
		for (int i = 0; i < messages.length; i++) {
			System.out.println(messages[i]);
		}
	}

	/**
	 * @return the message
	 */
	public String toString() {
		return message;
	}
}
