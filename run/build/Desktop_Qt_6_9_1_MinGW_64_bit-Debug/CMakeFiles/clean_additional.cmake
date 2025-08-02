# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\run_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\run_autogen.dir\\ParseCache.txt"
  "run_autogen"
  )
endif()
