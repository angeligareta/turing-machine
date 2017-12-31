#pragma once

#include <iostream>
#include <cstring>
#include <list>
#include <iterator>

using namespace std;

class Tape{
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	   \details    Muestra el Turing Machine en el ostream.
*/   

    friend ostream &operator<<(ostream&, const Tape&);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	   \details    Lee el Turing Machine del istream.
*/  

    friend istream& operator>>(istream&, Tape&);
   
    private:

    list<char> tape_;/**<Cinta infinita*/
    list<char>::iterator head_;/**<Cabecera de la cinta*/
   
    public:
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Constructor por defecto.
*/

    Tape();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Destructor por defecto. Limpia los conjuntos de simbolos no terminales y terminales.
*/

    ~Tape();
   
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details    Muestra la cinta.

*/

    void ShowTapeWithState(const int) const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Escribe el simbolo de entrada en la cabecera de la cinta.

*/
    
    void WriteSymbolInTape(const char);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details      Devuelve el simbolo en la cabecera de la cinta.

*/
    
    char ReadSymbolInTape() const;

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Mover la cabecera de la cinta.

*/
    
    void MoveHeadInTape(const int);

/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Inicializar cinta.

*/
    
    void InicializeTape();
    
/**
      \author   	Angel Luis Igareta Herráiz(angeliton@hotmail.es)
      \date 		22 de octubre de 2016

	\details       Devuelve si la cinta está vacía.

*/    

    bool is_empty() const;
   
    private:
   
    void clear();
   
    
   
};