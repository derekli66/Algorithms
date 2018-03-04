//
//  main.cpp
//  BST-Cpp
//
//  Created by LEE CHIEN-MING on 30/01/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <functional>

struct Node {
    Node *parentNode{nullptr};
    Node *leftNode{nullptr};
    Node *rightNode{nullptr};
    int key{0};
};

class BST {
    virtual bool add(int key) = 0;
    virtual bool remove(int key) = 0;
    virtual Node* search(int key) = 0;
    virtual Node* successor(int key) = 0;
    virtual Node* predecessor(int key) = 0;
    virtual int max() = 0;
    virtual int min() = 0;
    virtual void inorderTraverse(std::function<void(int)> traversal) = 0;
    virtual void preorderTraverse(std::function<void(int)> traversal) = 0;
    virtual void postorderTraverse(std::function<void(int)> traversal) = 0;
};

class BSTree: BST {
public:
    BSTree() {
        
    }
    
    ~BSTree() {
        
    }
    
    virtual Node* search(int key) {
        Node* target = m_root;
        
        while (target != nullptr) {
            if (target->key < key) {
                target = target->rightNode;
                continue;
            }
            else if (target->key > key) {
                target = target-> leftNode;
                continue;
            }
            
            break;
        }
        
        return target;
    }
    
    virtual bool add(int key) {
        Node **link = &m_root;
        Node *current = nullptr;
        
        while (*link != nullptr) {
            current = *link;
            if (current->key < key) {
                link = &current->rightNode;
            }
            else if (current->key > key) {
                link = &current->leftNode;
            }
            else {
                // if the key is equal to the existing node's key
                return false;
            }
        }
        
        Node *newNode = new Node;
        newNode->parentNode = current;
        newNode->key = key;
        *link = newNode;
        return true;
    }
    
    virtual bool remove(int key) {
        Node *target = search(key);
        if (target == nullptr) return false;
        
        if (target->leftNode == nullptr && target->rightNode == nullptr) {
            *(getParentsChildLink(target)) = nullptr;
        }
        else if (target->leftNode == nullptr && target->rightNode != nullptr) {
            // Get predecessor of target->rightNode
            // Also check if next node is equal to target->rightNode
            Node *preNode = predecessor(target->rightNode->key);
            
            if (target->rightNode == preNode) {
                // Update parent's property
                *(getParentsChildLink(target)) = preNode;
                // Update candidate's parent property
                preNode->parentNode = target->parentNode;
            }
            else {
                // Update parent's property
                *(getParentsChildLink(preNode)) = nullptr;
                *(getParentsChildLink(target)) = preNode;
                
                // Update candidate's parent property
                preNode->parentNode = target->parentNode;
                preNode->leftNode = target->leftNode;
                preNode->rightNode = target->rightNode;
            }
            
        }
        else {
            // Get successor of target->leftNode
            // Also check if next node is equal to target->leftNode
            Node *succNode = successor(target->leftNode->key);
            
            if (key == 12) {
                std::cout << "Check successof of target's left child: " << succNode->key <<  std::endl;
            }
            
            if (target->leftNode == succNode) {
                succNode->parentNode = target->parentNode;
                *(getParentsChildLink(target)) = succNode;
            }
            else {
                // Update parent's property
                *(getParentsChildLink(succNode)) = nullptr;
                *(getParentsChildLink(target)) = succNode;
                
                // Update candidate's
                succNode->parentNode = target->parentNode;
                succNode->leftNode = target->leftNode;
                succNode->rightNode = target->rightNode;
            }
        }
        
        
        delete target;

        return true;
    }
    
    virtual int max() {
        Node *target = maxOf(m_root);
        int result = 0;
        if (target != nullptr) { result = target->key; }
        
        return result;
    }
    
    virtual int min() {
        Node *target = minOf(m_root);
        int result = 0;
        if (target != nullptr) { result = target->key; }
        
        return result;
    }
    
    virtual Node* predecessor(int key) {
        // Find target node
        Node *target = search(key);
        if (target == nullptr) return nullptr;
        
        target = maxOf(target->leftNode);
        
        return target;
    }
    
    virtual Node* successor(int key) {
        // Find target node
        Node *target = search(key);
        if (target == nullptr) return nullptr;

        target = minOf(target->rightNode);
        
        return target;
    }
    
    virtual void inorderTraverse(std::function<void(int)> traversal) {
        OnInorderTraverse(m_root, traversal);
    }
    
    virtual void preorderTraverse(std::function<void(int)> traversal) {
        OnPreorderTraverse(m_root, traversal);
    }
    
    virtual void postorderTraverse(std::function<void(int)> traversal) {
        OnPostorderTraverse(m_root, traversal);
    }
    
private:
    Node *m_root{nullptr};
    
    void OnInorderTraverse(Node *node, std::function<void(int)> traversal) {
        if (node == nullptr) return;
        
        this->OnInorderTraverse(node->leftNode, traversal);
        traversal(node->key);
        this->OnInorderTraverse(node->rightNode, traversal);
    }
    
    void OnPreorderTraverse(Node *node, std::function<void(int)> traversal) {
        if (node == nullptr) return;
        
        traversal(node->key);
        this->OnPreorderTraverse(node->leftNode, traversal);
        this->OnPreorderTraverse(node->rightNode, traversal);
    }
    
    void OnPostorderTraverse(Node *node, std::function<void(int)> traversal) {
        if (node == nullptr) return;
        
        this->OnPostorderTraverse(node->leftNode, traversal);
        this->OnPostorderTraverse(node->rightNode, traversal);
        traversal(node->key);
    }
    
    Node* maxOf(Node* root) {
        Node *last = root;
        while (last->rightNode != nullptr) {
            last = last->rightNode;
        }
        
        return last;
    }
    
    Node *minOf(Node* root) {
        Node *last = root;
        while (last->leftNode != nullptr) {
            last = last->leftNode;
        }
        
        return last;
    }
    
    // This will return the pointer where parent's left or right child is identical to input node
    Node **getParentsChildLink(Node *node) {
        if (node->parentNode == nullptr) return nullptr;
        
        if (node->parentNode->leftNode == node) {
            return &(node->parentNode->leftNode);
        }
        
        return &(node->parentNode->rightNode);
    }
};

const int inputValues[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

int main(int argc, const char * argv[]) {
    // insert code here...
    int count = 0;
    auto lambda = [&](int key){
        count++;
        std::cout << key << " ";
    };
    
    BSTree bst;
    
    for (const int &vl : inputValues) {
        bst.add(vl);
    }
    
    bst.inorderTraverse(lambda);
    std::cout << std::endl;
    std::cout << "1st Process count: " << count << std::endl;
    
    bst.remove(12);
    
    bst.inorderTraverse(lambda);
    std::cout << std::endl;
    std::cout << "2nd Process count: " << count << std::endl;
    
    std::cout << std::endl << std::flush;
    std::cout << "End of program" << std::endl;
    return 0;
}
