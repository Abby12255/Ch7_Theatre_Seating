#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

void inputPrices(int numbers[], int size);
void viewSeats();
void viewPrices(int numbers[]);
void viewSales();
void purchaseTicket(int numbers[]);

//Global variables
const int chartSize = 450;
char seatChart[chartSize];

/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
int main()
{
    const int size = 15;
    int numbers[size], choice;
    
    // Initializes the seating list
    for (int counter = 0; counter <= chartSize; counter++)
    {
        seatChart[counter] = '#';
    }

    // Call inputPrices to populate the array
    inputPrices(numbers, size);

    // Loop displays menu, takes input, and calls other programs accordingly
    do
    {
        cout << "\n\tTheatre Seating\n";
        cout << "\n1. View Available Seats";
        cout << "\n2. View Seating Prices";
        cout << "\n3. View Ticket Sales";
        cout << "\n4. Purchase Ticket";
        cout << "\n5. Exit the Program";
        cout << "\nEnter your chioce(1-5): ";
        cin >> choice;

        if (choice == 1)
        {
            viewSeats();
        }
        else if (choice == 2)
        {
            viewPrices(numbers);
        }
        else if (choice == 3)
        {
            viewSales();
        }
        else if (choice == 4)
        {
            purchaseTicket(numbers);
        }
    } while (choice != 5);

    return 0;
}

void inputPrices(int numbers[], int size) 
{
  /*
  inputPrices accepts no arguments
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

void viewSeats()
{
    /* 
    <viewSeats> accepts no arguments
    <it formats and prints the seatChart array>
    <it returns nothing> 
    */

    int rowEnd= 1;

    // Diplaying seat chart
    cout << "\n\t\tSeats\n       123456789012345678901234567890";

    // Loop displays and formats the entire seatChart list 
    for (int counter = 0; counter <= (chartSize - 1); counter++)
    {
        // If statement seperates each row and labels them
        if (counter == 0 ||
            counter == 30 || counter == 60 || counter == 90 ||
            counter == 120 || counter == 150 || counter == 180 ||
            counter == 210 || counter == 240 || counter == 270 ||
            counter == 300 || counter == 330 || counter == 360 ||
            counter == 390 || counter == 420 || counter == 450)
        {
            if (rowEnd > 9) // deducts a space when row names are in the double digits
            {
                cout << endl << "Row " << rowEnd << " ";
                rowEnd++;
            }
            else
            {
                cout << endl << "Row  " << rowEnd << " ";
                rowEnd++;
            }
        }
        cout << seatChart[counter]; // prints each item
    }
    cout << "\n\n\t Legend: * = Sold\n\t\t # = Available\n"; // prints legend
}

void viewPrices(int prices[])
{
    /*
    <viewPrices> accepts 1 arguments
    <It formats and prints the name of each row and its price>
    <It returns nothing>
    */

    cout << "Row\tPrice\n___\t____\n"; //Header
    for (int row = 1; row <= 15; row++) //Loops for the index
    {
        cout << " " << row << "\t" << prices[row - 1] << "\n";
    }
}

void viewSales()
{


}

void purchaseTicket(int prices[]) //Add ticket cost at the end
{
    /*
    purchaseTicket accepts 1 arguments
    <It asks for row and column and updates the seatChart array accordingly>
    <It returns nothing to main>
    */

    // Initialize variables
    string choice, another;
    int row, column, ticket = 0, money = 0;

    // The do while loop allows for more than one ticket to be purchased
    do
    {
        cout << "Do you wish to view the chart of availabe seats\n"
            << "before making your selections? (y/n): ";
        cin >> choice;

        // Calls viewSeats to display the selection
        if (choice == "y")
        {
            viewSeats();
        }

        // Asks user for input for row and column
        cout << "Please enter desired row number (1-15): ";
        cin >> row;
        cout << "Please enter desired seat number (1-30): ";
        cin >> column;

        // Checks if the index is valid
        if (row < 1 || row > 15 || column < 1 || column > 30)
        {
            cout << "Invalid row or column number!" << endl;
            continue;
        }

        // Updates the array accordingly using user input
        seatChart[(row - 1) * 30 + (column - 1)] = '*';
        ticket++;
        money += prices[row - 1];

        // Loops the program again if user chooses "y"
        cout << "Would you like to purchase another seat? (y/n): ";
        cin >> another;
        cout << endl;

    } while (another == "y");
    
    // Displays the number of tickets and the cost
    cout << "You have purchased a total of " << ticket
        << " tickets for a total price of $" << money;
}

