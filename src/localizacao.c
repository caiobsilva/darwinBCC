#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

#define TEMPO_PROJETIL 96

void inimigoAquatico(int tile, int *xAquatico, int *yAquatico, int *x, int *y, int *flagVida){
    static int t, r;
    int quocienteX, quocienteY;
    int xProjetil, yProjetil;

    ALLEGRO_BITMAP *iniAquatico[8];
    ALLEGRO_BITMAP *projetil;

    iniAquatico[0] = al_load_bitmap("../res/images/aquatico/esquerda.png");
    iniAquatico[1] = al_load_bitmap("../res/images/aquatico/esquerda2.png");
    iniAquatico[2] = al_load_bitmap("../res/images/aquatico/direita.png");
    iniAquatico[3] = al_load_bitmap("../res/images/aquatico/direita2.png");
    iniAquatico[4] = al_load_bitmap("../res/images/aquatico/baixo.png");
    iniAquatico[5] = al_load_bitmap("../res/images/aquatico/baixo2.png");
    iniAquatico[6] = al_load_bitmap("../res/images/aquatico/cima.png");
    iniAquatico[7] = al_load_bitmap("../res/images/aquatico/cima2.png");

    projetil = al_load_bitmap("../res/images/aquatico/projetil.png");

    xProjetil = *xAquatico;
    yProjetil = *yAquatico;

    if(quocienteX > quocienteY){
        if(*y < *yAquatico){
            if(t <= 6){
                al_draw_scaled_bitmap(iniAquatico[6], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
            }else if(t <= 12){
                al_draw_scaled_bitmap(iniAquatico[7], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
            }
            
            if(r = TEMPO_PROJETIL){
                yProjetil += 8;
            }
        }
        if(*y > *yAquatico){
            if(t <= 6){
                al_draw_scaled_bitmap(iniAquatico[4], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
            }else if(t <= 12){
                al_draw_scaled_bitmap(iniAquatico[5], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
            }

            if(r = TEMPO_PROJETIL){
                yProjetil -= 8;
            }
        }
    }else{
        if(*x < *xAquatico){
            if(t <= 6){
                al_draw_scaled_bitmap(iniAquatico[0], 0, 0, 24, 33, *xAquatico, *yAquatico, 48, 66, 0);
            }else if(t <= 12){
                al_draw_scaled_bitmap(iniAquatico[1], 0, 0, 24, 33, *xAquatico, *yAquatico, 48, 66, 0);
            }

            if(r = TEMPO_PROJETIL){
                xProjetil -= 8;
            }
        }
        if(*x > *xAquatico){
            if(t <= 6){
                al_draw_scaled_bitmap(iniAquatico[2], 0, 0, 24, 33, *xAquatico, *yAquatico, 48, 66, 0);
            }else if(t <= 12){
                al_draw_scaled_bitmap(iniAquatico[3], 0, 0, 24, 33, *xAquatico, *yAquatico, 48, 66, 0);
            }

            if(r = TEMPO_PROJETIL){
                xProjetil += 8;
            }
        }
    }

    if(t > 12){
        t = 0;
    }
    if(r > TEMPO_PROJETIL){
        r = 0;
    }

    for(int i = 0; i < 8; i++){
        al_destroy_bitmap(iniAquatico[i]);
    }
}


// função para movimentação do inimigo terrestre
void movimentacaoInimigos(int tile, int *xInimigo, int *yInimigo, int *x, int *y, int *flagVida){
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
        movimentacaoInimigos(tile, xInimigo, yInimigo, x, y, flagVida);
    }else if(tile == C1){
        movimentacaoInimigos(tile, xInimigo, yInimigo, x, y, flagVida);
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

void colisao(tile *tileAtual, int *x, int *y, int id){
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_COLOR corJogador, preto, vermelho, amarelo, azul, rosa, cores[5];

    preto = al_map_rgb(0, 0, 0); //colisão
    vermelho = al_map_rgb(255, 0, 0);//ninho
    amarelo = al_map_rgb(255, 234, 0);//árvore
    azul = al_map_rgb(0, 0, 255);//projétil e da cobra. Dano.
    rosa = al_map_rgb(255, 0, 255);//personagem principal

    //printf("%d", tileAtual->ID);

    switch(id){
      case 1:
        corJogador = al_get_pixel(tileAtual->colisao, *x + 33, *y);
        break;
      case 2:
        corJogador = al_get_pixel(tileAtual->colisao, *x + 33, *y + 66);
        break;
      case 3:
        corJogador = al_get_pixel(tileAtual->colisao, *x + 66, *y + 33);
        break;
      case 4:
        corJogador = al_get_pixel(tileAtual->colisao, *x, *y + 33);
        break;
    }

    cores[0] = preto;
    cores[1] = vermelho;
    cores[2] = amarelo;
    cores[3] = azul;
    cores[4] = rosa;

    for(int i = 0; i < 5; i++){
      if(memcmp(&cores[i], &corJogador, sizeof(ALLEGRO_COLOR)) == 0){
        switch(i){
          case 0:
            if(id == 1){
              *y += 5;
            }
            if(id == 2){
              *y -= 5;
            }
            if(id == 3){
              *x -= 5;
            }
            if(id == 4){
              *x += 5;
            }
            printf("O jogador não anda.\n");
            break;
          case 1:
            //Se interagir, animação do Ninho.
            //Fade, muda de era.
            printf("O jogador mudou de era.\n");
            break;
          case 2:
            //Se interagir, árvore vai ser derrubada.
            printf("O jogador derrubou a árvore.\n");
            break;
          case 3:
            printf("O jogador recebe dano.\n");
            break;
        }
      }
    }
  }
