

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;

class posno
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int n;
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		if(n==0)
		{
			System.out.print("Entered number is Zero");
		}
		else if(n>0)
		{
			System.out.print("Entered number is Positive number");
		}
		else if(n<0)
		{
			System.out.print("Entered number is Negative number");
		}
		else
		{
			System.out.print("Invalid input");
		}
	}
}
