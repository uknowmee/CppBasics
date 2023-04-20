add_executable (lab_03 main.cpp square.cpp circle.cpp square.h circle.h drawing.cpp drawing.h)

add_custom_target(run_lab_03 DEPENDS lab_03
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_03
)