#include <iostream>
#include <string>
#include <cctype>

std::string generarRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, int anio, int mes, int dia) {
    // Primer letra del apellido paterno
    char primeraLetraPaterno = apellidoPaterno[0];

    // Primera vocal interna del apellido paterno
    char primeraVocalInterna = 'X';
    for (char c : apellidoPaterno.substr(1)) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            primeraVocalInterna = c;
            break;
        }
    }

    // Inicial del apellido materno
    char inicialApellidoMaterno = apellidoMaterno.empty() ? 'X' : apellidoMaterno[0];

    // Inicial del primer nombre
    char inicialNombre = nombre[0];

    // Evitar palabras inconvenientes (opcional, basado en reglas específicas)
    if (toupper(primeraLetraPaterno) == 'B' && toupper(primeraVocalInterna) == 'U' &&
        toupper(inicialApellidoMaterno) == 'R' && toupper(inicialNombre) == 'O') {
        inicialNombre = 'X';
    }

    // Construir RFC
    std::string rfc;
    rfc += toupper(primeraLetraPaterno);
    rfc += toupper(primeraVocalInterna);
    rfc += toupper(inicialApellidoMaterno);
    rfc += toupper(inicialNombre);

    // Agregar año, mes y día
    rfc += std::to_string(anio).substr(2, 2);
    rfc += (mes < 10 ? "0" : "") + std::to_string(mes);
    rfc += (dia < 10 ? "0" : "") + std::to_string(dia);

    return rfc;
}

int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno;
    int anio, mes, dia;

    // Captura de datos
    std::cout << "Ingresa el nombre: ";
    std::getline(std::cin, nombre); // Leer línea completa para nombre

    std::cout << "Ingresa el apellido paterno: ";
    std::getline(std::cin, apellidoPaterno); // Leer línea completa para apellido paterno

    std::cout << "Ingresa el apellido materno (si no tienes, deja en blanco): ";
    std::getline(std::cin, apellidoMaterno); // Leer línea completa para apellido materno

    std::cout << "Ingresa el año de nacimiento (YYYY): ";
    std::cin >> anio;
    std::cin.ignore(); // Ignorar salto de línea

    std::cout << "Ingresa el mes de nacimiento (MM): ";
    std::cin >> mes;
    std::cin.ignore(); // Ignorar salto de línea

    std::cout << "Ingresa el día de nacimiento (DD): ";
    std::cin >> dia;
    std::cin.ignore(); // Ignorar salto de línea

    // Generar RFC
    std::string rfc = generarRFC(nombre, apellidoPaterno, apellidoMaterno, anio, mes, dia);

    // Mostrar RFC generado
    std::cout << "El RFC generado es: " << rfc << std::endl;

    return 0;
}
