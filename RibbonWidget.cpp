/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * https://github.com/fizzyade
 *
 * Created by Adrian Carpenter on 07/11/2020.
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
#include "ThemeSupport.h"

#include <QPaintEvent>
#include <QPainter>
#include <QTabBar>

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

#if defined(Q_OS_MACOS)
    setDocumentMode(true);
#endif
}

void Nedrysoft::Ribbon::RibbonWidget::paintEvent(QPaintEvent *event) {
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
