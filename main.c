/*
 * Calculadora Programador Didática
 * Autor: Maria Júlia Peixoto Oliveira
 * Data de criação: [21/08/2024]
 * Última atualização: [30/08/2024 às 20:19]
 * GitHub: https://github.com/majupeixoto/calculadora.git
 * 
 * Descrição: Este programa realiza conversões de base 10 para outras bases e representações numéricas, 
 * mostrando os passos detalhados na tela.
 *
 * Revisões/Atualizações:
 * - [21/08/2024 às 12:10]: Implementação inicial.
 * - [27/08/2024 às 09:38]: Escrita do README.
 * - [27/08/2024 às 09:44]: Atualização do README.
 * - [29/08/2024 às 09:07]: EScrita do menu e esqueleto das funções.
 * - [29/08/2024 às 11:12]: Implementação de algumas funções. (Implementação da QUESTÃO UM)
 * - [29/08/2024 às 11:46]: Refinamento da interface.
 * - [29/08/2024 às 18:07]: Criação do cabeçallho, refinamento da interface, otimização dos códigos.
 * - [29/08/2024 às 19:27]: Implementação correta da QUESTÃO UM, com a conversao BCD corrigida.
 * - [29/08/2024 às 19:40]: Implementação correta da QUESTÃO DOIS, sendo explicada de forma didática como a questão pede.
 * - [30/08/2024 às 20:19]: Implementação da QUESTÃO TRÊS
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void decimalBinario(int numero);
void decimalOctal(int numero);
void decimalHexa(int numero);
void decimalBCD(int numero);
void decimalA2(int numero);
void realFloatDouble(double real);

int main(){
    int opcao;
    do{
        printf("\n============================= MENU ==============================\n");
        printf("[1] Conversao de numeros decimais para binario; \n");
        printf("[2] Conversao de numeros decimais para octal; \n");
        printf("[3] Conversao de numeros decimais para hexadecimal; \n");
        printf("[4] Conversao de cada digito decimal para seu equivalente BCD; \n");
        printf("[5] Exibe a representacao do numero decimal em complemento a 2; \n");
        printf("[6] Conversao de numeros reais para suas representacoes float e double; \n");
        printf("[7] Sair; \n");

        printf("\n Digite a opcao que deseja: ");
        scanf("%d", &opcao);

        printf("\n================================================================\n");

        int numero;
        double real;

        switch(opcao){
        //Questçao UM
        case 1:
            printf("\nDigite um numero decimal para converte-lo ao binario: ");
            scanf("%d", &numero);
            decimalBinario(numero);
            break;
        
        case 2:
            printf("\nDigite um numero decimal para converte-lo ao octal: ");
            scanf("%d", &numero);
            decimalOctal(numero);
            break;
        
        case 3:
            printf("\nDigite um numero decimal para converte-lo ao hexadecimal: ");
            scanf("%d", &numero);
            decimalHexa(numero);
            break;
        
        case 4:
            printf("\nDigite um numero decimal para converte-lo ao seu equivalente BCD: ");
            scanf("%d", &numero);
            decimalBCD(numero);
            break;


        //Questão Dois
        case 5:
            printf("\nDigite um numero decimal para converte-lo ao complemento a 2: ");
            scanf("%d", &numero);
            decimalA2(numero);
            break;
        
        //Questão Três
        case 6:
            printf("\nDigite um numero real para converte-lo ao float e ao double: ");
            scanf("%le", &real);
            realFloatDouble(real);
            break;
        
        case 7:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }
    }while(opcao != 7);

    return 0;
}

void decimalBinario(int numero){
    if(numero == 0){
        printf("Resultado em binario: 0\n");
        return;
    }

    printf("Conversao de %d para binario:\n", numero);
    printf("Divisoes sucessivas por 2 e coleta dos restos(0 ou 1):\n");

    int binario[32];
    int i = 0;

    while(numero > 0){
        binario[i] = numero % 2;
        printf("%d / 2 = %d, resto = %d\n", numero, numero / 2, binario[i]);
        numero /= 2;
        i++;
    }
    printf("Resultado em binario: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void decimalOctal(int numero){
    printf("Conversao de %d para octal:\n", numero);
    printf("Divisoes sucessivas por 8 e coleta dos restos:\n");

    int octal[32];
    int i = 0;

    while(numero > 0){
        octal[i] = numero % 8;
        printf("%d / 8 = %d, resto = %d\n", numero, numero / 8, octal[i]);
        numero /= 8;
        i++;
    }
    printf("Resultado em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimalHexa(int numero){
    printf("Conversao de %d para hexadecimal:\n", numero);
    printf("Divisoes sucessivas por 16 e coleta dos restos:\n");

    char hexadecimal[32];
    int i = 0;

    while(numero > 0){
        int resto = numero % 16;

        if(resto < 10){
            hexadecimal[i] = 48 + resto;

        }else{
            hexadecimal[i] = 55 + resto;

        }

        printf("%d / 16 = %d, resto = %c\n", numero, numero / 16, hexadecimal[i]);
        numero /= 16;
        i++;
    }

    printf("Resultado em hexadecimal: Ox");
    for(int j = i - 1; j >= 0; j--){
        printf("%c", hexadecimal[j]);
    }

    printf("\n");
}

void decimalBCD(int numero) {
    if (numero == 0) {
        printf("Conversao de %d para BCD: 0000\n", numero);
        return;
    }

    printf("Conversao de %d para BCD:\n", numero);
    printf("Conversao de cada digito para BCD:\n");

    int bcd[16]; // Armazena os dígitos em BCD
    int i = 0;

    // Extrai cada dígito do número e armazena no array `bcd`
    while (numero > 0) {
        int digito = numero % 10; // Obtém o último dígito do número
        bcd[i] = digito;
        numero /= 10; // Remove o último dígito do número
        i++;
    }

    printf("\nEtapas da conversao:\n");
    for (int j = i - 1; j >= 0; j--) {
        printf("Digito %d: %d\n", i - j, bcd[j]); // Mostra cada dígito extraído
        printf("Em binario (4 bits): ");

        // Converte o dígito para binário de 4 bits
        int valor = bcd[j];
        int bits[4] = {0, 0, 0, 0}; // Array para armazenar os 4 bits

        for (int k = 3; k >= 0; k--) {
            bits[k] = valor % 2;
            valor /= 2;           // Divide por 2 para preparar o próximo bit
        }

        for (int k = 0; k < 4; k++) {
            printf("%d", bits[k]);  // Exibe cada bit em ordem
        }

        printf("\n");
    }

    printf("\nResultado em BCD (Binario Codificado Decimal): ");
    for(int j = i - 1; j >= 0; j--){
        int valor = bcd[j];
        int bits[4] = {0, 0, 0, 0}; // Array para armazenar os 4 bits

        for (int k = 3; k >= 0; k--){
            bits[k] = valor % 2;
            valor /= 2;           // Divide por 2 para preparar o próximo bit
        }

        for(int k = 0; k < 4; k++){
            printf("%d", bits[k]);  // Exibe cada bit em ordem
        }

        printf(" ");
    }
    printf("\n");
}


void decimalA2(int numero){
    int bits[16];
    int negativo = 0;

    if(numero < 0){
        negativo = 1;
        numero = -numero; // Trabalha com o valor absoluto do número
    }

    // Convertendo para binário
    printf("\nRepresentação binaria inicial de %d: ", negativo ? -numero : numero);
    for(int i = 15; i >= 0; i--){
        bits[i] = numero % 2;
        numero /= 2;
    }

    // Mostrar a representação binária
    for(int i = 0; i < 16; i++){
        if(i > 0 && i % 4 == 0) printf(" "); // Adiciona espaço a cada 4 dígitos
        printf("%d", bits[i]);
    }
    printf("\n");

    if(negativo){
        // Complemento a 1
        printf("\nComplemento a 1 (inversao dos bits): ");
        for(int i = 0; i < 16; i++){
            bits[i] = !bits[i];
        }

        // Mostrar o complemento a 1
        for(int i = 0; i < 16; i++){
            if(i > 0 && i % 4 == 0) printf(" "); // Adiciona espaço a cada 4 dígitos
            printf("%d", bits[i]);
        }
        printf("\n");

        // Somando + 1
        printf("\nSomando 1 ao complemento a 1: ");
        for(int i = 15; i >= 0; i--){
            if (bits[i] == 0) {
                bits[i] = 1;
                break;
            } else {
                bits[i] = 0;
            }
        }

        // Mostrar em complemento a 2
        for(int i = 0; i < 16; i++){
            if(i > 0 && i % 4 == 0) printf(" "); // Adiciona espaço a cada 4 dígitos
            printf("%d", bits[i]);
        }
        printf("\n");
    }

    printf("\nRepresentacao em complemento a 2 (16 bits): ");
    for(int i = 0; i < 16; i++){
        if(i > 0 && i % 4 == 0) printf(" "); // Adiciona espaço a cada 4 dígitos
        printf("%d", bits[i]);
    }
    printf("\n");
}

void printFloatBits(float numero) {
    uint32_t bits = *(uint32_t *)&numero;

    printf("\n=== Representacao Float ===\n");
    printf("Numero: %.7f\n", numero);
    printf("Sinal: %d\n", (bits >> 31) & 1); // O símbolo ">>" significa que houve um deslocamento de bits para a direita
    printf("Expoente: %d\n", (bits >> 23) & 0xFF); // Expoente
    printf("Expoente com vies: %d\n", ((bits >> 23) & 0xFF) - 127); // Expoente com viés
    printf("Fracao: 0x%06x\n", bits & 0x7FFFFF); // Mantissa
}

void printDoubleBits(double numero) {
    uint64_t bits = *(uint64_t *)&numero;

    printf("\n=== Representacao Double ===\n");
    printf("Numero: %.15lf\n", numero);
    printf("Sinal: %d\n", (bits >> 63) & 1); // O símbolo ">>" significa que houve um deslocamento de bits para a direita
    printf("Expoente: %d\n", (bits >> 52) & 0x7FF); // Expoente
    printf("Expoente com viés: %d\n", ((bits >> 52) & 0x7FF) - 1023); // Expoente com viés
    printf("Fracao: 0x%013lx\n", bits & 0xFFFFFFFFFFFFF); // Mantissa
}

void realFloatDouble(double real) {
    float numeroFloat = (float)real;
    printFloatBits(numeroFloat);
    printDoubleBits(real);
}