/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft Ribbon Bar. (https://github.com/nedrysoft/qt-ribbon)
 *
 * A cross-platform ribbon bar for Qt applications.
 *
 * Created by Adrian Carpenter on 02/12/2020.
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

#include "RibbonToolButton.h"

#include "RibbonWidget.h"

#include <QApplication>
#include <QStyle>

#include <QDebug>

constexpr auto ThemeStylesheet = R"(
    QToolButton {
        border: 0px none;
        background: [background-colour];
        margin: 0px;
        border-radius: none;
    }

    QToolButton::hover {
        background: [hover-colour];
    }
)";

Nedrysoft::Ribbon::RibbonToolButton::RibbonToolButton(QWidget *parent) :
        QToolButton(parent),
        m_themeSupport(new Nedrysoft::ThemeSupport::ThemeSupport) {

    connect(m_themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheet(isDarkMode);
    });

    updateStyleSheet(Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode());
}

Nedrysoft::Ribbon::RibbonToolButton::~RibbonToolButton() {
}

auto Nedrysoft::Ribbon::RibbonToolButton::updateStyleSheet(bool isDarkMode) -> void {
    QString styleSheet(ThemeStylesheet);

    if (isDarkMode) {
        styleSheet.replace("[background-colour]", "#434343");
        styleSheet.replace("[hover-colour]", "#616161");
    } else {
        styleSheet.replace("[background-colour]", "#ffffff");
    }

    setStyleSheet(styleSheet);
}
