cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

project(BSTTree)
include_directories("${CMAKE_SOURCE_DIR}/include")

set(PRINT_VERSION_MAJOR 0)
set(PRINT_VERSION_MINOR 1)
set(PRINT_VERSION_PATCH 0)
set(PRINT_VERSION_TWEAK 0)
set(PRINT_VERSION 
${PRINT_VERSION_MAJOR}.${PRINT_VERSION_MINOR}.${PRINT_VERSION_PATCH}.${PRINT_VERSION_TWEAK})
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")

add_library(tree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/tree.cpp)
add_library(tui STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/tui.cpp)

target_include_directories(tree PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(tui PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(tree tui ${EXAMPLE_NAME})
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin)
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

install(TARGETS tree tui
    EXPORT BSTTree-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT BSTTree-config DESTINATION cmake)
if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  message(STATUS "PROJECT_NAME: [${PROJECT_NAME}]")
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  message(STATUS "PROJECT_NAME_TEST_SOURCES: [${${PROJECT_NAME}_TEST_SOURCES}]")
  target_link_libraries(check tree tui ${DEPENDS_LIBRARIES})
  message(STATUS "DEPENDS LIBS: [${DEPENDS_LIBRARIES}]")
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes") 
    if (${CMAKE_BUILD_TYPE} MATCHES "Coverage")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")
    include(CodeCoverage)
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
    set(LCOV_REMOVE_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/tests/*" "${CMAKE_CURRENT_SOURCE_DIR}/sources/tui.cpp" "/Library/Developer/CommandLineTools/usr/include/c++/v1/*")
    add_executable(unit_tests ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(unit_tests tree tui ${DEPENDS_LIBRARIES})
    setup_target_for_coverage(unit_tests_coverage unit_tests coverage)
    else()
    add_test(NAME unit_tests COMMAND unit_tests "-s" "-r" "compact" "--use-colour" "yes")
    endif()
endif()

include(CPackConfig.cmake)
