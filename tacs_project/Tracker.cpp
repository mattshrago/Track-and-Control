#include <opencv\cv.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Point xy;

void update(Point input)
{
	xy = input;
	cout << xy << endl;
}

Point receiveUpdate()
{
	return xy;
}