package cc.ArduinoClassGenerator;

/** Name: Jacob Smith
 Date: May 13 2019
 Assignment: Personal Study, allows the user to create a scanner object which iterates
 	over a base string and returns one token at a time
 Email: jsmith2021@brandeis.edu
 Notes:
 	Throw error if hasNext was called twice in a row at end of input
 	The expected behavior of the class is that a new instance will be created, then
 	the prime method will be called whenever a string needs to be iterated over.
 	If the user calls hasNext or next before the scanner is primed, an exception is thrown
 	If there is more string to process, hasNext returns true
 	Next returns the next String to process, null if there is no next string
 	With this scheme, hasNext and next can be called forever with no exception as long as scanner is primed
 Rights: Copyright (C) 2019 Jacob Smith
    	 License is GPL-3.0, included in License.txt of this github project
 */

public class MiniScanner {

	private boolean hasNext;
	private boolean alreadyChecked;
	private boolean primed;
	private String base;
	private String token;
	private int curIndex;
	private String nextString;

	/** instantiates a MiniScanner object */
	public MiniScanner() {
		alreadyChecked = false;
		initClass();
	}

	/**
	 * Helper method to initialize or reset all of the classes instance
	 * variables
	 */
	public void initClass() {
		base = null;
		token = null;
		curIndex = 0;
		nextString = null;
		alreadyChecked = false;
	}

	/**
	 * Shows an example file with this class
	 */
	public static void main(String[] args) {
		// this example iterates over a base stirng with spaces used as a token
		MiniScanner reader = new MiniScanner();

		System.out.println("test prime with base string separated by spaces");
		reader.prime("This is a test", " ");
		while (reader.hasNext()) {
			System.out.println(reader.next());
		}

		System.out.println("test prime with base string separated by colons");
		reader.prime("This:is:also:a:test", ":");
		while (reader.hasNext()) {
			System.out.println(reader.next());
		}

	}

	/** Gets a MiniScanner reader to iterate over the MiniScanner */
	public void prime(String base, String token) {
		alreadyChecked = false;
		this.base = base;
		this.token = token;
		curIndex = 0;
		primed = true;
	}

	/**
	 * returns whether the scanner is reader to iterate over updates the
	 * nextString field
	 */
	public boolean hasNext() {
		// check if the scanner was primed with a base integer
		checkPrimed();
		// if the user called next twice, just return the last result
		if (alreadyChecked) {
			return hasNext;
		} else {// otherwise, state that this was already checked
			alreadyChecked = true;
		}
		// otherwise, check for the next element
		return getNextString();

	}

	/**
	 * helper method iterates along the base string to get the next piece
	 * 
	 * @return the next string to process which can't be null
	 */
	private boolean getNextString() {
		// if the base string is null, set the scanner to return null and sreturn false
		if (base == null) {
			hasNext=false;
			alreadyChecked = true;
			nextString = null;
			return false;
		}
		//if the first token is a space
		int offset=0;
		if(curIndex==0 | !token.equals(" ")) {
			offset=token.length()-1;
		}
		int nextIndex=base.indexOf(token,curIndex+offset);
		boolean hasNextToken=nextIndex!=-1;
		
		// if there is a next token, update nextString field return true
		if (hasNextToken) {
			//advance current index until the first 
			nextString = base.substring(curIndex, nextIndex);
			curIndex=nextIndex+token.length();
			//if the token is a space, ignore multiple of them
			//because spaces are more likely to be direct user input while
			//bars are processed input
			if(!token.equals(" ")) {return true;}
			while(base.indexOf(token,nextIndex+1)==nextIndex+1) {
				curIndex++;
				nextIndex++;
			}
			return true;
		}
		// otherwise, see if you are at the last index
		// and if you are update nextString with the rest of the string
		if (curIndex < base.length()) {
			nextString = base.substring(curIndex, base.length());
			curIndex = base.length();
			return true;
		}
		// if there is no next String, reset the class
		// but say that already checked is true, becuase there are no more
		// strings to return
		// this means next will return null until a new prime occurs
		initClass();
		alreadyChecked = true;
		return false;
	}

	/**
	 * returns the next string, which will be null if there is no next string
	 * */
	public String next() {
		// if scanner wasn't initially primed, throw exception
		checkPrimed();
		// this gets the next string if hasNext wasn't called
		if (!alreadyChecked) {
			hasNext();
		}
		alreadyChecked = false;
		// return the nextString and set it to null
		String temp = nextString;
		nextString = null;
		return temp;

	}
	
	/**
	 * returns the next string, which will be null if there is no next string
	 * @param tokenExpected the name of what the user is looking for to print in an error message
	 * */
	public String next(String tokenExpected) {
		//call has next and report an error if not found
		checkMissingToken(tokenExpected);
		//if an exception was not thrown, call the next method as normal
		return this.next();

	}
	/**
	 * returns all of the rest of a string for when another method of parsing will be used
	 * @return all the tokens left in the base string
	 * */
	public String getRest() {
		//calls private helper method with parameters
		//saying there is no end token, so return everything
		return getRest(false,"");
	}
	
	
	
	/**
	 * iterates through the bas estring until end token is found, useful 
	 * for parsing user input with known end token
	 * @param endToken the token marking end of input stream
	 * @return the tokens until and excluding the endToken
	 */
	public String getUntil(String endToken) {
		return getRest(true,endToken);
	}

	/**
	 * Hidden method to iterate through tokens
	 * @param hasEndToken wheether an end token is specified
	 * @param endToken, the endToken, ignored if hasNedToken is false
	 * @return the rest of the tokens or the rest until end token
	 */
	private String getRest(boolean hasEndToken,String endToken) {
		//whether the end token was found, always false if hasEndToken is false
		boolean foundEndToken=false;
		//temp, rest and prev will hold various parts of the string
		String temp=this.next();
		String rest=temp;
		//add all of the next string with the token, fencepost
		//and exit the loop if end token was found and there is one
		while(this.hasNext() && !foundEndToken) {
			//get the next word
			temp=this.next();
			//update whether the end token was found if there is an end token
			if(hasEndToken && temp.contains(endToken)) {
				foundEndToken=true;
			}else {
				//if end token not found, add the next word to the main string with a connecter
				rest+=token+temp;
			}
		}
		return rest;
	}
	
	/** throws an exception if the user hasn't primed the MiniScanner */
	private void checkPrimed() {
		if (!primed) {
			throw new IllegalArgumentException(
					"Error, Scanner not primed. Maybe you called next an extra time?");
		}
	}
	
	/**
	 * Used to throw an error message if a token is expected but not found
	 * @param tokenName the name of the token to put in an error message
	 */
	private void checkMissingToken(String tokenName) {
		if(!this.hasNext()) {
			throw new IllegalArgumentException("Error, Expected "+tokenName+" but not found");
		}
	}
	
	/**
	 *@return a String representation of the object
	 */
	public String toString() {
		return this.base+"\tNext String:"+this.nextString;
	}

}