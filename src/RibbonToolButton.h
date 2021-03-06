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

#ifndef NEDRYSOFT_RIBBONTOOLBUTTON_H
#define NEDRYSOFT_RIBBONTOOLBUTTON_H

#include "RibbonSpec.h"

#include <QToolButton>
#include <ThemeSupport>

namespace Nedrysoft { namespace Ribbon {
    /**
     * @brief       The RibbonToolButton widget provides a ribbon stylised push button with icon and optional text.
     *
     * @details     A ToolButton widget that is styled to match the RibbonBar.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonToolButton :
            public QToolButton {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonToolButton instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonToolButton(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonToolButton.
             */
            ~RibbonToolButton() override;

        private:
            /**
             * @brief       Updates the stylesheet when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            auto updateStyleSheet(bool isDarkMode) -> void;
    };
}}

#endif //NEDRYSOFT_RIBBONTOOLBUTTON_H
