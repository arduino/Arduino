/**Name: Jacob Smith
  *Email:jsmith2021@brandeis.edu 
  *Date: May 23, 2019
  *Assignment:Personal Study, a wrapper class for
  *the LinkedListNode
  *Bugs:
  *Sources:
  *Rights: Copyright (C) 2019 Jacob Smith
  * 	   License is GPL-3.0, included in License.txt of this github project
  */
package cc.ArduinoClassGenerator;

public class LinkedList {
	
	/**
	 * the head of the linked list, which the user can access
	 */
	private LinkedListNode head;
	/**
	 * the tail of the linked List to make adding easier
	 */
	private LinkedListNode tail;
	
	/**
	 * creates a new LinkedList object
	 */
	public LinkedList() {
		head=null;
		tail=null;
	}
	
	/**
	 * Accessor method for beginning of list
	 * @return the head of the LinkedList
	 */
	public LinkedListNode getHead() {
		return head;
	}
	
	/**
	 * Accessor method for ned of list
	 * @return the tail of the LinkedList
	 */
	public LinkedListNode getTail() {
		return tail;
	}
	
	/**
	 * Adds an element to the end of the linked list
	 * @param val the string to add to the linked list
	 */
	public void add(String val) {
		LinkedListNode node=new LinkedListNode(val);
		if(head==null) {
			head=node;
			tail=node;
		}else {
			LinkedListNode.updateLink(tail, node);
			tail=node;
		}
	}
	
	/**
	 * @return a string representation of the linked list
	 */
	public String toString() {
		LinkedListNode n=head;
		String s=n.getVal();
		while(n.getNext()!=null) {
			n=n.getNext();
			s+=" -->"+n.getVal();
		}
		return s;
	}
	
	/**
	 * switches two nodes in a linked list
	 * @param node1 node of linked list
	 * @param node2 different note of that same linked list
	 */
	public void switchNodes(LinkedListNode node1,LinkedListNode node2) {
		//check if node 1 and 2 aren't consecutive
		if(node1.getNext()!=node2) {
			throw new IllegalArgumentException("Node1 and 2 must be consecutive");
		}
		
		//make sure tail is updated
		if(tail==node1) {
			tail=node2;
		}else if (tail==node2) {
			tail=node1;
		}
		//make sure head is updated
		if(head==node1) {
			head=node2;
		}else if (head==node2) {
			head=node1;
		}
		//store adjacent nodes in memory
		LinkedListNode node0=node1.getPrev();
		LinkedListNode node3=node2.getNext();
		//update node0-2 link
		LinkedListNode.updateLink(node0, node2);
		//update node 2-1 link
		LinkedListNode.updateLink(node2, node1);
		//update node 1-3 link
		LinkedListNode.updateLink(node1, node3);
		
	}
	
	
}
