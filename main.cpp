#include "Tetris.h"


int main(int argc, char const *argv[])
{
    Tetris a(5);
    a.printVetorPecas();
    a.adicionaForma(0, 0, 'T', 90);
    a.adicionaForma(0, 0, 'O', 270);
    a.adicionaForma(0, 0, 'S', 0);
    a.adicionaForma(0, 0, 'L', 180);
    return 0;
}
