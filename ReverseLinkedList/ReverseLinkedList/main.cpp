//
//  main.cpp
//  ReverseLinkedList
//
//  Created by LEE CHIEN-MING on 12/05/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>

struct Node
{
    int key{0};
    Node *next{nullptr};
    
    Node(int k):key{k}
    {
    }
    
    ~Node()
    {
        std::cout << "Node key: " << key << " was eliminated" << std::endl;
    }
};

Node* reverseLinkedList(Node *root)
{
    Node *head = nullptr;
    Node *next = root;
    
    while (next != nullptr) {
        Node *temp = next->next;
        next->next = head;
        head = next;
        next = temp;
    }
    
    return head;
}

void print(Node *root)
{
    int count = 1;
    while (root != nullptr) {
        std::cout << "Node " << count << " : " << root->key << std::endl;
        root = root->next;
        count++;
    }
}

void freeLinkedList(Node *root)
{
    int count = 1;
    while (root != nullptr) {
        Node *next = root->next;
        delete root;
        root = next;
        count++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    
    print(node1);
    
    std::cout << "Then, reverse linked list." << std::endl;
    
    Node *newRoot = reverseLinkedList(node1);
    
    print(newRoot);
    
    freeLinkedList(newRoot);
    
    std::cout << "End of Program" << std::endl;
    
    return 0;
}
