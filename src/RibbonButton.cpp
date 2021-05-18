/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft Ribbon Bar. (https://github.com/nedrysoft/qt-ribbon)
 *
 * A cross-platform ribbon bar for Qt applications.
 *
 * Created by Adrian Carpenter on 12/12/2020.
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

#include <QtGlobal>

#include "RibbonButton.h"

#include "RibbonFontManager.h"
#include "RibbonWidget.h"

#include <QApplication>
#include <QStyle>
#include <ThemeSupport>

constexpr auto ThemeStylesheet = R"(
    QPushButton {
        border: 0px;
        padding: 3px;
        background: [normal-background-colour];
        border-radius: none;
    }

    QPushButton::hover {
        background: [hover-colour];
    }

    QPushButton::pressed {
        background: [pressed-colour];
    }
)";

Nedrysoft::Ribbon::RibbonButton::RibbonButton(QWidget *parent) :
        QPushButton(parent) {

    auto fontManager = RibbonFontManager::getInstance();

    auto font = QFont(fontManager->normalFont(), RibbonButtonDefaultFontSize);

    setFont(font);

    setFlat(true);

    auto themeSupport = Nedrysoft::ThemeSupport::ThemeSupport::getInstance();

    connect(themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheets(isDarkMode);
    });

    updateStyleSheets(themeSupport->isDarkMode());
}

Nedrysoft::Ribbon::RibbonButton::~RibbonButton() {

}

auto Nedrysoft::Ribbon::RibbonButton::updateStyleSheets(bool isDarkMode) -> void {
    QString styleSheet(ThemeStylesheet);

    auto themeSupport = Nedrysoft::ThemeSupport::ThemeSupport::getInstance();

    styleSheet.replace("[background-colour]", themeSupport->getColor(Nedrysoft::Ribbon::PushButtonColor).name());

    if (isDarkMode) {
        styleSheet.replace("[normal-background-colour]", "#434343");
    } else {
        styleSheet.replace("[normal-background-colour]", "#ffffff");
    }

    if (isDarkMode) {
        styleSheet.replace("[hover-colour]", "#4c4c4c");
    } else {
        styleSheet.replace("[hover-colour]", "#dddddd");
    }

    if (isDarkMode) {
        styleSheet.replace("[pressed-colour]", "#292929");
    } else {
        styleSheet.replace("[pressed-colour]", "#808080");
    }

    setStyleSheet(styleSheet);
}
