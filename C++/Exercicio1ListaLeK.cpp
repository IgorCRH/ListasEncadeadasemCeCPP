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

void moveMaxToK(Node** L, Node** K) {
    if (*L == nullptr) {
        return;
    }

    Node* maxNode = *L;
    Node* prevMax = nullptr;
    Node* prev = *L;
    Node* current = (*L)->next;

    while (current != nullptr) {
        if (current->data > maxNode->data) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->next;
    }

    if (prevMax != nullptr) {
        prevMax->next = maxNode->next;
    } else {
        *L = maxNode->next;
    }

    maxNode->next = *K;
    *K = maxNode;
}

void createOrderedLinkedList(Node** L, Node** K) {
    while (*L != nullptr) {
        moveMaxToK(L, K);
    }
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
    Node* L = nullptr;
    Node* K = nullptr;

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

    std::cout << "Lista L (desordenada): ";
    printList(L);

    createOrderedLinkedList(&L, &K);

    std::cout << "Lista K (ordenada): ";
    printList(K);

    freeList(K);

    return 0;
}
