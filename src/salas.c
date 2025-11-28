#include "salas.h"
#include "raygui.h" // Necessário para os botões

EstadoTela telaMapa(EstadoTela *tela, Imagens *imagens, int LARGURA, int ALTURA, int *idSalaAtual) {
    
    /*
        Dados referentes as salas (ID, posição no mapa interativo etc.
        Usamos static para criar apenas uma vez na memória
    */
    static SalaMapa salas[] = {
        // [0] Bibliotecas
        { (Rectangle){ 100, 200, 100, 100 }, ID_SALA_BIBLIOTECAS, "Bibliotecas", GREEN },
        // [1] Main
        { (Rectangle){ 250, 200, 100, 100 }, ID_SALA_MAIN, "Main()", YELLOW },
        // [2] Variaveis
        { (Rectangle){ 400, 200, 100, 100 }, ID_SALA_VARIAVEIS, "Variaveis", ORANGE },
        // [3] Output
        { (Rectangle){ 550, 100, 100, 100 }, ID_SALA_PRINT, "Output", RED },
        // [4] Input
        { (Rectangle){ 550, 300, 100, 100 }, ID_SALA_SCAN, "Input", RED }
    };

    EstadoTela proximaTela = *tela;

    // Fundo e linhas de conexão
    DrawRectangle(0, 0, LARGURA, ALTURA, RAYWHITE);
    DrawText("MAPA DA MASMORRA", LARGURA/2 - 100, 20, 20, BLACK);
    DrawText("Selecione a sala que deseja adentrar", LARGURA/2 - 120, 50, 16, DARKGRAY);

    
    DrawLine(200, 250, 250, 250, BLACK); // Biblioteca -> Main
    DrawLine(350, 250, 400, 250, BLACK); // Main -> Variaveis
    DrawLine(500, 250, 550, 150, BLACK); // Variaveis -> Output
    DrawLine(500, 250, 550, 350, BLACK); // Variaves -> Input

    // Deixa o fundo do botão transparente para usar a cor personalizada da sala
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(BLANK));
    

    // Botão 0: Bibliotecas
    DrawRectangleRec(salas[0].area, Fade(salas[0].cor, 0.4f));
    if (GuiButton(salas[0].area, salas[0].nome)) {
        *idSalaAtual = salas[0].idProximaSala; // Atualiza o ID
        proximaTela = TELA_JOGO;               // Muda a tela
    }

    // Botão 1: Main
    DrawRectangleRec(salas[1].area, Fade(salas[1].cor, 0.4f));
    if (GuiButton(salas[1].area, salas[1].nome)) {
        *idSalaAtual = salas[1].idProximaSala;
        proximaTela = TELA_JOGO;
    }

    // Botão 2: Variaveis
    DrawRectangleRec(salas[2].area, Fade(salas[2].cor, 0.4f));
    if (GuiButton(salas[2].area, salas[2].nome)) {
        *idSalaAtual = salas[2].idProximaSala;
        proximaTela = TELA_JOGO;
    }

    // Botão 3: Output
    DrawRectangleRec(salas[3].area, Fade(salas[3].cor, 0.4f));
    if (GuiButton(salas[3].area, salas[3].nome)) {
        *idSalaAtual = salas[3].idProximaSala;
        proximaTela = TELA_JOGO;
    }

    // Botão 4: Input
    DrawRectangleRec(salas[4].area, Fade(salas[4].cor, 0.4f));
    if (GuiButton(salas[4].area, salas[4].nome)) {
        *idSalaAtual = salas[4].idProximaSala;
        proximaTela = TELA_JOGO;
    }

    DrawText("Aperte 'M' para voltar ao Jogo", 10, ALTURA - 30, 15, GRAY);
    
    if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_TAB)) {
        return TELA_JOGO;
    }

    return proximaTela;
}