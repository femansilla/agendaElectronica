//#############################################################################
// ARCHIVO             : main.cpp
// AUTOR/ES            : nombre/s de autor/es
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : 31/08/2017.
// ULTIMA ACTUALIZACION: 31/08/2017.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//****************************************************************************
#ifndef MENUS_H
#define MENUS_H

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
// objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "MisFunciones.h"

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;
//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrarSubMenu3()
{
    cout <<"|-----------------SUBMENU 3-------------------|"<<endl;
    cout <<"| A-Modificacion                              |"<<endl;
    cout <<"| B-Volver                                    |"<<endl;
    cout <<"| C-Salir del programa                        |"<<endl;
    cout <<"|---------------------------------------------|"<<endl;
}

//===========================================================================
// FUNCION   : void subMenu3().
// ACCION    : Inicia el submenu3.
// PARAMETROS: NADA.
// DEVUELVE  : Si desea salir del programa o no.
//---------------------------------------------------------------------------
bool subMenu3()
{
    bool result = false;
    bool salir= false;//variable que controla el ciclo del menu
    char opcion;//variable que guarda la opcion seleccionada por el usuario
    while(!salir)
    {
        sys::cls();//Limpio la pantalla
        mostrarSubMenu3(); //Muestro el menu
        cout<< "Ingrese una opcion: "; //Solicitio al usuario que ingrese una opcion
        cin.get(opcion);//Guardo el ingreso del usuario
        cin.ignore();//Limpio el buffer de teclado
        switch(opcion)//Evaluo la variable opcion
        {
        case 'a':
        case 'A':
        {
            cout <<"La modificaicon se realizo correctamente!!!";
            cin.get();
        }
        break;
        case 'b':
        case 'B':
        {
            salir=true;
        }
        break;
        case 'c':
        case 'C':
        {
            result= true;//Para salir del programa
            salir=true;
        }
        break;

        default:
        {
            cout <<"Opcion no valida!!!";
            cin.get();
        }
        break;
        }

    }
    return result;
}
//===========================================================================
// FUNCION   : void mostrarSubMenu2().
// ACCION    : Muestra en pantalla el submenu 2.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrarSubMenu2()
{
    cout <<"|-----------------SUBMENU 2-------------------|"<<endl;
    cout <<"| A-Alta                                      |"<<endl;
    cout <<"| B-Volver                                    |"<<endl;
    cout <<"| C-Salir del programa                        |"<<endl;
    cout <<"|---------------------------------------------|"<<endl;
}

//===========================================================================
// FUNCION   : void subMenu2().
// ACCION    : Inicia el submenu2.
// PARAMETROS: NADA.
// DEVUELVE  : Si desea salir del programa o no.
//---------------------------------------------------------------------------
bool subMenu2()
{
    bool result = false;
    bool salir= false;//variable que controla el ciclo del menu
    char opcion;//variable que guarda la opcion seleccionada por el usuario
    while(!salir)
    {
        sys::cls();//Limpio la pantalla
        mostrarSubMenu2(); //Muestro el menu
        cout<< "Ingrese una opcion: "; //Solicitio al usuario que ingrese una opcion
        cin.get(opcion);//Guardo el ingreso del usuario
        cin.ignore();//Limpio el buffer de teclado
        switch(opcion)//Evaluo la variable opcion
        {
        case 'a':
        case 'A':
        {
            cout <<"Se dio de alta!!!";
            cin.get();
        }
        break;
        case 'b':
        case 'B':
        {
            salir=true;
        }
        break;
        case 'c':
        case 'C':
        {
            result= true;//Para salir del programa
            salir=true;
        }
        break;

        default:
        {
            cout <<"Opcion no valida!!!";
            cin.get();
        }
        break;
        }

    }
    return result;
}

//===========================================================================
// FUNCION   : void mostrarSubMenu1().
// ACCION    : Muestra en pantalla el submenu 1.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrarSubMenu1()
{
    cout <<"|-----------------SUBMENU 1-------------------|"<<endl;
    cout <<"| A-Ir a SubMenu3                             |"<<endl;
    cout <<"| B-Baja                                      |"<<endl;
    cout <<"| C-Volver                                    |"<<endl;
    cout <<"| D-Salir del programa                        |"<<endl;
    cout <<"|---------------------------------------------|"<<endl;
}

//===========================================================================
// FUNCION   : void subMenu1().
// ACCION    : Inicia el submenu1.
// PARAMETROS: NADA.
// DEVUELVE  : Si desea salir del programa o no.
//---------------------------------------------------------------------------
bool subMenu1()
{
    bool result = false;
    bool salir= false;//variable que controla el ciclo del menu
    char opcion;//variable que guarda la opcion seleccionada por el usuario
    while(!salir)
    {
        sys::cls();//Limpio la pantalla
        mostrarSubMenu1(); //Muestro el menu
        cout<< "Ingrese una opcion: "; //Solicitio al usuario que ingrese una opcion
        cin.get(opcion);//Guardo el ingreso del usuario
        cin.ignore();//Limpio el buffer de teclado
        switch(opcion)//Evaluo la variable opcion
        {
        case 'a':
        case 'A':
        {
            result=subMenu3();
            salir= result;
        }
        break;
        case 'b':
        case 'B':
        {
            cout <<"La baja se realizo correctamente!!!";
        }
        break;
        case 'c':
        case 'C':
        {
            salir=true;
        }
        break;
        case 'd':
        case 'D':
        {
            result= true;//Para salir del programa
            salir=true;
        }
        break;
        default:
        {
            cout <<"Opcion no valida!!!";
            cin.get();
        }
        break;
        }

    }
    return result;
}

//===========================================================================
// FUNCION   : void mostrarPrincipal().
// ACCION    : Muestra en pantalla el menu principal.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrarMenuPrincipal()
{
    cout <<"|---------------MENU PRINCIPAL----------------|"<<endl;
    cout <<"| I - C A R G A R                             |"<<endl;
    cout <<"| A - M O D I F I C A R                       |"<<endl;
    cout <<"| B - B U S C A R                             |"<<endl;
    cout <<"| A - M O S T R A R                           |"<<endl;
    cout <<"| S - S A L I R                               |"<<endl;
    cout <<"|---------------------------------------------|"<<endl;
}

//===========================================================================
// FUNCION   : void menuPrincipal().
// ACCION    : Inicia el menu principal.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void menuPrincipal(datContacto *d, telContacto *t)
{
    bool salir= false;
    char opcion;
    while(!salir)
    {
        sys::cls();
        mostrarMenuPrincipal();
        cout<< "Ingrese una opcion: ";
        cin.get(opcion);
        cin.ignore();
        switch(opcion)
        {
        case 'I':
        case 'i':
        {
            guardarDat(d);
        }
        break;
        case 'A':
        case 'a':
        {
            mostrarProducto(*d,*t);
        }
        break;
        case 'C':
        case 'c':
        {
            salir= subMenu2();
        }
        break;
        case 'S':
        case 's':
        {
            salir=true;
        }
        break;
        default:
        {
            cout <<"Opcion no valida!!!";
            cin.get();
        }
        break;
        }

    }
}

#endif // MENUS_H
