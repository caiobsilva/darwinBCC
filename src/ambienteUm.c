#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

#define A1 0
#define A2 1
#define A3 2
#define A4 3
#define A5 4
#define B1 5
#define B2 6
#define B3 7
#define B4 8
#define C1 9
#define C2 10
#define C3 11
#define C4 12
#define D1 13
#define D2 14
#define D3 15
#define D4 16
#define D5 17


void iniciarTiles(tile *tileAtual){ 
    tile *tileA1,*tileA2,*tileA3,*tileA4,*tileA5;
    tile *tileB1,*tileB2,*tileB3,*tileB4;
    tile *tileC1,*tileC2,*tileC3,*tileC4;
    tile *tileD1,*tileD2,*tileD3,*tileD4,*tileD5;
    tileA1 = malloc(sizeof(tile));
    tileA2 = malloc(sizeof(tile));
    tileA3 = malloc(sizeof(tile));
    tileA4 = malloc(sizeof(tile));
    tileA5 = malloc(sizeof(tile));
    tileB1 = malloc(sizeof(tile));
    tileB2 = malloc(sizeof(tile));
    tileB3 = malloc(sizeof(tile));
    tileB4 = malloc(sizeof(tile));
    tileC1 = malloc(sizeof(tile));
    tileC2 = malloc(sizeof(tile));
    tileC3 = malloc(sizeof(tile));
    tileC4 = malloc(sizeof(tile));
    tileD1 = malloc(sizeof(tile));
    tileD2 = malloc(sizeof(tile));
    tileD3 = malloc(sizeof(tile));
    tileD4 = malloc(sizeof(tile));
    tileD5 = malloc(sizeof(tile));

    // === A1 === 
    tileA1->esquerda = NULL;
    tileA1->direita = tileA2;
    tileA1->cima = NULL;
    tileA1-> baixo = tileB1;
    tileA1->imagem = al_load_bitmap("../res/images/tiles/Tile-A1.png");

    tileAtual = tileA1;


}


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

        al_clear_to_color(branco);
        localizacao(&x,&y,&flagPartes,&tileAtual);
        al_draw_bitmap(tileAtual.imagem, 0,0,0);
        addPartes(flagPartes, &xInimigo, &yInimigo, &x, &y);
        movimentacao(evento, &x, &y,&t);
        al_flip_display();
        
    }

    return Exit;
}
