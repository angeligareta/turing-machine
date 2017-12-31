#pragma once

#include <set>
#include <iostream>

using namespace std;

class Alphabet{
   
   friend ostream &operator<<(ostream&,const Alphabet&);
   
   private:
   
   set<char> alphabet_; /**< Conjunto de símbolos.*/
   
   public:
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto del alfabeto.

*/

   Alphabet();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Destructor por defecto del alfabeto. Llama a Clear.
   
*/   
   ~Alphabet();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve el alfabeto (set de char).
   
*/

   set<char> get_alphabet() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuleve el número de símbolos del alfabeto.
   
*/
   
   int get_size() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si el símbolo entrante esta contenido en el alfabeto.
   
*/
   
   bool it_belongs(const char&) const;
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si el set de símbolos entrante esta contenido en el alfabeto.
   
*/   
   
   bool it_belongs(const set<char>&) const;
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si el alfabeto está vacío.
   
*/   

   bool is_empty() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Borra el símbolo entrante del alfabeto.
   
*/

   void erase(const char&);
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Inserta un símbolo en el alfabeto.
   
*/

   void insert(const char&);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Borra el contenido del alfabeto.
   
*/

   void clear();




};