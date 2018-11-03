#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"


<<<<<<< HEAD
void movimentacaoInimigos(int tile,int *xInimigo,int *yInimigo, int *x, int *y){
    if(tile == A4){
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

void addPartes(int tile, int *xInimigo, int *yInimigo, int *x, int *y){
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 
    if(tile == B4){
=======
<<<<<<< HEAD

void localizacao(int *x, int *y, int *flagParte, tile *temp){
=======
void localizacao(int *x, int *y, int *i, int *flagEvento, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    if(*i == A1){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 125){
            *x = 125;
        }
        if(*x > 1230){
            *i = A2; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B1;
            *y = 0; 
        }

    }
    else if(*i == A2){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A1;
        }
        if(*x > 1230){
            *i = A3; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B2;
            *y = 0; 
        }

    }
    else if(*i == A3){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A2;
        }
        if(*x > 1230){
            *i = A4; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B3;
            *y = 0; 
        }

    }
    else if(*i == A4){
        if(*flagEvento == 1 ){
            falas(fila,evento,1);
            *flagEvento = 0;               
        }
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A3;
        }
        if(*x > 1230){
            *i = A5; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B4;
            *y = 0; 
        }

    }else if(*i == A5){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A4;
        }
        if(*x > 1080){
            *x = 1080;
        }else if( *y > 650 ){
            *y = 650; 
        }

    }else if(*i == B1){
        
        if(*y < 0 ){
            *i = A1;
            *y = 650;
        }if(*x < 125){
            *x = 125;
        }
        if(*x > 1230){
            *i = B2; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C1;
            *y = 0; 
        }

    }else if(*i == B2){
        
        if(*y < 0 ){
            *i = A2;
            *y = 650;
        }if(*x < 0){
            *x = 1230;
            *i = B1;
        }
        if(*x > 1230){
            *i = B3; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C2;
            *y = 0; 
        }

    }else if(*i == B3){
        
        if(*y < 0 ){
            *i = A3;
            *y = 650;
        }if(*x < 0){
            *x = 1230;
            *i = B2;
        }
        if(*x > 1230){
            *i = B4; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C3;
            *y = 0; 
        }

    }else if( *i == B4 ){
        if(*y < 0){
            *i = A4;
            *y = 650; 
        }else if(*x < 0){
            *x = 1230;
            *i = B3;
        }
        if(*x > 1230){
            *x = 1230;
        }
        if(*y > 650 ){
            *i = C4;
            *y = 0; 
        }
>>>>>>> 0b1c6de14dc555000d7c6eb3545dbe5796576bb9
>>>>>>> master

    }else if(tile == A4){
        movimentacaoInimigos(tile,xInimigo,yInimigo,x,y);
        al_draw_scaled_bitmap(inimigo,0,0,238,294,*xInimigo,*yInimigo,48,66,0);
    }
    al_destroy_bitmap(inimigo);

}

void colisao(tile *tileAtual, int *x, int *y, int ID){
    col *temp;
    temp = tileAtual->lista->primeiro;

    while(temp != NULL){
        
        //48 = largura, 66 = altura -> y
        //66 = largura, 48 = altura -> x
        
        switch(ID){
            case 1:
                if((*x+25 < temp->x && *x+25 > temp->x0) && (*y < temp->y && *y > temp->y0)){
                    *y += 5;
                }
            break;
            case 2:
                if((*x+25 < temp->x && *x+25 > temp->x0) && (*y+65 < temp->y && *y+65 > temp->y0)){
                    *y -= 5;
                }
            break;
            case 3:
                if((*x+65 < temp->x && *x+65 > temp->x0) && (*y+25 < temp->y && *y+25 > temp->y0)){
                    *x -= 5;    
                }
            break;
            case 4:
                if((*x < temp->x && *x > temp->x0) && (*y+25 < temp->y && *y+25 > temp->y0)){
                    *x += 5;
                }
            break;
        }
    
        temp = temp->proximo;
    }

}

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
