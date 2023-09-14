cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    modular-eda
    VERSION 0.1.0
    DESCRIPTION "EDA for PCB with modular design experience"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    modular-eda_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    modular-eda_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(modular-eda_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(modular-eda_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(modular-eda_exe source/main.cpp)
add_executable(modular-eda::exe ALIAS modular-eda_exe)

set_property(TARGET modular-eda_exe PROPERTY OUTPUT_NAME modular-eda)

target_compile_features(modular-eda_exe PRIVATE cxx_std_20)

target_link_libraries(modular-eda_exe PRIVATE modular-eda_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT modular-eda_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of modular-eda"
  )
endif()

include(cmake/dev-mode.cmake)
