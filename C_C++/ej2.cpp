#include <iostream>
#include <cmath> // <cmath>
#include <float.h>
#include <iomanip>

double funcion(double t, double m, double c){
  return 9.8 * m / c * (1 - exp( -c/m*t ) );
}

int main(int argc, char** argv){
   
  // Resolviendo el problema del paracaidista
  double veloant = 0.0;
  double velo = 0.0;
  double tiempo = 0.0;
  velo = funcion(tiempo, 68.1, 12.5);
  tiempo = 2.0;
  std::cout << std::setprecision(16) << "t = 0.0\t" <<  "vel = " << velo << std::endl;
  do{
    veloant = velo;
    velo = funcion(tiempo, 68.1, 12.5);
    std::cout << "t = " << tiempo << " vel = " << velo << std::endl;
    tiempo = tiempo + 2.0;
  }while( ( velo - veloant) > 0.0001 );
  std::cout << "Cambiado desde EciStudent" << std::endl;
  return 0;
}
