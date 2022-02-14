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

#include "RibbonAction.h"
#include "RibbonSpec.h"

#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>
#include <ThemeSupport>

namespace Nedrysoft { namespace Ribbon {
    constexpr auto RibbonDropButtonDefaultIconWidth = 32;
    constexpr auto RibbonDropButtonDefaultIconHeight = 48;
    constexpr auto RibbonDropButtonDefaultVerticalHeight = 16;
    constexpr auto RibbonDropButtonDefaultHorizontalHeight = 20;
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

            //! @cond

            Q_PROPERTY(QIcon icon READ icon WRITE setIcon)
            Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize)
            Q_PROPERTY(bool vertical READ vertical WRITE setVertical)
            Q_PROPERTY(QString text READ text WRITE setText)

            //! @endcond

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

            /**
             * @brief       Returns whether the layout is vertical.
             *
             * @returns     true if vertical; otherwise false.
             */
            auto vertical() -> bool;

            /**
             * @brief       Sets whether the layout is vertical.
             *
             * @param[in]   vertical true if vertical;otherwise false.
             */
            auto setVertical(const bool vertical) -> void;

            /**
             * @brief       Returns the icon that is currently assigned to the main button.
             *
             * @returns     the icon assigned to the main button.
             */
            auto text() -> QString;

            /**
             * @brief       Sets the text to be displayed on the main button.
             *
             * @param[in]   icon the text to be displayed on the main button.
             */
            auto setText(const QString &text) -> void;

            /**
             * @brief       Sets the ribbon action for this widget.
             *
             * @note        In addition to emitting the clicked signal, this widget will also trigger this
             *              action.
             *
             * @param[in]   action the action to associate with this button.
             */
            void setAction(Nedrysoft::Ribbon::RibbonAction *action);

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

            /**
             * @brief       Updates the widgets layout when the vertical property has been changed.
             */
            auto updateLayout() -> void;

        public:
            /**
             * @brief       This signal is emitted when the either the main or drop-down button has been clicked.
             *
             * @param[in]   dropdown true if the drop-down section was clicked; otherwise false (main button section was clicked).
             */
            Q_SIGNAL void clicked(bool dropdown);

            /**
             * @brief       Emitted when an event occurs on the owner widget.
             *
             * @param[in]   event contains information about the event.
             */
            Q_SIGNAL void ribbonEvent(const Nedrysoft::Ribbon::Event &event);

        private:
            //! @cond

            QBoxLayout *m_layout;
            QPushButton *m_mainButton;
            QPushButton *m_dropButton;
            QSize m_iconSize;
            bool m_vertical;
            QString m_text;
            RibbonAction *m_action;

            //! @endcond
    };
}}

#endif //NEDRYSOFT_RIBBONDROPBUTTON_H
