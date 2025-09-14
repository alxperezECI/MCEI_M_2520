#include<bits/stdc++.h>
#include <iomanip>
#define MAX_ITER 100

using namespace std;

// Un ejemplo de uso del método Regular Falsi paa encontra la raíz
// La función es: f(x) = sin(10*x) + cos(3*x)
double func(double x)
{
    return sin(10*x) + cos(3*x);
}

// Agregando otra función
double func1(double x){
  return x*x*x*x*x*x*x*x*x*x - 1;
}


// Imprime la raíz de la funición func(x) en el intervalo [a, b]
void regulaFalsi(double (*f)(double), double a, double b)
{
    int count = 0;
    if (f(a) * f(b) >= 0)
    {
        cout << "No asumió bien los valores de a y b\n";
        return;
    }

    double c = a;  // Inicializa el resultado

    for (int i=0; i < MAX_ITER; i++)
    {
        // Encuentra el punto de corte de la línea con el eje x 
        c = (a*f(b) - b*f(a))/ (f(b) - f(a));

        // Valida si el punto encontrado es la raíz
        if (f(c)==0)
            break;

        // Decide con cual segmento continua la búsqueda
        else if (f(c)*f(a) < 0)
            b = c;
        else
            a = c;
        
        count++;
    cout << "El valor de c es: " << setprecision(16) << c << endl;
    }
    cout << "El valor de la raíz es: " << setprecision(10) << c << endl;
    cout << "con " << count << " iteracions." << endl;
}

// Llama la función que implementa el método
int main()
{
    // Valores iniciales asumidos
    double a =4., b = 5.;
    regulaFalsi( func,a, b );
    regulaFalsi( func1, 0.,  1.3);
    return 0;
}
