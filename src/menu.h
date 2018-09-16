#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>


int introMenu(int n){
    ALLEGRO_BITMAP *intro[4];

    intro[0] = al_load_bitmap("../res/images/introMenu1.png");
    intro[1] = al_load_bitmap("../res/images/introMenu2.png");
    intro[2] = al_load_bitmap("../res/images/introMenu3.png");
    intro[3] = al_load_bitmap("../res/images/introMenu4.png");

    if(n < 6){
        al_draw_scaled_bitmap(intro[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n < 12){
        al_draw_scaled_bitmap(intro[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n < 18){
        al_draw_scaled_bitmap(intro[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n <= 24){
        al_draw_scaled_bitmap(intro[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }

    for (int i = 0; i < 4; i++){
        al_destroy_bitmap(intro[i]);
    }

    return (n += 1);
}

int menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int sair = 0, n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

    while (!sair){
        al_wait_for_event_timed(fila, &evento, 0.05);
        
        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
        }else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            sair = 1;
        }

        al_clear_to_color(branco);
        n = introMenu(n);
        al_flip_display();

        if(n > 24){
            n = 1;
        }
    }
    
    return 2;
}


int menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    
    int sair = 0, n = 0;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);   
    al_reserve_samples(1);
    ALLEGRO_SAMPLE *efeitoSelecionar = al_load_sample("../res/audio/pressEffect.flac");


    ALLEGRO_BITMAP *select[4];
    
    select[0] = al_load_bitmap("../res/images/selectMenu1.png");
    select[1]  = al_load_bitmap("../res/images/selectMenu2.png");
    select[2]  = al_load_bitmap("../res/images/selectMenuNewGame.png");
    select[3]  = al_load_bitmap("../res/images/selectMenuOptions.png");   
    
    al_clear_to_color(branco);
    al_draw_scaled_bitmap(select[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    al_flip_display();

    while(!sair){
        
        al_wait_for_event_timed(fila,&evento,0.05);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            
            return 0;

        }
        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            if(evento.keyboard.keycode == ALLEGRO_KEY_UP){
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(select[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                n = 3;
            }else if(evento.keyboard.keycode == ALLEGRO_KEY_DOWN){
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(select[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                n = 4;
            }else if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER){
                if(n != 0){
                    al_play_sample(efeitoSelecionar, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    al_rest(0.8);
                    sair = 1;
                }
            }
            al_flip_display();
        }
    }     

    al_destroy_sample(efeitoSelecionar);
    for (int i = 0; i < 4; i++){
        al_destroy_bitmap(select[i]);
    }
    
    return n;
}
