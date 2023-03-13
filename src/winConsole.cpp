#include "../include/winConsole.h"

#include <windows.h>
#include <iostream>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC "\x1b"
#define CSI "\x1b["

using namespace std;

Console::Console(){
    if(!EnableVT()){
        cout << "Unable to enable Virtual Terminal";
        return;
    }
    
    if(!GetConsoleScreenInfo()){
        cout <<"Unable to retrive screen size";
        return;
    }
}

bool Console::GetConsoleScreenInfo(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE){
        printf("Couldn't get the console handle. Quitting.\n");
        return false;
    }
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return true;
}

bool Console::EnableVT(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return false;
    }
    return true;
}


void Console::EnterAltBuffer(){
    cout << CSI << "?1049h";
}

void Console::ExitAltBuffer(){
    cout.clear();
    cout << CSI << "?1049l";
}

void Console::SetWindowTitle(string str){
    cout << ESC << "]0;" << str << ESC <<"\\";
}   

void Console::SetForeground(Color color){
    switch(color){
        case Color::BLACK:
            cout << CSI << 30 << "m";
            break;
        case Color::RED:
            cout << CSI << 31 << "m";  
            break;
        case Color::GREEN:
            cout << CSI << 32 << "m";  
            break;
        case Color::YELLOW:
            cout << CSI << 33 << "m";  
            break;
        case Color::BLUE:
            cout << CSI << 34 << "m";  
            break;
        case Color::MAGENTA:
            cout << CSI << 35 << "m";  
            break;
        case Color::CYAN:
            cout << CSI << 36 << "m";  
            break;
        case Color::WHITE:
            cout << CSI << 37 << "m";  
            break;
        case Color::DEFAULT:
            cout << CSI << 39 <<"m";
            break;
    }
}

void Console::SetBackground(Color color){
    switch(color){
        case Color::BLACK:
            cout << CSI << 40 << "m";
            break;
        case Color::RED:
            cout << CSI << 41 << "m";  
            break;
        case Color::GREEN:
            cout << CSI << 42 << "m";  
            break;
        case Color::YELLOW:
            cout << CSI << 43 << "m";  
            break;
        case Color::BLUE:
            cout << CSI << 44 << "m";  
            break;
        case Color::MAGENTA:
            cout << CSI << 45 << "m";  
            break;
        case Color::CYAN:
            cout << CSI << 46 << "m";  
            break;
        case Color::WHITE:
            cout << CSI << 47 << "m";  
            break;
        case Color::DEFAULT:
            cout << CSI << 49 <<"m";
            break;
    }
}

int Console::GetWindowRows(){
    return rows;
}

int Console::GetWindowColumns(){
    return columns;
}

void Console::Resize(){
    GetConsoleScreenInfo();
}

void Console::SetScrollingMargin(int numRows, int numColumns){
    cout << CSI<< numRows<<";"<<numColumns<<"r";
}

void Console::Clear(){
    cout << CSI<< "2J";
}
void Console::ClearLine(){
    cout << CSI<< "2K";
}
void Console::ClearLineToCursor(){
    cout << CSI << "1K";
}

void Console::ClearToCursor(){
    cout << CSI << "1J";
}