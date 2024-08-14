cmake_minimum_required(VERSION 3.5)

project(Impulse_freq_resp_visual VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/matplotplusplus)
#include_directories(${CMAKE_SOURCE_DIR}/external/matplotplusplus/source)
#set(matplot_DIR external/matplotplusplus)
#set(CMAKE_PREFIX_PATH "/external/matplot")


find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL DataVisualization)
find_package(OpenGL REQUIRED)

#find_package(matplot REQUIRED)


set(PROJECT_SOURCES
    main.cpp
    waterfallplot.cpp
    mainwindow.cpp
    plotwidget.cpp

    mainwindow.h
    plotwidget.h
    waterfallplot.h
)


add_executable(Impulse_freq_resp_visual
    ${PROJECT_SOURCES}
)

set_target_properties(Impulse_freq_resp_visual PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(Impulse_freq_resp_visual PRIVATE
    Qt5::Widgets
    Qt5::OpenGL
    Qt5::DataVisualization
    OpenGL::GL
)

install(TARGETS Impulse_freq_resp_visual
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
