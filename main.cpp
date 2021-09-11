#include "Tetris.h"

int main(int argc, char const *argv[])
{
    Tetris a(4);
    Tetris b;

    int coluna = 0;
    int linha = 0;
    char Tipo = ' ';
    int rotacao = 0;

    // while (true)
    // {
    //     std::cin >> coluna >> linha >> Tipo >> rotacao;
    //     if (Tipo == 'Q')
    //     {
    //         return 0;
    //     }

    //     std::cout << a.adicionaForma(coluna, linha, Tipo, rotacao);
    //     b = a;
    //     b.printMatrix();
    //     b.removeLinhasCompletas();
    //     b.printMatrix();
    // }

    std::cout << a.adicionaForma(0, 0, 'I', 90);
    std::cout << a.adicionaForma(0, 5, 'I', 0);
    std::cout << a.adicionaForma(1, 5, 'I', 0);
    a.printMatrix();
    std::cout << a.adicionaForma(2, 5, 'I', 0);
    a.removeColuna(2);

    a.printMatrix();

   

    b = a;
    b.printMatrix();
    b.removeLinhasCompletas();
    b.printMatrix();

    return 0;
}
