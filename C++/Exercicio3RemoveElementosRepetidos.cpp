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

void removeRepeatedElements(Node** list) {
    Node* current = *list;
    Node* prev = nullptr;

    while (current != nullptr) {
        Node* runner = *list;
        while (runner != current) {
            if (runner->data == current->data) {
                Node* duplicate = current;
                prev->next = current->next;
                current = current->next;
                delete duplicate;
                break;
            }
            runner = runner->next;
        }

        if (runner == current) {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* L = nullptr;

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
    removeRepeatedElements(&L);
    printList(L);

    return 0;
}
