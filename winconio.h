#ifndef WINCONIO_H_INCLUDED
#define WINCONIO_H_INCLUDED

enum COLORS
{
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

#ifdef __cplusplus
extern "C"
{
#endif

//!< Перейти к заданому знакоместу в консоли
void GotoXY( int __x, int __y );

//!< Получить текущую X координату курсора
int WhereX( );

//!< Получить текущую Y координату курсора
int WhereY( );

//!< Установить атрибуты (цвет текста и фона) символов для вывода
void TextAttr( int __newattr );

//!< Установить цвет текста символов для вывода
void TextColor( int __newcolor );

//!< Установить цвет фона символов для вывода
void TextBackground( int __newcolor );

//!< Отчистить экран
void ClearConsole();

//!< Установить размер консольного окна (по умолчанию 80 на 25)
void SetConsoleWindowSize(int weigth=80, int height=25);

//!< Установить размер крсора (каретки) консольного окна
void SetConsoleCursorSize(unsigned long percent=1, bool visible=false);

#ifdef __cplusplus
}
#endif

#endif // WINCONIO_H_INCLUDED
