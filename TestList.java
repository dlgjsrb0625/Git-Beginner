package Algorithm.test;

import java.io.*;

public class TestList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       
		LinkedList l= new LinkedList();
		l.insert(40);
		System.out.println(l.show());
		l.insert(10);
		System.out.println(l.show());
		l.insert(80);
		System.out.println(l.show());
		l.insert(50);
		System.out.println(l.show());
		l.insert(30);
	    System.out.println(l.show());
	    boolean r;
	    r = l.remove(40);  // 삭제 성공? 삭제 실패?
	    r = l.remove(70); // 삭제 성공? 삭제 실패?
   		System.out.println(l.show());
	}

}
