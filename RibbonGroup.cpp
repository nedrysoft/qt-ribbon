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

#include "RibbonGroup.h"

#include "RibbonFontManager.h"
#include "RibbonWidget.h"
#include "ThemeSupport.h"

#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QRegularExpression>

#if defined(Q_OS_WINDOWS)
constexpr auto TitleAdjustment = -4;
#else
constexpr auto TitleAdjustment = 0;
#endif

Nedrysoft::Ribbon::RibbonGroup::RibbonGroup(QWidget *parent) :
        QWidget(parent),
        m_fontMetrics(QFont()) {

    auto fontManager = RibbonFontManager::getInstance();

    m_font = QFont(fontManager->normalFont(), RibbonGroupDefaultFontSize);
    m_fontMetrics = QFontMetrics(m_font);

    // set the stylesheet font, this then propagates down to all children of the group.

    this->setStyleSheet(QString("font: %1pt \"%2\"").arg(m_font.pointSize()).arg(m_font.family()));

    setGroupName(QString("Group"));
#if (QT_VERSION_MAJOR<6)
    connect(qobject_cast<QApplication *>(QCoreApplication::instance()), &QApplication::paletteChanged, [=] (const QPalette &) {
        // TODO: anything to do?
    });
#endif
    updateMargins();

    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

#if (QT_VERSION_MAJOR>=6)
bool Nedrysoft::Ribbon::RibbonGroup::event(QEvent *event) {
    switch(event->type()) {
        case QEvent::ApplicationPaletteChange: {
            // TODO: anything to do?
            break;
        }

        default: {
            break;
        }
    }

    return false;
}
#endif

auto Nedrysoft::Ribbon::RibbonGroup::paintEvent(QPaintEvent *event) -> void {
    QPainter painter(this);
    auto widgetRect = rect();
    auto currentTheme = Nedrysoft::Ribbon::Light;

    if (Nedrysoft::ThemeSupport::ThemeSupport::isDarkMode()) {
        currentTheme = Nedrysoft::Ribbon::Dark;
    }

    widgetRect.setTop(widgetRect.bottom()-m_textRect.height());

    painter.save();

    painter.setFont(m_font);

    painter.setPen(Ribbon::TextColor[currentTheme]);

    auto textRect = contentsRect();

    textRect.setBottom(rect().bottom());

    painter.drawText(textRect.adjusted(0, 0, 0, TitleAdjustment), m_groupName, Qt::AlignBottom | Qt::AlignHCenter);

    painter.setClipRect(event->rect());

    painter.setPen(Ribbon::GroupDividerColor[currentTheme]);

    auto startPoint = QPoint(rect().right()-1, rect().top()+Ribbon::GroupDividerMargin);
    auto endPoint = QPoint(rect().right()-1, rect().bottom()-Ribbon::GroupDividerMargin);

    painter.drawLine(startPoint, endPoint);

    painter.restore();

    QWidget::paintEvent(event);
}

auto Nedrysoft::Ribbon::RibbonGroup::groupName() -> QString const {
    return m_groupName;
}

auto Nedrysoft::Ribbon::RibbonGroup::setGroupName(const QString &groupName) -> void {
    m_groupName = groupName;

    updateMargins();
}

auto Nedrysoft::Ribbon::RibbonGroup::updateMargins() -> void {
    m_textRect = m_fontMetrics.boundingRect(m_groupName);

    setMinimumWidth(m_textRect.width()+(RibbonGroupHorizontalMargins*2));

    setContentsMargins(RibbonGroupHorizontalMargins, 0, RibbonGroupHorizontalMargins, m_textRect.height());

    update();
}