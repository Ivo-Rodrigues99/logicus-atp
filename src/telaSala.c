#include "raylib.h"

#include "recursos.h"
#include "mapa.h"
#include "telas.h"

EstadoTela telaSala(Imagens *imagens, int LARGURA, int ALTURA, int *idSalaAtual) {
    	switch (*idSalaAtual) {
        case ID_SALA_BIBLIOTECAS:
            DrawRectangle(0, 0, LARGURA, ALTURA, DARKGREEN); // Fundo Verde
            DrawText("BIBLIOTECAS", 20, 50, 40, WHITE);
            break;
            
        case ID_SALA_MAIN:
            DrawRectangle(0, 0, LARGURA, ALTURA, YELLOW); // Fundo Amarelo
            DrawText("MAIN( )", 20, 50, 40, WHITE);
            break;
            
        case ID_SALA_VARIAVEIS:
            DrawRectangle(0, 0, LARGURA, ALTURA, ORANGE); // Fundo Laranja
            DrawText("SALA DAS VARIAVEIS", 20, 50, 40, WHITE);
            break;
            
        case ID_SALA_PRINT:
            DrawRectangle(0, 0, LARGURA, ALTURA, MAROON); // Fundo Vermelho
            DrawText("PRINTF", 20, 50, 40, WHITE);
            break;
            
        case ID_SALA_SCAN:
            DrawRectangle(0, 0, LARGURA, ALTURA, MAROON); // Fundo Vermelho
            DrawText("SCANF", 20, 50, 40, WHITE);
            break;

        default:
            // Caso seja ID_SALA_NULA ou erro, desenha a imagem padrão antiga
            DrawTexture((*imagens).interface[IMAGEM_FUNDO], 0, 0, WHITE);
            DrawText("SALA PADRÃO (Sem ID)", 20, 50, 20, WHITE);
            break;
    }

    if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_TAB)) {
        return TELA_MAPA;
    }
    return TELA_SALA;
}
