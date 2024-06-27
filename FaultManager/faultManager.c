#include <string.h>
#include "faultManager.h"

#if (FAULT_STRATEGY_STACK == STD_ON)

typedef struct {
    Faults_T stack[FAULT_STACK_ELEMENT_DEPTH];
    uint16_t top;
    FaultManger_Status_T status;
}FaultStack_T;

FaultStack_T faultStack;


static uint16_t FaultManger_Get_Fault_Index(Faults_T fault);

static uint16_t FaultManger_Get_Fault_Index(Faults_T fault){
    uint16_t i;
    for(i=0;i<faultStack.top;i++){
        if (fault == faultStack.stack[i]){
            break;
        }
    }
    return i;
}

void FaultManger_Set_Fault(Faults_T fault){
    if(faultStack.top < FAULT_STACK_ELEMENT_DEPTH){
        faultStack.stack[faultStack.top++] = fault; 
    }
    else{
        faultStack.status = STACK_OVERFLOW;
    }
}

void FaultManger_Clear_Fault(Faults_T fault){
    uint16_t i = FaultManger_Get_Fault_Index(fault);
    while(i< faultStack.top){
        i++;
        faultStack.stack[i-1] = faultStack.stack[i];
    }
    faultStack.stack[i] = 0;    
}

uint8_t FaultManger_Is_Fault_Set(Faults_T fault){
    return FaultManger_Get_Fault_Index(fault) < faultStack.top;
}


#endif

#if (FAULT_STRATEGY_MAP == STD_ON)

MAP_ELEMENT_TYPE FaultMap[(FAULT_MAXIMUM_INDEX/BITS_IN_MAP_ELEMENT) + 1];
FaultManger_Status_T status;


void FaultManger_Set_Fault(Faults_T fault){
    uint16_t index = fault/BITS_IN_MAP_ELEMENT;
    uint16_t bit  = fault%BITS_IN_MAP_ELEMENT;
    if(index < SIZE_OF_ARRAY(FaultMap)){
        FaultMap[index] |= (1<< bit);
    }
    else{
        status = MAP_OVERFLOW;
    }
}

void FaultManger_Clear_Fault(Faults_T fault){
    uint16_t index = fault/BITS_IN_MAP_ELEMENT;
    uint16_t bit  = fault%BITS_IN_MAP_ELEMENT;
    FaultMap[index] &= ~(1<< bit);
}

uint8_t FaultManger_Is_Fault_Set(Faults_T fault){
    uint16_t index = fault/BITS_IN_MAP_ELEMENT;
    uint16_t bit  = fault%BITS_IN_MAP_ELEMENT;
    return (FaultMap[index] & (1<< bit)) != 0;
}

#endif
