add_executable (lab_11 main.cpp VectoredList.cpp VectoredList.h)

add_custom_target(run_lab_11 DEPENDS lab_11
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_11
)