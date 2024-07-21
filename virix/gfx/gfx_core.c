////////////////////////////////////////////////////////////////////////////
//
//  VIRIX Source File.
//  Copyright (C) 2024 S/N: V-01
// -------------------------------------------------------------------------
//  File name:   gfx_core.c
//  Version:     v1.00
//  Created:     19/07/24 by V.
//  Description: 
// -------------------------------------------------------------------------
//  This file is licensed under the LGPL ver 2.1 License
//
////////////////////////////////////////////////////////////////////////////

#include "virix.h"

static void vk_base(){
	VLOGNF("GfxCore", "Initialized Vulkan base");

}

VPREINIT(gfx_core_register){
	vrtinitCheckInit();
	mdinitJob* VkBase = vrtinitAddJob("vk_base", &vk_base);
	mdinitAddDep(VkBase, "virix_core");

}

