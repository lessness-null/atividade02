#ifndef HASH_H
#define HASH_H
#include <No.h>


class Hash
{
public:
    Hash();
    ~Hash();
    void create(int tam, int x);
    No* insert(int val);
    No* lookup(int val);
    void destroy();
    int getCol();


private:
    No **tab;
    int M;
    int col;
    int h;
    int hash_div(int val);
    int hash_mult(int val);
    int minha_hash(int val);
};

#endif // HASH_H
