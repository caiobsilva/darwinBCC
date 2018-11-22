#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include "header.h"

//Intro do menu
int menuIntro(int n){
    ALLEGRO_BITMAP *intro[4];

    //Declarando os quatro frames da intro do menu
    intro[0] = al_load_bitmap("../res/images/introMenu1.png");
    intro[1] = al_load_bitmap("../res/images/introMenu2.png");
    intro[2] = al_load_bitmap("../res/images/introMenu3.png");
    intro[3] = al_load_bitmap("../res/images/introMenu4.png");

    //Decidindo qual dos frames vai ser desenhado
    if(n < 6){
        al_draw_scaled_bitmap(intro[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n < 12){
        al_draw_scaled_bitmap(intro[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n < 18){
        al_draw_scaled_bitmap(intro[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }
    else if(n <= 24){
        al_draw_scaled_bitmap(intro[3], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    }

    for (int i = 0; i < 4; i++){
        al_destroy_bitmap(intro[i]);
    }

    return (n += 1);
}

// Essa é a função do primeiro menu própriamente dita.
enum statesGame menu(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    int sair = 0, n = 1;

    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    
    //Loop do menu
    while (!sair){
        al_wait_for_event_timed(fila, &evento, 0.05);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 0;
        }
        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            sair = 1;
        }

        al_clear_to_color(branco);
        // A variavel n é igual ao retorno da função de densenho
        // Sempre aumentando de 1 em 1
        n = menuIntro(n);
        al_flip_display();

        // Como cada frame toma 6 cliclos e tem 4, quando o n for 25
        // ele volta para o primeiro frame.
        if(n > 24){
            n = 1;
        }
    }

    return Select;
}

// Depois que uma tecla for apertada o jogador seguirá para o menu de "Novo jogo", essa é a função que
// desenha o menu e encaminha para a opção escolhida.
enum statesGame menuSelect(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    enum statesGame estado;
    int sair = 0;

    al_reserve_samples(5);
    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    ALLEGRO_SAMPLE *efeitoSelecionar = al_load_sample("../res/audio/pressEffect.flac");
    ALLEGRO_SAMPLE *efeitoTrocar = al_load_sample("../res/audio/alternEffect.flac");
    ALLEGRO_SAMPLE *musicaMenu = al_load_sample("../res/audio/menuTheme.flac");

    ALLEGRO_BITMAP *arraySelecionar[3];
    
    arraySelecionar[0] = al_load_bitmap("../res/images/selectMenu1.png");
    arraySelecionar[1] = al_load_bitmap("../res/images/selectMenuNewGame.png");
    arraySelecionar[2] = al_load_bitmap("../res/images/selectMenuExit.png");

    al_clear_to_color(branco);
    al_draw_scaled_bitmap(arraySelecionar[0], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
    al_flip_display();

    estado = Menu;

    while(!sair){
        al_wait_for_event_timed(fila, &evento, 0.05);
        al_play_sample(musicaMenu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

        al_play_sample(musicaMenu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

        if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return Exit;
        }

        if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
            //Se o jogador apertar a "W" ou a seta para cima a opção de novo jogo será desenhada
            if(evento.keyboard.keycode == ALLEGRO_KEY_UP || evento.keyboard.keycode == ALLEGRO_KEY_W){
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(arraySelecionar[1], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                al_play_sample(efeitoTrocar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                estado = AmbienteUm;
            }else if(evento.keyboard.keycode == ALLEGRO_KEY_DOWN || evento.keyboard.keycode == ALLEGRO_KEY_S){
            //Se o jogador apertar a "S" ou a seta para baixo a opção de sair do jogo será desenhada
                al_clear_to_color(branco);
                al_draw_scaled_bitmap(arraySelecionar[2], 0, 0, 896, 504, 0, 0, 1280, 720, 0);
                al_play_sample(efeitoTrocar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                estado = Exit;
            }else if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER || evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
            //Se o jogador apertar a "espaço" ou a "ENTER" a opção selecionada vai ser computada
                if(estado != Menu){
                    al_play_sample(efeitoSelecionar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    al_rest(0.8);
                    sair = 1;
                }
            }
            al_flip_display();
        }
    }

    al_destroy_sample(efeitoSelecionar);
    al_destroy_sample(musicaMenu);

    for (int i = 0; i < 3; i++){
        al_destroy_bitmap(arraySelecionar[i]);
    }

    return estado;
    
}
