# Installs molecules library
#
#   library: molecules_debug
#   library: molecules_release
#
# Define the following variables
#
#   MOLECULE_INCLUDE_DIR
#   MOLECULE_LIBRARY_DEBUG
#   MOLECULE_LIBRARY_RELEASE
#   MOLECULE_FOUND

file(GLOB _src_files *.cpp)

foreach(build ${BUILD_TYPES})
  string(TOLOWER ${build} buildl)
  add_library(molecules_${buildl} ${_src_files})

  set_target_properties(molecules_${buildl}
    PROPERTIES
    COMPILE_FLAGS ${CMAKE_CXX_FLAGS_${build}}
    )

  target_include_directories(molecules_${buildl}
    SYSTEM PRIVATE
    ${DEBUGGER_INCLUDE_DIR}
    ${CMAKE_BINARY_DIR}
    )

  target_link_libraries(molecules_${buildl}
    ${DEBUGGER_LIBRARY_${build}}
    )

  set(MOLECULE_LIBRARY_${build} molecules_${buildl}
    CACHE STRING 
    "molecules library ${build}")
  mark_as_advanced(MOLECULE_LIBRARY_${build})
endforeach()

set(MOLECULE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..
  CACHE PATH 
  "molecules include directory")
set(MOLECULE_FOUND TRUE CACHE BOOL "FIND MOLECULE LIBRARY")
mark_as_advanced(MOLECULE_INCLUDE_DIR)
mark_as_advanced(MOLECULE_FOUND)
