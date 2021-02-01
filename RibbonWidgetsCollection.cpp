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

#include "RibbonWidgetsCollection.h"

#include "RibbonButtonPlugin.h"
#include "RibbonCheckBoxPlugin.h"
#include "RibbonComboBoxPlugin.h"
#include "RibbonDropButtonPlugin.h"
#include "RibbonGroupPlugin.h"
#include "RibbonLineEditPlugin.h"
#include "RibbonPushButtonPlugin.h"
#include "RibbonToolButtonPlugin.h"
#include "RibbonWidgetPlugin.h"

RibbonWidgetsCollection::RibbonWidgetsCollection(QObject *parent) :
        QObject(parent) {

    m_widgets.append(new RibbonGroupPlugin(this));
    m_widgets.append(new RibbonWidgetPlugin(this));
    m_widgets.append(new RibbonDropButtonPlugin(this));
    m_widgets.append(new RibbonPushButtonPlugin(this));
    m_widgets.append(new RibbonLineEditPlugin(this));
    m_widgets.append(new RibbonComboBoxPlugin(this));
    m_widgets.append(new RibbonCheckBoxPlugin(this));
    m_widgets.append(new RibbonToolButtonPlugin(this));
    m_widgets.append(new RibbonButtonPlugin(this));
}

auto RibbonWidgetsCollection::customWidgets() -> QList<QDesignerCustomWidgetInterface*> const {
    return m_widgets;
}
