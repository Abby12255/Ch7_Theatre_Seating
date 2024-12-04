#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <fstream>

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
    string  yn;
    
  Mason();
  Abby();
  Jullian();
  
  cout << "do you want to see a list of the seats that are sold(yn)\n";
  cin >> yn;
  if (yn == "y" || yn == "Y" || yn == "yes" || yn == "Yes")
  {
      Seb();
  }
}
/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
void Mason()
{
  
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

    int counter, counter2, soldseats = 0, notsold = 0, counter3 = 0;
    string seatslist;
    ofstream outfile;
    ifstream infile;
    const int collumns = 30;
    const int rows = 15;
    outfile.open("soldseatss.txt");

    /*
    string seats[rows][collumns] =  { {"#", "#", "#", "#", "#", "*", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "*", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        { "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#","#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "*", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} ,
    {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"} };
        */
    for (counter = 0; counter < 15; counter++)
    {
        for (counter2 = 0; counter2 < 30; counter2++)
        {
            cout << seats[counter][counter2];
            if (seats[counter][counter2] == "#")
            {
                notsold++;
            }
            else
            {

                soldseats++;
                outfile << "the seat in row " << counter << " collumn " << counter2 << " is not available\n";


            }
        }
        cout << "\n";


    }
    outfile.close();
    cout << "there are " << soldseats << " sold seats\nthere are " << notsold << " seats available\n";
    infile.open("soldseatss.txt");
    while (infile >> seatslist)
    {
        counter3++;
        cout << seatslist << " ";
        if (counter3 == 10)
        {
            cout << endl;
            counter3 = 0;
        }
    }
    
}
