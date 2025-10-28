#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_roots.h>
#include<bits/stdc++.h>
#include <iomanip>

#define EPSILON 0.00000001

using namespace std;

struct parametros{
  double a, b;
};
// Esta es la función a la que se le va a buscar la raíz
double f1(double x, void *par)
{
    return x*x*x-6*x*x+11*x-6;
}

double f2(double x, void *par){
  return (x-1)*(x-1)*(x-2);
}

double f3(double x, void *par){
  return tanh(10*(x-0.1))-0.5;
}

double f4(double x, void *par){
  return sin(50*x)/x;
}

double f5(double x, void *par){
  return abs(x-0.5)-0.1;
}
// Implementa el método de la bisección usando la GSL
int biseccion(double (*f)(double,void*), double x_lo, double x_hi)
{
  int status;
  int iter = 0, max_iter = 100;
  const gsl_root_fsolver_type *T;
  gsl_root_fsolver *s;
  double r = 0, r_expected = sqrt (5.0);
  parametros par={0., 1.};
  gsl_function F;
  F.function = f;
  F.params = &par;
  T = gsl_root_fsolver_bisection;
  s = gsl_root_fsolver_alloc (T);
  gsl_root_fsolver_set (s, &F, x_lo, x_hi);
  printf ("using %s method\n",
  gsl_root_fsolver_name (s));
  printf ("%5s [%9s, %9s] %9s %10s %9s\n", "iter", "lower", "upper", "root","err", "err(est)");

  do
  {
    iter++;
    status = gsl_root_fsolver_iterate (s);
    r = gsl_root_fsolver_root (s);
    x_lo = gsl_root_fsolver_x_lower (s);
    x_hi = gsl_root_fsolver_x_upper (s);
    status = gsl_root_test_interval (x_lo, x_hi,0, 0.00001);
    if (status == GSL_SUCCESS)
      printf ("Converged:\n");
    
    printf ("%5d [%.7f, %.7f] %.7f %+.7f %.7f\n",iter, x_lo, x_hi, r, r - r_expected, x_hi - x_lo);
  }while (status == GSL_CONTINUE && iter < max_iter);

  gsl_root_fsolver_free (s);
  return status;
}

// Aquí se invoca la función de bisección
int main()
{
    // Valores iniciales asumidos
    biseccion(f1, 4., 5.);
    biseccion(f2, 0., 1.3 );
    return 0;
}
