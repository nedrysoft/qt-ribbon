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

#ifndef NEDRYSOFT_RIBBONLINEDIT_H
#define NEDRYSOFT_RIBBONLINEDIT_H

#include "RibbonSpec.h"
#include "ThemeSupport.h"

#include <QLineEdit>
#include <QTextEdit>

namespace Nedrysoft::Ribbon {
    /**
     * @brief       The RibbonLineEdit widget provides a ribbon stylised line edit.
     *
     * @details     A LineEdit widget that is styled to match the RibbonBar.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonLineEdit :
            public QTextEdit {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonLineEdit instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonLineEdit(QWidget *parent=nullptr);

            /**
             * @brief       Destroys the RibbonLineEdit.
             */
            ~RibbonLineEdit() override;

        protected:
            /**
             * @brief       Reimplements QTextEdit::resizeEvent(QResizeEvent *event)
             *
             * @param[in]   event the resize event.
             */
            auto resizeEvent(QResizeEvent *event) -> void override;

            /**
             * @brief       Reimplements QTextEdit::event(QEvent *event).
             *
             * @note        Used to discard enter + return keys.
             *
             * @param[in[   event the event information.
             *
             * @returns     true if event handled; otherwise false.
             */
            auto event(QEvent *event) -> bool override;

            /**
             * @brief       Reimplements QTextEdit::insertFromMimeData(QEvent *event).
             *
             * @note        Used to discard any carriage returns or line feeds from paste (and also ensure that
             *              only text can be pasted.
             */
            auto insertFromMimeData(const QMimeData *source) -> void override;

        private:
            /**
             * @brief       Updates the stylesheet when the operating system theme is changed.
             *
             * @param[in]   isDarkMode true if dark mode; otherwise false.
             */
            auto updateStyleSheet(bool isDarkMode) -> void;

        private:
            Nedrysoft::ThemeSupport::ThemeSupport *m_themeSupport;                 //! theme support instance
    };
}

#endif //NEDRYSOFT_RIBBONLINEDIT_H
