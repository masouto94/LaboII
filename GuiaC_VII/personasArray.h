#include "persona.h"

void printPeopleArray(Person* peopleArray, int maxSize){
    for(int i=0; i < maxSize;i++){
        printf("####################\n");
        printPerson(&peopleArray[i]);
        printf("####################\n");
    }
}
float getAverage(Person* peopleArray, int maxSize){
    float average=0;
    if(maxSize < 1){
        return 0;
    }
    for(int i=0; i < maxSize;i++){
        average += peopleArray[i].age;
    }
    return average / maxSize;
}


void deletePerson(Person * peopleArray,  int deleteId, int * currentSize){
    for (int i = deleteId; i < *currentSize- 1; i++) {
    strcpy(peopleArray[i].name, peopleArray[i + 1].name);
    peopleArray[i].age = peopleArray[i + 1].age;
    peopleArray[i].gender = peopleArray[i + 1].gender;
        }
    (*currentSize)--;
}


void sortPeopleArray(Person * peopleArray, int * currentSize,int critheria){
    bool comparison=false;

    for (int globalIteration = 0; globalIteration < *currentSize - 1; globalIteration++){
    //Para cada elemento del array hasta el global -1
    //cada vez que corre, se fija si el elemento X y el X+1 cumplen la condicion
        for (int position = 0; position < *currentSize - globalIteration - 1; position++){
            switch(critheria){
                case 0:
                    comparison = peopleArray[position].age > peopleArray[position + 1].age;
                    break;
                case 1:
                    comparison = strlen(peopleArray[position].name) > strlen(peopleArray[position + 1].name);
                    break;
                case 2:
                    comparison = (int)peopleArray[position].gender > (int )peopleArray[position + 1].gender;
                    break;
                default:
                    break;
                }
            if (comparison){
            //Si se cumple que el de la izquierda es mayor que el de la derecha, los swapea
                std::swap(peopleArray[position], peopleArray[position + 1]);
            }
        }
    }
};

void createPeople(){
    Person alama = loadPerson("alama", 22, 'f');
    Person nanasa = loadPerson("nanasa", 26, 'f');
    Person alf = loadPerson("alf", 30, 'm');
    Person saracustica = loadPerson("saracustica", 19, 'f');
    int MAX_SIZE = 4;
    int currentSize = 0;
    int * currentSize_p = &currentSize;
// Cuando le paso las personas creadas en el programa, funciona.
//    Person people[MAX_SIZE] = {alama,nanasa,alf,saracustica};
//    currentSize = 4;
    Person people[MAX_SIZE];
    for(int i=0; i < MAX_SIZE; i++){
        people[i] = createPerson();
        currentSize++;
    }
    //printf("%f\n",getAverage(people, MAX_SIZE));
//    printPeopleArray(people,currentSize);
//    printf("####################\n");
//    printf("####################\n");
//    deletePerson(people, 2,currentSize_p);
//    printPeopleArray(people,currentSize);
    //sortPeopleArray(people, currentSize_p,1);
    printPeopleArray(people,currentSize);
}
