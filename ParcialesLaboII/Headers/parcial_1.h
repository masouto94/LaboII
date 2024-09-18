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
            if (articleList[i].stock < amount) {
                printf("Insufficient stock %d to sell amount %d\n", articleList[i].stock, amount);
                return;
            }
            articleList[i].stock -= amount;
            articleList[i].quantitySold += amount;
        }
    }
    printf("No such article with productId %d exists\n", productId);
    return;
}
void readArticleFromFile(Article cursor, char * filePath) {
    Article * pReader = &cursor;
    FILE * res = fopen(filePath, "rb");
    fseek(res, 0, SEEK_END);
    int fileSize = ftell(res) / sizeof(Article);
    fseek(res, 0, SEEK_SET);
    for(int i = 1; i <= fileSize; i++) {
        fread(pReader, sizeof(Article), 1, res);
        printf("ProductId: %d\n", pReader->productId);
        printf("Name: %s\n", pReader->name);
        printf("Stock: %d\n", pReader->stock);
        printf("Quantity sold: %d\n", pReader->quantitySold);
    }
    fclose(res);
}

int loadArticlesFromFile(Article cursor, char * filePath, Article ** articleList) {
    Article * pReader = &cursor;
    Article * articlesCollector;
    FILE * resources = fopen(filePath, "rb");
    fseek(resources, 0, SEEK_END);
    int fileSize = ftell(resources) / sizeof(Article);
    fseek(resources, 0, SEEK_SET);
    articlesCollector = (Article *) realloc(*articleList, sizeof(Article) * fileSize);
    for(int i = 0; i < fileSize; i++) {
        fread(pReader, sizeof(Article), 1, resources);
        articlesCollector[i] = *pReader;
    }
    *articleList = articlesCollector;
    fclose(resources);
    return fileSize;
}

void printArticles(Article * articleList, int size) {
    for (int i = 0; i < size; i++) {
        printf("ProductId: %d\n", articleList[i].productId);
        printf("Name: %s\n", articleList[i].name);
        printf("Stock: %d\n", articleList[i].stock);
        printf("Quantity sold: %d\n", articleList[i].quantitySold);
    }
}

void loadArticlesLoop(){
    int size=1;
    int articles = size;
    int productId;
    char name[50];
    float price;
    int stock;
    int quantitySold;

    Article * articleVector = (Article *)malloc(sizeof(Article) * size);
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
        printf("Ingrese id del producto:\n");
        scanf("%d", &productId);
    }while (productId != 0);

    FILE * inventory = fopen("../resources/outputFiles/articles.dat", "wb");
    fwrite(articleVector, sizeof(Article), articles, inventory);
    fclose(inventory);
    return;
}
void parcial_1() {

    //loadArticlesLoop();
    Article reader;
    char * filePath = "../resources/outputFiles/articles.dat";
    //readArticleFromFile(reader, filePath);
    Article * articleVector = (Article *)malloc(sizeof(Article) * 1);
    int totalArticles = loadArticlesFromFile(reader, filePath, &articleVector);
    printArticles(articleVector, totalArticles);
    free(articleVector);
}