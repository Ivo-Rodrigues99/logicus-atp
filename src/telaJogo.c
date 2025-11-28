// se alterar, favor manter a ordem das includes de bibliotecas
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "raygui.h"
#include "recursos.h"
// telas.h obrigatoriamente há de estar após recursos.h, senão dá erro ao não saber o que é uma Texture2D
#include "telas.h"

// FOLHA DE ESTILO ---------------------------------------------------------------------------------------

    Color
        corStrPular = WHITE,
        corStrSalvamentos = WHITE;
    
// FIM DA FOLHA DE ESTILO --------------------------------------------------------------------------------


// VARIAVEIS DE CONTROLE ---------------------------------------------------------------------------------

    // maximo de caracteres por linha com tamanho de fonte 20 é de 68 caracteres
    char strCaixaDialogo[] = "texto texto texto texto texto texto texto texto texto texto texto \ntexto texto texto texto texto texto texto texto texto texto texto \ntexto texto texto texto texto texto texto texto texto texto texto \ntexto texto texto texto texto texto texto texto texto texto texto \ntexto texto texto texto texto texto texto texto texto texto texto \n";
    // usar laço for() para realizar a quebra de linhas
    
// FIM DAS VARIAVEIS DE CONTROLE -------------------------------------------------------------------------

EstadoTela telaJogo(EstadoTela *tela, Imagens *imagens, int LARGURA, int ALTURA)
{
    /* levando em consideração que:
        typedef struct Rectangle {
            float x;      // posição horizontal (eixo X)
            float y;      // posição vertical (eixo Y)
            float width;  // largura do retângulo
            float height; // altura do retângulo
        } Rectangle;
    */

    DrawTexture((*imagens).interface[IMAGEM_FUNDO], 0, 0, WHITE);
    Rectangle fundoDeTela = {0, ALTURA * 0.04, 800, 480};

    // calcula área de clique baseada no tamanho do texto
    int larguraPular = MeasureText("Pular", 12);
    int larguraSalvar = MeasureText("Salvamentos", 12);
    int espacoInterno = 12;
    int offset = 0;

    Rectangle areaPular = {((LARGURA / 2) - larguraPular - espacoInterno) - offset, 8, larguraPular, 12};
    Rectangle areaSalvamentos = {((LARGURA / 2) + espacoInterno) - offset, 8, larguraSalvar, 12};

    // desenha a palavra
    DrawText("Pular", areaPular.x, areaPular.y, 12, corStrPular);
    DrawText("Salvar", areaSalvamentos.x, areaSalvamentos.y, 12, corStrSalvamentos);

    // CAIXA DE DIALOGO
    DrawRectangleRounded((Rectangle){LARGURA * 0.01, ALTURA * 0.65, LARGURA * 0.98, ALTURA * 0.33}, 0.3f, 10, (Color){0, 0, 0, (255)/1.5});
    // DIALOGO INTERNO
    DrawText(strCaixaDialogo, LARGURA * 0.04, ALTURA * 0.7, 20, WHITE);

    // PULAR
    // detecta o mouse dentro da área do texto
    if (CheckCollisionPointRec(GetMousePosition(), areaPular)) {
        
        // mudar cor do texto ao passar o mouse por cima
        corStrPular = (Color){ 0, 255, 255, 255 };
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Pular\n");
        }

    } else {
        corStrPular = WHITE;
    }

    // SALVAMENTOS
    // detecta o mouse dentro da área do texto
    if (CheckCollisionPointRec(GetMousePosition(), areaSalvamentos)) {
        
        // mudar cor do texto ao passar o mouse por cima
        corStrSalvamentos = (Color){ 0, 255, 255, 255 };
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Salvamentos\n");
        }

    } else {
        corStrSalvamentos = WHITE;
    }

    // se (clicar na tela) OU apertar Enter OU apertar Espaçamento
    if ((CheckCollisionPointRec(GetMousePosition(), fundoDeTela) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
        printf("Abrindo tela de input...\n");
        return TELA_INPUT;
    }
    
    
    return *tela;
}
