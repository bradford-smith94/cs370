/* Aidan Racaniello, Bradford Smith, and Nicholas Zubrycki
 * CS 370 Assignment1: ProjectEuler 13 LargeSum.java
 * 02/07/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.io.IOException;

/* class LargeSum
 * for completing ProjectEuler Problem #13: LargeSum
 */
public class LargeSum {

    /* the path to the input file containing the BigIntegers
     * MAY NEED TO BE CHANGED FOR GRADING
     */
    private static final String FILE_PATH = "./input.txt";

    //the base to store the BigIntegers in: 10 for decimal
    private static final int BASE = 10;

    //boolean for whether or not to turn on debug level print statements
    private static final boolean DEBUG = false;


    /* pre: takes in two ArrayList<Character> (l1 and l2), which each store an
     *      integer value
     * post: l1 will contain the value of the two BigIntegers added together
     */
    public static void addBigInts(ArrayList<Character> l1, ArrayList<Character> l2) {
        if (DEBUG) {
            System.out.println("start:" + l1.size() + ", " + l2.size());
        }

        int i;
        int j;
        int carry = 0; //the number "carried" to the next column when adding two digits together
        int tempCarry; //a temporary storage for carry when it's value is needed in another computation

        /* start loop counter i at the index of the last digit in l1
         * start loop counter j at the index of the last digit in l2
         *
         * loop backward (toward the most significant digit) until either i or j
         *      has read the last digit in their respective number
         */
        for (i = l1.size() - 1, j = l2.size() - 1; i >= 0 && j >= 0; i--, j--) {
            if (DEBUG) {
                System.out.println("in");
            }

            /* if there is no carry
             * carry = (digit + digit) / BASE
             * newDigit = (digit + digit) % BASE
             */
            if (carry == 0) {
                carry = (Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j))) / BASE;
                l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j))) % BASE, 10));

                if (DEBUG) {
                    System.out.println("no carry");
                    System.out.println(l1.toString());
                }

            }
            /* else there is a carry
             * newCarry = (digit + digit + carry) / BASE
             * newDigit = (digit + digit + carry) % BASE
             */
            else {
                //need to make use of tempCarry to avoid using the wrong value for computing the new digit
                tempCarry = (Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j)) + carry) / BASE;
                l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + Character.getNumericValue(l2.get(j)) + carry) % BASE, 10));

                if (DEBUG) {
                    System.out.println("carry" + carry);
                    System.out.println(l1.toString());
                }

                carry = tempCarry;

            }
        } //end for loop (backward through integers)


        /* if both i and j have reached the end of their integers and there is
         * still a carry
         */
        if (i < 0 && j < 0 && carry != 0) {
            //add the carry to the beginning
            l1.add(0, Character.forDigit(carry, 10));

            if (DEBUG) {
                System.out.println("same length with carry");
                System.out.println(l1.toString());
            }

        }
        //else if j has reached the end of its integer and there is a carry
        else if (j < 0 && carry != 0) {
            //loop through the rest of l1 and account for carry
            do {
                tempCarry = (Character.getNumericValue(l1.get(i)) + carry) / BASE;
                l1.set(i, Character.forDigit((Character.getNumericValue(l1.get(i)) + carry) % BASE, 10));
                carry = tempCarry;
                --i;

                if (DEBUG) {
                    System.out.println("second shorter with carry");
                    System.out.println(l1.toString());
                }
            } while (carry != 0 && i >= 0); //while we haven't reached the beginning of l1 and there is still a carry

            //if there is a carry on the last digit, add it to the front
            if (carry != 0) {
                l1.add(0, Character.forDigit(carry, 10));

                if (DEBUG) {
                    System.out.println(l1.toString());
                }
            }
        }
        //else if i has reached the end of its integer but j hasn't
        else if (i < 0 && j >= 0) {
            //loop through the rest of l2
            do {
                //if there is no carry add the digits to the front of l1
                if (carry == 0) {
                    l1.add(0, l2.get(j));
                }
                //else account for carry, calculate new carry, and add the digit
                //to the front of l1
                else {
                    tempCarry = (Character.getNumericValue(l2.get(j)) + carry) / BASE;
                    l1.add(0, Character.forDigit((Character.getNumericValue(l2.get(j)) + carry) % BASE, 10));

                    if (DEBUG) {
                        System.out.println(l1.toString());
                    }

                    carry = tempCarry;
                }
                --j;

                if (DEBUG) {
                    System.out.println("first short");
                    System.out.println(l1.toString());
                }
            } while (j >= 0);

            //if there is a carry on the last digit, add it to the front
            if (carry != 0) {
                l1.add(0, Character.forDigit(carry, 10));
            }
        }

        if (DEBUG) {
            System.out.println(l1.toString());
        }

    } //end addBigInts


    /* pre: takes in an ArrayList<Character> (list) that stores an integer
     *      value, and an integer (length)
     * post: returns length digits of the integer stored in list as a String
     * return: a String representation of the integer stored in list
     */
    public static String bigIntToString(ArrayList<Character> list, int length) {
       String result = "";
       int i;

       //loop through the ArrayList appending each digit to the String
       for (i = 0; i < list.size() && i < length; i++) {
           result += list.get(i);
       }

       return result;
    }


    /* pre: takes in an ArrayList<Character> (list) that stores an integer value
     * post: returns the whole integer stored in list as a String
     * return: a String representation of the whole integer stored in list
     */
    public static String bigIntToString(ArrayList<Character> list) {
        //call the other bigIntToString with the length of the list
        return bigIntToString(list, list.size());
    }


    /* pre: takes in a String[] (args) containing command line arguments
     * post: prints the sum of the integers in a file
     */
    public static void main(String[] args) {

        FileInputStream file;

        //attempt to open the file for reading
        try {
            file = new FileInputStream(new File(FILE_PATH));
        }
        //handle file not found exception
        catch(FileNotFoundException e) {
            System.out.println("File not found!");
            return;
        }

        ArrayList<Character> total = new ArrayList<Character>(50); //store the total value
        ArrayList<Character> temp = new ArrayList<Character>(50); //store a number to be added to total

        int c; //the integer representation of a character in the file
        //attempt to read in from the file
        try {
            //read until the next newline
            while ((c = file.read()) != '\n') {
                if (c != '\r') { //skip carridge returns (because Windows ends lines with \r\n)
                    total.add((char) c); //initialize total to the first number
                }
            }
            //loop through the rest of the file
            while ((c = file.read()) != -1) {
                if (c == '\r') {
                    continue; //skip carridge returns (because Windows ends lines with \r\n)
                }
                else if (c != '\n') {
                    temp.add((char) c);
                }
                else if (c == '\n') { //newline means we've finished a number
                    addBigInts(total, temp); //add to total
                    temp.clear(); //clear temp ArrayList
                }
            }
            addBigInts(total, temp); //add last number to total

            //print results
            System.out.println("Full sum: " + bigIntToString(total));
            System.out.println("First 10 digits: " + bigIntToString(total, 10));

        }
        //handle I/O Exceptions
        catch(IOException e) {
            System.out.println("An IOException has occurred!");
            return;
        }

        //attempt to close FileInputStream
        try {
            file.close();
        }
        catch(Exception e) {
            //no one cares if it doesn't work
        }
    } //end main
} //end class LargeSum

