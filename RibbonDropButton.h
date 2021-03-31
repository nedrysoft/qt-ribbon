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

#ifndef NEDRYSOFT_RIBBONDROPBUTTON_H
#define NEDRYSOFT_RIBBONDROPBUTTON_H

#include "RibbonSpec.h"
#include "ThemeSupport.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace Nedrysoft::Ribbon {
    constexpr auto RibbonDropButtonDefaultIconWidth = 32;
    constexpr auto RibbonDropButtonDefaultIconHeight = 48;
    constexpr auto RibbonDropButtonDefaultHeight = 16;
    constexpr auto RibbonDropButtonArrowWidth = 5;
    constexpr auto RibbonDropButtonArrowHeight = 5;

    /**
     * @brief       The RibbonDropButton widget provides a ribbon stylised push button with a drop down action.
     *
     * @details     A PushButton widget that is styled to match the RibbonBar, consists of a main push button which
     *              is the primary action and a secondary drop down button which can provide further actions.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonDropButton :
            public QWidget {

        private:
            Q_OBJECT

            Q_PROPERTY(QIcon icon READ icon WRITE setIcon)
            Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize)

        public:
            /**
             * @brief       Constructs a new RibbonDropButton which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonDropButton(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonDropButton.
             */
            ~RibbonDropButton() override;

            /**
             * @brief       Returns the icon that is currently assigned to the main button.
             *
             * @returns     the icon assigned to the main button.
             */
            auto icon() -> QIcon;

            /**
             * @brief       Sets the icon to be displayed on the main button.
             *
             * @param[in]   icon the icon to be displayed on the main button.
             */
            auto setIcon(QIcon &icon) -> void;

            /**
             * @brief       Returns the current size of the icon.
             *
             * @returns     the current size of the icon.
             */
            auto iconSize() -> QSize;

            /**
             * @brief       Sets the current size of the icon.
             *
             * @param[in]   iconSize the new size of the icon to be used.
             */
            auto setIconSize(QSize iconSize) -> void;

        private:
            /**
             * @brief       Updates the child widgets when the size of the icon is changed.
             */
            auto updateSizes() -> void;

            /**
              * @brief       Updates the child widgets stylesheets when the operating system theme is changed.
              *
              * @param[in]   isDarkMode true if dark mode; otherwise false.
              */
            auto updateStyleSheets(bool isDarkMode) -> void;

        public:
            /**
             * @brief       This signal is emitted when the either the main or drop-down button has been clicked.
             *
             * @param[in]   dropdown true if the drop-down section was clicked; otherwise false (main button section was clicked).
             */
            Q_SIGNAL void clicked(bool dropdown);

        private:
            QVBoxLayout *m_layout;                              //! the layout for this widget
            QPushButton *m_mainButton;                          //! the main button
            QPushButton *m_dropButton;                          //! the drop down button
            QSize m_iconSize;                                   //! the size of the icon
            Nedrysoft::ThemeSupport::ThemeSupport *m_themeSupport;     //! theme support instance
    };
}

#endif //NEDRYSOFT_RIBBONDROPBUTTON_H
