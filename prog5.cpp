//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 5, 2-d array and func.      Filename: prog4.cpp
// Due Date: 11/07/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
//  This program asks the user for data to fill a 2-d array. It asks them
//  for number of rows, columns, and number of values to fill. Then the 
//  program totals each row in the array and determines which row has
//  the largest total and displays this value and where it was found.
//  The user can repeat the process.
//-------------------------------------------------------------------------


#include <iostream>
using namespace std;


//The GetData function fills a 2-d array with data.
//Pre: Maximum size of array is 10*10.
//Post: A 2-d, not neccesarily square,array is filled with values obtained
//     from the user.
void GetData(int a[][10], int iRows, int iMaxCols);

//The CalcMax function totals each row in the array and find the maximum
//row total and where this occurs.
//Pre: A filled array of maximum size 10*10 is passed to the function.
//Post: The maximum row total and row number where this occurs are returned.
int CalcMax(int a[][10], int iRows, int iMaxCols, int & imax, int & irownum);

//The PrintMax function prints the results of the CalcMax function.
//Pre:The CalcMax function has been executed.
//Post:The maximum row total and row number where this occurs are printed.
void PrintMax(int imax, int rownum);

int main() 
{
  //Declare Variables
  char cAgain;
  int iRows, iMaxCols, imax, irownum;
  int a[10][10];  

  do
  {
    //Initialize variables
    imax=0;
    irownum=0;
    
    //User input  
    cout<<"Enter number of rows"<<endl;
    cin>>iRows;
    cout<<"Enter number of entries in the longest row"<<endl;
    cin>>iMaxCols;
      
    //Calculate and print out results
    GetData(a, iRows, iMaxCols);
    CalcMax(a, iRows, iMaxCols, imax, irownum);
    PrintMax(imax, irownum);
   
    //Ask user if wants to repeat the calculation
    cout<<"Again? Y/y/N/n" <<endl;
    cin>>cAgain; 
  } while(cAgain=='Y' || cAgain=='y');
    
  return 0;
}
    
      
void GetData(int a[][10], int iRows, int iMaxCols)
{
  int iCols;
  
  for(int i=0;i<iRows; i++)
  {
    cout<<"Enter number of values in Row "<<i+1<<endl;
    cin>>iCols;
    cout<<"Enter all values in Row "<<i+1<<endl;
           
    for(int j=0;j<iCols;j++)
      cin>>a[i][j];
    
    for(int k=iCols;k<iMaxCols;k++)
      a[i][k]=0;
  } 
}  

int CalcMax(int a[][10], int iRows, int iMaxCols, int & imax, int & irownum)
{
  int isum=0;
  
  for(int i=0;i<iRows;i++)
  {
    for(int j=0;j<iMaxCols;j++)
    {
      isum = isum + a[i][j];
    }
    
    if(isum>imax)
    {
      imax=isum;
      irownum=i+1;    
    }
      
    isum=0;     
  }
 
  return imax;
  return irownum;
}    

void PrintMax(int imax, int irownum)
{    
  cout<<"Max total is row "<<irownum<<endl; 
  cout<<"Max total = "<<imax<<endl;     
}     
