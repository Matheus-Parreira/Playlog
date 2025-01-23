#ifndef LIB_H
#define LIB_H

typedef struct
{
	int id;
	char artista[50];
	char nome[100];
	char ano[10];
	char pais[20];
	int dia_grav;
	int mes_grav;
	int ano_grav;
	int hora_grav;
	int min_grav;
	int seg_grav;	
}Musica;

int leitura_inicial(Musica[]);
void exibir_musicas(Musica[], int);
void concluida();
void obter_data(Musica[], int, struct tm);
void troca_artista(Musica[], Musica[], int, int);
void troca_musica(Musica[], Musica[], int, int);
void ordenacao_artista(Musica[], int);
void ordenacao_musica(Musica[], int);
void registrar_musicas(Musica[], int);

#endif
