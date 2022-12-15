#include "gtest/gtest.h"

extern "C" {
    #include "singly_linked_list/singly_linked_list.h"
}

TEST(push_node, null) {
    struct Node *head = NULL;

    push_node(&head, {1, 2});

    EXPECT_NE(head, nullptr);
    EXPECT_EQ(head->data.key, 1);
    EXPECT_EQ(head->data.value, 2);
    EXPECT_EQ(head->next, nullptr);
}

TEST(push_node, non_null) {
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = {1, 2};
    head->next = NULL;

    push_node(&head, {2, 3});

    EXPECT_EQ(head->data.key, 1);
    EXPECT_EQ(head->data.value, 2);
    EXPECT_EQ(head->next->data.key, 2);
    EXPECT_EQ(head->next->data.value, 3);
    EXPECT_EQ(head->next->next, nullptr);
}

TEST(delete_node, single) {
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = {1, 2};
    head->next = NULL;
    
    delete_node(&head, 1);

    EXPECT_EQ(head, nullptr);
}

TEST(delete_node, tail) {
    struct Node *tail = (struct Node*) malloc(sizeof(struct Node));
    tail->data = {2, 3};
    tail->next = NULL;
    
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = {1, 2};
    head->next = tail;
   
    delete_node(&head, 2);

    EXPECT_EQ(head->data.key, 1);
    EXPECT_EQ(head->data.value, 2);
    EXPECT_EQ(head->next, nullptr);
}

TEST(delete_node, middle) {
    struct Node *tail = (struct Node*) malloc(sizeof(struct Node));
    tail->data = {3, 4};
    tail->next = NULL;
    
    struct Node *middle = (struct Node*) malloc(sizeof(struct Node));
    middle->data = {2, 3};
    middle->next = tail;
   
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = {1, 2};
    head->next = middle;
   
    delete_node(&head, 2);

    EXPECT_EQ(head->data.key, 1);
    EXPECT_EQ(head->data.value, 2);
    EXPECT_EQ(head->next->data.key, 3);
    EXPECT_EQ(head->next->data.value, 4);
    EXPECT_EQ(head->next->next, nullptr);
}

TEST(delete_node, none) {
    struct Node *tail = (struct Node*) malloc(sizeof(struct Node));
    tail->data = {2, 3};
    tail->next = NULL;
    
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->data = {1, 2};
    head->next = tail;
   
    delete_node(&head, 0);

    EXPECT_NE(head, nullptr);
    EXPECT_EQ(head->data.key, 1);
    EXPECT_EQ(head->data.value, 2);
    EXPECT_EQ(head->next->data.key, 2);
    EXPECT_EQ(head->next->data.value, 3);
    EXPECT_EQ(head->next->next, nullptr);
}
