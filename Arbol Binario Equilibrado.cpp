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
        std::cout << " 2.- Mostrar árbol completo\n";
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
            std::cout << "\nMostrar el árbol completo: \n\n";
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

// Función para mostrar árbol completo
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

// Función para obtener la altura de un nodo
int altura(Nodo *nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }
    int alturaIzq = altura(nodo->izq);
    int alturaDer = altura(nodo->der);
    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}

// Función para obtener el factor de equilibrio de un nodo
int factorEquilibrio(Nodo *nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }
    return altura(nodo->izq) - altura(nodo->der);
}

// Función para realizar rotación a la derecha
void rotarDerecha(Nodo *&nodo)
{
    Nodo *tempIzq = nodo->izq;
    nodo->izq = tempIzq->der;
    tempIzq->der = nodo;
    nodo = tempIzq;
}

// Función para realizar rotación a la izquierda
void rotarIzquierda(Nodo *&nodo)
{
    Nodo *tempDer = nodo->der;
    nodo->der = tempDer->izq;
    tempDer->izq = nodo;
    nodo = tempDer;
}

// Función para balancear un nodo
void balancearNodo(Nodo *&nodo)
{
    if (factorEquilibrio(nodo) == -2)
    {
        if (factorEquilibrio(nodo->der) == 1)
        {
            rotarDerecha(nodo->der);
        }
        rotarIzquierda(nodo);
    }
    else if (factorEquilibrio(nodo) == 2)
    {
        if (factorEquilibrio(nodo->izq) == -1)
        {
            rotarIzquierda(nodo->izq);
        }
        rotarDerecha(nodo);
    }
}

// Función para insertar un nuevo nodo en el árbol
void insertarNodo(Nodo *&arbol, int n)
{
    if (arbol == nullptr)
    {
        arbol = crearNodo(n);
    }
    else
    {
        if (n < arbol->flame)
        {
            insertarNodo(arbol->izq, n);
        }
        else
        {
            insertarNodo(arbol->der, n);
        }

        // Balancear el árbol después de la inserción
        balancearNodo(arbol);
    }
}
