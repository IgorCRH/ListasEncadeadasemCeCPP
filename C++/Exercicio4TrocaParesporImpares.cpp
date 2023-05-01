#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** list, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

void printList(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void changeEvenForOdds(Node** list) {
Node* current = *list; // Ponteiros current (atual) ser� usado para compara��o por toda a lista

while (current != nullptr) { // Enquanto n�o chega ao final da lista
if (current -> data % 2 == 0){ // Se o valor do elemento for par, ent�o:
current -> data += 1; // Troca para �mpar
}
current = current->next; // Aponta para o pr�ximo n� ou elemento a ser comparado
}
}


main (){
Node *L = nullptr;

   int num;
    std::cout << "Digite os numeros para inserir na lista (digite -1 para encerrar):\n";
    while (true) {
        std::cout << "Digite um numero: ";
        std::cin >> num;
        if (num == -1) {
            break;
        }
        insertNode(&L, num);
    }

        printList(L);
        changeEvenForOdds(&L);
        std::cout <<"Lista apos trocar os pares pelos impares:";
        printList(L);
}
