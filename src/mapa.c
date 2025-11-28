#include "mapa.h"
#include "raygui.h" // Necessário para os botões

EstadoTela telaMapa(EstadoTela *tela, Imagens *imagens, int LARGURA, int ALTURA, int *idSalaAtual) {
    
    // --- 1. DADOS DAS SALAS (Organizados e fáceis de editar) ---
    // Usamos static para criar apenas uma vez na memória
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

    // --- 2. DESENHO DO FUNDO E CONEXÕES ---
    DrawRectangle(0, 0, LARGURA, ALTURA, RAYWHITE);
    DrawText("MAPA DA MASMORRA", LARGURA/2 - 100, 20, 20, BLACK);
    DrawText("Selecione um módulo para carregar...", LARGURA/2 - 120, 50, 16, DARKGRAY);

    // Linhas de conexão (Hardcoded para design fixo)
    DrawLine(200, 250, 250, 250, BLACK); // Biblio -> Main
    DrawLine(350, 250, 400, 250, BLACK); // Main -> Var
    DrawLine(500, 250, 550, 150, BLACK); // Var -> Output
    DrawLine(500, 250, 550, 350, BLACK); // Var -> Input

    // --- 3. ESTILIZAÇÃO DO RAYGUI ---
    // Deixa o fundo do botão transparente para usarmos nossa cor personalizada
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(BLANK));

    // --- 4. BOTÕES (Implementação Manual sem Laço) ---

    // --- Botão 0: Bibliotecas ---
    DrawRectangleRec(salas[0].area, Fade(salas[0].cor, 0.4f)); // Fundo colorido suave
    if (GuiButton(salas[0].area, salas[0].nome)) {
        *idSalaAtual = salas[0].idProximaSala; // Atualiza o ID
        return TELA_SALA;               // Muda a tela
    }

    // --- Botão 1: Main ---
    DrawRectangleRec(salas[1].area, Fade(salas[1].cor, 0.4f));
    if (GuiButton(salas[1].area, salas[1].nome)) {
        *idSalaAtual = salas[1].idProximaSala;
        return TELA_SALA;
    }

    // --- Botão 2: Variaveis ---
    DrawRectangleRec(salas[2].area, Fade(salas[2].cor, 0.4f));
    if (GuiButton(salas[2].area, salas[2].nome)) {
        *idSalaAtual = salas[2].idProximaSala;
        return TELA_SALA;
    }

    // --- Botão 3: Output ---
    DrawRectangleRec(salas[3].area, Fade(salas[3].cor, 0.4f));
    if (GuiButton(salas[3].area, salas[3].nome)) {
        *idSalaAtual = salas[3].idProximaSala;
        return TELA_SALA;
    }

    // --- Botão 4: Input ---
    DrawRectangleRec(salas[4].area, Fade(salas[4].cor, 0.4f));
    if (GuiButton(salas[4].area, salas[4].nome)) {
        *idSalaAtual = salas[4].idProximaSala;
        return TELA_SALA;
    }

    // --- 5. BOTÃO VOLTAR ---
    // Restaurar estilo padrão se quiser que esse botão seja cinza, 
    // ou desenhar manualmente também.
    DrawText("Aperte 'M' para voltar ao Jogo", 10, ALTURA - 30, 15, GRAY);
    
    if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_TAB)) {
        return TELA_JOGO;
    }

    return proximaTela;
}
