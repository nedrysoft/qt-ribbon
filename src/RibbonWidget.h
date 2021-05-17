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

#ifndef NEDRYSOFT_RIBBONWIDGET_H
#define NEDRYSOFT_RIBBONWIDGET_H

#include <QtGlobal>

#include "RibbonSpec.h"

#include <QHBoxLayout>
#include <QMetaProperty>
#include <QTabWidget>

namespace Nedrysoft { namespace Ribbon {
    class RibbonTabBar;

    /**
     * @brief       Represents the current theme that the application should use.
     */
    enum ThemeMode {
        Light = 0,                                                              /**< Draw Ribbon in light mode. */
        Dark = 1                                                                /**< Draw Ribbon in dark mode. */
    };

    /**
     * @brief       TextColour of text on the control
     */
    static constexpr QRgb TextColor[] = {
        qRgb(73, 69, 66),
        qRgb(0xDC, 0xDC, 0xDC)
    };

    /**
     * @brief       Background colour of the tab bar
     */
    static constexpr QRgb TabBarBackgroundColor[] = {
        qRgb(0xf5, 0xf5, 0xf5),
        qRgb(0x2d, 0x2d, 0x2d)
    };

    /**
     * @brief       Highlight colour of a tab when hovered over
     */
    static constexpr QRgb TabHoverColor[] = {
        qRgb(254, 251, 255),
        TabBarBackgroundColor[Dark]
    };

    /**
     * @brief       Colour of a tab when the mouse is being held down
     */
    static constexpr QRgb TabSelectedColor[] = {
        qRgb(51, 84, 151),
        qRgb(0xdf, 0xdf, 0xdf)
    };

    /**
     * @brief       Colour of the ribbon divider at the bottom of the control
     */
    static constexpr QRgb RibbonBorderColor[] = {
        qRgb(214, 211, 207),
        qRgb(0, 0, 0)
    };

    /**
     * @brief       Colour of the group divider
     */
    static constexpr QRgb GroupDividerColor[] = {
        qRgb(180, 178, 173),
        qRgb(0x57, 0x57, 0x57)
    };

    /**
     * @brief       Colour of the push button
     */
    static constexpr QRgb PushButtonColor[] = {
        qRgb(209, 198, 197),
        qRgb(65, 65, 65)
    };

    /**
     * @note        Small tweaks are required on a OS level to ensure that the rendered RibbonBar looks correct
     *              on each platform.
     */

#if defined(Q_OS_MACOS)
    static constexpr int TabBarHeight = 34;
    static constexpr int DefaultFontSize = 12;
#else
    static constexpr int TabBarHeight = 28;
    static constexpr int DefaultFontSize = 10;
#endif
    static constexpr int RibbonBarHeight = 100;
    static constexpr int TabHighlightHeight = 3;
    static constexpr int GroupDividerMargin = 2;

    static constexpr int RibbonBarDefaultWidth = 200;

    /**
     * @brief       The RibbonWidget widget provides the main Ribbon container.
     *
     * @details     A RibbonWidget is the top level Ribbon control, a RibbonWidget consists of multiple pages
     *              of functional blocks, each functional block is then sub divided into logical groups (RibbonGroup) and
     *              finally each RibbonGroup acts as a container for Ribbon widgets.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonWidget :
            public QTabWidget {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Constructs a new RibbonWidget instance which is a child of the parent.
             *
             * @param[in]   parent the owner widget.
             */
            explicit RibbonWidget(QWidget *parent = nullptr);

            /**
             * @brief       Returns the ribbon bar background color.
             *
             * @returns     the colour.
             */
            auto backgroundColor() -> QColor;

            friend class RibbonTabBar;
            friend class RibbonGroup;

        protected:
            /**
             * @brief       Reimplements: QWidget::paintEvent(QPaintEvent *event).
             *
             * @param[in]   event the event information.
             */
            auto paintEvent(QPaintEvent *event) -> void override;

        private:
            //! @cond

            Nedrysoft::Ribbon::RibbonTabBar *m_tabBar;

            //! @endcond
    };
}}

#endif // NEDRYSOFT_RIBBONWIDGET_H
