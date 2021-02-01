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

#include "RibbonWidgetPlugin.h"

#include "RibbonWidget.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Widget">
        <widget class="Nedrysoft::Ribbon::RibbonWidget" name="ribbonWidget">
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

RibbonWidgetPlugin::RibbonWidgetPlugin(QObject *parent) :
        QObject(parent) {

    qRegisterMetaType<RibbonWidgetPlugin *>("RibbonWidgetPlugin");
}

auto RibbonWidgetPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonWidgetPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonWidgetPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonWidget(parent);
}

auto RibbonWidgetPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonWidget");
}

auto RibbonWidgetPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonWidgetPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonWidgetPlugin::toolTip() -> QString const {
    return tr("A Ribbon Widget");
}

auto RibbonWidgetPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Widget is the top level container of the Ribbon Bar.");
}

auto RibbonWidgetPlugin::isContainer() -> bool const {
    return false;
}

auto RibbonWidgetPlugin::domXml() -> QString const {
    return QString(ConfigurationXML)
            .replace("[default-width]", QString::number(Nedrysoft::Ribbon::RibbonBarDefaultWidth))
            .replace("[default-height]", QString::number(Nedrysoft::Ribbon::RibbonBarHeight));
}

auto RibbonWidgetPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonWidget.h");
}
