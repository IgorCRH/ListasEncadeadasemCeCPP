#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Insere Lista
void insertNode(Node** list, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

// Imprime Lista
void printList(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Remove Lista
void removeList(Node** list) {
    Node* current = *list;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    *list = nullptr;
}

// Remove Nó Inicial e Atualiza para outro nó
Node* removeInitialandChangeNode(Node** list) {
    Node* newInitial = (*list)->next;
    delete *list;
    return newInitial;
}

// Remove Nó Final e Atualiza para outro nó
Node* removeFinalandChangeNode(Node** list) {
    Node* current = (*list)->next;
    Node* penultimate = *list;
    if (current == nullptr) {
        delete *list;
        return nullptr;
    }
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return *list;
}

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;
    int num;
    int opcao;

    while (true) {
        std::cout << "Escolha uma opcao:" << std::endl;
        std::cout << "1. Inserir na Lista 1" << std::endl;
        std::cout << "2. Inserir na Lista 2" << std::endl;
        std::cout << "3. Remover nó inicial da Lista 1 e atualizar para outro nó" << std::endl;
        std::cout << "4. Remover nó final da Lista 1 e atualizar para outro nó" << std::endl;
        std::cout << "5. Remover nó inicial da Lista 2 e atualizar para outro nó" << std::endl;
        std::cout << "6. Remover nó final da Lista 2 e atualizar para outro nó" << std::endl;
        std::cout << "7. Remover lista 1" << std::endl;
        std::cout << "8. Remover lista 2" << std::endl;
        std::cout << "9. Encerrar o programa" << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite os numeros para inserir na Lista 1 (digite -1 para encerrar):" << std::endl;
                while (true) {
                    std::cout << "Digite um numero: ";
                    std::cin >> num;
                    if (num == -1) {
                        break;
                    }
                    insertNode(&L1, num);
                }
                std::cout << "Lista 1 atual: ";
                printList(L1);
                break;
            case 2:
                std::cout << "Digite os numeros para inserir na Lista 2 (digite -1 para encerrar):";
                while (true) {
                    std::cout << "Digite um numero: ";
                    std::cin >> num;
                    if (num == -1) {
                        break;
                    }
                    insertNode(&L2, num);
                }
                std::cout << "Lista 2 atual: ";
                printList(L2);
                break;
            case 3:
                L1 = removeInitialandChangeNode(&L1);
                std::cout << "Lista 1 atualizada: ";
                printList(L1);
                break;
            case 4:
                L1 = removeFinalandChangeNode(&L1);
                std::cout << "Lista 1 atualizada: ";
                printList(L1);
                break;
            case 5:
                L2 = removeInitialandChangeNode(&L2);
                std::cout << "Lista 2 atualizada: ";
                printList(L2);
                break;
            case 6:
                L2 = removeFinalandChangeNode(&L2);
                std::cout << "Lista 2 atualizada: ";
                printList(L2);
                break;
            case 7:
                removeList(&L1);
                std::cout << "Lista 1 removida!" << std::endl;
                break;
            case 8:
                removeList(&L2);
                std::cout << "Lista 2 removida!" << std::endl;
                break;
            case 9:
                std::cout << "Encerrando o programa..." << std::endl;
                removeList(&L1);
                removeList(&L2);
                return 0;
            default:
                std::cout << "Opcao invalida!" << std::endl;
                break;
        }
    }
}
