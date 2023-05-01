#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode1(Node** list1, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list1;
    *list1 = newNode;
}

void insertNode2(Node** list2, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list2;
    *list2 = newNode;
}

void concatenateLists(Node** list1, Node** list2){
if (*list1 == NULL){
*list1 = *list2; // Conecta o primeiro nó da lista 1 com o primeiro da lista 2
} else {
Node* current = *list1;
while (current -> next != NULL){ //  Inicia um loop que continua enquanto o ponteiro current não apontar para NULL, indicando que alcançamos o final da lista.
current = current->next; // Continua apontando para o próximo da lista 1
}
current->next = *list2; // Ajusta o ponteiro next do último nó da primeira lista para apontar para o primeiro nó da segunda lista
}
*list2 = NULL; // Indica que a segunda lista não está mais em uso.
}

void printList(Node* list) { // Variável local current que aponta para o nó inicial da lista,
    Node* current = list; // Percorre a lista
    while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current não apontar para NULL, indicando que alcançamos o final da lista.
        printf("%d ", current->data); // Imprime os valores do campo data dos nós atuais da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o próximo nó na lista, avançando para o próximo elemento.
    }
    printf("\n");
}

void freeList(Node* list) { // Variável local current que aponta para o nó inicial da lista,
Node* current = list; // Percorre a lista
while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current não apontar para NULL, indicando que alcançamos o final da lista.
        Node* temp = current; // Variável local temp armazena o nó atual da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o próximo nó na lista, avançando para o próximo elemento antes de liberar a memória do nó atual.
        free(temp); // Libera a memória alocada para o nó atual (temp) e o remove da lista, utilizando a função free da biblioteca padrão.
    }
}

main (){
Node *L1 = NULL;
Node *L2 = NULL;

   int numL1, numL2;
    printf("Digite os numeros para inserir na lista L1 (digite -1 para encerrar):\n");
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &numL1);
        if (numL1 == -1) {
            break;
        }
        insertNode1(&L1, numL1);
    }

        printf("Digite os numeros para inserir na lista L2 (digite -1 para encerrar):\n");
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &numL2);
        if (numL2 == -1) {
            break;
        }
        insertNode2(&L2, numL2);
    }

    concatenateLists(&L1,&L2);
    printList(L1);
    freeList(L2);
}
