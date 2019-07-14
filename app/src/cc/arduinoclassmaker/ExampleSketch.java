/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 29, 2019
  *Assignment:	Personal Study, provides hardcoded fields necessary in generation of an
  * example arduino sketch. This is not included with the ArduinoClass Example because it 
  * was written later
  *Bugs:
  *Sources:
  * Rights: Copyright (C) 2019 Jacob Smith
  *  		License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public enum ExampleSketch {
	/**
	 * hardcoded methods
	 */
	SKETCHMETHODS("void|setup||runs once|\n"
			+"timer.resetTime()\n"
			+"delay(3000);\n"
			+"Serial.println(timer.getTime())\n\n"
			+"void|loop||runs many times|\n"
			+"Serial.println(timer.getAndResetTime());\n"
			+"delay(3000);\n"),
	/**
	 * hardcoded morse code sketch from 
	 * https://www.arduino.cc/en/Hacking/LibraryTutorial
	 */
	MORSECODESKETCH("int pin = 13;\n\n"
			+"void setup()\n"
			+"{\n"
			+"  pinMode(pin, OUTPUT);\n"
			+"}\n"

			+"void loop()\n"
			+"{\n"
			+"  dot(); dot(); dot();\n"
			+"  dash(); dash(); dash();\n"
			+"  dot(); dot(); dot();\n"
			+"  delay(3000);\n"
			+"}\n\n"

			+"void dot()\n"
			+"{\n"
			+ "  digitalWrite(pin, HIGH);\n"
			+ "  delay(250);\n"
			+ "  digitalWrite(pin, LOW);\n"
			+ "  delay(250);\n"
			+"}\n\n"

			+"void dash()\n"
			+"{\n"
			+ "  digitalWrite(pin, HIGH);\n"
			+ "  delay(1000);\n"
			+ "  digitalWrite(pin, LOW);\n"
			+ "  delay(250);\n"
			+"}");
	
	/**
	 * field for method
	 */
	private String input;
	/**
	 * creates a new example sketch
	 * @param input the method to input
	 */
	private ExampleSketch(String input) {
		this.input=input;
	}
	/**
	 * @return a string representation of the object
	 */
	public String toString() {
		return input;
	}
	
	/**
	 *  shows the fields of the enums
	 * @param args not used
	 * 	 */
	public static void main (String[]args) {
		ExampleSketch[]fields=ExampleSketch.values();
		ExampleSketch example;
		for(int i=0;i<fields.length;i++) {
			example=fields[i];
			System.out.println(example.name()+":\n"+example.toString());
		}
	}
}