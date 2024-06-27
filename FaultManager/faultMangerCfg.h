#ifndef FAULT_MANAGER_CFG_H
#define FAULT_MANAGER_CFG_H

#define STD_ON      1
#define STD_OFF     0

/* decides how to implement storing of faults in backend */
/* Stack strategy is useful in system where number of active faults is less but Possible faults is very high */
/* requires less RAM footprint as RAM is allocated to store only active faults */
#define FAULT_STRATEGY_STACK    STD_OFF

/* Map fault is useful in system where there is chance for large number of faults to be active */
/* requires more memory as for each fault a dedicated bit is reserved */
#define FAULT_STRATEGY_MAP      STD_ON

#if (FAULT_STRATEGY_STACK == FAULT_STRATEGY_MAP)
#error "Stack and Map Strategy both can not be set at once, only one strategy is supported"
#endif


#if (FAULT_STRATEGY_STACK == STD_ON)
/* depth of stack for storing faults, this should be kept high enough so stackover flow does not happen */
/* in case of stack overflow error oveflow fault is set and no further faults will be stored in stack */
#define FAULT_STACK_ELEMENT_DEPTH   32
#endif

#if (FAULT_STRATEGY_MAP == STD_ON)

#define MAP_ELEMENT_TYPE        uint32_t
#define BITS_IN_MAP_ELEMENT     (sizeof(MAP_ELEMENT_TYPE)*8)
#define SIZE_OF_ARRAY(x)        (sizeof(x)/sizeof(x[0]))         
#endif

#endif //FAULT_MANAGER_CFG_H
