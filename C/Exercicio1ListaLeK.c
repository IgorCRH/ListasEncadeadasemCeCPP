/**
Essas linhas incluem as bibliotecas necessárias e definem uma estrutura de dados chamada Node para representar um nó
da lista encadeada. A estrutura contém um campo data para armazenar o valor do nó e um ponteiro next
que aponta para o próximo nó na lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
Insere um novo nó com o valor data no início da lista list. Ela alocará memória para o novo nó, atribuirá o valor data
ao campo data do nó e atualizará os ponteiros next para refletir a nova ordem dos nós na lista.
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

    Node* maxNode = *L; // Ponteiro para L para procurar o máximo
    Node* prevMax = NULL;
    Node* prev = *L; // Ponteiro para L, acompanha o nó anterior ao nó atual durante a iteração pela lista
    Node* current = (*L)->next; // Aponta para o proximo elemento da lista

    while (current != NULL) {
        if (current->data > maxNode->data) { // Aponta curent e MaxNode para o campo data da struct node e compara
            maxNode = current; // Então o current será o máximo do nó
            prevMax = prev; // O maximo anterior volta a ser o elemento anterior antes do maximo, quando o nó máximo for removido da lista.
        }
        prev = current; // E o elemento anterior é atualizado para ser igual ao current (atual) da lista
        current = current->next; // Current é atualizado aponta para o proximo elemento da lista
    }

    if (prevMax != NULL) {
        prevMax->next = maxNode->next;
    } else {
        *L = maxNode->next;
    }

    maxNode->next = *K; // Move o valor máximo da lista para K, apontando para o nó inicial dela
    *K = maxNode; // atualiza o ponteiro para K com o máximo encontrado
}

void createOrderedLinkedList(Node** L, Node** K) {
    while (*L != NULL) {
        moveMaxToK(L, K);
    }
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

    freeList(K);  // Liberar memória alocada pela lista K

    return 0;
}
