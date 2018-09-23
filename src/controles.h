void movimentacao(ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento, int *x, int *y){

    al_wait_for_event_timed(fila, &evento, 0.05);

    if(evento.type == ALLEGRO_EVENT_KEY_DOWN){

        if(evento.keyboard.keycode == ALLEGRO_KEY_W){
            *y -= 3; 
        }else if(evento.keyboard.keycode == ALLEGRO_KEY_S){
            *y += 3;
        }else if(evento.keyboard.keycode == ALLEGRO_KEY_D){
            *x += 3;
        }else if(evento.keyboard.keycode == ALLEGRO_KEY_A){
            *x -= 3;
        }
    
    }
}