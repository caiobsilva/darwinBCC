#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

int pausa(ALLEGRO_BITMAP *cenario, ALLEGRO_BITMAP *sprite, int x, int y, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int sair = 0;
    ALLEGRO_BITMAP *fundo = al_load_bitmap("../res/images/menu_1.png");
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    while(!sair){
        while(!(al_is_event_queue_empty(fila))){
            
            al_wait_for_event(fila,&evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                return 1;
            }else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    sair  = 1;
                }    
            }
        
        }
        al_clear_to_color(branco);
        al_draw_bitmap(cenario, 0,0,0);
        al_draw_scaled_bitmap(sprite, 0, 0, 16, 22, x, y, 48, 66, 0);
        al_draw_bitmap(fundo,0,0,0);
        al_flip_display();
    }
    
    al_destroy_bitmap(fundo);

    return 0;
}
