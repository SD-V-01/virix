////////////////////////////////////////////////////////////////////////////
//
//  VIRIX Source File.
//  Copyright (C) 2024 S/N: V-01
// -------------------------------------------------------------------------
//  File name:   virix.c
//  Version:     v1.00
//  Created:     16/07/24 by V.
//  Description: 
// -------------------------------------------------------------------------
//  This file is licensed under the LGPL ver 2.1 License
//
////////////////////////////////////////////////////////////////////////////

#include "vrt.h"
#include "virix.h"

void vrt_preInitUsr(){


}

static void testInitTestJobInit() {
	vsys_writeConsoleNullStr("Initializing \"TestJob\"\n");

}

static void testInitTestJobInit2() {
	vsys_writeConsoleNullStr("Initializing \"TestJob2\"\n");

}

static void testInit() {
	mdInitState TestState;
	mdinitCreateState(&TestState);

	mdinitJob* TestJob = mdinitGetNewJobPtr(&TestState, "TestJob", &testInitTestJobInit);
	mdinitAddDep(TestJob, "TestJob2");
	mdinitAddDep(TestJob, "Nonexsitant dependency");
	//mdinitDumpJobToStdout(TestJob);
	mdinitJob* TestJob2 = mdinitGetNewJobPtr(&TestState, "TestJob2", &testInitTestJobInit2);

	mdinitDumpStateToStdout(&TestState);

	mdinitRunState(&TestState);

}

//NOTE(V): To anyone who is not familiar with my no-libc way of working, vrt_usrCode is main
//int main(int argc, char argv[]){

void vrt_usrCode() {
	testInit();

}
