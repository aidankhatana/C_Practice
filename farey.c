#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    int den;
    struct node* next;
};

struct node* makeFareyNode(int num, int den, struct node* next) {
    struct node* n = malloc(sizeof(struct node));
    n->num = num;
    n->den = den;
    n->next = next;
    return n;
}

void print_list(struct node* list) {
    printf("(");
    while (list != NULL) {
        printf("%d/%d", list->num, list->den);
        if (list->next != NULL) {
            printf(", ");
        }
        list = list->next;
    }
    printf(")\n");
}

void free_list(struct node* list) {
    if (list == NULL) {
        return;
    }

    while (list != NULL) {
        struct node* temp = list;
        list = list->next;
        free(temp);
    }
}

void generateFareySequence(int level) {
    if (level < 1) {
        printf("Usage: farey <n>\nwhere n >= 1 is the level of the Farey sequence.\n");
        return;
    }

    struct node* list = makeFareyNode(0, 1, makeFareyNode(1, 1, NULL));
    print_list(list);

    if (level == 1) {
        free_list(list);
        return;
    }

    struct node* current;
    struct node* temp;
    struct node* prev;

    for (int i = 2; i <= level; i++) {
        current = list;
        temp = list->next;
        prev = list;

        while (temp != NULL) {
            if (temp->den+current->den <= i) {
                struct node* new_node = makeFareyNode(current->num + temp->num, current->den + temp->den, temp);
                prev->next = new_node;
                new_node->next = temp;
                prev = new_node;
            }

            struct node* next = temp->next;
            prev = temp;
            current = temp;
            temp = next;
        }

        print_list(list);
    }

    free_list(list);
}



int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: farey <n>\nwhere n >= 1 is the level of the Farey sequence.\n");
        return 1;
    }

    int level = atoi(argv[1]);
    generateFareySequence(level);

    return 0;
}
