//
//  main.cpp
//  QuarterlyCalc
//  Created by Adams Daouda on 1/16/20.
//  Copyright © 2020 Adams Daouda. All rights reserved.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main ( void )
{
  //Variable declarations, stores salesperson's name, each sales amount, total sales, and average
  double sales_amount = 0;
  double total_sales = 0;
  double avg_sales = 0;
  double sales = 0;
  const int num_months = 3;
  int i;
  char repeat = 'Y';
  string name, dummy;
  
  //Allow user to run program again
  do
  {
    //Resets total to process another salesperson if desired
   total_sales = 0;
   
    //Read name
   cout << "Please enter employee's full name " << endl;    // use getline to read a name
   getline(cin, name);
    //Reads sales
    for(i = 1; i <= num_months; i++)
    {
       do
       {
        // Prompt and read the monthly sale
          cout << "Enter the sales for the month" << endl;
          cin >> sales;
        // If sales is less than 0, prompt error info and need to read again
         if (sales <0)
         {cout << "WRONG! You can't have negative sales unless you gave it all away" << endl;
         cout << "If this is the case, your fired. If not, re-enter your sales" << endl;}
       }while(sales<0);
       
       total_sales = total_sales + sales;       // add sales to tota
       
    }
    avg_sales = total_sales/num_months;
    cout << setprecision(2) << fixed << showpoint;
    cout << "The total sales for " << name << " is: $" << total_sales << endl;    // format the output
    cout << "The average sales for " << name << " is: $" << avg_sales << endl;
    cout << "Do you want to calculate another employee's sales? Y or N" << endl;
    cin >> repeat;
  getline(cin, dummy);
  } while (repeat == 'Y' || repeat == 'y');
     
return 0;
}
