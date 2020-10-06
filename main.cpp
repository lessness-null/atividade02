#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <math.h>
#include <Hash.h>
#include <No.h>

using namespace std;

int* vetor(int tam) {
    int *vet = new int[tam];
    srand(time(0));
    for(int i = 0; i < tam; ++i)
        vet[i] = 1000 +(rand()%(9999-1000+1));
    return vet;
}

void imprime_vet(int vet[], int tam) {
    for(int i = 0; i < tam; ++i) {
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main()
{
    //1 = método da divisão
    //2 = método da multiplicação
    //3 = método do meio-quadrado
    int M = 200;
    int *vet = vetor(M*2);
    Hash ha;
    ha.create(M, 1);
    No *p;
    for(int i = 0; i < M*2; ++i) {
        p = ha.insert(vet[i]);
    }
    cout << "Colisoes do metodo da divisao = " << ha.getCol() << endl << endl;
    ha.destroy();
    ha.create(M, 2);
    for(int i = 0; i < M; ++i) {
        p = ha.insert(vet[i]);
    }
    cout << "Colisoes do metodo da multiplicacao = " << ha.getCol() << endl << endl;
    ha.destroy();
    ha.create(M, 3);
    for(int i = 0; i < M; ++i) {
        p = ha.insert(vet[i]);
    }
    cout << "Colisoes do metodo do meio-quadrado = " << ha.getCol() << endl << endl;
    ha.destroy();
    return 0;
}
