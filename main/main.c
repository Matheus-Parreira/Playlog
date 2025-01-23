#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"..\lib\lib.h"

main()
{
	Musica musicas[2000];
	int tam;
	tam = leitura_inicial(musicas);
	int opcao = 1;

while(opcao != 0)
{
	system("cls");
	printf("Bem-vindo ao PlayLog!\n\nOpcoes: \n1 - Visualizar Playlist\n2 - Adicionar nova musica\n3 - Fechar\n\n");
	scanf("%i", &opcao);
	
	system("cls");
	switch(opcao)
	{
		case 1:
			exibir_musicas(musicas, tam);
			concluida();					
		break;
		case 2:
			registrar_musicas(musicas, tam);
			tam++;
			concluida();	
		break;
		case 3:
			printf("Encerrando...\n");
			return 0;
		break;
		default:
			printf("Opcao invalida.\nDigite qualquer tecla para retornar ao menu.");
			concluida();
		break;
	}
}
	return 0; 
}