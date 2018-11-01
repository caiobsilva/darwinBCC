#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "header.h"


int falas(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int s){

    int n = 0, i = 0, d;

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_BITMAP *sprite = al_load_bitmap("../res/images/sprite01/baixo01.png");
    ALLEGRO_BITMAP *falasDarwin = al_load_bitmap("../res/images/barraTexto.png");
    ALLEGRO_FONT *yoster = al_load_ttf_font("../res/font/prstart.ttf",17,0);
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
    
    char *falasInicio[12];
    falasInicio[0] = "Bem vindo! Meu nome é Charles Darwin.";
    falasInicio[1] = "Há anos venho estudando as interações dos animais entre eles mesmos e os ambientes.";
    falasInicio[2] = "Durante uma viagem que fiz pelo mundo eu encontrei diversas espécies diferentes que compartilhavam características.";
    falasInicio[3] = "Por meio da observação eu consegui entender";
    falasInicio[4] = "Os animais tinham características que melhor se enquadravam no ambiente em que se encontravam.";
    falasInicio[5] = "Infelizmente isso não era o suficiente para produzir uma teoria, faltava uma peça.";
    falasInicio[6] = "Quando eu cheguei em casa tive tempo pra pensar e a resposta parcial surgiu.";
    falasInicio[7] = "Os cachorros eram selecionados pelos humanos baseando-se nas características que melhor se ajustam a tarefa a ser realizada, por consequência diversas raças com características diferentes apareceram.";
    falasInicio[8] = "Para ser publicado, faltava somente encaixar a ideia no ambiente selvagem";
    falasInicio[9] = "Depois de algum tempo, um livro me deu a resposta: a competição imposta por um ambiente e recursos limitados selecionava os que melhor se adaptavam!";
    falasInicio[10] = "Agora é a sua vez de experimentar as mudanças e melhor se adaptar ao ambiente!";
    falasInicio[11] = "Boa sorte na sua aventura, nova espécie!";

    char *falasInimigos[4];
    falasInimigos[0] = "Cuidado!";
    falasInimigos[1] = "Essa espécie me parece estranha";
    falasInimigos[2] = "Olha a cor dela, tenho certeza de que isso é um caso de coloração de advertência.";
    falasInimigos[3] = "A cor característica do animal serve como um alerta, eu recomendaria ficar longe.";
    ALLEGRO_BITMAP *parte[2];
    parte[0] = al_load_bitmap("../res/images/tiles/Tile-B4.png");
    parte[1] = al_load_bitmap("../res/images/tiles/Tile-A4.png");
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 
        
    switch(s){
        case 0:
            d = 12;
            break;
        case 1:
            d = 4;
            break;
    }

    while(n < d){
        al_clear_to_color(branco);
        al_draw_bitmap(parte[s], 0,0,0);
        al_draw_scaled_bitmap(falasDarwin,0,0,1440,290,10,460,1152,232,0);
        switch(s){
            case 0:
                al_draw_scaled_bitmap(sprite, 0, 0, 16, 22, 610, 294, 48, 66, 0);
                al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInicio[n]);
                break;
            case 1:
                al_draw_scaled_bitmap(inimigo,0,0,238,294,610,380,48,66,0);
                al_draw_multiline_text(yoster,preto,70,500,650,25,0,falasInimigos[n]);
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

    al_destroy_bitmap(sprite);
    al_destroy_bitmap(falasDarwin);
    al_destroy_font(yoster);

    return (0);
}
