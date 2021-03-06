#include "Tetris.h"

Tetris::Tetris(const int &numeroDeColunas)
{
    //Assinalando e alocando dinamicamente as variaveis
    this->numColunas = numeroDeColunas;
    alturas = new int[numeroDeColunas];

    jogo = new char *[numeroDeColunas];
    for (int i = 0; i < numeroDeColunas; i++)
    {
        jogo[i] = new char[0];

        //Inicializando o vetor de alturas
        alturas[i] = 0;
    }
    criaVetorPecas();
}

Tetris::~Tetris()
{
    for (int i = 0; i < numColunas; i++)
    {
        delete[] jogo[i];
    }
    delete[] jogo;
    delete[] alturas;
}

Peca::Peca()
{
    numColunas = 0;
    numLinhas = 0;
    peca = nullptr;
}

Peca::Peca(const Peca &other)
{
    numColunas = other.numColunas;
    numLinhas = other.numLinhas;

    this->peca = new char *[other.numColunas];

    for (int i = 0; i < other.numColunas; i++)
    {
        peca[i] = new char[other.numLinhas];
    }

    for (int coluna = 0; coluna < other.numColunas; coluna++)
    {
        for (int linha = 0; linha < other.numLinhas; linha++)
        {
            peca[coluna][linha] = other.peca[coluna][linha];
        }
    }
    std::cout << "Construtor de Copia chamado" << std::endl;
}

void Peca::setPeca(const char pecaExemplo[4][4], const int &colunas, const int &linhas)
{
    numColunas = colunas;
    numLinhas = linhas;
    peca = new char *[colunas];

    for (int i = 0; i < colunas; i++)
    {
        peca[i] = new char[linhas];
    }

    for (int coluna = 0; coluna < colunas; coluna++)
    {
        for (int linha = 0; linha < linhas; linha++)
        {
            peca[coluna][linha] = pecaExemplo[linha][coluna];
        }
    }
}

Peca::~Peca()
{
    for (int i = 0; i < numColunas; i++)
    {
        delete[] peca[i];
    }

    delete[] peca;
}

void Tetris::criaVetorPecas()
{
    //* Criacao da Peca I
    char pecaI_0_180[4][4] = {{'I', ' ', ' ', ' '}, {'I', ' ', ' ', ' '}, {'I', ' ', ' ', ' '}, {'I', ' ', ' ', ' '}};
    pecas[0].setPeca(pecaI_0_180, 1, 4);
    char pecaI_90_270[4][4] = {{'I', 'I', 'I', 'I'}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[1].setPeca(pecaI_90_270, 4, 1);
    pecas[2].setPeca(pecaI_0_180, 1, 4);
    pecas[3].setPeca(pecaI_90_270, 4, 1);

    //* Criacao da Peca J
    char pecaJ_0[4][4] = {{'J', 'J', 'J', 'J'}, {' ', ' ', ' ', 'J'}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[4].setPeca(pecaJ_0, 4, 2);
    char pecaJ_90[4][4] = {{' ', 'J', ' ', ' '}, {' ', 'J', ' ', ' '}, {' ', 'J', ' ', ' '}, {'J', 'J', ' ', ' '}};
    pecas[5].setPeca(pecaJ_90, 2, 4);
    char pecaJ_180[4][4] = {{'J', ' ', ' ', ' '}, {'J', 'J', 'J', 'J'}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[6].setPeca(pecaJ_180, 4, 2);
    char pecaJ_270[4][4] = {{'J', 'J', ' ', ' '}, {'J', ' ', ' ', ' '}, {'J', ' ', ' ', ' '}, {'J', ' ', ' ', ' '}};
    pecas[7].setPeca(pecaJ_270, 2, 4);

    //*Criacao da Peca L
    char pecaL_0[4][4] = {{'L', 'L', 'L', 'L'}, {'L', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[8].setPeca(pecaL_0, 4, 2);
    char pecaL_90[4][4] = {{'L', 'L', ' ', ' '}, {' ', 'L', ' ', ' '}, {' ', 'L', ' ', ' '}, {' ', 'L', ' ', ' '}};
    pecas[9].setPeca(pecaL_90, 2, 4);
    char pecaL_180[4][4] = {{' ', ' ', ' ', 'L'}, {'L', 'L', 'L', 'L'}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[10].setPeca(pecaL_180, 4, 2);
    char pecaL_270[4][4] = {{'L', ' ', ' ', ' '}, {'L', ' ', ' ', ' '}, {'L', ' ', ' ', ' '}, {'L', 'L', ' ', ' '}};
    pecas[11].setPeca(pecaL_270, 2, 4);

    //* Criacao da Peca O
    char pecaO[4][4] = {{'O', 'O', ' ', ' '}, {'O', 'O', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[12].setPeca(pecaO, 2, 2);
    pecas[13].setPeca(pecaO, 2, 2);
    pecas[14].setPeca(pecaO, 2, 2);
    pecas[15].setPeca(pecaO, 2, 2);

    //* Criacao da Peca S
    char pecaS_0_180[4][4] = {{' ', 'S', 'S', ' '}, {'S', 'S', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[16].setPeca(pecaS_0_180, 3, 2);
    char pecaS_90_270[4][4] = {{'S', ' ', ' ', ' '}, {'S', 'S', ' ', ' '}, {' ', 'S', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[17].setPeca(pecaS_90_270, 2, 3);
    pecas[17].printPeca();
    pecas[18].setPeca(pecaS_0_180, 3, 2);
    pecas[19].setPeca(pecaS_90_270, 2, 3);

    //* Criacao da Peca T
    char pecaT_0[4][4] = {{'T', 'T', 'T', ' '}, {' ', 'T', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[20].setPeca(pecaT_0, 3, 2);
    char pecaT_90[4][4] = {{' ', 'T', ' ', ' '}, {'T', 'T', ' ', ' '}, {' ', 'T', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[21].setPeca(pecaT_90, 2, 3);
    char pecaT_180[4][4] = {{' ', 'T', ' ', ' '}, {'T', 'T', 'T', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[22].setPeca(pecaT_180, 3, 2);
    char pecaT_270[4][4] = {{'T', ' ', ' ', ' '}, {'T', 'T', ' ', ' '}, {'T', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[23].setPeca(pecaT_270, 2, 3);

    //*Criacao da Peca Z
    char pecaZ_0_180[4][4] = {{'Z', 'Z', ' ', ' '}, {' ', 'Z', 'Z', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[24].setPeca(pecaZ_0_180, 3, 2);
    char pecaZ_90_270[4][4] = {{' ', 'Z', ' ', ' '}, {'Z', 'Z', ' ', ' '}, {'Z', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    pecas[25].setPeca(pecaZ_90_270, 2, 3);
    pecas[26].setPeca(pecaZ_0_180, 3, 2);
    pecas[27].setPeca(pecaZ_90_270, 2, 3);
}

const char Tetris::get(const int &coluna, const int &linha) const
{
    if (coluna > numColunas || coluna < 0)
    {
        throw "Posicao de acesso de coluna invalido";
    }
    if (linha > alturas[coluna] || linha < 0)
    {
        throw "Posicao de acesso de linha invalido";
    }
    return jogo[coluna][linha];
}

void Tetris::removeColuna(const int &numColuna)
{
    if (numColuna > numColunas || numColuna < 0)
    {
        throw "Tentativa de remover coluna inexistente";
    }
    char *colunaMarcada = jogo[numColuna];
    for (int i = numColuna; i < numColunas - 1; i++)
    {
        jogo[i] = jogo[i + 1];
    }
    delete[] colunaMarcada;
    numColunas--;
}

unsigned int Tetris::getMaiorAltura() const
{
    unsigned int maiorAltura = 0;
    for (int i = 0; i < numColunas; i++)
    {
        if (alturas[i] > maiorAltura)
        {
            maiorAltura = alturas[i];
        }
    }

    return maiorAltura;
}

void Tetris::printMatrix() const
{
    unsigned int maiorAltura = getMaiorAltura();
    std::cout << "\nA MATRIX ESTA IMPRESSA DEITADA CUIDADO!! (Colunas na Horizontal)\n";

    std::cout << "Numero de colunas: " << numColunas << std::endl;
    std::cout << "Maior Altura: " << maiorAltura << std::endl;

    for (int i = 0; i <= maiorAltura; i++)
    {
        std::cout << std::setw(3) << i - 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < numColunas; i++)
    {
        std::cout << std::setw(3) << i;
        for (int j = 0; j < alturas[i]; j++)
        {
            std::cout << std::setw(3) << jogo[i][j];
        }
        std::cout << std::endl;
    }
}

void Peca::printPeca() const
{
    std::cout << "\nA PECA ESTA IMPRESSA DEITADA CUIDADO!! (Colunas na Horizontal)\n";
    std::cout << "Numero de colunas: " << numColunas << std::endl;
    std::cout << "Numero de linhas: " << numLinhas << std::endl;

    for (int i = 0; i <= numLinhas; i++)
    {
        std::cout << std::setw(3) << i - 1;
    }
    std::cout << std::endl;
    for (int i = 0; i < numColunas; i++)
    {
        std::cout << std::setw(3) << i;
        for (int j = 0; j < numLinhas; j++)
        {
            std::cout << std::setw(3) << peca[i][j];
        }
        std::cout << std::endl;
    }
}

void Tetris::printVetorPecas() const
{
    for (int i = 0; i < 28; i++)
    {
        pecas[i].printPeca();
    }
}

unsigned int Tetris::getMenorAltura() const
{
    unsigned int menorAltura = alturas[0];

    //Descobre a menor coluna, precisamos checar ate o limite superior dela
    for (int i = 0; i < numColunas; i++)
    {
        if (alturas[i] < menorAltura)
        {
            menorAltura = alturas[i];
        }
    }
    return menorAltura;
}

void Tetris::removeElemento(const int &posRemover, const int &indiceColuna)
{
    char *colunaAuxiliar = new char[alturas[indiceColuna] - 1];
    int indice = 0;
    for (int i = 0; i < alturas[indiceColuna]; i++)
    {
        if (posRemover == i)
        {
            break;
        }

        colunaAuxiliar[indice] = jogo[indiceColuna][i];
        indice++;
    }

    char *arrayDel = jogo[indiceColuna];
    jogo[indiceColuna] = colunaAuxiliar;
    alturas[indiceColuna]--;
    delete[] arrayDel;
}

void Tetris::removeLinha(const int &linhaARemover)
{
    for (int i = 0; i < numColunas; i++)
    {
        removeElemento(linhaARemover, i);
    }
}

void Tetris::removeLinhasCompletas()
{
    unsigned int menorAltura = getMenorAltura();

    ///Verifica se a linha precisa ser removida
    for (int linha = menorAltura - 1; linha >= 0; linha--)
    {
        bool devoRemoverLinha = true;

        for (int coluna = 0; coluna < numColunas; coluna++)
        {
            if (jogo[coluna][linha] == ' ')
            {
                devoRemoverLinha = false;
            }
        }

        if (devoRemoverLinha)
        {
            removeLinha(linha);
        }
    }
}

const int Tetris::getNumColunas() const
{
    return numColunas;
}

unsigned int Tetris::getAltura(const int &indiceColuna) const
{
    return alturas[indiceColuna];
}

unsigned int Tetris::getAltura() const
{
    return getMaiorAltura();
}

TipoPeca Tetris::decodePeca(const char id) const
{
    switch (id)
    {
    case 'I':
        return TipoI;
        break;
    case 'J':
        return TipoJ;
        break;
    case 'L':
        return TipoL;
        break;
    case 'O':
        return TipoO;
        break;
    case 'S':
        return TipoS;
        break;
    case 'T':
        return TipoT;
        break;
    case 'Z':
        return TipoZ;
        break;

    default:
        throw "Tipo de pessa invalido";
        break;
    }
}

bool Tetris::adicionaForma(const int coluna, const int linha, const char id, const int rotacao)
{
    TipoPeca peca = decodePeca(id);

    Peca pecaInserir = pecas[peca + rotacao / 90];

    std::cout << "INSERINDO PECA COLUNA:LINHA " << coluna << ":" << linha << " TIPO: " << id << " " << rotacao << std::endl;
    pecaInserir.printPeca();

    return true;
}

const int Peca::getNumColunas() const
{
    return numColunas;
}

const int Peca::getNumLinhas() const
{
    return numLinhas;
}

const char Peca::getPecaChar(const int &coluna, const int &linha) const
{
    return peca[coluna][linha];
}