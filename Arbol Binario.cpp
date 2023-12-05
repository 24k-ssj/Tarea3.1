// Profesor tengo una duda, al momento de usar cout y cin me marcan errores si no coloco "std::" antes de ponerlo, ¿tiene alguna solucion? o ya es de afuerzas ponerlo
#include <iostream>

// Creación de nodo
struct Nodo
{
    int flame;
    Nodo *der;
    Nodo *izq;
};

// Prototipos
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void menu();
void mostrarArbol(Nodo *, int);

Nodo *arbol = nullptr;

int main()
{
    menu();
    return 0;
}

// Función de menú
void menu()
{
    int flame, opcion, contador = 0;

    do
    {
        std::cout << "\n Menu:\n";
        std::cout << " 1.- Insertar un nuevo nodo\n";
        std::cout << " 2.- Mostrar arbol completo\n";
        std::cout << " 3.- Salir\n";

        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::cout << "Digite un numero: ";
            std::cin >> flame;
            insertarNodo(arbol, flame);
            std::cout << "\n";
            system("pause");
            break;
        case 2:
            std::cout << "\nMostrar el arbol completo: \n\n";
            mostrarArbol(arbol, contador);
            std::cout << "\n \n";
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 3);
}

// Función para crear un nuevo nodo
Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->flame = n;
    nuevo_nodo->der = nullptr;
    nuevo_nodo->izq = nullptr;
    return nuevo_nodo;
}

// Función para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n)
{
    if (arbol == nullptr)
    { // Si el arbol está vacío
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else
    {                                 // Si el arbol tiene uno o más nodos
        int valorRaiz = arbol->flame; // Obtener valor de la raíz
        if (n < valorRaiz)
        { // Si el elemento es menor a la raíz, insertamos en la izquierda
            insertarNodo(arbol->izq, n);
        }
        else
        { // Si el elemento es mayor a la raíz, insertamos en la derecha
            insertarNodo(arbol->der, n);
        }
    }
}

// Función para mostrar el árbol completo
void mostrarArbol(Nodo *arbol, int contador)
{
    if (arbol == nullptr)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der, contador + 1);
        for (int i = 0; i < contador; i++)
        {
            std::cout << "   ";
        }
        std::cout << arbol->flame << "-----\n";
        mostrarArbol(arbol->izq, contador + 1);
    }
}
