#ifndef	VRPN_CONFIGURE_H
#define	VRPN_CONFIGURE_H

//--------------------------------------------------------------
/* This file contains configuration options for VRPN.  The first
   section has definition lines that can be commented in or out
   at build time.  The second session has automaticly-generated
   directives and should not be edited. */
//--------------------------------------------------------------

//--------------------------------------------------------//
// EDIT BELOW THIS LINE FOR NORMAL CONFIGURATION SETTING. //
//--------------------------------------------------------//

//-----------------------
// Instructs VRPN not to use any iostream library functions, but
// rather to always use C-style FILE objects.  This is to provide
// compatibility with code that uses the other kind of streams than
// VRPN uses.
#define	VRPN_NO_STREAMS

//-----------------------
// Instructs VRPN to use phantom library to construct a unified
// server, using phantom as a common device, and phantom 
// configuration in .cfg file.
// PLEASE SPECIFY PATH TO GHOSTLIB IN NEXT SECTION IF YOU USE THIS
//#define	VRPN_USE_PHANTOM_SERVER

//-----------------------
// Instructs VRPN to use the high-performance timer code on
// Windows, rather than the default clock which has an infrequent
// update.  At one point in the past, an implementation of this
// would only work correctly on some flavors of Windows and with
// some types of CPUs.
// There are actually two implementations
// of the faster windows clock.  The original one, made by Hans
// Weber, checks the clock rate to see how fast the performance
// clock runs (it takes a second to do this when the program
// first calls gettimeofday()).  The second version by Haris
// Fretzagias relies on the timing supplied by Windows.  To use
// the second version, also define VRPN_WINDOWS_CLOCK_V2.
#define	VRPN_UNSAFE_WINDOWS_CLOCK
#define	VRPN_WINDOWS_CLOCK_V2

//-----------------------
// Instructs VRPN to use the default room space transforms for
// the Desktop Phantom as used in the nanoManipulator application
// rather than the default world-origin with identity rotation.
// Please don't anyone new use the room space transforms built
// into VRPN -- they are a hack pulled forward from Trackerlib.
//#define	DESKTOP_PHANTOM_DEFAULTS

//-----------------------
// Instructs VRPN library and server to include code that uses
// the DirectX SDK (from its standard installation in C:\DXSDK).
// Later in this file, we also instruct the compiler to link with
// the DirectX library if this is defined.
//#define	VRPN_USE_DIRECTINPUT

//-----------------------
// Instructs the VRPN server to create an entry for the Adrienne
// time-code generator.  This is a device that produces time values
// from an analog video stream so that events in the virtual world
// can be synchronized with events on a movie.  The Adrienne folder
// should be located at the same level as the VRPN folder for the
// code to find it.
//#define	INCLUDE_TIMECODE_SERVER

//-----------------------
// Instructs the VRPN library and server to include code to run
// InterSense trackers using their supplied set of driver code.
// This should support more of the trackers than the modified
// serial-port-only Fastrak code supports.  If this is defined,
// the isense.h, types.h, and isense.c files should also be copied into
// the same directory that the vrpn_Configure.h file is located
// in (horrible hack, but there is not a standard installation
// location to put in the Include path).  I can't get this to
// compile correctly with the current release of the DLL code;
// several of the things it is looking for are undefined.
//#define VRPN_INCLUDE_INTERSENSE

//----------------------------------------------------------------//
// DO NOT EDIT BELOW THIS LINE FOR NORMAL CONFIGURATION SETTING.  //
// DO EDIT IF THE LIBRARIES TO BE USED ARE NOT IN STANDARD PLACES.//
//----------------------------------------------------------------//

// Load VRPN Phantom library if we are using phantom server as unified server
// Load SensAble Technologies GHOST library to run the Phantom
#ifdef	VRPN_USE_PHANTOM_SERVER
#pragma comment (lib,"C:/Program Files/SensAble/GHOST/v4.0/lib/GHOST40.lib")
#endif

// Load DirectX SDK libraries and tell which version we need if we are using it.
// If this doesn't match where you have installed these libraries,
// edit the following lines to point at the correct libraries.  Do
// this here rather than in the project settings so that it can be
// turned on and off using the definition above. 
#ifdef	VRPN_USE_DIRECTINPUT
#define	DIRECTINPUT_VERSION 0x0800
#pragma comment (lib, "C:/DXSDK/lib/dxguid.lib")
#pragma comment (lib, "C:/DXSDK/lib/dxerr8.lib")
#pragma comment (lib, "C:/DXSDK/lib/dinput8.lib")
#endif

// Load Adrienne libraries if we are using the timecode generator.
// If this doesn't match where you have installed these libraries,
// edit the following lines to point at the correct libraries.  Do
// this here rather than in the project settings so that it can be
// turned on and off using the definition above. 
#ifdef	INCLUDE_TIMECODE_SERVER
#pragma comment (lib, "../../Adrienne/AEC_DLL/AEC_NTTC.lib")
#endif

#endif
