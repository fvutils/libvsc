
include(GoogleTest)

find_package(Threads REQUIRED)

include (ExternalProject)

ExternalProject_Add(
  gtest
  URL https://github.com/google/googletest/archive/master.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  # Disable install step
  INSTALL_COMMAND ""
  )
  
ExternalProject_Get_Property(gtest source_dir binary_dir)

# find_package(Gtest)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
    )
    
include_directories("${source_dir}/googletest/include"
				"${source_dir}/googlemock/include")

file(GLOB_RECURSE test_libvsc_SRC
  "*.h"
  "*.cpp"
  )

add_executable(test_libvsc ${test_libvsc_SRC})
target_include_directories(test_libvsc PUBLIC
    "${source_dir}/googletest/include"
    )
target_link_libraries(test_libvsc vsc libgtest libgmock ${Boolector_LIBRARIES})

gtest_discover_tests(test_libvsc)
