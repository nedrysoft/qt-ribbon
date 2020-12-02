/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * https://github.com/fizzyade
 *
 * Created by Adrian Carpenter on 11/11/2020.
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
#include "ThemeSupport.h"

#include <QApplication>
#include <QSpacerItem>

constexpr auto ThemeStylesheet = R"(
    QPushButton {
        border: 0px;
        padding: 3px;
    }

    QPushButton::hover {
        background: [background-colour];
    }
)";

Nedrysoft::Ribbon::RibbonDropButton::RibbonDropButton(QWidget *parent) :
        QWidget(parent),
        m_iconSize(QSize(RibbonDropButtonDefaultIconWidth,RibbonDropButtonDefaultIconHeight)),
        m_themeSupport(new Nedrysoft::Utils::ThemeSupport) {

    m_layout = new QVBoxLayout;
    m_mainButton = new QPushButton;
    m_dropButton = new QPushButton;

    m_mainButton->installEventFilter(this);

    m_layout->addWidget(m_mainButton);
    m_layout->addWidget(m_dropButton);
    m_layout->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    m_layout->setContentsMargins(0,0,0,0);
    m_layout->setSpacing(0);

    m_dropButton->setMinimumHeight(RibbonDropButtonDefaultHeight);
    m_dropButton->setMaximumHeight(RibbonDropButtonDefaultHeight);

    m_mainButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_dropButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    m_dropButton->setIconSize(QSize(RubbonDropButtonArrowWidth,RubbonDropButtonArrowHeight));

    m_dropButton->setFlat(true);
    m_mainButton->setFlat(true);

    setLayout(m_layout);

    connect(m_mainButton, &QPushButton::clicked, [=] (bool checked) {
        Q_EMIT clicked(false);
    });

    connect(m_dropButton, &QPushButton::clicked, [=] (bool checked) {
        Q_EMIT clicked(true);
    });

    updateSizes();

    connect(m_themeSupport, &Nedrysoft::Utils::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheets(isDarkMode);
    });

    updateStyleSheets(Nedrysoft::Utils::ThemeSupport::isDarkMode());
}

Nedrysoft::Ribbon::RibbonDropButton::~RibbonDropButton() {
    m_mainButton->deleteLater();
    m_dropButton->deleteLater();
    m_layout->deleteLater();
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

    styleSheet.replace("[background-colour]", Nedrysoft::Utils::ThemeSupport::getColor(Nedrysoft::Ribbon::PushButtonColor).name());

    m_mainButton->setStyleSheet(styleSheet);
    m_dropButton->setStyleSheet(styleSheet);

    if (isDarkMode) {
        m_dropButton->setIcon(QIcon(":/Nedrysoft/Ribbon/icons/arrow-drop-dark@2x.png"));
    } else {
        m_dropButton->setIcon(QIcon(":/Nedrysoft/Ribbon/icons/arrow-drop-light@2x.png"));
    }
}

bool Nedrysoft::Ribbon::RibbonDropButton::eventFilter(QObject *object, QEvent *event) {
    if (event->type()==QEvent::MouseButtonPress) {
        QString styleSheet(ThemeStylesheet);

        styleSheet.replace("[background-colour]", "#292929");

        m_mainButton->setStyleSheet(styleSheet);
    } else if (event->type()==QEvent::MouseButtonRelease) {
        updateStyleSheets(m_themeSupport->isDarkMode());
    }

    return false;
}