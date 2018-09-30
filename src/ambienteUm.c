#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int n = 0, sair = 0, x = 0, y = 0, *p = &x, *q = &x;
    p = &x;
    q = &y;

    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_BITMAP *player[3];

    player[0] = al_load_bitmap("../res/images/sprite01/baixo01.png");
    player[1] = al_load_bitmap("../res/images/sprite01/baixo02.png");
    player[2] = al_load_bitmap("../res/images/sprite01/baixo03.png");

    while (!sair){
        al_wait_for_event_timed(fila, &evento, 0.05);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return Exit;
            for(int i = 0; i < 3; i++){
                al_destroy_bitmap(player[i]);
            }
        }

        al_clear_to_color(branco);
        movimentacao(fila, evento, p, q);
        al_draw_scaled_bitmap(player[n], 0, 0, 16, 22, x, y, 48, 66, 0);
        al_flip_display();

    }

    for(int i = 0; i < 3; i++){
        al_destroy_bitmap(player[i]);
    }

    return Exit;
}
