#pragma once

#include "../Shared/alphabet.h"
#include "../Shared/state.h"
#include "../Shared/transition.h"
#include "tape.h"

#include <iostream>
#include <cstring>
#include <list>
#include <set>
#include <unistd.h>

#define ERROR_VALUE 127

using namespace std;

class TuringMachine{
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	   \details    Muestra el Turing Machine en el ostream.
*/   

   friend ostream &operator<<(ostream&, const TuringMachine&);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	   \details    Lee el Turing Machine del istream.
*/  

   friend istream& operator>>(istream&, TuringMachine&);
   
   private:
   
   set<State> set_state_;     /**< Conjunto de estados*/
   Alphabet alphabet_;        /**< Conjunto de simbolos*/
   Alphabet alphabet_tape_;   /**< Conjunto de simbolos de la cinta*/
   
   public:
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto.
*/

   TuringMachine();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Destructor por defecto. Limpia los conjuntos de simbolos no terminales y terminales.
*/

   ~TuringMachine();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	   \details    Destructor por defecto. Limpia los conjuntos de simbolos no terminales y terminales.
	   
	   * @param  	Devuelve si esta vacío o no el Turing Machine.
*/   
   
   bool is_empty() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Analaliza la cinta

*/
   
   int AnalyzeTape(Tape&, const int);
   
   private:
   
   void clear();
   
   State GetStateWithId(const int) const;
   
   State GetInitialState() const;
   
   set<State> GetFinalState() const;
   
   void SwapState(const State&, const State&);
   
   bool is_infinite() const;
};