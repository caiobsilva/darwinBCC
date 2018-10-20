#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

int menuIntro(int n){
    ALLEGRO_BITMAP *intro[4];

    intro[0] = al_load_bitmap("../res/images/introMenu1.png");
    intro[1] = al_load_bitmap("../res/images/introMenu2.png");
    intro[2] = al_load_bitmap("../res/images/introMenu3.png");
    intro[3] = al_load_bitmap("../res/images/introMenu4.png");

    if(n < 6){
        al_draw_scaled_bitmap(intro[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n < 12){
        al_draw_scaled_bitmap(intro[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n < 18){
        al_draw_scaled_bitmap(intro[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n <= 24){
        al_draw_scaled_bitmap(intro[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }

    for (int i = 0; i < 4; i++){
        al_destroy_bitmap(intro[i]);
    }

    return (n += 1);
}

enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int sair = 0, n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

    while (!sair){
        al_wait_for_event_timed(fila, &evento, 0.05);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
        }
        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            sair = 1;
        }

        al_clear_to_color(branco);
        n = menuIntro(n);
        al_flip_display();

        if(n > 24){
            n = 1;
        }
    }

    return Select;
}


enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    enum statesGame estado;
    int sair = 0;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    al_reserve_samples(1);
    ALLEGRO_SAMPLE *efeitoSelecionar = al_load_sample("../res/audio/pressEffect.flac");
    ALLEGRO_SAMPLE *efeitoTrocar = al_load_sample("../res/audio/alternEffect.flac");

    ALLEGRO_BITMAP *arraySelecionar[3];

    arraySelecionar[0] = al_load_bitmap("../res/images/selectMenu1.png");
    arraySelecionar[1]  = al_load_bitmap("../res/images/selectMenuNewGame.png");
    arraySelecionar[2]  = al_load_bitmap("../res/images/selectMenuOptions.png");

    al_clear_to_color(branco);
    al_draw_scaled_bitmap(arraySelecionar[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    al_flip_display();

    while(!sair){
        al_wait_for_event_timed(fila,&evento,0.05);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return Exit;
        }
        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            if(evento.keyboard.keycode == ALLEGRO_KEY_UP){
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(arraySelecionar[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                al_play_sample(efeitoTrocar, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                estado = AmbienteUm;
            }if(evento.keyboard.keycode == ALLEGRO_KEY_DOWN){
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(arraySelecionar[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                al_play_sample(efeitoTrocar, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                estado = Exit;
            }else if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER){
                if(estado != Menu){
                    al_play_sample(efeitoSelecionar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    al_rest(0.8);
                    sair = 1;
                }
            }
            al_flip_display();
        }
    }

    al_destroy_sample(efeitoSelecionar);
    for (int i = 0; i < 3; i++){
        al_destroy_bitmap(arraySelecionar[i]);
    }

    return estado;
    
}
