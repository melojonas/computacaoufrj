/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2023/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Jonas da Silva Melo
 * 
 * Descricao: <descrição sucinta dos objetivos do programa>
 * 
 * $Author$
 * $Date$
 * $Log$
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include "aula0901.h"

tipoErros ExibirConteudoArquivo(char *nomeArquivo) {
    FILE *arquivo;
    unsigned char buffer[16];
    size_t bytesRead;
    int i;

    if (nomeArquivo == NULL)
        return argumentoInvalido;

    arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL)
        return argumentoInvalido;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), arquivo)) > 0) {
        printf("%016lX | ", ftell(arquivo) - bytesRead);
        
        for (i = 0; i < bytesRead; i++)
            printf("%02X%c", buffer[i], (i == 7) ? ' ' : ' ');
        
        for (i = bytesRead; i < sizeof(buffer); i++)
            printf("   %c", (i == 7) ? ' ' : ' ');
        
        printf("| ");
        
        for (i = 0; i < bytesRead; i++)
            printf("%c", (buffer[i] >= 0x20 && buffer[i] < 0x7F) ? buffer[i] : '.');
        
        printf("\n");
    }
    
    fclose(arquivo);
    return ok;
}


tipoErros ConverterArquivoFormatoUnixParaFormatoDos(char *arquivoOriginal, char *arquivoConvertido) {
    FILE *original, *convertido;
    char *temporario = NULL;
    char *novoNome = NULL;
    time_t currentTime;
    struct tm *timeInfo;
    char backupName[256];
    int ch;

    if (arquivoOriginal == NULL)
        return argumentoInvalido;

    original = fopen(arquivoOriginal, "r");
    if (original == NULL)
        return erroArquivoOriginal;

    if (arquivoConvertido == NULL) {
        /* Criar arquivo temporário */
        temporario = strdup("convertido-XXXXXX");
        int fd = mkstemp(temporario);
        if (fd == -1) {
            fclose(original);
            return erroCriarArquivoTemporario;
        }
        close(fd);

        /* Criar nome de backup com timestamp */
        currentTime = time(NULL);
        timeInfo = localtime(&currentTime);
        strftime(backupName, sizeof(backupName), "%Y%m%d_%H%M%S", timeInfo);

        novoNome = (char *)malloc(strlen(arquivoOriginal) + strlen(".backup-") + strlen(backupName) + 1);
        strcpy(novoNome, arquivoOriginal);
        strcat(novoNome, ".backup-");
        strcat(novoNome, backupName);
    }

    /* Abrir arquivo convertido para escrita */
    convertido = fopen((arquivoConvertido == NULL) ? temporario : arquivoConvertido, "w");

    if (convertido == NULL) {
        fclose(original);
        free(temporario);
        return erroArquivoConvertido;
    }

    /* Converter conteúdo do arquivo original para formato DOS */
    while ((ch = fgetc(original)) != EOF) {
        if (ch == '\n')
            fputc('\r', convertido);
        fputc(ch, convertido);
    }

    fclose(original);
    fclose(convertido);

    /* Renomear arquivo original para backup */
    if (arquivoConvertido == NULL) {
        if (rename(arquivoOriginal, novoNome) != 0) {
            free(temporario);
            return erroRenomearOriginal;
        }
        /* Renomear arquivo temporário para original */
        if (rename(temporario, arquivoOriginal) != 0) {
            free(temporario);
            return erroRenomearConvertido;
        }
        free(temporario);
    }

    return ok;
}

/* $RCSfile$ */