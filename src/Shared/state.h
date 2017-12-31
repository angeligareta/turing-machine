#pragma once
#include "transition.h"

#include <set>
#include <iostream>

#define ERROR_VALUE 127

using namespace std;

class State{
   
   friend ostream &operator<<(ostream &,const State&);
   
   private:
   
   int identifier_;/**<Identificador del estado*/
   bool initial_;/**<Etiqueta inicial del estado*/ 
   bool final_;/**<Etiqueta final del estado*/ 
   set<Transition> set_transition_;/**<Conjunto de transiciones del estado*/ 
   
   public:
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto del estado.

*/

   State();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor al que se le pasa el identificador del estado.

*/
   
   State(const int);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor de copia del alfabeto.

*/

 
   State(const State&);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Destructor por defecto del alfabeto.

*/
   
   ~State();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Borra el contenido del alfabeto.

*/
   
   void clear();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Asigna un nuevo identificador al estado.

*/
   
   void set_identifier(const int);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Asigna un nuevo bool inicial al estado.

*/   

   void set_initial(const bool);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Asigna un nuevo bool final al estado.

*/   
   
   void set_final(const bool);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Inserta una nueva transición al estado.

*/   
   
   void insert_transition(const char, const char, const char, const int);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el identificador del estado.

*/   
   
   int get_identifier() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si el estado es inicial.

*/  

   bool get_initial() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si el estado es final.

*/ 

   bool get_final() const;


/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el conjunto de transiciones.

*/ 

   set<Transition> get_set_transition() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el siguiente estado para el símbolo de entrada.

*/ 

   int get_next_state(const char) const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el siguiente movimiento para el símbolo de entrada.

*/ 
   
   int get_next_movement(const char) const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el valor de escritura para el símbolo de entrada.

*/ 
   
   char get_next_write_value(const char) const;


/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Intercambia la 1º transición por la segunda.

*/ 
   
   void SwapTransition(const Transition&, const Transition&);
   
   State& operator=(const State &state_in);

   int operator==(const State &state_in) const;

   int operator<(const State &state_in) const;
   
};