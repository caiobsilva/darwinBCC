#include <allegro5/allegro.h>
#include "header.h"

void movimentacao(ALLEGRO_EVENT evento,tile *tileAtual, int *x, int *y, int *t){
    ALLEGRO_KEYBOARD_STATE tecla;
    al_get_keyboard_state(&tecla);
    static int i;
    ALLEGRO_BITMAP *player[12];
    player[0] = al_load_bitmap("../res/images/sprite01/baixo01.png");
    player[1] = al_load_bitmap("../res/images/sprite01/baixo02.png");
    player[2] = al_load_bitmap("../res/images/sprite01/baixo03.png");
    player[3] = al_load_bitmap("../res/images/sprite01/cima01.png");
    player[4] = al_load_bitmap("../res/images/sprite01/cima02.png");
    player[5] = al_load_bitmap("../res/images/sprite01/cima03.png");
    player[6] = al_load_bitmap("../res/images/sprite01/esquerda01.png");
    player[7] = al_load_bitmap("../res/images/sprite01/esquerda02.png");
    player[8] = al_load_bitmap("../res/images/sprite01/esquerda03.png");
    player[9] = al_load_bitmap("../res/images/sprite01/direita01.png");
    player[10] = al_load_bitmap("../res/images/sprite01/direita02.png");
    player[11] = al_load_bitmap("../res/images/sprite01/direita03.png");


    if(al_key_down(&tecla, ALLEGRO_KEY_W) || al_key_down(&tecla, ALLEGRO_KEY_UP)){
        *y -= 5;
        //colisao(tileAtual,x,y,1);
        if(*t <= 6){
            al_draw_scaled_bitmap(player[3], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 12){
            al_draw_scaled_bitmap(player[4], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 18){
            al_draw_scaled_bitmap(player[5], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }
        i = 3;
        *t += 1;
    }else if(al_key_down(&tecla, ALLEGRO_KEY_S) || al_key_down(&tecla, ALLEGRO_KEY_DOWN)){
        *y += 5;
        //colisao(tileAtual,x,y,2);
        if(*t <= 6){
            al_draw_scaled_bitmap(player[0], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 12){
            al_draw_scaled_bitmap(player[1], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 18){
            al_draw_scaled_bitmap(player[2], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }
        i = 0;
        *t += 1;
    }else if(al_key_down(&tecla, ALLEGRO_KEY_D) || al_key_down(&tecla, ALLEGRO_KEY_RIGHT)){
        *x += 5;
        //colisao(tileAtual,x,y,3);
        if(*t <= 6){
            al_draw_scaled_bitmap(player[9], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 12){
            al_draw_scaled_bitmap(player[10], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 18){
            al_draw_scaled_bitmap(player[11], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }
        i = 9;
        *t += 1;
    }else if(al_key_down(&tecla, ALLEGRO_KEY_A) || al_key_down(&tecla, ALLEGRO_KEY_LEFT)){
        *x -= 5;
        //colisao(tileAtual,x,y,4);
        if(*t <= 6){
            al_draw_scaled_bitmap(player[6], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 12){
            al_draw_scaled_bitmap(player[7], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else if(*t <= 18){
            al_draw_scaled_bitmap(player[8], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }
        i = 6;
        *t += 1;
    }else{
        if(i == 3 || i == 0){
            al_draw_scaled_bitmap(player[i], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }else{
            al_draw_scaled_bitmap(player[i], 0, 0, 22, 22, *x, *y, 66, 66, 0);
        }
    
    }
    if(*t > 18){
        *t = 0;
    }
    
    for(int i = 0; i < 12; i++){
        al_destroy_bitmap(player[i]);
    }
}
