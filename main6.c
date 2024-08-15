#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Variáveis globais para controle
sem_t sem_autoriza;
int contador_autorizacoes = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void autoriza(void) {
    pthread_mutex_lock(&mutex);
    contador_autorizacoes++;
    if (contador_autorizacoes >= 3) {
        sem_post(&sem_autoriza);  // Libera uma tarefa "mostra"
        contador_autorizacoes -= 3;
    }
    pthread_mutex_unlock(&mutex);
}

void espera_3_autorizacoes(void) {
    sem_wait(&sem_autoriza);
}

void* func1(void* arg) {
    int x, y, z;
    y = 3;
    z = 4;
    x = y + z;

    autoriza();  // Autoriza após o cálculo
    return NULL;
}

void* func2(void* arg) {
    int x, y, z;
    y = 3;
    z = 4;
    x = y + z;

    autoriza();  // Autoriza após o cálculo
    return NULL;
}

void* func3(void* arg) {
    char param = *((char*)arg);
    char x, y, z;

    if (param == 'a') {
        y = 3;
        z = 4;
        x = y + z;
    } else {
        y = 5;
        z = 5;
        x = y + z;
    }

    autoriza();  // Autoriza após o cálculo
    return NULL;
}

void* func4(void* arg) {
    float param = *((float*)arg);
    espera_3_autorizacoes();  // Espera 3 autorizações
    printf("\nThe parameter is: %.2f", param);
    return NULL;
}

void* func5(void* arg) {
    espera_3_autorizacoes();  // Espera 3 autorizações
    int temp_param = 15;
    printf("\nValue to temp_param will be 15");
    return NULL;
}

int main() {
    // Inicializa o semáforo com valor 0, indicando que nenhuma tarefa "mostra" pode executar no início
    sem_init(&sem_autoriza, 0, 0);

    pthread_t threads[5];

    char param_1 = 'b';
    float param_4 = 50.0;

    pthread_create(&threads[0], NULL, func1, NULL);
    pthread_create(&threads[1], NULL, func2, NULL);
    pthread_create(&threads[2], NULL, func3, &param_1);
    pthread_create(&threads[3], NULL, func4, &param_4);
    pthread_create(&threads[4], NULL, func5, NULL);

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_autoriza);
    pthread_mutex_destroy(&mutex);

    return 0;
}
