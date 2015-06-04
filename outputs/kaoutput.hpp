/***********************************************************************
 *
 * Lightweight AVR Outputs C++ bindings for KALibs
 * Copyright (C) 2015  Łukasz "Kuszki" Dróżdż
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 **********************************************************************/

#ifndef _KALIBS_KAOUTPUT_HPP
#define _KALIBS_KAOUTPUT_HPP

#include "../tools/kapin.hpp"

/*! \file kaoutoput.hpp
 *  \brief Zawiera deklaracje klasy KAOutput.
 *
 * Deklaracja zamieszczona w innym pliku pomaga uniknąć chaosu w organizacji kodu.
 *
 */

/*! \file kaoutoput.cpp
 *  \brief Zawiera implementacje klasy KAOutput.
 *
 * Implementacja każdej klasy w innym pliku pomaga uniknąć chaosu w organizacji kodu.
 *
 */

/*! \brief Reprezentacja cyfrowego wyjścia.
 *
 * Pozwala na łatwą obsługę wyjść cyfrowych.
 *
 */
class KAOutput : public KAPin
{

	public:

		/*! \brief			Konstruktor obiektu.
		 *  \param [in]		Port		Port wyprowadzenia.
		 *  \param [in]		Mask		Maska bitowa.
		 *
		 * Inicjuje wszystkie pola obiektu i ustala wyprowadzenie portu na wyjściowe.
		 *
		 */
		KAOutput(PORT Port,
			    char Mask);

		/*! \brief Destruktor obiektu.
		 *
		 * Wyłącza diodę i ustawia jej pin na wejściowy.
		 *
		 */
		~KAOutput(void);

		/*! \brief Uaktywnia wyjście.
		 *
		 * Ustala stan wysoki na wyjściu.
		 *
		 */
		void On(void);

		/*! \brief Deaktywuje wyjście.
		 *
		 * Ustala stan niski na wyjściu.
		 *
		 */
		void Off(void);

		/*! \brief Przełącza wyjście.
		 *
		 * Ustala odwrotny stan na wyjściu.
		 *
		 */
		void Switch(void);

		/*! \brief		Ustala stan wyjścia.
		 *  \param [in]	State Nowy stan wyjścia.
		 *  \see			On(), Off().
		 *
		 * Zmienia dotychczasowy stan wyjścia na wybrany.
		 *
		 */
		void SetState(bool State);

		/*! \brief		Sprawdza stan wyjścia.
		 *  \return		Aktualny stan wyjścia.
		 *
		 * Pobiera aktualny stan wyjścia.
		 *
		 */
		bool GetState(void) const;

};

#endif