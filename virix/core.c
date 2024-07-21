////////////////////////////////////////////////////////////////////////////
//
//  VIRIX Source File.
//  Copyright (C) 2024 S/N: V-01
// -------------------------------------------------------------------------
//  File name:   core.c
//  Version:     v1.00
//  Created:     19/07/24 by V.
//  Description: 
// -------------------------------------------------------------------------
//  This file is licensed under the LGPL ver 2.1 License
//
////////////////////////////////////////////////////////////////////////////

#include "core.h"

static void virix_core() {

}

VPREINIT(virix_preinit) {
	//vsys_writeConsoleNullStr("!!!!!!!!!!");
	mdinitJob* VirixCore = vrtinitAddJob("virix_core", &virix_core);

}

