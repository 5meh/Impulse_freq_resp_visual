cmake_minimum_required(VERSION 3.5)

project(Impulse_freq_resp_visual VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(FFTW_DIR "/usr/local/lib/cmake/fftw3")
#set(CMAKE_PREFIX_PATH "/usr/local/")
#list(APPEND CMAKE_PREFIX_PATH "/usr/local/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


add_subdirectory(external/matplotplusplus)
#include_directories(${CMAKE_SOURCE_DIR}/external/matplotplusplus/source)
#set(matplot_DIR external/matplotplusplus)
#set(CMAKE_PREFIX_PATH "/external/matplot")


find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL DataVisualization Charts)
find_package(OpenGL REQUIRED)
find_package(FFTW REQUIRED)

include_directories(${FFTW3_INCLUDE_DIR})

#find_package(matplot REQUIRED)

file(GLOB_RECURSE PROJECT_SOURCES_CPP
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/plotwidget.cpp
    ${CMAKE_SOURCE_DIR}/waterfallplot.cpp
    ${CMAKE_SOURCE_DIR}/Algorithms/ialgorithm.cpp#TODO:mb delete later
    ${CMAKE_SOURCE_DIR}/Algorithms/fftalgorithm.cpp
    #${CMAKE_SOURCE_DIR}/algorithmtemplate.cpp
    #${CMAKE_SOURCE_DIR}/Parser/parser.cpp uncoment if we need cpp file
    ${CMAKE_SOURCE_DIR}/Parser/FileParser/datfileparser.cpp
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/idata.cpp#TODO:remove later
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/datasourcetype.cpp
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/FileData/filedata.cpp
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/FileData/datfiledata.cpp
    ${CMAKE_SOURCE_DIR}/datamanager.cpp
    ${CMAKE_SOURCE_DIR}/UIComponents/ampenvelspectrumwidget.cpp
    #"${CMAKE_SOURCE_DIR}/FIleReader/*.cpp"
)

file(GLOB_RECURSE PROJECT_HEADERS  
    #${CMAKE_SOURCE_DIR}/algorithmtemplate.h
    ${CMAKE_SOURCE_DIR}/Algorithms/ialgorithm.h
    ${CMAKE_SOURCE_DIR}/Algorithms/fftalgorithm.h
    ${CMAKE_SOURCE_DIR}/mainwindow.h
    ${CMAKE_SOURCE_DIR}/datamanager.h
    ${CMAKE_SOURCE_DIR}/plotwidget.h
    ${CMAKE_SOURCE_DIR}/waterfallplot.h
    ${CMAKE_SOURCE_DIR}/Parser/iparser.h
    ${CMAKE_SOURCE_DIR}/Parser/FileParser/fileparser.h
    ${CMAKE_SOURCE_DIR}/Parser/FileParser/datfileparser.h
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/idata.h

    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/datasourcetype.h
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/FileData/filedata.h
    ${CMAKE_SOURCE_DIR}/DataToBeProcessed/FileData/datfiledata.h

    ${CMAKE_SOURCE_DIR}/UIComponents/ampenvelspectrumwidget.h

    #"${CMAKE_SOURCE_DIR}/*.h"
    #"${CMAKE_SOURCE_DIR}/FIleReader/*.h"
)

list(FILTER PROJECT_SOURCES_CPP EXCLUDE REGEX ".*external/")

# Alternatively, you can exclude the entire directory
list(FILTER PROJECT_SOURCES_CPP EXCLUDE REGEX ".*external/matplotplusplus/test/integration/.*")
# Combine source and header files into one variable if needed
set(PROJECT_SOURCES ${PROJECT_SOURCES_CPP} ${PROJECT_HEADERS})

#TODO:remove plotwidget
#set(PROJECT_SOURCES
#    main.cpp
#    waterfallplot.cpp
#    mainwindow.cpp
#    plotwidget.cpp
#    algorithmtemplate.cpp
#    fftalgorithm.cpp

#    mainwindow.h
#    plotwidget.h
#    waterfallplot.h
#    algorithmtemplate.h
#    fftalgorithm.h
#)


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
    ${FFTW3_LIBRARIES}
    Qt5::Charts
)

install(TARGETS Impulse_freq_resp_visual
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
