//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 4, Drunkard's Walk          Filename: prog4.cpp
// Due Date: 10/10/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
//  This program simulates the walk of a drunk man that wanders at random,
//  one block at a time, over an 8 block line.  If he reaches the pub, at 
//  block 1 or home at block 8, he stays there.  The program simulates 1 
//  million trips from each starting position of block 2 through 7.  The 
//  program uses a function to simulate each single walk.  It then 
//  calculates and outputs the propotion of the time he ends up at 
//  home and the average number of blocks walked on each trip.
//-------------------------------------------------------------------------

//Note: this is a Linux version. In windows, the random number generator using
//srand(time(0)) doesn't work!

#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <time.h>   //for Windows: to enable to random # generator to work based on time

//Declare global variable
int ihome;   //number of times drunkard reaches home

int main() 
{
  //Declare Variables
  int icount; //number of moves in each single walk 
  int isum;  //total number of moves
  
  //The walk() function simulates a single random 1D walk  
  //Pre: The initial value of iloc must be between 2 and 7
  //Post: Number of moves for single walk is returned and 
  //      global variable ihome is changed based on number
  //      of times that drunkard reaches home.
  int walk(int iloc);
  
  //Seed the Random Number generator
  srand(time(0));            //this only works in linux.
     
  //Loop for each starting point, blocks 2-7
  for(int iloc=2;iloc<=7; iloc++)
  {
    isum=0;
    ihome=0;

    //Loop for repeating walk 1 million times 
    for(int i=1; i<=1000000;i++)
    {
      icount = walk(iloc);
      isum = icount + isum;
    }
    
    //Output results
    cout<<"I =            "<<iloc<<endl;
    cout<<"Total Moves = "<<isum<<endl;
    cout<<"Avg Moves = "<<isum/1000000.0<<endl;
    cout<<"Total Home = "<<ihome<<endl;  
    cout<<"Avg Home = "<<ihome/1000000.0<<endl<<endl<<endl;        
  }
    
return 0;
}    
      
int walk(int iloc)
{
  int imove, icount=0; //random number and number
                       //of moves respectively
   
  //Loop for moving while not at house nor pub 
  do
  { 
    imove = rand()%3+1;  
    if(imove==1 || imove==2)
    {
      iloc = iloc-1;
      icount++;
    }
               
    if(imove==3)
    { 
      iloc = iloc+1;
      icount++;
    }
         
    if(iloc==8)
      ihome++;
          
  } while((iloc>=2 && iloc<=7));
      
return icount;        
}    
   

