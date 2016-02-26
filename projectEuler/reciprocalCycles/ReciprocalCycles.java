/* Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
 * CS 370 Assignment 4 ReciprocalCycles.java
 * 02/26/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

import java.util.*;

public class ReciprocalCycles
{
    public static String printDecimal(String digits, boolean repeats, int index)
    {
        String result = "";
        int i;

        if (digits.isEmpty())
        {
            result += 1;
        }
        else if (repeats)
        {
            result += "0.";
            for (i = 0; i < digits.length() - 1; i++)
            {
                if (i == index)
                    result += "(";
                result += digits.charAt(i);
            }
            result += "), cycle length ";
            result += digits.length() - 1 - index;
        }
        else
        {
            result += "0.";
            for (i = 0; i < digits.length() - 1; i++)
                result += digits.charAt(i);
        }

        return result;
    }

    public static void main(String[] args)
    {
        int remainder;
        int digits;
        int count;
        int tmp;
        int denominator = 1; //so the syntax checker doesn't have an aneurysm
        int repeatIndex;
        ArrayList<Integer> remList;
        boolean done;
        boolean repeats;

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

            if (denominator < 1 || denominator > 2000)
            {
                System.out.println("Error: Denominator must be an integer in [1, 2000]. Received '" + denominator +"'.");
                System.exit(-1);
            }
        }

        remList = new ArrayList<Integer>();
        done = false;
        repeats = false;
        remainder = 1;
        digits = 0;
        count = 0;
        repeatIndex = 0;
        tmp = 10;
        while(!done)
        {
            remainder %= denominator;
            digits = tmp / denominator;
            if(remList.contains(remainder))
            {
                done = true;
                repeats = true;
                repeatIndex = remList.indexOf(remainder);
            }
            else if (remainder == 0)
            {
                done = true;
                repeats = false;
            }
            else
            {
                remList.add(new Integer(remainder));
                count++;
                remainder *= 10;
                tmp *= 10;

            }
        }

        //digits now contains all the digits of repeating portion of the decimal
        //plus the first repeating digit
        if (count == 0)
            System.out.println("1/" + denominator + " = " + printDecimal("", repeats, repeatIndex));
        else
            System.out.println("1/" + denominator + " = " + printDecimal((new Integer(digits)).toString(), repeats, repeatIndex));
    }
}
