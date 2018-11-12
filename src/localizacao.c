#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

// função para movimentação do inimigo
void movimentacaoInimigos(int tile, int *xInimigo,int *yInimigo, int *x, int *y, int *flagVida){
    if(*xInimigo < *x - 3){
        *xInimigo += 3;
    }else if(*xInimigo > *x + 3){
        *xInimigo -= 3;
    }else if(*yInimigo < *y - 3){
        *yInimigo += 3;
    }else if (*yInimigo > *y + 3){
        *yInimigo -= 3;
    }
}

// função para adicionar extras no ambiente (inimigos e algumas imagens)
void addPartes(int tile, int *xInimigo, int *yInimigo, int *x, int *y, int *flagVida){
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 
    if(tile == A4){
        movimentacaoInimigos(tile,xInimigo,yInimigo,x,y, flagVida);
        al_draw_scaled_bitmap(inimigo,0,0,238,294,*xInimigo,*yInimigo,48,66,0);
    }else if(tile == C1){
        al_draw_scaled_bitmap(inimigo,0,0,238,294,*xInimigo,*yInimigo,48,66,0);
        movimentacaoInimigos(tile,xInimigo,yInimigo,x,y, flagVida);
    }
    al_destroy_bitmap(inimigo);
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
