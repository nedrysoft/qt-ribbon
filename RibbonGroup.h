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

#ifndef NEDRYSOFT_RIBBONGROUP_H
#define NEDRYSOFT_RIBBONGROUP_H

#include "RibbonSpec.h"

#include <QFontMetrics>
#include <QMap>
#include <QWidget>

namespace Nedrysoft { namespace Ribbon {
    constexpr auto RibbonGroupHorizontalMargins = 12;
#if defined(Q_OS_MACOS)
    constexpr int RibbonGroupDefaultFontSize = 10;
#else
    constexpr int RibbonGroupDefaultFontSize = 8;
#endif

    /**
     * @brief       The RibbonGroup widget provides a ribbon stylised group container.
     *
     * @details     A RibbonGroup is a container for a logical grouping of controls, a RibbonWidget page will
     *              contain multiple groups which in turn contain multiple controls.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonGroup :
            public QWidget {

        private:
            Q_OBJECT

            Q_PROPERTY(QString groupName READ groupName WRITE setGroupName)

        public:
            /**
             * @brief       Constructs a new RibbonGroup which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonGroup(QWidget *parent = nullptr);

            /**
             * @brief       Destroys the RibbonGroup.
             */
            auto groupName() -> QString const;

            /**
             * @brief       Sets the displayed name of the group.
             *
             * @param[in]   name the name of the group which is displayed at the bottom of the group.
             */
            auto setGroupName(const QString &name) -> void;

            /**
             * @brief       Updates the margins to account for the group border.
             */
            auto updateMargins() -> void;

        protected:
            /**
             * @brief       Reimplements: QWidget::paintEvent(QPaintEvent *event).
             *
             * @param[in]   event the event information.
             */
            auto paintEvent(QPaintEvent *event) -> void override;

        private:
            QString m_groupName;                                    //! Group name that is displayed
            QFont m_font;                                           //! Font used to draw the group name
            QFontMetrics m_fontMetrics;                             //! The font metrics of the selected font
            QRect m_textRect;                                       //! The rectangle of the group name in the selected font
    };
}}

#endif // NEDRYSOFT_RIBBONGROUP_H
