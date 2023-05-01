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
*list1 = *list2; // Conecta o primeiro n� da lista 1 com o primeiro da lista 2
} else {
Node* current = *list1;
while (current -> next != NULL){ //  Inicia um loop que continua enquanto o ponteiro current n�o apontar para NULL, indicando que alcan�amos o final da lista.
current = current->next; // Continua apontando para o pr�ximo da lista 1
}
current->next = *list2; // Ajusta o ponteiro next do �ltimo n� da primeira lista para apontar para o primeiro n� da segunda lista
}
*list2 = NULL; // Indica que a segunda lista n�o est� mais em uso.
}

void printList(Node* list) { // Vari�vel local current que aponta para o n� inicial da lista,
    Node* current = list; // Percorre a lista
    while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current n�o apontar para NULL, indicando que alcan�amos o final da lista.
        printf("%d ", current->data); // Imprime os valores do campo data dos n�s atuais da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o pr�ximo n� na lista, avan�ando para o pr�ximo elemento.
    }
    printf("\n");
}

void freeList(Node* list) { // Vari�vel local current que aponta para o n� inicial da lista,
Node* current = list; // Percorre a lista
while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current n�o apontar para NULL, indicando que alcan�amos o final da lista.
        Node* temp = current; // Vari�vel local temp armazena o n� atual da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o pr�ximo n� na lista, avan�ando para o pr�ximo elemento antes de liberar a mem�ria do n� atual.
        free(temp); // Libera a mem�ria alocada para o n� atual (temp) e o remove da lista, utilizando a fun��o free da biblioteca padr�o.
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
