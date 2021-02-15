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

void RibbonSliderPlugin::initialize(QDesignerFormEditorInterface *core) {
    Q_UNUSED(core)

    if (m_initialized) {
        return;
    }

    m_initialized = true;
}

bool RibbonSliderPlugin::isInitialized() const {
    return m_initialized;
}

QWidget *RibbonSliderPlugin::createWidget(QWidget *parent) {
    return new Nedrysoft::Ribbon::RibbonSlider(parent);
}

QString RibbonSliderPlugin::name() const {
    return QStringLiteral("Nedrysoft::Ribbon::RibbonSlider");
}

QString RibbonSliderPlugin::group() const {
    return QStringLiteral("Nedrysoft Ribbon Widgets");
}

QIcon RibbonSliderPlugin::icon() const {
    return QIcon(":/Nedrysoft/Ribbon/icons/ribbon.png");
}

QString RibbonSliderPlugin::toolTip() const {
    return QString();
}

QString RibbonSliderPlugin::whatsThis()  const {
    return tr("The Ribbon Line Edit is a QSlider subclass that is styled to match the Ribbon.");
}

bool RibbonSliderPlugin::isContainer() const {
    return false;
}

QString RibbonSliderPlugin::domXml() const {
    return ConfigurationXML;
}

QString RibbonSliderPlugin::includeFile() const {
    return QStringLiteral("Ribbon/RibbonSlider.h");
}
