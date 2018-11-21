#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "header.h"


void animacaoC1(int x, int y){
    
    int xInimigo = 610, n = 0;

    ALLEGRO_BITMAP *sprite2 = al_load_bitmap("../res/images/sprite01/esquerda01.png"); 
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/terrestre/baixo.png"); 
    ALLEGRO_BITMAP *sprite = al_load_bitmap("../res/images/sprite01/baixo01.png");
    ALLEGRO_BITMAP *tile  = al_load_bitmap("../res/images/tiles/Tile-C1.png");
    
    while( n < 6 ){

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(tile,0,0,0);
        al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
        al_draw_scaled_bitmap(sprite2, 0, 0, 22, 22, 610, 294, 66, 66, 0);
        al_draw_scaled_bitmap(inimigo,0,0,238,294,xInimigo,294,48,66,0);
        al_flip_display();

        if(xInimigo == 610)
            xInimigo = 540;
        else
            xInimigo = 610;

        al_rest(.5);

        n++;

    }
}

void animacaoG10(int x,int y, ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE *fila){
    
    int n = 0, xCov = 750, yCov = 315, numeroVezes = 0, v = 0;  
    ALLEGRO_BITMAP *parte = al_load_bitmap("../res/images/tiles/Tile-G10.png");
    ALLEGRO_BITMAP *sprite = al_load_bitmap("../res/images/sprite01/direita01.png");
    ALLEGRO_BITMAP *spriteCov[3];
    spriteCov[0] = al_load_bitmap("../res/images/cov/direita01.png");
    spriteCov[1] = al_load_bitmap("../res/images/cov/direita02.png");
    spriteCov[2] = al_load_bitmap("../res/images/cov/direita03.png");
    ALLEGRO_BITMAP *falasDarwin = al_load_bitmap("../res/images/barraTexto.png");
    ALLEGRO_FONT *yoster = al_load_ttf_font("../res/font/prstart.ttf",17,0);
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);

    char *falasIrradiacao[5];
    falasIrradiacao[0] = "Olha só, parece que há tempos, de alguma forma, um ancestral seu conseguiu chegar nessa ilha.";
    falasIrradiacao[1] = "Cada ilha tem um sistema próprio e a sua espécie se desevolveu de forma diferente nessa! Um caso claro de irradiação adaptativa!";
    falasIrradiacao[2] = "...";
    falasIrradiacao[3] = "VOCÊ VIU AQUILO?";
    falasIrradiacao[4] = "Aquela espécie acabou de se camuflar! algumas espécies tem a habilidade de \"desaparecer\" quando se sentem ameaçadas, fantástico!";

    while(n < 5){
        if(n < 2){
            al_clear_to_color(branco);
            al_draw_bitmap(parte,0,0,0);
            al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
            al_draw_scaled_bitmap(spriteCov[0], 0, 0, 22, 22, xCov, yCov, 66, 66, 0);
            al_draw_scaled_bitmap(falasDarwin,0,0,1440,290,10,460,1152,232,0);
            al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasIrradiacao[n]);
            al_flip_display();
        }
        else if(n == 2){
            while(numeroVezes < 20){
                al_clear_to_color(branco);
                al_draw_bitmap(parte,0,0,0);
                al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
                al_draw_scaled_bitmap(spriteCov[v], 0, 0, 22, 22, xCov, yCov, 66, 66, 0);
                al_draw_scaled_bitmap(falasDarwin,0,0,1440,290,10,460,1152,232,0);
                al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasIrradiacao[n]);
                al_flip_display();
                xCov += 5;
                v++;
                if(v > 2){
                    v = 0;
                }
                al_rest(0.01);
                numeroVezes++;
            }
            n++;
        }else{
            al_clear_to_color(branco);
            al_draw_bitmap(parte,0,0,0);
            al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
            al_draw_scaled_bitmap(falasDarwin,0,0,1440,290,10,460,1152,232,0);
            al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasIrradiacao[n]);
            al_flip_display();
        }
        al_wait_for_event_timed(fila, &evento, 0.05);
        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            if(evento.keyboard.keycode == ALLEGRO_KEY_E || evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
                n++;
            }
        }
    }
    
}

int falas(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int seletor, int x, int y, int *pontuacao){

    int n = 0, numeroVezes;
    static int flagInimigos = 1, flagInicio = 1, flagInteracao = 1, flagNinho = 1, flagIrra = 1, flagAqua = 1;
    
    al_init_font_addon();
    al_init_ttf_addon();

    if(seletor == 8 && flagInicio == 1){
        numeroVezes = 12;
        seletor = 0;
        flagInicio = 0;
    }else if(seletor == 3 && flagInimigos == 1){
        *pontuacao += 1;
        numeroVezes = 4;
        seletor = 1;
        flagInimigos = 0;
    }else if(seletor == 9 && flagInteracao == 1){
        *pontuacao += 1;
        animacaoC1(x,y);
        numeroVezes = 4;
        seletor = 2;
        flagInteracao = 0;
    }else if(seletor == 17 && flagNinho == 1){
        *pontuacao += 1;
        seletor = 3;
        numeroVezes = 3;
        flagNinho = 0;
    }else if(seletor == 36 && flagIrra == 1){
        //*pontuacao += 1;
        seletor = 5;
        flagIrra = 0;
    }else if(seletor == 21 && flagAqua == 1){
        //*pontuacao += 1;
        seletor = 4;
        numeroVezes = 3;
        flagAqua = 0;
    }else{
        return 0;
    }

    ALLEGRO_BITMAP *sprite = al_load_bitmap("../res/images/sprite01/baixo01.png");
    ALLEGRO_BITMAP *falasDarwin = al_load_bitmap("../res/images/barraTexto.png");
    ALLEGRO_FONT *yoster = al_load_ttf_font("../res/font/prstart.ttf",17,0);
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
    
    char *falasInicio[12];
    falasInicio[0] = "Bem vindo! Meu nome é Charles Darwin.";
    falasInicio[1] = "Há anos venho estudando as interações dos animais entre eles mesmos e os ambientes.";
    falasInicio[2] = "Durante uma viagem que fiz pelo mundo, encontrei diversas espécies diferentes que compartilhavam características.";
    falasInicio[3] = "Por meio da observação eu consegui entender:";
    falasInicio[4] = "Os animais tinham características que melhor se enquadravam no ambiente em que se encontravam.";
    falasInicio[5] = "Infelizmente isso não era o suficiente para produzir uma teoria, faltava uma peça.";
    falasInicio[6] = "Quando eu cheguei em casa, tive tempo pra pensar e a resposta parcial surgiu:";
    falasInicio[7] = "Os cachorros eram selecionados pelos humanos baseando-se nas características que melhor se ajustam a tarefa a ser realizada, por consequência, diversas raças com características diferentes apareceram.";
    falasInicio[8] = "Para ser publicado, faltava somente encaixar a ideia no ambiente selvagem";
    falasInicio[9] = "Depois de algum tempo, um livro me deu a resposta: a competição imposta por um ambiente e recursos limitados selecionava os que melhor se adaptavam!";
    falasInicio[10] = "Agora é a sua vez de experimentar as mudanças e melhor se adaptar ao ambiente. Seu habitat atual já não é mais seguro com a chegada de novas espécies. É hora de migrar!";
    falasInicio[11] = "Boa sorte na sua aventura, nova espécie!";

    char *falasInimigos[4];
    falasInimigos[0] = "Cuidado!";
    falasInimigos[1] = "Essa espécie me parece estranha";
    falasInimigos[2] = "Olha a cor dela, tenho certeza de que isso é um caso de coloração de advertência.";
    falasInimigos[3] = "A cor característica do animal serve como um alerta, eu recomendaria ficar longe.";
    
    char *falasInteracoes[4];
    falasInteracoes[0] = "!!!!!";
    falasInteracoes[1] = "...";
    falasInteracoes[2] = "Pobre criatura. Nossas duvidas foram confirmadas, aquela espécie está mesmo interagindo com a sua";
    falasInteracoes[3] = "O desenvolvimento pode ser atrasado ou adiantado com a intervenção de outro ser. Chamamos isso de 'Interações Ambientais'";

    char *falasNinho[3];
    falasNinho[0] = "Um ninho! Era disso que precisávamos, e este vulcão parece dar a proteção ideal contra ataques de outras espécies."; 
    falasNinho[1] = "É importante para o desenvolvimento de uma espécie que ela tenha um lugar seguro para se reproduzir";
    falasNinho[2] = "É durante a troca de geração que as novas característica podem ser  desenvolvidas, com sorte ganharemos uma que se encaixa bem no nosso ambiente";
    
    char  *falasIntroducao2[4];
    falasIntroducao2[0] = "Uma nova geração, bem-vinda!";
    falasIntroducao2[1] = "Parece que nos últimos anos algumas coisas aconteceram";
    falasIntroducao2[2] = "Aparentemente a erupção do vulcão gerou uma ponte firme para uma das ilhas vizinhas!";
    falasIntroducao2[3] = "Não há como saber o que esperar, um novo ambiente com formas de vida complexa e diferentes pressões ambientais! Vamos, rápido!";

    char *falasInimigoAqua[3];
    falasInimigoAqua[0] = "Espere um pouco...";
    falasInimigoAqua[1] = "Aparentemente essa espécie usou o tempo vago para se adaptar a água salgada";
    falasInimigoAqua[2] = "Fantastático!";

    ALLEGRO_BITMAP *parte[5];
    parte[0] = al_load_bitmap("../res/images/tiles/Tile-B4.png");
    parte[1] = al_load_bitmap("../res/images/tiles/Tile-A4.png");
    parte[2] = al_load_bitmap("../res/images/tiles/Tile-C1.png");  
    parte[3] = al_load_bitmap("../res/images/tiles/Tile-D5.png");
    parte[4] = al_load_bitmap("../res/images/tiles/Tile-D7.png");

    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 

    if(seletor == 5){
        animacaoG10(x,y,evento,fila);
    }else{

        while(n < numeroVezes){
            al_clear_to_color(branco);
            al_draw_bitmap(parte[seletor], 0,0,0);
            al_draw_scaled_bitmap(falasDarwin,0,0,1440,290,10,460,1152,232,0);
            switch(seletor){
                case 0:
                    al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, 610, 294, 66, 66, 0);
                    al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInicio[n]);
                    break;
                case 1:
                    al_draw_scaled_bitmap(inimigo,0,0,238,294,610,380,48,66,0);
                    al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInimigos[n]);
                    break;
                case 2:
                    al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
                    al_draw_scaled_bitmap(inimigo,0,0,238,294,640,294,48,66,0);
                    al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInteracoes[n]);
                    break;
                case 3:
                    al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
                    al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasNinho[n]);
                case 4:  
                    al_draw_scaled_bitmap(sprite, 0, 0, 22, 22, x, y, 66, 66, 0);
                    al_draw_scaled_bitmap(inimigo,0,0,238,294,640,10,48,66,0);
                    al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInimigoAqua[n]);
                    break;
            }
            al_flip_display();

            al_wait_for_event_timed(fila, &evento, 0.05);
            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                return (1);
            }else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_E || evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
                    n++;
                }
            }
            
        }
    }

    al_destroy_bitmap(sprite);
    al_destroy_bitmap(falasDarwin);
    al_destroy_font(yoster);

    return (0);
}
