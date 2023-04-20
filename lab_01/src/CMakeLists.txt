add_executable (lab_01 main.cpp)

add_custom_target(run_lab_01 DEPENDS lab_01
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_01
)