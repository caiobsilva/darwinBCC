#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"


void movimentacaoInimigos(int i,int *xInimigo,int *yInimigo, int *x, int *y){
    if(i == A4){
        if(*xInimigo < *x){
            *xInimigo += 3;
        }else if(*xInimigo > *x){
            *xInimigo -= 3;
        }else if(*yInimigo < *y){
            *yInimigo += 3;
        }else if (*yInimigo > *y){
            *yInimigo -= 3;
        }
    }
}

void addPartes(int i, int *xInimigo, int *yInimigo, int *x, int *y){
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 
    if(i == B4){
        
    }else if(i == A4){
        movimentacaoInimigos(i,xInimigo,yInimigo,x,y);
        al_draw_scaled_bitmap(inimigo,0,0,238,294,*xInimigo,*yInimigo,48,66,0);
    }
    al_destroy_bitmap(inimigo);

}

enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int flagInimigos = 1, flagOpcoes = 0, flagPartes = B4, flagSom = 1;
    int n = 0, sair = 0,  x = 610, y = 294, xInimigo = 610, yInimigo = 380, t = 0;

    tile tileAtual;

    iniciarTiles(&tileAtual);

    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
    ALLEGRO_KEYBOARD_STATE tecla;

    
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

        printf("Tile atual = %d\n", tileAtual.ID);

        al_clear_to_color(branco);
        localizacao(&x,&y,tileAtual.ID,&tileAtual);
        al_draw_bitmap(tileAtual.imagem, 0,0,0);
        addPartes(flagPartes, &xInimigo, &yInimigo, &x, &y);
        movimentacao(evento, &x, &y,&t);
        al_flip_display();
        
    }


    return Exit;
}
