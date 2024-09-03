typedef struct Person{
    char name[16];
    int age;
    char gender;
}Person;

void printPerson(Person *persona){
    printf("Nombre: %s\n", persona->name);
    printf("Edad: %d\n", persona->age);
    printf("Genero: %c\n", persona->gender);
}

void printPersonValue(Person persona){
    printf("Nombre: %s\n", persona.name);
    printf("Edad: %d\n", persona.age);
    printf("Genero: %c\n", persona.gender);
}
Person loadPerson(char nombre[16], int edad, char genero){
    Person newPerson;
    strcpy(newPerson.name, nombre);
    newPerson.age = edad;
    newPerson.gender= genero;
    return newPerson;
}

Person createPerson() {
    char name[16];
    int age;
    char gender;

    printf("Ingrese un nombre:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Ingrese la edad:\n");
    scanf("%d", &age);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    printf("Ingrese el genero:\n");
    scanf("%c", &gender);
    while (getchar() != '\n'); // Limpia el buffer de entrada

    Person persona = loadPerson(name, age, gender);
    return persona;
}
