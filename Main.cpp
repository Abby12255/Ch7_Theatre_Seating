#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

void Mason(int numbers[], int size);
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
    const int size = 15;
    int numbers[size];

    // Call Mason to populate the array
    Mason(numbers, size);

    Abby();
    Jullian();
    Seb();

    return 0;
}

void Mason(int numbers[], int size) 
{
  /*
  Mason accepts no arguments
  Ask for price of each row
  return row price as array to main
  */

  // using loop to move to every array element and then using cin to insert the value given by user to the array element
  for (int count = 0; count < size; count++) 
  {
      cout << "Please enter ticket price for Row "<<count+1<<": ";
      cin >> numbers[count];
  }
  cout << endl;
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
void Jullian()
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
