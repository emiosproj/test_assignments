add_library(ultra_assignment_lib INTERFACE)
target_sources(ultra_assignment_lib INTERFACE
                include/subset_sum.h
                include/bitwise_add.h
                )

target_include_directories(ultra_assignment_lib INTERFACE include/)
