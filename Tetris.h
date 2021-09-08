/*
    Trabalho 2 Estruturas de Dados
    Para de Minas 07/09/2021
    Felipe Pereira Ferereira
*/

#include <iomanip>
#include <iostream>

enum TipoPeca
{
    TipoI = 0,
    TipoJ = 4,
    TipoL = 8,
    TipoO = 12,
    TipoS = 16,
    TipoT = 20,
    TipoZ = 24
};

class Peca
{
private:
    ///Guarda a peca em si, e a disposicao dos elementos
    char **peca;
    ///Guarda o numero de colunas da peca
    int numColunas;
    ///Guarda o numero de linhas da peca
    int numLinhas;

public:
    //* Construtor e destrutor da classe

    
    Peca();
    Peca(const Peca &other);
    ~Peca();

    //* Getters

    /// Funcao que retorna o numero de colunas de cada peca
    const int getNumColunas() const;
    /// Funcao que retorna o numero de linhas de cada peca
    const int getNumLinhas() const;
    /// Funcao que retorna o caracter em determinada posicao da peca
    const char getPecaChar(const int &coluna, const int &linha) const;
    /// Funcao que printa a Peca 
    void printPeca() const;
    /// Funcao para setar as pecas
    void setPeca(const char pecaExemplo[4][4], const int &colunas, const int &linhas);
};

class Tetris
{
private:
    ///Ponteiro de ponteiro para guardar o estado do jogo e a disposicao dos caracteres
    char **jogo;
    ///Ponteiro para guardar as alturas de cada coluna
    int *alturas;
    /// inteiro que guarda o a lagura (numero de colunas) da matriz do jogo
    int numColunas;
    ///Vetor que possui todas as pecas usadas no jogo, e cridado na seguinte ordem I,J,L,O,S,T,Z cada uma com as rotacoes em sequencia
    Peca pecas[28];

    //* Funcoes de uso privado da classe
    ///Retornar a menor altura das colunas
    unsigned int getMenorAltura() const;
    ///Retorna a maior altura das colunas
    unsigned int getMaiorAltura() const;
    ///Fucao que remove uma linha dos arrays do jogo
    void removeLinha(const int &linhaARemover);
    ///Fucao que remove um elemento de cada array
    void removeElemento(const int &posRemover, const int &indiceColuna);
    ///Funcao que retorna o tipo de peca ser inserida
    TipoPeca decodePeca(const char id) const;
    ///Funcao que ira criar o vetor de pecas
    void criaVetorPecas();

public:
    //* Construtor e Destrutor da Classe
    /// Consturtor que aloca dinamicamente a matriz com base no numero de colunas, ele tambem inicializa todos os valores
    Tetris(const int &numeroDeColunas);
    ~Tetris();

    //*Funcoes para Facilitar o desenvolvimento do Programa
    //Funcao que imprime o estado atual do jogo
    void printMatrix() const;
    /// Funcao que imprime todo o vetor de pecas
    void printVetorPecas() const;


    //* Fucoes de uso do programa

    /// Funcao que retorna o character da matriz jogo
    const char get(const int &coluna, const int &linha) const;
    ///Funcao que dado um indice, remove uma coluna da matriz
    void removeColuna(const int &numColuna);
    ///Funcao que remove linhas que estejam completas e nao possuem espacos
    void removeLinhasCompletas();
    ///Funcao que retorna o numero atual de colunas no jogo
    const int getNumColunas() const;
    /// Funcao que retorna a altura de uma coluna em especifico
    unsigned int getAltura(const int &indiceColuna) const;
    /// Funcao que retornar a altura maxima do jogo
    unsigned int getAltura() const;
    ///Funcao que tenta adicionar as pessas na tela atual, retorna false caso nao seja possivel colocar
    bool adicionaForma(const int coluna, const int linha, const char id, const int rotacao);
};
