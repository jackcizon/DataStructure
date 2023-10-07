cmake_minimum_required(VERSION 3.22)

project(config)

add_library(config config.c)

#intall lib into local
set_target_properties(config PROPERTIES PUBLIC_HEADER config.h)
install(TARGETS config LIBRARY DESTINATION lib # this will instal to /usr/local/lib
    PUBLIC_HEADER DESTINATION include # this will install to /usr/local/include/
)