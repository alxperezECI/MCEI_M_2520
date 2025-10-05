#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    cout << "=== SOLUCIONADOR DE SISTEMAS LINEALES CON EIGEN ===" << endl << endl;
    
    // Sistema del archivo adjunto:
    // 2y + 5z = 9
    // 2x + y + z = 9
    // 3x + y = 10
    //
    // En forma matricial:
    // [ 0  2  5] [x]   [ 9]
    // [ 2  1  1] [y] = [ 9]
    // [ 3  1  0] [z]   [10]
    
    cout << "1. SISTEMA DE ECUACIONES DEL PROBLEMA:" << endl;
    cout << "2y + 5z = 9" << endl;
    cout << "2x + y + z = 9" << endl;
    cout << "3x + y = 10" << endl << endl;
    
    Matrix3d A;
    A << 0,  2,  5,
         2,  1,  1,
         3,  1,  0;
    
    Vector3d b;
    b << 9, 9, 10;
    
    cout << "Matriz A:" << endl << A << endl << endl;
    cout << "Vector b:" << endl << b << endl << endl;
    
    // 2. Solución por Descomposición LU
    cout << "2. SOLUCIÓN POR DESCOMPOSICIÓN LU:" << endl;
    Vector3d x_lu = A.lu().solve(b);
    cout << "Solución x = " << x_lu.transpose() << endl;
    cout << "Error relativo: " << (A * x_lu - b).norm() / b.norm() << endl << endl;
    
    cout << "Variables del sistema:" << endl;
    cout << "x = " << x_lu(0) << endl;
    cout << "y = " << x_lu(1) << endl;
    cout << "z = " << x_lu(2) << endl << endl;
    
    // 3. Verificación de la solución
    cout << "3. VERIFICACIÓN DE LA SOLUCIÓN:" << endl;
    Vector3d verificacion = A * x_lu;
    cout << "A * x = " << verificacion.transpose() << endl;
    cout << "b     = " << b.transpose() << endl;
    cout << "Diferencia = " << (verificacion - b).transpose() << endl << endl;
    
    // Verificación manual de cada ecuación
    cout << "Verificación manual de ecuaciones:" << endl;
    double eq1 = 2*x_lu(1) + 5*x_lu(2);  // 2y + 5z
    double eq2 = 2*x_lu(0) + x_lu(1) + x_lu(2);  // 2x + y + z
    double eq3 = 3*x_lu(0) + x_lu(1);  // 3x + y
    
    cout << "Ecuación 1: 2y + 5z = 2(" << x_lu(1) << ") + 5(" << x_lu(2) << ") = " << eq1 << " (debe ser 9)" << endl;
    cout << "Ecuación 2: 2x + y + z = 2(" << x_lu(0) << ") + " << x_lu(1) << " + " << x_lu(2) << " = " << eq2 << " (debe ser 9)" << endl;
    cout << "Ecuación 3: 3x + y = 3(" << x_lu(0) << ") + " << x_lu(1) << " = " << eq3 << " (debe ser 10)" << endl << endl;
    
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
    
    cout << "ACCESO A ELEMENTOS INDIVIDUALES:" << endl;
    cout << "• x_lu(0), x_lu(1), x_lu(2)           // Acceso por índices (x, y, z)" << endl;
    cout << "• double eq1 = 2*x_lu(1) + 5*x_lu(2)   // Uso en cálculos manuales" << endl << endl;
    
    cout << "CÁLCULOS DE NORMAS Y ERRORES:" << endl;
    cout << "• vector.norm()                        // Norma euclidiana" << endl;
    cout << "• (A * x_lu - b).norm()                // Norma del vector residuo" << endl;
    cout << "• error_relativo = residuo/b.norm()    // Error relativo normalizado" << endl << endl;
    
    cout << "VERIFICACIÓN MATEMÁTICA:" << endl;
    cout << "• Sustitución directa en ecuaciones originales" << endl;
    cout << "• Comparación numérica de resultados" << endl;
    cout << "• Validación de consistencia del sistema" << endl << endl;
    
    cout << "NAMESPACES UTILIZADOS:" << endl;
    cout << "• using namespace Eigen;               // Acceso directo a clases Eigen" << endl;
    cout << "• using namespace std;                 // Funciones estándar de C++" << endl;
    
    cout << "========================================" << endl;
    
    return 0;
}