#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

int pausa(int x, int y, int *flagSom, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int sair = 0, i;

    if(*flagSom == 1){
        i = 0;
    }else{
        i = 1;
    }

    ALLEGRO_BITMAP *fundo[7];
    fundo[0] = al_load_bitmap("../res/images/pausaPOn.png");
    fundo[1] = al_load_bitmap("../res/images/pausaPOff.png");
    fundo[2] = al_load_bitmap("../res/images/pausaSairOn.png");
    fundo[3] = al_load_bitmap("../res/images/pausaSairOff.png");
    fundo[4] = al_load_bitmap("../res/images/pausaPisca.png");
    fundo[5] = al_load_bitmap("../res/images/pausaSOn.png");
    fundo[6] = al_load_bitmap("../res/images/pausaSOff.png");
    
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
    while(!sair){
        while(!(al_is_event_queue_empty(fila))){
            
            al_wait_for_event(fila,&evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                return 1;
            }else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    sair  = 1;
                }else if(evento.keyboard.keycode == ALLEGRO_KEY_UP || evento.keyboard.keycode == ALLEGRO_KEY_W){
                    if(*flagSom == 1){
                        i = 5;
                    }else{
                        i = 6;
                    }
                }else if(evento.keyboard.keycode == ALLEGRO_KEY_DOWN || evento.keyboard.keycode == ALLEGRO_KEY_S){
                    if(*flagSom == 1){
                        i = 2;
                    }else{
                        i = 3;
                    }
                }else if(evento.keyboard.keycode == ALLEGRO_KEY_LEFT && (i == 5 || i == 6) || evento.keyboard.keycode == ALLEGRO_KEY_A){
                    i = 5;
                    *flagSom = 1;
                }else if(evento.keyboard.keycode == ALLEGRO_KEY_RIGHT && (i == 5 || i == 6) || evento.keyboard.keycode == ALLEGRO_KEY_D && (i == 5 || i == 6)){
                    i = 6;
                    *flagSom = 0;
                }else if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
                    switch(i){
                        case 2:
                            return 1;
                            break;
                        case 3:
                            return 1;
                            break;
                        case 5:
                            i = 0;
                            break;
                        case 6:
                            i = 1;
                            break;
                    }
                }    
            }
        }
        
        al_clear_to_color(preto);
        al_draw_bitmap(fundo[i],0,0,0);
        al_flip_display();
    }
    for(int i = 0; i < 6; i++){
        al_destroy_bitmap(fundo[i]);
    }

    return 0;
}
