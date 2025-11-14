#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definindo o número máximo de territórios
#define MAX_TERRITORIOS 5

// Definindo a estrutura do tipo Território
struct territorio {
    char nome[30];
    char cor[10];
    int quantidade;
};

// Função para simular o lançamento de um dado de 6 lados para atacante e defensor
int dadoatacante(void) {
    return (rand() % 6) + 1;
}
int dadodefensor(void) {
    return (rand() % 6) + 1;
}

// Função void para realizar o ataque entre territórios
void atacar(struct territorio *territorios){
    //variavel para armazenar o número do território atacante escolhido pelo usuário
    int atacante;
    printf("Digite o número do território atacante:\n ");
    for ( int i = 0; i < MAX_TERRITORIOS; i++){
        printf("%d - %s exército %s com %d tropas\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].quantidade);
    }
    scanf("%d", &atacante);
    //variavel para armazenar o índice do território atacante na array
    int indiceatacante = atacante - 1;
    //verifica se o território atacante tem tropas suficientes para atacar
    do{ 
        if (indiceatacante < 0 || indiceatacante >= MAX_TERRITORIOS){
            printf("Número de território inválido. Escolha outro território.\n");
            scanf("%d", &atacante);
            //atualiza o índice do território atacante
            indiceatacante = atacante - 1;
        }
        else if (territorios[indiceatacante].quantidade < 2){
            printf("O território %s não tem tropas suficientes para atacar. Escolha outro território.\n", territorios[indiceatacante].nome);
            scanf("%d", &atacante);
            //atualiza o índice do território atacante
            indiceatacante = atacante - 1; 
        }
    }
    while (territorios[indiceatacante].quantidade < 2 || indiceatacante < 0 || indiceatacante >= MAX_TERRITORIOS);

    printf("O território %s vai atacar\n", territorios[indiceatacante].nome);
    //Armazena o valor do dado lançado pelo atacante
    int dado_atacante = dadoatacante();
    //variavel para armazenar o número do território defensor escolhido pelo usuário
    int defensor;
    for ( int i = 0; i < MAX_TERRITORIOS; i++){
         printf("%d - %s exército %s com %d tropas\n", i + 1, territorios[i].nome, territorios[i].cor, territorios[i].quantidade);
    }
    printf("Digite o número do território que deseja atacar:\n");
    scanf("%d", &defensor);
    //variavel para armazenar o índice do território defensor na array
    int indicedefensor = defensor - 1;
    //verifica se o território atacante não é o mesmo que o defensor
    do{
        if (indicedefensor < 0 || indicedefensor >= MAX_TERRITORIOS)
        {
            printf("Número de território inválido. Escolha outro território.\n");
            scanf("%d", &defensor);
            //atualiza o índice do território defensor
            indicedefensor = defensor - 1;
        }
        
        if (atacante == defensor){
            printf("Um território não pode atacar ele mesmo! Escolha outro território.\n");
            scanf("%d", &defensor); 
            indicedefensor = defensor - 1;
            //atualiza o índice do território defensor
        }
    }
    while (atacante == defensor || indicedefensor < 0 || indicedefensor >= MAX_TERRITORIOS);
   
    
    printf("O território %s vai defender\n", territorios[indicedefensor].nome);
    //Armazena o valor do dado lançado pelo defensor
    int dado_defensor = dadodefensor();
    printf("%s lançou o dado e tirou: %d\n", territorios[indiceatacante].nome, dado_atacante);
    printf("%s lançou o dado e tirou: %d\n", territorios[indicedefensor].nome, dado_defensor);
    //Compara os valores dos dados e atualiza as quantidades de tropas dos territórios conforme o resultado da batalha
    if (dado_atacante > dado_defensor ){
        printf("%s venceu a batalha!\n", territorios[indiceatacante].nome);
        //Reduz a quantidade de tropas do território defensor em 1
        territorios[indicedefensor].quantidade --;
        printf("O território %s agora tem %d tropas.\n", territorios[indicedefensor].nome, territorios[indicedefensor].quantidade);
        //Verifica se o território defensor ficou sem tropas
        if (territorios[indicedefensor].quantidade <= 0){
            //Conquista do território defensor pelo atacante
            printf("O território %s agora pertence ao exercito %s!\n", territorios[indicedefensor].nome, territorios[indiceatacante].cor);
            strcpy(territorios[indicedefensor].cor, territorios[indiceatacante].cor);
            //Move metade das tropas do território atacante para o território conquistado
            territorios[indicedefensor].quantidade = territorios[indiceatacante].quantidade/2;
            territorios[indiceatacante].quantidade = territorios[indiceatacante].quantidade/2;
        }
    }
    else if (dado_atacante <= dado_defensor){
        printf("%s venceu a batalha!\n", territorios[indicedefensor].nome);
        //Reduz a quantidade de tropas do território atacante em 1
        territorios[indiceatacante].quantidade --;
        printf("O território %s agora tem %d tropas.\n", territorios[indiceatacante].nome, territorios[indiceatacante].quantidade);
    }
}
    
int main() {

srand(time(NULL));

// Alocação dinâmica de memória para a array de territórios
struct territorio *territorios;
territorios=(struct territorio*) calloc(MAX_TERRITORIOS, sizeof(struct territorio));
if (territorios==NULL) {
    printf("Erro de alocação de memória\n");
    return 1;
}

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

// Loop para exibir os dados dos de territórios
for(int i = 0; i < MAX_TERRITORIOS; i++) {
    printf("TERRITORIO %d \n Nome: %s \n Dominado pelo exército %s \n Tropas: %d\n", 
           i+1 , 
           territorios[i].nome, 
           territorios[i].cor, 
           territorios[i].quantidade);
    printf("-------------------------\n");
}
  
// Início da fase de ataque
printf("\n");
printf("-------------------------\n");
printf("Agora começa a batalha!\n");
printf("-------------------------\n");

int condition;
do {
    // Chama a função atacar para realizar um ataque
    atacar(territorios);
    // Exibe o mapa atualizado após o ataque
    printf("-------------------------\n");
    printf("MAPA DO MUNDO ATUALIZADO\n");
    printf("-------------------------\n");
    for(int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("TERRITORIO %d \n Nome: %s \n Dominado pelo exército %s \n Tropas: %d\n", 
           i+1 , 
           territorios[i].nome, 
           territorios[i].cor, 
           territorios[i].quantidade);
        }
    printf("-------------------------\n");
    // Pergunta ao usuário se deseja continuar atacando ou sair do jogo
    printf("\nDeseja continuar atacando? (1-Sim / 0-Encerrar jogo): ");
    if (scanf("%d", &condition) != 1) {
        condition = 0;
        printf("Entrada inválida — encerrando.\n");
    }
} while (condition == 1);
// Liberação da memória alocada para a array de territórios
free(territorios);
printf("\nFim do jogo! Obrigado por jogar!\n");
return 0;
}
