# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\objectTimer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\objectTimer_autogen.dir\\ParseCache.txt"
  "objectTimer_autogen"
  )
endif()
