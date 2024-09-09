//
// Created by matias on 09/09/24.
//

#ifndef PERSON_H
#define PERSON_H

#endif //PERSON_H

typedef struct Person{
    char name[16];
    int age;
    char gender;
    char nationality[16];
}Person;

void printPerson(Person *persona){
    printf("Nombre: %s\n", persona->name);
    printf("Edad: %d\n", persona->age);
    printf("Genero: %c\n", persona->gender);
    printf("Nacionalidad: %s\n", persona->nationality);
}

void printPersonValue(Person persona){
    printf("Nombre: %s\n", persona.name);
    printf("Edad: %d\n", persona.age);
    printf("Genero: %c\n", persona.gender);
}
Person loadPerson(char nombre[16], int edad, char genero, char nacionalidad[16]){
    Person newPerson;
    strcpy(newPerson.name, nombre);
    newPerson.age = edad;
    newPerson.gender= genero;
    strcpy(newPerson.nationality, nacionalidad);
    return newPerson;
}

Person createPerson() {
    char name[16];
    int age;
    char gender;
    char nationality[16];

    printf("Ingrese un nombre:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Ingrese la edad:\n");
    scanf("%d", &age);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    printf("Ingrese el genero:\n");
    scanf("%c", &gender);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    printf("Ingrese la Nacionalidad:\n");
    fgets(nationality, sizeof(nationality), stdin);
    nationality[strcspn(nationality, "\n")] = '\0';

    Person persona = loadPerson(name, age, gender,nationality);
    return persona;
}