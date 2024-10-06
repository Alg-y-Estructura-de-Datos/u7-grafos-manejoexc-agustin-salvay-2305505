#include <iostream>
#include <string>
#include "Grafos/Grafo.h"

using namespace std;

void menu()
{
    cout << "***Menu de Red universitaria***" << endl;
    cout << "1.Agregar Miembro" << endl;
    cout << "2.Agregar Colaboracion" << endl;
    cout << "3.Eliminar Colaboracion" << endl;
    cout << "4.Buscar miembro" << endl;
    cout << "5.Imprimir red universitaria" << endl;
    cout << "6.Salir" << endl;
}

void agregarMiembro(Grafo<string> &g1)
{
    string nUsuario;
    do
    {
        try
        {
            cout << "Ingrese la persona, para salir ingrese 1" << endl;
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

void agregarColaboracion(Grafo<string> &g1)
{

    string usuario1, usuario2;
    cout << "Ingrese el nombre de la persona 1 " << endl;
    getline(cin, usuario1);
    cout << "Ingrese el nombre de la persona 2" << endl;
    getline(cin, usuario2);

    try
    {
        g1.agregarArista(usuario1, usuario2);
        cout << "Amistad generada" << endl;
    }
    catch (int e)
    {
        cout << "Uno de las personas  no es parte de la red social" << endl;
    }
}

void eliminarColaboracion(Grafo<string> &g1)
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
        cout << "Uno de los usuarios no es parte de la red universitaria" << endl;
    }
}

void buscarMiembro(Grafo<string> &g1)
{

    string usuario;

    cout << "Ingrese el nombre de la persona" << endl;
    cin.ignore();
    getline(cin, usuario);

    try

    {
        g1.buscarNodo(usuario);
        cout << "persona encontrada" << endl;
    }
    catch (int e)
    {
        cout << "Usuario no encontrado" << endl;
    }
}



int main()
{

    cout << "Ejercicio N° 1" << endl;

    Grafo<string> redUniversitaria;
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
            agregarMiembro(redUniversitaria);
            break;
        case 2:
            cin.ignore();
            agregarColaboracion(redUniversitaria);
            break;
        case 3:
            cin.ignore();
            eliminarColaboracion(redUniversitaria);
            break;
        case 4:
            cin.ignore();
            buscarMiembro(redUniversitaria);
            break;
        case 5:
            redUniversitaria.imprimir();
            break;
        default:
            cout << "Saliendo..." << endl;
            break;
        }
    } while (option != 6);

    return 0;
}
