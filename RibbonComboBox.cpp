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

#include "RibbonComboBox.h"

#include <QApplication>
#include <QSpacerItem>

constexpr auto ThemeStylesheet = R"(
    QComboBox {
        padding: 2px;
        border: 0px;
        margin-right: 1px;
        background-color: [background-colour];
        selection-background-color: [selected-background-colour];
    }

    QComboBox::drop-down {
        background-color: [background-colour];
    }

    QComboBox::down-arrow {
        image: url(':/Nedrysoft/Ribbon/icons/arrow-drop-[theme]@2x.png');
        width: 5px;
        height: 4px;
    }

    QComboBox::down-arrow:hover {
        background-color: [hover-background-colour];
    }
)";

Nedrysoft::Ribbon::RibbonComboBox::RibbonComboBox(QWidget *parent) :
        QComboBox(parent),
        m_themeSupport(new Nedrysoft::ThemeSupport::ThemeSupport) {

    setAttribute(Qt::WA_MacShowFocusRect,false);

    connect(m_themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheet(isDarkMode);
    });

    updateStyleSheet(Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode());
}

Nedrysoft::Ribbon::RibbonComboBox::~RibbonComboBox() {
    if (m_themeSupport) {
        delete m_themeSupport;
    }
}

auto Nedrysoft::Ribbon::RibbonComboBox::updateStyleSheet(bool isDarkMode) -> void {
    QString styleSheet(ThemeStylesheet);

#if defined(Q_OS_MACOS)
    styleSheet.replace("[selected-background-colour]", Nedrysoft::Utils::ThemeSupport::getHighlightedBackground().name());
#else
    styleSheet.replace("[selected-background-colour]", this->palette().highlight().color().name());
#endif
    styleSheet.replace("[theme]", isDarkMode ? "dark" : "light");

    if (isDarkMode) {
        styleSheet.replace("[background-colour]", "#434343");
        styleSheet.replace("[border-colour]", "#323232");
        styleSheet.replace("[hover-background-colour]", "#626262");

    } else {
        styleSheet.replace("[background-colour]", "#ffffff");
        styleSheet.replace("[border-colour]", "#B9B9B9");
        styleSheet.replace("[hover-background-colour]", "#f5f5f5");
    }

    setStyleSheet(styleSheet);
}
