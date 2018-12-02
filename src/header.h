#ifndef HEADER_H
#define HEADER_H

enum statesGame {Menu, Select, Options, AmbienteUm, Exit};

typedef struct T{
    int ID;
    struct T *esquerda;
    struct T *direita;
    struct T *baixo;
    struct T *cima;
    ALLEGRO_BITMAP *imagem;
    ALLEGRO_BITMAP *arvores;
    ALLEGRO_BITMAP *colisao;
    int bInimigo, xInimigo, yInimigo;
}tile;

#define A1 0
#define A2 1
#define A3 2
#define A4 3
#define A5 4
#define B1 5
#define B2 6
#define B3 7
#define B4 8
#define C1 9
#define C2 10
#define C3 11
#define C4 12
#define D1 13
#define D2 14
#define D3 15
#define D4 16
#define D5 17

#define C8 18
#define C9 19
#define D6 20
#define D7 21
#define D8 22
#define D9 23
#define D10 24
#define D11 25
#define E7 26
#define E8 27
#define E9 28
#define E10 29
#define E11 30
#define F7 31
#define F8 32
#define F9 33
#define F10 34
#define G9 35
#define G10 36

enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
void movimentacao(ALLEGRO_EVENT evento,tile *tileAtual, int *x, int *y, int *t, int flagEvolucao, int *flagVida);
int pausa(int x, int y, int *flagSom, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
int falas(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int s, int x, int y, int *pontuacao);
void localizacao(int *x, int *y, tile *temp);
void iniciarTiles(tile *tileAtual);
void movimentacaoInimigos(tile *tileAtual, int *xInimigo, int *yInimigo, int *x, int *y, int *flagVida);
void colisaoInimigo(tile *tileAtual, int *x, int *y, int id);
void colisao(tile *tileAtual, int *x, int *y, int id, int *flagvida);
int ninho(tile *tileAtual, int *x, int *y,int *flagPontos,int *flagEvolucao);
void fade();
void falaNinho();
void falaNinho2();
void inimigoAquatico(int tile, int *xAquatico, int *yAquatico, int *x, int *y, int *flagVida);

#endif
