
#include <iostream>
#include <limits>
#include "AddData.h"
#include "SearchByKey.h"
#include "SearchByValue.h"
#include "cmake-build-debug/Readtxt.h"

using namespace std;

int main() {
    cout << "--------------------Proyecto 2 - In Memory DB--------------------\n";

    string fileAccess;

    cout << "Ingrese la ruta de acceso del archivo de texto: " << endl;
    cout << "Considere que debe quitar las comillas de la ruta de acceso" << endl;
    cin >> fileAccess;

    Readtxt reader(fileAccess);

    cout << "Datos cargados exitosamente desde el archivo, continue con 's'" << std::endl;
    char continiue;
    cin >> continiue;

    in:
    system("cls");
    cho:
    int choice = 0;
    cout << "Opciones:\n";
    cout << "1. Cargar más datos desde un archivo\n";
    cout << "2. Busqueda por clave\n";
    cout << "3. Busqueda por valor\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";

    string input;
    getline(cin, input);
    try {
        choice = std::stoi(input);
    } catch (const std::invalid_argument& e) {
        std::cout << "Entrada no válida. Por favor, ingrese un número válido." << std::endl;
        goto cho;
    }

    switch (choice) {
        case 1: {
            system("cls");
            AddData addDataOption(reader);
            string filename;
            cout << "Ingrese el nombre del archivo: ";
            cin >> filename;
            addDataOption.addDataFromFile(filename);
            back:
            cout << "Datos cargados exitosamente desde el archivo, continue con 's'" << std::endl;
            char continiue1;
            cin >> continiue1;
            if (continiue1 == 's')
            {
                goto in;
            }
            else {
                cout << "Seleccione 's' por favor" << endl;
                goto back;
            }
            break;
        }
        case 2: {
            SearchByKey searcher(reader);

            std::string searchTerm;
            std::cout << "Ingrese la clave a buscar: ";
            std::cin >> searchTerm;

            auto matchingSets = searcher.searchByKeyPrefix(searchTerm);

            if (!matchingSets.empty()) {
                for (const auto& set : matchingSets) {
                    std::cout << "Clave: " << set.first << ", Valores: ";
                    for (const auto& value : set.second) {
                        std::cout << value << " ";
                    }
                    std::cout << std::endl;
                }
            } else {
                std::cout << "La clave no se encontró en los datos." << std::endl;
            }

            back1:
            cout << "Hash encontrado, continue con 's'" << std::endl;
            char continiue2;
            cin >> continiue2;
            if (continiue2 == 's')
            {
                goto in;
            }
            else {
                cout << "Seleccione 's' por favor" << endl;
                goto back1;
            }
            break;
        }
        case 3: {
            SearchByValue searchByValueOption(reader);

            std::string searchTerm;
            std::cout << "Ingrese el valor a buscar: ";
            cin >> searchTerm;

            auto matchingPairs = searchByValueOption.searchByValue(searchTerm);

            back2:
            cout << "Value encontrado, continue con 's'" << std::endl;
            char continiue3;
            cin >> continiue3;
            if (continiue3 == 's')
            {
                goto in;
            }
            else {
                cout << "Seleccione 's' por favor" << endl;
                goto back2;
            }
            break;
        }
        case 4:
            std::cout << "Saliendo del programa." << std::endl;
            return 0;
        default:
            std::cout << "Opción no válida, escoja un numero correcto" << std::endl;
            system("cls");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            goto cho;
    }
    return 0;
}


