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

void deleteArticle(Article *articleList,  int * size, int productId) {
    char confirm = 'n';
    for (int i = 0; i < *size; i++) {
        if (articleList[i].productId == productId) {
            do {
                printf("Desea borrar:\n");
                printf("Product Id: %d => %s\n", articleList[i].productId,articleList[i].name);
                scanf("%c", &confirm);
                while (getchar() != '\n');
            }while(confirm != 'n' && confirm != 'N' && confirm != 'y' && confirm != 'Y' );
            if (confirm == 'n' || confirm == 'N') {
                printf("Process aborted\n");
                return;
            }
            while(i < *size) {
                articleList[i].productId = articleList[i+1].productId;
                strcpy(articleList[i].name, articleList[i+1].name);
                articleList[i].price = articleList[i+1].price;
                articleList[i].stock = articleList[i+1].stock;
                articleList[i].quantitySold = articleList[i+1].quantitySold;
                i++;
            }
            *size -= 1;
            return;
        }
        printf("Product Id: %d Not Found\n", productId);
    }
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
            return;
        }
    }
    printf("No such article with productId %d exists\n", productId);
}
void modifyArticle(Article *articleList, int size, const int productId) {
    char name[20];
    float price;
    int stock;
    int quantitySold;
    char modify = 'n';
    for (int i = 0; i < size; i++) {
        if (articleList[i].productId == productId) {
            printf("Modifying article with productId %d\n", articleList[i].productId);
            printf("Modify name? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Enter name: \n");
                fgets(name, sizeof(name), stdin);
                strcpy(articleList[i].name, name);
            }
            printf("Modify price? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Enter price: \n");
                scanf("%f", &price);
                articleList[i].price = price;
            }
            printf("Modify stock? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Enter stock: \n");
                scanf("%d", &stock);
                articleList[i].stock = stock;
            }
            printf("Modify sales amount? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Enter quantity sold: \n");
                scanf("%d", &quantitySold);
                articleList[i].quantitySold = quantitySold;
            }
            return;
        }
        printf("No such article with productId %d exists\n", productId);
    }
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
float calculateSales(Article * articleList, int size) {
    float totalSales = 0;
    for (int i = 0; i < size; i++) {
        totalSales += articleList[i].quantitySold * articleList[i].price;
    }
    return totalSales;
}

int loadArticlesFromFile(char * filePath, Article ** articleList) {
    Article cursor;
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
        printf("Name: %.2f\n", articleList[i].price);
        printf("Stock: %d\n", articleList[i].stock);
        printf("Quantity sold: %d\n", articleList[i].quantitySold);
    }
}

void saveArticlesToTxt(Article * articleList, int size, FILE * file) {
    for (int i = 0; i < size; i++) {
        fprintf(file,"##########\n");
        fprintf(file,"ProductId: %d\n", articleList[i].productId);
        fprintf(file,"Name: %s\n", articleList[i].name);
        fprintf(file,"Name: %.2f\n", articleList[i].price);
        fprintf(file,"Stock: %d\n", articleList[i].stock);
        fprintf(file,"Quantity sold: %d\n", articleList[i].quantitySold);
        fprintf(file, "##########\n");
    }
}

void loadArticlesLoop(char * filePath){
    int size=1;
    int articles = 0;
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

    FILE * inventory = fopen(filePath, "wb");
    fwrite(articleVector, sizeof(Article), articles, inventory);
    fclose(inventory);
}
void parcial_1() {

    char * filePath = "../resources/outputFiles/articles.dat";
    // loadArticlesLoop(filePath);
    //readArticleFromFile(reader, filePath);
    Article * articleVector = (Article *)malloc(sizeof(Article) * 1);
    int totalArticles = loadArticlesFromFile(filePath, &articleVector);
    // sellArticle(articleVector,totalArticles,1,1);
    // sellArticle(articleVector,totalArticles,2,100);
    // deleteArticle(articleVector, &totalArticles, 33);
    printArticles(articleVector, totalArticles);
    float sales=calculateSales(articleVector, totalArticles);
    printf("Sales: %f\n", sales);
    FILE * textFile = fopen("../resources/outputFiles/articles.txt", "w+");
    saveArticlesToTxt(articleVector, totalArticles, textFile);
    free(articleVector);

}