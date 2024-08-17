int sumar(int *vector_ , size_t vectorSize){
    int suma=0;
    for(int i=0; i < vectorSize; i++){
        suma += vector_[i];
    }
    return suma;
}
void sumaVector(){
    int  v[] = {1,1,1,1,1,1,1,1,1,1};
    size_t v_size = sizeof(v)/ sizeof(v[0]);
    printf("La suma del vector es %d", sumar((int*)&v, v_size));
}
