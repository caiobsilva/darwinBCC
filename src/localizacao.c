#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <math.h>
#include "header.h"

#define TEMPO_PROJETIL 96

void fade(){
    ALLEGRO_BITMAP *fade[10];
    int n = 0;
    fade[0] = al_load_bitmap("../res/efeitos/fade/fade1.png");
    fade[1] = al_load_bitmap("../res/efeitos/fade/fade2.png");
    fade[2] = al_load_bitmap("../res/efeitos/fade/fade3.png");
    fade[3] = al_load_bitmap("../res/efeitos/fade/fade4.png");
    fade[4] = al_load_bitmap("../res/efeitos/fade/fade5.png");
    fade[5] = al_load_bitmap("../res/efeitos/fade/fade6.png");
    fade[6] = al_load_bitmap("../res/efeitos/fade/fade7.png");
    fade[7] = al_load_bitmap("../res/efeitos/fade/fade8.png");
    fade[8] = al_load_bitmap("../res/efeitos/fade/fade9.png");
    fade[9] = al_load_bitmap("../res/efeitos/fade/fade10.png");

    while(n != 20){
        al_clear_to_color(al_map_rgb(255,255,255));
        if(n < 2){
            al_draw_scaled_bitmap(fade[0], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 4){
            al_draw_scaled_bitmap(fade[1], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 6){
            al_draw_scaled_bitmap(fade[2], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 8){
            al_draw_scaled_bitmap(fade[3], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 10){
            al_draw_scaled_bitmap(fade[4], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 12){
            al_draw_scaled_bitmap(fade[5], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 14){
            al_draw_scaled_bitmap(fade[6], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 16){
            al_draw_scaled_bitmap(fade[7], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 18){
            al_draw_scaled_bitmap(fade[8], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }else if(n < 20){
            al_draw_scaled_bitmap(fade[9], 0, 0, 1280, 720, 0, 0, 1280, 720, 0);
        }
        al_flip_display();

        n++;
    }
}

void inimigoAquatico(int tile, int *xAquatico, int *yAquatico, int *x, int *y, int *flagVida){
    static int t, r;
    static int xProjetil, yProjetil = 1000;
    double mod, A, B;

    if(tile == C3 && (yProjetil > 720 || yProjetil < 0)){
        yProjetil = 565;
    }


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

    xProjetil = *xAquatico+33;

    if(*yAquatico > *y){
        
        if(t <= 24){
            al_draw_scaled_bitmap(iniAquatico[6], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
        }else if(t <= 48){
            al_draw_scaled_bitmap(iniAquatico[7], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
        }   

        if(r = TEMPO_PROJETIL){
            yProjetil -= 8;
        }            

    }else{
        
        if(t <= 24){
            al_draw_scaled_bitmap(iniAquatico[4], 0, 0, 33, 24, *xAquatico, *yAquatico, 66, 48, 0);
        }else if(t <= 48){
            al_draw_scaled_bitmap(iniAquatico[5], 0, 0, 33, 24, *xAquatico, *yAquatico + 20, 66, 48, 0);
        }

        if(r = TEMPO_PROJETIL){
            yProjetil += 8;
        }

    }

    al_draw_bitmap(projetil,xProjetil,yProjetil,0);

    A = (*x - xProjetil) * (*x - xProjetil);
    B = (*y - yProjetil) * (*y - yProjetil);
    mod = A + B;
    if(mod < 4000){
        *flagVida -= 1;
        if(*x < *xAquatico){
            *x -= 100;
        }else{
            *x += 100;
        }
    }
    printf("%lf\n", mod);

    t += 1;
    
    if(t > 48){
        t = 0;
    }
    if(r > TEMPO_PROJETIL){
        r = 0;
    }

    for(int i = 0; i < 8; i++){
        al_destroy_bitmap(iniAquatico[i]);
    }
}

int ninho(tile *tileAtual, int *x, int *y,int *flagPontos,int *flagEvolucao){
    if(tileAtual->ID == 17 && *flagPontos == 3){
        ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);
        ALLEGRO_COLOR corJogador = al_get_pixel(tileAtual->colisao, *x + 33, *y + 33);
        if(memcmp(&vermelho, &corJogador, sizeof(ALLEGRO_COLOR)) == 0){
            ALLEGRO_BITMAP *tranEra = al_load_bitmap("../res/images/transEra.png");
            fade();
            falaNinho();
            fade();
            al_draw_bitmap(tranEra,0,0,0);
            al_flip_display();
            al_rest(5.0);
            fade();
            falaNinho2();
            *flagPontos = 0;
            *flagEvolucao = 1;
            tileAtual->esquerda->direita->imagem = al_load_bitmap("../res/images/tiles/Tile-D5A.png");
            tileAtual->esquerda->direita->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D5A.png");
            tileAtual->imagem = al_load_bitmap("../res/images/tiles/Tile-D5A.png");
            tileAtual->colisao = al_load_bitmap("../res/tiles/colisao/Tile-D5A.png");
            al_destroy_bitmap(tranEra);
        }

    }else if(tileAtual->ID == 30 && *flagPontos == 2){
        ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);
        ALLEGRO_COLOR corJogador = al_get_pixel(tileAtual->colisao, *x + 33, *y + 33);
        if(memcmp(&vermelho, &corJogador, sizeof(ALLEGRO_COLOR)) == 0){
            fade();
            return(1);
        }
    }
    return(0);
}


// função para movimentação do inimigo terrestre
void movimentacaoInimigos(int tile, int *xInimigo, int *yInimigo, int *x, int *y, int *flagVida){
    static int t, i;
    double mod, A, B;
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

    A = (*x - *xInimigo) * (*x - *xInimigo);
    B = (*y - *yInimigo) * (*y - *yInimigo);
    mod = A + B;
    if(mod < 20){
        *flagVida -= 1;
        if(B > A){
            *y += 100;
        }else{
            *x += 100;
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

void colisao(tile *tileAtual, int *x, int *y, int id, int *flagVida){
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
          case 2:            
            //Se interagir, árvore vai ser derrubada.
            fade();
            tileAtual->cima->imagem = al_load_bitmap("../res/images/tiles/Tile-E9A.png");
            tileAtual->cima->colisao = al_load_bitmap("../res/tiles/colisao/Tile-E9A.png");
            tileAtual->arvores = al_load_bitmap("../res/images/tiles/Tile-F9-ArvoreA.png");
            tileAtual->esquerda->direita->arvores = al_load_bitmap("../res/images/tiles/Tile-F9-ArvoreA.png");

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
            printf("O jogador derrubou a árvore.\n");
            break;
          case 3:
            *flagVida--;
            printf("O jogador recebe dano.\n");
            break;
        }
      }
    }
  }
}