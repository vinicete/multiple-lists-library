#ifndef NOME_DO_ARQUIVO_H
#define NOME_DO_ARQUIVO_H

#include <locale.h>
#include <string.h>
#include <stdio.h>

// Função auxiliar para definir e restaurar o locale
char* MudarLocale() {
    char *localeOriginal = setlocale(LC_ALL, NULL);
    if (localeOriginal != NULL) {
        localeOriginal = strdup(localeOriginal);
    }
    setlocale(LC_ALL, "C");
    return localeOriginal;
}

void RestaurarLocale(char* localeOriginal) {
    if (localeOriginal != NULL) {
        setlocale(LC_ALL, localeOriginal);
        free(localeOriginal);
    }
}

void ClearTela(void) {
    char *localeOriginal = MudarLocale();

    // limpa tela pricipal e mensagem
    int x, y;
    for (x = 30; x <= 78; x++) {
        for (y = 6; y <= 20; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }

    RestaurarLocale(localeOriginal);
}

void ClearMensagem(void) {
    char *localeOriginal = MudarLocale();

    // limpar mensagem
    int x;
    for (x = 15; x < 78; x++) {
        gotoxy(x, 23);
        printf(" ");
    }
    gotoxy(15, 23);

    RestaurarLocale(localeOriginal);
}

void ClearNota(void) {
    char *localeOriginal = MudarLocale();

    // limpa tela pricipal e mensagem
    int x, y;
    for (x = 2; x <= 79; x++) {
        for (y = 5; y <= 21; y++) {
            gotoxy(x, y);
            printf(" ");
        }
    }

    RestaurarLocale(localeOriginal);
}

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF) {
    char *localeOriginal = MudarLocale();

    int i;
    textcolor(CorT);
    textbackground(CorF);
    gotoxy(CI, LI);
    printf("%c", 201);
    gotoxy(CI, LF);
    printf("%c", 200);
    gotoxy(CF, LI);
    printf("%c", 187);
    gotoxy(CF, LF);
    printf("%c", 188);
    for (i = CI + 1; i < CF; i++) {
        gotoxy(i, LI);
        printf("%c", 205);
        gotoxy(i, LF);
        printf("%c", 205);
    }
    for (i = LI + 1; i < LF; i++) {
        gotoxy(CI, i);
        printf("%c", 186);
        gotoxy(CF, i);
        printf("%c", 186);
    }

    textcolor(7);
    textbackground(0);

    RestaurarLocale(localeOriginal);
}

void Formulario(void) {
    char *localeOriginal = MudarLocale();

    system("cls");
    Moldura(1, 1, 80, 25, 12, 3);
    gotoxy(24, 3);
    textcolor(12);
    printf(" # # #  TRABALHO LEANDRO  # # #");
    Moldura(2, 2, 79, 4, 12, 4);
    Moldura(2, 5, 27, 21, 12, 3);
    Moldura(2, 22, 79, 24, 12, 4);
    Moldura(28, 5, 79, 21, 12, 3);
    gotoxy(4, 23);
    textcolor(12);
    printf("Mensagem: ");
    
    gotoxy(7, 7);
    printf("   ***MENU***\n");
    gotoxy(5, 9);
    printf("[A] Excluir Livro\n");
    gotoxy(5,11);
    printf("  ***Relatorios***");
    gotoxy(5, 13);
    printf("[B] Livros p/ autor\n");
    gotoxy(5, 14);
    printf("[C] Livros p/ editora\n");
    gotoxy(5, 15);
    printf("[D] Autores sem livro\n");
    gotoxy(5, 17);
    printf("[E] Exibicoes\n");
    gotoxy(5, 19);
    printf("[ESC] Sair\n");
    ClearMensagem();
    printf("Escolha uma opcao do Menu: ");

    RestaurarLocale(localeOriginal);
}

void Formulario2(void) {
    char *localeOriginal = MudarLocale();

    system("cls");
    Moldura(1, 1, 80, 25, 12, 3);
    gotoxy(24, 3);
    textcolor(12);
    printf(" # # #  TRABALHO LEANDRO  # # #");
    Moldura(2, 2, 79, 4, 12, 4);
    Moldura(2, 22, 79, 24, 12, 4);
    Moldura(2, 5, 79, 21, 12, 3);
    gotoxy(4, 23);
    textcolor(12);
    printf("Mensagem: ");

    RestaurarLocale(localeOriginal);
}

void ClearRelatorio(void) {
    char *localeOriginal = MudarLocale();

    // limpa tela pricipal e mensagem
    int x, y;
    for (x = 2; x <= 79; x++) {
        for (y = 5; y <= 21; y++) {
            gotoxy(x, y);
            Sleep(0.5);
            printf(" ");
        }
    }

    RestaurarLocale(localeOriginal);
}

void ClearPartePequena(void) {
    char *localeOriginal = MudarLocale();

    // limpa tela pricipal e mensagem
    int x, y;
    for (x = 2; x <= 79; x++) {
        for (y = 16; y <= 21; y++) {
            gotoxy(x, y);
            Sleep(0.5);
            printf(" ");
        }
    }

    RestaurarLocale(localeOriginal);
}

void ClearAreaExibicao(void) {
    char *localeOriginal = MudarLocale();

    int x, y;
    for (x = 30; x <= 75; x++) {
        for (y = 6; y <= 19; y++) {
            gotoxy(x, y);
            Sleep(0.5);
            printf(" ");
        }
    }

    RestaurarLocale(localeOriginal);
}

#endif // NOME_DO_ARQUIVO_H
