#include <iostream>
#include <unsupported/Eigen/Polynomials>

using namespace std;

int main(int argc, char** argv){
  if(argc == 1){
    cout << "Debe ingresar los coeficientes a0 a1 a2 ... del respectivo polinomio.\n";
    return -1;
  }

  Eigen::VectorXd coeff( argc - 1);

  double tmp;

  for(int i = 0; i < argc - 1; i++){
    tmp = atof( argv[i+1] );
    coeff(i) = tmp;
  }

  
  Eigen::PolynomialSolver<double, Eigen::Dynamic> solver;
  solver.compute(coeff);
  const Eigen::PolynomialSolver<double, Eigen::Dynamic>::RootsType &r = solver.roots();
  cout << r << endl;
  return 0;
}
