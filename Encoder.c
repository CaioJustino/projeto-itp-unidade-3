#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SPACING_DEFAULT 4
#define BAR_WIDTH_DEFAULT 3
#define HEIGHT_DEFAULT 50

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <Identificador EAN-8> <Arquivo de Saída .pbm> [Espaçamento (Opcional)] [Largura (Opcional)] [Altura (Opcional)]\n", argv[0]);
        return EXIT_FAILURE;
    }

    BarcodeConfig config = {
        .identifier = argv[1],
        .filename = argv[2],
        .spacing = (argc > 3) ? atoi(argv[3]) : SPACING_DEFAULT,
        .bar_width = (argc > 4) ? atoi(argv[4]) : BAR_WIDTH_DEFAULT,
        .height = (argc > 5) ? atoi(argv[5]) : HEIGHT_DEFAULT
    };

    // Verifica se o arquivo tem a extensão ".pbm"
    const char *extension = strrchr(config.filename, '.');
    if (!extension || strcmp(extension, ".pbm") != 0) {
        fprintf(stderr, "Erro! O arquivo de saída deve ter a extensão .pbm\n");
        return EXIT_FAILURE;
    }

    if (config.spacing <= 0 || config.bar_width <= 0 || config.height <= 0) {
        fprintf(stderr, "Erro! Espaçamento, largura e altura precisam ser valores positivos.\n");
        return EXIT_FAILURE;
    }

    // Verifica se o arquivo já existe
    FILE *file = fopen(config.filename, "r");
    if (file) {
        fclose(file);
        printf("O arquivo '%s' já existe. Deseja sobrescrevê-lo? (S/N): ", config.filename);

        char resposta;
        if (scanf(" %c", &resposta) != 1) {
            fprintf(stderr, "Erro ao ler a resposta do usuário.\n");
            return EXIT_FAILURE;
        }

        if (resposta != 'S' && resposta != 's') {
            fprintf(stderr, "Erro! O arquivo resultante já existe.\n");
            return EXIT_FAILURE;
        }
    }

    if (!gerar_codigo(&config)) {
        return EXIT_FAILURE;
    }

    printf("Imagem do código de barras criada com sucesso! Ela pode ser acessada no arquivo: %s\n", config.filename);
    return EXIT_SUCCESS;
}
