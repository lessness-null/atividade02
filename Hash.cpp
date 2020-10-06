#include "Hash.h"
#include "No.h"
#include <cstddef>
#include <math.h>
#include <sstream>

Hash::Hash() {}
Hash::~Hash() {}

int Hash::hash_div(int val)
{
    return val % M;
}

int Hash::hash_mult(int val)
{
    float A = (sqrt(5)-1)/2;
    float kA = A*val;
    float ipart;
    float modkA = modf(kA, &ipart);
    return floor(M*modkA);
}

int Hash::minha_hash(int val)
{
    int quad = val * val;
    std::stringstream ss;
    ss << quad;
    std::string s;
    ss >> s;
    char n[3];
    int i = s.size()/2;
    n[0] = s[i-1];
    n[1] = s[i];
    n[2] = s[i+1];
    int num = atoi(n);
    return hash_div(num);
}

void Hash::create(int tam, int x)
{
    M = tam;
    h = x;
    col = 0;
    tab = new No*[M];
    for(int i = 0; i < M; ++i)
        tab[i] = NULL;
}

No* Hash::insert(int val)
{
    No *novo = new No();
    novo->setInfo(val);
    novo->setProx(NULL);

    int i;
    switch(h)
    {
    case 1:
        i = hash_div(val);
        break;
    case 2:
        i = hash_mult(val);;
        break;
    case 3:
        i = minha_hash(val);
        break;
    }
    if(tab[i] != NULL)
    {
        col++;
        No *aux = tab[i];
        while(aux->getProx() != NULL)
        {
            aux = aux->getProx();
        }
        aux->setProx(novo);
        return aux->getProx();
    }
    else
    {
        tab[i] = novo;
        return tab[i];
    }
}

No* Hash::lookup(int val)
{
    int i;
    switch(h)
    {
    case 1:
        i = hash_div(val);
        break;
    case 2:
        i = hash_mult(val);;
        break;
    case 3:
        i = minha_hash(val);
        break;
    }
    No *aux = tab[i];
    while(aux != NULL)
    {
        if(aux->getInfo() == val)
        {
            return aux;
        }
        aux = aux->getProx();
    }
    return NULL;
}

void Hash::destroy()
{
    No *aux;
    No *d;
    for(int i = 0; i < M; ++i)
    {
        aux = tab[i];
        tab[i] = NULL;
        while(aux != NULL)
        {
            d = aux;
            aux = aux->getProx();
            delete d;
        }
    }
    delete [] tab;
}

int Hash::getCol()
{
    return col;
}
