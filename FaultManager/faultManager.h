#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

#include <stdint.h>
#include "faultMangerCfg.h"

typedef enum {
    FAULT_NONE,
    #include "FaultManager_FaultList.inc"
    FAULT_MAXIMUM_INDEX,
}Faults_T;


typedef enum {
    NO_ERROR,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    MAP_OVERFLOW
}FaultManger_Status_T;


void FaultManger_Set_Fault(Faults_T fault);
void FaultManger_Clear_Fault(Faults_T fault);
uint8_t FaultManger_Is_Fault_Set(Faults_T fault);

#endif //FAULT_MANAGER_H