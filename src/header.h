#ifndef HEADER_H
#define HEADER_H


enum statesGame {Menu, Select, Options, AmbienteUm, Exit};

enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
void movimentacao(ALLEGRO_EVENT evento, int *x, int *y, int *t);
int pausa(int x, int y, int *flagSom, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
int falas(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int s);

typedef struct T {
    struct T *esquerda;
    struct T *direita;
    struct T *baixo;
    struct T *cima;
    ALLEGRO_BITMAP *imagem;
}tile;

void localizacao(int *x, int *y, int *flagParte, tile *temp);

#endif

