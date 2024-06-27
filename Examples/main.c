#include "FaultManager/faultManager.h"
#include "Module1/mod1.h"
#include "Module2/mod2.h"
#include "Module3/mod3.h"


int main(){
    FaultManger_Set_Fault(MAIN_FAULT_1);
    Init_Mod1();
    Init_Mod3();
    Init_Mod2();
    while(1);
    return 0;
}
