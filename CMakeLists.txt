#
# Copyright (C) 2020 Adrian Carpenter
#
# This file is part of the Nedrysoft Ribbon library. (https://github.com/fizzyade/qt-ribbon)
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
    RibbonButton.cpp
    RibbonButton.h
    RibbonCheckBox.cpp
    RibbonCheckBox.h
    RibbonComboBox.cpp
    RibbonComboBox.h
    RibbonDropButton.cpp
    RibbonDropButton.h
    RibbonFontManager.cpp
    RibbonFontManager.h
    RibbonGroup.cpp
    RibbonGroup.h
    RibbonLineEdit.cpp
    RibbonLineEdit.h
    RibbonPushButton.cpp
    RibbonPushButton.h
    RibbonResources.qrc
    RibbonSlider.cpp
    RibbonSlider.h
    RibbonSpec.h
    RibbonTabBar.cpp
    RibbonTabBar.h
    RibbonToolButton.cpp
    RibbonToolButton.h
    RibbonToolButtonPlugin.cpp
    RibbonToolButtonPlugin.h
    RibbonWidget.cpp
    RibbonWidget.h
    ThemeSupport.h
)

if(APPLE)
    list(APPEND library_SOURCES ThemeSupport.mm)
endif()

add_library(${PROJECT_NAME} SHARED
    ${library_SOURCES}
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework AppKit" "-framework Cocoa")

    target_link_libraries(${PROJECT_NAME} stdc++ objc)
endif()

target_link_libraries(${PROJECT_NAME} "Qt5::Widgets")

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
        RibbonButtonPlugin.cpp
        RibbonButtonPlugin.h
        RibbonCheckBoxPlugin.cpp
        RibbonCheckBoxPlugin.h
        RibbonComboBoxPlugin.cpp
        RibbonComboBoxPlugin.h
        RibbonDropButtonPlugin.cpp
        RibbonDropButtonPlugin.h
        RibbonGroupPlugin.cpp
        RibbonGroupPlugin.h
        RibbonLineEditPlugin.cpp
        RibbonLineEditPlugin.h
        RibbonPushButtonPlugin.cpp
        RibbonPushButtonPlugin.h
        RibbonWidgetsCollection.cpp
        RibbonWidgetsCollection.h
        RibbonWidgetPlugin.cpp
        RibbonWidgetPlugin.h
    )

    if(APPLE)
        target_sources(${PROJECT_NAME} "PRIVATE"
            ThemeSupport.mm
            ThemeSupport.h
            )
    endif()

    target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::UiPlugin)

    if(APPLE)
        target_link_libraries(${PROJECT_NAME} "-framework AppKit" "-framework Cocoa")
    endif()

    if(DEFINED NEDRYSOFT_RIBBON_DESIGNER_DIR)
        set(PLUGIN_OUTPUT_DIR ${NEDRYSOFT_RIBBON_DESIGNER_DIR}/Designer/${CMAKE_LIBRARY_ARCHITECTURE}/${Qt5_VERSION})

        file(MAKE_DIRECTORY ${PLUGIN_OUTPUT_DIR})

        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PLUGIN_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PLUGIN_OUTPUT_DIR}")
    else()
        message(STATUS "Set NEDRYSOFT_RIBBON_DESIGNER_DIR to set the binary output dir.")
    endif()
else()
    message(STATUS "Set NEDRYSOFT_RIBBON_BUILD_DESIGNER_PLUGIN to build the designer plugin.")
endif()
