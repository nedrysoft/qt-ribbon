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

#include "RibbonLineEdit.h"

#include <QApplication>
#include <QPainter>
#include <QPicture>
#include <QResizeEvent>
#include <QSpacerItem>
#include <QDebug>

constexpr auto ThemeStylesheet = R"(
    QTextEdit {
        background-color: [background-colour];
        height: 13px;
        border: 0px solid [border-colour];
        padding: 0px;
    }

    QTextEdit:focus {
        border-color: [border-colour];
    }
)";

constexpr auto lineEditHeightAdjustment = 2;

Nedrysoft::Ribbon::RibbonLineEdit::RibbonLineEdit(QWidget *parent) :
        QTextEdit(parent),
        m_themeSupport(new Nedrysoft::Utils::ThemeSupport) {

    setAttribute(Qt::WA_MacShowFocusRect,false);

    connect(m_themeSupport, &Nedrysoft::Utils::ThemeSupport::themeChanged, [=](bool isDarkMode) {
        updateStyleSheet(isDarkMode);
    });

    connect(this, &Nedrysoft::Ribbon::RibbonLineEdit::textChanged, [=]() {
#if defined(__clang__)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "VirtualCallInCtorOrDtor"
#endif
        resizeEvent(nullptr);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    });

    updateStyleSheet(Nedrysoft::Utils::ThemeSupport::isDarkMode());

    setLineWrapMode(QTextEdit::NoWrap);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    static int minimumLineHeight = 0;

    if (!minimumLineHeight) {
        QLineEdit lineEdit;

        minimumLineHeight = lineEdit.minimumSizeHint().height()+lineEditHeightAdjustment;
    }

    setSizePolicy(sizePolicy().horizontalPolicy(), QSizePolicy::Fixed);

    setFixedHeight(minimumLineHeight);

    if (placeholderText().isEmpty()) {
        setPlaceholderText(" ");
    }
}

Nedrysoft::Ribbon::RibbonLineEdit::~RibbonLineEdit() {
    if (m_themeSupport) {
        delete m_themeSupport;
    }
}

auto Nedrysoft::Ribbon::RibbonLineEdit::updateStyleSheet(bool isDarkMode) -> void {
    QString styleSheet(ThemeStylesheet);

    if (isDarkMode) {
        styleSheet.replace("[background-colour]", "#434343");
        styleSheet.replace("[border-colour]", "none");
    } else {
        styleSheet.replace("[background-colour]", "#ffffff");
        styleSheet.replace("[border-colour]", "#B9B9B9");
    }

    setStyleSheet(styleSheet);
}

auto Nedrysoft::Ribbon::RibbonLineEdit::resizeEvent(QResizeEvent *event) -> void {
    QFontMetrics fontMetrics(font());

    auto text = toPlainText().isEmpty()?placeholderText():toPlainText();
    auto offset = (rect().height()-fontMetrics.boundingRect(text).height())/2;

    if (offset!=document()->documentMargin()) {
        document()->setDocumentMargin(offset);
    }
}


