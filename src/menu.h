#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int desenhar(int n){

    ALLEGRO_BITMAP *background = al_load_bitmap("../res/images/introMenu01.png");
    ALLEGRO_BITMAP *background1 = al_load_bitmap("../res/images/introMenu02.png");
    ALLEGRO_BITMAP *background2 = al_load_bitmap("../res/images/introMenu03.png");


    switch (n){
        case 1:
        al_draw_scaled_bitmap(background, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
        break;
        case 2:
        al_draw_scaled_bitmap(background1, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
        break;
        case 3:
        al_draw_scaled_bitmap(background2, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
        break;
    }

    return (n += 1);
}

int menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){

    int n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);

    while(1){
        
        al_wait_for_event_timed(fila, &evento, 0.05);
        if(evento.type){
            break;
        }
        al_clear_to_color(branco);
        n = desenhar(n);
        al_flip_display();
        al_rest(0.5);

        if(n > 3){
            n = 1;
        }        
    }

    al_clear_to_color(preto);
    al_flip_display();

    return 0;
}
