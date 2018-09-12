#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int introMenu(int n){
    ALLEGRO_BITMAP *intro[4];

    intro[0] = al_load_bitmap("../res/images/introMenu1.png");
    intro[1] = al_load_bitmap("../res/images/introMenu2.png");
    intro[2] = al_load_bitmap("../res/images/introMenu3.png");
    intro[3] = al_load_bitmap("../res/images/introMenu4.png");

    if (n < 6){
        al_draw_scaled_bitmap(intro[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if (n < 12){
        al_draw_scaled_bitmap(intro[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if (n < 18){
        al_draw_scaled_bitmap(intro[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }else if (n <= 24){
        al_draw_scaled_bitmap(intro[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }

    for (int i = 0; i < 4; i++){
      al_destroy_bitmap(intro[i]);
    }

    return (n += 1);
}

int menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
  //Tirei o sair, mas consigo perceber como ele seria necessário em alguns casos, ainda, você prefere com "break"
  //ou com "sair" (no caso, a forma do while se quebrar)?
    int n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);

    while (1){
        al_wait_for_event_timed(fila, &evento, 0.05);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
            break;
        }

        al_clear_to_color(branco);
        n = introMenu(n);
        al_flip_display();

        if (n > 24){
            n = 1;
        }
    }
    return 0;
}
