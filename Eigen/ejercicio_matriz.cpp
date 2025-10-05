#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    cout << "=== SOLUCIONADOR DE SISTEMAS LINEALES CON EIGEN ===" << endl << endl;
    
    // Sistema del archivo adjunto:
    // [ 3   -0.1  -0.2] [x1]   [ 7.85]
    // [0.1   7   -0.3 ] [x2] = [-19.3]
    // [0.3  -0.2   10 ] [x3]   [71.4 ]
    
    cout << "1. SISTEMA DE ECUACIONES DEL PROBLEMA:" << endl;
    
    Matrix3d A;
    A << 3,   -0.1, -0.2,
         0.1,  7,   -0.3,
         0.3, -0.2,  10;
    
    Vector3d b;
    b << 7.85, -19.3, 71.4;
    
    cout << "Matriz A:" << endl << A << endl << endl;
    cout << "Vector b:" << endl << b << endl << endl;
    
    // 2. Solución por Descomposición LU
    cout << "2. SOLUCIÓN POR DESCOMPOSICIÓN LU:" << endl;
    Vector3d x_lu = A.lu().solve(b);
    cout << "Solución x = " << x_lu.transpose() << endl;
    cout << "Error relativo: " << (A * x_lu - b).norm() / b.norm() << endl << endl;
    
    // 3. Verificación de la solución
    cout << "3. VERIFICACIÓN DE LA SOLUCIÓN:" << endl;
    Vector3d verificacion = A * x_lu;
    cout << "A * x = " << verificacion.transpose() << endl;
    cout << "b     = " << b.transpose() << endl;
    cout << "Diferencia = " << (verificacion - b).transpose() << endl << endl;
    
    // ================================================================
    // LIBRERÍAS EIGEN IMPLEMENTADAS PARA LA SOLUCIÓN
    // ================================================================
    cout << "4. LIBRERÍAS EIGEN IMPLEMENTADAS:" << endl << endl;
    
    cout << "INCLUSIÓN DE LIBRERÍAS:" << endl;
    cout << "• #include <Eigen/Dense>               // Librería principal de Eigen" << endl << endl;
    
    cout << "DECLARACIÓN DE MATRICES Y VECTORES:" << endl;
    cout << "• Matrix3d A;                          // Matriz estática 3x3 de doubles" << endl;
    cout << "• Vector3d b;                          // Vector estático de 3 elementos" << endl;
    cout << "• A << valores;                        // Inicialización con operador <<" << endl << endl;
    
    cout << "RESOLUCIÓN DE SISTEMAS LINEALES:" << endl;
    cout << "• A.lu().solve(b)                      // Descomposición LU + resolución" << endl;
    cout << "• Vector3d x_lu = A.lu().solve(b);     // Almacena la solución" << endl << endl;
    
    cout << "OPERACIONES MATRICIALES:" << endl;
    cout << "• A * x_lu                             // Multiplicación matriz-vector" << endl;
    cout << "• (A * x_lu - b)                       // Operaciones combinadas" << endl;
    cout << "• vector.transpose()                   // Transpuesta para visualización" << endl << endl;
    
    cout << "CÁLCULOS DE NORMAS Y ERRORES:" << endl;
    cout << "• vector.norm()                        // Norma euclidiana" << endl;
    cout << "• (A * x_lu - b).norm()                // Norma del vector residuo" << endl;
    cout << "• error_relativo = residuo/b.norm()    // Error relativo normalizado" << endl << endl;
    
    cout << "NAMESPACES UTILIZADOS:" << endl;
    cout << "• using namespace Eigen;               // Acceso directo a clases Eigen" << endl;
    cout << "• using namespace std;                 // Funciones estándar de C++" << endl;
    
    cout << "========================================" << endl;
    
    return 0;
}