package euler;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.io.IOException;

public class LargeSum {
	
	private static final int BASE = 10;
	
	public static void addBigInts(ArrayList<Character> l1, ArrayList<Character> l2){
		
		System.out.println("start:" + l1.size() + ", " + l2.size());
		
		int i;
		int j;
		int carry = 0;
		int tempCarry;
		
		for(i = l1.size() - 1, j = l2.size() - 1; i >= 0 && j >= 0; i--, j--){
			System.out.println("in");
			
			if(carry == 0){
				carry = (Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j))) / (BASE);
				l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j))) % (BASE), 10));
				System.out.println("no carry");
				System.out.println(l1.toString());

			}
			else{
				tempCarry = (Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j)) + carry) / (BASE);
				l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j)) + carry) % (BASE), 10));
				System.out.println("carry" + carry);
				//System.out.println("carry" + carry);
				carry = tempCarry;
				System.out.println(l1.toString());

			}
		}
		
//		if(i < 0 ){
//			i = 0;
//		}
//		if(j < 0){
//			j = 0;
//		}
		
		if(i < 0 && j < 0 && carry != 0){
			l1.add(0, Character.forDigit(carry, 10));
			System.out.println("same length with carry");
			System.out.println(l1.toString());

		}else if(j < 0 && carry != 0){
			do{
				tempCarry = (Character.getNumericValue(l1.get(i)) + carry) / (BASE);
				l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + carry) % (BASE), 10));
				carry = tempCarry;
				--i;
				System.out.println("second shorter with carry");
				System.out.println(l1.toString());

			}
			while(carry != 0 && i >= 0);
			if(carry != 0){
				l1.add(0, Character.forDigit(carry, 10));
				System.out.println(l1.toString());

			}
		}else if(i < 0 && j >= 0){
			do{
				if(carry == 0){
					l1.add(0, l2.get(j));
				}else{
					tempCarry = (Character.getNumericValue(l2.get(j)) + carry) / (BASE);
					l1.add(0, Character.forDigit((Character.getNumericValue(l2.get(j)) + carry) % (BASE), 10));
					System.out.println(l1.toString());

					carry = tempCarry;
				}
				--j;
				System.out.println("first short");
				System.out.println(l1.toString());

			}
			while(j >= 0);
			
			if(carry != 0){
				l1.add(0, Character.forDigit(carry, 10));
			}
		}
		
		System.out.println(l1.toString());
		
	}

	public static void main(String[] args) {
		
		FileInputStream file;
		
		try{
			file = new FileInputStream(new File("C:/Users/Class2017/workspace/ProjectEuler/src/euler/input"));	
		}
		catch(FileNotFoundException e){
			System.out.println("File not found");
			return;
		}
		
		ArrayList<Character> total = new ArrayList<Character>(50);
		ArrayList<Character> temp = new ArrayList<Character>(50);
		
		int c;
		try{
			while((c = file.read()) != '\n'){
				if(c != '\r'){
					total.add((char) c);
					//System.out.println("add" + c);
				}
			}
		//	c = (char)System.in.read();
			while((c = file.read()) != -1){
				if(c == '\r'){
					continue;
				}
				else if(c != '\n'){
					temp.add((char) c);
				}else if(c == '\n'){
					addBigInts(total, temp);
					temp.clear();
				}
			}
			addBigInts(total, temp);
			System.out.println("Full sum: " + total.toString());
			System.out.println("First 10 digits: " + total.toString());
		//	c = (char)System.in.read();
			
		//	addBigInts(total, temp);
			//System.out.println(total.toString());
			
		}
		catch(IOException e){
			return;	
		}
		
	//	file.close();
	}
}

