#include <stdio.h>
#include <allegro5/allegro.h>

#define JANELA_X 1280
#define JANELA_Y 720

int main(){
    
    al_init();

    ALLEGRO_DISPLAY *janela = al_create_display(JANELA_X,JANELA_Y);
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);

    al_clear_to_color(branco);
    al_flip_display();

    al_rest(5.0);
    al_destroy_display(janela);

    return 0;
}
