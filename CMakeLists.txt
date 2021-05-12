#
# Copyright (C) 2020 Adrian Carpenter
#
# This file is part of the Nedrysoft Ribbon library. (https://github.com/nedrysoft/qt-ribbon)
#
# A cross-platform ribbon bar for Qt applications.
#
# Created by Adrian Carpenter on 02/12/2020.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# set up general cmake settings (common to the ribbon library and the designer plugin)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

ADD_DEFINITIONS(-DNEDRYSOFT_LIBRARY_RIBBON_EXPORT)

# create the ribbon library

project(Ribbon)

set(library_SOURCES
    src/RibbonButton.cpp
    src/RibbonButton.h
    src/RibbonCheckBox.cpp
    src/RibbonCheckBox.h
    src/RibbonComboBox.cpp
    src/RibbonComboBox.h
    src/RibbonDropButton.cpp
    src/RibbonDropButton.h
    src/RibbonFontManager.cpp
    src/RibbonFontManager.h
    src/RibbonGroup.cpp
    src/RibbonGroup.h
    src/RibbonLineEdit.cpp
    src/RibbonLineEdit.h
    src/RibbonPushButton.cpp
    src/RibbonPushButton.h
    src/RibbonResources.qrc
    src/RibbonSlider.cpp
    src/RibbonSlider.h
    src/RibbonSpec.h
    src/RibbonTabBar.cpp
    src/RibbonTabBar.h
    src/RibbonToolButton.cpp
    src/RibbonToolButton.h
    src/RibbonWidget.cpp
    src/RibbonWidget.h
)

if(WIN32)
    configure_file("src/Version.h.in" "Version.h")
    list(APPEND library_SOURCES "src/version.rc")
    add_definitions("-DNEDRYSOFT_MODULE_FILENAME=\"${PROJECT_NAME}.dll\"")
    add_definitions("-DNEDRYSOFT_MODULE_NAME=\"${PROJECT_NAME}\"")
endif()

add_library(${PROJECT_NAME} SHARED
    ${library_SOURCES}
)

# discover which Qt version is available

if (NOT DEFINED QT_VERSION_MAJOR)
    if (DEFINED USE_QT_VERSION)
        set(QT_VERSION_MAJOR ${USE_QT_VERSION})
        message(STATUS "Qt${QT_VERSION_MAJOR} has been manually selected")
    else()
        message(STATUS "Detecting Qt version")

        find_package(Qt6 COMPONENTS Core QUIET)
        find_package(Qt5 COMPONENTS Core QUIET)

        if (Qt6_FOUND)
            set(QT_VERSION_MAJOR 6)
        elseif(Qt5_FOUND)
            set(QT_VERSION_MAJOR 5)
        else()
            message(FATAL_ERROR "No valid Qt version was set, and none could be found")
        endif()
        message(STATUS "Detecting Qt version - done")
    endif()

    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core QUIET)

    if (NOT Qt${QT_VERSION_MAJOR}_FOUND)
        message(FATAL_ERROR "Qt${QT_VERSION_MAJOR} could not be found")
    endif()

    message(STATUS "Qt major version: ${QT_VERSION_MAJOR}")
endif()

# end of qt selection/detection

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets REQUIRED)

set(Qt_LIBS "Qt${QT_VERSION_MAJOR}::Core" "Qt${QT_VERSION_MAJOR}::Widgets")

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework AppKit" "-framework Cocoa")

    target_link_libraries(${PROJECT_NAME} stdc++ objc)
endif()

target_link_directories(${PROJECT_NAME} PRIVATE ${NEDRYSOFT_THEMESUPPORT_LIBRARY_DIR})

target_link_libraries(${PROJECT_NAME} ${Qt_LIBS} "ThemeSupport")

target_include_directories(${PROJECT_NAME} PRIVATE "${NEDRYSOFT_THEMESUPPORT_INCLUDE_DIR}")

if(DEFINED NEDRYSOFT_RIBBON_LIBRARY_DIR)
    set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${NEDRYSOFT_RIBBON_LIBRARY_DIR}")
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${NEDRYSOFT_RIBBON_LIBRARY_DIR}")
else()
    message(STATUS "Set NEDRYSOFT_RIBBON_LIBRARY_DIR to set the binary output dir.")
endif()

# designer widgets

option(NEDRYSOFT_RIBBON_BUILD_DESIGNER_PLUGIN "Build Ribbon QtDesigner Plugin" OFF)

if(NEDRYSOFT_RIBBON_BUILD_DESIGNER_PLUGIN)
    project(Nedrysoft.Ribbon)

    add_definitions(-DNEDRYSOFT_RIBBON_DESIGNER_EXPORT)

    find_package(Qt5 COMPONENTS Widgets UiPlugin REQUIRED)

    add_library(${PROJECT_NAME} SHARED
        ${library_SOURCES}
        src/RibbonButtonPlugin.cpp
        src/RibbonButtonPlugin.h
        src/RibbonCheckBoxPlugin.cpp
        src/RibbonCheckBoxPlugin.h
        src/RibbonComboBoxPlugin.cpp
        src/RibbonComboBoxPlugin.h
        src/RibbonDropButtonPlugin.cpp
        src/RibbonDropButtonPlugin.h
        src/RibbonGroupPlugin.cpp
        src/RibbonGroupPlugin.h
        src/RibbonLineEditPlugin.cpp
        src/RibbonLineEditPlugin.h
        src/RibbonPushButtonPlugin.cpp
        src/RibbonPushButtonPlugin.h
        src/RibbonSliderPlugin.cpp
        src/RibbonSliderPlugin.h
        src/RibbonToolButtonPlugin.cpp
        src/RibbonToolButtonPlugin.h
        src/RibbonWidgetsCollection.cpp
        src/RibbonWidgetsCollection.h
        src/RibbonWidgetPlugin.cpp
        src/RibbonWidgetPlugin.h
    )

    target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::UiPlugin "ThemeSupport")

    target_link_directories(${PROJECT_NAME} PRIVATE ${NEDRYSOFT_THEMESUPPORT_LIBRARY_DIR})

    target_include_directories(${PROJECT_NAME} PRIVATE "${NEDRYSOFT_THEMESUPPORT_INCLUDE_DIR}")

    if(APPLE)
        target_link_libraries(${PROJECT_NAME} "-framework AppKit" "-framework Cocoa")
    endif()

    if(DEFINED NEDRYSOFT_RIBBON_DESIGNER_DIR)
        set(PLUGIN_OUTPUT_DIR ${NEDRYSOFT_RIBBON_DESIGNER_DIR})

        file(MAKE_DIRECTORY ${PLUGIN_OUTPUT_DIR})

        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PLUGIN_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PLUGIN_OUTPUT_DIR}")
    else()
        message(STATUS "Set NEDRYSOFT_RIBBON_DESIGNER_DIR to set the binary output dir.")
    endif()
else()
    message(STATUS "Set NEDRYSOFT_RIBBON_BUILD_DESIGNER_PLUGIN to build the designer plugin.")
endif()
