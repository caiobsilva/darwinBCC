#include <allegro5/allegro.h>
#include "header.h"

void movimentacao(ALLEGRO_EVENT evento, int *x, int *y){
    ALLEGRO_KEYBOARD_STATE tecla;
    al_get_keyboard_state(&tecla);
    if(al_key_down(&tecla,ALLEGRO_KEY_W) || al_key_down(&tecla,ALLEGRO_KEY_UP)){
        *y -= 10;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_S) || al_key_down(&tecla,ALLEGRO_KEY_DOWN)){
        *y += 10;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_D) || al_key_down(&tecla,ALLEGRO_KEY_RIGHT)){
        *x += 10;
    }
    if(al_key_down(&tecla,ALLEGRO_KEY_A) || al_key_down(&tecla,ALLEGRO_KEY_LEFT)){
        *x -= 10;
    }
}
