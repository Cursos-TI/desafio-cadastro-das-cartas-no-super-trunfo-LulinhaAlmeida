#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado;                
    char codigo[4];             
    char nome_cidade[50];        
    int populacao;              
    float area;                 
    float PIB;                  
    int pontos_turisticos;
} CartaSuperTrunfo;

// Função para ler uma carta do usuário
void lerCarta(CartaSuperTrunfo *carta, int numero_carta) {
    printf("\nDigite os dados da Carta %d:\n", numero_carta);
    
    // Estado (A-H)
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    while (carta->estado < 'A' || carta->estado > 'H') {
        printf("Estado inválido! Digite uma letra de A a H: ");
        scanf(" %c", &carta->estado);
    }
    
    // Código da Carta (Estado + 01-04)
    printf("Código da Carta (%c01-%c04): ", carta->estado, carta->estado);
    scanf("%s", carta->codigo);
    while (strlen(carta->codigo) != 3 || 
           carta->codigo[0] != carta->estado || 
           carta->codigo[1] < '0' || carta->codigo[1] > '0' || 
           carta->codigo[2] < '1' || carta->codigo[2] > '4') {
        printf("Código inválido! Digite no formato %c01-%c04: ", carta->estado, carta->estado);
        scanf("%s", carta->codigo);
    }
    
    // Nome da Cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome_cidade);  // Lê até encontrar uma nova linha
    
    // População
    printf("População (Milhões): ");
    scanf("%f", &carta->populacao);
    
    // Área
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    
    // PIB
    printf("PIB: ");
    scanf("%f", &carta->PIB);
    
    // Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir uma carta
void exibirCarta(CartaSuperTrunfo carta, int numero_carta) {
    printf("\nCarta %d:\n", numero_carta);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %f\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    CartaSuperTrunfo carta1, carta2;
    
    printf("=== SUPER TRUNFO - CADASTRO DE CARTAS ===\n");
    
    // Ler as duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    // Exibir as cartas cadastradas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    return 0;
}