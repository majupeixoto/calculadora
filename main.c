#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao;
    do{
        printf("\n ============================ MENU ============================= \n");
        printf("[1] Conversao de numeros decimais para binario; \n");
        printf("[2] Conversao de numeros decimais para octal; \n");
        printf("[3] Conversao de numeros decimais para hexadecimal; \n");
        printf("[4] Conversao de cada digito decimal para seu equivalente BCD; \n");
        printf("[5] Exibe a representacao do numero decimal em complemento a 2; \n");
        printf("[6] Conversão de numeros reais para suas representacoes float e double; \n");
        printf("[7] Sair; \n");

        printf("Digite a opcao que deseja: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            /* decimalBinario */
            break;
        
        case 2:
            /* decimalOctal */
            break;
        
        case 3:
            /* decimalHexa */
            break;
        
        case 4:
            /* decimalBCD */
            break;
        
        case 5:
            /* decimalA2 */
            break;
        
        case 6:
            /* realFloatDouble */
            break;
        
        case 7:
            /* Sair... */
            break;

        default:
            break;
        }
    }while(opcao != 7);

    return 0;
}

void decimalBinario(){
    /* code */
}

void decimalOctal(){
    /* code */
}

void decimalHexa(){
    /* code */
}

void decimalBCD(){
    /* code */
}

void decimalA2(){
    /* code */
}

void realFloatDouble(){
    /* code */
}