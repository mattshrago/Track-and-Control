#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <Windows.h>
#include "MouseTracker.h"

using namespace cv;
using namespace std;

int scale_width(int x);
int scale_height(int y);

Point track_mt()
{
	POINT p;
	int x, y;

	if (GetCursorPos(&p))
	{
		//cursor position now in p.x and p.y
		x = p.x;
		y = p.y;
	}
	
	waitKey(30);

	Point xy(scale_width(x),scale_height(y));
	return xy;
}

int scale_width(int x)
{
	int min = 0;
	int max = GetSystemMetrics(SM_CXSCREEN);

	int smin = min;
	int smax = 640;

	return abs(min + (x-min)*(smax-smin)/(max-min) - smax);
}

int scale_height(int y)
{
	int min = 0;
	int max = GetSystemMetrics(SM_CYSCREEN);

	int smin = min;
	int smax = 480;

	return min + (y-min)*(smax-smin)/(max-min);
}