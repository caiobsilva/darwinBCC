#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

int vazia(listaCol *lista){
    if(lista->tamanho == 0){
        return 1;
    }
    return 0;
}

void inserirPedra(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 50;
    no->y0 = y;
    no->y = y + 50;
    no->proximo = NULL;
    
    if(vazia(lista)){
        lista->primeiro = no;
        lista->ultimo = no;
    }else{
        lista->ultimo->proximo = no;
        lista->ultimo = no;
    }
    lista->tamanho += 1;
}

void inserirArvore(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 20;
    no->y0 = y;
    no->y = y + 20;
    no->proximo = NULL;
    
    if(vazia(lista)){
        lista->primeiro = no;
        lista->ultimo = no;   
    }else{
        lista->ultimo->proximo = no;
        lista->ultimo = no;
    }
    lista->tamanho += 1;

}

void inserirMar(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 20;
    no->y0 = y;
    no->y = y + 20;
    no->proximo = NULL;
    
    if(vazia(lista)){
        lista->primeiro = no;
        lista->ultimo = no;   
    }else{
        lista->ultimo->proximo = no;
        lista->ultimo = no;
    }
    lista->tamanho += 1;

}

void inserirRio(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 20;
    no->y0 = y;
    no->y = y + 20;
    no->proximo = NULL;
    
    if(vazia(lista)){
        lista->primeiro = no;
        lista->ultimo = no;   
    }else{
        lista->ultimo->proximo = no;
        lista->ultimo = no;
    }
    lista->tamanho += 1;

}

void iniciarLista(listaCol *lista){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

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

    listaCol *colA1,*colA2,*colA3,*colA4,*colA5;
    listaCol *colB1,*colB2,*colB3,*colB4;
    listaCol *colC1,*colC2,*colC3,*colC4;
    listaCol *colD1,*colD2,*colD3,*colD4,*colD5;
    colA1 = malloc(sizeof(listaCol));
    colA2 = malloc(sizeof(listaCol));
    colA3 = malloc(sizeof(listaCol));
    colA4 = malloc(sizeof(listaCol));
    colA5 = malloc(sizeof(listaCol));
    colB1 = malloc(sizeof(listaCol));
    colB2 = malloc(sizeof(listaCol));
    colB3 = malloc(sizeof(listaCol));
    colB4 = malloc(sizeof(listaCol));
    colC1 = malloc(sizeof(listaCol));
    colC2 = malloc(sizeof(listaCol));
    colC3 = malloc(sizeof(listaCol));
    colC4 = malloc(sizeof(listaCol));
    colD1 = malloc(sizeof(listaCol));
    colD2 = malloc(sizeof(listaCol));
    colD3 = malloc(sizeof(listaCol));
    colD4 = malloc(sizeof(listaCol));
    colD5 = malloc(sizeof(listaCol));

    // === A1 === 

    tileA1->ID = A1;
    tileA1->esquerda = NULL;
    tileA1->direita = tileA2;
    tileA1->cima = NULL;
    tileA1-> baixo = tileB1;
    tileA1->imagem = al_load_bitmap("../res/images/tiles/Tile-A1.png");
    tileA1->lista = colA1;
    iniciarLista(colA1);

    // === A2 === 
 
    tileA2->ID = A2;
    tileA2->esquerda = tileA1;
    tileA2->direita = tileA3;
    tileA2->cima = NULL;
    tileA2-> baixo = tileB2;
    tileA2->imagem = al_load_bitmap("../res/images/tiles/Tile-A2.png");
    tileA2->lista = colA2;
    iniciarLista(colA2);

    // === A3 === 
 
    tileA3->ID = A3;
    tileA3->esquerda = tileA2;
    tileA3->direita = tileA4;
    tileA3->cima = NULL;
    tileA3-> baixo = tileB3;
    tileA3->imagem = al_load_bitmap("../res/images/tiles/Tile-A3.png");
    tileA3->lista = colA3;
    iniciarLista(colA3);
    
    // === A4 === 

    tileA4->ID = A4;
    tileA4->esquerda = tileA3;
    tileA4->direita = tileA5;
    tileA4->cima = NULL;
    tileA4-> baixo = tileB4;
    tileA4->imagem = al_load_bitmap("../res/images/tiles/Tile-A4.png");
    iniciarLista(colA4);
    tileA4->lista = colA4;
    iniciarLista(colA4);

    // === A5 === 

    tileA5->ID = A5;
    tileA5->esquerda = tileA4;
    tileA5->direita = NULL;
    tileA5->cima = NULL;
    tileA5-> baixo = NULL;
    tileA5->imagem = al_load_bitmap("../res/images/tiles/Tile-A5.png");
    tileA5->lista = colA5;
    iniciarLista(colA5);


    // === B1 === 

    tileB1->ID = B1;
    tileB1->esquerda = NULL;
    tileB1->direita = tileB2;
    tileB1->cima = tileA1;
    tileB1-> baixo = tileC1;
    tileB1->imagem = al_load_bitmap("../res/images/tiles/Tile-B1.png");
    tileB1->lista = colB1;
    iniciarLista(colB1);

    // === B2 === 
 
    tileB2->ID = B2;
    tileB2->esquerda = tileB1;
    tileB2->direita = tileB3;
    tileB2->cima = tileA2;
    tileB2-> baixo = tileC2;
    tileB2->imagem = al_load_bitmap("../res/images/tiles/Tile-B2.png");
    tileB2->lista = colB2;
    iniciarLista(colB2);

    // === B3 === 
 
    tileB3->ID = B3;
    tileB3->esquerda = tileB2;
    tileB3->direita = tileB4;
    tileB3->cima = tileA3;
    tileB3-> baixo = tileC3;
    tileB3->imagem = al_load_bitmap("../res/images/tiles/Tile-B3.png");
    tileB3->lista = colB3;
    iniciarLista(colB3);

    // === B4 === 

    tileB4->ID = B4;
    tileB4->esquerda = tileB3;
    tileB4->direita = NULL;
    tileB4->cima = tileA4;
    tileB4-> baixo = tileC4;
    tileB4->imagem = al_load_bitmap("../res/images/tiles/Tile-B4.png");
    tileB4->lista = colB4;
    iniciarLista(colB4);
    inserirPedra(colB4,45,565);
    inserirPedra(colB4,45,100);

    // === C1 === 

    tileC1->ID = C1;
    tileC1->esquerda = tileC1;
    tileC1->direita = tileC2;
    tileC1->cima = tileB1;
    tileC1-> baixo = tileD1;
    tileC1->imagem = al_load_bitmap("../res/images/tiles/Tile-C1.png");
    tileC1->lista = colC1;
    iniciarLista(colC1);

    // === C2 === 
 
    tileC2->ID = C2;
    tileC2->esquerda = tileC1;
    tileC2->direita = tileC3;
    tileC2->cima = tileB2;
    tileC2-> baixo = tileD2;
    tileC2->imagem = al_load_bitmap("../res/images/tiles/Tile-C2.png");
    tileC2->lista = colC2;
    iniciarLista(colC2);

    // === C3 === 
 
    tileC3->ID = C3;
    tileC3->esquerda = tileC2;
    tileC3->direita = tileC4;
    tileC3->cima = tileB3;
    tileC3-> baixo = tileD3;
    tileC3->imagem = al_load_bitmap("../res/images/tiles/Tile-C3.png");
    tileC3->lista = colC3;
    iniciarLista(colC3);

    // === C4 === 

    tileC4->ID = C4;
    tileC4->esquerda = tileC3;
    tileC4->direita = tileC4;
    tileC4->cima = tileB4;
    tileC4-> baixo = tileD4;
    tileC4->imagem = al_load_bitmap("../res/images/tiles/Tile-C4.png");
    tileC4->lista = colC4;
    iniciarLista(colC4);


    // === D1 === 

    tileD1->ID = D1;
    tileD1->esquerda = NULL;
    tileD1->direita = tileD2;
    tileD1->cima = tileC1;
    tileD1-> baixo = NULL;
    tileD1->imagem = al_load_bitmap("../res/images/tiles/Tile-D1.png");
    tileD1->lista = colD1;
    iniciarLista(colD1);

    // === D2 === 
 
    tileD2->ID = D2;
    tileD2->esquerda = tileD1;
    tileD2->direita = tileD3;
    tileD2->cima = tileC2;
    tileD2-> baixo = NULL;
    tileD2->imagem = al_load_bitmap("../res/images/tiles/Tile-D2.png");
    tileD2->lista = colD2;
    iniciarLista(colD2);

    // === D3 === 
 
    tileD3->ID = D3;
    tileD3->esquerda = tileD2;
    tileD3->direita = tileD4;
    tileD3->cima = tileC3;
    tileD3-> baixo = NULL;
    tileD3->imagem = al_load_bitmap("../res/images/tiles/Tile-D3.png");
    tileD3->lista = colD3;
    iniciarLista(colD3);
    // === D4 === 

    tileD4->ID = D4;
    tileD4->esquerda = tileD3;
    tileD4->direita = tileD5;
    tileD4->cima = tileC4;
    tileD4-> baixo = NULL;
    tileD4->imagem = al_load_bitmap("../res/images/tiles/Tile-D4.png");
    tileD4->lista = colD4;
    iniciarLista(colD4);
    // === D5 === 

    tileD5->ID = D5;
    tileD5->esquerda = tileD4;
    tileD5->direita = NULL;
    tileD5->cima = NULL;
    tileD5-> baixo = NULL;
    tileD5->imagem = al_load_bitmap("../res/images/tiles/Tile-D5.png");
    tileD5->lista = colD5;
    iniciarLista(colD5);

    *tileAtual = *tileB4;
}