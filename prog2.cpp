//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 2, Factoring Integers       Filename: prog2.cpp
// Due Date: 09/26/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
//  This program takes an integer value and writes out it's prime 
//  factorization.  The program tests the user input for invalid data.
//  It also allows the user to do this for as many numbers as they like.
//----------------------------------------------------------------------


#include <iostream>
using namespace std;
#include <cmath>

int main() 
{
  //Declare Variables
    char cAgain;   //To ask user if wants calculation repeated
    int i, N, Limit;
    
  //First loop for entire calculation 
  do
  {
    //Loop for checking if input data is valid
    do
    {
      // Input/Output Prompts
      cout<< "Enter an integer to compute its prime factorization, >=2" <<endl;
      cin>>N;
      
      //Make sure input data is valid
      if(N <2)
      {
        cout<<"Wrong Input. Number must be >=2." <<endl;
        cout<<"Please try again" <<endl<<endl;
      } 
    } while(N<2);

    cout<< "Prime factors of "<<N<<" are:"<<endl;
   
    Limit = sqrt(N);
    for(i=2;i<=Limit;i++)
      //Do loop for showing factors
      do
      {
        if(N%i==0)
        {
         N=N/i;                //update N   
         cout<< i <<endl;  
        }
      } while(N%i==0);
    
    //code for special case, N is also a factor
    if(N>1)
      cout<<N<<endl;     
      
    //Ask user if wants to repeat the calculation    
    cout<<"Again? Y/y/N/n" <<endl;
    cin>>cAgain;
  } while(cAgain=='Y' || cAgain == 'y');
  
  return 0;
}     
      

