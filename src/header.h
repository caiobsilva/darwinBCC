#ifndef HEADER_H
#define HEADER_H


enum statesGame {Menu, Select, Options, AmbienteUm, Exit};

typedef struct L{
    int x0;
    int y0;
    int x;
    int y;
    struct L *proximo;
}col;

typedef struct{
    col *primeiro;
    col *ultimo;
    int tamanho;
}listaCol;

typedef struct T {
    int ID;
    struct T *esquerda;
    struct T *direita;
    struct T *baixo;
    struct T *cima;
    listaCol *lista;
    ALLEGRO_BITMAP *imagem;
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

enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
void movimentacao(ALLEGRO_EVENT evento,tile *tileAtual, int *x, int *y, int *t);
int pausa(int x, int y, int *flagSom, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
int falas(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int s, int x, int y, int *pontuacao);
void localizacao(int *x, int *y, tile *temp);
void iniciarTiles(tile *tileAtual);
void movimentacaoInimigos(int i,int *xInimigo,int *yInimigo, int *x, int *y);
void addPartes(int i, int *xInimigo, int *yInimigo, int *x, int *y);
void colisao(tile *tileAtual, int *x, int *y, int ID);

#endif

