/*
 * Copyright (C) 2021 Adrian Carpenter
 *
 * This file is part of the Nedrysoft Ribbon Bar. (https://github.com/nedrysoft/qt-ribbon)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 26/06/2021.
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

#ifndef PINGNOO_COMPONENTS_CORE_RIBBONACTION_H
#define PINGNOO_COMPONENTS_CORE_RIBBONACTION_H

#include <QObject>

namespace Nedrysoft { namespace Ribbon {
    class RibbonDropButton;

    enum class EventType {
        Null,
        DropButtonClicked
    };

    class Event {
        public:
            virtual auto type() -> Nedrysoft::Ribbon::EventType {
                return Nedrysoft::Ribbon::EventType::Null;
            }
    };

    class DropButtonClickedEvent :
        public Nedrysoft::Ribbon::Event {

        public:
            DropButtonClickedEvent(RibbonDropButton *dropButton, bool dropDown) :
                    m_button(dropButton),
                    m_dropDown(dropDown) {

            }

            auto type() -> Nedrysoft::Ribbon::EventType override {
                return Nedrysoft::Ribbon::EventType::DropButtonClicked;
            }

            auto button() -> RibbonDropButton * {
                return m_button;
            }

            auto dropDown() -> bool {
                return m_dropDown;
            }

        private:
            Nedrysoft::Ribbon::RibbonDropButton *m_button;
            bool m_dropDown;
    };


    /**
     * @brief       The RibbonAction class provides a QAction style object which is used by the ribbon bar
     *              to indicate that an action has been triggered by the user.
     */
    class RibbonAction :
            public QObject {

        private:
            Q_OBJECT

        public:
            /**
             * @brief       Sets whether the ribbon action is enabled.
             *
             * @note        The ribbon action state can be used to synchonise ribbon items enabled state.
             *
             * @param[in]   state should be true if the action is enabled; otherwise false.
             */
            auto setEnabled(bool state) -> void {
                m_enabled = state;
            }

            /**
             * @brief       Emits the ribbonEvent signal with the given event data.
             *
             * @param[in]   event the event.
             */
            virtual auto triggerEvent(Nedrysoft::Ribbon::Event *event) -> void {
                Q_EMIT ribbonEvent(event);
            }

        public:
            /**
             * @brief       Emitted when an event occurs on the owner widget.
             *
             * @param[in]   event contains information about the event.
             */
            Q_SIGNAL void ribbonEvent(Nedrysoft::Ribbon::Event *event);

        private:
            //! @cond

            bool m_enabled;

            //! @endcond
    };
}}

#endif // PINGNOO_COMPONENTS_CORE_RIBBONACTION_H
