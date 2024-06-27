
target_include_directories(
    FaultManager_lib 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)


set(
    EXAMPLE_1_SRC
    main.c
    Module1/mod1.c
    Module2/mod2.c
    Module3/mod3.c
)

add_executable(
    FaultManager_Example
    ${EXAMPLE_1_SRC}
)

target_include_directories(
    FaultManager_Example
    PUBLIC
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(
    FaultManager_Example 
    FaultManager_lib
)
