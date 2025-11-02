# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PL_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PL_autogen.dir\\ParseCache.txt"
  "PL_autogen"
  )
endif()
