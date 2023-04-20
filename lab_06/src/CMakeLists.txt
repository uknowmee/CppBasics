add_executable (lab_06 main.cpp Figure.cpp Figure.h Square.cpp Square.h Circle.cpp Circle.h Drawing.cpp Drawing.h)

add_custom_target(run_lab_06 DEPENDS lab_06
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_06
)