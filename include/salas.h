#ifndef SALAS_H
#define SALAS_H

#include "raylib.h"
#include "recursos.h"
#include "telas.h" 

// Definição dos IDs das Salas
typedef enum {
    ID_SALA_NULA = 0,
    ID_SALA_BIBLIOTECAS,
    ID_SALA_MAIN,
    ID_SALA_VARIAVEIS,
    ID_SALA_PRINT,
    ID_SALA_SCAN
} IdSala;

// Definição da Struct da Sala
typedef struct {
    Rectangle area;         // Onde o botão fica
    IdSala idProximaSala;   // Para onde ele leva
    const char *nome;       // Texto do botão
    Color cor;              // Cor temática
} SalaMapa;

// Protótipo da Função
EstadoTela telaMapa(EstadoTela *tela, Imagens *imagens, int LARGURA, int ALTURA, int *idSalaAtual);

#endif