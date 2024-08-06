// Si se corre en windows incluir esta
//#include <windows.h>
// Si se corre en linux incluir esta
#include <unistd.h>

void cuentaRegresiva(){
    int periodo;
    printf("Ingrese el periodo\n");
    std::cin >> periodo;
    for(int i=0; i < periodo; i++){
        printf("############\n");
        printf("%d\n",periodo - i);
        printf("############\n");
        sleep(1);
    }
    printf("DESPEGUE!");
}

