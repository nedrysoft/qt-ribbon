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

#include "RibbonDropButton.h"

#include "RibbonWidget.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

constexpr auto ThemeStylesheet = R"(
    QPushButton {
        border: 0px;
        padding-right: 3px;
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

Nedrysoft::Ribbon::RibbonDropButton::RibbonDropButton(QWidget *parent) :
        QWidget(parent),
        m_iconSize(QSize(RibbonDropButtonDefaultIconWidth,RibbonDropButtonDefaultIconHeight)),
        m_vertical(true),
        m_layout(nullptr),
        m_action(nullptr) {

    m_mainButton = new QPushButton;
    m_dropButton = new QPushButton;

    auto themeSupport = Nedrysoft::ThemeSupport::ThemeSupport::getInstance();

    m_mainButton->installEventFilter(this);

    m_dropButton->setMinimumHeight(RibbonDropButtonDefaultVerticalHeight);
    m_dropButton->setMaximumHeight(RibbonDropButtonDefaultVerticalHeight);

    m_mainButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_dropButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_dropButton->setIconSize(QSize(RibbonDropButtonArrowWidth, RibbonDropButtonArrowHeight));

    m_dropButton->setFlat(true);
    m_mainButton->setFlat(true);

    connect(m_mainButton, &QPushButton::clicked, [=] (bool checked) {
        if (m_action) {
            auto dropButtonEvent = new Nedrysoft::Ribbon::DropButtonClickedEvent(this, false);

            m_action->triggerEvent(dropButtonEvent);

            delete dropButtonEvent;
        }

        Q_EMIT clicked(false);
    });

    connect(m_dropButton, &QPushButton::clicked, [=] (bool checked) {
        if (m_action) {
            auto dropButtonEvent = new Nedrysoft::Ribbon::DropButtonClickedEvent(this, true);

            m_action->triggerEvent(dropButtonEvent);

            delete dropButtonEvent;
        }

        Q_EMIT clicked(true);
    });

    updateSizes();

    connect(themeSupport, &Nedrysoft::ThemeSupport::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheets(isDarkMode);
    });

    updateLayout();

    updateStyleSheets(themeSupport->isDarkMode());
}

Nedrysoft::Ribbon::RibbonDropButton::~RibbonDropButton() {
    if (m_mainButton) {
        delete m_mainButton;
    }

    if (m_dropButton) {
        delete m_dropButton;
    }

    if (m_layout) {
        delete m_layout;
    }
}

QIcon Nedrysoft::Ribbon::RibbonDropButton::icon() {
    return m_mainButton->icon();
}

void Nedrysoft::Ribbon::RibbonDropButton::setIcon(QIcon &icon) {
    m_mainButton->setIcon(icon);
}

QSize Nedrysoft::Ribbon::RibbonDropButton::iconSize() {
    return m_iconSize;
}

void Nedrysoft::Ribbon::RibbonDropButton::setIconSize(QSize iconSize)
{
    m_iconSize = iconSize;

    updateSizes();
}

void Nedrysoft::Ribbon::RibbonDropButton::updateSizes() {
    m_mainButton->setMinimumSize(m_iconSize);
    m_mainButton->setIconSize(m_iconSize);
}

void Nedrysoft::Ribbon::RibbonDropButton::updateStyleSheets(bool isDarkMode) {
    QString styleSheet(ThemeStylesheet);

    if (isDarkMode) {
        styleSheet.replace("[normal-background-colour]", "#434343");
    } else {
        styleSheet.replace("[normal-background-colour]", "#ffffff");
    }

    if (isDarkMode) {
        styleSheet.replace("[hover-colour]", "#4C4C4C");
    } else {
        styleSheet.replace("[hover-colour]", "#DDDDDD");
    }

    if (isDarkMode) {
        styleSheet.replace("[pressed-colour]", "#292929");
    } else {
        styleSheet.replace("[pressed-colour]", "#808080");
    }

    this->setStyleSheet(styleSheet);

    if (isDarkMode) {
        m_dropButton->setIcon(QIcon(":/Nedrysoft/Ribbon/icons/arrow-drop-dark@2x.png"));
    } else {
        m_dropButton->setIcon(QIcon(":/Nedrysoft/Ribbon/icons/arrow-drop-light@2x.png"));
    }
}

auto Nedrysoft::Ribbon::RibbonDropButton::updateLayout() -> void {
    QBoxLayout *layout;
    QSpacerItem *spacerItem=nullptr;

    if (m_vertical) {
        layout = new QVBoxLayout;
        spacerItem = new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        m_dropButton->setMinimumHeight(RibbonDropButtonDefaultVerticalHeight);
        m_dropButton->setMaximumHeight(RibbonDropButtonDefaultVerticalHeight);

    } else {
        layout = new QHBoxLayout;

        m_dropButton->setMinimumHeight(RibbonDropButtonDefaultHorizontalHeight);
        m_dropButton->setMaximumHeight(RibbonDropButtonDefaultHorizontalHeight);
    }

    layout->addWidget(m_mainButton);
    layout->addWidget(m_dropButton);

    if (spacerItem) {
        layout->addSpacerItem(spacerItem);
    }

    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    if (m_layout) {
        delete m_layout;
    }

    m_layout = layout;

    setLayout(m_layout);
}

auto Nedrysoft::Ribbon::RibbonDropButton::vertical() -> bool {
    return m_vertical;
}

auto Nedrysoft::Ribbon::RibbonDropButton::setVertical(const bool vertical) -> void {
    m_vertical = vertical;

    updateLayout();
}

auto Nedrysoft::Ribbon::RibbonDropButton::text() -> QString {
    return m_text;
}

auto Nedrysoft::Ribbon::RibbonDropButton::setText(const QString &text) -> void {
    QString padding;

    m_text = text;

    if (!m_vertical) {
        for (int i=0;i<3;i++) {
            padding += QLatin1Char(0x00A0);
        }
    }

    m_mainButton->setText(padding+m_text);
}

auto Nedrysoft::Ribbon::RibbonDropButton::setAction(Nedrysoft::Ribbon::RibbonAction *action) -> void {
    m_action = action;
}