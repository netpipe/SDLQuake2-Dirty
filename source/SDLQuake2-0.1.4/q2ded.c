// q2ded.c
// dummy client functions for dedicated server

#include "q_shared.h"

qboolean send_packet_now = false;

void (*KBD_Update_fp)(void);

void KBD_Update(void) {
};

void CL_Shutdown (void) {
}

void SCR_BeginLoadingPlaque (void) {
}

void SCR_EndLoadingPlaque (void) {
}

void CL_Drop (qboolean skipdisconnect) {
}


void SCR_DebugGraph (float value, int color) {
}

void CL_Frame (int msec) {
}

void CL_Init (void) {
    KBD_Update_fp = KBD_Update;
    Cvar_ForceSet("dedicated", "1");
}

void Key_Init (void) {
}

void Con_Print (char *text) {
}

void Cmd_ForwardToServer (void) {
}

const char *CL_Get_Loc_There (void) { return ""; }
const char *CL_Get_Loc_Here (void) { return ""; }
