#include "iostream"

const int longCad = 20;

struct costoPorArticulo
{
    char nombreDelArticulo [longCad + 1];
    int cantidad;
    float precio;
    float costoPorArtico;
};

using namespace std;

costoPorArticulo leerArray(int, costoPorArticulo arr []);
costoPorArticulo calcularCosto(int, costoPorArticulo arr[]);
void recorrerArray(int, costoPorArticulo arr[]);
float totalaPagar(int, costoPorArticulo arr []);

int main() 
{
    //Variable
    int n;
    float precioTotal;
    //input-output
    cout << "Programa que da la informacion del producto al cliente." << endl;
    cout << "------------" << endl;
    cin >> n;
    cin.ignore(100, '\n'); 
    if(n <= 10 && n > 0)
    {
        costoPorArticulo arr [n];
        //Procedimiento
        leerArray(n, arr);
        calcularCosto(n, arr);
        recorrerArray(n, arr);
        precioTotal = totalaPagar(n, arr);
        //output
        cout << "--------" << endl;
        cout << "Cantidad a pagar es: $" << precioTotal;
    }else
    {
        cout << "El precio del producto debe de ser menor o igual a 10 y mayor a 0." << endl;
    }
    return 0;
}
costoPorArticulo leerArray(int n, costoPorArticulo arr[])
{
    //Variables
    int cantidad;
    float precio;
    //Complatamos los arreglos 
    for(int i = 0; i < n; i++)
    {
        int n = i + 1;
        cout << "Ingrese los datos del articulo: " << n << endl;
        cout << "Nombre del articulo: "<< endl;
        cin.getline(arr [i].nombreDelArticulo, 20, '\n');
        cout << "Cantidad de los articulos: " << endl;
        cin >> cantidad;
        cout << "Precio del articulo: " << endl;
        cin >> precio;
        cin.ignore(100, '\n');
        cout << "----------" << endl;
        //Validacion de la cantidad
        if(cantidad > 0 && precio > 0)
        {
            arr [i].cantidad = cantidad;
            arr [i].precio = precio;
        }else
        {
            i--;
            cout << "No es valida la cantidad ingresada." << endl;
        }
        
    }
    return arr [0];
}
costoPorArticulo calcularCosto(int n, costoPorArticulo arr [])
{
    float costoFinal = 0;
    for(int i = 0; i < n; i++)
    {
        //Sumando el precio de todos los articulos
        costoFinal = arr [i].precio * arr [i].cantidad;
        arr [i].costoPorArtico = costoFinal;
    }
    return arr [0];
}
void recorrerArray(int x, costoPorArticulo arr [])
{
    //Datos de la compra
    cout << " FACTURA " << endl;
    for(int i = 0; i < x; i++)
    {
        int n = i + 1;
        cout << "Articulo " << n << ": " << arr [i].nombreDelArticulo << " Cantidad: " << arr [i].cantidad << " Precio: $" << arr [i].precio << " Precio total de los articulos: $" << arr [i].costoPorArtico << endl;
    }
}
float totalaPagar(int x, costoPorArticulo arr [])
{
    //Retenedor 
    float precioTotal = 0;
    //Desarrollo
    for(int i = 0; i < x; i++)
    {
        precioTotal += arr [i].costoPorArtico;
    }
    return precioTotal;
}
