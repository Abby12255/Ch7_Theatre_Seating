#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

void Mason();
void Abby();
void Jullian();
void Seb();

/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
int main()
{
  Mason();
  Abby();
  Jullian();
  Seb();
}

void Mason()
{
  /*
  Mason accepts no arguments
  Ask for price of each row
  return row price as array to main
  */

  // defining array size
  int size = 5;
  // defining array of size "size"
  int numbers[size];

  // using loop to move to every array element and then
  // using either cin to insert the value given by the
  // user to the array element
  for (int count = 0; count < size; count++) 
  {
      cout << "Enter a number: ";
      cin >> numbers[count];
  }

  // Print the array elements
  cout << "The array elements are: ";
  for (int count = 0; count < size; count++) {
      cout << numbers[count] << " ";
  }

  return numbers;
}
  
/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
void Abby()
{

}
/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
void Jullain()
{

}
/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
void Seb()
{

}
