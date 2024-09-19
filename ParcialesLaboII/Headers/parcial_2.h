//
// Created by matias on 17/09/24.
//

#ifndef PARCIAL_2_H
#define PARCIAL_2_H

#endif //PARCIAL_2_H

typedef struct Farmaco {
    int productCode;
    char name[50];
    float price;
    int available;
    int sold;
}Farmaco;

void displayFarmaco(Farmaco farmaco) {
    printf("###########\n");
    printf("Codigo: %d\n", farmaco.productCode);
    printf("Nombre: %s\n", farmaco.name);
    printf("Precio: %.2f\n", farmaco.price);
    printf("Disponible: %d\n", farmaco.available);
    printf("Vendido: %d\n", farmaco.sold);
    printf("###########\n");
}

Farmaco createFarmaco(int productCode, char name[50], float price, int available, int sold) {
    Farmaco newFarmaco;
    newFarmaco.productCode = productCode;
    strcpy(newFarmaco.name, name);
    newFarmaco.price = price;
    newFarmaco.available = available;
    newFarmaco.sold = sold;
    return newFarmaco;
}
void addFarmacoToArray(Farmaco* farmacoArray, Farmaco farmaco, int index) {
    farmacoArray[index] = farmaco;
}
void sellFarmaco(Farmaco* farmacoArray,int size, int productCode, int amount) {
    for (int i = 0; i < size; i++) {
        if (farmacoArray[i].productCode == productCode) {
            if(farmacoArray[i].available < amount) {
                printf("Cantidad insuficiente (%d) para vender %d", farmacoArray[i].available, amount);
                return;
            }
            farmacoArray[i].sold += amount;
            farmacoArray[i].available -= amount;
            displayFarmaco(farmacoArray[i]);
            return;
        }
    }
    printf("No se encontro el producto %d\n", productCode);
}

void deleteFarmaco(Farmaco* farmacoArray, int productCode, int * size) {
   char confirm;
    for (int i = 0; i < *size; i++) {
        if (farmacoArray[i].productCode == productCode) {
            printf("Queres borrar el farmaco?: (y/n)\n");
            displayFarmaco(farmacoArray[i]);
            scanf("%c", &confirm);
            while(getchar() != '\n');
            if (confirm != 'Y' && confirm != 'y') {
                printf("Cancelado\n");
                return;
            }
            while(i < *size) {
                farmacoArray[i] = farmacoArray[i + 1];
                i++;
            };
            *size -=1;
            return;
        }
    }
}
void modifyFarmaco( Farmaco * farmacoArray, int size, int productCode) {
    char modify;
    for (int i = 0; i < size; i++) {
        if(farmacoArray[i].productCode == productCode) {
            printf("Quiere modificar el codigo? (y/n)\n");
            scanf("%c", &modify);
            while(getchar() != '\n');
            if(modify == 'y' || modify == 'Y') {
                int newCode;
                printf("Ingrese el nuevo codigo: \n");
                scanf("%d", &newCode);
                while(getchar() != '\n');
                farmacoArray[i].productCode = newCode;
            }
            printf("Quiere modificar el nombre? (y/n)\n");
            scanf("%c", &modify);
            while(getchar() != '\n');
            if(modify == 'y' || modify == 'Y') {
                char newName[50];
                printf("Ingrese el nuevo nombre: \n");
                fgets(newName, sizeof(newName), stdin);
                newName[strcspn(newName, "\n")] = '\0';
                strcpy(farmacoArray[i].name, newName);
            }
            printf("Quiere modificar el precio? (y/n)\n");
            scanf("%c", &modify);
            while(getchar() != '\n');
            if(modify == 'y' || modify == 'Y') {
                float newPrice;
                printf("Ingrese el nuevo precio: \n");
                scanf("%f", &newPrice);
                while(getchar() != '\n');
                farmacoArray[i].price = newPrice;
            }
            printf("Quiere modificar el stock? (y/n)\n");
            scanf("%c", &modify);
            while(getchar() != '\n');
            if(modify == 'y' || modify == 'Y') {
                int newStock;
                printf("Ingrese el nuevo stock: \n");
                scanf("%d", &newStock);
                while(getchar() != '\n');
                farmacoArray[i].available = newStock;
            }
            printf("Quiere modificar la cantidad vendida? (y/n)\n");
            scanf("%c", &modify);
            while(getchar() != '\n');
            if(modify == 'y' || modify == 'Y') {
                int newSoldQuantity;
                printf("Ingrese el nuevo valor: \n");
                scanf("%d", &newSoldQuantity);
                while(getchar() != '\n');
                farmacoArray[i].sold = newSoldQuantity;
            }
            displayFarmaco(farmacoArray[i]);
            return;
        }
    }
    printf("No se encontro el farmaco con el codigo %d\n", productCode);
}
float calculateSalesFarmaco(Farmaco * farmacoArray, int size) {
    float totalSales=0;
    for (int i = 0; i < size; i++) {
        totalSales += farmacoArray[i].sold * farmacoArray[i].price;
    }
    return totalSales;
}
void maxSalesFarmaco(Farmaco * farmacoArray, int size) {
    int maxSales=0;
    Farmaco maxFarmaco;
    for (int i = 0; i < size; i++) {
        if (farmacoArray[i].sold > maxSales) {
            maxSales = farmacoArray[i].sold;
            maxFarmaco = farmacoArray[i];
        }
    }
    if(maxSales == 0) {
        printf("No se vendio ningun farmaco\n");
        return;
    }
    printf("El maximo de sales es:\n");
    displayFarmaco(maxFarmaco);
}
void loadFarmacosLoop(char* fileName) {
    int productCode;
    char name[50];
    float price;
    int available;
    int sold;

    int arrSize = 1;
    int createdFarmaco = 0;
    Farmaco * farmacoArray = (Farmaco *) malloc(sizeof(Farmaco) * arrSize);
    if (farmacoArray == NULL) {
        printf("No se pudo alocar el array\n");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese el codigo del farmaco:\n");
    scanf("%d", &productCode);
    while(getchar() != '\n');
    do {
        printf("Ingrese el nombre del farmaco:\n");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("Ingrese el precio del farmaco:\n");
        scanf("%f", &price);
        while(getchar() != '\n');
        printf("Ingrese el stock del farmaco:\n");
        scanf("%d", &available);
        while(getchar() != '\n');
        printf("Ingrese la cantidad vendida hasta ahora:\n");
        scanf("%d", &sold);
        while(getchar() != '\n');
        Farmaco medicamento = createFarmaco(productCode, name, price, available, sold);
        createdFarmaco++;
        if(createdFarmaco > arrSize) {
            arrSize = createdFarmaco;
            farmacoArray = (Farmaco *) realloc(farmacoArray, sizeof(Farmaco) * arrSize);
            if (farmacoArray == NULL) {
                printf("No se pudo alocar el array\n");
                exit(EXIT_FAILURE);
            }
        }
        addFarmacoToArray(farmacoArray,medicamento,arrSize -1 );
        printf("Ingrese el codigo del farmaco:\n");
        scanf("%d", &productCode);
        while(getchar() != '\n');
    }
    while(productCode != 0);
    for(int i = 0; i < arrSize; i++) {
        displayFarmaco(farmacoArray[i]);
    }
    FILE *f = fopen(fileName, "wb");
    if (f == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    fwrite(farmacoArray, sizeof(Farmaco), arrSize, f);
    fclose(f);
}
void parcial_2() {
    char * filename = "../resources/outputFiles/farmacos_2.dat";
    loadFarmacosLoop(filename);
    FILE *f = fopen(filename, "rb");
    Farmaco farmaco;
    if (f == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    int farmacosAmount = size / sizeof(Farmaco);
    fseek(f, 0, SEEK_SET);
    Farmaco* farmacos = (Farmaco*)malloc(size);
    fread(&farmaco, sizeof(Farmaco), 1, f);
    for (int i = 0; i < farmacosAmount; i++) {
        farmacos[i] = farmaco;
        printf("INDEX: %d\n",i);
        displayFarmaco(farmacos[i]);
        fread(&farmaco, sizeof(Farmaco), 1, f);
    }
    // sellFarmaco(farmacos, farmacosAmount, 10000,400);
    // modifyFarmaco(farmacos, farmacosAmount,10001);
    //deleteFarmaco(farmacos, 10001, &farmacosAmount);
    for (int i = 0; i < farmacosAmount; i++) {
        displayFarmaco(farmacos[i]);
    }
    // printf("Las ventas totales fueron %.2f\n", calculateSalesFarmaco(farmacos, farmacosAmount));
    // maxSalesFarmaco(farmacos, farmacosAmount);
    free(farmacos);

}