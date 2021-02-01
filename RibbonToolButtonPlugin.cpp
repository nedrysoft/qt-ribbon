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

auto RibbonToolButtonPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonToolButtonPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonToolButtonPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonToolButton(parent);
}

auto RibbonToolButtonPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonToolButton");
}

auto RibbonToolButtonPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonToolButtonPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonToolButtonPlugin::toolTip() -> QString const {
    return tr("A Ribbon Tool Button");
}

auto RibbonToolButtonPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Tool Button is a control that provides a tool button in the ribbon style.");
}

auto RibbonToolButtonPlugin::isContainer() -> bool const {
    return true;
}

auto RibbonToolButtonPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonToolButtonPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonToolButton.h");
}
