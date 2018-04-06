//#############################################################################
// ARCHIVO             : main.cpp
// AUTOR/ES            : Mansilla Francisco
// VERSION             : 0.02 beta.
// FECHA DE CREACION   : 31/08/2017.
// ULTIMA ACTUALIZACION: 18/09/2017.
// LICENCIA            : GPL (General Public License) - Version 3.
//****************************************************************************
#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#include <cmath>

using namespace std;
//****************************************************************************
//****************************************************************************
//****************************************************************************

struct persona
{
    int id_persona;
    char nombre[50];
    char apellido[50];
    char alias[50];
    char domicilio[50];
    char email[50];
    bool eliminado;
};

struct telefono
{
    int id_telefono;
    int id_persona;
    char tipo[50];
    int numero;
    bool eliminado;
};

const char ruta_persona[]= "Datos.data";
const char ruta_per_encontradas[]= "Personas_Encontradas.data";
const char ruta_telefono[]= "Telefono.data";
int ID_per, ID_tel = 0;

persona *vec_per_encontradas;
void menuPrincipal();
void menu_eliminar_registro();
void menu_mod();
void menu_mod_datos();
void menu_mod_telefonos();
void menu_mod_contacto();
void menu_switch_mod_telefono();
void mostrar_contactos_eliminados();


//=============================================================================
// FUNCION   : bool esNumero(char* cadena)
// ACCION    : valida si la cadena ingresada es numero.
// PARAMETROS: char* cadena
// DEVUELVE  : TRUE si esta dentro del rango, FALSE si no lo cumple
//-----------------------------------------------------------------------------
bool esNumero(char* cadena)//* pasar por puntero porque es una cadena/vector.
{
    int i = 0;

    bool esNro = true;
    int n = strlen(cadena);
    while (cadena[i] != '\0' || strlen(cadena) < 1) //'\0' fin de cadena.
    {
        if(cadena[i] < 48 || cadena[i] > 57 || strlen(cadena) < 1)
            return false;

        i++;
    }
    return esNro;

}

//=============================================================================
// FUNCION : int strToInt (char* cadena)
// ACCION : convierte una cadena de caracteres a un número entero.
// PARAMETROS: cadena
// DEVUELVE : tipo --> int
//-----------------------------------------------------------------------------
int strToInt (char* cadena)
{
    int i = 0;
    int entero_pos = 0;
    int entero = 0;
    int cont = 0;

    bool esNumero = true;
    cont = strlen(cadena);

    while (cadena[i] != '\0')
    {
        if(cadena[i] < 48 || cadena[i] > 57)
            esNumero = false;

        i++;
    }

    if(esNumero)
    {
        i = 0;
        while(cadena[i] != '\0')
        {
            entero_pos = (cadena[i] - '0') * round(pow(10, cont - i - 1));
            entero += entero_pos;
            entero_pos = 0;
            i++;
        }
    }

    return entero;

}



////===========================================================================
//// FUNCION   : void  contar_ID().
//// ACCION    : Contador para ID_telefono y ID_persona.
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void contar_ID()
{
    FILE *arch_per;
    arch_per = fopen(ruta_persona,"ab");

    if(arch_per != NULL )
    {
        fseek(arch_per,0,SEEK_END);
        ID_per = ftell(arch_per) / sizeof(persona);
    }
    fclose(arch_per);

    if (ID_per == 0)
        ID_per = 1;
    else
        ID_per++;

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono,"ab");
    if(arch_tel != NULL )
    {
        fseek(arch_tel,0,SEEK_END);
        ID_tel = ftell(arch_tel) / sizeof(telefono);
    }

    fclose(arch_tel);

    if (ID_tel == 0)
        ID_tel = 1;
    else
        ID_tel++;

}

//===========================================================================
// FUNCION   : bool guardarTel(telefono tel).
// ACCION    : .
// PARAMETROS: telefono tel.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
bool guardarTel(telefono tel)
{
    bool result = false;
    FILE *arch_tel;
    arch_tel= fopen(ruta_telefono,"ab");
    if(arch_tel!=NULL)
    {
        fwrite(&tel,sizeof(telefono),1,arch_tel);
        fclose(arch_tel);
        result=true;
        ID_tel++;
    }
    return result;
}

////===========================================================================
//// FUNCION   : void cargarTelefono(persona per, telefono *tel).
//// ACCION    :
//// PARAMETROS: persona per, telefono *tel.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void cargarTelefono(persona per, telefono *tel)
{
    cout<< " Ingrese el TIPO del numero: ";
    sys::getline( tel->tipo, 50 );

    char cad_num[20];
    cout<< " Ingrese el NUMERO del contacto: ";
    sys::getline(cad_num,20);
    bool esNum = false;
    while(!esNum)
    {
        if(esNumero(cad_num))
        {
            tel->numero = strToInt(cad_num);
            esNum = true;
        }
        if(!esNum)
        {
            cout<< " EL NUMERO QUE INGRESO NO ES VALIDO..."<<endl;
            cout << " INGRESE NUEVAMENTE...";
            sys::msleep(1);
            sys::cls();
            cout<< " Ingrese el NUMERO del contacto: ";
            sys::getline(cad_num,20);
        }
    }

    tel->id_persona = per.id_persona;

    tel->id_telefono = ID_tel;

    tel->eliminado = false;

    sys::cls();
}

////===========================================================================
//// FUNCION   : void cargarTelefonos(persona per).
//// ACCION    :
//// PARAMETROS: persona per.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void cargarTelefonos(persona per)
{
    char opc[1];
    telefono tel;
    do
    {
        cout<< "\nPARA CARGAR UN NUEMRO AL CONTACTO INGRESE A...\n";
        sys::getline(opc,1);
        if(opc[0] == 'a' || opc[0] == 'A')
        {
            if(tel.id_telefono != NULL)
            {
                cargarTelefono(per, &tel);
                if(guardarTel(tel))
                {
                    cout << "SE GUARDO EL TELEFONO CORRECTAMENTE...";
                    sys::msleep(1);
                }

            }
            cout << "\nPARA FINALIZAR LA CARGA DE TELEFONOS INGRECE 0 (CERO)"<<endl;
            sys::getline(opc,1);
        }
        else
            break;

    }
    while(opc[0]!= '0');

}

//===========================================================================
// FUNCION   : bool guardar_persona(persona per).
// ACCION    : .
// PARAMETROS: persona per.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
bool guardar_persona(persona per)
{
    bool result = false;
    FILE *arch_per;

    arch_per = fopen(ruta_persona,"ab");

    if(arch_per != NULL)
    {
        fwrite(&per, sizeof(persona), 1, arch_per);
        fclose(arch_per);

        cout << "\nSE GUARDO LA PERSONA CORRECTAMENTE..." << endl;
        result = true;
        ID_per ++;
    }

    return result;
}

//===========================================================================
// FUNCION   : void datos_persona(persona *per).
// ACCION    : .
// PARAMETROS: persona per.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void datos_persona(persona *per)
{
    cout<< " Ingrese el NOMBRE del contacto: ";
    sys::getline(per->nombre, 50);

    cout<< " Ingrese el APELLIDO del contacto: ";
    sys::getline(per->apellido, 50);

    cout<< " Ingrese el APODO del contacto: ";
    sys::getline(per->alias, 50);

    cout<< " Ingrese el DOMICILIO del contacto: ";
    sys::getline(per->domicilio, 50);

    cout<< " Ingrese el CORREO del contacto: ";
    sys::getline(per->email, 50);

    per->eliminado=false;

    per->id_persona = ID_per;

}

////===========================================================================
//// FUNCION   : void cargar_persona().
//// ACCION    : Cargar una persona y telefonos (si se desean)
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void cargar_persona()
{
    sys::cls();
    persona per;
    datos_persona(&per);

    guardar_persona(per);

    cargarTelefonos(per);

    sys::cls();
}

////===========================================================================
//// FUNCION   : void mostrar_contactos().
//// ACCION    :
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void mostrar_contactos()
{
    persona per;
    telefono tel;

    FILE *arch_per;
    arch_per = fopen(ruta_persona,"rb");

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono,"rb");

    int cont = 0;
    sys::cls();

    if(arch_per != NULL)
    {
        while( fread(&per, sizeof(persona), 1, arch_per))
        {
            if(!per.eliminado)
            {
                cout<< " ==================================="<<endl;
                cout<< "           ID CONTACTO: "<< per.id_persona << endl;
                cout<< " ==================================="<<endl;
                cout<< " NOMBRE  : " << per.nombre << endl;
                cout<< " APELLIDO: " << per.apellido << endl;
                cout<< " CORREO  : " << per.email << endl;
                cout<< " APODO   : " << per.alias << endl;

                fseek(arch_tel, sizeof(telefono), SEEK_SET);
                fseek(arch_tel,-sizeof(tel),1);

                if(arch_tel != NULL)
                {
                    while(fread(&tel, sizeof(telefono), 1, arch_tel))
                    {
                        if (!tel.eliminado)
                        {
                            if(per.id_persona == tel.id_persona)
                            {
                                cout<< " -----------------------------------"<<endl;
                                cout<< " ID TELEFONO: "<< tel.id_telefono << endl;
                                cout<< " -----------------------------------"<<endl;
                                cout<< " TELEFONO TIPO: " << tel.tipo << endl;
                                cout<< " NUMERO       : " << tel.numero << endl;
                            }
                        }

                    }

                }
                cout<< " ==================================="<<endl<<endl;

                cont ++;

                if(cont == 5)
                {
                    cin.get();
                    sys::cls();
                    cont = 0;
                }
            }
        }
    }

    fclose(arch_tel);
    fclose(arch_per);
    cin.get();
}

////===========================================================================
//// FUNCION   : void mostrar_contacto().
//// ACCION    :
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void mostrar_contacto(persona per)
{
    telefono tel;

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono, "rb");

    cout<< " ==================================="<<endl;
    cout<< "           ID CONTACTO: "<< per.id_persona << endl;
    cout<< " ==================================="<<endl;
    cout<< " NOMBRE  : " << per.nombre << endl;
    cout<< " APELLIDO: " << per.apellido << endl;
    cout<< " CORREO  : " << per.email << endl;
    cout<< " APODO   : " << per.alias << endl;

    if(arch_tel != NULL)
    {
        while(fread(&tel, sizeof(telefono), 1, arch_tel))
        {
            if(per.id_persona == tel.id_persona &&
                    !tel.eliminado)
            {
                cout<< " -----------------------------------"<<endl;
                cout<< " ID TELEFONO: "<< tel.id_telefono << endl;
                cout<< " -----------------------------------"<<endl;
                cout<< " TELEFONO TIPO: " << tel.tipo << endl;
                cout<< " NUMERO       : " << tel.numero << endl;
            }

        }
    }

    cout<< " ==================================="<<endl;

    fclose(arch_tel);
}

//=============================================================================
// FUNCION : bool esMinuscula(char caracter)
// ACCION : averigua si el caracter ya es minuscula o no
// PARAMETROS: caracter
// DEVUELVE : tipo --> bool
//-----------------------------------------------------------------------------
bool esMinuscula (char caracter)
{
    int ascii = caracter;

    if(ascii > 93 &&
            ascii < 123)
    {
        return true;
    }
    else
        return false;
}

//=============================================================================
// FUNCION : void strToUpper(char * cadena)
// ACCION : convierte una cadena a mayúsculas.
// PARAMETROS: cadena
// DEVUELVE : tipo --> void
//-----------------------------------------------------------------------------
void strToUpper(char * cadena)
{
    int i = 0;
    int ascii = 0;

    while(cadena[i] != '\0')
    {
        if(esMinuscula(cadena[i]))
        {
            ascii = cadena[i] - 32;
            cadena[i] = ascii;
            ascii = 0;
        }

        i++;
    }
}

////===========================================================================
//// FUNCION   : int buscar_subcadena(char* persona_nombre, char* subcadena).
//// ACCION    :
//// PARAMETROS:
//// DEVUELVE  : -1 si no encuentra la subcadena
////---------------------------------------------------------------------------
int buscar_subcadena(char* persona_nombre, char* subcadena)
{
    int i = 0;
    int j = 0;
    int retorno = 0;

    char per_nombre[50], sub_cadena[50];

    strcpy(per_nombre, persona_nombre);
    strcpy(sub_cadena, subcadena);

    strToUpper(per_nombre);
    strToUpper(sub_cadena);

    while (per_nombre[i] != '\0')
    {
        if(per_nombre[i] == sub_cadena[j])
        {
            if ( retorno == -1 )
                retorno = i;

            j++;
        }
        else
        {
            if(sub_cadena[j] != '\0')
            {
                retorno = -1;
                j = 0;
            }
        }

        i++;
    }

    if (per_nombre[i] == '\0' && sub_cadena[j] != '\0')
        retorno = -1;

    return retorno;
}

//===========================================================================
// FUNCION   : void mostrar_opcion_busqueda(int opc).
// ACCION    : Muestra en pantalla el submenu 1.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrar_opcion_busqueda(int opc)
{
    switch (opc)
    {
    case 1:
    {
        cout<<"Ingrese Apellido:  ";
    }
    break;

    case 2:
    {
        cout<<"Ingrese Nombre:  ";
    }
    break;

    case 3:
    {
        cout<<"Ingrese Alias:  ";
    }
    break;

    }
}

////===========================================================================
//// FUNCION   :bool buscar(int opc).
//// ACCION    : busca de forma generica un contacto por Apellido,Nombre o Alias
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
bool buscar(int opc)
{
    FILE *arch_per = fopen(ruta_persona, "rb+" );
    persona per;
    char sub_cadena[30];
    bool retorno = false;
    int encontrado = 0;
    FILE *arch_per_encotradas = fopen(ruta_per_encontradas, "wb" );

    mostrar_opcion_busqueda(opc);
    sys::getline(sub_cadena, 30);
    sys::cls();


    while(fread(&per, sizeof(persona),1,arch_per))
    {
        if(per.eliminado != true)
        {
            encontrado = 0;

            switch (opc)
            {
            case 1:
            {
                if ( buscar_subcadena(per.apellido, sub_cadena ) != -1 )
                {
                    mostrar_contacto(per);
                    retorno = true;
                    encontrado = 1;
                }
            }
            break;

            case 2:
            {
                if ( buscar_subcadena(per.nombre, sub_cadena ) != -1 )
                {
                    mostrar_contacto(per);
                    retorno = true;
                    encontrado = 1;
                }
            }
            break;

            case 3:
            {
                if ( buscar_subcadena(per.alias, sub_cadena ) != -1 )
                {
                    mostrar_contacto(per);
                    retorno = true;
                    encontrado = 1;
                }
            }
            break;

            default:
            {

            } break;
            }

            if (encontrado  == 1)
                fwrite(&per, sizeof(per), 1, arch_per_encotradas);
        }

    }

    cin.get();

    fclose(arch_per);
    fclose(arch_per_encotradas);

    return retorno;
}

////===========================================================================
//// FUNCION   : void modificar_dato_persona(int opc, int id_persona, char* nuevo_dato).
//// ACCION    : Dependiendo de la opc recivida, modifica el contacto o lo elimina
//// PARAMETROS: opc, ed_persona, nuevo_dato.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void modificar_dato_persona(int opc, int id_persona, char* nuevo_dato)
{
    persona per;
    FILE *arch_per = fopen(ruta_persona, "rb+" );

    while(fread(&per, sizeof(persona),1,arch_per) )
    {
        if ( id_persona == per.id_persona &&
                per.eliminado == false )
        {
            if (opc == 1 )
                strcpy(per.apellido, nuevo_dato);

            if (opc == 2 )
                strcpy(per.nombre, nuevo_dato);

            if (opc == 3 )
                strcpy(per.alias, nuevo_dato);

            if (opc == 4 )
                strcpy(per.email, nuevo_dato);

            if(opc == 5)
                per.eliminado = true;

            fseek(arch_per,-sizeof(per),1);
            fwrite(&per, sizeof(persona),1,arch_per);

            if (opc == 5)
                cout<<"Contacto Eliminado"<<endl;
            else
                cout<<"Contacto Modificado"<<endl;

            sys::msleep(2);
            break;
        }
    }

    fclose(arch_per);
    cin.get();
}

////===========================================================================
//// FUNCION   : void eliminar_telefono().
//// ACCION    : Editar dato de telefono o eliminado
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void editar_telefono(persona per, int id_telefono, int opcion, int nuevo_numero, char* nuevo_tipo)
{
    telefono tel;
    bool modificado = false;

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono, "rb+");

    if(arch_tel != NULL)
    {
        while(fread(&tel, sizeof(telefono), 1, arch_tel))
        {
            if(opcion == 4)
            {
                if( tel.id_persona == per.id_persona &&
                        id_telefono == tel.id_telefono &&
                        tel.eliminado)
                {
                    tel.eliminado = false; //TODO: revisar
                    cout<< "Telefono Recuperado"<<endl;
                    modificado = true;
                }
            }

            else
            {
                if( tel.id_persona == per.id_persona &&
                        id_telefono == tel.id_telefono &&
                        !tel.eliminado )
                {
                    if(opcion == 1)
                    {
                        tel.eliminado = true;
                        cout<< "Telefono Eliminado"<<endl;
                    }

                    if(opcion == 2)
                    {
                        strcpy(tel.tipo, nuevo_tipo);
                        cout<< "Tipo de telefono Modificado"<<endl;
                    }

                    if(opcion == 3)
                    {
                        tel.numero = nuevo_numero;
                        cout<< "Numero de telefono Modificado"<<endl;
                    }

                    modificado = true;
                }
            }

            if(modificado == true)
            {


                fseek(arch_tel, -sizeof(tel), 1);
                fwrite(&tel, sizeof(telefono), 1, arch_tel);



                sys::msleep(2);

                break;
            }
        }

        if(modificado != true)
            cout<<"El ID de telefono no pertenece a este contacto o no existe"<<endl;
    }


    fclose(arch_tel);

    cin.get();
}

////===========================================================================
//// FUNCION   : void modificar_contacto().
//// ACCION    : Eliminado logico de un contacto
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void modificar_contacto(persona per)
{
    int opci;
    bool salir = false;
    char nuevo_dato[50];

    sys::cls();

    mostrar_contacto(per);
    cout<<endl<<endl;

    while (!salir)
    {
        menu_mod_contacto();

        cin>>opci;
        cin.ignore();

        switch(opci)
        {
        case 1:
        {
            cout<<"Ingrese el nuevo Apellido  : ";
            sys::getline(nuevo_dato, 50);
            modificar_dato_persona(1, per.id_persona, nuevo_dato);
        }
        break;

        case 2:
        {
            cout<<"Ingrese el nuevo Nombre  : ";
            sys::getline(nuevo_dato, 50);
            modificar_dato_persona(2, per.id_persona, nuevo_dato);
        }
        break;

        case 3:
        {
            cout<<"Ingrese el nuevo Alias  : ";
            sys::getline(nuevo_dato, 50);
            modificar_dato_persona(3, per.id_persona, nuevo_dato);
        }
        break;

        case 4:
        {
            cout<<"Ingrese el nuevo Correo  : ";
            sys::getline(nuevo_dato, 50);
            modificar_dato_persona(4, per.id_persona, nuevo_dato);
        }
        break;

        case 0:
        {
            salir = true;
        }
        break;

        default:
        {
            cout<<"Opcion incorrecta"<<endl;
        }
        break;
        }
    }
}

////===========================================================================
//// FUNCION   : void eliminar_telefono(int id_telefono).
//// ACCION    : Eliminado logico de un telefono
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void eliminar_telefono(int id_telefono)
{
    telefono tel;

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono, "rb+");

    if(arch_tel != NULL)
    {
        while(fread(&tel, sizeof(telefono), 1, arch_tel))
        {
            if(id_telefono == tel.id_telefono)
            {
                tel.eliminado = true;

                fseek(arch_tel, -sizeof(tel), 1);
                fwrite(&tel, sizeof(telefono), 1, arch_tel);

                cout<< "TELEFONO ELIMINADO" << endl;
                sys::msleep(2);

                break;
            }
        }

        if(tel.eliminado != true)
            cout<<"INGRESASTE UN ID INVALIDO..."<<endl;

    }

    fclose(arch_tel);

    cin.get();
}

////===========================================================================
//// FUNCION   : void modificar_contacto().
//// ACCION    : Agregar telefonos,
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void modificar_lista_contactos(persona per, int id_telefono)
{
    int opc, numero;
    char tipo[50];
    bool salir = false;

    while(!salir)
    {
        menu_switch_mod_telefono();
        cin>>opc;

        switch(opc)
        {
        case 1:
        {
            cout<<"Ingrese el nuevo Tipo"<<endl;
            sys::getline(tipo, 50);
            editar_telefono(per, id_telefono, 2, 0, tipo);
            salir = true;
        }
        break;

        case 2:
        {
            cout<<"Ingrese el nuevo Telefono"<<endl;
            cin>>numero;
            editar_telefono(per, id_telefono, 3, numero, "tipo");

            salir = true;
        }
        break;

        case 0:
        {
            salir = true;

        }
        break;
        default:
        {
            cout<<"Opcion Incorrecta.."<<endl;
            sys::msleep(2);
        }
        break;
        }
    }
}

////===========================================================================
//// FUNCION   : void modificar_telefono().
//// ACCION    : Agregar telefonos, o modificar lo que ya tiene una persona
//// PARAMETROS: persona.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void modificar_telefono(persona per)
{
    int id_telefono, opci;
    bool salir = false;

    sys::cls();

    mostrar_contacto(per);
    cout<<endl<<endl;

    while (!salir)
    {
        menu_mod_telefonos();
        cin>>opci;
        cin.ignore();

        switch(opci)
        {
        case 1:
        {
            cargarTelefonos(per);
        }
        break;

        case 2:
        {
            cout<<"Ingrese el ID del telefono a modificar"<<endl;
            cin>>id_telefono;
            modificar_lista_contactos(per, id_telefono);
            salir = true;

            }break;

            case 3:
            {
                mostrar_contactos_eliminados();
                salir = true;

            }break;

            case 0:
            {
                salir = true;

            }break;

        default:
        {
            cout<<"Opcion incorrecta"<<endl;
            sys::msleep(2);
        }
        break;
        }
    }
}

////===========================================================================
//// FUNCION   : void modificar_registro().
//// ACCION    : principal a la entrada de modificar un contacto o sus telefonos
//// PARAMETROS: persona.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void modificar_registro(persona per)
{
    int id_telefono, opci;
    bool salir = false;

    while (!salir)
    {

        menu_mod();
        cin>>opci;
        cin.ignore();




        switch(opci)
        {
        case 1:
        {
            modificar_contacto(per);
        }
        break;

        case 2:
        {
            modificar_telefono(per);
        }
        break;

        case 0:
        {
            salir = true;
        }
        break;

        default:
        {
            cout<<"Opcion incorrecta"<<endl;
            sys::msleep(2);
            cin>>opci;
            cin.ignore();
        }
        }
    }

}

////===========================================================================
//// FUNCION   : void eliminar_registro(persona per).
//// ACCION    : Agregar telefonos,
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void eliminar_registro(persona per)
{
    int id_telefono, opci;
    bool salir = false;


    sys::cls();

    mostrar_contacto(per);
    cout<<endl<<endl;

    while (!salir)
    {
        menu_eliminar_registro();

        cin>>opci;
        cin.ignore();

        switch(opci)
        {
        case 1:
        {


            modificar_dato_persona(5, per.id_persona, "A");
            salir = true;
        }
        break;

        case 2:
        {
            cout<<"Ingrese el ID de telefono a eliminar \n (cero para salir)"<<endl;
            cin>>id_telefono;
            cin.ignore();
            if(id_telefono != 0)
                editar_telefono(per, id_telefono,1, 0, "A");

            salir = true;

        }
        break;

        case 0:
        {
            salir = true;

        }
        break;

        default:
        {
            cout<<"Opcion incorrecta"<<endl;
            sys::msleep(2);

        }
        break;
        }
    }
}

////===========================================================================
//// FUNCION   : void preguntar_id().
//// ACCION    : busca sobre los contactos guardados a partir de la funcion generica void buscar()
//// PARAMETROS: opc(eliminar o modificar).
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void preguntar_id( int opc )
{
    FILE *arch_per_encotradas = fopen(ruta_per_encontradas, "rb" );
    persona per;
    int id_contacto;
    int encontrar = 2;


    cout<< "Ingrese el ID dentro de la lista resultado (cero para volver al menu anterior)"<<endl;
    cin>> id_contacto;
    cin.ignore();

    while (encontrar == 2 && id_contacto != 0)
    {
        while(fread (&per, sizeof(persona), 1, arch_per_encotradas)
                && (id_contacto == per.id_persona))
        {
            sys::cls();
            mostrar_contacto(per);

            cin.get();

            if (opc == 3)
                eliminar_registro(per);
            else
                modificar_registro(per);

            encontrar = 1;

            break;
        }

        if( encontrar == 2)
        {
            sys::cls();
            cout<< "El ID ingresado no esta en la lista de encontrados:  "<<endl<<endl;
            cout<< "Ingrese el ID dentro de la lista resultado  (cero para volver al menu anterior)"<<endl;
            cin>> id_contacto;
            cin.ignore();



        }
    }

    fclose(arch_per_encotradas);

}

////===========================================================================
//// FUNCION   : void mostrar_contactos_eliminados().
//// ACCION    :
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void recuperar_contacto(int id_contacto)
{
    FILE *arch_per = fopen(ruta_persona, "rb+");
    persona per;
    bool modificado = false;

    if(arch_per != NULL)
    {
        while(fread(&per, sizeof(persona), 1, arch_per))
        {
            if(per.id_persona == id_contacto &&
                    per.eliminado == true)
            {
                per.eliminado = false;
                modificado = true;
            }

            if(modificado == true)
            {
                fseek(arch_per,-sizeof(per),1);
                fwrite(&per, sizeof(persona),1,arch_per);
                sys::cls();
                cout<<"Contacto recuperado:   "<<endl<<endl;
                mostrar_contacto(per);
                break;
            }

        }

        if(modificado == false)
        {
            cout<<"EL CONTACTO INGRESADO NO HA SIDO ELIMINADO O NO EXISTE"<<endl;
            sys::msleep(2);
        }
    }

}

////===========================================================================
//// FUNCION   : void mostrar_contactos_eliminados().
//// ACCION    :
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void mostrar_contactos_eliminados()
{
    persona per;
    telefono tel;
    int id_contacto;

    FILE *arch_per;
    arch_per = fopen(ruta_persona,"rb");

    FILE *arch_tel;
    arch_tel = fopen(ruta_telefono,"rb");

    int cont = 0;
    sys::cls();

    if(arch_per != NULL)
    {
        while( fread(&per, sizeof(persona), 1, arch_per))
        {
            if(per.eliminado != false)
            {
                cout<< " ==================================="<<endl;
                cout<< "           ID CONTACTO: "<< per.id_persona << endl;
                cout<< " ==================================="<<endl;
                cout<< " NOMBRE  : " << per.nombre << endl;
                cout<< " APELLIDO: " << per.apellido << endl;
                cout<< " CORREO  : " << per.email << endl;
                cout<< " APODO   : " << per.alias << endl;

                fseek(arch_tel, sizeof(telefono), SEEK_SET);
                fseek(arch_tel,-sizeof(tel),1);

                if(arch_tel != NULL)
                {
                    while(fread(&tel, sizeof(telefono), 1, arch_tel))
                    {
                        if (tel.eliminado == false)
                        {
                            if(per.id_persona == tel.id_persona)
                            {
                                cout<< " -----------------------------------"<<endl;
                                cout<< " ID TELEFONO: "<< tel.id_telefono << endl;
                                cout<< " -----------------------------------"<<endl;
                                cout<< " TELEFONO TIPO: " << tel.tipo << endl;
                                cout<< " NUMERO       : " << tel.numero << endl;
                            }
                        }

                    }

                }
                cout<< " ==================================="<<endl<<endl;
                cont ++;
            }
        }
    }

    fclose(arch_tel);
    fclose(arch_per);

    if(cont == 0)
        cout<<"NO HAY CONTACTOS ELIMINADOS"<<endl;
    else
    {
        cout<<"INGRESE EL ID DEL CONTACTO A RECUPERAR"<<endl;
        cin>>id_contacto;
        cin.ignore();

        recuperar_contacto(id_contacto);
    }


    cin.get();
}

////===========================================================================
//// FUNCION   : void buscar_eliminados().
//// ACCION    : busca de forma generica un contacto por Apellido,Nombre o Alias
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
//bool buscar_eliminados( int opc)
//{
//    FILE *arch_per = fopen(ruta_persona, "rb+" );
//    persona per;
//    char sub_cadena[30];
//    bool retorno = false;
//    int encontrado = 0;
//    FILE *arch_per_encotradas = fopen(ruta_per_encontradas, "wb" );
//
//    mostrar_opcion_busqueda(opc);
//    sys::getline(sub_cadena, 30);
//
//
//    while(fread(&per, sizeof(persona),1,arch_per))
//    {
//        if(per.eliminado != true)
//        {
//            encontrado = 0;
//
//            switch (opc)
//            {
//                case 1:
//                {
//                    if ( buscar_subcadena(per.apellido, sub_cadena ) != -1 )
//                    {
//                        mostrar_contacto(per);
//                        retorno = true;
//                        encontrado = 1;
//                    }
//                }break;
//
//                case 2:
//                {
//                    if ( buscar_subcadena(per.nombre, sub_cadena ) != -1 )
//                    {
//                        mostrar_contacto(per);
//                        retorno = true;
//                        encontrado = 1;
//                    }
//                }break;
//
//                case 3:
//                {
//                    if ( buscar_subcadena(per.alias, sub_cadena ) != -1 )
//                    {
//                        mostrar_contacto(per);
//                        retorno = true;
//                        encontrado = 1;
//                    }
//                }break;
//
//                default:
//                {
//
//                }break;
//            }
//
//            if (encontrado  == 1)
//                fwrite(&per, sizeof(per), 1, arch_per_encotradas);
//        }
//
//    }
//
//    cin.get();
//    fclose(arch_per);
//    fclose(arch_per_encotradas);
//
//    return retorno;
//}


#endif // MISFUNCIONES_H_INCLUDED
