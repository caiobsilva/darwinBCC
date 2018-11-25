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
    no->x = x + 65;
    no->y0 = y;
    no->y = y + 45;
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
    no->x = x + 250;
    no->y0 = y;
    no->y = y + 240;
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

void inserirMar_V(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 124;
    no->y0 = y;
    no->y = y + 720;
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

void inserirMar_H(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 1280;
    no->y0 = y;
    no->y = y + 124;
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
    no->x = x + 1280;
    no->y0 = y;
    no->y = y + 160;
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

void inserirNinho(listaCol *lista, int x, int y){
    
    col *no;
    no = malloc(sizeof(col));

    no->x0 = x;
    no->x = x + 50;
    no->y0 = y;
    no->y = y + 35;
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
    tile *tileC1,*tileC2,*tileC3,*tileC4,*tileC8,*tileC9;
    tile *tileD1,*tileD2,*tileD3,*tileD4,*tileD5,*tileD6,*tileD7,*tileD8,*tileD9,*tileD10;
    tile *tileE7,*tileE8,*tileE9,*tileE10,*tileE11;
    tile *tileF7,*tileF8,*tileF9,*tileF10;
    tile *tileG9,*tileG10;
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
    tileC8 = malloc(sizeof(tile));
    tileC9 = malloc(sizeof(tile));
    tileD1 = malloc(sizeof(tile));
    tileD2 = malloc(sizeof(tile));
    tileD3 = malloc(sizeof(tile));
    tileD4 = malloc(sizeof(tile));
    tileD5 = malloc(sizeof(tile));
    tileD6 = malloc(sizeof(tile));
    tileD7 = malloc(sizeof(tile));
    tileD8 = malloc(sizeof(tile));
    tileD9 = malloc(sizeof(tile));
    tileD10 = malloc(sizeof(tile));
    tileE7 = malloc(sizeof(tile));
    tileE8 = malloc(sizeof(tile));
    tileE9 = malloc(sizeof(tile));
    tileE10 = malloc(sizeof(tile));
    tileE11 = malloc(sizeof(tile));
    tileF7 = malloc(sizeof(tile));
    tileF8 = malloc(sizeof(tile));
    tileF9 = malloc(sizeof(tile));
    tileF10 = malloc(sizeof(tile));
    tileG9 = malloc(sizeof(tile));
    tileG10 = malloc(sizeof(tile));

    /*

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

    */

    // === A1 === 

    tileA1->ID = A1;
    tileA1->esquerda = NULL;
    tileA1->direita = tileA2;
    tileA1->cima = NULL;
    tileA1->baixo = tileB1;
    tileA1->imagem = al_load_bitmap("../res/images/tiles/Tile-A1.png");
    tileA1->arvores = al_load_bitmap("../res/images/tiles/Tile-A1-Arvore.png");
    /*
    tileA1->lista = colA1;
    iniciarLista(colA1);
    inserirMar_H(colA1,0,0);
    inserirMar_V(colA1,0,0);
    */

    // === A2 === 
 
    tileA2->ID = A2;
    tileA2->esquerda = tileA1;
    tileA2->direita = tileA3;
    tileA2->cima = NULL;
    tileA2->baixo = tileB2;
    tileA2->imagem = al_load_bitmap("../res/images/tiles/Tile-A2.png");
    tileA2->arvores = al_load_bitmap("../res/images/tiles/Tile-A2-Arvore.png");
    /*
    tileA2->lista = colA2;
    iniciarLista(colA2);
    inserirMar_H(colA2,0,0);
    */

    // === A3 === 
 
    tileA3->ID = A3;
    tileA3->esquerda = tileA2;
    tileA3->direita = tileA4;
    tileA3->cima = NULL;
    tileA3->baixo = tileB3;
    tileA3->imagem = al_load_bitmap("../res/images/tiles/Tile-A3.png");
    tileA3->arvores = al_load_bitmap("../res/images/tiles/Tile-A3-Arvore.png");
    /*
    tileA3->lista = colA3;
    iniciarLista(colA3);
    inserirMar_H(colA3,0,0);
    */
    
    // === A4 === 

    tileA4->ID = A4;
    tileA4->esquerda = tileA3;
    tileA4->direita = tileA5;
    tileA4->cima = NULL;
    tileA4->baixo = tileB4;
    tileA4->imagem = al_load_bitmap("../res/images/tiles/Tile-A4.png");
    tileA4->arvores = al_load_bitmap("../res/images/tiles/Tile-A4-Arvore.png");
/*
    iniciarLista(colA4);
    tileA4->lista = colA4;
    inserirMar_H(colA4,0,0);
    */

    // === A5 === 

    tileA5->ID = A5;
    tileA5->esquerda = tileA4;
    tileA5->direita = NULL;
    tileA5->cima = NULL;
    tileA5->baixo = NULL;
    tileA5->imagem = al_load_bitmap("../res/images/tiles/Tile-A5.png");
    tileA5->arvores = al_load_bitmap("../res/images/tiles/Tile-A5-Arvore.png");
    /*
    tileA5->lista = colA5;
    iniciarLista(colA5);
    inserirMar_H(colA5,0,0);
    inserirMar_V(colA5,1153,0);
    */


    // === B1 === 

    tileB1->ID = B1;
    tileB1->esquerda = NULL;
    tileB1->direita = tileB2;
    tileB1->cima = tileA1;
    tileB1->baixo = tileC1;
    tileB1->imagem = al_load_bitmap("../res/images/tiles/Tile-B1.png");
    tileB1->arvores = al_load_bitmap("../res/images/tiles/Tile-B1-Arvore.png");
    /*
    tileB1->lista = colB1;
    iniciarLista(colB1);
    inserirMar_V(colB1,0,0);
    */
    
    // === B2 === 
 
    tileB2->ID = B2;
    tileB2->esquerda = tileB1;
    tileB2->direita = tileB3;
    tileB2->cima = tileA2;
    tileB2->baixo = tileC2;
    tileB2->imagem = al_load_bitmap("../res/images/tiles/Tile-B2.png");
    tileB2->arvores = al_load_bitmap("../res/images/tiles/Tile-B2-Arvore.png");
    /*
    tileB2->lista = colB2;
    iniciarLista(colB2);
    */

    // === B3 === 
 
    tileB3->ID = B3;
    tileB3->esquerda = tileB2;
    tileB3->direita = tileB4;
    tileB3->cima = tileA3;
    tileB3->baixo = tileC3;
    tileB3->imagem = al_load_bitmap("../res/images/tiles/Tile-B3.png");
    tileB3->arvores = al_load_bitmap("../res/images/tiles/Tile-B3-Arvore.png");
    // tileB3->lista = colB3;
    // iniciarLista(colB3);

    // === B4 === 

    tileB4->ID = B4;
    tileB4->esquerda = tileB3;
    tileB4->direita = NULL;
    tileB4->cima = tileA4;
    tileB4->baixo = tileC4;
    tileB4->imagem = al_load_bitmap("../res/images/tiles/Tile-B4.png");
    tileB4->arvores = al_load_bitmap("../res/images/tiles/Tile-B4-Arvore.png");
    // tileB4->lista = colB4;
    // // iniciarLista(colB4);
    // inserirPedra(colB4,290,475);
    // inserirPedra(colB4,70,130);
    // inserirPedra(colB4,105,105);
    // inserirPedra(colB4,980,590);

    // === C1 === 

    tileC1->ID = C1;
    tileC1->esquerda = tileC1;
    tileC1->direita = tileC2;
    tileC1->cima = tileB1;
    tileC1->baixo = tileD1;
    tileC1->imagem = al_load_bitmap("../res/images/tiles/Tile-C1.png");
    tileC1->arvores = al_load_bitmap("../res/images/tiles/Tile-C1-Arvore.png");
    // tileC1->lista = colC1;
    // iniciarLista(colC1);
    //inserirMar_V(colC1,0,0);

    // === C2 === 
 
    tileC2->ID = C2;
    tileC2->esquerda = tileC1;
    tileC2->direita = tileC3;
    tileC2->cima = tileB2;
    tileC2->baixo = tileD2;
    tileC2->imagem = al_load_bitmap("../res/images/tiles/Tile-C2.png");
    tileC2->arvores = al_load_bitmap("../res/images/tiles/Tile-C2-Arvore.png");
    // tileC2->lista = colC2;
    // iniciarLista(colC2);

    // === C3 === 
 
    tileC3->ID = C3;
    tileC3->esquerda = tileC2;
    tileC3->direita = tileC4;
    tileC3->cima = tileB3;
    tileC3->baixo = tileD3;
    tileC3->imagem = al_load_bitmap("../res/images/tiles/Tile-C3.png");
    tileC3->arvores = al_load_bitmap("../res/images/tiles/Tile-C3-Arvore.png");
    // tileC3->lista = colC3;
    // iniciarLista(colC3);

    // === C4 === 

    tileC4->ID = C4;
    tileC4->esquerda = tileC3;
    tileC4->direita = tileC4;
    tileC4->cima = tileB4;
    tileC4->baixo = tileD4;
    tileC4->imagem = al_load_bitmap("../res/images/tiles/Tile-C4.png");
    tileC4->arvores = al_load_bitmap("../res/images/tiles/Tile-C4-Arvore.png");
    // tileC4->lista = colC4;
    // iniciarLista(colC4);

    // === C8 ===

    tileC8->ID = C8;
    tileC8->esquerda = NULL;
    tileC8->direita = tileC9;
    tileC8->cima = NULL;
    tileC8->baixo = tileD8;
    tileC8->imagem = al_load_bitmap("../res/images/tiles/Tile-C8.png");
    tileC8->arvores = al_load_bitmap("../res/images/tiles/Tile-C8-Arvore.png");

    // === C9 ===

    tileC9->ID = C4;
    tileC9->esquerda = tileC8;
    tileC9->direita = NULL;
    tileC9->cima = NULL;
    tileC9->baixo = tileD9;
    tileC9->imagem = al_load_bitmap("../res/images/tiles/Tile-C9.png");
    tileC9->arvores = al_load_bitmap("../res/images/tiles/Tile-C9-Arvore.png");

    // === D1 === 

    tileD1->ID = D1;
    tileD1->esquerda = NULL;
    tileD1->direita = tileD2;
    tileD1->cima = tileC1;
    tileD1->baixo = NULL;
    tileD1->imagem = al_load_bitmap("../res/images/tiles/Tile-D1.png");
    tileD1->arvores = NULL;
    // tileD1->lista = colD1;
    // iniciarLista(colD1);
    //inserirMar_V(colD1,0,0);
    //inserirMar_H(colD1,0,595);

    // === D2 === 
 
    tileD2->ID = D2;
    tileD2->esquerda = tileD1;
    tileD2->direita = tileD3;
    tileD2->cima = tileC2;
    tileD2->baixo = NULL;
    tileD2->imagem = al_load_bitmap("../res/images/tiles/Tile-D2.png");
    tileD2->arvores = al_load_bitmap("../res/images/tiles/Tile-D2-Arvore.png");
    // tileD2->lista = colD2;
    // iniciarLista(colD2);
    //inserirMar_H(colD2,0,595);

    // === D3 === 
 
    tileD3->ID = D3;
    tileD3->esquerda = tileD2;
    tileD3->direita = tileD4;
    tileD3->cima = tileC3;
    tileD3->baixo = NULL;
    tileD3->imagem = al_load_bitmap("../res/images/tiles/Tile-D3.png");
    tileD3->arvores = al_load_bitmap("../res/images/tiles/Tile-D3-Arvore.png");
    // tileD3->lista = colD3;
    // iniciarLista(colD3);
    //inserirMar_H(colD3,0,595);
    // === D4 === 

    tileD4->ID = D4;
    tileD4->esquerda = tileD3;
    tileD4->direita = tileD5;
    tileD4->cima = tileC4;
    tileD4->baixo = NULL;
    tileD4->imagem = al_load_bitmap("../res/images/tiles/Tile-D4.png");
    tileD4->arvores = al_load_bitmap("../res/images/tiles/Tile-D4-Arvore.png");
    // tileD4->lista = colD4;
    // iniciarLista(colD4);
    //inserirMar_H(colD4,0,595);

    // === D5 === 

    tileD5->ID = D5;
    tileD5->esquerda = tileD4;
    tileD5->direita = tileD6;
    tileD5->cima = NULL;
    tileD5->baixo = NULL;
    tileD5->imagem = al_load_bitmap("../res/images/tiles/Tile-D5.png");
    tileD5->arvores = al_load_bitmap("../res/images/tiles/Tile-D5-Arvore.png");
    // tileD5->lista = colD5;
    // iniciarLista(colD5);
    //inserirMar_H(colD5,0,595);

    // === D6 ===

    tileD6->ID = D6;
    tileD6->esquerda = tileD5;
    tileD6->direita = tileD7;
    tileD6->cima = NULL;
    tileD6->baixo = NULL;
    tileD6->imagem = al_load_bitmap("../res/images/tiles/Tile-D6.png");
    tileD6->arvores = al_load_bitmap("../res/images/tiles/Tile-D6-Arvore.png");

    // === D7 ===

    tileD7->ID = D7;
    tileD7->esquerda = tileD6;
    tileD7->direita = tileD8;
    tileD7->cima = NULL;
    tileD7->baixo = tileE7;
    tileD7->imagem = al_load_bitmap("../res/images/tiles/Tile-D7.png");
    tileD7->arvores = al_load_bitmap("../res/images/tiles/Tile-D7-Arvore.png");

    // === D8 ===

    tileD8->ID = D8;
    tileD8->esquerda = tileD7;
    tileD8->direita = tileD9;
    tileD8->cima = tileC8;
    tileD8->baixo = tileE8;
    tileD8->imagem = al_load_bitmap("../res/images/tiles/Tile-D8.png");
    tileD8->arvores = al_load_bitmap("../res/images/tiles/Tile-D8-Arvore.png");

    // === D9 ===

    tileD9->ID = D9;
    tileD9->esquerda = tileD8;
    tileD9->direita = tileD10;
    tileD9->cima = tileC9;
    tileD9->baixo = tileE9;
    tileD9->imagem = al_load_bitmap("../res/images/tiles/Tile-D9.png");
    tileD9->arvores = al_load_bitmap("../res/images/tiles/Tile-D9-Arvore.png");

    // === D10 ===

    tileD10->ID = D10;
    tileD10->esquerda = tileD9;
    tileD10->direita = NULL;
    tileD10->cima = NULL;
    tileD10->baixo = tileE10;
    tileD10->imagem = al_load_bitmap("../res/images/tiles/Tile-D10.png");
    tileD1->arvores = NULL;

    // === E7 ===

    tileE7->ID = E7;
    tileE7->esquerda = NULL;
    tileE7->direita = tileE8;
    tileE7->cima = tileD7;
    tileE7->baixo = tileF7;
    tileE7->imagem = al_load_bitmap("../res/images/tiles/Tile-E7.png");
    tileE7->arvores = al_load_bitmap("../res/images/tiles/Tile-E7-Arvore.png");

    // === E8 ===

    tileE8->ID = E8;
    tileE8->esquerda = tileE7;
    tileE8->direita = tileE9;
    tileE8->cima = tileD8;
    tileE8->baixo = tileF8;
    tileE8->imagem = al_load_bitmap("../res/images/tiles/Tile-E8.png");
    tileE8->arvores = al_load_bitmap("../res/images/tiles/Tile-E8-Arvore.png");

    // === E9 ===

    tileE9->ID = E9;
    tileE9->esquerda = tileE8;
    tileE9->direita = tileE10;
    tileE9->cima = tileD9;
    tileE9->baixo = tileF9;
    tileE9->imagem = al_load_bitmap("../res/images/tiles/Tile-E9.png");
    tileE9->arvores = al_load_bitmap("../res/images/tiles/Tile-E9-Arvore.png");

    // === E10 ===
    
    tileE10->ID = E10;
    tileE10->esquerda = tileE9;
    tileE10->direita = tileE11;
    tileE10->cima = tileD10;
    tileE10->baixo = tileF10;
    tileE10->imagem = al_load_bitmap("../res/images/tiles/Tile-E10.png");
    tileE10->arvores = al_load_bitmap("../res/images/tiles/Tile-E10-Arvore.png");

    // === E11 ===

    tileE11->ID = E11;
    tileE11->esquerda = tileE10;
    tileE11->direita = NULL;
    tileE11->cima = NULL;
    tileE11->baixo = NULL;
    tileE11->imagem = al_load_bitmap("../res/images/tiles/Tile-E11.png");
    tileE11->arvores = al_load_bitmap("../res/images/tiles/Tile-E11-Arvore.png");

    // === F7 ===

    tileF7->ID = F7;
    tileF7->esquerda = NULL;
    tileF7->direita = tileF8;
    tileF7->cima = tileE7;
    tileF7->baixo = NULL;
    tileF7->imagem = al_load_bitmap("../res/images/tiles/Tile-F7.png");
    tileF7->arvores = al_load_bitmap("../res/images/tiles/Tile-F7-Arvore.png");

    // === F8 ===

    tileF8->ID = F8;
    tileF8->esquerda = tileF7;
    tileF8->direita = tileF9;
    tileF8->cima = tileE8;
    tileF8->baixo = NULL;
    tileF8->imagem = al_load_bitmap("../res/images/tiles/Tile-F8.png");
    tileF8->arvores = NULL;

    // === F9 ===

    tileF9->ID = F9;
    tileF9->esquerda = tileF8;
    tileF9->direita = tileF10;
    tileF9->cima = tileE9;
    tileF9->baixo = tileG9;
    tileF9->imagem = al_load_bitmap("../res/images/tiles/Tile-F9.png");
    tileF9->arvores = al_load_bitmap("../res/images/tiles/Tile-F9-Arvore.png");

    // === F10 ===

    tileF10->ID = F10;
    tileF10->esquerda = tileF9;
    tileF10->direita = NULL;
    tileF10->cima = tileE10;
    tileF10->baixo = tileG10;
    tileF10->imagem = al_load_bitmap("../res/images/tiles/Tile-F10.png");
    tileF10->arvores = al_load_bitmap("../res/images/tiles/Tile-F10-Arvore.png");

    // === G9 ===

    tileG9->ID = G9;
    tileG9->esquerda = NULL;
    tileG9->direita = tileG10;
    tileG9->cima = tileF9;
    tileG9->baixo = NULL;
    tileG9->imagem = al_load_bitmap("../res/images/tiles/Tile-G9.png");
    tileG9->arvores = al_load_bitmap("../res/images/tiles/Tile-G9-Arvore.png");

    // === G10 ===

    tileG10->ID = G10;
    tileG10->esquerda = tileG9;
    tileG10->direita = NULL;
    tileG10->cima = tileF10;
    tileG10->baixo = NULL;
    tileG10->imagem = al_load_bitmap("../res/images/tiles/Tile-G10.png");
    tileG10->arvores = al_load_bitmap("../res/images/tiles/Tile-G10-Arvore.png");

    *tileAtual = *tileB4;
}
