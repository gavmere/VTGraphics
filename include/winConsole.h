#ifndef WINCONSOLE_H
#define WINCONSOLE_H

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define ESC "\x1b"
#define CSI "\x1b["

struct Color{
    enum Type{
        BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, DEFAULT
    };
    Type color;
    Color(Type c): color(c){}
    operator Type () const {return color;};
};

class Console{
    public:
        /*
        Contructor, enables Virtual Terminal and retrives columns and rows.
        */
        Console();

        /*
        Enters alternate buffer, aka, creating a buffer outside of the buffer that called it
        params: N/A
        Returns: Nothing
        */
        void EnterAltBuffer();

        /*
        Enters alternate buffer, aka, creating a buffer outside of the buffer that called it
        params: N/A
        Returns: Nothing
        */
        void ExitAltBuffer();

        /*
        Set window title to string passed in, cannot be more then 255 chars
        params: target name for window title
        Returns: Nothing
        */
        void SetWindowTitle(string);

        /*
        Set's the forground/"Text color" To the color passed in
        params: Color
        Returns: Nothing
        */
        void SetForeground(Color);

        /*
        Set's background of terminal to color passed in, **ALL TEXT PRINTED TO TERMINAL HAS THIS BACKGROUND UNLESS CHANGED, DOES NOT CHANGE WHOLE TERMINAL BACKGROUND
        params: N/A
        Returns: Nothing
        */
        void SetBackground(Color);

        /*
        Re-calculates columns and rows in case of window resizing
        params: N/A
        Returns: nothing, changes column and row variables
        */
        void Resize();

        /*
        gets number of columns in terminal
        params: N/A
        Returns: integer number of columns
        */
        int GetWindowColumns();

        /*
        gets number of rows in terminal
        params: N/A
        Returns: integer number of rows
        */
        int GetWindowRows();

        /*
        Sets scrolling margins
        params: row and column
        Returns: nothing
        */
        void SetScrollingMargin(int, int);

        /*
        Clears display **DOES NOT MOVE CURSOR BACK**
        */
        void Clear();

        /*
        Clears line **DOES NOT MOVE CURSOR BACK**
        */
        void ClearLine();

        /*
        Clears line until cursor **DOES NOT MOVE CURSOR BACK**
        */
        void ClearLineToCursor();

        /*
        Clears display up to cursor **DOES NOT MOVE CURSOR BACK**
        */
        void ClearToCursor();

    private:
        bool EnableVT();
        bool GetConsoleScreenInfo();
        int columns;
        int rows;
};


#endif