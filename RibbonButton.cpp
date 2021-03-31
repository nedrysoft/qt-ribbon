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

#include "RibbonButton.h"

#include "RibbonFontManager.h"
#include "RibbonWidget.h"

#if defined(Q_OS_MACOS)
#include "ThemeSupport.h"
#endif

#include <QApplication>
#include <QStyle>

#include <QDebug>

constexpr auto ThemeStylesheet = R"(
    QPushButton {
        border: 0px;
        padding: 3px;
        background: [normal-background-colour];
    }

    QPushButton::hover {
        background: [hover-colour];
    }

    QPushButton::pressed {
        background: [pressed-colour];
    }
)";

Nedrysoft::Ribbon::RibbonButton::RibbonButton(QWidget *parent) :
        QPushButton(parent),
        m_themeSupport(new Nedrysoft::ThemeSupport::ThemeSupport) {

    auto fontManager = RibbonFontManager::getInstance();

    auto font = QFont(fontManager->normalFont(), RibbonButtonDefaultFontSize);

    setFont(font);

    setFlat(true);

    connect(m_themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheets(isDarkMode);
    });

    updateStyleSheets(Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode());
}

Nedrysoft::Ribbon::RibbonButton::~RibbonButton() {
    if (m_themeSupport) {
        delete m_themeSupport;
    }
}

auto Nedrysoft::Ribbon::RibbonButton::updateStyleSheets(bool isDarkMode) -> void {
    QString styleSheet(ThemeStylesheet);

    styleSheet.replace("[background-colour]", Nedrysoft::ThemeSupport::ThemeSupport::getColor(Nedrysoft::Ribbon::PushButtonColor).name());

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
