/*********************************************************
Materia: Gráficas Computacionales
Fecha: 14 de agosto del 2017
Autor: A01376121 Luis Ricardo Gutierrez
*********************************************************/

#include <iostream>
int PerimetroRectangulo(int base, int altura);
float AreaTriangulo(float base, float altura);
int Mayor(int numero1, int numero2, int numero3);
int Menor(int numero1, int numero2, int numero3);
void FilaEstrellas(int n);
void MatrizEstrellas(int n);
void PiramideEstrellas(int n);
void FlechaEstrellas(int n);
void Fibonacci(int n);
bool EsPrimo(int numero);

int main() {
    std::cout << "Hello World!" << std::endl;
    int p = PerimetroRectangulo(5, 3);
    std::cout << p << std::endl;
    float a = AreaTriangulo(5.0f, 3.0f);
    std::cout << a << std::endl;
    int mayor = Mayor(5, 9, 1);
    std::cout << mayor << std::endl;
    int menor = Menor(5, 9, 1);
    std::cout << menor << std::endl;
    FilaEstrellas(5);
    MatrizEstrellas(4);
    PiramideEstrellas(6);
    FlechaEstrellas(3);
    Fibonacci(9);
    bool primo = EsPrimo(52);
    std::cout << primo << std::endl;

    return 0;
}
int PerimetroRectangulo(int base, int altura) {
    return  (2*base) + (2 *altura);
    
}
float AreaTriangulo(float base, float altura) {
 return base*altura/2;   
    
}
int Mayor(int numero1, int numero2, int numero3) {
    return numero1*(numero1>numero2 & numero1>numero3)+numero2*(numero2>numero1 & numero2>numero3)+numero3*(numero3>numero1&numero3>numero2);
    
}
int Menor(int numero1, int numero2, int numero3) {
    return numero1*(numero1<numero2 & numero1<numero3)+numero2*(numero2<numero1 & numero2<numero3)+numero3*(numero3<numero1&numero3<numero2);
}
void FilaEstrellas(int n) { 
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout<<std::endl;
}

void MatrizEstrellas(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void PiramideEstrellas(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void FlechaEstrellas(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    for (int i = n-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void Fibonacci(int n) {
    int n1=1,n2=1,next;
    for (int i = 1; i <= n; i++) {
        if(i == 1){
            std::cout << n1 << " ";
        }
        else if(i == 2){
            std::cout << n2 << " ";
        }
        else{
            next = n1 + n2;
            n1 = n2;
            n2 = next;
            std::cout << next << " ";
        }
    }
    std::cout<<std::endl;
}
bool EsPrimo(int numero) {
    for (int i=2; i<numero; i++){
		if (numero % i == 0){
			return false;
		}
	}
	return true;
    
}