#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define JANELA_X 1280
#define JANELA_Y 720

int main(){
    
    al_init();
    al_init_image_addon();

    ALLEGRO_BITMAP *imagem = al_load_bitmap("docs/images/lizardPixelArt.png");
    ALLEGRO_DISPLAY *janela = al_create_display(JANELA_X,JANELA_Y);
    ALLEGRO_COLOR branco = al_map_rgb(255,255,255);


    al_clear_to_color(branco);
    al_draw_scaled_bitmap(imagem,0,0,23,38,500,250,115,190,0);
    al_flip_display();

    al_rest(5.0);
    al_destroy_display(janela);

    return 0;
}
