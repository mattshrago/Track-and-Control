cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(ProjectName TACS)

set(CMAKE_DEFAULT_STARTUP_PROJECT ProjectName)

include_directories(${CMAKE_SOURCE_DIR}/../opencv/build/include
					${CMAKE_SOURCE_DIR}/../sqlite)

link_directories(${CMAKE_SOURCE_DIR}/../opencv/build/x86/vc10/lib
				${CMAKE_SOURCE_DIR}/../sqlite)

add_executable (${ProjectName} 
						${CMAKE_SOURCE_DIR}/FacialRecognitionTracker.cpp
						${CMAKE_SOURCE_DIR}/FacialRecognitionTracker.h
						${CMAKE_SOURCE_DIR}/MouseTracker.cpp
						${CMAKE_SOURCE_DIR}/MouseTracker.h
						${CMAKE_SOURCE_DIR}/ObjectTracker.cpp
						${CMAKE_SOURCE_DIR}/ObjectTracker.h
						${CMAKE_SOURCE_DIR}/TACSMain.cpp
						${CMAKE_SOURCE_DIR}/Tracker.cpp
						${CMAKE_SOURCE_DIR}/Tracker.h
						${CMAKE_SOURCE_DIR}/WindowsGridOrganizer.cpp
						${CMAKE_SOURCE_DIR}/WindowsGridOrganizer.h
						${CMAKE_SOURCE_DIR}/WindowsPerspective.cpp
						${CMAKE_SOURCE_DIR}/WindowsPerspective.h
						${CMAKE_SOURCE_DIR}/SettingsModule.cpp
						${CMAKE_SOURCE_DIR}/SettingsModule.h
						${CMAKE_SOURCE_DIR}/SleepManager.cpp
						${CMAKE_SOURCE_DIR}/SleepManager.h)

target_link_libraries (${ProjectName} 
						opencv_calib3d248d.lib
						opencv_core248d.lib
						opencv_contrib248d.lib
						opencv_imgproc248d.lib
						opencv_highgui248d.lib
						opencv_ml248d.lib
						opencv_video248d.lib
						opencv_features2d248d.lib
						opencv_flann248d.lib
						opencv_gpu248d.lib
						opencv_legacy248d.lib
						opencv_nonfree248d.lib
						opencv_objdetect248d.lib
						opencv_ocl248d.lib
						opencv_photo248d.lib
						opencv_stitching248d.lib
						opencv_superres248d.lib
						opencv_ts248d.lib
						opencv_videostab248d.lib
						sqlite3.lib)
project(${ProjectName})