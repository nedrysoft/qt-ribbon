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

void RibbonComboBoxPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core);

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonComboBoxPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonComboBoxPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonComboBox(parent);
}

QString RibbonComboBoxPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonComboBox");
}

QString RibbonComboBoxPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonComboBoxPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonComboBoxPlugin::toolTip() const {
    return tr("A Ribbon Combo Box");
}

QString RibbonComboBoxPlugin::whatsThis() const {
    return tr("The Ribbon Combo Box is a QComboBox subclass that is styled to match the Ribbon.");
}

bool RibbonComboBoxPlugin::isContainer() const {
    return false;
}

QString RibbonComboBoxPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonComboBoxPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonComboBox.h");
}
