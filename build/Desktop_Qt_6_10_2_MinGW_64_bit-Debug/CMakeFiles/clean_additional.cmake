# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExpensesTracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExpensesTracker_autogen.dir\\ParseCache.txt"
  "ExpensesTracker_autogen"
  )
endif()
