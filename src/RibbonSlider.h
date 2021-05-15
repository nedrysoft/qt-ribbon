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

#ifndef NEDRYSOFT_RIBBONSLIDER_H
#define NEDRYSOFT_RIBBONSLIDER_H

#include "RibbonSpec.h"

#include <QSlider>
#include <ThemeSupport>

namespace Nedrysoft { namespace Ribbon {
    /**
     * @brief       The RibbonSlider widget provides a ribbon stylised slider.
     *
     * @details     A Slider widget that is styled to match the RibbonBar.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonSlider :
            public QSlider {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonSlider instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonSlider(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonSlider.
             */
            ~RibbonSlider() override;

        private:
            /**
             * @brief       Updates the stylesheet when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            auto updateStyleSheet(bool isDarkMode) -> void;

        private:
            //! @cond

            Nedrysoft::ThemeSupport::ThemeSupport *m_themeSupport;

            //! @endcond
    };
}}

#endif //NEDRYSOFT_RIBBONSLIDER_H
