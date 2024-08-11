cmake_minimum_required(VERSION 3.5)

project(Impulse_freq_resp_visual VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)
find_package(OpenGL REQUIRED)

find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.h
    mainwindow.cpp
    plotwidget.h
    plotwidget.cpp
)


add_executable(Impulse_freq_resp_visual
    ${PROJECT_SOURCES}
)
set_target_properties(Impulse_freq_resp_visual PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

add_subdirectory(external/matplotplusplus)
target_link_libraries(Impulse_freq_resp_visual PRIVATE Qt${QT_VERSION_MAJOR}::Widgets matplot Qt5::OpenGL OpenGL::GL)

target_link_libraries(Impulse_freq_resp_visual PRIVATE
    Qt5::Widgets
    Qt5::OpenGL
    OpenGL::GL
    matplot
)

set_target_properties(Impulse_freq_resp_visual PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Impulse_freq_resp_visual
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Impulse_freq_resp_visual)
endif()
