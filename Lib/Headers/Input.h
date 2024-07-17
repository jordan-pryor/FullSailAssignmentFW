//
// Created by Jordan on 7/16/2024.
//
#pragma once

#include <string>
#include <vector>

using namespace std;

class Input{
public:
    static string getString(string message);
    static int getInteger(string message, int min, int max);
    static int getMenuSelect(vector<string> menuOptions, string message = "Choice?");
    static void pressEnter(bool silent = false);

private:
    static void clearInputBuffer();
};
