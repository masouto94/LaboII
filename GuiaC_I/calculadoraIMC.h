#include <cmath>

float calcularIMC(float peso, float altura){
    return peso / pow(altura,2);
}

//probando usar string
std::string categoriaIMC(float valorIMC){
    if (valorIMC < 18.5){
        return "Peso bajo";
    }
    else if((valorIMC >= 18.5) && (valorIMC < 25) ){
        return "Normal";
    }
    else if((valorIMC >= 25) && (valorIMC < 30) ){
        return "Sobrepeso";
    }
    return "Obesidad";
}

void calculadoraIMC(){
    float peso,altura;
    printf("Para calcular el IMC se tiene que dividir el peso por el cuadrado de la altura\n");
    printf("############\n");
    printf("Ingrese el peso en kilos:\n");
    std::cin >> peso;
    printf("Ingrese la altura en metros:\n");
    std::cin >> altura;
    float imc = calcularIMC(peso,altura);
    //Funciona solo si se usa std::cout en vez de printf
    std::cout << "El IMC para esos valores es " <<imc << ". Lo que es categoria " << categoriaIMC(imc);


}
