////////////////////////////////////////////////////////////////////////////
//
//  VIRIX Source File.
//  Copyright (C) 2024 S/N: V-01
// -------------------------------------------------------------------------
//  File name:   gfx_openxr.c
//  Version:     v1.00
//  Created:     17/07/24 by V.
//  Description: 
// -------------------------------------------------------------------------
//  This file is licensed under the LGPL ver 2.1 License
//
////////////////////////////////////////////////////////////////////////////

#include "virix.h"
#include "system.h"
#include "VHatesOpenxr.h"

static void openxr_preinit(){
	VLOGNF("OpenXR", "Preinitialized openxr");


}

static void openxr_graphicsinit() {
	VLOGNF("OpenXR", "Openxr graphics initialized");

}

#ifdef VIRIX_DEBUG
static void openxr_debug_dump() {
	xrsuxDumpInstanceInfo();

}

#endif

VPREINIT(openxr_register){
	vrtinitCheckInit();
	mdinitJob* Openxr = vrtinitAddJob("openxr_preinit", &openxr_preinit);
	mdinitAddDep(Openxr, "virix_core");

	#ifdef VIRIX_DEBUG
	mdinitJob* OpenxrDump = vrtinitAddJob("openxr_debug_dump", &openxr_debug_dump);
	mdinitAddDep(Openxr, "openxr_debug_dump");

	#endif

	mdinitJob* Graphics = vrtinitAddJob("openxr_graphicsinit", &openxr_graphicsinit);
	mdinitAddDep(Graphics, "virix_core");
	mdinitAddDep(Graphics, "openxr_preinit");
	mdinitAddDep(Graphics, "vk_base");

}
