#include <stdio.h>
#include <string.h>
// Definindo o número máximo de territórios
#define MAX_TERRITORIOS 5

// Definindo a estrutura do tipo Território
struct territorio {
    char nome[30];
    char cor[10];
    int quantidade;
};

int main() {

// Criando uma array Territorios de 5 espaços
struct territorio territorios[MAX_TERRITORIOS];
int totalterritorios = 0;

// Início do jogo
printf("---Bem-vindo ao jogo de War!---\n");
printf("Vamos inserir os dados de 5 territórios\n");
printf("\n");

// Loop para inserir os dados dos territórios na array
for(int i = 0; i < MAX_TERRITORIOS; i++) {
    printf("----Território %d----\n", i+1);
    printf("Nome: ");
    scanf ("%s", territorios[totalterritorios].nome);
    printf("Cor: ");
    scanf ("%s", territorios[totalterritorios].cor);
    printf("Quantidade de tropas: ");
    scanf ("%d", &territorios[totalterritorios].quantidade);
    printf("\n");
    totalterritorios++;
}

// Exibindo o mapa do jogo
printf("-------------------------\n");
printf("MAPA DO MUNDO\n");
printf("-------------------------\n");

// Loop para exibir os dados da array de territórios
for(int i = 0; i < MAX_TERRITORIOS; i++) {
    printf("TERRITORIO %d \n Nome: %s \n Dominado por: Exército %s \n Tropas: %d\n", 
           i+1 , 
           territorios[i].nome, 
           territorios[i].cor, 
           territorios[i].quantidade);
    printf("-------------------------\n");
}

return 0;

}
