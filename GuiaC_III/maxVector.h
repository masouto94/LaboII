
int getMax(int *vector_ , size_t vectorSize){
    int maximo=0;
    for(int i=0; i < vectorSize; i++){
        if(vector_[i] > maximo){
            maximo = vector_[i];
        }
    }
    return maximo;
}
void maxVector(){
    int  v[] = {1,12,312,13,213,11,23131231,1,1,1};
    size_t v_size = sizeof(v)/ sizeof(v[0]);
    printf("La el maximo del vector es %d", getMax((int*)&v, v_size));
}
