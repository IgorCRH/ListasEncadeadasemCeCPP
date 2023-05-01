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
Node* current = *list; // Ponteiros current (atual) será usado para comparação por toda a lista

while (current != nullptr) { // Enquanto não chega ao final da lista
if (current -> data % 2 == 0){ // Se o valor do elemento for par, então:
current -> data += 1; // Troca para ímpar
}
current = current->next; // Aponta para o próximo nó ou elemento a ser comparado
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
