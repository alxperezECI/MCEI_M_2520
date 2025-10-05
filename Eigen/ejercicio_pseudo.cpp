#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    cout << "=== CÁLCULO DE PSEUDOINVERSA CON EIGEN ===" << endl << endl;
    
    // ================================================================
    // CÁLCULO DE PSEUDOINVERSA - MATRIZ DEL PROBLEMA
    // ================================================================
    cout << "1. MATRIZ DEL PROBLEMA:" << endl;
    cout << "Se calculará la pseudoinversa de la siguiente matriz 4x3:" << endl << endl;
    
    // Matriz de la imagen adjunta
    MatrixXd A(4, 3);
    A << 1,  0,  2,
         2, -1,  5,
         0,  1, -1,
         1,  3, -1;
    
    cout << "MatrixXd A(4, 3); // Matriz rectangular 4x3" << endl;
    cout << "A << 1,  0,  2," << endl;
    cout << "     2, -1,  5," << endl;
    cout << "     0,  1, -1," << endl;
    cout << "     1,  3, -1;" << endl << endl;
    
    cout << "Matriz A:" << endl << A << endl << endl;
    
    // ================================================================
    // CÁLCULO DE LA PSEUDOINVERSA
    // ================================================================
    cout << "2. CÁLCULO DE LA PSEUDOINVERSA:" << endl;
    cout << "La pseudoinversa A+ se calcula usando la descomposición ortogonal completa" << endl;
    cout << "Para una matriz A de 4x3, la pseudoinversa A+ será de 3x4" << endl << endl;
    
    // Calcular pseudoinversa
    cout << "Comando Eigen utilizado:" << endl;
    cout << "MatrixXd A_pinv = A.completeOrthogonalDecomposition().pseudoInverse();" << endl << endl;
    
    MatrixXd A_pinv = A.completeOrthogonalDecomposition().pseudoInverse();
    
    cout << "Pseudoinversa A+ (3x4):" << endl << A_pinv << endl << endl;
    
    // ================================================================
    // VERIFICACIÓN DE PROPIEDADES DE MOORE-PENROSE
    // ================================================================
    cout << "3. VERIFICACIÓN DE PROPIEDADES:" << endl;
    
    cout << "Propiedad 1: A * A+ * A = A" << endl;
    MatrixXd prop1 = A * A_pinv * A;
    cout << "A * A+ * A =" << endl << prop1 << endl;
    cout << "Error ||A * A+ * A - A||: " << (prop1 - A).norm() << endl << endl;
    
    cout << "Propiedad 2: A+ * A * A+ = A+" << endl;
    MatrixXd prop2 = A_pinv * A * A_pinv;
    cout << "A+ * A * A+ =" << endl << prop2 << endl;
    cout << "Error ||A+ * A * A+ - A+||: " << (prop2 - A_pinv).norm() << endl << endl;
    
    // Propiedades adicionales de simetría
    cout << "Propiedad 3: A * A+ debe ser simétrica" << endl;
    MatrixXd AA_pinv = A * A_pinv;
    cout << "A * A+ =" << endl << AA_pinv << endl;
    cout << "Transpuesta (A * A+)^T =" << endl << AA_pinv.transpose() << endl;
    cout << "Error de simetría ||A * A+ - (A * A+)^T||: " << (AA_pinv - AA_pinv.transpose()).norm() << endl << endl;
    
    cout << "Propiedad 4: A+ * A debe ser simétrica" << endl;
    MatrixXd A_pinvA = A_pinv * A;
    cout << "A+ * A =" << endl << A_pinvA << endl;
    cout << "Transpuesta (A+ * A)^T =" << endl << A_pinvA.transpose() << endl;
    cout << "Error de simetría ||A+ * A - (A+ * A)^T||: " << (A_pinvA - A_pinvA.transpose()).norm() << endl << endl;
    
    // ================================================================
    // COMANDOS EIGEN IMPLEMENTADOS PARA LA SOLUCIÓN
    // ================================================================
    cout << "4. COMANDOS EIGEN UTILIZADOS:" << endl << endl;
    
    cout << "DECLARACIÓN Y CONSTRUCCIÓN DE MATRICES:" << endl;
    cout << "• MatrixXd A(4, 3);                    // Matriz dinámica 4x3" << endl;
    cout << "• A << valores;                        // Inicialización con operador <<" << endl;
    cout << "• VectorXd b(4);                       // Vector dinámico de 4 elementos" << endl << endl;
    
    cout << "CÁLCULO DE PSEUDOINVERSA:" << endl;
    cout << "• A.completeOrthogonalDecomposition()  // Descomposición QRP completa" << endl;
    cout << "• .pseudoInverse()                     // Pseudoinversa Moore-Penrose" << endl << endl;
    
    cout << "OPERACIONES MATRICIALES:" << endl;
    cout << "• A * A_pinv                           // Multiplicación matriz-matriz" << endl;
    cout << "• A_pinv * b                           // Multiplicación matriz-vector" << endl;
    cout << "• A * x - b                            // Operaciones combinadas" << endl << endl;
    
    cout << "CÁLCULOS DE NORMAS Y ERRORES:" << endl;
    cout << "• matrix.norm()                        // Norma de Frobenius" << endl;
    cout << "• vector.transpose()                   // Transpuesta para visualización" << endl << endl;
    
    cout << "ANÁLISIS DE DIMENSIONES:" << endl;
    cout << "• Matriz original A: 4x3 (4 filas, 3 columnas)" << endl;
    cout << "• Pseudoinversa A+: 3x4 (3 filas, 4 columnas)" << endl;
    cout << "• Para Ax = b: x = A+ * b (solución de mínimos cuadrados)" << endl;
    
    cout << "========================================" << endl;
    
    return 0;
}