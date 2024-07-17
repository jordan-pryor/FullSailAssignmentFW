//
// Created by Jordam on 7/16/2024.
//
#include "../Headers/Console.h"
#include <iostream>

using namespace std;

const string Console::ESC = "\x1B";
int Console::windowWidth = 100, Console::windowHeight = 50;

void Console::resizeWindow(int width, int height)
{
    windowWidth = width;
    windowHeight = height;
    cout << ESC << "[8;" << height << ";" << width << "t";
}
void Console::reset()
{
    cout << ESC << "[0m";
}

void Console::clear()
{
    cout << ESC << "[2J" << ESC << "[H"; //clears the screen and moves the cursor to the top-left
}

void Console::setCursorPosition(int x, int y)
{
    cout << ESC << "[" << y << ";" << x << "H";
}

void Console::setCursorLeft(int x)
{
    cout << ESC << "[" << x << "G";
}

void Console::Write(string message)
{
    cout << message;
}

void Console::Write(string message, ConsoleColors foreColor, ConsoleColors backColor)
{
    setForegroundColor(foreColor);
    setBackgroundColor(backColor);
    cout << message;
    reset();
}

void Console::writeLine(std::string message)
{
    cout << message << std::endl;
}

/*void Console::WriteCentered(const std::string& message, ConsoleColor color) {
    // Get console width
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    else {
        consoleWidth = 80;  // Default width if unable to get info
    }

    // Calculate padding
    int padding = (consoleWidth - message.length()) / 2;
    if (padding > 0) {
        std::cout << std::string(padding, ' ');
    }

    // Print the message
    WriteLine(message, color);
}*/

void Console::writeLine(string message, ConsoleColors foreColor, ConsoleColors backColor)
{
    setForegroundColor(foreColor);
    setBackgroundColor(backColor);
    cout << message;
    reset();
    cout << std::endl;
}

void Console::setForegroundColor(ConsoleColors foreColor)
{
    cout << ESC << "[" << foreColor + 30 << "m";
}

void Console::setForegroundColor(int r, int g, int b)
{
    cout << ESC << "[38;2;" << r << ";" << g << ";" << b << "m";
}

void Console::setBackgroundColor(ConsoleColors backColor)
{
    cout << ESC << "[" << backColor + 40 << "m";
}

void Console::setBackgroundColor(int r, int g, int b)
{
    cout << ESC << "[48;2;" << r << ";" << g << ";" << b << "m";
}
