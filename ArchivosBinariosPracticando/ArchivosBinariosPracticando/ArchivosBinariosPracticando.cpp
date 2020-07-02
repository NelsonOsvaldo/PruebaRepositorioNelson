/*

ESTA ES UNA SEGUNDA VERSION DE PRUEBA
*/

///////////// algun cambio al archivo para pruebas
#include <iostream>
#include <fstream>  // manejo de archivos
#include <string> // para disponer de la funcion strcpy ( arg1, arg2 );

using namespace std;

struct Struct_Estudiante { 
    int ID_Estudiante;
    char nombre[20];
    int edad;
};

// FUNCION PARA CARGAR EN EL STRUCT

Struct_Estudiante IngresarEstudiante() {
    Struct_Estudiante estudiante;
    string nombre;

    cout << "\n\tEscriba el numero de ID del estudiante: ";
    cin >> estudiante.ID_Estudiante;
    cout << endl;
    cin.ignore();

    cout << "\n\tEscriba el nombre del estudiante: ";
    getline(cin, nombre);
    strcpy_s(estudiante.nombre, nombre.c_str()); // strcpy_s en lugar de strcpy
    cout << endl;

    cout << "\n\tEscriba la edad del estudiante: ";
    cin >> estudiante.edad;
    cout << endl;
    cin.ignore();

    return estudiante;
}

int main()
{
    ofstream ArchivoEstudiantes; 
    ArchivoEstudiantes.open("MiArchivo.dat", ios::out | ios::binary);

    int continuar = 1;
    Struct_Estudiante UnEstudiante;

    while (continuar == 1){
        UnEstudiante = IngresarEstudiante();

        ArchivoEstudiantes.write((char*)&UnEstudiante, sizeof(Struct_Estudiante));

        cout << "\t0. Finalizar\n\t1. Ingresar otro estudiante";
        cin >> continuar; 

    }

    cout << endl;
    cout << "\tIngreso del archivo finalizado\n";
    ArchivoEstudiantes.close();
    return 0;
}


