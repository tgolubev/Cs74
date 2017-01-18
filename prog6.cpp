//----------------------------------------------------------------------
// Programmer: Tim Golubev             Student ID: 18032108
// Program 6, Triangle Class           Filename: prog6.cpp
// Due Date: 11/28/12                  Class: CSc74, Section C
//----------------------------------------------------------------------
// Program Description:
// This program creates a class called 'Triangle'.  The class is used to 
// identify the type of triangle given when given its side lenghts.
// The program can also tell if two triangles are similar.
//
//-------------------------------------------------------------------------


#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
  public:
    void getTriangle();
    float Perimeter(float &  perimeter);
    //Pre: A valid triangle's side lenghts have been input.
    //Post: Returns the perimeter of the triangle.
     
    bool Equilateral(bool & equi);
    //Pre: A valid triangle's side lengths have been input.
    //Post: Returns true if equilateral and false if is not equilateral.
    
    bool Right(bool & right);
    //Pre: A valid triangle's side lengths have been input.
    //Post: Returns true if is a right triangle and false if is not.
    
    friend bool operator==(const Triangle triangle1, const Triangle triangle2);
    Triangle();  //default constructor
    Triangle(float a, float b, float c);
    void readin();
    void print();
    
  private:
    float x,y,z;    //side lengths of triangle 
    bool valid;     //true if lengths form a triangle
    
};

int main()
{
  Triangle triangle1, triangle2;
  char cAgain1, cAgain2;
  do
  {
    float perimeter=0;
    bool equi=false, right=false;
    triangle1.readin();
    triangle1.Perimeter(perimeter);
    triangle1.Equilateral(equi);
    triangle1.Right(right);
    
    cout<<"Again? Y/y/N/n"<<endl;
    cin>>cAgain1;
  } while(cAgain1=='Y'||cAgain1=='y');
   
   
  do
  {
    cout<<"The program will now compare two triangles."<<endl;
    triangle1.readin();
    triangle2.readin();

    if(triangle1 == triangle2)
     cout<<"The two triangles are similar"<<endl;
    else
     cout<<"The two triangles are not similar"<<endl;
  
    cout<<"Again? Y/y/N/n"<<endl;
    cin>>cAgain2;  
  } while(cAgain2=='Y'||cAgain2=='y');
   
  return 0;
}

float Triangle::Perimeter(float & perimeter)
{
  perimeter = x+y+z;
  cout<<"Perimeter is "<<perimeter<<endl;
  return perimeter;
} 

void Triangle::readin()
{
  do
  {
    cout<<"Enter 3 side lengths of a triangle smallest to largest."<<endl;
    cin>>x;
    cin>>y;
    cin>>z;
    if(x<=0||y<=0||z<=0||(x+y)<=z||(y+z)<=x||(x+z)<=y)
     cout<<"Invalid input. Please try again."<<endl;
  }  while(x<=0||y<=0||z<=0||(x+y)<=z||(y+z)<=x||(x+z)<=y);

}   

bool operator==(const Triangle triangle1, const Triangle triangle2)
{
  return(triangle1.x/triangle2.x == triangle1.y/triangle2.y && 
         triangle1.y/triangle2.y == triangle1.z/triangle2.z);
} 
void Triangle::print()
{
  cout<<"print"<<x<<y<<z<<endl;
}

bool Triangle::Equilateral(bool& equi)
{
 
  if  (x==y && y==z)
   {
    equi = true;
    cout<<"The triangle is equilateral."<<endl;
   }   
  else
   cout<<"The triangle is not equilateral."<<endl; 
return equi; 
}

bool Triangle::Right(bool& right)
{
  if((x*x+y*y)==z*z||(y*y+z*z)==x*x||(x*x+z*z)==y*y)
   {
    right = true;
    cout<<"This is a right triangle."<<endl;
   }
  
  else
   cout<<"This is not a right triangle."<<endl;
   
  return right;
}
  
Triangle::Triangle()
{}
/* float x, y, z;
 
 do
 {
  cout<<"Enter 3 side lengths of triangle"<<endl;
  cin>>x;
  cin>>y;
  cin>>z;
  if(x<=0||y<=0||z<=0||(x+y)<=z||(y+z)<=x||(x+z)<=y)
   cout<<"Invalid data. Please Try Again"<<endl;
   
 } while(x<=0||y<=0||z<=0||(x+y)<=z||(y+z)<=x||(x+z)<=y);
return;
}*/

