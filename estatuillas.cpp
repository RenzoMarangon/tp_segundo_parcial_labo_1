#include <iostream>
using namespace std;
#include <string>
#include "funciones.h"
#include "menu.h"

int elegirEstatuilla(string jugador, int* cantEstatuillasElegidas)
{
    int estatuillaElegida;
    string estatuillas[] = { "Cangrejo de arena", "Hormiga de tierra", "Medusa de agua",  "Aguila de aire", "Salamandra de fuego"};
    bool estatuillaElegidaYaExiste = false;
    string usuarioElige;

    do{

        cout << endl << "Menu para elegir estatuillas" << endl;
        mostrarMenuEstatuillas();


        cout << endl << jugador << " elija una opcion: " << endl;
        cin >> estatuillaElegida;


        //Verifico que la estatuilla no exista

        if( cantEstatuillasElegidas[ estatuillaElegida-1 ] > 0 )
        {
            estatuillaElegidaYaExiste = true;
        }


        //Si la opcion ingresada no es valida muestro un cartel
        if( estatuillaElegida > 5 || estatuillaElegida < 1 )
        {
            esperarEnter();
            cout << endl << "La opcion elegida es incorrecta, presione enter para volver a elegir. " << endl << endl;
            esperarEnter();
            estatuillaElegidaYaExiste = true;
        }


        //Si la estatuilla no esta elegida el jugador puede ganarla, sino vuelve al menu de estatuillas.
        if( !estatuillaElegidaYaExiste )
        {
            cout << endl << "Usted eligio la estatuilla: " << estatuillas[estatuillaElegida-1] << ". Escriba 'si' para continuar o 'no' para rechazar " << endl;
            cin >> usuarioElige;
            if( usuarioElige != "si" && usuarioElige != "Si" && usuarioElige != "SI" && usuarioElige != "S" && usuarioElige != "s")
            {
                cantEstatuillasElegidas[estatuillaElegida-1]++;
                esperarEnter();
                cout << "Para volver al menu de estatuillas presione enter." << endl;
                esperarEnter();
            }
        }else{
            cout << endl << endl << "Esa estatuilla ya fue ganada. Por favor presione ENTER para volver al menu de estatuillas para elegir otra. "<< endl;

            esperarEnter();
        }


    //Mientras el usuario haya ingresado una opcion invalida o la estatuilla ya este en juego vuelvo a repetir
    } while( estatuillaElegida > 5 || estatuillaElegida < 1 || estatuillaElegidaYaExiste );



    //Si esta todo bien retorno la estatuilla elegida
    return estatuillaElegida;
}



bool cumpleConRequisitosEstatuilla(int estatuilla, int dado1, int dado2, int dado3){

    bool cumple = false;

    if (dado3==0){
         switch(estatuilla){
            //1 dado par 1 dado impar
           case 1:
               if ((dado1 % 2 != 0 && dado2 % 2 == 0) || (dado1 % 2 == 0 && dado2 % 2 != 0)){
                   cumple = true;
               }
            break;

           //2 dados menores a 5
           case 2:
               if( dado1 < 5 && dado2 < 5)
               {
                   cumple = true;
               }
            break;

            //Suma de los dados == 7
           case 3:
               if( dado1 + dado2 == 7)
               {
                   cumple = true;
               }
               break;

           //dado con 1 y dado con 10
           case 4:
               if( dado1 == 1 && dado2 == 10 || dado1 == 10 && dado2 == 1)
               {
                   cumple = true;
               }
            break;



           //dados consecutivos
           case 5:
               if( dado1 == dado2+1 || dado2 == dado1+1 )
               {
                   cumple = true;
               }
            break;


         }
      }
      else {
         switch(estatuilla){
            //1 dado par 1 dado impar
           case 1:
               if (dado1 % 2 != 0 && dado2 % 2 == 0 || dado1 % 2 == 0 && dado2 % 2 != 0 || dado1 % 2 != 0 && dado3 % 2 == 0 || dado1 % 2 == 0 && dado3 % 2 != 0 || dado3 % 2 != 0 && dado2 % 2 == 0 || dado3 % 2 == 0 && dado2 % 2 != 0){
                   cumple = true;
               }
            break;

            //2 dados menores a 5
           case 2:
               if( dado1 < 5 && dado2 < 5 || dado1 < 5 && dado3 < 5 || dado3 < 5 && dado2 < 5 )
               {
                   cumple = true;
               }
            break;


          //Suma de los dados == 7
           case 3:
               if( dado1 + dado2 == 7 || dado1 + dado3 == 7 || dado3 + dado2 == 7)
               {
                   cumple = true;
               }
           break;

           //dado con 1 y dado con 10
           case 4:
               if( dado1 == 1 && dado2 == 10 || dado1 == 10 && dado2 == 1 || dado1 == 1 && dado3 == 10 || dado1 == 10 && dado3 == 1 || dado3 == 1 && dado2 == 10 || dado3 == 10 && dado2 == 1)
               {
                   cumple = true;
               }
            break;



           //dados consecutivos
           case 5:
               if( dado1 == dado2+1 || dado2 == dado1+1 || dado1 == dado3+1 || dado3 == dado1+1 || dado3 == dado2+1 || dado2 == dado3+1)
               {
                   cumple = true;
               }
            break;


         }
      }
    return cumple;
}
