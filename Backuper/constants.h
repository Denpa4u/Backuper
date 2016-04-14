#pragma once

#include <windows.h>

#define BLACK 0
#define BLUE 1
#define YELLOW 6
#define WHITE 7
#define GREY 8
#define LPURPLE 13 // L = Light
#define LWHITE 15

// Toggle visibility of the cursor in the console window
static void toggleConsoleCursor() {
	static auto outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(outputHandle, &cursorInfo);
	cursorInfo.bVisible = !cursorInfo.bVisible;
	SetConsoleCursorInfo(outputHandle, &cursorInfo);
}

// Sets the position of the cursor in the terminal
static void xy(SHORT x, SHORT y) {
	static auto outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(outputHandle, { x, y });
}

// Sets the foreground and background colour to render following text in (sc = Set Colour)
static void sc(WORD fg, WORD bg = BLACK) {
	static auto outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(outputHandle, fg + bg * 16);
}