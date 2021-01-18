// Shop_Sales.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Saves records to a sequential access file and also
calculates and displays the total of the sales amounts
stored in the file.

Created/revised by Matt Norton
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//fn prototypes
int getChoice();
void addRecords();
void displayTotal();

int main()
{
    //Title graphic
    cout << R"(                                                 
  /$$$$$$  /$$                                  /$$$$$$            /$$                    
 /$$__  $$| $$                                 /$$__  $$          | $$                    
| $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$       | $$  \__/  /$$$$$$ | $$  /$$$$$$   /$$$$$$$
|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$      |  $$$$$$  |____  $$| $$ /$$__  $$ /$$_____/
 \____  $$| $$  \ $$| $$  \ $$| $$  \ $$       \____  $$  /$$$$$$$| $$| $$$$$$$$|  $$$$$$ 
 /$$  \ $$| $$  | $$| $$  | $$| $$  | $$       /$$  \ $$ /$$__  $$| $$| $$_____/ \____  $$
|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/      |  $$$$$$/|  $$$$$$$| $$|  $$$$$$$ /$$$$$$$/
 \______/ |__/  |__/ \______/ | $$____/        \______/  \_______/|__/ \_______/|_______/ 
                              | $$                                                        
                              | $$                                                        
                              |__/                                                        

                    An application for tracking the sales of salespersons

 ============================================================================================                                           
 )" << '\n';

    int choice = 0;
    do
    {
        //get user's menu choice
        choice = getChoice();
        if (choice == 1)
            addRecords();
        else if (choice == 2)
            displayTotal();
        //end if
    } while (choice != 3);
    return 0;
}//end main


//fn definititions:

int getChoice()
{
    //displays menu and retunrs choice
    int menuChoice = 0;
    cout << endl << "Menu Options" << endl;
    cout << "1 Add a Sale Record" << endl;
    cout << "2 Display Total Sales" << endl;
    cout << "3 Exit" << endl;
    cout << "Choice (1, 2, or 3)? ";
    cin >> menuChoice;
    cin.ignore(100, '\n');
    cout << endl;
    return menuChoice;
}//end getChoice fn

void addRecords()
{
    //saves records to a sequential acces file
    string name = "";
    int sales = 0;
    ofstream outFile;

    //open file for append
    outFile.open("Sales.txt", ios::app);

    //if the open was successfil, get the salesperson's name
    //and sales amount and then write the info to the file;
    //otherwise, display an error message

    if (outFile.is_open())
    {
        cout << "Salesperson's name (X to stop): ";
        getline(cin, name);
        while (name != "X" && name != "x")
        {
            cout << "Sales: ";
            cin >> sales;
            cin.ignore(100, '\n');
            outFile << name << '#' << sales << endl;

            cout << "Salesperson's name " << "(X to stop): ";
            getline(cin, name);
        }//end while
        outFile.close();
    }
    else
        cout << "Sales.txt file could not be opened" << endl;
}//end addRecords fn

void displayTotal()
{
    //calculates and displays the toal sales
    string name = "";
    int sales = 0;
    int total = 0;
    ifstream inFile;

    //open file for input
    inFile.open("Sales.txt");

    //if the open was successfil, read the salesperson's name
    //and sales amount, then add the sales amount to the accumulator,
    // and then display the accumulator; otherwise, display an error message

    if (inFile.is_open())
    {

        getline(inFile, name, '#');
        inFile >> sales;
        inFile.ignore();

        while (!inFile.eof())
        {
            total += sales;
            getline(inFile, name, '#');
            inFile >> sales;
            inFile.ignore();
        }//end while
        inFile.close();
        cout << "Total sales $" << total << endl << endl;
    }
    else
        cout << "Sales.txt file could not be opened" << endl;
}//end of displayTotal fn


