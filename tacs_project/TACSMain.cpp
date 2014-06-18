#include <iostream>
#include <stdio.h>
#include <opencv\cv.h>
#include <Windows.h>
#include "sqlite3.h"

#include "Tracker.h"
#include "FacialRecognitionTracker.h"
#include "ObjectTracker.h"
#include "MouseTracker.h"

#include "WindowsGridOrganizer.h"
#include "WindowsPerspective.h"
#include "SleepManager.h"

#include "SettingsModule.h"

using namespace std;
using namespace cv;

void getFeed();
void feature_wgo(int x, int y);
void feature_wgo_reset();
void feature_wp(int x, int y);
void feature_sm(int x, int y, int delay);

int hotkey = VK_LCONTROL;
int delay = 5; //Seconds

int main( int argc, const char** argv )
{
	write_to_db();
	setGrid();
	getFeed();
}

void getFeed()
{
	// 1 = ObjectTracker
	// 2 = FacialRecognitionTracker
	// 3 = MouseTracker
	int tracker = 1;
	while(true)
	{

		Point xy;
		switch(tracker){
		case 1:
			xy = track_ot();
			break;
		case 2:
			xy = track_frt();
			break;
		case 3:
			xy = track_mt();
			break;
		}
		
		// Display the coordinates
		std::cout << xy << std::endl;

		
		// 1 = Windows Grid Organizer
		// 2 = Windows Perspective
		// 3 = Sleep Manager
		int feature = 3;
		switch(feature){
		case 1:
			if(GetAsyncKeyState(hotkey)){
				feature_wgo(xy.x, xy.y);
			}
			else
			{
				feature_wgo_reset();
			}
			break;
		case 2:
			if(GetAsyncKeyState(hotkey)){
				feature_wp(xy.x, xy.y);
			}
			break;
		case 3:
			feature_sm(xy.x, xy.y, delay);
			break;
		}
	}
}

void feature_wgo(int x, int y)
{
	updateMiddle(x, y);
}

void feature_wgo_reset()
{
	resetMiddle();
}

void feature_wp(int x, int y)
{
	showPerspective(x, y);
}

void feature_sm(int x, int y, int delay)
{
	sleep(x, y, delay);
}