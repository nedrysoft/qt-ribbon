/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * https://github.com/fizzyade
 *
 * Created by Adrian Carpenter on 07/11/2020.
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

#include "RibbonGroupPlugin.h"
#include "RibbonGroup.h"
#include "RibbonWidget.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Group">
        <widget class="Nedrysoft::Ribbon::RibbonGroup" name="ribbonGroup">
            <property name="groupName">
                <string>Group</string>
            </property>
        
            <property name="geometry">
                <rect>
                    <x>0</x>
                    <y>0</y>
                    <width>[default-width]</width>
                    <height>[default-height]</height>
                </rect>
            </property>
        </widget>
    </ui>
)";

RibbonGroupPlugin::RibbonGroupPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

void RibbonGroupPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core);

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonGroupPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonGroupPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonGroup(parent);
}

QString RibbonGroupPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonGroup");
}

QString RibbonGroupPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonGroupPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonGroupPlugin::toolTip() const {
    return tr("A Ribbon Group");
}

QString RibbonGroupPlugin::whatsThis() const {
    return tr("The Ribbon Group is a container that contains a set of controls that are logically grouped together.");
}

bool RibbonGroupPlugin::isContainer() const {
    return true;
}

QString RibbonGroupPlugin::domXml() const {
    return QString(ConfigurationXML).replace("[default-width]", QString::number(Nedrysoft::Ribbon::RibbonBarDefaultWidth))
                                    .replace("[default-height]", QString::number(Nedrysoft::Ribbon::RibbonBarHeight));
}

QString RibbonGroupPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonGroup.h");
}
