//#############################################################################
// ARCHIVO             : main.cpp
// AUTOR/ES            : nombre/s de autor/es
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : 31/08/2017.
// ULTIMA ACTUALIZACION: 31/08/2017.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//****************************************************************************
#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

using namespace std;

const char rutaDat[]= "Datos.data";
const char rutaTel[]= "Telefono.data";



struct datContacto // Los datos mínimos deberán organizarse en estructuras relacionadas:
//Contacto (nombre, apellido, domicilio, apodo, email.).
{
    int id;
    bool eliminado;
    char nombre[50];
    char apellido[50];
    char alias[50];
    char domicilio[50];
    char email[50];
};

struct telContacto // Teléfono (de línea, celular, otros).
{
    int id;
    int idContacto;
    bool eliminado;
    char tipo[50];
    int numero;
};

////===========================================================================
//// FUNCION   : void mostrarSubMenu3().
//// ACCION    : Muestra en pantalla el submenu 3.
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void cargarTelefono(telContacto *t, datContacto *d)
{
    cout<< "Ingrese el TIPO del numero: ";
    sys::getline(t->tipo,50);
    cout<< "Ingrese el NUMERO del contacto: ";
    t->idContacto=d->id;
    cin >> t->numero;
    cin.ignore();
    t->eliminado=false;
    sys::cls();
}




//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
bool guardarDat(datContacto d)
{
    bool result = false;
    FILE *arcDat;
    arcDat = fopen(rutaDat,"ab");
    if(arcDat!=NULL)
    {
        fwrite(&d,sizeof(datContacto),1,arcDat);
        fclose(arcDat);
        result=true;
    }
    return result;
}
//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void cargarContacto(datContacto *p,telContacto *t)
{
    cout<< "Ingrese el NOMBRE del contacto: ";
    sys::getline(p->nombre,50);
    cout<< "Ingrese el APELLIDO del contacto: ";
    sys::getline(p->apellido,50);
    cout<< "Ingrese el CORREO del contacto: ";
    sys::getline(p->email,50);
    cout<< "Ingrese el APODO del contacto: ";
    sys::getline(p->alias,50);
    p->eliminado=false;
    cargarTelefonos(p,t);
    sys::cls();
}
//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
bool guardarTel(telContacto t)
{
    bool result = false;
    FILE *arcTel;
    arcTel= fopen(rutaTel,"ab");
    if(arcTel!=NULL)
    {
        cargarContacto(d, t);
        fwrite(&t,sizeof(telContacto),1,arcTel);
        fclose(arcTel);
        result=true;
    }
    return result;
}

////===========================================================================
//// FUNCION   : void mostrarSubMenu3().
//// ACCION    : Muestra en pantalla el submenu 3.
//// PARAMETROS: NADA.
//// DEVUELVE  : NADA.
////---------------------------------------------------------------------------
void cargarTelefonos(datContacto *d, telContacto *t)
{
    char var[1];
    var[0]='\0';
    while(var[0]!='0')
    {
        if(t->id!= NULL)
        {
            cargarTelefono(t, d);
            if(guardarTel(*t))
            {
                cout << "Se guardo el telefono correctamente correctamente...";
                sys::msleep(1);
            }
        }
        cout << "\nPARA FINALIZAR LA CARGA DE TELEFONOS INGRECE 0 (CERO)..."<<endl;
        sys::getline(var,1);
    }


}








//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
mostrarTel(datContacto p, telContacto t)
{
    cout <<"*Telefono tipo: "<< t.tipo;
    cout <<" numero: "<< t.numero;
}

//===========================================================================
// FUNCION   : void mostrarSubMenu3().
// ACCION    : Muestra en pantalla el submenu 3.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//---------------------------------------------------------------------------
void mostrarProducto(datContacto p, telContacto t)
{
    cout <<"\n*-----------"<<p.id<<"----------"<<endl;
    cout <<"*Nombre  : "<<p.nombre<<endl;
    cout <<"*Apellido: "<<p.apellido<<endl;
    cout <<"*Correo  : "<<p.email<<endl;
    cout <<"*Apodo   : "<<p.alias<<endl;
    mostrarTel(p,t);
    cin.get();
}






#endif // MISFUNCIONES_H_INCLUDED
