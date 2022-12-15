struct Data {
    int key;
    int value;
};

struct Node {
    struct Data data;
    struct Node *next;
};

int push_node(struct Node **head, struct Data data);
int delete_node(struct Node **head, int key);
