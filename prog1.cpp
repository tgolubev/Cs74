//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 1, Artificial Sweetener     Filename: prog1.cpp
// Due Date: 09/12/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
//  Research has indicated that artificial sweetener in diet soda causes 
//  death in labarotory  mice. The program calculates how much diet soda a
//  human can drink without dying based on the assumption that the by 
//  proportion, the amount of  sweetener needed to kill a mouse is the same
//  as the amount that will kill a human.  The program tests the user input
//  for invalid data, and then calculates the above.  It also allows the user
//  to repeat the calculation.


#include <iostream>
using namespace std;

int main() 
{
  //Declare Variables
  float fkillmouse;  //amount of sweetener to kill mouse (grams)
  float fwtmouse;    //weight of mouse (g)
  float fwthuman;    //weight of human (lbs)
  float fkillhuman;  //amount of sweetener to kill human
  float fsoda;       //number of 16oz cans of soda human can drink before dies  
  
  const float kfCHEMRATIO = .001; //proportion of sweetener in diet soda
  char cAgain;   //To ask user if wants calculation repeated
 
 
  //format floating point values
  cout.setf (ios::fixed);
  cout.setf (ios::showpoint);
  cout.precision(4);
 
  //First loop for entire calculation 
  do
  {
    //Loop for checking if input data is valid
    do
    {
      // Input/Output Prompts
      cout<< "Enter the amount of sweetener to kill a mouse (g), >0" <<endl;
      cin>>fkillmouse;
      cout<< "Enter weight of mouse (g), >0" <<endl;
      cin>>fwtmouse;
      cout<<"Enter weight of human (lbs), >0" <<endl;
      cin>>fwthuman;
      
      //Make sure input data is valid
      if(fkillmouse <=0 || fwtmouse <=0 || fwthuman <=0)
      {
        cout<<"You are an idiot, ALL MUST BE >0" <<endl;
        cout<<"Please try again" <<endl;
      } 
    } while(fkillmouse <=0 || fwtmouse <=0 || fwthuman <=0);

    //Process the data and write out results
       
    fkillhuman = (fwthuman*fkillmouse)/fwtmouse;
    fsoda = fkillhuman/kfCHEMRATIO;
    cout<<"Amount of 16 oz. cans of soda to kill human is " <<fsoda<<endl;
   
    //Ask user if wants to repeat the calculation    
    cout<<"Again? Y/y/N/n" <<endl;
    cin>>cAgain;
  } while(cAgain=='Y' || cAgain == 'y');
  
  return 0 ;
}     
      

