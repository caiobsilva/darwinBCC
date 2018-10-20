#include <allegro5/allegro.h>
#include "header.h"

void movimentacao(ALLEGRO_EVENT evento, int *x, int *y){
    ALLEGRO_KEYBOARD_STATE tecla;
    al_get_keyboard_state(&tecla);
    if(al_key_down(&tecla,ALLEGRO_KEY_W)){
        *y -= 50;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_S)){
        *y += 50;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_D)){
        *x += 50;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_A)){
        *x -= 50;
    }
}
