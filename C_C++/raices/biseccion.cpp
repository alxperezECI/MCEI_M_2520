#include<bits/stdc++.h>
#include <iomanip>

#define EPSILON 0.00000001

using namespace std;

// Este es un ejemplo de uso del método de bisección para encontra la raíz
// La función es f(x)= sin(10x) +cos(3x)
double func(double x)
{
    return sin(10*x) + cos(3*x);
}


// Otra función
double func1(double x){
  return x*x*x*x*x*x*x*x*x*x -1 ;
}

// Imprime las raices de la func(x) con un error de EPSILON
void biseccion(double (*f)(double), double a, double b)
{
    int count = 0;
    if (f(a) * f(b) >= 0)
    {
        cout << "No asumió bien los valores de a y b.\n";
        return;
    }

    double c = a;
    while ((b-a) >= EPSILON)
    {
        // Encuentra el punto medio
        c = (a+b)/2;

        // Verifica si el punto medio es una raíz
        if (f(c) == 0.0)
            break;

        // Decide con cual segmento continua la búsqueda 
        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
        count++;
        cout << "El valor de c es: " << setprecision(10) << c << endl;
    }
    cout << "El valor de la raíz es: " << setprecision(16) << c << endl;
    cout << "Con " << count << " iteraciones." << endl;
}

// Aquí se invoca la función de bisección
int main()
{
    // Valores iniciales asumidos
    double a =4., b = 5.;
    biseccion(func, a, b);
    biseccion(func1, 0., 1.3 );
    return 0;
}
