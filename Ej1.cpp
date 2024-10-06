#include <iostream>
#include <string>
#include "Grafos/Grafo.h"

using namespace std;

void menu()
{
    cout << "***Menu de Red***" << endl;
    cout << "1.Agregar Persona" << endl;
    cout << "2.Agregar Amistad" << endl;
    cout << "3.Eliminar amistad" << endl;
    cout << "4.Buscar Persona" << endl;
    cout << "5 Eliminar Nodo" << endl;
    cout << "6 Buscar Amistad" << endl;
    cout << "7.Imprimir red" << endl;
    cout << "8.Salir" << endl;
}

void altaUsuario(Grafo<string> &g1)
{
    string nUsuario;
    do
    {
        try
        {
            cout << "Ingrese el nUsuarioero, para salir ingrese 1" << endl;
            getline(cin, nUsuario);
            if (nUsuario != "1")
            {
                g1.agregarNodo(nUsuario);
                cout << "Cargado con exito" << endl;
            }
        }
        catch (int e)
        {
            if (e == 200)
            {
                cout << "El elemento ya existe" << endl;
            }
        }

    } while (nUsuario != "1");
}

void agregarAmistad(Grafo<string> &g1)
{

    string usuario1, usuario2;
    cout << "Ingrese el nombre del usuario 1" << endl;
    getline(cin, usuario1);
    cout << "Ingrese el nombre del usuario 2" << endl;
    getline(cin, usuario2);

    try
    {
        g1.agregarArista(usuario1, usuario2);
        cout << "Amistad generada" << endl;
    }
    catch (int e)
    {
        cout << "Uno de los usuarios no es parte de la red social" << endl;
    }
}

void eliminarAmistad(Grafo<string> &g1)
{

    string usuario1, usuario2;
    cout << "Ingrese el nombre del usuario 1" << endl;
    getline(cin, usuario1);
    cout << "Ingrese el nombre del usuario 2" << endl;
    getline(cin, usuario2);

    try
    {
        g1.eliminarArista(usuario1, usuario2);
        cout << "Amistad Eliminda" << endl;
    }
    catch (int e)
    {
        cout << "Uno de los usuarios no es parte de la red social" << endl;
    }
}

void buscarUsuario(Grafo<string> &g1)
{

    string usuario;

    cout << "Ingrese el nombre del usuario" << endl;
    cin.ignore();
    getline(cin, usuario);

    try

    {
        g1.buscarNodo(usuario);
        cout << "Usuario encontrado" << endl;
    }
    catch (int e)
    {
        cout << "Usuario no encontrado" << endl;
    }
}

void bajaUsuario(Grafo<string> &g1)
{
    string baja;

    try
    {
        cout << "Ingrese el usuario para dar de baja" << endl;
        getline(cin, baja);
        g1.eliminarNodo(baja);
        cout << "Elemento eliminado" << endl;
    }
    catch (int e)
    {

        cout << "No se pudo eliminar el usuario" << endl;
    }
}

void buscarAmistades(Grafo<string> &g1)
{
    string usuario1, usuario2;
    cout << "Ingrese el nombre del usuario 1" << endl;
    getline(cin, usuario1);
    cout << "Ingrese el nombre del usuario 2" << endl;
    getline(cin, usuario2);

    if(g1.estanConectados(usuario1,usuario2)){
        cout<<"El usuario: "<<usuario1<<" es amigo de: "<<usuario2<<"."<<endl;
    }
    else
    {
        cout<<"Los usuarios no estan conectados"<<endl;
    }

}

int main()
{

    cout << "Ejercicio N° 2" << endl;

    Grafo<string> redSocial;
    int option;
    do
    {
        menu();
        cout << "Ingrese una opcion" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cin.ignore();
            altaUsuario(redSocial);
            break;
        case 2:
            cin.ignore();
            agregarAmistad(redSocial);
            break;
        case 3:
            cin.ignore();
            eliminarAmistad(redSocial);
            break;
        case 4:
            cin.ignore();
            buscarUsuario(redSocial);
            break;
        case 5:
            cin.ignore();
            bajaUsuario(redSocial);
            break;
        case 6:
            cin.ignore();
            buscarAmistades(redSocial);
            break;
        case 7:
            redSocial.imprimir();
            break;
        case 8:
            cout<<"Saliendo..."<<endl;
        default:
            cout << "Opcion incorrecta..." << endl;
            break;
        }
    } while (option != 8);

    return 0;
}
