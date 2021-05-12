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

#include "RibbonToolButtonPlugin.h"

#include "RibbonToolButton.h"

#include <QRegularExpression>
#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Tool Button">
        <widget class="Nedrysoft::Ribbon::RibbonToolButton" name="ribbonToolButton">
            <property name="text">
                <string>Button</string>
            </property>
        </widget>
    </ui>
)";

RibbonToolButtonPlugin::RibbonToolButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

void RibbonToolButtonPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonToolButtonPlugin::isInitialized() const {
    return m_initialized;
}

QWidget * RibbonToolButtonPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonToolButton(parent);
}

QString RibbonToolButtonPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonToolButton");
}

QString RibbonToolButtonPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonToolButtonPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonToolButtonPlugin::toolTip() const {
    return tr("A Ribbon Tool Button");
}

QString RibbonToolButtonPlugin::whatsThis() const {
    return tr("The Ribbon Tool Button is a control that provides a tool button in the ribbon style.");
}

bool RibbonToolButtonPlugin::isContainer() const {
    return true;
}

QString RibbonToolButtonPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonToolButtonPlugin::includeFile() const {
    return QStringLiteral("<RibbonToolButton>");
}
