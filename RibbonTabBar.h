/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft Ribbon Bar. (https://github.com/fizzyade/qt-ribbon)
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

#ifndef NEDRYSOFT_RIBBONTABBAR_H
#define NEDRYSOFT_RIBBONTABBAR_H

#include "RibbonSpec.h"
#include "ThemeSupport.h"

#include <QFont>
#include <QTabBar>

namespace Nedrysoft::Ribbon {
    /**
     * @brief       The RibbonTabBar widget provides a ribbon stylised tab bar.
     *
     * @details     A TabBar widget that is styled to match the RibbonBar, the TabBar on a QTabWidget is replaced
     *              with an instance of this class.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonTabBar :
            public QTabBar {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonTabBar instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonTabBar(QWidget *parent = nullptr);

        protected:
            /**
             * @brief       Reimplements: QWidget::paintEvent(QPaintEvent *event).
             *
             * @param[in]   event the event information.
             */
            auto paintEvent(QPaintEvent *event) -> void override;

            /**
             * @brief       Returns the size hint for the tab at position index.
             *
             * @param[in]   index the index of the page.
             *
             * @returns     the size hint for the tab at position index.
             */
            auto tabSizeHint(int index) -> QSize const;

            /**
             * @brief       Reimplements: QObject::eventFilter(QObject *watched, QEvent *event).
             *
             * @param[in]   watched the object that caused the event.
             * @param[in]   event the event information.
             *
             * @returns     true if event was handled, otherwise false.
             */
            auto eventFilter(QObject *watched, QEvent *event) -> bool override;

        private:
            /**
             * @brief       Updates the widgets stylesheet when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            auto updateStyleSheet(bool isDarkMode) -> void;

        private:
            QFont m_selectedFont;                                   //! font to use on selected tab
            QFont m_normalFont;                                     //! font to use on deselected tabs
            bool m_mouseInWidget;                                   //! tracks whether the mouse is tracked inside the widget

            Nedrysoft::Utils::ThemeSupport *m_themeSupport;         //! theme support instance
    };
}
#endif // NEDRYSOFT_RIBBONTABBAR_H
