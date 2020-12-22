/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of the Nedrysoft Ribbon Bar. (https://github.com/fizzyade/qt-ribbon)
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

#include "RibbonDropButtonPlugin.h"
#include "RibbonDropButton.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Drop Button">
        <widget class="Nedrysoft::Ribbon::RibbonDropButton" name="ribbonDropButton">
        </widget>
    </ui>
)";

RibbonDropButtonPlugin::RibbonDropButtonPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

auto RibbonDropButtonPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonDropButtonPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonDropButtonPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonDropButton(parent);
}

auto RibbonDropButtonPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonDropButton");
}

auto RibbonDropButtonPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonDropButtonPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonDropButtonPlugin::toolTip() -> QString const {
    return tr("A Ribbon Drop Button");
}

auto RibbonDropButtonPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Drop Button is button which contains a main action button and a drop down button for extended actions and is styled to match the Ribbon.");
}

auto RibbonDropButtonPlugin::isContainer() -> bool const {
    return true;
}

auto RibbonDropButtonPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonDropButtonPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonDropButton.h");
}
