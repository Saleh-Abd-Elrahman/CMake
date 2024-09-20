#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>  
#include <random>  
#include <algorithm> 

using namespace std;

namespace homework_utils{
    struct Node {
        string value;
        Node* next;
        Node* prev;

        Node(const string& val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* createNode(const string& value) {
        return new Node(value);
    }

    Node* insert(Node* node, Node* new_node) {
        if (new_node == nullptr) {
            return nullptr;
        }

        if (node == nullptr) {
            // Insert at the beginning
            new_node->next = nullptr;
            new_node->prev = nullptr;
            return new_node;
        }

        new_node->next = node;
        new_node->prev = node->prev;

        if (node->prev != nullptr) {
            node->prev->next = new_node;
        }
        node->prev = new_node;

        return new_node;
    }

    Node* erase(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* next_node = node->next;

        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }

        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }

        delete node;
        return next_node;
    }
    
    Node* add(Node* p, Node* n) {
        if (p == nullptr || n == nullptr) {
            return nullptr;
        }

        n->next = p->next;
        n->prev = p;

        if (p->next != nullptr) {
            p->next->prev = n;
        }
        p->next = n;

        return n;
    }


}