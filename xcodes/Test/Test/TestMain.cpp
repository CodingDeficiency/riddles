//
//  TestMain.cpp
//  Test
//
//  Created by Adams Daouda on 1/16/20.
//  Copyright © 2020 Adams Daouda. All rights reserved.
//
#include <iostream>
#include <ctime>     //Header file for time functions: ctime
#include <cstdlib>     //Header file for random number generators: cstdlib
using namespace std;

int main()
{
  //Variable Declaration/Initialization
  int seed = 0;                               //Declaration for seed
  int rand_number= 0;                                 //Declaration for random number
  int no_possibilities = 0;                              //Declaration for number of possibilites
  int no_secs=0;

  //Display graphics window (not used in this lab - but used next week)
 
  

  //Set the seed to be the number of seconds since 1970
  seed = no_secs =time(0);

  //Initialize srand function with seed
  srand(seed);

  //Prompt the user for the number of random values desired for this application
  cout << "Enter desired range of random numbers to generate: ";
  cin >> no_possibilities ;

  //Compute random number (normalized to desired # of possibilites)
  rand_number = rand()%no_possibilities;

  //Display random number generated (10 cases)
  cout << "Random #1 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #2 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #3 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #4 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #5 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #6 generated: " << rand_number << endl;


  rand_number = rand()%no_possibilities;
  cout << "Random #7 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #8 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #9 generated: " << rand_number << endl;

  rand_number = rand()%no_possibilities;
  cout << "Random #10 generated: " << rand_number << endl;
  
  return 0;
}
