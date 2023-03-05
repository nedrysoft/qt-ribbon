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

#include "RibbonFontManager.h"

#include <QFontDatabase>
#include <QList>

Nedrysoft::Ribbon::RibbonFontManager::RibbonFontManager() :
        m_regularFontId(QFontDatabase::addApplicationFont(":/Nedrysoft/Ribbon/OpenSans/OpenSans-Regular.ttf")),
        m_boldFontId(QFontDatabase::addApplicationFont(":/Nedrysoft/Ribbon/OpenSans/OpenSans-Bold.ttf")) {

}

auto Nedrysoft::Ribbon::RibbonFontManager::getInstance() ->Nedrysoft::Ribbon::RibbonFontManager * {
    static RibbonFontManager instance;

    return &instance;
}

auto Nedrysoft::Ribbon::RibbonFontManager::normalFont() -> QString const {
    auto families = QFontDatabase::applicationFontFamilies(m_regularFontId);

    if (families.count()) {
        return families.at(0);
    }

    return QString();
}

auto Nedrysoft::Ribbon::RibbonFontManager::boldFont() -> QString const {
    auto families = QFontDatabase::applicationFontFamilies(m_boldFontId);

    if (families.count()) {
        return families.at(0);
    }

    return QString();
}
