#include <iostream>
#include <cmath>
#include <gsl/gsl_multimin.h>

using namespace std;

// Definir la función objetivo
double my_function(const gsl_vector *v, void *params) {
    double x = gsl_vector_get(v, 0);
    double y = gsl_vector_get(v, 1);
    return (x - 2) * (x - 2) + (y + 3) * (y + 3);  // mínimo en (2, -3)
}

int main() {
    const gsl_multimin_fminimizer_type *T = gsl_multimin_fminimizer_nmsimplex2;
    gsl_multimin_fminimizer *s;

    size_t n = 2;  // número de variables
    gsl_vector *x = gsl_vector_alloc(n);         // vector de valores iniciales
    gsl_vector *step_size = gsl_vector_alloc(n); // tamaño del paso por dimensión

    gsl_multimin_function minex_func;
    minex_func.n = n;
    minex_func.f = my_function;
    minex_func.params = nullptr;

    // Estimar un punto inicial
    gsl_vector_set(x, 0, 0.0);  // x inicial
    gsl_vector_set(x, 1, 0.0);  // y inicial

    // Tamaños iniciales del paso
    gsl_vector_set_all(step_size, 1.0);

    // Inicializar el minimizador
    s = gsl_multimin_fminimizer_alloc(T, n);
    gsl_multimin_fminimizer_set(s, &minex_func, x, step_size);

    size_t iter = 0;
    int status;
    double size;

    do {
        iter++;
        status = gsl_multimin_fminimizer_iterate(s);

        if (status) break; // error

        size = gsl_multimin_fminimizer_size(s);
        status = gsl_multimin_test_size(size, 1e-5);

        cout << "Iter " << iter
             << ": x = " << gsl_vector_get(s->x, 0)
             << ", y = " << gsl_vector_get(s->x, 1)
             << ", f = " << s->fval
             << ", size = " << size << endl;
    } while (status == GSL_CONTINUE && iter < 100);

    gsl_vector_free(x);
    gsl_vector_free(step_size);
    gsl_multimin_fminimizer_free(s);

    return 0;
}
