#!/bin/bash
gcc controles.c menu.c pausa.c falas.c mapaAmbiente1.c localizacao.c ambienteUm.c main.c -o game -lallegro -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf
exit 0
