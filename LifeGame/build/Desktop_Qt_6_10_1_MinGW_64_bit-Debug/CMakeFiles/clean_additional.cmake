# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LifeGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LifeGame_autogen.dir\\ParseCache.txt"
  "LifeGame_autogen"
  )
endif()
