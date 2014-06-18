#include <set>
#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
	
const int resolutionX = GetSystemMetrics(SM_CXSCREEN); //Screen Resulution x
const int resolutionY = GetSystemMetrics(SM_CYSCREEN); //Screen Resulution y
time_t away_time;
time_t last_visible_time;

//Will determine if the user has left the field of view and will put the computer to sleep.
void putToSleep()//POINT pos)
{
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
}

void sleep(int x, int y, int delay) 
{ 
	if(x == 0 && y == 0)
	{
		time(&away_time);
		int counting_time = away_time - last_visible_time;
		if(counting_time == delay)
		{
			putToSleep();
			SetCursorPos(resolutionX/2, resolutionY/2);
		}
	}
	else
	{
		time(&last_visible_time);
	}
}