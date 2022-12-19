cmake_minimum_required (VERSION 3.8)

project ("strings-c")

add_executable (strings-c "string.cpp" "string.h" "string-id.h" "string-id.cpp" "menu.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET strings-c PROPERTY CXX_STANDARD 20)
endif()
