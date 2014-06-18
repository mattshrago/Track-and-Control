
#include <sstream>
#include <string>
#include <iostream>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <Windows.h>

using namespace cv;
using namespace std;


//default capture width and height
const int FRAME_WIDTH = 640;
const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const double RATIO_WIDTH = (double) SCREEN_WIDTH / (double) FRAME_WIDTH;
const int FRAME_HEIGHT = 480;
const int SCREEN_HEIGHT =  GetSystemMetrics(SM_CYSCREEN);

int __x = -1;
int __y = -1;
double _y_speed = 4.0;
double _x_speed = 2.0;
bool already_resized = false;
LPCSTR window_name_1 = "TACS - Microsoft Visual Studio";
LPCSTR window_name_2= "WIT";
LPCSTR window_name_3 = "C:\\Users\\mossr\\Desktop\\WIT\\Physics Research\\src\\modeling\\run.jl (milkywaymodel) - Sublime Text 2 (UNREGISTERED)";
LPCSTR window_name_4 = "videos";
HWND window_1 = FindWindow(NULL, TEXT(window_name_1));
HWND window_2 = FindWindow(NULL, TEXT(window_name_2));
HWND window_3 = FindWindow(NULL, TEXT(window_name_3));
HWND window_4 = FindWindow(NULL, TEXT(window_name_4));

void moveWindow(int x, int y) {
	HDESK desktop = NULL;

	//EnumWindows(EnumWindowsProc, NULL);

	//Updates the tracked position as the center.
	if(__x < 0)
		__x = x;
	if(__y < 0)	
		__y = y;

	//	moveWindow(windowName, x * RATIO_WIDTH, y);

	//Find window by handle name (also see EnumDesktopWindows())
	int x_update = (x - __x) + 200;
	int y_update = SCREEN_HEIGHT/2 - (SCREEN_HEIGHT*0.75)/2;// -(y - __y);

	x_update *= _x_speed;
	SetWindowPos(window_1, HWND_NOTOPMOST, x_update, y_update, 0, 0, SWP_NOSIZE);
	SetWindowPos(window_2, HWND_NOTOPMOST, x_update * .2, y_update, 0, 0, SWP_NOSIZE);
	SetWindowPos(window_3, HWND_NOTOPMOST, x_update * .40, y_update, 0, 0, SWP_NOSIZE);
	SetWindowPos(window_4, HWND_NOTOPMOST, x_update * .80, y_update, 0, 0, SWP_NOSIZE);
	
	//SetWindowPos(window_4, HWND_TOP, x_update, y_update, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_SHOWWINDOW);
	return;
}

void showWindow(HWND window, int offset)
{
	int width = SCREEN_WIDTH/2;
	int height = SCREEN_HEIGHT*0.75;
	int x = SCREEN_WIDTH/2 - width/2 + offset;
	int y = SCREEN_HEIGHT/2 - height/2;

	SetWindowPos(window, HWND_NOTOPMOST, x, y, width, height, SWP_SHOWWINDOW);
}

void showPerspective(int x, int y)
{
	if(!already_resized) {
		showWindow(window_1, 0);
		showWindow(window_2, 0);
		showWindow(window_3, 0);
		showWindow(window_4, 0);
		already_resized = true;
	}
	moveWindow(x, y);
}
