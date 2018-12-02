#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

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

    // === A1 ===

    tileA1->ID = A1;
    tileA1->esquerda = NULL;
    tileA1->direita = tileA2;
    tileA1->cima = NULL;
    tileA1->baixo = tileB1;
    tileA1->colisao = al_load_bitmap("../res/tiles/colisao/Tile-A1.png");
    tileA1->imagem = al_load_bitmap("../res/images/tiles/Tile-A1.png");
    tileA1->arvores = al_load_bitmap("../res/images/tiles/Tile-A1-Arvore.png");

    // === A2 ===

    tileA2->ID = A2;
    tileA2->esquerda = tileA1;
    tileA2->direita = tileA3;
    tileA2->cima = NULL;
    tileA2->baixo = tileB2;
    tileA2->colisao = al_load_bitmap("../res/tiles/colisao/Tile-A2.png");
    tileA2->imagem = al_load_bitmap("../res/images/tiles/Tile-A2.png");
    tileA2->arvores = al_load_bitmap("../res/images/tiles/Tile-A2-Arvore.png");

    // === A3 ===

    tileA3->ID = A3;
    tileA3->esquerda = tileA2;
    tileA3->direita = tileA4;
    tileA3->cima = NULL;
    tileA3->baixo = tileB3;
    tileA3->colisao = al_load_bitmap("../res/tiles/colisao/Tile-A3.png");
    tileA3->imagem = al_load_bitmap("../res/images/tiles/Tile-A3.png");
    tileA3->arvores = al_load_bitmap("../res/images/tiles/Tile-A3-Arvore.png");

    // === A4 ===

    tileA4->ID = A4;
    tileA4->esquerda = tileA3;
    tileA4->direita = tileA5;
    tileA4->cima = NULL;
    tileA4->baixo = tileB4;
    tileA4->colisao = al_load_bitmap("../res/tiles/colisao/Tile-A4.png");
    tileA4->imagem = al_load_bitmap("../res/images/tiles/Tile-A4.png");
    tileA4->arvores = al_load_bitmap("../res/images/tiles/Tile-A4-Arvore.png");

    // === A5 ===

    tileA5->ID = A5;
    tileA5->esquerda = tileA4;
    tileA5->direita = NULL;
    tileA5->cima = NULL;
    tileA5->baixo = NULL;
    tileA5->colisao = al_load_bitmap("../res/tiles/colisao/Tile-A5.png");
    tileA5->imagem = al_load_bitmap("../res/images/tiles/Tile-A5.png");
    tileA5->arvores = al_load_bitmap("../res/images/tiles/Tile-A5-Arvore.png");


    // === B1 ===

    tileB1->ID = B1;
    tileB1->esquerda = NULL;
    tileB1->direita = tileB2;
    tileB1->cima = tileA1;
    tileB1->baixo = tileC1;
    tileB1->colisao = al_load_bitmap("../res/tiles/colisao/Tile-B1.png");
    tileB1->imagem = al_load_bitmap("../res/images/tiles/Tile-B1.png");
    tileB1->arvores = al_load_bitmap("../res/images/tiles/Tile-B1-Arvore.png");

    // === B2 ===

    tileB2->ID = B2;
    tileB2->esquerda = tileB1;
    tileB2->direita = tileB3;
    tileB2->cima = tileA2;
    tileB2->baixo = tileC2;
    tileB2->colisao = al_load_bitmap("../res/tiles/colisao/Tile-B2.png");
    tileB2->imagem = al_load_bitmap("../res/images/tiles/Tile-B2.png");
    tileB2->arvores = al_load_bitmap("../res/images/tiles/Tile-B2-Arvore.png");

    // === B3 ===

    tileB3->ID = B3;
    tileB3->esquerda = tileB2;
    tileB3->direita = tileB4;
    tileB3->cima = tileA3;
    tileB3->baixo = tileC3;
    tileB3->colisao = al_load_bitmap("../res/tiles/colisao/Tile-B3.png");
    tileB3->imagem = al_load_bitmap("../res/images/tiles/Tile-B3.png");
    tileB3->arvores = al_load_bitmap("../res/images/tiles/Tile-B3-Arvore.png");
    // === B4 ===

    tileB4->ID = B4;
    tileB4->esquerda = tileB3;
    tileB4->direita = NULL;
    tileB4->cima = tileA4;
    tileB4->baixo = tileC4;
    tileB4->colisao = al_load_bitmap("../res/tiles/colisao/Tile-B4.png");
    tileB4->imagem = al_load_bitmap("../res/images/tiles/Tile-B4.png");
    tileB4->arvores = al_load_bitmap("../res/images/tiles/Tile-B4-Arvore.png");

    // === C1 ===

    tileC1->ID = C1;
    tileC1->esquerda = tileC1;
    tileC1->direita = tileC2;
    tileC1->cima = tileB1;
    tileC1->baixo = tileD1;
    tileC1->bInimigo = 1;
    tileC1->xInimigo = 610;
    tileC1->yInimigo = 380;
    tileC1->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C1.png");
    tileC1->imagem = al_load_bitmap("../res/images/tiles/Tile-C1.png");
    tileC1->arvores = al_load_bitmap("../res/images/tiles/Tile-C1-Arvore.png");

    // === C2 ===

    tileC2->ID = C2;
    tileC2->esquerda = tileC1;
    tileC2->direita = tileC3;
    tileC2->cima = tileB2;
    tileC2->baixo = tileD2;
    tileC2->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C2.png");
    tileC2->imagem = al_load_bitmap("../res/images/tiles/Tile-C2.png");
    tileC2->arvores = al_load_bitmap("../res/images/tiles/Tile-C2-Arvore.png");

    // === C3 ===

    tileC3->ID = C3;
    tileC3->esquerda = tileC2;
    tileC3->direita = tileC4;
    tileC3->cima = tileB3;
    tileC3->baixo = tileD3;
    tileC3->bInimigo = 2;
    tileC3->xInimigo = 610;
    tileC3->yInimigo = 565;
    tileC3->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C3.png");
    tileC3->imagem = al_load_bitmap("../res/images/tiles/Tile-C3.png");
    tileC3->arvores = al_load_bitmap("../res/images/tiles/Tile-C3-Arvore.png");

    // === C4 ===

    tileC4->ID = C4;
    tileC4->esquerda = tileC3;
    tileC4->direita = tileC4;
    tileC4->cima = tileB4;
    tileC4->baixo = tileD4;
    tileC4->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C4.png");
    tileC4->imagem = al_load_bitmap("../res/images/tiles/Tile-C4.png");
    tileC4->arvores = al_load_bitmap("../res/images/tiles/Tile-C4-Arvore.png");

    // === C8 ===

    tileC8->ID = C8;
    tileC8->esquerda = NULL;
    tileC8->direita = tileC9;
    tileC8->cima = NULL;
    tileC8->baixo = tileD8;
    tileC8->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C8.png");
    tileC8->imagem = al_load_bitmap("../res/images/tiles/Tile-C8.png");
    tileC8->arvores = al_load_bitmap("../res/images/tiles/Tile-C8-Arvore.png");

    // === C9 ===

    tileC9->ID = C4;
    tileC9->esquerda = tileC8;
    tileC9->direita = NULL;
    tileC9->cima = NULL;
    tileC9->baixo = tileD9;
    tileC9->colisao = al_load_bitmap("../res/tiles/colisao/Tile-C9.png");
    tileC9->imagem = al_load_bitmap("../res/images/tiles/Tile-C9.png");
    tileC9->arvores = al_load_bitmap("../res/images/tiles/Tile-C9-Arvore.png");

    // === D1 ===

    tileD1->ID = D1;
    tileD1->esquerda = NULL;
    tileD1->direita = tileD2;
    tileD1->cima = tileC1;
    tileD1->baixo = NULL;
    tileD1->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D1.png");
    tileD1->imagem = al_load_bitmap("../res/images/tiles/Tile-D1.png");
    tileD1->arvores = al_load_bitmap("../res/images/tiles/pngcuck.png");

    // === D2 ===

    tileD2->ID = D2;
    tileD2->esquerda = tileD1;
    tileD2->direita = tileD3;
    tileD2->cima = tileC2;
    tileD2->baixo = NULL;
    tileD2->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D2.png");
    tileD2->imagem = al_load_bitmap("../res/images/tiles/Tile-D2.png");
    tileD2->arvores = al_load_bitmap("../res/images/tiles/Tile-D2-Arvore.png");

    // === D3 ===

    tileD3->ID = D3;
    tileD3->esquerda = tileD2;
    tileD3->direita = tileD4;
    tileD3->cima = tileC3;
    tileD3->baixo = NULL;
    tileD3->bInimigo = 1;
    tileD3->xInimigo = 610;
    tileD3->yInimigo = 380;
    tileD3->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D3.png");
    tileD3->imagem = al_load_bitmap("../res/images/tiles/Tile-D3.png");
    tileD3->arvores = al_load_bitmap("../res/images/tiles/Tile-D3-Arvore.png");

    // === D4 ===

    tileD4->ID = D4;
    tileD4->esquerda = tileD3;
    tileD4->direita = tileD5;
    tileD4->cima = tileC4;
    tileD4->baixo = NULL;
    tileD4->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D4.png");
    tileD4->imagem = al_load_bitmap("../res/images/tiles/Tile-D4.png");
    tileD4->arvores = al_load_bitmap("../res/images/tiles/Tile-D4-Arvore.png");

    // === D5 ===

    tileD5->ID = D5;
    tileD5->esquerda = tileD4;
    tileD5->direita = tileD6;
    tileD5->cima = NULL;
    tileD5->baixo = NULL;
    tileD5->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D5.png");
    tileD5->imagem = al_load_bitmap("../res/images/tiles/Tile-D5.png");
    tileD5->arvores = al_load_bitmap("../res/images/tiles/Tile-D5-Arvore.png");

    // === D6 ===

    tileD6->ID = D6;
    tileD6->esquerda = tileD5;
    tileD6->direita = tileD7;
    tileD6->cima = NULL;
    tileD6->baixo = NULL;
    tileD6->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D6.png");
    tileD6->imagem = al_load_bitmap("../res/images/tiles/Tile-D6.png");
    tileD6->arvores = al_load_bitmap("../res/images/tiles/Tile-D6-Arvore.png");

    // === D7 ===

    tileD7->ID = D7;
    tileD7->esquerda = tileD6;
    tileD7->direita = tileD8;
    tileD7->cima = NULL;
    tileD7->baixo = tileE7;
    tileD7->bInimigo = 2;
    tileD7->xInimigo = 640;
    tileD7->yInimigo = 10;
    tileD7->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D7.png");
    tileD7->imagem = al_load_bitmap("../res/images/tiles/Tile-D7.png");
    tileD7->arvores = al_load_bitmap("../res/images/tiles/Tile-D7-Arvore.png");

    // === D8 ===

    tileD8->ID = D8;
    tileD8->esquerda = tileD7;
    tileD8->direita = tileD9;
    tileD8->cima = tileC8;
    tileD8->baixo = tileE8;
    tileD8->bInimigo = 2;
    tileD8->xInimigo = 640;
    tileD8->yInimigo = 580;
    tileD8->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D8.png");
    tileD8->imagem = al_load_bitmap("../res/images/tiles/Tile-D8.png");
    tileD8->arvores = al_load_bitmap("../res/images/tiles/Tile-D8-Arvore.png");

    // === D9 ===

    tileD9->ID = D9;
    tileD9->esquerda = tileD8;
    tileD9->direita = tileD10;
    tileD9->cima = tileC9;
    tileD9->baixo = tileE9;
    tileD9->bInimigo = 2;
    tileD9->xInimigo = 640;
    tileD9->yInimigo = 40;
    tileD9->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D9.png");
    tileD9->imagem = al_load_bitmap("../res/images/tiles/Tile-D9.png");
    tileD9->arvores = al_load_bitmap("../res/images/tiles/Tile-D9-Arvore.png");

    // === D10 ===

    tileD10->ID = D10;
    tileD10->esquerda = tileD9;
    tileD10->direita = NULL;
    tileD10->cima = NULL;
    tileD10->baixo = tileE10;
    tileD10->bInimigo = 1;
    tileD10->xInimigo = 840;
    tileD10->yInimigo = 580;
    tileD10->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D10.png");
    tileD10->imagem = al_load_bitmap("../res/images/tiles/Tile-D10.png");
    tileD10->arvores = al_load_bitmap("../res/images/tiles/pngcuck.png");

    // === E7 ===

    tileE7->ID = E7;
    tileE7->esquerda = NULL;
    tileE7->direita = tileE8;
    tileE7->cima = tileD7;
    tileE7->baixo = tileF7;
    tileE7->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E7.png");
    tileE7->imagem = al_load_bitmap("../res/images/tiles/Tile-E7.png");
    tileE7->arvores = al_load_bitmap("../res/images/tiles/Tile-E7-Arvore.png");

    // === E8 ===

    tileE8->ID = E8;
    tileE8->esquerda = tileE7;
    tileE8->direita = tileE9;
    tileE8->cima = tileD8;
    tileE8->baixo = tileF8;
    tileE8->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E8.png");
    tileE8->imagem = al_load_bitmap("../res/images/tiles/Tile-E8.png");
    tileE8->arvores = al_load_bitmap("../res/images/tiles/Tile-E8-Arvore.png");

    // === E9 ===

    tileE9->ID = E9;
    tileE9->esquerda = tileE8;
    tileE9->direita = tileE10;
    tileE9->cima = tileD9;
    tileE9->baixo = tileF9;
    tileE9->bInimigo = 2;
    tileE9->xInimigo = 670;
    tileE9->yInimigo = 180;
    tileE9->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E9.png");
    tileE9->imagem = al_load_bitmap("../res/images/tiles/Tile-E9.png");
    tileE9->arvores = al_load_bitmap("../res/images/tiles/Tile-E9-Arvore.png");

    // === E10 ===

    tileE10->ID = E10;
    tileE10->esquerda = tileE9;
    tileE10->direita = tileE11;
    tileE10->cima = tileD10;
    tileE10->baixo = tileF10;
    tileE10->bInimigo = 1;
    tileE10->xInimigo = 840;
    tileE10->yInimigo = 280;
    tileE10->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E10.png");
    tileE10->imagem = al_load_bitmap("../res/images/tiles/Tile-E10.png");
    tileE10->arvores = al_load_bitmap("../res/images/tiles/Tile-E10-Arvore.png");

    // === E11 ===

    tileE11->ID = E11;
    tileE11->esquerda = tileE10;
    tileE11->direita = NULL;
    tileE11->cima = NULL;
    tileE11->baixo = NULL;
    tileE11->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E11.png");
    tileE11->imagem = al_load_bitmap("../res/images/tiles/Tile-E11.png");
    tileE11->arvores = al_load_bitmap("../res/images/tiles/Tile-E11-Arvore.png");

    // === F7 ===

    tileF7->ID = F7;
    tileF7->esquerda = NULL;
    tileF7->direita = tileF8;
    tileF7->cima = tileE7;
    tileF7->baixo = NULL;
    tileF7->bInimigo = 2;
    tileF7->xInimigo = 640;
    tileF7->yInimigo = 310;
    tileF7->colisao = al_load_bitmap("../res/tiles/colisao/Tile-F7.png");
    tileF7->imagem = al_load_bitmap("../res/images/tiles/Tile-F7.png");
    tileF7->arvores = al_load_bitmap("../res/images/tiles/Tile-F7-Arvore.png");

    // === F8 ===

    tileF8->ID = F8;
    tileF8->esquerda = tileF7;
    tileF8->direita = tileF9;
    tileF8->cima = tileE8;
    tileF8->baixo = NULL;
    tileF8->bInimigo = 1;
    tileF8->xInimigo = 840;
    tileF8->yInimigo = 580;
    tileF8->colisao = al_load_bitmap("../res/tiles/colisao/Tile-F8.png");
    tileF8->imagem = al_load_bitmap("../res/images/tiles/Tile-F8.png");
    tileF8->arvores = al_load_bitmap("../res/images/tiles/pngcuck.png");
    
    // === F9 ===

    tileF9->ID = F9;
    tileF9->esquerda = tileF8;
    tileF9->direita = tileF10;
    tileF9->cima = tileE9;
    tileF9->baixo = tileG9;
    tileF9->colisao = al_load_bitmap("../res/tiles/colisao/Tile-F9.png");
    tileF9->imagem = al_load_bitmap("../res/images/tiles/Tile-F9.png");
    tileF9->arvores = al_load_bitmap("../res/images/tiles/Tile-F9-Arvore.png");

    // === F10 ===

    tileF10->ID = F10;
    tileF10->esquerda = tileF9;
    tileF10->direita = NULL;
    tileF10->cima = tileE10;
    tileF10->baixo = tileG10;
    tileF10->bInimigo = 1;
    tileF10->xInimigo = 150;
    tileF10->yInimigo = 580;
    tileF10->colisao = al_load_bitmap("../res/tiles/colisao/Tile-F10.png");
    tileF10->imagem = al_load_bitmap("../res/images/tiles/Tile-F10.png");
    tileF10->arvores = al_load_bitmap("../res/images/tiles/Tile-F10-Arvore.png");

    // === G9 ===

    tileG9->ID = G9;
    tileG9->esquerda = NULL;
    tileG9->direita = tileG10;
    tileG9->cima = tileF9;
    tileG9->baixo = NULL;
    tileG9->colisao = al_load_bitmap("../res/tiles/colisao/Tile-G9.png");
    tileG9->imagem = al_load_bitmap("../res/images/tiles/Tile-G9.png");
    tileG9->arvores = al_load_bitmap("../res/images/tiles/Tile-G9-Arvore.png");

    // === G10 ===

    tileG10->ID = G10;
    tileG10->esquerda = tileG9;
    tileG10->direita = NULL;
    tileG10->cima = tileF10;
    tileG10->baixo = NULL;
    tileG10->colisao = al_load_bitmap("../res/tiles/colisao/Tile-G10.png");
    tileG10->imagem = al_load_bitmap("../res/images/tiles/Tile-G10.png");
    tileG10->arvores = al_load_bitmap("../res/images/tiles/Tile-G10-Arvore.png");

    *tileAtual = *tileB4;
}
