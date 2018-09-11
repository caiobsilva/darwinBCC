#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    
    int n = 1, a = 0;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    
    ALLEGRO_BITMAP *select = al_load_bitmap("../res/images/selectMenu01.png");
    ALLEGRO_BITMAP *select1 = al_load_bitmap("../res/images/selectMenu02.png");
    
    while(a < 10){
        al_clear_to_color(branco);
        if(n == 1)
            al_draw_scaled_bitmap(select, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
        else
            al_draw_scaled_bitmap(select1, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
        n += 1;
        if(n > 2){
            n = 1;
        }
        al_flip_display();
        al_rest(.4);
        
        a++;
    }
    
    al_destroy_bitmap(select);
    al_destroy_bitmap(select1);
    return 0;
}

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

    al_destroy_bitmap(background);
    al_destroy_bitmap(background1);
    al_destroy_bitmap(background2);

    return (n += 1);
}

int menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){

    int n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

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

    menuSelect(fila, evento);

    return 0;
}
