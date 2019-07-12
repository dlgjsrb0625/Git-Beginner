package Algorithm.test;

public class LinkedList {

	private Node head;
	private Node tail;
	
	private class Node {
		
		private int key;
		private Node next;
		
		public Node(int k){
			this.key = k;
			this.next = null;
		}
	}
	public void insert(int k) {
	
		if(head==null) {
			head = new Node(k);
		}
		else
			if(head.key>k) {
				tail = head;
				head = new Node(k);
				head.next = tail;
			}
			else
		        {
	             Node p =head;
	               while(p.next !=null) 
	               {
	            	 if(p.next.key>k)break;
	            	 
	            	 p=p.next;
	               }
	             tail=p.next;
	             p.next=new Node(k);
	             p.next.next=tail;
		        }
				
	}
	public boolean remove(int k) {
		
		if(head ==null) {
			System.out.println("삭제 실패");
			return false;
		}
		if(head.key==k)
		   {
			tail=head.next;
			head=null;
			head=tail;
			System.out.println("삭제 성공");
			return true;
		   }
		   else
		   {
		    Node s =head;
	       while(s.next !=null) 
	        {
	          if(s.next.key==k)
	    	 {
	          tail=s.next.next;
	    	  s.next=null;
	    	  s.next=tail;
	    	  System.out.println(k+" : 삭제 성공");
	    	  return true;
	    	 }
	 	    s=s.next;
	        }
		   }
		System.out.println(k+ " : 삭제 실패");
	    return false;
	}
	public String show() {
		if(head == null)
		   {
	           return "[]"; 
	       }       
	      
	       Node nod = head;
	       String str = "[";
	      
	       while(nod.next != null)
	       {
	           str += nod.key + ",";
	           nod = nod.next;
	       }
	 
	       str += nod.key;
	       return str+"]";
	}
	
}