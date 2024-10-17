#include <stdio.h>

#define PRECO 30.50

void menu();
void filmesDisponiveis();
void valoresIngressos();
void comprarIngressos();
void pausar();
void novaCompra(); // função para escolher entre nova compra ou sair

int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                filmesDisponiveis();
                pausar();
                break;
            case 2:
                valoresIngressos();
                pausar();
                break;
            case 3:
                comprarIngressos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                pausar();
        }
    } while(opcao != 0);

    return 0;
}

// função do menu
void menu() {
    printf("\nBem-vindo ao cinema!\n");
    printf("1 - Filmes disponíveis\n");
    printf("2 - Valores dos ingressos\n");
    printf("3 - Comprar ingressos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

//lista filmes disponiveis
void filmesDisponiveis() {
    printf("\nFilmes disponíveis:\n");
    printf("1 - É assim que acaba\n");
    printf("2 - Deadpool e Wolverine\n");
    printf("3 - Divertidamente 2\n");
    printf("4 - Armadilha\n");
    printf("0 - Voltar ao menu\n");
}

// printa valor dos ingressos
void valoresIngressos() {
    printf("\nPreço do ingresso: R$ %.2f\n", PRECO);
    printf("Meia-entrada disponível para menores de 10 anos e maiores de 65 anos.\n");
}

// compra ingreço e bloco pra calcular meia entrada
void comprarIngressos() {
    int filme, quantidade, idade;
    float total = 0;

    filmesDisponiveis();
    printf("Escolha o filme (0 para voltar): ");
    scanf("%d", &filme);

    if(filme == 0) return;

    printf("Quantidade de ingressos: ");
    scanf("%d", &quantidade);

    float precos[quantidade]; // Array para armazenar os preços

    for(int i = 0; i < quantidade; i++) {
        printf("Idade do ingresso %d: ", i + 1);
        scanf("%d", &idade);

        if(idade < 10 || idade > 65) {
            precos[i] = PRECO / 2;
        } else {
            precos[i] = PRECO;
        }

        total += precos[i];
    }

    printf("\nDetalhamento da compra:\n");
    for(int i = 0; i < quantidade; i++) {
        printf("Ingresso %d: R$ %.2f\n", i + 1, precos[i]);
    }
    printf("Total a pagar: R$ %.2f\n", total);
    
    printf("Compra confirmada! Aproveite o filme.\n");

    novaCompra();
}

void novaCompra() {
    int opcao;
    printf("\nDeseja fazer uma nova compra ou sair?\n");
    printf("1 - Nova compra\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if(opcao == 1) {
        comprarIngressos();
    } else {
        printf("Saindo...\n");
    }
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    fflush(stdin); // Limpa o buffer de entrada
    getchar();     // Espera o usuário pressionar Enter
    getchar();     
}
