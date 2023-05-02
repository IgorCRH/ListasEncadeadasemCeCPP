#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insere Lista
void insertNode(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

// Imprime Lista
void printList(Node* list) { // Variável local current que aponta para o nó inicial da lista,
    Node* current = list; // Percorre a lista
    while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current não apontar para NULL, indicando que alcançamos o final da lista.
        printf("%d ", current->data); // Imprime os valores do campo data dos nós atuais da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o próximo nó na lista, avançando para o próximo elemento.
    }
    printf("\n");
}

// Remove Lista
void removeList(Node** list) {
Node* current = *list;
Node* next;

while (current != NULL) { // Enquanto não chega ao final da lista
next = current->next; // Armazena o próximo elemento em next
free(current); // Libera a memória alocada pro current
current = next; // Current aponta para next que possui o ponteiro para o próximo elemento
}
*list = NULL; // Define o ponteiro da lista como NULL para indicar que a lista está vazia
}

// Remove Nó Inicial e Atualiza para outro nó
Node* removeInitialandChangeNode(Node** list){
Node* newinitial = (*list)->next;

free(*list);
return newinitial;
}

// Remove Nó Final e Atualiza para outro nó
Node* removeFinalandChangeNode (Node** list){
Node* current = (*list)->next;
Node* penultimate = *list;
if (current == NULL){ // Se apenas tivermos um nó na lista, chegamos ao final
free(*list); // Se removermos este nó, excluiremos a lista
return NULL; // Retorna que a lista não existe
}
while (current->next->next != NULL) { // Percorre até o penúltimo elemento da lista
current = current->next; // Ponteiro current agora aponta para o último elemento a partir do penúltimo
}
free(current->next); // Liberamos a memória do current->next para removê-lo efetivamente
current->next = NULL; // Retorna nulo para sinalizar que o atual current->next, o último, não existe mais
return *list; // Retorna a lista atualizada
}

int main() {
    Node* L1 = NULL;
    Node* L2 = NULL;
    int num;
    int opcao;

    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1. Inserir na Lista 1\n");
        printf("2. Inserir na Lista 2\n");
        printf("3. Remover nó inicial da Lista 1 e atualizar para outro nó\n");
        printf("4. Remover nó final da Lista 1 e atualizar para outro nó\n");
        printf("5. Remover nó inicial da Lista 2 e atualizar para outro nó\n");
        printf("6. Remover nó final da Lista 2 e atualizar para outro nó\n");
        printf("7. Remover lista 1\n");
        printf("8. Remover lista 2\n");
        printf("9. Encerrar o programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite os numeros para inserir na Lista 1 (digite -1 para encerrar):\n");
                while (1) {
                    printf("Digite um numero: ");
                    scanf("%d", &num);
                    if (num == -1) {
                        break;
                    }
                    insertNode(&L1, num);
                }
                printf("Lista 1 atual: ");
                printList(L1);
                break;
            case 2:
                printf("Digite os numeros para inserir na Lista 2 (digite -1 para encerrar):\n");
                while (1) {
                    printf("Digite um numero: ");
                    scanf("%d", &num);
                    if (num == -1) {
                        break;
                    }
                    insertNode(&L2, num);
                }
                printf("Lista 2 atual: ");
                printList(L2);
                break;
            case 3:
                L1 = removeInitialandChangeNode(&L1);
                printf("Lista 1 atualizada: ");
                printList(L1);
                break;
            case 4:
                L1 = removeFinalandChangeNode(&L1);
                printf("Lista 1 atualizada: ");
                printList(L1);
                break;
            case 5:
                L2 = removeInitialandChangeNode(&L2);
                printf("Lista 2 atualizada: ");
                printList(L2);
                break;
            case 6:
                L2 = removeFinalandChangeNode(&L2);
                printf("Lista 2 atualizada: ");
                printList(L2);
                break;
            case 7:
                removeList(&L1);
                printf("Lista 1 removida!\n");
                break;
            case 8:
                removeList(&L2);
                printf("Lista 2 removida!\n");
                break;
            case 9:
                printf("Encerrando o programa...\n");
                removeList(&L1);
                removeList(&L2);
                return 0;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}
