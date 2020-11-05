#include<windows.h>
//#include<iosfwd>
using namespace std;

#ifndef Color_H
#define Color_H

//set color values, simply call the color to change disired text instead of memorizing the numbers
enum consolecolor { black = 0, dark_blue = 1, dark_green = 2, dark_aqua = 3, dark_red = 4, dark_purple = 5, 
	dark_yellow = 6, dark_white = 7, gray = 8, blue = 9, green = 10, aqua = 11,	red = 12, purple = 13,
	yellow = 14, white = 15 };


HANDLE console_output;	//Standard Output Handle //SetConsoleTextAttribute requires the use of a handle
consolecolor textcolor, orgtextcolor;

void update_colors()
{
	CONSOLE_SCREEN_BUFFER_INFO consolebuffer;//Struct that stores screen info
	GetConsoleScreenBufferInfo(console_output, &consolebuffer); //Gets the screen dimensions
	textcolor = consolecolor(consolebuffer.wAttributes); //Changes text color
	
}
void consolecol()
{
	console_output = GetStdHandle(STD_OUTPUT_HANDLE);
	update_colors();
	orgtextcolor = textcolor; 
}

void settextcolor(consolecolor tcolor)
{
	int changes = tcolor;
	SetConsoleTextAttribute(console_output, changes);
}

void setcolor(consolecolor tcolor, consolecolor bcolor)
{
	int changes = tcolor;
	SetConsoleTextAttribute(console_output, changes);
}

template<class elem, class colors>
basic_ostream<elem, colors>& operator<<(basic_ostream<elem, colors>& stream, consolecolor col)
{
	stream.flush(); settextcolor(col); return stream;
}
#endif