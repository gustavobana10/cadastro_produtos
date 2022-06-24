/*
    Considere a estrutura de um produto (registro) de uma loja contendo as seguintes informações:
    código, nome, preço e estoque. Faça um programa que leia e armazene os dados de 50 produtos. Após a leitura dos produtos o programa deve ler um código qualquer e exibir o nome, preço e estoque da respectiva mercadoria (caso o código não for cadastrado o programa deverá exibir a mensagem “Produto inexistente”). O programa encerra quando o usuário informar o código zero. OBS: utilizar constantes e vetores.
*/

#include <stdio.h>
#define TAM 3

typedef struct registro
{
    int codigo;
    char nome[20];
    float preco;
    int estoque;
} registro_t;

void ler_produto(registro_t vet[])
{
    int i;

    for (i = 0; i < TAM; i++)
    {
        printf("\nPRODUTO %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &vet[i].codigo);

        while (getchar() != '\n')
            ;
        printf("Nome: ");
        fgets(vet[i].nome, 20, stdin);

        printf("Preco: R$");
        scanf("%f", &vet[i].preco);

        printf("Estoque: ");
        scanf("%d", &vet[i].estoque);
    }
}

void verificar(registro_t *vet)
{
    int i;
    int aux;
    int cont = 0;

    do
    {
        printf("digite o codigo do produto: ");
        scanf("%d", &aux);

        for (i = 0, cont = 0; i < TAM, aux != 0; i++)
        {
            if (aux == vet[i].codigo)
            {
                printf("Nome: %s\n", vet[i].nome);
                printf("Preco: R$%2.f\n", vet[i].preco);
                printf("Estoque: %d\n", vet[i].estoque);
            }
            else if (aux != vet[i].codigo)
            {
                cont++;
            }
        }

        if (cont == TAM)
        {
            printf("\nProduto inexistente\n");
        }

    } while (aux != 0);
}

int main()
{
    registro_t vet[TAM];

    ler_produto(vet);
    verificar(vet);

    return 0;
}