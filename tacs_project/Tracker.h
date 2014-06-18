#ifndef TRACKER_H
#define TRACKER_H

#include <opencv\cv.h>
using namespace cv;

void update(Point xy);
Point receiveUpdate();

#endif