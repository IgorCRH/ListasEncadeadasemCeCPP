#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insertNode1(Node** list1, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *list1;
    *list1 = newNode;
}

void insertNode2(Node** list2, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *list2;
    *list2 = newNode;
}

void concatenateLists(Node** list1, Node** list2) {
    if (*list1 == nullptr) {
        *list1 = *list2;
    } else {
        Node* current = *list1;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = *list2;
    }
    *list2 = nullptr;
}

void printList(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void freeList(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    int numL1, numL2;
    std::cout << "Digite os numeros para inserir na lista L1 (digite -1 para encerrar):\n";
    while (true) {
        std::cout << "Digite um numero: ";
        std::cin >> numL1;
        if (numL1 == -1) {
            break;
        }
        insertNode1(&L1, numL1);
    }

    std::cout << "Digite os numeros para inserir na lista L2 (digite -1 para encerrar):\n";
    while (true) {
        std::cout << "Digite um numero: ";
        std::cin >> numL2;
        if (numL2 == -1) {
            break;
        }
        insertNode2(&L2, numL2);
    }

    concatenateLists(&L1, &L2);
    printList(L1);
    freeList(L2);

    return 0;
}
