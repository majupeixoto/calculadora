/*
 * Calculadora Programador Didática
 * Autor: Maria Júlia Peixoto Oliveira
 * Data de criação: [21/08/2024]
 * Última atualização: [29/08/2024 e 18:07]
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
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("\nDigite um numero decimal: ");
            scanf("%d", &numero);
            decimalBinario(numero);
            break;
        
        case 2:
            printf("\nDigite um numero decimal: ");
            scanf("%d", &numero);
            decimalOctal(numero);
            break;
        
        case 3:
            printf("\nDigite um numero decimal: ");
            scanf("%d", &numero);
            decimalHexa(numero);
            break;
        
        case 4:
            printf("\nDigite um numero decimal: ");
            scanf("%d", &numero);
            decimalBCD(numero);
            break;


        //Questão Dois
        case 5:
            printf("\nDigite um numero decimal: ");
            scanf("%d", &numero);
            decimalA2(numero);
            break;
        
        //Questão Três
        case 6:
            printf("\nDigite um numero real: ");
            scanf("%le", &real);
            realFloatDouble(real);
            break;
        
        case 7:
            printf("Saindo...\n");
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

    int binario[32]; //depois explicar pq [32]
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

    int octal[32]; //explicar o pq é [32]
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
            hexadecimal[i] = 48 + resto; //Se o resto é menor que 10, ele é convertido diretamente para um caractere numérico ('0' a '9') usando a expressão 48 + resto. O valor 48 é a posição ASCII do caractere '0'.

        }else{
            hexadecimal[i] = 55 + resto; //Se o resto está entre 10 e 15, ele é convertido em um caractere hexadecimal ('A' a 'F') usando a expressão 55 + resto. O valor 55 é obtido subtraindo 10 da posição ASCII do caractere 'A' (65 - 10 = 55).

        }

        printf("%d / 16 = %d, resto = %c\n", numero, numero / 16, hexadecimal[i]);
        numero /= 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%c", hexadecimal[j]);
    }

    printf("\n");
}

void decimalBCD(int numero){
    printf("Conversao de %d para BCD:\n", numero);
    printf("Conversao de cada digito para BCD:\n");

    while(numero > 0){
        int digito = numero % 10;

        printf("%d: %04d\n", digito, digito); // Exemplo simples de BCD para cada dígito
        numero /= 10;
    }
}


void decimalA2(int numero){
    int bits[16];
    int negativo = 0;

    if(numero < 0){
        negativo = 1;
        numero = -numero; // Trabalha com o valor absoluto do número
    }

    // Convertendo para binário
    for(int i = 15; i >= 0; i--){
        bits[i] = numero % 2;
        numero /= 2;
    }

    if(negativo){
        // Complemento a 1
        for(int i = 0; i < 16; i++){
            bits[i] = !bits[i];
        }

        // Somando 1
        for(int i = 15; i >= 0; i--){
            if (bits[i] == 0) {
                bits[i] = 1;
                break;
            }else{
                bits[i] = 0;
            }
        }
    }

    printf("Representação em complemento a 2 (16 bits): ");

    for(int i = 0; i < 16; i++){
        printf("%d", bits[i]);
    }

    printf("\n");
}

void realFloatDouble(double real){
    /* code */
}