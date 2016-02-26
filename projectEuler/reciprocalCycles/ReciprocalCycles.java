/* Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
 * CS 370 Assignment 4 ReciprocalCycles.java
 * 02/26/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

import java.util.*;

public class ReciprocalCycles
{
    public static String printDecimal(ArrayList<Integer> list, boolean repeats, int index)
    {
        String result = "";
        int i;

        if (list.isEmpty())
        {
            result += 1;
        }
        else if (repeats)
        {
            result += "0.";
            for (i = 0; i < list.size(); i++)
            {
                if (i == index)
                    result += "(";
                result += list.get(i);
            }
            result += "), cycle length ";
            result += list.size() - index;
        }
        else
        {
            result += "0.";
            for (i = 0; i < list.size(); i++)
                result += list.get(i);
        }

        return result;
    }

    public static void main(String[] args)
    {
        int remainder;
        int tmp;
        int denominator = 1; //so the syntax checker doesn't have an aneurysm
        int repeatIndex;
        ArrayList<Integer> list;
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

        //find decimal result and store digits in list
        list = new ArrayList<Integer>();
        done = false;
        repeats = false;
        remainder = 0;
        repeatIndex = 0;
        tmp = 1;
        while(!done)
        {
            remainder = tmp % denominator;
            if(list.contains(remainder))
            {
                done = true;
                repeats = true;
                repeatIndex = list.indexOf(remainder);
            }
            else if (remainder == 0)
            {
                done = true;
                repeats = false;
            }
            else
            {
                list.add(new Integer(remainder));
                tmp = remainder * 10;
            }
        }

        //list now contains all the digits of repeating portion of the decimal
        System.out.println("1/" + denominator + " = " + printDecimal(list, repeats, repeatIndex));
    }
}
