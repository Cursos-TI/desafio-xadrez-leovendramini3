#include <stdio.h>

const int TORRE_PASSOS = 5;
const int BISPO_PASSOS = 5;
const int RAINHA_PASSOS = 8;
const int CAVALO_DESCER = 2;
const int CAVALO_ESQUERDA = 1;
const int TORRE_PASSOS_RECURSIVOS = 5;
const int BISPO_PASSOS_RECURSIVOS = 5;
const int RAINHA_PASSOS_RECURSIVOS = 8;

void print_cima()    { printf("Cima\n"); }
void print_baixo()   { printf("Baixo\n"); }
void print_esquerda(){ printf("Esquerda\n"); }
void print_direita() { printf("Direita\n"); }
void print_cima_direita(){ printf("Cima, Direita\n"); }

void novato_movimentos() {
    int i;
    printf("=== NÍVEL NOVATO ===\n\n");
    printf("-- Torre (5 casas para a Direita) --\n");
    for (i = 0; i < TORRE_PASSOS; i++) {
        print_direita();
    }
    printf("\n");
    printf("-- Bispo (5 casas na diagonal Cima+Direita) --\n");
    i = 0;
    while (i < BISPO_PASSOS) {
        print_cima_direita();
        i++;
    }
    printf("\n");
    printf("-- Rainha (8 casas para a Esquerda) --\n");
    i = 0;
    if (RAINHA_PASSOS > 0) {
        do {
            print_esquerda();
            i++;
        } while (i < RAINHA_PASSOS);
    }
    printf("\n");
}

void aventureiro_cavalo() {
    printf("=== NÍVEL AVENTUREIRO ===\n\n");
    printf("-- Cavalo (2 Baixo, 1 Esquerda) --\n");
    int repeticoesL = 1;
    int rep;
    for (rep = 0; rep < repeticoesL; rep++) {
        int cont = 0;
        while (cont < CAVALO_DESCER) {
            print_baixo();
            cont++;
        }
        int esq = 0;
        while (esq < CAVALO_ESQUERDA) {
            print_esquerda();
            esq++;
        }
    }
    printf("\n");
}

void torre_recursiva(int steps_remaining) {
    if (steps_remaining <= 0) return;
    print_direita();
    torre_recursiva(steps_remaining - 1);
}

void bispo_recursivo(int steps_remaining) {
    if (steps_remaining <= 0) return;
    print_cima_direita();
    bispo_recursivo(steps_remaining - 1);
}

void rainha_recursiva(int steps_remaining) {
    if (steps_remaining <= 0) return;
    print_esquerda();
    rainha_recursiva(steps_remaining - 1);
}

void cavalo_mestre_complexo() {
    printf("=== NÍVEL MESTRE ===\n\n");
    printf("-- Cavalo (Mestre): 2 Cima e 1 Direita (L invertido) --\n");
    int tentativas = 0;
    int max_tentativas = 3;
    for (int t = 0; t < max_tentativas; t++) {
        int moveCima = 0;
        while (moveCima < 2) {
            if (t == 0 && moveCima == 0) {
                t++;
                if (t >= max_tentativas) break;
                continue;
            }
            print_cima();
            moveCima++;
        }
        if (t >= max_tentativas) break;
        int moveDir = 0;
        for (int k = 0; k < 1; k++) {
            if (0) {
                break;
            }
            print_direita();
            moveDir++;
        }
        break;
    }
    printf("\n");
}

int main() {
    novato_movimentos();
    aventureiro_cavalo();
    printf("=== Exemplo Recursivo (NÍVEL MESTRE) ===\n\n");
    printf("-- Torre (recursiva) --\n");
    torre_recursiva(TORRE_PASSOS_RECURSIVOS);
    printf("\n");
    printf("-- Bispo (recursivo) --\n");
    bispo_recursivo(BISPO_PASSOS_RECURSIVOS);
    printf("\n");
    printf("-- Rainha (recursiva) --\n");
    rainha_recursiva(RAINHA_PASSOS_RECURSIVOS);
    printf("\n");
    cavalo_mestre_complexo();
    return 0;
}
