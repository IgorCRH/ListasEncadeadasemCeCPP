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

void removerepeatedElements(Node** list) {
Node* current = *list; // Ponteiros current (atual) e prev (anterior) ser�o usados para compara��o por toda a lista
Node* prev = NULL;

while (current != NULL) { // Enquanto n�o chega ao final da lista
Node* runner = *list; // Percorre a lista comparando os n�s anteriores a current (atual)
while (runner != current) { //  Inicia um loop que compara a posi��o na mem�ria e continua enquanto runner n�o alcan�ar current, percorrendo os n�s anteriores a current.
if (runner->data == current->data) { // Elemento duplicado encontrado
Node* duplicate = current; // O duplicado recebe o current, que � o que precisar� ser removido
prev->next = current->next; // Atualiza o ponteiro do prev para saltar o duplicado e ir para o pr�ximo
current = current->next; // Atualiza current para apontar para o pr�ximo n� ap�s o n� duplicado, avan�ando na lista.
free(duplicate); // Libera a mem�ria do n� ou elemento duplicado.
break;
}
runner = runner->next; // Atualiza runner para apontar para o pr�ximo n� anterior a current, para seguir avan�ando na lista de n�s anteriores.
}

if (runner == current) { // Verifica se runner alcan�ou current, o que indica que nenhum n� anterior a current � uma duplicata ou n�o h� mais n�s duplicados.
prev = current; // Atualiza prev para apontar para current, pois current se tornar� o pr�ximo n� a ser verificado
current = current->next; //  Atualiza current para apontar para o pr�ximo n� na lista
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
