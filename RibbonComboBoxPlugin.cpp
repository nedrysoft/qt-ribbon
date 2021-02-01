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

#include "RibbonComboBoxPlugin.h"
#include "RibbonComboBox.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Combo Box">
        <widget class="Nedrysoft::Ribbon::RibbonComboBox" name="ribbonComboBox">
            <property name="geometry">
                <rect>
                    <x>0</x>
                    <y>0</y>
                    <width>100</width>
                    <height>13</height>
                </rect>
            </property>
        </widget>
    </ui>
)";

RibbonComboBoxPlugin::RibbonComboBoxPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

auto RibbonComboBoxPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonComboBoxPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonComboBoxPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonComboBox(parent);
}

auto RibbonComboBoxPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonComboBox");
}

auto RibbonComboBoxPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonComboBoxPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonComboBoxPlugin::toolTip() -> QString const {
    return tr("A Ribbon Combo Box");
}

auto RibbonComboBoxPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Combo Box is a QComboBox subclass that is styled to match the Ribbon.");
}

auto RibbonComboBoxPlugin::isContainer() -> bool const {
    return false;
}

auto RibbonComboBoxPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonComboBoxPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonComboBox.h");
}
