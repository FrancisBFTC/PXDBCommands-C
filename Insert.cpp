#include <cstdlib>
#include <cstdio>
#include "Structs.h"

void insertTable(){

	int size = 1;
	usuarios insert[size];
	FILE *arquivo;

	if((arquivo = fopen("admin.usuarios.db", "wb")) == NULL){
	printf("\nErro ao salvar os dados!\n");
	return;
	}

	fwrite(insert, sizeof(usuarios), size, arquivo);
	fclose(arquivo);
	printf("\nTabela 'usuarios' construida na base 'admin'!\n");
	printf("Codigo pxdb executado com 0 erros!\n");
}

int main(void){
	 insertTable();
	 return 0;
}
