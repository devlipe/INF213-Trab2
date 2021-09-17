/*
    Trabalho 2 Estruturas de Dados
    Para de Minas 07/09/2021
    Felipe Pereira Ferereira
*/

#include <iomanip>
#include <iostream>

/// Enumerado de tipos de pecas, ele pemite que encontremos a peca no vetor de pecas de forma mais rapida
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

    //* Funcoes de uso privado da classe
    //Funcao que cria uma peca vazia
    void create();
    //Funcao que destroi uma peca
    void destroy();
    //Fucao que destroi e depois cria uma peca
    void clear();

public:
    //* Construtor e destrutor da classe

    Peca();
    //Construtor de copia
    Peca(const Peca &other);
    ~Peca();

    //* Operadores

    Peca &operator=(const Peca &other);

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
    //Funcao que cria um vazio
    void create();
    //Funcao que destroi um Jogo
    void destroy();
    //Fucao que destroi e depois cria um Jogo
    void clear();
    ///Fucao que verifica se podemos inserir a peca (retorna true se a peca pode ser inserida)
    bool verificaInsercao(const Peca &peca, const int &coluna, const int &linha);
    ///Funcao que verifica se a peca nao ultrapassa os limites do jogo (retorna true se a peca ultrapassa limites)
    bool ultrapassaLimites(const Peca &peca, const int &coluna, const int &linha);
    //Funcao que verifica se a peca nao intercepta outras pecas (retorna true se a peca intecepta outras pecas)
    bool interceptaPecas(const Peca &peca, const int &coluna, const int &linha);
    /// Fucao que insere uma peca em determinada posicao
    void inserePeca(const Peca &peca, const int &coluna, const int &linha);
    /// Fuacao que faz o resizes nas colunas para permitir que novas pecas sejam colocadas no tabuleiro
    void resizeColuna(const int &indiceColuna, const int &novaAltura);
    ///Funcao que ira remover os espacos brancos inuteis das coluas 
    void removeEspacos();
    ///Funcao que remove um elemento do vetor de alturas
    void removeAltura(const int &posAltura);

public:
    //* Construtor e Destrutor da Classe

    /// Consturtor que aloca dinamicamente a matriz com base no numero de colunas, ele tambem inicializa todos os valores
    Tetris(const int &numeroDeColunas);
    ///Construtor default da classe Tetris
    Tetris();
    ///Construtor de Copia
    Tetris(const Tetris &other);
    ~Tetris();

    //* Operadores

    Tetris &operator=(const Tetris &other);

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
    bool adicionaForma(const int &coluna, const int &linha, const char &id, const int &rotacao);
};
