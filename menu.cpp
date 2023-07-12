#include <iostream>
#include "menu.h"
#include "funciones.h"

#include "juego.h"
#include <wchar.h>
#include <conio.h>


using namespace std;

void mostrarMenu()
{

    limpiarConsola();

    char a = 201; // ╔
    char b = 205; // ═
    char c = 187; // ╗
    char d = 186; // ║
    char e = 200; // ╚
    char f = 188; // ╝
    char h = 185; // ╣
    char g = 174; //«
    char j = 175; //»

    int opcion;
    bool flag_estadisticas=false;
    char confirmacion;

    do{
        cout <<"    " << g << b << h << b << b << b << "IRWIN'S" << b << "REVENGE" << j << endl;
        cout << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << c << endl;
        cout << d << "   1 - Jugar                 " << d << endl;
        cout << d << "   2 - Mostrar reglamento    " << d << endl;
        cout << d << "   3 - Mostrar estadisticas  " << d << endl;
        cout << d << "   4 - Mostrar creditos      " << d << endl;
        cout << d << "   0 - Salir                 " << d << endl;
        cout << e << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << f << endl;

        cout << endl << "Ingresar opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
            case 1:
                {
                    iniciarJuego();
                    break;
                }
            case 2:
                {
                    mostrarReglamento();
                    mostrarMenu();

                    break;
                }
            case 3:
                {
                    if (flag_estadisticas==false){
                        limpiarConsola();

                        cout << "Las estadisticas muestran al jugador con la mayor cantidad de puntos de victoria." << endl;
                        cout << "Desafia a un amigo a jugar Irwin's Revange para desbloquear la seccion." << endl << endl;

                    }else{
                        mostrarEstadisticas();
                    }
                    cout << endl <<  "Presione ENTER para volver al menu principal." << endl << endl;

                    esperarEnter();
                    mostrarMenu();

                    break;
                }
            case 4:
                {
                    mostrarCreditos();
                    cout << endl <<  "Presione ENTER para volver al menu principal." << endl << endl;
                    esperarEnter();
                    mostrarMenu();
                    break;
                }
            case 0:
                {
                     cout << "¿Está seguro de que quiere salir? (S/N)" << endl;
                     cin >> confirmacion;

                     if (confirmacion == 'S' || confirmacion == 's'){
                        salir();
                     }else{
                        mostrarMenu();
                     }
                    break;
                }
            default:{
                cout << endl << "Opcion incorrecta, presione enter para volver al menu." << endl << endl << endl;
                esperarEnter();
                mostrarMenu();
                break;
            }
        }
    }while( opcion < 0 || opcion > 4 );
}

void mostrarMenuEstatuillas()
{
    limpiarConsola();

    // INICIO DEL MENU ELEGIR ESTATUILLA
    char a = 201; // ╔
    char b = 205; // ═
    char c = 187; // ╗
    char d = 186; // ║
    char e = 200; // ╚
    char f = 188; // ╝
    char h = 185; // ╣
    char g = 174; //«
    char j = 175; //»

    cout << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << c << endl;
    cout << d << "  1 - Cangrejo de arena    " << d << endl;
    cout << d << "  2 - Aguila de aire       " << d << endl;
    cout << d << "  3 - Hormiga de tierra    " << d << endl;
    cout << d << "  4 - Salamandra de fuego  " << d << endl;
    cout << d << "  5 - Medusa de agua       " << d << endl;
    cout << e << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << f << endl;
    // FIN DEL MENU ELEGIR ESTATUILLA
}

void mostrarReglamento()
{
    limpiarConsola();

    cout << "Irwin's Revenge es un juego de dados en el que dos jugadores compiten por obtener estatuillas en la Fase de Expedición. Lanzan dos dados de 10 caras y siguen reglas para obtener las estatuillas." << endl;
    cout << "Luego, pasan a la Fase Final, donde lanzan cinco dados de 6 caras para formar una escalera y ganar el juego." << endl;
    cout << "Algunas estatuillas tienen reglas especiales." << endl;
    cout << "El jugador con más estatuillas gana el turno de la Fase Final." << endl;
    cout << "La victoria se determina por la escalera o reglas especiales de las estatuillas." << endl;
    cout << endl <<  "Presione ENTER para volver al menu principal." << endl << endl;
    esperarEnter();
}

/*
void mostrarCondicionDeObtencion()
{
    std::string condicion_obtencion(int estatuillaElegida[], int x)
	std::string condicion;

	switch (estatuillaElegida[x]) {
	case 1:
		condicion = "Condicion de la obtencion: Uno de sus dados debe ser par y otro de sus dados impar.";
		break;

	case 2:
		condicion = "Condicion de la obtencion: Al menos dos dados deben ser menores a 5.";
		break;

	case 3:
		condicion = "Condicion de la obtencion: La suma de dos de los dados lanzados debe dar exactamente siete.";
		break;

	case 4:
		condicion = "Condicion de la obtencion: Dos de los dados lanzados deberán devolver los números 1 y 10.";
		break;

	case 5:
		condicion = "Condicion de la obtencion: Los dados lanzados deben ser consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10)";
		break;
	}

	return condicion;
}
}
*/


void mostrarCreditos()
{
    limpiarConsola();

    cout << "Integrantes del grupo ... :" << endl << endl;
}

void mostrarEstadisticas()
{

    limpiarConsola();

    string jugador1 = "pepe";
    string jugador2 = "elrufian";

    cout << "HITO \t" << jugador1 << "\t" << jugador2 << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Estatuilla \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Estatuilla++ \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Estatuilla-- \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Ganador \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "Lanzamiento \t " << "PUNTOS 1" << "\t" << "PUNTOS 2" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "TOTAL \t" << "PUNTOS 1 " << "\t" << " PUNTOS 1 " << "\t" << " PUNTOS 2" << endl;
    cout << "GANADOR: " << "GANADOR" << " con " << "PUNTOS" << "puntos de victoria" << endl;
    cout << endl << endl << endl;
}





