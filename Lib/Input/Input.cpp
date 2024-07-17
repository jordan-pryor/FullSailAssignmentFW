//
// Created by Jordan on 7/16/2024.
//

#include "../Headers/Input.h"
#include <iostream>
#include <limits>

using namespace std;

void Input::pressEnter(bool silent){
    if(!silent) cout << "Press ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Input::getMenuSelect(vector<string> menuOptions, string message)
{
    //show the menu options
    //get the user's selection

    for (auto& option : menuOptions)
    {
        cout << option << ::endl;
    }
    return getInteger(message, 1, (int)menuOptions.size());

}

string Input::getString(string message)
{
    cout << "\n" << message << " ";
    string usersInput;
    getline(::cin, usersInput);
    return usersInput;
}

int Input::getInteger(string message, int min, int max)
{
    int number = 0;
    while (true)
    {
        cout << "\n" << message;
        if (cin >> number && number >= min && number <= max)
        {
            clearInputBuffer();
            break;
        }
        clearInputBuffer();
        cout << "\nInvalid number.\n";
    }
    return number;
}



void Input::clearInputBuffer()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

/*
// New function to display centered message and wait for Enter key
void Input::pressEnterCentered(const ::string& message)
{
    // Get the width of the console window (you may need to adjust this based on your console)
    const int consoleWidth = 80; // Adjust based on your console's width

    // Calculate the position to start the message
    int messageLength = message.length();
    int padding = (consoleWidth - messageLength) / 2;

    // Print spaces to center the message
    ::cout << ::string(padding, ' ') << message << ::endl;
    PressEnter();  // Wait for Enter key
}*/
