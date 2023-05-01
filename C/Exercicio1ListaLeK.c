/**
Essas linhas incluem as bibliotecas necess�rias e definem uma estrutura de dados chamada Node para representar um n�
da lista encadeada. A estrutura cont�m um campo data para armazenar o valor do n� e um ponteiro next
que aponta para o pr�ximo n� na lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
Insere um novo n� com o valor data no in�cio da lista list. Ela alocar� mem�ria para o novo n�, atribuir� o valor data
ao campo data do n� e atualizar� os ponteiros next para refletir a nova ordem dos n�s na lista.
*/
void insertNode(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

/**

*/
void moveMaxToK(Node** L, Node** K) {
    if (*L == NULL) {
        return;
    }

    Node* maxNode = *L; // Ponteiro para L para procurar o m�ximo
    Node* prevMax = NULL;
    Node* prev = *L; // Ponteiro para L, acompanha o n� anterior ao n� atual durante a itera��o pela lista
    Node* current = (*L)->next; // Aponta para o proximo elemento da lista

    while (current != NULL) {
        if (current->data > maxNode->data) { // Aponta curent e MaxNode para o campo data da struct node e compara
            maxNode = current; // Ent�o o current ser� o m�ximo do n�
            prevMax = prev; // O maximo anterior volta a ser o elemento anterior antes do maximo, quando o n� m�ximo for removido da lista.
        }
        prev = current; // E o elemento anterior � atualizado para ser igual ao current (atual) da lista
        current = current->next; // Current � atualizado aponta para o proximo elemento da lista
    }

    if (prevMax != NULL) {
        prevMax->next = maxNode->next;
    } else {
        *L = maxNode->next;
    }

    maxNode->next = *K; // Move o valor m�ximo da lista para K, apontando para o n� inicial dela
    *K = maxNode; // atualiza o ponteiro para K com o m�ximo encontrado
}

void createOrderedLinkedList(Node** L, Node** K) {
    while (*L != NULL) {
        moveMaxToK(L, K);
    }
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

int main() {
    Node* L = NULL;  // Lista L (desordenada)
    Node* K = NULL;  // Lista K (ordenada)

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

    printf("Lista L (desordenada): ");
    printList(L);

    createOrderedLinkedList(&L, &K);

    printf("Lista K (ordenada): ");
    printList(K);

    freeList(K);  // Liberar mem�ria alocada pela lista K

    return 0;
}
