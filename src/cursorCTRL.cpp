#include "../include/cursorCTRL.h"

#include <windows.h>
#include <iostream>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC "\x1b"
#define CSI "\x1b["

using namespace std;

CursorController::CursorController(){
    userCursor = Cursor(Cursor::SHAPE::DEFAULT, Cursor::VISIBLITY::VISIBILE);
}

void CursorController::SetCursor(Cursor cur){
    switch(cur.cursorShape){
        case(Cursor::SHAPE::BLINKING_BLOCK):
            cout << CSI<<"1 q";
            break;
        case(Cursor::SHAPE::STEADY_BLOCK):
            cout << CSI<<"2 q";
            break;
        case(Cursor::SHAPE::BLINKING_UNDERLINE):
            cout << CSI<<"3 q";
            break;
        case(Cursor::SHAPE::STEADY_UNDERLINE):
            cout << CSI<<"4 q";
            break;
        case(Cursor::SHAPE::BLINKING_BAR):
            cout << CSI<<"5 q";
            break;
        case(Cursor::SHAPE::STEADY_BAR):
            cout << CSI<<"6 q";
            break;
        case(Cursor::SHAPE::DEFAULT):
            cout << CSI<<"0 q";
            break;
    }
    switch(cur.visibility){
        case(Cursor::VISIBLITY::HIDE):
            cout << CSI << "?25l";
            break;
        case(Cursor::VISIBLITY::VISIBILE):
            cout << CSI<< "?25h";
            break;
    }
}

void CursorController::CursorUp(int n){
    cout << CSI<< n<< "A";
}
void CursorController::CursorDown(int n){
    cout << CSI<< n<< "B";
}
void CursorController::CursorRight(int n){
    cout << CSI<< n<< "C";
}
void CursorController::CursorLeft(int n ){
    cout << CSI<< n<< "D";
}
void CursorController::CursorNextLine(int n ){
    cout << CSI<< n<< "E";
}

void CursorController::CursorPreviousLine(int n ){
    cout << CSI<< n<< "F";
}

bool CursorController::SetCursorPosition(int x, int y){
    cout << CSI<< y<<";" << x<< "G";
    return true;
}

void CursorController::SaveCursorPosition(){
    cout << CSI<<"s";
}

void CursorController::RestoreCursorPosition(){
    cout << CSI<<"u";
}