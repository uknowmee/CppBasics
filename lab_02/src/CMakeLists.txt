add_executable (lab_02 main.cpp square.cpp circle.cpp square.h circle.h)

add_custom_target(run_lab_02 DEPENDS lab_02
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_02
)