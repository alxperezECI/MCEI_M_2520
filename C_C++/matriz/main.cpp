#include <iostream>
#include <Eigen/Dense>

int main() {
  std::cout << "[inicialización]\n";
  Eigen::MatrixXd A(3, 3);
  A << 3, -.1, -.2, .1, 7, -.3, .3, -.2, 10;
  std::cout << "Matriz de entrada A antes de la descomposición:\n" << A << "\n";
  std::cout << "[inicialización]\n";

  std::cout << "[declaración]\n";
  Eigen::PartialPivLU<Eigen::Ref<Eigen::MatrixXd> > lu(A);
  std::cout << "Matriz A después de la descomposición:\n" << A << "\n";
  std::cout << "[declaración]\n";

  std::cout << "[matrizLU]\n";
  std::cout << "Matriz que almacena los factores L y U:\n" << lu.matrixLU() << "\n";
  std::cout << "[matrizLU]\n";

  // Extraer la matriz LU combinada
  Eigen::MatrixXd LU = lu.matrixLU(); // LU contiene L (triangular inferior con 1s en la diagonal) y U (triangular superior)
  // Obtener la matriz L (triangular inferior con 1s en la diagonal)
  Eigen::MatrixXd L = LU.triangularView<Eigen::UnitLower>(); // L es la parte triangular inferior de LU, con 1s en la diagonal
  // Obtener la matriz U (triangular superior)
  Eigen::MatrixXd U = LU.triangularView<Eigen::Upper>(); // U es la parte triangular superior de LU
  // Mostrar L y U por separado
  std::cout << "Matriz L:\n" << L << "\n"; // Imprime la matriz L
  std::cout << "Matriz U:\n" << U << "\n"; // Imprime la matriz U

  std::cout << "[resolver]\n";
  Eigen::VectorXd b(3);
  b << 7.85, -19.3, 71.4;
  std::cout << "Vector b:\n" << b << "\n";
  Eigen::VectorXd x = lu.solve(b);
  std::cout << "Solución x:\n" << x << "\n";
  std::cout << "Residuo: " << (A * x - b).norm() << "\n";
  std::cout << "[resolver]\n";
}
