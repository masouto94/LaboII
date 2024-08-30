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
    printf("Nacionalidad: %s\n", persona.nationality);
}
Person loadPerson(char nombre[16], int edad, char genero, char nacionalidad[16]){
    Person newPerson;
    strcpy(newPerson.name, nombre);
    newPerson.age = edad;
    newPerson.gender= genero;
    strcpy(newPerson.nationality, nacionalidad);
    return newPerson;
}

Person createPerson(){
    char name[16];
    int age;
    char gender;
    char nationality[16];
    printf("Ingrese un nombre:\n");
    fgets(name, 16, stdin);
    printf("Ingrese la nacionalidad:\n");
    fgets(nationality, 16, stdin);
    printf("Ingrese la edad:\n");
    std::cin >> age;
    printf("Ingrese el genero:\n");
    std::cin >> gender;
    strtok(name, "\n");
    strtok(nationality, "\n");
    Person persona = loadPerson(name, age, gender, nationality);
    //printPerson(&persona);
    return persona;
}
