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

#ifndef NEDRYSOFT_RIBBONSPEC_H
#define NEDRYSOFT_RIBBONSPEC_H

#if defined(RIBBON_DESIGNER_EXPORT)
#include <QtUiPlugin/QDesignerExportWidget>
#define NEDRYSOFT_RIBBON_WIDGET_EXPORT Q_DECL_EXPORT
#else
#if defined(NEDRYSOFT_LIBRARY_RIBBON_EXPORT)
#define NEDRYSOFT_RIBBON_WIDGET_EXPORT Q_DECL_EXPORT
#else
#define NEDRYSOFT_RIBBON_WIDGET_EXPORT Q_DECL_IMPORT
#endif
#endif

#endif // NEDRYSOFT_RIBBONSPEC_H
