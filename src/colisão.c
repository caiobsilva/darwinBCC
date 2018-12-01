#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>

int main (void){
  ALLEGRO_DISPLAY *janela = NULL;
  ALLEGRO_BITMAP *imagem = NULL;

  ALLEGRO_COLOR cor, preto;

  al_init();
  al_init_image_addon();

  janela = al_create_display(640, 480);
  imagem = al_load_bitmap("image.jpg");

  al_draw_bitmap(imagem, 0, 0, 0);

  al_flip_display();

  preto = al_map_rgb(0, 0, 0);
  cor = al_get_pixel(imagem, 630, 460);

  if(memcmp(&preto, &cor, sizeof(ALLEGRO_COLOR)) == 0){
    printf("A\n");
  }

  al_rest(1.0);

  al_destroy_display(janela);

  return 0;

  /*
  AS PARTES COMENTADAS FORAM TESTES, ELAS NÃO ESTÃO FUNCIONANDO.
  Achei mais alguns exemplos (marcados com *), alguns destes já foram testados, coloquei aqui apenas pra vocẽ verificar.

  https://stackoverflow.com/questions/16961072/allegro-defining-pixel-color*
  https://stackoverflow.com/questions/16958922/checking-pixel-color-allegro-5-c
  https://stackoverflow.com/questions/16958922/checking-pixel-color-allegro-5-c/16959311#16959311
  https://www.allegro.cc/forums/thread/607895
  https://www.allegro.cc/forums/thread/616050*
  */

}
