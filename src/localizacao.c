#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "header.h"

#define A1 0
#define A2 1
#define A3 2
#define A4 3
#define A5 4
#define B1 5
#define B2 6
#define B3 7
#define B4 8
#define C1 9
#define C2 10
#define C3 11
#define C4 12
#define D1 13
#define D2 14
#define D3 15
#define D4 16
#define D5 17

void localizacao(int *x, int *y, int *i, int *flagEvento, ALLEGRO_EVENT_QUEUE *fila, ALLEGRO_EVENT evento){
    if(*i == A1){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 0;
        }
        if(*x > 1230){
            *i = A2; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B1;
            *y = 0; 
        }

    }
    else if(*i == A2){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A1;
        }
        if(*x > 1230){
            *i = A3; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B2;
            *y = 0; 
        }

    }
    else if(*i == A3){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A2;
        }
        if(*x > 1230){
            *i = A4; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B3;
            *y = 0; 
        }

    }
    else if(*i == A4){
        if(*flagEvento == 1 ){
            falas(fila,evento,1);
            *flagEvento = 0;               
        }
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A3;
        }
        if(*x > 1230){
            *i = A5; 
            *x = 0;
        }else if( *y > 650 ){
            *i = B4;
            *y = 0; 
        }

    }else if(*i == A5){
        
        if(*y < 125 ){
            *y = 125;
        }if(*x < 0){
            *x = 1230;
            *i = A4;
        }
        if(*x > 1030){
            *x = 1030;
        }else if( *y > 650 ){
            *y = 650; 
        }

    }else if(*i == B1){
        
        if(*y < 0 ){
            *i = A1;
            *y = 650;
        }if(*x < 125){
            *x = 125;
        }
        if(*x > 1230){
            *i = B2; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C1;
            *y = 0; 
        }

    }else if(*i == B2){
        
        if(*y < 0 ){
            *i = A2;
            *y = 650;
        }if(*x < 0){
            *x = 1230;
            *i = B1;
        }
        if(*x > 1230){
            *i = B3; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C2;
            *y = 0; 
        }

    }else if(*i == B3){
        
        if(*y < 0 ){
            *i = A3;
            *y = 650;
        }if(*x < 0){
            *x = 1230;
            *i = B2;
        }
        if(*x > 1230){
            *i = B4; 
            *x = 0;
        }else if( *y > 650 ){
            *i = C3;
            *y = 0; 
        }

    }else if( *i == B4 ){
        if(*y < 0){
            *i = A4;
            *y = 650; 
        }else if(*x < 0){
            *x = 1230;
            *i = B3;
        }
        if(*x > 1230){
            *x = 1230;
        }
        if(*y > 650 ){
            *i = C4;
            *y = 0; 
        }

    }else if(*i == C1){
        
        if(*y < 0 ){
            *y = 730;
            *i = B1;
        }if(*x < 125){
            *x = 125;
        }
        if(*x > 1230){
            *i = C2; 
            *x = 0;
        }else if( *y > 550 ){
            *y = 550; 
        }

    }else if(*i == C2){
        
        if(*y < 0 ){
            *y = 730;
            *i = B2;
        }if(*x < 0){
            *x = 1230;
            *i = C1;
        }
        if(*x > 1230){ 
            *x = 0;
            *i = C3;
        }else if( *y > 550 ){
            *y = 550; 
        }

    }else if(*i == C3){
        
        if(*y < 0 ){
            *y = 730;
            *i = B3;
        }if(*x < 0){
            *x = 1230;
            *i = C2;
        }
        if(*x > 1230){
            *i = C4; 
            *x = 0;
        }else if( *y > 550 ){
            *y = 550; 
        }

    }else if( *i == C4 ){
        if(*y < 0){
            *i = B4;
            *y = 650; 
        }else if(*x < 0){
            *x = 1230;
            *i = C3;
        }
        if(*x > 1230){
            *x = 1230;
        }
        if(*y > 550 ){
            *y = 550; 
        }

    }

}
