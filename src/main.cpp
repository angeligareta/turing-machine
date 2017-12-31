#include "TM/turing_machine.h"
#include "TM/tape.h"

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
		
	TuringMachine turing_machine; Tape tape;
	
	if (argc != 3) {
        cout << "ERROR: Número de argumentos inválido." << endl;
        return 0;
    }
	
    ifstream file_1; file_1.open(argv[1]); file_1 >> turing_machine;
    string string_tape=argv[2];
    ifstream file_2; file_2.open(string_tape); file_2 >> tape; tape.InicializeTape();
    
    int opcion,tape_error=0,turing_error=0;
    
    if (turing_machine.is_empty()) {
        cout << "ERROR EN EL FICHERO DE LECTURA DE LA MAQUINA DE TURING" << endl;
        turing_error=1;
    }
    
    if (tape.is_empty()) {
        cout << "ERROR EN EL FICHERO DE LECTURA DE LA CINTA" << endl;
        tape_error=1;
    }
    
    // Menú
    do {
        cout << "\n\n" << "╔" << string(40, '-') << " Selecciona una opción " << string(40, '-') << "╗" <<  "\n" << endl;
        
        cout << "\t⬤ Opción 0: Salir" << endl;
        cout << "\t⬤ Opción 1: Cambiar Máquina de Turning" << endl;
        cout << "\t⬤ Opción 2: Cambiar Cinta"<< endl;
        cout << "\t⬤ Opción 3: Mostar Máquina de Turning" << endl;
        cout << "\t⬤ Opción 4: Mostrar Cinta" << endl;
        cout << "\t⬤ Opción 5: Comprobar Cadena y Mostrar Proceso" << endl;
        cout << "\t⬤ Opción 6: Comprobar Cadena y Mostrar Proceso Lentamente" << endl;
        cout << "\t⬤ Opción 7: Comprobar Cadena Sin Mostrar" << endl;
        
        cout << "\n" << "╚" << string (103, '-') << "╝" << endl;
        cin >> opcion;
        system ("clear");
        
        switch (opcion) {
                case 1:
                {
                    cout << "Introduce el nombre del fichero .tm:" << endl;
                    string string_aux; cin >> string_aux;
                    file_1.close(); file_1.open(string_aux); file_1 >> turing_machine;
                    
                    if (turing_machine.is_empty()) {
                        cout << "ERROR EN EL FICHERO DE LECTURA DE LA MAQUINA DE TURING" << endl;
                        turing_error=1;
                    }
                    else
                        turing_error=0;
                    
                    break;    
                }
                case 2:
                {
                    cout << "Introduce el nombre del fichero .tape:" << endl;
                    string string_aux; cin >> string_tape;
                    file_2.close(); file_2.open(string_tape); file_2 >> tape; tape.InicializeTape();
                    if (tape.is_empty()) {
                        cout << "ERROR EN EL FICHERO DE LECTURA DE LA CINTA" << endl;
                        tape_error=1;
                    }
                    else
                        tape_error=0;
                    break;
                }
                case 3:
                {
                    if (!tape_error && !turing_error)
                        cout << turing_machine;
                    else {
                        if (tape_error)
                            cout << "DEBE INTRODUCIR UNA CINTA CORRECTA PRIMERO" << endl;
                        else if (turing_error)
                            cout << "DEBE INTRODUCIR UNA MAQUINA TURING CORRECTA PRIMERO" << endl;
                    }
                    break;
                }
                case 4:
                {
                    if (!tape_error && !turing_error)
                        cout << tape;
                    else {
                        if (tape_error)
                            cout << "DEBE INTRODUCIR UNA CINTA CORRECTA PRIMERO" << endl;
                        else if (turing_error)
                            cout << "DEBE INTRODUCIR UNA MAQUINA TURING CORRECTA PRIMERO" << endl;
                    }
                    break;
                }
                case 5:
                {
                    if (!tape_error && !turing_error){
                        char option2='n';
                        do{
                            int tape_accepted=turing_machine.AnalyzeTape(tape,1);
                            if (tape_accepted==1)
                                cout << "\n\t\t ¡ La cadena está aceptada !" << endl;
                            else if (tape_accepted==0)
                                cout << "\n\t\t ¡ La cadena no está aceptada !" << endl;
                            else if (tape_accepted==-1){
                                cout << "\t\t ¡ La cadena no está aceptada !" << endl;
                                cout << "\n\t\t ¡ La máquina de Turing entra en bucle Infinito !" << endl;
                                cout << "\n\t\t ¿Quiere seguir iterando para ver si se acepta? (y/n)" << endl;
                                cin >> option2;
                            }
                        }while (option2=='y');
                        file_2.close(); file_2.open(string_tape); 
                        file_2 >> tape; tape.InicializeTape();
                    }
                    else {
                        if (tape_error)
                            cout << "DEBE INTRODUCIR UNA CINTA CORRECTA PRIMERO" << endl;
                        else if (turing_error)
                            cout << "DEBE INTRODUCIR UNA MAQUINA TURING CORRECTA PRIMERO" << endl;
                    }
                    break;
                }
                case 6:
                {
                   if (!tape_error && !turing_error){
                        char option2='n';
                        do{
                            int tape_accepted=turing_machine.AnalyzeTape(tape,2);
                            if (tape_accepted==1)
                                cout << "\n\t\t ¡ La cadena está aceptada !" << endl;
                            else if (tape_accepted==0)
                                cout << "\n\t\t ¡ La cadena no está aceptada !" << endl;
                            else if (tape_accepted==-1){
                                cout << "\t\t ¡ La cadena no está aceptada !" << endl;
                                cout << "\n\t\t ¡ La máquina de Turing entra en bucle Infinito !" << endl;
                                cout << "\n\t\t ¿Quiere seguir iterando para ver si se acepta? (y/n)" << endl;
                                cin >> option2;
                            }
                        }while (option2=='y');
                        file_2.close(); file_2.open(string_tape); 
                        file_2 >> tape; tape.InicializeTape();
                    }
                    else {
                        if (tape_error)
                            cout << "DEBE INTRODUCIR UNA CINTA CORRECTA PRIMERO" << endl;
                        else if (turing_error)
                            cout << "DEBE INTRODUCIR UNA MAQUINA TURING CORRECTA PRIMERO" << endl;
                    }
                    break;
                }
                case 7:
                {
                    if (!tape_error && !turing_error){
                        char option2='n';
                        do{
                            int tape_accepted=turing_machine.AnalyzeTape(tape,0);
                            if (tape_accepted==1)
                                cout << "\n\t\t ¡ La cadena está aceptada !" << endl;
                            else if (tape_accepted==0)
                                cout << "\n\t\t ¡ La cadena no está aceptada !" << endl;
                            else if (tape_accepted==-1){
                                cout << "\t\t ¡ La cadena no está aceptada !" << endl;
                                cout << "\n\t\t ¡ La máquina de Turing entra en bucle Infinito !" << endl;
                                cout << "\n\t\t ¿Quiere seguir iterando para ver si se acepta? (y/n)" << endl;
                                cin >> option2;
                            }
                        }while (option2=='y');
                        file_2.close(); file_2.open(string_tape); 
                        file_2 >> tape; tape.InicializeTape();
                    }
                    else {
                        if (tape_error)
                            cout << "DEBE INTRODUCIR UNA CINTA CORRECTA PRIMERO" << endl;
                        else if (turing_error)
                            cout << "DEBE INTRODUCIR UNA MAQUINA TURING CORRECTA PRIMERO" << endl;
                    }
                    break;
                }
                default: cout << "Introduzca un número válido" << endl; break;
        }
        
    } while (opcion!=0);

	file_1.close(); file_2.close();
}