//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 3, Random Walk in 2D        Filename: prog3.cpp
// Due Date: 10/10/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
//  This program simulates a man that starts at the origin of a 2D surface
//  and then makes 100 moves each of 1 unit in the x or y direction.  The 
//  program determines the man's distance from the origin after his moves.
//  This simulation is run 1 million times and then the maximum distance
//  from the origin and the average distance from the origin the man got.
//  This simulation can be repeated.
//-------------------------------------------------------------------------


#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <time.h> //for Windows, to enable random # gen to work

int main() 
{
  //Declare Variables
  int ixloc, iyloc, imove;
  float fdist, fmaxdist, favgdist, fsumdist;
  char cAgain;   //To ask user if wants calculation repeated
      
  //Seed the Random Number generator
  srand(time(0));
   
  //First loop for entire calculation 
  do
  { 
    //Reset the values of fmax and fsum to 0
    fmaxdist=-1;
    fsumdist=0;
    
    //Loop for running simulation 1 million times
    for(int j=1;j<=1000000; j++)
    { 
      //Reset man's position to 0
      ixloc=0;
      iyloc=0;
      
      
      //Loop for making 100 moves     
      for(int i =1; i <=100; i++)
      { imove = rand()%4+1;  
 
        if(imove==1)
         { ixloc = ixloc-1;
           iyloc = iyloc-1;
         }       
        if(imove==2)
         { ixloc = ixloc+1;
           iyloc = iyloc+1;
         } 
        if(imove==3)
         { ixloc = ixloc-1;   
           iyloc = iyloc+1;
         }        
        if(imove==4)
         { ixloc = ixloc+1;
           iyloc = iyloc-1;
         }  
       }
      
      fdist=sqrt(ixloc*ixloc + iyloc*iyloc);
      fsumdist=fdist+fsumdist;
      
      if(fdist>fmaxdist)
       fmaxdist = fdist; 
         
    }
    
    //Calculate the Average distance 
    favgdist=fsumdist/1000000;
    
    //Output Results
    cout<<"The longest distance away from the origin is "<<fmaxdist<<endl;   
    cout<<"The average distance away from origin is "<<favgdist<<endl;      
   
    //Ask user if wants to repeat the calculation    
    cout<<"Again? Y/y/N/n" <<endl;
    cin>>cAgain;
  } while(cAgain=='Y' || cAgain == 'y');
  
  return 0;
}     
      

