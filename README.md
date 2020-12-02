# Nedrysoft Ribbon

![ribbon image](https://user-images.githubusercontent.com/55795671/100941548-b5652700-34f1-11eb-975d-5bf284852590.png)

The ribbon library provides a simple ribbon bar implementation for Qt-based applications.

## Features

* Cross-platform and tested under macOS, Windows and Linux
* RibbonWidget is the main ribbon widget.
* RibbonGroup is a container for sub controls.
* RibbonPushButton is a push-button styled for the ribbon.
* RibbonDropButton is a push button with a drop-down button to allow multiple actions.
* RibbonComboBox is a combo box styled for the ribbon.
* RibbonCheckBox is a checkbox styled for the ribbon.
* RibbonLineEdit is a line edit styled for the ribbon.
* RibbonSlider is a slider styled for the ribbon.
* RibbonToolBar is a tool button styled for the ribbon.

You can build the designer plugin, which allows the layout of ribbon bars in Designer or Qt Creator.

## Requirements

* Qt 5
* CMake

## Building

To build the library, invoke CMake or open the CMakeLists.txt file in your preferred IDE.

Setting the following CMake variables allows the customisation of the build.

```
NEDRYSOFT_RIBBON_LIBRARY_DIR=<dir>
```

Sets the output folder for the dynamic library; if omitted, you can find the binaries in the default location.

```
NEDRYSOFT_RIBBON_BUILD_DESIGNER_PLUGIN=ON|OFF
```

Set to ON to build the designer plugin. (defaults to off)

```
NEDRYSOFT_RIBBON_DESIGNER_DIR=<dir>
```

Sets the output folder for the designer plugin; if omitted, you can find the binaries in the default location.

# License

This project is open source and released under the GPLv3 licence.

Distributed as-is; no warranty is given.
