import java.util.*;

import java.lang.*;

import java.io.*;

import java.util.Scanner;


class oddeven

{
	
	public static void main (String[] args) throws java.lang.Exception
	
	{

	
	int n;

		Scanner s = new Scanner(System.in);

		System.out.print("Entere the number");

		n = s.nextInt();
		
		if(n%2==0)
			System.out.print("Entered number is Even number");

		else

			System.out.print("Entered number is Odd number");


	}

}

