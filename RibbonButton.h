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

#ifndef NEDRYSOFT_RIBBONBUTTON_H
#define NEDRYSOFT_RIBBONBUTTON_H

#include "RibbonSpec.h"
#include "ThemeSupport.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace Nedrysoft::Ribbon {
    constexpr auto RibbonButtonDefaultIconWidth = 32;
    constexpr auto RibbonButtonDefaultIconHeight = 48;
    constexpr auto RibbonButtonDefaultFontSize = 10;

    /**
     * @brief       The RibbonButton widget provides a ribbon stylised push button with icon and optional text.
     *
     * @details     A Button widget that is styled to match the RibbonBar.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonButton :
            public QPushButton {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonButton instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonButton(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonButton.
             */
            ~RibbonButton() override;

        private:
            /**
             * @brief       Updates the child widgets stylesheets when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            auto updateStyleSheets(bool isDarkMode) -> void;

        private:
            Nedrysoft::Utils::ThemeSupport *m_themeSupport;     //! an instance of theme support
    };
}

#endif //NEDRYSOFT_RIBBONBUTTON_H
