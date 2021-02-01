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

#include "RibbonPushButtonPlugin.h"

#include "RibbonPushButton.h"

#include <QRegularExpression>
#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Push Button">
        <widget class="Nedrysoft::Ribbon::RibbonPushButton" name="ribbonPushButton">
            <property name="text">
                <string>Button</string>
            </property>
        </widget>
    </ui>
)";

RibbonPushButtonPlugin::RibbonPushButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

auto RibbonPushButtonPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonPushButtonPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonPushButtonPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonPushButton(parent);
}

auto RibbonPushButtonPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonPushButton");
}

auto RibbonPushButtonPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonPushButtonPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

void RibbonPushButtonPlugin::toolTip() -> QString const {
    return tr("A Ribbon Push Button");
}

auto RibbonPushButtonPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Push Button is a control that provides a main push button with optional text and is styled to match the Ribbon.");
}

auto RibbonPushButtonPlugin::isContainer() -> bool const {
    return true;
}

auto RibbonPushButtonPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonPushButtonPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonPushButton.h");
}
