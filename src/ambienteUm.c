#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int flagOpcoes = 0, flagSom = 1, flagPontos = 0, flagVida = 3, flagEvolucao = 0;
    int sair = 0, x = 610, y = 294, t = 0;
    tile tileAtual;
    iniciarTiles(&tileAtual);

    ALLEGRO_BITMAP *fimJogo = al_load_bitmap("../res/images/telaMorte.png");
    ALLEGRO_BITMAP *pontos[4];
    pontos[0] = al_load_bitmap("../res/images/pontos0.png");
    pontos[1] = al_load_bitmap("../res/images/pontos1.png");
    pontos[2] = al_load_bitmap("../res/images/pontos2.png");
    pontos[3] = al_load_bitmap("../res/images/pontos3.png");
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);

    ALLEGRO_BITMAP *vida[4];
    vida[0] = al_load_bitmap("../res/images/coracao0.png");
    vida[1] = al_load_bitmap("../res/images/coracao1.png");
    vida[2] = al_load_bitmap("../res/images/coracao2.png");
    vida[3] = al_load_bitmap("../res/images/coracao3.png");

    fade();
    while (!sair){
        while(!(al_is_event_queue_empty(fila))){

            al_wait_for_event(fila, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                return Exit;
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    flagOpcoes = pausa(x, y, &flagSom, fila, evento);

                    if(flagOpcoes){
                        return Exit;
                    }
                }
            }
        }

        if(falas(fila, evento, tileAtual.ID, x, y, &flagPontos)){
            return Exit;
        }

        if(flagVida == 0){
            al_draw_scaled_bitmap(fimJogo, 0, 0, 896, 504, 0, 0, 1280, 720, 0);
            al_flip_display();
            al_rest(5.0);
            return Exit;
        }


        if(ninho(&tileAtual, &x, &y, &flagPontos, &flagEvolucao)){
            return Exit;
        }

        al_clear_to_color(branco);
        localizacao(&x, &y, &tileAtual);
        al_draw_bitmap(tileAtual.imagem, 0, 0, 0);
        if(tileAtual.bInimigo == 1)
            movimentacaoInimigos(&tileAtual, &tileAtual.xInimigo, &tileAtual.yInimigo, &x, &y, &flagVida);
        if(tileAtual.bInimigo == 2)
            inimigoAquatico(tileAtual.ID, &tileAtual.xInimigo, &tileAtual.yInimigo, &x, &y, &flagVida);
        movimentacao(evento, &tileAtual, &x, &y, &t, flagEvolucao, &flagVida);
        al_draw_bitmap(tileAtual.arvores, 0, 0, 0);
        al_draw_bitmap(pontos[flagPontos], 1100, 0, 0);
        al_draw_bitmap(vida[flagVida], 50, 0, 0);
        al_flip_display();
    }

    return Exit;
}
