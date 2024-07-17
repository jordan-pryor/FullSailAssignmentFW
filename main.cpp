#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
#include "Lib/Headers/Console.h"
#include "Lib/Headers/Input.h"


void displaySplashScreen() {
    Console::resizeWindow(150, 30);
    Console::clear();

    // Colors for the rainbow effect
    ConsoleColors rainbowColors[] = {
            ConsoleColors::Red,
            ConsoleColors::Yellow,
            ConsoleColors::Green,
            ConsoleColors::Cyan,
            ConsoleColors::Blue,
            ConsoleColors::Purple,
            ConsoleColors::White
    };
    const int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

    const std::string textLines[] = {
            "**************************",
            "* Fifth Circle Developments *",
            "**************************"
    };

    // Calculate the number of iterations to last 2.5 seconds
    const int durationMs = 2500; // 2.5 seconds
    const int delayMs = 100;     // 100 milliseconds delay
    const int iterations = durationMs / delayMs;

    // Display text with rainbow effect
    for (int i = 0; i < iterations; ++i) {
        Console::clear();

        // Cycle through colors and display text
        for (size_t j = 0; j < sizeof(textLines) / sizeof(textLines[0]); ++j) {
            Console::setForegroundColor(rainbowColors[(i + j) % numColors]);
            Console::Write(textLines[j], rainbowColors[(i + j) % numColors]);
        }

        // Delay to create the flashing effect
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }

    // Ensure the text is displayed in the final color
    Console::setForegroundColor(ConsoleColors::White);
    Console::clear();
    for (const auto& line : textLines) {
        Console::Write(line, ConsoleColors::White);
    }
    Console::clear();
}

int main() {
    displaySplashScreen(); // Show splash screen before the main menu
    Console::Write("Hello World \n", ConsoleColors::Purple);
    Input::pressEnter();
    Console::clear();
}