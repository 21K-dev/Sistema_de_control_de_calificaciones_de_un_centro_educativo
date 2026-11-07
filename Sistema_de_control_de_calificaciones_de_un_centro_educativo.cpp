/*
Sistema_de_control_de_calificaciones_de_un_centro_educativo.cpp

Descripción: Programa de consola para registrar calificaciones de estudiantes mediante bucles, validando los datos, calculando promedios y generando un resumen final del grupo.
Valores de entrada: Cantidad de estudiantes (numero entero), nombre (texto), 4 calificaciones (numeros decimales), opcion para repetir (letra).
Proceso: El proceso engloba bucles anidados para iterar sobre la cantidad de estudiantes y sus calificaciones. Se validan los rangos permitidos, se opera la suma para los promedios, se decide el estado condicionalmente (>= 70) y se acumulan los contadores para el resumen general.
Valores de salida: Promedio individual con estado de aprobacion, totales de aprobados/reprobados, promedio general y el estudiante con la nota mas alta.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    char repetirPrograma;
    cout << fixed << setprecision(2);
    do {
    
        int cantidadEstudiantes = 0;
        int aprobados = 0;
        int reprobados = 0;
        double sumaPromediosGrupo = 0.0;
        double mejorPromedio = -1.0;
        string mejorEstudiante = "";
    
        while (cantidadEstudiantes <= 0) {
            cout << "Cantidad de estudiantes: ";
            cin >> cantidadEstudiantes;
        }
    
        int i = 1;
        while (i <= cantidadEstudiantes) {
            string nombre;
            double sumaNotas = 0.0;

            cout << "Estudiante " << i << endl;
            cout << "Nombre: ";
            cin >> nombre;
    
            int j = 1;
            while (j <= 4) {
                double calificacion = -1.0;
   
                while (calificacion < 0 || calificacion > 100) {
                    cout << "Calificacion " << j << ": ";
                    cin >> calificacion;
                }

                sumaNotas = sumaNotas + calificacion;
                j = j + 1;
            }

            double promedio = sumaNotas / 4.0;
            sumaPromediosGrupo = sumaPromediosGrupo + promedio;

            if (promedio >= 70) {
                cout << "Promedio: " << promedio << " - Aprobado" << endl;
                aprobados = aprobados + 1;
            }
            else {
                cout << "Promedio: " << promedio << " - Reprobado" << endl;
                reprobados = reprobados + 1;
            }

   
            if (promedio > mejorPromedio) {
                mejorPromedio = promedio;
                mejorEstudiante = nombre;
            }

            i = i + 1;
        }

        double promedioGeneral = sumaPromediosGrupo / cantidadEstudiantes;

        cout << "===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << promedioGeneral << endl;
        cout << "Mejor promedio: " << mejorEstudiante << " (" << mejorPromedio << ")" << endl;

        cout << "¿Desea procesar otro grupo? (s/n): ";
        cin >> repetirPrograma;

    } while (repetirPrograma == 's' || repetirPrograma == 'S');

    return 0; 
}