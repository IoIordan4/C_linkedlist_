# CMakeList.txt : CMake project for Link_Cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (nxp_c_ll "LL_Test.c" "linked_list.c" "linked_list.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET nxp_c_ll PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
