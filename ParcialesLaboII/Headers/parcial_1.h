//
// Created by matias on 17/09/24.
//

#ifndef PARCIAL_1_H
#define PARCIAL_1_H

#endif //PARCIAL_1_H

/*
Lucı́a y Juan necesitan controlar el inventario de su supermercado, por lo que
deciden solicitar a la unsam que desarrollen un programa de gestion que tenga
las siguientes funciones dentro de un menú que las contenga, asegurándose de
incluir una opción para finalizar el programa. Como dato importante, acuerdan
definir una estructura para el inventario.
*/

typedef struct Article {
    int productId;
    char name[50];
    float price;
    int stock;
    int quantitySold;
} Article;

void addArticle(Article article,Article *articleList, const int index) {
    articleList[index] = article;
}
Article createArticle(int productId, char name[50], float price, int stock, int quantitySold) {
    Article newArticle;
    newArticle.productId = productId;
    strcpy(newArticle.name, name);
    newArticle.price = price;
    newArticle.stock = stock;
    newArticle.quantitySold = quantitySold;
    return newArticle;
}
void sellArticle(Article *articleList, int size, const int productId, int amount) {
    for (int i = 0; i < size; i++) {
        if (articleList[i].productId == productId) {
            if (articleList[i].stock >= amount) {
                articleList[i].stock -= amount;
                articleList[i].quantitySold += amount;
            }
            printf("Insufficient stock %d to sell amount %d", articleList[i].stock, amount);
            return;
        }
    }
    printf("No such article with productId %d exists\n", productId);
    return;
}
void parcial_1() {
    int size=1;
    int articles = 0;
    int productId;
    char name[50];
    float price;
    int stock;
    int quantitySold;

    Article * articleVector = (Article *)malloc(sizeof(Article) * size);
    //articleVector[0] = notebook;
     printf("Ingrese id del producto:\n");
     scanf("%d", &productId);
     do {
        while(getchar()!='\n');
         printf("Ingrese nombre del article:\n");
         fgets(name,sizeof(name),stdin);
         name[strcspn(name,"\n")] = '\0';
         printf("Ingrese el price del article:\n");
         scanf("%f", &price);
         while(getchar()!='\n');
         printf("Ingrese el stock del article:\n");
         scanf("%d", &stock);
         while(getchar()!='\n');
         printf("Ingrese el quantity del article:\n");
         scanf("%d", &quantitySold);
         while(getchar()!='\n');
         Article newArticle = createArticle(productId, name, price, stock, quantitySold);
         articles++;
         if (articles > size) {
             size = articles;
             articleVector = (Article *)realloc(articleVector, size * sizeof(Article));
         }
         addArticle(newArticle, articleVector, size-1);
        // Article notebook = createArticle(1, "notebook", 100, 10, 1);
        // Article book = createArticle(2, "book", 200, 20, 20);
         printf("Ingrese id del producto:\n");
         scanf("%d", &productId);
    }while (productId != 0);

    sellArticle(articleVector,size,1,3);
    for(int i = 0; i < articles; i++) {
        printf("Vector %s\n", articleVector[i].name);
        printf("Vector %d\n", articleVector[i].productId);
        printf("Vector %d\n", articleVector[i].stock);
        printf("Vector %d\n", articleVector[i].quantitySold);
    }
    free(articleVector);
}