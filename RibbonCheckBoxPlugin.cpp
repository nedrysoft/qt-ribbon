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

#include "RibbonCheckBoxPlugin.h"
#include "RibbonCheckBox.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Check Box">
        <widget class="Nedrysoft::Ribbon::RibbonCheckBox" name="ribbonCheckBox">
            <property name="text">
                <string>CheckBox</string>
            </property>
            <property name="checked">
                <bool>true</bool>
            </property>
        </widget>
    </ui>
)";

RibbonCheckBoxPlugin::RibbonCheckBoxPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

auto RibbonCheckBoxPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonCheckBoxPlugin::isInitialized() -> const {
    return m_initialized;
}

auto RibbonCheckBoxPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonCheckBox(parent);
}

auto RibbonCheckBoxPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonCheckBox");
}

auto RibbonCheckBoxPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonCheckBoxPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonCheckBoxPlugin::toolTip() -> QString const {
    return tr("A Ribbon Check Box");
}

auto RibbonCheckBoxPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Check Box is a QCheckBox subclass that is styled to match the Ribbon.");
}

auto RibbonCheckBoxPlugin::isContainer()  -> bool const {
    return false;
}

auto RibbonCheckBoxPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonCheckBoxPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonCheckBox.h");
}
