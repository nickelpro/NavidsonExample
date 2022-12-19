cmake_minimum_required(VERSION 3.25)

project(NavidsonRecord LANGUAGES CXX VERSION 1.5.97)

add_library(house SHARED)
target_compile_features(house PRIVATE cxx_std_23)
target_sources(house PRIVATE hallway.cpp)
target_sources(house PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES include/labyrinth.hpp
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/navidson.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/navidson.pc
  @ONLY
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/navidson.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/navidson-config-version.cmake
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/navidson-config-version.cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/navidson-config.cmake
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/navidson
)

install(TARGETS house
  EXPORT navidsonTargets
  FILE_SET HEADERS
)

install(EXPORT navidsonTargets NAMESPACE nvr:: DESTINATION ${CMAKE_INSTALL_DATADIR}/navidson)
