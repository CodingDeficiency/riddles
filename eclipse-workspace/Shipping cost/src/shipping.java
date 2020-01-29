//Program that calculate shipping cost


import java.io.IOException;
import java.util.Scanner;

public class shipping
{
	final double FIXED = 3.50;     		   
	final double ADDITIONAL = 1.27;       
	final double BASE_WEIGHT = 4.0;

	public static void main(String[] args) throws IOException 
	{
		Scanner scanner = new Scanner(System.in);
		// Declaration and Initialization Statements
		double freight_charge = 0;
			
		//Prompt and read weight of package(s) from user
		System.out.print("what is the weight of the package: ");
		byte weight = scanner.nextByte();
		  		
		  
		//Calculate the freight charge
		  if (weight > 4.0)
		    freight_charge= (3.50+ (weight-4.0) *1.27);    
		  else
		    freight_charge= 3.50;
		  
		  //format output
		  
		 
		  //Display weight and freight charge
		  System.out.println("The weight of the package is "+ weight + "kg");
		  System.out.println("The freight charge is $" + freight_charge);
		  
		return;

	}

}
