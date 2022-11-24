## set up model configuration ##

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "DebugRelease")
endif()

# float point operation precision
option(SinglePrecision "Enable single precision" OFF)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
  if (NOT "DEBUG" IN_LIST BUILD_TYPES)
    list(APPEND BUILD_TYPES "DEBUG")
  endif()
endif()

if (CMAKE_BUILD_TYPE MATCHES "Release")
  if (NOT "RELEASE" IN_LIST BUILD_TYPES)
    list(APPEND BUILD_TYPES "RELEASE")
  endif()
endif()
