#include "persona.h"

void printPeopleArray(Person* peopleArray, int maxSize){
    for(int i=0; i < maxSize;i++){
        printPerson(&peopleArray[i]);
    }
}
void createPeople(){
    int MAX_SIZE = 2;
    Person people[MAX_SIZE];
    for(int i=0; i < MAX_SIZE; i++){
        people[i] = createPerson();
    }
    printPeopleArray(people, MAX_SIZE);
}
