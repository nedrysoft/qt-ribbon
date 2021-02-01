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

#include "RibbonSliderPlugin.h"
#include "RibbonSlider.h"

#include <QtPlugin>

constexpr auto ConfigurationXML = R"(
    <ui language="c++" displayname="Ribbon Slider">
        <widget class="Nedrysoft::Ribbon::RibbonSlider" name="ribbonSlider">
        </widget>
    </ui>
)";

RibbonSliderPlugin::RibbonSliderPlugin(QObject *parent) :
        QObject(parent),
        m_initialized(false) {

}

auto RibbonSliderPlugin::initialize(QDesignerFormEditorInterface *core) -> void {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

auto RibbonSliderPlugin::isInitialized() -> bool const {
    return m_initialized;
}

auto RibbonSliderPlugin::createWidget(QWidget *parent) -> QWidget * {
    return new Nedrysoft::Ribbon::RibbonSlider(parent);
}

auto RibbonSliderPlugin::name() -> QString const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonSlider");
}

auto RibbonSliderPlugin::group() -> QString const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

auto RibbonSliderPlugin::icon() -> QIcon const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

auto RibbonSliderPlugin::toolTip() -> QString const {
    return QString();
}

auto RibbonSliderPlugin::whatsThis() -> QString const {
    return tr("The Ribbon Line Edit is a QSlider subclass that is styled to match the Ribbon.");
}

auto RibbonSliderPlugin::isContainer() -> bool const {
    return false;
}

auto RibbonSliderPlugin::domXml() -> QString const {
    return ConfigurationXML;
}

auto RibbonSliderPlugin::includeFile() -> QString const {
    return QStringLiteral("Ribbon/RibbonSlider.h");
}
