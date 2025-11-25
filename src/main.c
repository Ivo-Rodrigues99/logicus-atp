// importacao de arquivos header de bibliotecas padrao

#include <stdio.h>

// importacao de arquivos header de bibliotecas third party

#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"

// importacao de arquivos header de prototipacao e carregamento

#include "save.h"
#include "dialogo.h"
#include "recursos.h"

// declaracao de constantes globais
// ...
typedef enum {
    TELA_INICIAL = 0,
    TELA_MENU,
    TELA_JOGO,
    TELA_MAPA
} EstadoTela;

//Identificadores das salas
typedef enum {
	ID_SALA_NULA = 0,
	ID_SALA_BIBLIOTECAS,
	ID_SALA_MAIN,
	ID_SALA_VARIAVEIS,
	ID_SALA_PRINT,
	ID_SALA_SCAN
} IdSala;

//Struct para representar uma sala no mapa
typedef struct {
	Rectangle area;			//Área clicável do mapa (eixos, largura, altura)
	IdSala idProximaSala;	//Qual ID de sala vai ser carregado
	const char *nome;		//Nome da sala que vai aparecer na tela
	Color cor;				//Cor da sala no mapa
} SalaMapa;

// define tamanho da janela

#define LARGURA 800
#define ALTURA 480

// declaracao de variaveis globais
// ...

// prototipação de funções
//Agora mudarTela recebe um ponteiro pro ID da sala
void mudarTela (EstadoTela *telaAtual, Imagens *imagens, int *idSalaAtual);
// cada tela é representada por uma função
EstadoTela telaInicial(EstadoTela **tela);
EstadoTela telaMenu(EstadoTela **tela, Imagens **imagens);

//telaMapa e telaJogo tbm recebem ponteiro pro ID da sala
EstadoTela telaJogo(EstadoTela **tela, int *idSalaAtual);
EstadoTela telaMapa(EstadoTela **tela, int *idSalaAtual);

int main(void) {
    // aloca estaticamente memoria para recursos de imagem
    Imagens imagens = {0};

    // declara a tela inicial ao abrir o programa
    EstadoTela tela = TELA_INICIAL;
    
    //Variavel para controlar em qual sala o jogador está
    int idSalaAtual = ID_SALA_NULA;

    // inicializa janela da biblioteca RayGUI
    InitWindow(LARGURA, ALTURA, "Logicus;");
    SetTargetFPS(60);

    // carrega recursos de imagem do jogo
    carregarRecursos(&imagens);

    // inicia game loop para desenhar na janela
    while (!WindowShouldClose()) {

        BeginDrawing();
            // limpa cor de fundo para proxima iteracao
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // através desta função acontecem todas as transições
            mudarTela(&tela, &imagens, &idSalaAtual);

        EndDrawing();

    }
    
    // descarrega recursos de imagem alocadas pelo rayGUI
    descarregarRecursos(&imagens);

    // finaliza janela
    CloseWindow();
    return 0;
}

//função que muda de tela ativamente
void mudarTela (EstadoTela *telaAtual, Imagens *imagens, int *idSalaAtual){
    // estrutura de controle das telas
    switch(*telaAtual){
        case TELA_INICIAL:
            *telaAtual = telaInicial(&telaAtual);
            break;
        
        case TELA_MENU:
            *telaAtual = telaMenu(&telaAtual, &imagens);
            break;
        
        case TELA_JOGO:
            *telaAtual = telaJogo(&telaAtual, idSalaAtual);
            break;

        case TELA_MAPA:
            *telaAtual = telaMapa(&telaAtual, idSalaAtual);
            break;
    }
}

EstadoTela telaInicial(EstadoTela **tela){
	DrawText("TELA INICIAL", 300, 200, 30, BLACK);
    DrawText("Pressione ENTER para começar", 250, 250, 20, BLACK);       
	if (IsKeyPressed(KEY_ENTER)) {
        return TELA_MENU;
    } else {
        // se Enter não for apertado a tela permanece a mesma
        return **tela;
    }
}

EstadoTela telaMenu(EstadoTela **tela, Imagens **imagens){
    // desenha splash arte do menu
    DrawTexture((**imagens).interface[SPLASH_ARTE], 0, 0, WHITE);
    
    // desenha titulo
    DrawTexture((**imagens).interface[TITULO_ARTE], (LARGURA / 2) - 180, ALTURA / 28, WHITE);
    DrawText("TELA DE MENU - Aperte Enter para continuar", 150, 200, 20, WHITE);

    if (IsKeyPressed(KEY_ENTER))
    {
        return TELA_JOGO;
    } else {
        // se Enter não for apertado a tela permanece a mesma
        return **tela;
    }
}

EstadoTela telaJogo(EstadoTela **tela, int *idSalaAtual){
    
    //Nova barra superior e indicador de mapa
    DrawRectangle(0, 0, LARGURA, 40, LIGHTGRAY);
    DrawText("Logicus - Pré-Alpha", 10, 10, 20, BLACK);
    DrawText("Aperte 'M' para abrir o mapa", LARGURA - 200, 10, 13, BLACK);
    DrawText("TELA INICIAL EM DESENVOLVIMENTO, PROSSIGA PARA O MAPA", 80, 200, 20, BLACK);
    
    //Viaja para a sala especifica de acordo com o ID
    switch (*idSalaAtual){
    	
    	case ID_SALA_BIBLIOTECAS:
    		DrawRectangle(0, 40, LARGURA, ALTURA, GREEN); //Fundo da sala
    		DrawText("Sala da Masmorra: Bibliotecas", 50, 100, 40, WHITE);
    		DrawText("Aqui reside o conhecimento pleno de <stdio.h>!!!", 50, 400, 20, WHITE);
    		break;
		case ID_SALA_MAIN:
			DrawRectangle(0, 40, LARGURA, ALTURA, YELLOW); //Fundo da sala
    		DrawText("Sala da Masmorra: Main()", 50, 100, 40, WHITE);
    		DrawText("A Main() será sua arma principal", 50, 400, 20, WHITE);
    		break;
		case ID_SALA_VARIAVEIS:
			DrawRectangle(0, 40, LARGURA, ALTURA, ORANGE); //Fundo da sala
    		DrawText("Sala da Masmorra: Variaveis", 50, 100, 40, WHITE);
    		DrawText("Declare suas habilidades!", 50, 400, 20, WHITE);
    		break;
		case ID_SALA_PRINT:
			DrawRectangle(0, 40, LARGURA, ALTURA, RED); //Fundo da sala
    		DrawText("Sala da Masmorra: Output", 50, 100, 40, WHITE);
    		DrawText("Aprenda a liberar sua magia pelo mundo", 50, 400, 20, WHITE);
    		break;
		case ID_SALA_SCAN:
			DrawRectangle(0, 40, LARGURA, ALTURA, RED); //Fundo da sala
    		DrawText("Sala da Masmorra: Input", 50, 100, 40, WHITE);
    		DrawText("Aprenda a absorver a magia do mundo", 50, 400, 20, WHITE);
    		break;
	}
	
	//Tecla para entrar no mapa
	if (IsKeyPressed(KEY_M)) {
        return TELA_MAPA;
    }

    // Tecla para sair do mapa
    if (IsKeyPressed(KEY_ESCAPE)){
        return TELA_MENU;
    }
    
    return **tela;

}

EstadoTela telaMapa(EstadoTela **tela, int *idSalaAtual){
    SalaMapa salas[] = {
        { (Rectangle){ 100, 200, 100, 100 }, ID_SALA_BIBLIOTECAS, "Bibliotecas", GREEN },
        { (Rectangle){ 250, 200, 100, 100 }, ID_SALA_MAIN, "Main()", YELLOW },
        { (Rectangle){ 400, 200, 100, 100 }, ID_SALA_VARIAVEIS, "Variaveis", ORANGE },
        { (Rectangle){ 550, 100, 100, 100 }, ID_SALA_PRINT, "Output", RED },
        { (Rectangle){ 550, 300, 100, 100 }, ID_SALA_SCAN, "Input", RED }
    };
    
    int qtdSalas = 5;
    
    DrawText("Mapa da Masmorra", 280, 20, 20, BLACK);
    DrawText("Selecione uma sala para adentrar!", 280, 50, 16, DARKGRAY);
    
    Vector2 mousePos = GetMousePosition();
    EstadoTela proximaTela = **tela;
    
    // 2. Loop para desenhar e detectar cliques
    for (int i = 0; i < qtdSalas; i++) {
        
        bool mouseEmCima = CheckCollisionPointRec(mousePos, salas[i].area);

        if (mouseEmCima) {
            //Hover nos botoes das salas
            DrawRectangleRec(salas[i].area, Fade(salas[i].cor, 0.8f));
            DrawRectangleLinesEx(salas[i].area, 3, BLACK);
            
            //Dectando o clique
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                *idSalaAtual = salas[i].idProximaSala; //Muda o ID para alterar a sala
                proximaTela = TELA_JOGO;          	   //Altera a tela
            }
        } else {
            DrawRectangleRec(salas[i].area, Fade(salas[i].cor, 0.4f));
            DrawRectangleLinesEx(salas[i].area, 1, DARKGRAY);
        }

        //Mostra o nome da sala no quadradinho do mapa
        DrawText(salas[i].nome, (int)salas[i].area.x + 10, (int)salas[i].area.y + 10, 16, DARKGRAY);
    }

    //Sair do mapa sem ir para outra sala
    DrawText("Aperte 'M' para sair do mapa", 10, ALTURA - 30, 15, GRAY);
    if (IsKeyPressed(KEY_M)){
		return TELA_JOGO;
	}
	

    return proximaTela;
}