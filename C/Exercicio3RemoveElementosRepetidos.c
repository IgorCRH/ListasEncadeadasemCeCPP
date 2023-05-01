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

void printList(Node* list) { // Variável local current que aponta para o nó inicial da lista,
    Node* current = list; // Percorre a lista
    while (current != NULL) { //  Inicia um loop que continua enquanto o ponteiro current não apontar para NULL, indicando que alcançamos o final da lista.
        printf("%d ", current->data); // Imprime os valores do campo data dos nós atuais da lista
        current = current->next; // Atualiza o ponteiro current para apontar para o próximo nó na lista, avançando para o próximo elemento.
    }
    printf("\n");
}

void removerepeatedElements(Node** list) {
Node* current = *list; // Ponteiros current (atual) e prev (anterior) serão usados para comparação por toda a lista
Node* prev = NULL;

while (current != NULL) { // Enquanto não chega ao final da lista
Node* runner = *list; // Percorre a lista comparando os nós anteriores a current (atual)
while (runner != current) { //  Inicia um loop que compara a posição na memória e continua enquanto runner não alcançar current, percorrendo os nós anteriores a current.
if (runner->data == current->data) { // Elemento duplicado encontrado
Node* duplicate = current; // O duplicado recebe o current, que é o que precisará ser removido
prev->next = current->next; // Atualiza o ponteiro do prev para saltar o duplicado e ir para o próximo
current = current->next; // Atualiza current para apontar para o próximo nó após o nó duplicado, avançando na lista.
free(duplicate); // Libera a memória do nó ou elemento duplicado.
break;
}
runner = runner->next; // Atualiza runner para apontar para o próximo nó anterior a current, para seguir avançando na lista de nós anteriores.
}

if (runner == current) { // Verifica se runner alcançou current, o que indica que nenhum nó anterior a current é uma duplicata ou não há mais nós duplicados.
prev = current; // Atualiza prev para apontar para current, pois current se tornará o próximo nó a ser verificado
current = current->next; //  Atualiza current para apontar para o próximo nó na lista
}
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
        removerepeatedElements(&L);
        printList(L);
}
