#include "FaultManager/faultManager.h"
#include "mod1.h"

void Init_Mod1()
{
    /* Init failed fault*/
    FaultManger_Set_Fault(MODULE_1_INIT_FAILED_FAULT);
    Mod1_actions();
}

void Mod1_actions()
{
    FaultManger_Set_Fault(MODULE_1_FAILED_FAULT);
}