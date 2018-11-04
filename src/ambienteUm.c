#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"


enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int flagOpcoes = 0, flagSom = 1;
    int sair = 0,  x = 610, y = 294, xInimigo = 610, yInimigo = 380,xInimigo2 = 610,yInimigo2 = 380, t = 0;

    tile tileAtual;

    iniciarTiles(&tileAtual);

    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    
    while (!sair){

        while(!(al_is_event_queue_empty(fila))){

            al_wait_for_event(fila, &evento);
            
            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                printf("fechou!\n");
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
    
        if(falas(fila,evento,tileAtual.ID,x,y)){
            return Exit;
        }
        al_clear_to_color(branco);
        localizacao(&x,&y,&tileAtual);
        al_draw_bitmap(tileAtual.imagem, 0,0,0);
        addPartes(tileAtual.ID, &xInimigo, &yInimigo, &x, &y);
        addPartes(tileAtual.ID, &xInimigo2, &yInimigo2, &x, &y);
        movimentacao(evento,&tileAtual, &x, &y,&t);
        al_flip_display();
        
    }


    return Exit;
}
