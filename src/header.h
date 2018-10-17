#ifndef HEADER_H
#define HEADER_H

enum statesGame {Menu, Select, Options, AmbienteUm, Exit};

enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);
void movimentacao(ALLEGRO_EVENT evento, int *x, int *y);
int pausa(ALLEGRO_BITMAP *cenario, ALLEGRO_BITMAP *sprite, int x, int y, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento);

#endif
