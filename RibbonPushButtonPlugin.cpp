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

void RibbonPushButtonPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core);

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonPushButtonPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonPushButtonPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonPushButton(parent);
}

QString RibbonPushButtonPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonPushButton");
}

QString RibbonPushButtonPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonPushButtonPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonPushButtonPlugin::toolTip() const {
    return tr("A Ribbon Push Button");
}

QString RibbonPushButtonPlugin::whatsThis() const {
    return tr("The Ribbon Push Button is a control that provides a main push button with optional text and is styled to match the Ribbon.");
}

bool RibbonPushButtonPlugin::isContainer() const {
    return true;
}

QString RibbonPushButtonPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonPushButtonPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonPushButton.h");
}
