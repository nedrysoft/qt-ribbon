# Contributing to the project

The following document contains a set of guidelines for contributing to the project.  Any pull-requests should be compliant with this guide.  Code style is often fluent, if you have a suggestion which you think will improve the readability of the code then please open an issue so that we can discuss that potentially modify the style guide to accommodate any new changes.

#C++ Style Guide

The following guide should be followed to ensure consistent code throughout the project.

## C++ Version

Code should target the C++17 standard, C++11 is the minimum standard that should be used.

## Header Files

Header files should always start with a copyright block.

```c++
/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * https://github.com/fizzyade
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
```

## Includes

Include files are logically grouped according to their scope and sorted alphabetically for clarity.

### Source file

1. The first header should be the corresponding header to the source file.
2. *Empty Line*
3. Local includes (sorted alphabetically)
4. *Empty Line*
5. System includes (sorted alphabetically)
6. *Empty Line*
7. Objective C imports

### Header file

1. Local includes (sorted alphabetically)
2. *Empty Line*
3. System includes (sorted alphabetically)

### Exceptions

If a file needs to be included at a specific location (i.e either the first include or the last include) then it also goes in the appropriate position but must include a comment explaining why the file is out of sequence.

# C++

## Include Guards

All include files should have an include guard to prevent the file from being included more than once.

```c++
#ifndef NEDRYSOFT_RIBBONPUSHBUTTON_H
#define NEDRYSOFT_RIBBONPUSHBUTTON_H
...
#endif // NEDRYSOFT_RIBBONPUSHBUTTON_H
```

The format of an include guard should be as follows:

```c++
[ORGANISATION]_[FILENAME]_H
```

## Namespaces

All code must exist in an appropriate namespace to prevent clashes with third party code, when using an item from a namespace then the fully qualified name should be used, and "using <namespace>" should not be used, by including the full namespace it makes it much easier to locate where a function can be found.

* C++17 nested namespaces should always be used.
* Braces should be on the same line as the namespace definition.
* Items inside a namespace indent 1 level

*Good*

```c++
namespace Nedrysoft::Utils {
    ...
}
```

*Bad*

```c++
namespace Nedrysoft {
    namespace Utils {
        ...
    }
}
```
```c++
namespace Nedrysoft
{
    ...
}
```

### Constants

For constant values, it is preferred that ```constexpr``` is used rather than ```#define```.  Constants should be limited to a namespace or the class scope and should not be global.

*Good*

```c++
constexpr auto RibbonPushButtonDefaultIconWidth = 32;
constexpr auto RibbonPushButtonDefaultIconHeight = 48;
constexpr auto RibbonPushButtonDefaultFontSize = 10;
```

*Bad*

```c++
#define RibbonPushButtonDefaultIconWidth 32
#define RibbonPushButtonDefaultIconHeight = 48
#define RibbonPushButtonDefaultFontSize = 10;
```

### Line Breaks

Line breaks are permitted when they improve clarity.  A double indent must be used on the following lines.

```c++
QString filename =
        fore(AnsiColour::WHITE)+
        "\""+
        fore(0xb0,0x85, 0xbe)+
        fileInfo.fileName()+
        fore(AnsiColour::WHITE)+
        "\""+
        fore(AnsiColour::YELLOW);
```

### Casting

C++ style casts must be used, do not use C style casts.

*Good*

```c++
auto asFloat = static_cast<float>(exampleInteger);
```

*Bad*
```c++
auto asFloat = (float) exampleInteger;
```

### Comments

Comments should be used where appropriate, code should use descriptive names which alleviates the need for large blocks of comments.  Comments should be used to describe operations that may not be obvious at first glance exactly what they do.

### Doxygen

Doxygen comments must be included in every header file, the comments should follow the JavaDoc style for consistency.

*Good*

```c++
/**
 * @brief       Reimplements: QObject::eventFilter(QObject *watched, QEvent *event).
 *
 * @param[in]   watched the object that caused the event.
 * @param[in]   event the event information.
 *
 * @returns     true if event was handled, otherwise false.
 */
bool eventFilter(QObject *watched, QEvent *event) override;
```

* The comment must directly before the method and there should be no gap between the comment and the function declaration.
* A new line must exist between each section of the comment, params are grouped without newlines.
* The ```@returns``` tag should be used instead of ```@return```.
* Parameters should include the direction of data.

### Class declarations

The scope modifier should be indented one level and functions and variables also should be indented a further level.

All class definitions should adhere to the following style:

*Good*

```c++
class RibbonTabBar :
    public QTabBar,
    public MyInterface {
        ...
    }
};
```
```c++
class RibbonTabBar {
    ...
};
```

Bad

```c++
class RibbonTabBar 
{
    ...
};
```
```c++
class RibbonTabBar {
public:
    ...
};
```
```c++
class RibbonTabBar 
{
public:
    ...
};
```

### Class layout

The layout of the class is designed such that items are grouped by their scope and type.

```c++
class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonTabBar :
    public QTabBar,
    public MyInterface {
        private:¹
            Q_OBJECT

            Q_INTERFACES(MyInterfaces)
        
        public:²
            enum RibbonType {
                Standard,
                Fresh
            };
            
        public:³
            /**
             * @brief       Constructs a new RibbonTabBar instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonTabBar(QWidget *parent = nullptr);
    
        protected:⁴
            /**
             * @brief       Reimplements: QWidget::paintEvent(QPaintEvent *event).
             *
             * @param[in]   event contains information for painting this widget
             */
            void paintEvent(QPaintEvent *event) override;

        private:⁵
            /**
             * @brief       Updates the widgets stylesheet when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            void updateStyleSheet(bool isDarkMode);
    
        private:⁶
            QFont m_selectedFont;                                   //! the font to use on the selected tab
    }
}
```

1. This section should implicitly set the scope to private and should ***only*** include Qt macros.  Macros are grouped logically together and each group is separated by a new line.
2. This section (there may be more than one depending on scope) should define any ```enums``` or ```constexpr```.
3. This section includes constructors, destructors, and any public methods that the class exposes.
4. This section contains any overridden superclass functions.
5. This section (there may be more than one depending on scope) contains internal functions.
6. This section contains any member variables.

### Case

Class names should start (wherever possible) with a capital letter and the start of each further word is then capitalised.

Functions should use camelCase.

*Good*

```c++
class MyClass {
    public:
        void doSomething();
};
```

*Bad*
```c++
class MyClass {
    public:
        void DoSomething();
};
```
```c++
class myclass {
    public:
        void DoSomething();
};
```

### Member variables

Member variables should use camelCase and be prefixed with ```m_```.

```c++
class MyClass {
    public:
        ...
        
    private:
        int m_totalCount;
};
```

## Source Files

Source files generally follow the same style as set out for include files, all code should adhere to these rules.

### Function Definition

Function names should be descriptive and whenever possible not truncated, using descriptive naming makes the code easier to follow and clearer and negates the need for comments.

Each function definition must conform to the following code standard.

1. Member variables should use initialiser lists instead of being assigned.
2. The colon for the initialiser list must appear on the same line as the function definition.
3. Each initialiser is indented by 2 levels.
3. One initialiser per line.
4. The final initialiser contains the opening brace for the function.
5. A blank line should always follow the opening brace for constructors that have initialisers regardless of whether or not any statements follow.  For constructors, without initialisers the blank line should be omitted.

*Good*

```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {
    
    ...
}

Nedrysoft::Image::Image() :
        m_data(nullptr),
        m_width(0),
        m_height(0),
        m_stride(0),
        m_imageId(0),
        m_isValid(false),
        m_length(0) {
    <blank line>
}


```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {
    
    doSomething();
    ...
}
```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) {
    ...
}
```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) {
    doSomething();
    ...
}
```

*Bad*

```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) : QObject(parent), m_initialized(false) {
    ...
}
```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) : QObject(parent), m_initialized(false)
{
    ...
}
```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) :
    QObject(parent),
    m_initialized(false) {
    
    ...
}
```
```c++
RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {
    doSomething();
    ...
}
```
```c++
Nedrysoft::Image::Image() :
        m_data(nullptr),
        m_width(0),
        m_height(0),
        m_stride(0),
        m_imageId(0),
        m_isValid(false),
        m_length(0) {
}
```
### Return values

Return values should not be enclosed in braces.

*Good*

```c++
bool MyTest::isFinished() {
    return m_isFinished;
}
```

*Bad*

```c++
bool MyTest::isFinished() {
    return(m_isFinished);
}
```

### Program flow

The program flow style is an extension of the rules described above.

#### if conditional

* Braces should always be used, even in the case of a single-line statement.
* Braces appear on the same line as the terminating conditional statement
* Multiple conditions may be split across multiple lines if it improves clarity.
* Each conditional must be surrounded by braces to avoid ambiguity.

*Good*

```c++
if (m_value>10) {
    ...
}
```
```c++
if (m_value>10) {
    ...
} else {
    ...
}
```
```c++
if (m_value>10) {
    ...
} else if (m_value>5) {
    ...
}
```
```c++
if ((m_fileLoaded) && 
    (m_fileSize<1024)) {
    ...
}
```

*Bad*

```c++
if (m_value>10)
{
    ...
}
```
```c++
if (m_value>10)
    ...
```
```c++
if (m_value>10)
    ...
else
    ...
```

#### for loops

* Wherever possible use range-based loops or iterators.
* Use descriptive names for indices or iterators

*Good*

```c++
for (auto fileEntry : files) {
    ...
}
```
```c++
for (auto currentIndex=0; currentIndex<totalValues; currentIndex++) {
    ...
}
```

#### while/do loops

* Braces appear on the same line as the loop.

*Good*

```c++
while(isRunning) {
    ...
}
```
```c++
do {
    ...
} while(isRunning);
```

*Bad*

```c++
while(isRunning)
{
    ... 
}
```
```c++
do
{
    ...
} while(isRunning);
```

#### Switch statements

* Cases are indented by one level.
* Multiple cases may be combined.
* Braces must always be used.
* The opening case brace is on the same line as the final case statement.

*Good*

```c++
switch(m_currentMode) {
    case Loading: {
        ...
        break;
    }
    
    case Saving: {
        ...
        break;
    }
    
    case Reading:
    case Writing: {
        ....
        break;
    }
    
    default: {
        ...
        break;
    }
}
```

*Bad*

```c++
switch(m_currentMode) {
case Loading: {
    ...
    break;
}
}
```
```c++
switch(m_currentMode) {
    case Loading:
        ...
        break;
}
```

#### Lambda functions

* The use of lambda expressions is recommended where possible, this is particularly true when dealing with asynchronous operations where using a lambda expression will result in cleaner and more readable code.
* std::function should be used as it allows both lambda and callback style operations to be performed.

```c++
void MyClass::downloadFile(DownloadInfo downloadInfo, std::function<void(DownloadStatus status)> statusFunction) {
    statusFunction(DownloadStatus(InitiatingDownload));
    
    startDownload(downloadInfo, statusFunction);
}
```

#### Singletons

* Singletons may be used where appropriate, for example, the MainWindow of the application may be accessed through a singleton which provides access to the object across the project easily.
* Singletons must use the C++11 pattern.

```c++
MyClass::getInstance() {
    static MyClass *instance = new MyClass;
    
    return instance;
}
```

### Qt Specific

* Qt keyword definitions should be disabled as they may conflict with third party code.  
* The ```Q_EMIT Q_SIGNAL Q_SLOT``` macros should be used on each function declaration.

```c++
class MyObject : 
        public QObject {
        
    private:
        Q_OBJECT
        
    public:
        Q_SLOT valueChanged(int newValue);
        
        Q_SIGNAL finished();
};
```

### Typing

The use of the keyword character "auto" should be used wherever possible, it produces a cleaner looking code.  Primitive types such as int, float, long, etc may be typed if auto doesn't make sense or results in ambiguity.

*Good*

```c+++
auto settingsDialog = SettingsDialog();

int totalCount;
```

*Bad*

```c+++
QSettingsDialog settingsDialog;
```

### Variables

Variable names should be descriptive, the more descriptive the name the easier and clearer the code is to understand.  Variables should be named using camelCase.

*Good*

```c++
for (int currentCharacter=0;currentCharacter<stringLength;currentCharacter++) {
    
}
```

*Bad*

```c++
for (int i=0;i<j;i++) {
    ...
}
```

# Commit Messages

This repository uses the conventional commit style for commit messages, any commits must follow this style.

The following tags are currently used:

* repo: a change to the repo, includes operations such as editing README.md or restructuring.
* wip: a work in progress message.
* refactor: refactoring of the code.
* chore: general housekeeping task such as removing dead files from the repo.
* fix: a fix of a specific issue, should normally be linked to a GitHub issue.
* feat: work on a specific feature.

If another tag type is required, then please raise a GitHub issue to discuss adding it.
