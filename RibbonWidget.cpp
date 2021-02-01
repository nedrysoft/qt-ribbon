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

#include "RibbonWidget.h"

#include "RibbonTabBar.h"

#include <QPaintEvent>
#include <QPainter>

constexpr auto ThemeStylesheet = R"(
    QWidget {
        font-family: "Open Sans";
        font-size: 10pt;
    }
)";

Nedrysoft::Ribbon::RibbonWidget::RibbonWidget(QWidget *parent) :
        QTabWidget(parent) {

    m_tabBar = new RibbonTabBar(this);

    setTabBar(m_tabBar);
    setStyleSheet(ThemeStylesheet);

    setMinimumHeight(RibbonBarHeight+TabBarHeight);
    setMaximumHeight(RibbonBarHeight+TabBarHeight);

    setDocumentMode(true);
}

auto Nedrysoft::Ribbon::RibbonWidget::paintEvent(QPaintEvent *event) -> void {
    Q_UNUSED(event)
    QPainter painter(this);
    auto widgetRect = rect();
    auto currentTheme = Nedrysoft::Ribbon::Light;

    if (Nedrysoft::Utils::ThemeSupport::isDarkMode()) {
        currentTheme = Nedrysoft::Ribbon::Dark;
    }

    painter.save();

    painter.fillRect(widgetRect, TabBarBackgroundColor[currentTheme]);

    widgetRect.setTop(widgetRect.bottom());

    painter.fillRect(widgetRect, RibbonBorderColor[currentTheme]);

    painter.restore();
}
