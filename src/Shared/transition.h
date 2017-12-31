#pragma once

#include <set>
#include <iostream>
#include <cassert>

using namespace std;

class Transition{
   
   friend ostream& operator<<(ostream &,const Transition &);
   
   private:
   
   char symbol_entry_;/**<Símbolo de entrada de la transición.*/ 
   char write_value_;/**<Símbolo a escribir en el cabezal*/ 
   int next_movement_;/**<Siguiente movimiento.*/ 
   int number_next_state_;/**<Numero del siguiente estado*/
   
   public:

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto vacio de la transición.

*/

   Transition();

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto de la transición.

*/

   Transition(const char, const char, const char, const int);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor de copia de la transición.

*/

   Transition(const Transition&);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Destructor por defecto de la transición.

*/

   ~Transition();

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Cambia el estado siguiente 1 por el 2.

*/
   
   void swap_next_state (const int);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Cambia el simbolo de entrada 1 por el 2.

*/
   
   void swap_symbol_entry (const char);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Cambia el movimiento 1 por el 2.

*/
   
   void swap_movement (const char);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el siguiente estado.

*/
   
   int get_next_state () const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el sñimbolo de entrada.

*/
   
   char get_symbol_entry () const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el siguiente movimiento.

*/
   
   int get_movement () const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el valor a escribir.

*/
   
   char get_write_value() const;

   Transition& operator= (const Transition&);

   int operator== (const Transition&) const;

   int operator< (const Transition&) const;
   
   private:
   
   void ConvertMovementToInt(const char);
};