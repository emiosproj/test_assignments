
add_executable(ultra_assignment ultra_assignment.cpp)
target_include_directories(ultra_assignment PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(ultra_assignment ultra_assignment_lib)

target_compile_features(ultra_assignment PUBLIC cxx_std_17)
set_target_properties(ultra_assignment PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_FLAGS "${WARNING_FLAGS}"
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )
