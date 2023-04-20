add_executable (lab_3 main.cpp square.cpp circle.cpp square.h circle.h drawing.cpp drawing.h)

add_custom_target(run_lab_3 DEPENDS lab_3
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_3
)