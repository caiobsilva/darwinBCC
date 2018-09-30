#include <allegro5/allegro.h>
#include "header.h"

void movimentacao(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int *x, int *y){
    al_wait_for_event_timed(fila, &evento, 0.05);

    if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
        switch(evento.keyboard.keycode){
            case ALLEGRO_KEY_W:
                *y -= 50;
                break;
            case ALLEGRO_KEY_S:
                *y += 50;
                break;
            case ALLEGRO_KEY_D:
                *x += 50;
                break;
            case ALLEGRO_KEY_A:
                *x -= 50;
                break;
        }

    }
}
