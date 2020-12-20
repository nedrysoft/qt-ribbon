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

#ifndef NEDRYSOFT_RIBBONFONTMANAGER_H
#define NEDRYSOFT_RIBBONFONTMANAGER_H

#include "RibbonSpec.h"

#include <QString>

namespace Nedrysoft::Ribbon {
    /**
     * @brief           The RibbonFont manager provides access to the system UI font.
     *
     * @details         Singleton responsible for loading and returning the fonts used
     *                  by the ribbon control.  This class is a singleton and therefore cannot be instantiated directly
     *                  the instace can be obtained using the getInstance() method.
     */
    class NEDRYSOFT_RIBBON_WIDGET_EXPORT RibbonFontManager {
        private:
            /**
             * @brief       Constructs a new RibbonFontManager.
             *
             * @note        Cannot be directly instantiated, this is a singleton class and the instance can be
             *              accessed through the getInstance() method.
             */
            explicit RibbonFontManager();

            /**
             * @brief       Destroys the MainWindow.
             */
            ~RibbonFontManager();

            /**
             * @brief       Delete the copy constructor.
             */
            RibbonFontManager(const RibbonFontManager&) = delete;

            /**
             * @brief       Delete the assignment operator.
             */
            RibbonFontManager& operator=(const RibbonFontManager&) = delete;

        public:
            /**
             * @brief       Returns the singleton instance of the RibbonFontManager class.
             *
             * @returns     the instance of the class
             */
            static Nedrysoft::Ribbon::RibbonFontManager *getInstance();

            /**
             * @brief       Returns the normal font name
             *
             * @returns     the normal font family name
             */
            QString normalFont() const;

            /**
             * @brief       Returns the bold font name
             *
             * @returns     the bold font family name
             */
            QString boldFont() const;

        private:
            int m_regularFontId;                                                //! Regular font id after loading
            int m_boldFontId;                                                   //! Bold font id after loading
    };
}

#endif // NEDRYSOFT_RIBBONFONTMANAGER_H
