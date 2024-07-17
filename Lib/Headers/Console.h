//
// Created by Jordan on 7/16/2024.
//
#pragma once
#include <string>

using namespace std;

enum ConsoleColors{
    Black,
    White,
    Grey,
    Blue,
    Red,
    Purple,
    Green,
    Yellow,
    Cyan,
    Default = 10
};

class Console {
public:
    // Console Size Declares
    static void resizeWindow(int width, int height);
    static int getWindowWidth(){ return windowWidth; }
    static int getWindowHeight(){ return windowHeight; }
    // Cursor Declares
    static void setCursorPosition(int x, int y);
    static void setCursorLeft(int x);
    // Set Fore & Background Colors Declares
    static void setForegroundColor(ConsoleColors foreColor);
    static void setForegroundColor(int r, int g, int b);
    static void setBackgroundColor(ConsoleColors foreColor);
    static void setBackgroundColor(int r, int g, int b);

    // Write/Write-Line Declares
    static void Write(string message);
    static void Write(string message, ConsoleColors foreColor, ConsoleColors backColor = ConsoleColors::Black);
    static void writeLine(string message);
    static void writeLine(string message, ConsoleColors foreColor, ConsoleColors backColor = ConsoleColors::Black);

    // Clear & Reset Declarations
    static void reset();
    static void clear();
private:
    const static string ESC;
    static int windowWidth, windowHeight;
};

