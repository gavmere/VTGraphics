#ifndef CURSORCTRL_H
#define CURSORCTRL_H

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define ESC "\x1b"
#define CSI "\x1b["

struct Cursor{
    enum SHAPE{
        DEFAULT, BLINKING_BLOCK, STEADY_BLOCK, BLINKING_UNDERLINE, STEADY_UNDERLINE, BLINKING_BAR, STEADY_BAR
    };

    enum VISIBLITY{
        VISIBILE, HIDE
    };

    SHAPE cursorShape;
    VISIBLITY visibility;

    Cursor(){
        cursorShape = SHAPE::DEFAULT;
        visibility = VISIBLITY::VISIBILE;
    }

    Cursor(SHAPE cShape, VISIBLITY cVisbility){
        cursorShape = cShape;
        visibility = cVisbility;
    }
    operator SHAPE () const {return cursorShape;};
    operator VISIBLITY () const {return visibility;};
};

class CursorController{
    public:
        /*
        Contructor, sets userCursor to user's default setting
        */
        CursorController();

        /*
        Set's cursor to the cursor object that is passed in
        Params: Cursor struct
        Returns: Nothing
        */
        void SetCursor(Cursor);
        void CursorUp(int = 1);
        void CursorDown(int = 1);
        void CursorRight(int = 1);
        void CursorLeft(int = 1);
        void CursorNextLine(int = 1);
        void CursorPreviousLine(int = 1);
        bool SetCursorPosition(int, int);
        void SaveCursorPosition();
        void RestoreCursorPosition();
    private:
        Cursor userCursor;


};

#endif