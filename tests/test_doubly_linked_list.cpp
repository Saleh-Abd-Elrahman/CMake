

#include <gtest/gtest.h>
#include "../src/doubly_linked_list.h"  // Include the header where your function is declared
using namespace homework_utils;


TEST(DoublyLinkedListTest, InsertNodes) {
    Node* node = createNode("Apple");
    node = insert(node, createNode("Banana"));
    node = insert(node, createNode("Cherry"));

    Node* current = node;
    ASSERT_EQ(current->value, "Cherry");
    ASSERT_EQ(current->next->value, "Banana");
    ASSERT_EQ(current->prev, nullptr);

    current = current->next;
    ASSERT_EQ(current->value, "Banana");
    ASSERT_EQ(current->next->value, "Apple");
    ASSERT_EQ(current->prev->value, "Cherry");

    current = current->next;
    ASSERT_EQ(current->value, "Apple");
    ASSERT_EQ(current->prev->value, "Banana");
    ASSERT_EQ(current->next, nullptr);

    // Free all nodes
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

TEST(DoublyLinkedListTest, EraseNodes) {
    Node* node = createNode("Apple");
    node = insert(node, createNode("Banana"));
    node = insert(node, createNode("Cherry"));

    // Erase the middle node (Banana)
    Node* current = node->next; // Banana
    current = erase(current);

    ASSERT_EQ(node->value, "Cherry");
    ASSERT_EQ(node->next->value, "Apple");
    ASSERT_EQ(node->next->prev, node);

    // Erase the first node (Cherry)
    current = node;
    current = erase(current);

    ASSERT_EQ(current->value, "Apple");
    ASSERT_EQ(current->prev, nullptr);

    // Erase the last remaining node (Apple)
    current = erase(current);
    ASSERT_EQ(current, nullptr);

    // Free all nodes
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

TEST(DoublyLinkedListTest, AddNodes) {
    Node* head = createNode("Apple");
    Node* node = head;

    node = add(node, createNode("Banana"));
    node = add(node, createNode("Cherry"));

    // Validate the list starting from the head (Apple)
    Node* current = head;
    ASSERT_EQ(current->value, "Apple");
    ASSERT_EQ(current->next->value, "Banana");
    ASSERT_EQ(current->prev, nullptr);

    current = current->next;
    ASSERT_EQ(current->value, "Banana");
    ASSERT_EQ(current->next->value, "Cherry");
    ASSERT_EQ(current->prev->value, "Apple");

    current = current->next;
    ASSERT_EQ(current->value, "Cherry");
    ASSERT_EQ(current->prev->value, "Banana");
    ASSERT_EQ(current->next, nullptr);

    // Free all nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
