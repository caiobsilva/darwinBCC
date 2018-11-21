#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

// função para movimentação do inimigo
void movimentacaoInimigos(int tile, int *xInimigo,int *yInimigo, int *x, int *y, int *flagVida){
    static int t, i;
    ALLEGRO_BITMAP *iniTerrestre[8];

    iniTerrestre[0] = al_load_bitmap("../res/images/terrestre/baixo.png");
    iniTerrestre[1] = al_load_bitmap("../res/images/terrestre/baixo2.png");
    iniTerrestre[2] = al_load_bitmap("../res/images/terrestre/cima.png");
    iniTerrestre[3] = al_load_bitmap("../res/images/terrestre/cima2.png");
    iniTerrestre[4] = al_load_bitmap("../res/images/terrestre/direita.png");
    iniTerrestre[5] = al_load_bitmap("../res/images/terrestre/direita2.png");
    iniTerrestre[6] = al_load_bitmap("../res/images/terrestre/esquerda.png");
    iniTerrestre[7] = al_load_bitmap("../res/images/terrestre/esquerda2.png");

    if(*xInimigo < *x - 3){
        *xInimigo += 3;

        if(t <= 12){
            al_draw_scaled_bitmap(iniTerrestre[4], 0, 0, 22, 9, *xInimigo, *yInimigo, 66, 27, 0);
        }else if(t <= 24){
            al_draw_scaled_bitmap(iniTerrestre[5], 0, 0, 22, 9, *xInimigo, *yInimigo, 66, 27, 0);
        }

        i = 4;
    }else if(*xInimigo > *x + 3){
        *xInimigo -= 3;

        if(t <= 12){
            al_draw_scaled_bitmap(iniTerrestre[6], 0, 0, 22, 9, *xInimigo, *yInimigo, 66, 27, 0);
        }else if(t <= 24){
            al_draw_scaled_bitmap(iniTerrestre[7], 0, 0, 22, 9, *xInimigo, *yInimigo, 66, 27, 0);
        }

        i = 6;
    }else if(*yInimigo < *y - 3){
        *yInimigo += 3;

        if(t <= 12){
            al_draw_scaled_bitmap(iniTerrestre[0], 0, 0, 9, 22, *xInimigo, *yInimigo, 27, 66, 0);
        }else if(t <= 24){
            al_draw_scaled_bitmap(iniTerrestre[1], 0, 0, 9, 22, *xInimigo, *yInimigo, 27, 66, 0);
        }

        i = 0;
    }else if (*yInimigo > *y + 3){
        *yInimigo -= 3;

        if(t <= 12){
            al_draw_scaled_bitmap(iniTerrestre[2], 0, 0, 9, 22, *xInimigo, *yInimigo, 27, 66, 0);
        }else if(t <= 24){
            al_draw_scaled_bitmap(iniTerrestre[3], 0, 0, 9, 22, *xInimigo, *yInimigo, 27, 66, 0);
        }

        i = 2;
    }else{
        if(i == 4 || i == 6){
            al_draw_scaled_bitmap(iniTerrestre[i], 0, 0, 22, 9, *x, *y, 66, 27, 0);
        }else{
            al_draw_scaled_bitmap(iniTerrestre[i], 0, 0, 9, 22, *x, *y, 27, 66, 0);
        }
    }

    t += 1;

    if(t > 20){
        t = 0;
    }

    for(int i = 0; i < 8; i++){
        al_destroy_bitmap(iniTerrestre[i]);
    }
}

// função para adicionar extras no ambiente (inimigos e algumas imagens)
void addPartes(int tile, int *xInimigo, int *yInimigo, int *x, int *y, int *flagVida){
    if(tile == A4){
        movimentacaoInimigos(tile,xInimigo,yInimigo,x,y, flagVida);
    }else if(tile == C1){
        movimentacaoInimigos(tile,xInimigo,yInimigo,x,y, flagVida);
    }
}


// função que detecta qualquer tipo de colisão 
/*
void colisao(tile *tileAtual, int *x, int *y, int ID){
    
    col *temp;
    temp = tileAtual->lista->primeiro;

    while(temp != NULL){    
        
        switch(ID){
            case 1:
                if((*x+33 < temp->x && *x+33 > temp->x0) && (*y < temp->y && *y > temp->y0)){
                    *y += 6;
                }
            break;
            case 2:
                if((*x+33 < temp->x && *x+33 > temp->x0) && (*y+65 < temp->y && *y+65 > temp->y0)){
                    *y -= 6;
                }
            break;
            case 3:
                if((*x+65 < temp->x && *x+65 > temp->x0) && (*y+33 < temp->y && *y+33 > temp->y0)){
                    *x -= 6;    
                }
            break;
            case 4:
                if((*x < temp->x && *x > temp->x0) && (*y+33 < temp->y && *y+33 > temp->y0)){
                    *x += 6;
                }
            break;
        }
    
        temp = temp->proximo;
    }   

}
*/

// função que detecta mudança de tile.
void localizacao(int *x, int *y, tile *tileAtual){

    if(tileAtual->esquerda != NULL && *x < 0){
        *x = 1230;
        *tileAtual = *tileAtual->esquerda;

    }else if(tileAtual->direita != NULL && *x > 1230){
        *x = 0;
        *tileAtual = *tileAtual->direita;
    }else if(tileAtual->cima != NULL && *y < 0){
        *y = 650;
        *tileAtual = *tileAtual->cima;
    }else if(tileAtual->baixo != NULL && *y > 650){
        *y = 0;
        *tileAtual = *tileAtual->baixo;
    }

}
