#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
/* TO USE WITH LINUX IN PLACE OF INTRIN.H
UNCOMMENT TO USE
*/
//#include <immintrin.h>
//#include <ammintrin.h>

void func1(){
    int x, y, z;

    y = 3;
    z = 4;
    x = y+z;
}

int func2(){
    int x, y, z;

    y = 3;
    z = 4;
    x = y+z;

    return x;
}

char func3(char param){
    char x, y, z;
    if(param = 'a'){
        y = 3;
        z = 4;
        x = y+z;
    }else{
        y = 5;
        z = 5;
        x = y+z;
    }
    if(x == 10){
        return 'a';
    }else{
        return 'b';
    }
}


void func4(float param){
    printf("\n The parameter is: %.2f", param);
}

short func5(){
    int temp_param;
    printf("\nValue to temp_param will be 15: ");
    temp_param = 15;

    return ((short)temp_param);

}

int main(){

    clock_t start, finish; //os nomes das variaveis são alterados para evitar conflito
    double time_spent;

    char param_1 = 'b';
    short param_2;
    int param_3;
    float param_4 = 50.0;
    uint64_t begin, end;

    //for(int i=0; i<100; i++){ //Implementação do laço de 100 repetições. Para executar o exercício 2, retire a notação de comentário.

        //start = clock();
        //for(int i = 0; i < 100; i++){
            func1();
        //}
        //finish = clock();
        //time_spent = ((double)(finish - start)) / CLOCKS_PER_SEC; //Caso queira retirar o benchmark, deve por as linhas em comentario, deixando apenas as funções.
        //printf("\nTime taken by func1: %.12f\n", time_spent);

        //start = clock();
        //for(int i = 0; i < 100; i++){
            param_3 = func2();
        //}
        //finish = clock();
        //time_spent = ((double)(finish - start)) / CLOCKS_PER_SEC;
        //printf("\nTime taken by func2: %.12f\n", time_spent);

        //start = clock();
        //for(int i = 0; i < 100; i++){
            func3(param_1);
        //}
        //finish = clock();
        //time_spent = ((double)(finish - start)) / CLOCKS_PER_SEC;
        //printf("\nTime taken by func3: %.12f\n", time_spent);

        //start = clock();
        //(int i = 0; i < 100; i++){
            func4(param_4);
        //}
        //finish = clock();
        //time_spent = ((double)(finish - start)) / CLOCKS_PER_SEC;
        //printf("\nTime taken by func4: %.12f\n", time_spent);

        //start = clock();
        //for(int i = 0; i < 100; i++){
            param_2 = func5();
        //}
        //finish = clock();
        //time_spent = ((double)(finish - start)) / CLOCKS_PER_SEC;
        //printf("\nTime taken by func5: %.12f\n", time_spent);

    //}
}
