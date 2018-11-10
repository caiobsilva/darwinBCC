#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

int fade(int n){
    ALLEGRO_BITMAP *fade[10];

    fade[0] = al_load_bitmap("../res/efeitos/fade/fade1.png");
    fade[1] = al_load_bitmap("../res/efeitos/fade/fade2.png");
    fade[2] = al_load_bitmap("../res/efeitos/fade/fade3.png");
    fade[3] = al_load_bitmap("../res/efeitos/fade/fade4.png");
    fade[4] = al_load_bitmap("../res/efeitos/fade/fade5.png");
    fade[5] = al_load_bitmap("../res/efeitos/fade/fade6.png");
    fade[6] = al_load_bitmap("../res/efeitos/fade/fade7.png");
    fade[7] = al_load_bitmap("../res/efeitos/fade/fade8.png");
    fade[8] = al_load_bitmap("../res/efeitos/fade/fade9.png");
    fade[9] = al_load_bitmap("../res/efeitos/fade/fade10.png");

    while(n != 20){

        if(n < 2){
            al_draw_scaled_bitmap(fade[0], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 4){
            al_draw_scaled_bitmap(fade[1], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 6){
            al_draw_scaled_bitmap(fade[2], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 8){
            al_draw_scaled_bitmap(fade[3], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 10){
            al_draw_scaled_bitmap(fade[4], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 12){
            al_draw_scaled_bitmap(fade[5], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 14){
            al_draw_scaled_bitmap(fade[6], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 16){
            al_draw_scaled_bitmap(fade[7], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 18){
            al_draw_scaled_bitmap(fade[8], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 20){
            al_draw_scaled_bitmap(fade[9], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }

        return n++;
    }
}

enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int flagOpcoes = 0, flagSom = 1, flagPontos = 0, flagVida = 3;
    int sair = 0, x = 610, y = 294, xInimigo = 610, yInimigo = 380,xInimigo2 = 610,yInimigo2 = 380, t = 0;
    tile tileAtual;
    iniciarTiles(&tileAtual);

    ALLEGRO_BITMAP *pontos[4];
    pontos[0] = al_load_bitmap("../res/images/pontos0.png");
    pontos[1] = al_load_bitmap("../res/images/pontos1.png");
    pontos[2] = al_load_bitmap("../res/images/pontos2.png");
    pontos[3] = al_load_bitmap("../res/images/pontos3.png");
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);

    while (!sair){
        while(!(al_is_event_queue_empty(fila))){

            al_wait_for_event(fila, &evento);
            
            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                return Exit;
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    flagOpcoes = pausa(x,y,&flagSom,fila,evento);

                    if(flagOpcoes){ 
                        return Exit;
                    }
                }
            }
        }
    
        if(falas(fila,evento,tileAtual.ID,x,y,&flagPontos)){
            return Exit;
        }

        al_clear_to_color(branco);
        localizacao(&x,&y,&tileAtual);
        al_draw_bitmap(tileAtual.imagem, 0,0,0);
        addPartes(tileAtual.ID, &xInimigo, &yInimigo, &x, &y);
        addPartes(tileAtual.ID, &xInimigo2, &yInimigo2, &x, &y);
        movimentacao(evento,&tileAtual, &x, &y,&t);
        al_draw_bitmap(pontos[flagPontos],1100,0,0);
        al_flip_display();
        
    }


    return Exit;
}
