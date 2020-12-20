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

void RibbonCheckBoxPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core);

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonCheckBoxPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonCheckBoxPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonCheckBox(parent);
}

QString RibbonCheckBoxPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonCheckBox");
}

QString RibbonCheckBoxPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonCheckBoxPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonCheckBoxPlugin::toolTip() const {
    return tr("A Ribbon Check Box");
}

QString RibbonCheckBoxPlugin::whatsThis() const {
    return tr("The Ribbon Check Box is a QCheckBox subclass that is styled to match the Ribbon.");
}

bool RibbonCheckBoxPlugin::isContainer() const {
    return false;
}

QString RibbonCheckBoxPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonCheckBoxPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonCheckBox.h");
}
