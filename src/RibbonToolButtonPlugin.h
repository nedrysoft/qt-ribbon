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

#ifndef NEDRYSOFT_RIBBONTOOLBUTTONPLUGIN_H
#define NEDRYSOFT_RIBBONTOOLBUTTONPLUGIN_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

/**
 * @brief       Ribbon push button with label Qt Designer plugin.
 *
 * @details     Exposes the RibbonToolButton widget to Qt Designer, this class is responsible for creating instances of
 *              the widget and exposing properties and functions required for design.
 */
class RibbonToolButtonPlugin :
        public QObject,
        public QDesignerCustomWidgetInterface {

    private:
        Q_OBJECT

        Q_INTERFACES(QDesignerCustomWidgetInterface)

    public:
        /**
         * @brief       Constructs a new RibbonToolButtonPlugin instance which is a child of the parent.
         *
         * @param[in]   parent the owner object.
         */
        explicit RibbonToolButtonPlugin(QObject *parent = nullptr);

        /**
         * @brief       Returns true if the widget is intended to be used as a container; otherwise returns false.
         *
         * @returns     true if it container; otherwise false.
         */
        bool isContainer() const override;

        /**
         * @brief       Returns true if the widget has been initialized; otherwise returns false.
         *
         * @returns     true if initialised; otherwise false.
         */
        bool isInitialized() const override;

        /**
         * @brief       Returns the icon used to represent the custom widget in Qt Designer's widget box.
         *
         * @returns     the icon used to represent the custom widget in Qt Designer's widget box.
         */
        QIcon icon() const override;

        /**
         * @brief       Returns the XML that is used to describe the custom widget's properties to Qt Designer.
         *
         * @returns     the XML describing the widgets properties.
         */
        QString domXml() const override;

        /**
         * @brief       Returns the name of the group to which the widget belongs.
         *
         * @returns     the name of the group.
         */
        QString group() const override;

        /**
         * @brief       Returns the path to the include file that uic uses when creating code for the widget.
         *
         * @returns     the path to the include file.
         */
        QString includeFile() const override;

        /**
         * @brief       Returns the class name of the widget supplied by the interface.
         *
         * @returns     the name of the widget.
         */
        QString name() const override;

        /**
         * @brief       Returns a short description of the widget that can be used by Qt Designer in a tool tip.
         *
         * @returns     the description.
         */
        QString toolTip() const override;

        /**
         * @brief       Returns a description of the widget that can be used by Qt Designer in "What's This?" help for the widget.
         *
         * @returns     the description.
         */
        QString whatsThis() const override;

        /**
         * @brief       Returns a new instance of the RibbonToolButton class, with the given parent.
         *
         * @returns     the widget instance.
         */
        QWidget *createWidget(QWidget *parent) override;

        /**
         * @brief       Initializes the widget for use with the specified formEditor interface.
         */
        void initialize(QDesignerFormEditorInterface *core) override;

    private:
        //! @cond

        bool m_initialized = false;

        //! @endcond
};

#endif // NEDRYSOFT_RIBBONTOOLBUTTONPLUGIN_H
