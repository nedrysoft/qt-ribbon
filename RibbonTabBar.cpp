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

#include "RibbonTabBar.h"

#include "RibbonFontManager.h"
#include "RibbonWidget.h"

#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QWindow>

constexpr auto ThemeStylesheet = R"(
    QTabBar::tab {
        padding: 18px
    }
)";

Nedrysoft::Ribbon::RibbonTabBar::RibbonTabBar(QWidget *parent) :
        QTabBar(parent),
        m_themeSupport(new Nedrysoft::ThemeSupport::ThemeSupport) {

    auto fontManager = Nedrysoft::Ribbon::RibbonFontManager::getInstance();

    m_normalFont = QFont(fontManager->normalFont(), DefaultFontSize);
    m_selectedFont = QFont(fontManager->boldFont(), DefaultFontSize, QFont::Bold);

    m_mouseInWidget = false;

    connect(m_themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheet(isDarkMode);
    });

    updateStyleSheet(Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode());

#if defined(Q_OS_UNIX)
    setMouseTracking(true);
    installEventFilter(this);
#endif
}

Nedrysoft::Ribbon::RibbonTabBar::~RibbonTabBar() {
    if (m_themeSupport) {
        delete m_themeSupport;
    }
}

auto Nedrysoft::Ribbon::RibbonTabBar::eventFilter(QObject *watched, QEvent *event) -> bool {
    Q_UNUSED(watched)

    static auto lastTabIndex = -1;

    switch(event->type()) {
        case QEvent::Enter: {
            auto enterEvent = reinterpret_cast<QEnterEvent *>(event);

#if (QT_VERSION_MAJOR>=6)
            lastTabIndex = tabAt(enterEvent->position().toPoint());
#else
            lastTabIndex = tabAt(enterEvent->pos());
#endif
            m_mouseInWidget = true;

            update();

            break;
        }

        case QEvent::Leave: {
            lastTabIndex = -1;

            m_mouseInWidget = false;

            update();

            break;
        }

        case QEvent::MouseMove: {
            auto mouseEvent = reinterpret_cast<QMouseEvent *>(event);

#if (QT_VERSION_MAJOR>=6)
            QPoint mousePosition = mouseEvent->position().toPoint();
#else
            QPoint mousePosition = mouseEvent->pos();
#endif
            if (lastTabIndex != tabAt(mousePosition)) {
                update();

                lastTabIndex = tabAt(mousePosition);
            }

            break;
        }

        default: {
            break;
        }
    }

    return false;
}

auto Nedrysoft::Ribbon::RibbonTabBar::tabSizeHint(int index) const -> QSize {
    auto size = QTabBar::tabSizeHint(index);

    size.setHeight(Ribbon::TabBarHeight);

    return size;
}

auto Nedrysoft::Ribbon::RibbonTabBar::paintEvent(QPaintEvent *event) -> void {
    Q_UNUSED(event)
    auto globalCursorPos = QCursor::pos();
    auto textRect = QRect();
    auto cursorPos = mapFromGlobal(globalCursorPos);
    auto hoveredTab = tabAt(cursorPos);
    QColor backgroundColor;
    QPainter painter(this);
    auto  currentTheme = Ribbon::Light;

    if (Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode()) {
        currentTheme = Nedrysoft::Ribbon::Dark;
    }

#if defined(Q_OS_MACOS)
    if (!m_mouseInWidget) {
        hoveredTab = -1;
    }
#endif

    painter.save();

    for(auto tabIndex=0;tabIndex<count();tabIndex++) {
        auto rect = tabRect(tabIndex);

#if defined(Q_OS_MACOS)
        rect.adjust(0,0,0,-4);
#endif
        if (hoveredTab==tabIndex) {
            backgroundColor = Ribbon::TabHoverColor[currentTheme];
        } else {
            backgroundColor = Ribbon::TabBarBackgroundColor[currentTheme];
        }

        if (tabIndex==currentIndex()) {
            painter.setFont(m_selectedFont);
        } else {
            painter.setFont(m_normalFont);
        }

        painter.fillRect(rect, backgroundColor);

        painter.setPen(Ribbon::TextColor[currentTheme]);

        painter.drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, tabText(tabIndex), &textRect);

        rect.setTop(rect.bottom()-Ribbon::TabHighlightHeight);

        if (hoveredTab!=tabIndex) {
            rect.setLeft(textRect.left());
            rect.setRight(textRect.right());
        }

        if (tabIndex==currentIndex()) {
            painter.fillRect(rect, Ribbon::TabSelectedColor[currentTheme]);
        }
    }

    painter.restore();
}

auto Nedrysoft::Ribbon::RibbonTabBar::updateStyleSheet(bool isDarkMode) -> void {
    Q_UNUSED(isDarkMode)

    QString styleSheet(ThemeStylesheet);

    setStyleSheet(styleSheet);
}
