#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
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
    parte[0] = al_load_bitmap("../res/images/ambienteUm-parteUm.png");
    parte[1] = al_load_bitmap("../res/images/ambienteUm-parteDois.png");
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

void localizacao(int *x, int *y, int i){
    // AMBIENTE 1 PARTE 1
    if( i == 0 ){
        if(*x < 0){
        *x = 0;
        }
        if(*x > 1230){
            *x = 1230;
        }
        if(*y > 650 ){
            *y = 650;
        }
    }
    // AMBIENTE 1 PARTE 2
    else if(i == 1){
        if(*x < 0){
            *x = 0;
        }
        if(*x > 1230){
            *x = 1230;
        }
        if(*y < 0 ){
            *y = 0;
        }
    }
}

void movimentacaoInimigos(int i,int *xInimigo,int *yInimigo,  int *flagInimigo){
    //AMBIENTE 1 PARTE 2
    if(i == 1){

        if(*xInimigo < 800 && *flagInimigo == 0){
            *xInimigo += 5;
        }else{
            *flagInimigo = 1;
        }

        if(*xInimigo > 300 && *flagInimigo == 1){
            *xInimigo -= 5;
        }else{
            *flagInimigo = 0;
        }

    }
}

void addPartes(int i, int *xInimigo, int *yInimigo,int *flagInimigo){
    ALLEGRO_BITMAP *inimigo = al_load_bitmap("../res/images/inimigos1.png"); 
    if(i == 0){

    }else if(i == 1){
        movimentacaoInimigos(i,xInimigo,yInimigo,flagInimigo);
        al_draw_scaled_bitmap(inimigo,0,0,238,294,*xInimigo,*yInimigo,48,66,0);
    }
    al_destroy_bitmap(inimigo);

}

enum statesGame ambienteUm(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int flagInimigos = 0, flagOpcoes = 0, flagSom = 1, flagInimigo = 0;
    int n = 0, sair = 0, i = 0, x = 610, y = 294, xInimigo = 610, yInimigo = 380, t = 0;

    if(falas(fila,evento,0)){
        return Exit;
    }


    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);
    ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
    ALLEGRO_KEYBOARD_STATE tecla;

    ALLEGRO_BITMAP *parte[2];

    parte[0] = al_load_bitmap("../res/images/ambienteUm-parteUm.png");
    parte[1] = al_load_bitmap("../res/images/ambienteUm-parteDois.png");

    while (!sair){

        while(!(al_is_event_queue_empty(fila))){

            al_wait_for_event(fila, &evento);
            
            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                printf("fechou!\n");
                for(int j = 0; j < 2; j++){
                    al_destroy_bitmap(parte[j]);
                }
                return Exit;
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    flagOpcoes = pausa(x,y,&flagSom,fila,evento);

                    if(flagOpcoes){
                        for(int j = 0; j < 2; j++){
                            al_destroy_bitmap(parte[j]);
                        }
                        return Exit;
                    }
                }
            }
        }

        if( i == 0 && y < 0 ){
            if(flagInimigos == 0){
                if(falas(fila,evento,1)){
                    for(int j = 0; j < 2; j++){
                        al_destroy_bitmap(parte[j]);
                    }

                    return Exit;                    
                }
                flagInimigos = 1;
            }
            i = 1;
            y = 650; 
        }else if( i == 1 && y > 650 ){
            i = 0;
            y = 0; 
        }
        
        al_clear_to_color(branco);
        al_draw_bitmap(parte[i], 0,0,0);
        addPartes(i, &xInimigo, &yInimigo, &flagInimigo);
        localizacao(&x,&y,i);
        movimentacao(evento, &x, &y,&t);
        al_flip_display();
        
    }
    for(int j = 0; j < 2; j++){
        al_destroy_bitmap(parte[j]);
    }

    return Exit;
}
