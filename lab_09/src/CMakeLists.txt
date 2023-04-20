add_executable (lab_09 main.cpp)

add_custom_target(run_lab_09 DEPENDS lab_09
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_09
)