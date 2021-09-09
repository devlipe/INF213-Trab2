#include "Tetris.h"

int main(int argc, char const *argv[])
{
    Tetris a(7);
    a.adicionaForma(4, 0, 'I', 90); 
    

    Tetris b;

    b = a;
    return 0;
}
