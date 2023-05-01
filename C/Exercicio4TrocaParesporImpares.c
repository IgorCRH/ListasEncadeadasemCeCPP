#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

void printList(Node* list) { // Vari�vel local current que aponta para o n� inicial da lista,
    Node* current = list; // Percorre a lista
    while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current n�o apontar para NULL, indicando que alcan�amos o final da lista.
        printf("%d ", current->data); // Imprime os valores do campo data dos n�s atuais da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o pr�ximo n� na lista, avan�ando para o pr�ximo elemento.
    }
    printf("\n");
}

void changeEvenForOdds(Node** list) {
Node* current = *list; // Ponteiros current (atual) ser� usado para compara��o por toda a lista

while (current != NULL) { // Enquanto n�o chega ao final da lista
if (current -> data % 2 == 0){ // Se o valor do elemento for par, ent�o:
current -> data += 1; // Troca para �mpar
}
current = current->next; // Aponta para o pr�ximo n� ou elemento a ser comparado
}
}


main (){
Node *L = NULL;

   int num;
    printf("Digite os numeros para inserir na lista (digite -1 para encerrar):\n");
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        insertNode(&L, num);
    }

        printList(L);
        changeEvenForOdds(&L);
        printf("Lista apos trocar os pares pelos impares:");
        printList(L);
}
