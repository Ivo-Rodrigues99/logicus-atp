// importacao de arquivos header de bibliotecas padrao

#include <stdio.h>

// importacao de arquivos header de bibliotecas third party

#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"

// importacao de arquivos header de prototipacao

#include "save.h"
#include "dialogo.h"

// declaracao de constantes globais

typedef enum {
    TELA_INICIAL = 0,
    TELA_MENU,
    TELA_JOGO
} EstadoTela;

// declaracao de variaveis globais

// prototipação de funções

void mudarTela (EstadoTela *telaAtual);
EstadoTela telaInicial(EstadoTela **tela);
EstadoTela telaMenu(EstadoTela **tela);
EstadoTela telaJogo(EstadoTela **tela);

int main(void) {

    //Variavel de controle
    EstadoTela tela = TELA_INICIAL;

    InitWindow(800, 460, "Logicus;");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
            
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            // através desta função acontecem todas as transições
            mudarTela(&tela);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}

//função que muda de tela ativamente
void mudarTela (EstadoTela *telaAtual){
    switch(*telaAtual){
        case TELA_INICIAL:
            *telaAtual = telaInicial(&telaAtual);
            break;
        
        case TELA_MENU:
            *telaAtual = telaMenu(&telaAtual);
            break;
        
        case TELA_JOGO:
            *telaAtual = telaJogo(&telaAtual);
    }
}

EstadoTela telaInicial(EstadoTela **tela){
    DrawText("TELA INICIAL - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_MENU;
    } else {
        return **tela;
    }
}

EstadoTela telaMenu(EstadoTela **tela){
    DrawText("TELA DO MENU - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_JOGO;
    } else {
        return **tela;
    }
}

EstadoTela telaJogo(EstadoTela **tela){
    DrawText("TELA DO JOGO - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_MENU;
    } else {
        return **tela;
    }
}