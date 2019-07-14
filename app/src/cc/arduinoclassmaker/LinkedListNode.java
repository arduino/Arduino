/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 23, 2019
  *Assignment:	Personal Study, a simple class to implement
  *a linked list to allow for iteration when parsing
  *Bugs:
  *Sources:
  *Rights: Copyright (C) 2019 Jacob Smith
  *  	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.arduinoclassmaker;

public class LinkedListNode {
	private LinkedListNode prev;
	private LinkedListNode next;
	private String val;
	
	/**
	 * Creates a new LinkedListNode object
	 * @param val the value of the node
	 */
	public LinkedListNode(String val) {
		this.val=val;
		prev=null;
		next=null;
	}
	
	/**
	 * Set the next field of this LinkedListnode
	 * @param node the node to point to
	 */
	private void setNext(LinkedListNode node) {
		this.next=node;
	}
	
	/**
	 * Set the prev field of this LinkedListnode
	 * @param node the node to point to
	 */
	private void setPrev(LinkedListNode node) {
		this.prev=node;
	}
	
	/**
	 * getter method for next field
	 * @return the next node pointed to
	 */
	public LinkedListNode getNext() {
		return next;
	}
	
	/**
	 * getter method for prev field
	 * @return the prev node pointed to
	 */
	public LinkedListNode getPrev() {
		return prev;
	}
	
	/**
	 * Getter method to access string
	 *@return the value of this node
	 */
	public String getVal() {
		return val;
	}
	
	/**
	 * Sets a to be the prev of b and b to be next of a
	 * handles null pointer exceptions
	 * @param a the first LinkedListNode
	 * @param b the second LinkedListNode
	 */
	public static void updateLink(LinkedListNode a,LinkedListNode b) {
		//only call a if it isn't null
		//otherwise, a doesn't need to be set and a null pointer
		//exception is avoided
		if(a!=null) {
			//set b as next node to a
			a.setNext(b);
		}
		//only call b if it isn't null
		if(b!=null) {
			//set a as prev node to b
			b.setPrev(a);
		}
	}
	
	/**
	 * @return a string representation of the node
	 */
	public String toString() {
		return val;
	}

}
