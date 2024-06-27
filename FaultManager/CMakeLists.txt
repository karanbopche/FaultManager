
set(
    FAULT_MANGER_SRC
    faultManager.c
)

add_library(
    FaultManager_lib
    STATIC
    ${FAULT_MANGER_SRC}
)

