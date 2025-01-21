package neetcode;
class ListNode{
	int var;
	ListNode next;
	// constructor that sets 'next' to null by default
	public ListNode(int var){
		this(var, null);
	}
	// constructor that accepts both value and next node
	public ListNode(int var, ListNode next){
		this.var = var;
		this.next = next;
	}
}
class LinkedList{
	private ListNode head;
	private ListNode tail;
	public LinkedList(){
		// Init the list with a "dummy" node which makes
		this.head = new ListNode(-1);
		this.tail = this.head;
	}
	public int get(int index){
		ListNode curr = head.next;
		int i = 0;
		while(curr != null){
			if(i == index){
				return curr.var;
			}
			i++;
			curr = curr.next;
		}
		return -1;
	}
	public void insertHead(int var){
		ListNode newNode = new ListNode(var);
		newNode.next = head.next;
		head.next = newNode;
		if(newNode.next == null){
			tail = newNode;
		}
	}
	public void insertTail(int var){
		ListNode newNode = new ListNode(var);
		newNode.next = null;
		tail.next = newNode;
		tail = newNode;
	}
	public boolean remove(int index){
		ListNode curr = this.head;
		int i = 0;
		while(i < index && curr != null){
			i++;
			curr= curr.next;
		}
		if(curr != null && curr.next != null){
			if(curr.next == this.tail){
				this.tail = curr;
			}
			curr.next = curr.next.next;
			return true;
		}
		return false;
	}

}
