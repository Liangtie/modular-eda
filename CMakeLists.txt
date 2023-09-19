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


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

# ---- Declare executable ----

qt_add_executable(ModularEda source/main.cpp)


set_target_properties(ModularEda PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(ModularEda PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)


target_compile_features(ModularEda PRIVATE cxx_std_20)

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
