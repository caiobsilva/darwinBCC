#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "menu.h"

#define JANELA_X 1280
#define JANELA_Y 720

int main(){

    int sair = 0;

    al_init();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *janela = al_create_display(JANELA_X, JANELA_Y);
    ALLEGRO_EVENT_QUEUE *fila;
    fila = al_create_event_queue();
    al_register_event_source(fila, al_get_keyboard_event_source());
    ALLEGRO_EVENT evento;

    menu(fila, evento);

    al_rest(2.0);
    
    al_destroy_display(janela);
    al_uninstall_keyboard();

    return 0;
}
