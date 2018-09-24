#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "controles.h"


int ambienteInicial(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){

    int n,sair,x,y,*p,*q;
    sair = 0;
    n = 0;
    x = 0;
    y = 0;
    p = &x;
    q = &y;

    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_BITMAP *lizard[2];
    lizard[0] = al_load_bitmap("../res/images/lizard01.png");
    lizard[1] = al_load_bitmap("../res/images/lizard02.png");

    while (!sair){

        al_wait_for_event_timed(fila, &evento, 0.05);
        
        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
            al_destroy_bitmap(lizard[0]);
            al_destroy_bitmap(lizard[1]);
        }

        al_clear_to_color(branco);
        movimentacao(fila,evento,p,q);
        //al_draw_bitmap(lizard[n],x,y,0);
        al_draw_scaled_bitmap(lizard[n],0,0,23,38,x,y,69,114,0);
        al_flip_display();

    }

    for(int i = 0; i < 2; i++){
        al_destroy_bitmap(lizard[i]);
    }

    return (0);
}