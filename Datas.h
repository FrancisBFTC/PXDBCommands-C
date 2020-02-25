#include <conio.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <cstdlib>
#include <cstdio>

//Estrutura de informação de banco de dados
struct DataBase
{
      char database[20];
      char table[20];   
      char field[20][20];
};

//Estrutura de quantidade
struct DataQuant{
       int atual;       
};

//Função pra salvar mais um número de tabelas
void SaveQuant(int q)
{
     DataQuant quantity[0];
     quantity[0].atual = q;
     FILE *file;
     file = fopen("Quant.q", "wb");
     fwrite(quantity, sizeof(DataQuant), 1, file);
     fclose(file);    
}

//Função que retorna a quantidade de tabelas registradas
DataQuant ReadQuant()
{ 
    DataQuant quantity;
    FILE *file;
    file = fopen("Quant.q", "rb");
    fread(&quantity, sizeof(DataQuant), 1, file);
    fclose(file);
    return quantity;
}


