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

// Constant Variables for seatChart
const int ROWS = 15;
const int COLS = 30;

void inputPrices(int numbers[], int size);
void viewSeats(char seatChart[][COLS]);
void viewPrices(int numbers[]);
void viewSales(char seatChart[][COLS], int numbers[]);
void purchaseTicket(int numbers[], char seatChart[][COLS]);

/*
<function name> accepts __ arguments
<describe what it does>
<describe what it outputs or returns>
*/
int main()
{

    //Chart Initialization
    //const int chartSize = 450;
    char seatChart[ROWS][COLS];

    // Variables for inputPrices
    const int size = 15;
    int numbers[size], choice;
    
    // Initializes the seating list; using for loops
    for (int counter1 = 0; counter1 < ROWS; counter1++)
    {
        for (int counter2 = 0; counter2 < COLS; counter2++)
        {
            seatChart[counter1][counter2] = '#';
        }
    }

    // Calls inputPrices
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
            viewSeats(seatChart);
        }
        else if (choice == 2)
        {
            viewPrices(numbers);
        }
        else if (choice == 3)
        {
            viewSales(seatChart, numbers);
        }
        else if (choice == 4)
        {
            purchaseTicket(numbers, seatChart);
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

void viewSeats(char seatChart[][COLS])
{
    /* 
    <viewSeats> accepts 1 arguments
    <it formats and prints the seatChart array>
    <it returns nothing> 
    */
  
    int soldseats = 0, notsold = 0; // Variables for sold seats
  
    // Diplaying seat chart
    cout << "\n\t\tSeats\n       123456789012345678901234567890";

    // Loop displays and formats the entire seatChart list 
    for (int counter1 = 0; counter1 < ROWS; counter1++) // Rows
    {
        if (counter1 >= 9) // deducts a space when row names are in the double digits
        {
            cout << endl << "Row " << counter1 + 1 << " ";
        }
        else
        {
            cout << endl << "Row  " << counter1 + 1 << " ";
        }

        for (int counter2 = 0; counter2 < COLS; counter2++) // Columns
        {
            cout << seatChart[counter1][counter2]; // prints each item
            // Finds number of sold and unsold seats
            if (seatChart[counter1][counter2] == '#')
              {
                  notsold++;
              }
            else
            {
                soldseats++;
            }
        }
    }
    cout << "\n\n\t Legend: * = Sold\n\t\t # = Available\n\n"; // prints legend
    cout << "there are " << soldseats << " sold seat(s)\nthere are " << notsold << " seat(s) available\n";
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

void viewSales(char seatChart[][COLS], int numbers[])
{
    /*
    <viewSales> accepts 2 arguments
    <It finds the number of tickets sold and the amount earned>
    <and displays it>
    <It returns nothing>
    */
  
    int ticketSales = 0, Earnings = 0, variable;
  
    // Uses the seating chart to check how many tickets have been sold
    // Then uses the pricing chart (numbers) to determine how much the seats cost
    for (int counter1 = 0; counter1 < ROWS; counter1++)
    {
        for (int counter2 = 0; counter2 < COLS; counter2++)
        {
            variable = seatChart[counter1][counter2];

            if (variable == '*')
            {
                ticketSales += 1;
                Earnings += numbers[counter1];
            }
        }
    }
    // Output
    cout << "\nA total of " << ticketSales << " tickets have been sold";
    cout << "\nTotal revenue: $" << Earnings;
}

void purchaseTicket(int prices[], char seatChart[][COLS]) //Add ticket cost at the end
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
            viewSeats(seatChart);
        }

        // Asks user for input for row and column
        cout << "Please enter desired row number (1-15): ";
        cin >> row;
        cout << "Please enter desired seat number (1-30): ";
        cin >> column;

        // Checks if the index is valid
        if (row < 1 || row > 15 || column < 1 || column > 30)
        {
            cout << "\nInvalid row or column number!\n" << endl;
            continue;
        }

        // Checks if seat has already been taken
        if (seatChart[row - 1][column - 1] == '*')
        {
            cout << "\nThis seat has already been sold\n" << endl;
            continue;
        }

        // Updates the array accordingly using user input
        seatChart[row - 1][column - 1] = '*';
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