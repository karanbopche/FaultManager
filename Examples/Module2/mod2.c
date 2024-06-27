
#include "FaultManager/faultManager.h"
#include "mod2.h"

void Mod2_actions()
{
    FaultManger_Set_Fault(MODULE_2_FAULT4);
}

void Init_Mod2()
{
    /* Init failed fault*/
    FaultManger_Set_Fault(MODULE_2_FAULT2);
    Mod2_actions();
}