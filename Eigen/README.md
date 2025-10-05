# Ejemplos con la Librería Eigen

Este directorio contiene ejemplos prácticos de uso de la librería Eigen para álgebra lineal en C++.

## Contenido

### 1. `ejercicio_matriz.cpp` 
Solucionadores de sistemas lineales:
- **Resuelve el sistema del archivo adjunto**: 
  ```
  [ 3   -0.1  -0.2] [x1]   [ 7.85]
  [ 0.1   7   -0.3] [x2] = [-19.3]
  [ 0.3  -0.2   10] [x3]   [71.4 ]
  ```
- Diferentes métodos de descomposición (LU, QR, LDLT)
- Sistemas sobredeterminados (mínimos cuadrados)
- Análisis de propiedades de la matriz

### 2. `aplicaciones_eigen.cpp`
Aplicaciones avanzadas con explicaciones paso a paso:
- **Descomposición LU con pivoteo parcial** (explicación línea por línea)
- **Pseudoinversa de Moore-Penrose** (con aplicación práctica)
- Verificación matemática de propiedades
- Ejemplos de sistemas sobredeterminados
- Resumen de funciones Eigen utilizadas

## Instalación de Eigen

### Ubuntu/Debian:
```bash
sudo apt-get install libeigen3-dev
```

### Usando vcpkg:
```bash
vcpkg install eigen3
```

### Compilación manual:
```bash
git clone https://gitlab.com/libeigen/eigen.git
cd eigen
mkdir build && cd build
cmake ..
make install
```

## Compilación

### Opción 1: Usando CMake (Recomendado)
```bash
cd Eigen
mkdir build && cd build
cmake ..
make

# Ejecutar ejemplos
./ejercicio_matriz
./aplicaciones_eigen
```

### Opción 2: Compilación manual
```bash
# Asegúrate de que Eigen esté instalado en tu sistema
g++ -I/usr/include/eigen3 -O3 ejercicio_matriz.cpp -o ejercicio_matriz
g++ -I/usr/include/eigen3 -O3 aplicaciones_eigen.cpp -o aplicaciones_eigen
```

## Características de Eigen

### Ventajas:
- **Solo headers**: No requiere compilación de librería
- **Alto rendimiento**: Optimizaciones automáticas y vectorización
- **Sintaxis expresiva**: Similar a MATLAB/Python NumPy
- **Flexibilidad**: Matrices estáticas y dinámicas
- **Amplia funcionalidad**: Desde operaciones básicas hasta descomposiciones avanzadas

### Tipos principales:
- `Matrix<tipo, filas, columnas>`: Matrices de tamaño fijo
- `MatrixXd`: Matrices dinámicas de double
- `Vector<tipo, tamaño>`: Vectores de tamaño fijo
- `VectorXd`: Vectores dinámicos de double

### Operaciones disponibles:
- Álgebra lineal básica (+, -, *, transpose, etc.)
- Descomposiciones (LU, QR, SVD, Cholesky, etc.)
- Solución de sistemas lineales
- Cálculo de valores propios
- Transformaciones geométricas
- Y mucho más...

## Notas de rendimiento

- Usa `-O3` para optimizaciones de compilación
- Para matrices grandes (>100x100), considera usar descomposiciones específicas
- Eigen utiliza lazy evaluation para optimizar operaciones en cadena
- Las matrices estáticas (tamaño conocido en tiempo de compilación) son más eficientes

## Referencias

- [Documentación oficial de Eigen](https://eigen.tuxfamily.org/dox/)
- [Tutorial rápido](https://eigen.tuxfamily.org/dox/GettingStarted.html)
- [Referencia API](https://eigen.tuxfamily.org/dox/modules.html)