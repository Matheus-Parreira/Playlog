#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"lib.h"

int leitura_inicial(Musica musicas[])
{
	char linhas[150];
	int lidas = 0;	
	FILE *finicial;
	finicial = fopen("..\\playlist\\log.txt", "r");	
	fgets(linhas, 150, finicial);
	fgets(linhas, 150, finicial);			
	while (fscanf(finicial, "%i| %[^|]| %[^|]| %[^|]| %[^|]| %d/%d/%d %d:%d:%d|\n", &musicas[lidas].id, musicas[lidas].artista, 
	musicas[lidas].nome, musicas[lidas].ano, musicas[lidas].pais, &musicas[lidas].dia_grav, &musicas[lidas].mes_grav, &musicas[lidas].ano_grav, 
	&musicas[lidas].hora_grav, &musicas[lidas].min_grav, &musicas[lidas].seg_grav) != EOF)
		lidas++;

	fclose(finicial);	
	return lidas;
}

void exibir_musicas(Musica musicas[], int tam)
{
	printf("   ID|            ARTISTA/BANDA|                                    NOME|       ANO|         PAIS/REGIAO|        ADICIONADA EM|\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------");
	for(int i=0; i <tam; i++)
	{
		printf("\n%5i|%25s|%40s|%10s|%20s|", musicas[i].id, musicas[i].artista, musicas[i].nome, musicas[i].ano, musicas[i].pais);
		printf("  %.2d/%.2d/%d %.2d:%.2d:%.2d|", musicas[i].dia_grav, musicas[i].mes_grav, 
		musicas[i].ano_grav,  musicas[i].hora_grav, musicas[i].min_grav, musicas[i].seg_grav);
	}				
	printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
}

void concluida()
{
	printf("\nAcao concluida.\nDigite qualquer tecla para retornar ao menu.");
	fflush(stdin);
	getchar();	
}

void obter_data(Musica musicas[], int tam, struct tm data)
{
	musicas[tam].dia_grav = data.tm_mday;
	musicas[tam].mes_grav = data.tm_mon + 1;
	musicas[tam].ano_grav = data.tm_year + 1900;
	musicas[tam].hora_grav = data.tm_hour;
	musicas[tam].min_grav = data.tm_min;
	musicas[tam].seg_grav = data.tm_sec;
}

void troca_artista(Musica vet1[], Musica vet2[], int a, int b) 
{
 	strcpy(vet1[a].artista, vet2[b].artista);
 	strcpy(vet1[a].nome, vet2[b].nome);
 	strcpy(vet1[a].ano, vet2[b].ano);
 	strcpy(vet1[a].pais, vet2[b].pais);
 	vet1[a].dia_grav = vet2[b].dia_grav;
 	vet1[a].mes_grav = vet2[b].mes_grav;
 	vet1[a].ano_grav = vet2[b].ano_grav;
 	vet1[a].hora_grav = vet2[b].hora_grav;
 	vet1[a].min_grav = vet2[b].min_grav;
 	vet1[a].seg_grav = vet2[b].seg_grav;
}

void troca_musica(Musica vet1[], Musica vet2[], int a, int b) 
{
	strcpy(vet1[a].nome, vet2[b].nome);
 	strcpy(vet1[a].ano, vet2[b].ano);
 	strcpy(vet1[a].pais, vet2[b].pais);
 	vet1[a].dia_grav = vet2[b].dia_grav;
 	vet1[a].mes_grav = vet2[b].mes_grav;
 	vet1[a].ano_grav = vet2[b].ano_grav;
 	vet1[a].hora_grav = vet2[b].hora_grav;
 	vet1[a].min_grav = vet2[b].min_grav;
 	vet1[a].seg_grav = vet2[b].seg_grav;
}

void ordenacao_artista(Musica musicas[], int tam)
{
	Musica aux[1];
	for (int i = tam-1; i > 0; i--) 
	{
		for (int j = 0; j < i; j++) 
		{
      		if(strcmp(musicas[j].artista, musicas[j+1].artista) > 0) 
	  		{
        		troca_artista(aux, musicas, 0, j);
        		troca_artista(musicas, musicas, j, j+1);
        		troca_artista(musicas, aux, j+1, 0);
     		}
    	}
  	}
}

void ordenacao_musica(Musica musicas[], int tam)
{
	Musica aux[1];
	int cont = 0;
	for(int i = 0; i < tam; i++)
	{
		if(strcmp(musicas[i].artista, musicas[i+1].artista) != 0)
		{
			cont++;
			for(int final = i; final > (i+1) - cont; final--)
			{				
  				for(int j = (i+1)-cont; j < i+1; j++)
				{
					if(strcmp(musicas[j].nome, musicas[j+1].nome) > 0 && j+1 != i+1)
					{
						troca_musica(aux, musicas, 0, j);
        				troca_musica(musicas, musicas, j, j+1);
       			 		troca_musica(musicas, aux, j+1, 0);
					}
				}
						
			}
			cont = 0;
		}			
		else
			cont++;		
	}
}

void registrar_musicas(Musica musicas[], int tam)
{		
	fflush(stdin);
	printf("Artista: ");
	scanf("%[^\n]", musicas[tam].artista);
	printf("Musica: ");
	scanf(" %[^\n]", musicas[tam].nome);
	printf("Ano: ");
	scanf(" %[^\n]", musicas[tam].ano);
	printf("Pais: ");
	scanf(" %[^\n]", musicas[tam].pais);
	
	musicas[tam].id = tam+1;
	time_t mytime;
    mytime = time(NULL);
	struct tm data = *localtime(&mytime);
	
	data_igual(musicas, tam, data);
	ordenacao_artista(musicas, tam+1);
	ordenacao_musica(musicas, tam+1);	
	
	FILE *fregistro;	
	fregistro = fopen("..\\playlist\\log.txt", "w");	
	fprintf(fregistro, "   ID|            ARTISTA/BANDA|                                    NOME|       ANO|         PAIS/REGIAO|        ADICIONADA EM|\n");
	fprintf(fregistro, "-------------------------------------------------------------------------------------------------------------------------------");
	for(int i=0; i <tam+1; i++)
	{
		fprintf(fregistro, "\n%5i|%25s|%40s|%10s|%20s|", musicas[i].id, musicas[i].artista, musicas[i].nome, musicas[i].ano, musicas[i].pais);
		fprintf(fregistro,"  %.2d/%.2d/%d %.2d:%.2d:%.2d|", musicas[i].dia_grav, musicas[i].mes_grav, 
		musicas[i].ano_grav,  musicas[i].hora_grav, musicas[i].min_grav, musicas[i].seg_grav);
	}				
	fclose(fregistro);	
}