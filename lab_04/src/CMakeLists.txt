add_executable (lab_04 main.cpp drawing.cpp drawing.h square.cpp square.h circle.cpp circle.h figure.cpp figure.h)

add_custom_target(run_lab_04 DEPENDS lab_04
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_04
)