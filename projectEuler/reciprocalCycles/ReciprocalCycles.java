/* Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
 * CS 370 Assignment 4 ReciprocalCycles.java
 * 02/26/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

import java.util.ArrayList;
import java.lang.StringBuilder;

public class ReciprocalCycles
{
    /* pre: takes in String digits, boolean repeats and int index
     *      digits contains the digits of the decimal number including the first
     *      repeating digit or is empty if the number isn't a decimal
     * post: builds a string representing the decimal number based on the
     *      decimal digits, whether or not it repeats and the index it
     *      starts repeating at
     * return: a String representing the possibly repeating decimal
     */
    private static String printDecimal(String digits, boolean repeats, int index)
    {
        StringBuilder builder = new StringBuilder();
        int i;

        //if digits is empty then the number is evenly divisible (not a decimal)
        //for this project that means 1/1 which equals 1
        if (digits.isEmpty())
        {
            builder.append(1);
        }
        else if (repeats) //else if the decimal repeats
        {
            //start with "0."
            builder.append("0.");
            for (i = 0; i < digits.length() - 1; i++)
            {
                if (i == index) //when you get to the index where it starts repeating
                    builder.append("("); //add the "("
                builder.append(digits.charAt(i));
            }
            builder.append("), cycle length ");
            builder.append(digits.length() - 1 - index);
        }
        else //else the decimal doesn't repeat
        {
            //start with "0."
            builder.append("0.");
            for (i = 0; i < digits.length() - 1; i++)
                builder.append(digits.charAt(i)); //append all digits
        }

        return builder.toString();
    }

    /* pre: takes in String[] args command line arguments
     *      only one argument <denominator> in [1, 2000]
     * post:
     */
    public static void main(String[] args)
    {
        //declare variables
        int remainder; //the result of modulus
        int digits; //the decimal digits
        int count; //used to count how many digits we have
        int offset; //the offset for division
        int denominator = 1; //initialized so the syntax checker doesn't have an aneurysm
        int repeatIndex; //the index where the decimal starts repeating from
        ArrayList<Integer> list; //a list of all the remainders
        boolean done; //flag to know when we're done
        boolean repeats; //flag to know if the decimal repeats

        //error checking
        if (args.length <= 0)
        {
            System.out.println("Usage: java ReciprocalCycles <denominator>");
            System.exit(-1);
        }
        else if (args.length > 1)
        {
            System.out.println("Usage: java ReciprocalCycles <denominator>");
            System.exit(-1);
        }
        else
        {
            try
            {
                //attempt to parse the argument
                denominator = Integer.parseInt(args[0]);
            }
            catch (Exception e)
            {
                System.out.println("Error: Denominator must be an integer in [1, 2000]. Received '" + args[0] +"'.");
                System.exit(-1);
            }

            //make sure denominator is within the given bounds
            if (denominator < 1 || denominator > 2000)
            {
                System.out.println("Error: Denominator must be an integer in [1, 2000]. Received '" + denominator +"'.");
                System.exit(-1);
            }
        }

        //initialize variables
        list = new ArrayList<Integer>();
        done = false;
        repeats = false;
        remainder = 1;
        digits = 0;
        count = 0;
        repeatIndex = 0;
        offset = 10;

        //main loop
        while(!done)
        {
            remainder %= denominator; //get remainder
            digits = offset / denominator;
            if(list.contains(remainder)) //if list contains remainder
            {
                done = true;
                repeats = true;
                repeatIndex = list.indexOf(remainder);
            }
            else if (remainder == 0) //else if remainder is 0 (decimal terminates)
            {
                done = true;
                repeats = false;
            }
            else //else we keep going
            {
                list.add(new Integer(remainder)); //add remainder to list
                count++; //count this digit
                remainder *= 10; //remainder moves to the next digit
                offset *= 10; //offset moves to the next digit

            }
        }

        //digits now contains all the digits of repeating portion of the decimal
        //plus the first repeating digit

        //if we didn't count any digits, pass our helper an empty string
        if (count == 0)
            System.out.println("1/" + denominator + " = " + printDecimal("", repeats, repeatIndex));
        else
            System.out.println("1/" + denominator + " = " + printDecimal((new Integer(digits)).toString(), repeats, repeatIndex));
    }
}
