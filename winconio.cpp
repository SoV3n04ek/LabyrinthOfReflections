#include <windows.h>

#include "winconio.h"

void GotoXY( int __x, int __y )
{
    COORD kursor;
//    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (GetConsoleScreenBufferInfo(hStdOut, &csbiInfo))
//        if ( __x >= 0 && __x<csbiInfo.dwMaximumWindowSize.X && __y >= 0 && __y<csbiInfo.dwMaximumWindowSize.Y)
        {
            kursor.X = __x;
            kursor.Y = __y;
            SetConsoleCursorPosition( hStdOut, kursor );
        }
};

int WhereX( void )
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbiInfo))
        return csbiInfo.dwCursorPosition.X;
    else return -1;
};

int WhereY( void )
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbiInfo))
        return csbiInfo.dwCursorPosition.Y;
    else return -1;
};

void TextAttr( int __newattr )
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, __newattr );
};

void TextColor( int __newcolor )
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbiInfo))
        SetConsoleTextAttribute(hStdOut, (csbiInfo.wAttributes&0xfff0) | (__newcolor&0x000f));
}

void TextBackground( int __newcolor )
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbiInfo))
        SetConsoleTextAttribute(hStdOut,  (csbiInfo.wAttributes&0xff0f) | ((__newcolor<<4)&0x00f0) ) ;
}

void ClearConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi ))
        return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR) ' ',
                cellCount,
                homeCoords,
                &count
            ))
        return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count
            ))
        return;

    // Move the cursor home
    SetConsoleCursorPosition( hStdOut, homeCoords );
};

void SetConsoleWindowSize(int weigth, int height)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = {(short)weigth, (short)height};
    SMALL_RECT src = {0, 0, (short)(crd.X-1), (short)(crd.Y-1)};
    SetConsoleScreenBufferSize(hStdOut, crd);//
    SetConsoleWindowInfo (hStdOut, true, &src);
    SetConsoleScreenBufferSize (hStdOut, crd);//
}

void SetConsoleCursorSize(unsigned long percent, bool visible)
{   CONSOLE_CURSOR_INFO cci = { percent, visible };
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(hStdOut, &cci);
}
