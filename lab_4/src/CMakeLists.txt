add_executable (lab_4 main.cpp drawing.cpp drawing.h square.cpp square.h circle.cpp circle.h figure.cpp figure.h)

add_custom_target(run_lab_4 DEPENDS lab_4
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_4
)