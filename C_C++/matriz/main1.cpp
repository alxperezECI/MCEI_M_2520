#include <iostream>
#include <Eigen/Dense>

int main() {
    // Definir una matriz rectangular o cuadrada 
    Eigen::MatrixXd A(4, 3);
    A << 1, 0, 2, 
        2, -1, 5,
        0, 1, -1,
        1, 3, -1 ;
        std::cout << "Matriz A:\n" << A << "\n";

    // Calcular la pseudoinversa de Moore-Penrose usando la descomposición SVD (Singular Value Decomposition)
    // SVD descompone A en U * S * V^T, donde S es diagonal con los valores singulares
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
    double tol = 1e-6; // Tolerancia para considerar valores singulares como cero

    // Invertir los valores singulares: si el valor es mayor que la tolerancia, se invierte; si no, se pone a cero
    Eigen::VectorXd singularValuesInv = svd.singularValues();
    for (int i = 0; i < singularValuesInv.size(); ++i) {
        if (singularValuesInv(i) > tol)
            singularValuesInv(i) = 1.0 / singularValuesInv(i); // Invertir valor singular
        else
            singularValuesInv(i) = 0; // Si es muy pequeño, se considera cero
    }
    // Calcular la pseudoinversa: V * S^+ * U^T
    // S^+ es la matriz diagonal con los valores singulares invertidos
    Eigen::MatrixXd A_pinv = svd.matrixV() * singularValuesInv.asDiagonal() * svd.matrixU().transpose();

    std::cout << "Pseudoinversa de Moore-Penrose de A:\n" << A_pinv << "\n";
    return 0;
}
