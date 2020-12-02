/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * https://github.com/fizzyade
 *
 * Created by Adrian Carpenter on 11/11/2020.
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

void RibbonDropButtonPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core);

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonDropButtonPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonDropButtonPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonDropButton(parent);
}

QString RibbonDropButtonPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonDropButton");
}

QString RibbonDropButtonPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonDropButtonPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonDropButtonPlugin::toolTip() const {
    return tr("A Ribbon Drop Button");
}

QString RibbonDropButtonPlugin::whatsThis() const {
    return tr("The Ribbon Drop Button is button which contains a main action button and a drop down button for extended actions and is styled to match the Ribbon.");
}

bool RibbonDropButtonPlugin::isContainer() const {
    return true;
}

QString RibbonDropButtonPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonDropButtonPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonDropButton.h");
}
