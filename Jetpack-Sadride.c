#include <stdio.h>
#include "raylib.h"

#define ALTURA 700
#define COMPRIMENTO 1200

typedef struct  {
    int x, y;
    int velocidade;
    int largura, altura;
}Personagem_t;

void Movimento (int *y, int *velocidade) {
    int aceleracao = 1;
    if (IsKeyDown(KEY_SPACE)) {
        *velocidade = -10;
    }else {
        *velocidade += aceleracao;
    }
    *y += *velocidade;
}

int main (  ) {

    InitWindow(COMPRIMENTO, ALTURA, "Jetpack do Gremio");
    SetTargetFPS(60);

    Personagem_t jetpack;
    jetpack.x = 200;
    jetpack.y = 600;
    jetpack.velocidade = 10;
    jetpack.largura = 30;
    jetpack.altura = 50;

    while (!WindowShouldClose()) {

        BeginDrawing();
        DrawRectangle(jetpack.x, jetpack.y, jetpack.largura, jetpack.altura, BLACK);
        ClearBackground(RAYWHITE);

        Movimento (&jetpack.y, &jetpack.velocidade);

        EndDrawing();

    }


    CloseWindow();
    return 0;
};
