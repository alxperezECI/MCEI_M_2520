#include "demo_fn.h"

double quadratic (double x, void *params)
{
  quadratic_params *p = ( quadratic_params *) params;
  double a = p->a;
  double b = p->b;
  double c = p->c;
  //return (a * x + b) * x + c;
  return sin(10*x) + cos(3*x);
}

double quadratic_deriv (double x, void *params)
{
  quadratic_params *p = (quadratic_params *) params;
  double a = p->a;
  double b = p->b;
  return 2.0 * a * x + b;
}

void quadratic_fdf (double x, void *params, double *y, double *dy)
{
  quadratic_params *p = ( quadratic_params *) params;
  double a = p->a;
  double b = p->b;
  double c = p->c;
  *y = (a * x + b) * x + c;
  *dy = 2.0 * a * x + b;
}
