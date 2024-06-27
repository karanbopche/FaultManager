
#include "FaultManager/faultManager.h"
#include "mod3.h"

void Init_Mod3()
{
    /* Init failed fault*/
    FaultManger_Set_Fault(MODULE_3_INIT_FAILED_FAULT1);
    Mod3_actions();
}

void Mod3_actions()
{
    FaultManger_Set_Fault(MODULE_3_FAULT2);
}