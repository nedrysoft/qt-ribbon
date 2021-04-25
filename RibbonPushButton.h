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

#ifndef NEDRYSOFT_RIBBONPUSHBUTTON_H
#define NEDRYSOFT_RIBBONPUSHBUTTON_H

#include "RibbonSpec.h"
#include "ThemeSupport.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

namespace Nedrysoft { namespace Ribbon {
    constexpr auto RibbonPushButtonDefaultIconWidth = 32;
    constexpr auto RibbonPushButtonDefaultIconHeight = 48;
    constexpr auto RibbonPushButtonDefaultFontSize = 10;

    /**
     * @brief       The RibbonPushButton widget provides a ribbon stylised push button with icon and optional text.
     *
     * @details     A PushButton widget that is styled to match the RibbonBar.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonPushButton :
            public QWidget {

        private:
            Q_OBJECT

            Q_PROPERTY(QIcon icon READ icon WRITE setIcon)
            Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize)
            Q_PROPERTY(QString text READ text WRITE setText)

        public:
            /**
             * @brief       Constructs a new RibbonPushButton instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonPushButton(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonPushButton.
             */
            ~RibbonPushButton() override;

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
             * @brief       Returns the text that is displayed under the main button.
             *
             * @returns     the text that is displayed under the main button.
             */
            auto text() -> QString;

            /**
             * @brief       Sets the text that is displayed under the main button.
             *
             * @note        If the text is empty, then the RibbonPushButton modifies the layout so that the space
             *              that would contain the text is removed.
             *
             * @param[in]   text the text that is displayed under the main button.
             */
            auto setText(QString text) -> void;

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
             * @brief       This signal is emitted when the main button has been clicked.
             */
            Q_SIGNAL void clicked();

        protected:
            /**
             * @brief       Reimplements: QWidget::eventFilter(QObject *object, QEvent *event).
             *
             * @param[in]   object the target object for the event.
             * @param[in]   event the event information.
             */
            auto eventFilter(QObject *object, QEvent *event) -> bool override;

        private:
            QVBoxLayout *m_layout;                              //! the layout for this widget
            QPushButton *m_mainButton;                          //! the main button
            QLabel *m_buttonLabel;                              //! the main button label
            QSize m_iconSize;                                   //! the size of the icon
            Nedrysoft::ThemeSupport::ThemeSupport *m_themeSupport;     //! an instance of theme support
    };
}}

#endif //NEDRYSOFT_RIBBONPUSHBUTTON_H
