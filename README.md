Track-and-Control
=================

Software Design and Development with Professor **[Pierre Elysee](mailto:elyseep@wit.edu)** <sup><sup>(1)</sup></sup>

- **[Robert Moss](mailto:mossr@wit.edu)** <sup><sup>(1)</sup></sup>
- **[Aaron Pereira](mailto:pereiraa1@wit.edu)** <sup><sup>(1)</sup></sup>
- **[Matthew Shrago](mailto:shragom@wit.edu)** <sup><sup>(1)</sup></sup>

<sup><sup>(1) Wentworth Institute of Technology | Boston, MA</sup></sup>

## Installation

- Download [CMake](http://www.cmake.org/files/v2.8/cmake-2.8.12.1-win32-x86.exe "CMake") and click **Add CMake to the system PATH for all users** during the installation.
- Download [OpenCV](https://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.4.8/opencv-2.4.8.exe/download "OpenCV") version 2.4.8.
	- Put the *opencv* folder into your *Track-and-Control* directory.
- Run the *build\_project.bat* file (this builds the Visual Studio project with CMake).
- Now you can open **tracking\_module\_build/Debug/TrackingModule.exe** or the Visual Studio project.

## Notes

###### FRONT_END

- **Tracking Module** (TM)
	- *Input*: Raw camera data
	- *Output*: Coordinates of tracked object
	- Methods of approach:
		- Color isolation
			- OpenCV
				- HSV
				- RGB
				- Only filter movement detection
		- Infrared isolation
			- Wiimote as infrared camera
			- Infrared lights facing user
			- Reflection off iris 
		- Facial recognition
			- OpenCV
			- No external hardware necessary
- **Window Controller** (WC)
	- Window Viewer (3D)
	- Window Grid Organizer
		- Left, Right, Top, Bottom, and Middle.
		- hot key + shift = full grid view.
	- Sleep Manager
		- Off screen delay
		- Sleep or screen dim (user setting)
	- All features have a user defined hot key

###### BACK-EN
- [SQLite](http://www.sqlite.org/download.html "SQLite1") for settings.


## Ideas/Features

###### TODO
- Include objectives.