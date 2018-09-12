#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int selectMenu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int a = 0;

    ALLEGRO_BITMAP *select[2];

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

    select[0] = al_load_bitmap("../res/images/selectMenu1.png");
    select[1] = al_load_bitmap("../res/images/selectMenu2.png");

    while (a < 4){
        al_clear_to_color(branco);

        for (int n = 0; n < 2; n++){
            al_draw_scaled_bitmap(select[n], 0, 0, 896, 504, 0, 0, 1280, 720, 0);

            if (n > 2){
                n = 1;
            }
            al_flip_display();
            al_rest(1);
        }
        a++;
    }

    al_destroy_bitmap(select[0]);
    al_destroy_bitmap(select[1]);

    return 0;
}

int introMenu(int n){

    ALLEGRO_BITMAP *intro[4];

    intro[0] = al_load_bitmap("../res/images/introMenu1.png");
    intro[1] = al_load_bitmap("../res/images/introMenu2.png");
    intro[2] = al_load_bitmap("../res/images/introMenu3.png");
    intro[3] = al_load_bitmap("../res/images/introMenu4.png");

    if(n < 10){
        al_draw_scaled_bitmap(intro[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n < 20){
        al_draw_scaled_bitmap(intro[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n < 30){
        al_draw_scaled_bitmap(intro[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if(n <= 40){
        al_draw_scaled_bitmap(intro[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    
    al_destroy_bitmap(intro[0]);
    al_destroy_bitmap(intro[1]);
    al_destroy_bitmap(intro[2]);
    al_destroy_bitmap(intro[3]);

    return (n += 1);
}

int menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

    while (!evento.type){
    
        al_wait_for_event_timed(fila, &evento, 0.05);
        al_clear_to_color(branco);
        n = introMenu(n);
        al_flip_display();  

        if(n > 40){
            n = 1;
        }

    }
    
    return 0;
}

