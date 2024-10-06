#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;

void menu()
{
    cout << "****MENU****" << endl;
    cout << "1.Agregar Estacion." << endl;
    cout << "2.Conectar Estacion." << endl;
    cout << "3.Eliminar Estacion." << endl;
    cout << "4.Eliminar Ruta." << endl;
    cout << "5.Consultar Conectividad." << endl;
    cout << "6.Buscar Estacion." << endl;
    cout << "7.Estaciones conecradas a una." << endl;
    cout << "8.Imprimir Mapa." << endl;
    cout << "9.Salir" << endl;
}

void agregarEstacion(Grafo<string> &estaciones)
{

    string nEstacion;

    cout << "Ingrese el nombre de la nueva estacion" << endl;
    getline(cin, nEstacion);

    try
    {
        estaciones.agregarNodo(nEstacion);
        cout << "Estacion agregada con exito" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "la estacion ya existe" << endl;
    }
}

void conectarEstacion(Grafo<string> &estaciones)
{

    string nEstacion1, nEstacion2;

    cout << "Ingrese el nombre de la estacion 1 " << endl;
    getline(cin, nEstacion1);
    cout << "Ingrese el nombre de la estacion 2" << endl;
    getline(cin, nEstacion2);
    try
    {
        estaciones.agregarArista(nEstacion1, nEstacion2);
        cout << "Estaciones conectadas" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Una o ambas estaciones no existen" << endl;
    }
}

void eliminarEstacion(Grafo<string> &estaciones)
{

    string nEstacion;

    cout << "Ingrese el nombre de la estacion que desea eliminar" << endl;
    getline(cin, nEstacion);

    try
    {
        estaciones.eliminarNodo(nEstacion);
        cout << "Estacion eliminada con existo" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "La estacion no se pudo eliminar" << endl;
    }
}

void eliminarConexion(Grafo<string> &estaciones)
{

    string nEstacion1, nEstacion2;

    cout << "Ingrese el nombre de la estacion 1 " << endl;
    getline(cin, nEstacion1);
    cout << "Ingrese el nombre de la estacion 2" << endl;
    getline(cin, nEstacion2);
    try
    {
        estaciones.eliminarArista(nEstacion1, nEstacion2);
        cout << "Conexion eliminada" << endl;
    }
    catch (const std::exception &e)
    {
        cout << "Una o ambas estaciones no existen" << endl;
    }
}

void consultarConectividad(Grafo<string> &estaciones)
{

    string nEstacion1, nEstacion2;

    cout << "Ingrese el nombre de la estacion 1 " << endl;
    getline(cin, nEstacion1);
    cout << "Ingrese el nombre de la estacion 2" << endl;
    getline(cin, nEstacion2);

    if (estaciones.estanConectados(nEstacion1, nEstacion2))
    {
        cout << "Estaciones conectadas" << endl;
    }
    else
    {
        cout << "Las estaciones no estan conectadas" << endl;
    }
}

void buscarEstacion(Grafo<string> &estaciones)
{

    string nEstacion;

    cout << "Ingrese el nombre de la estacion que quiere buscar" << endl;
    getline(cin, nEstacion);

    try
    {
        estaciones.buscarNodo(nEstacion);
        cout << "Estacion encontrada" << endl;
    }
    catch (int e)
    {
        cout << "La estacion no existe" << endl;
    }
}

/*void conexionesEstacion(Grafo<string> &estaciones)
{

    string nEstacion;

    cout << "Ingrese el nombre de la estacion" << endl;
    getline(cin, nEstacion);

    try
    {
        estaciones.agregarNodo(nEstacion);
        cout << "Estacion agregada con exito" << endl;
    }
    catch (int e)
    {
        cout << "La estacion ya existe" << endl;
    }
}*/

int main()
{

    cout << "Ejercicio N° 3" << endl;

    Grafo<string> estaciones;
    int option;

    do
    {
        menu();
        cout << "Ingrese una opcion" << endl;
        cin >> option;
        cout << " " << endl;

        switch (option)
        {
        case 1:
            cin.ignore();
            agregarEstacion(estaciones);
            break;
        case 2:
            cin.ignore();
            conectarEstacion(estaciones);
            break;
        case 3:
            cin.ignore();
            eliminarEstacion(estaciones);
            break;
        case 4:
            cin.ignore();
            eliminarConexion(estaciones);
            break;
        case 5:
            cin.ignore();
            consultarConectividad(estaciones);
            break;
        case 6:
            cin.ignore();
            buscarEstacion(estaciones);
            break;
        case 7:
            cin.ignore();
            break;
        case 8:
            estaciones.imprimir();
            break;
        case 9:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    } while (option != 9);

    return 0;
}
