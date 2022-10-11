// https://www.hackerrank.com/challenges/three-month-preparation-kit-insert-a-node-into-a-sorted-doubly-linked-list/problem
// easy, linked-list

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep)
{
    while (node)
    {
        cout << node->data;

        node = node->next;

        if (node)
        {
            cout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
    while (node)
    {
        DoublyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *head, int data)
{
    auto node = new DoublyLinkedListNode(data);

    if (head == nullptr)
    {
        return node;
    }

    if (node->data < head->data)
    {
        node->next = head;
        head->prev = node;
        head = node;
        return head;
    }

    if (head->next == nullptr)
    {
        head->next = node;
        node->prev = head;
        return head;
    }

    auto curr = head;
    while (curr->data < node->data)
    {
        if (curr->next == nullptr)
        {
            curr->next = node;
            node->prev = curr;
            return head;
        }
        curr = curr->next;
    }
    auto prev = curr->prev;
    prev->next = node;
    node->prev = prev;

    node->next = curr;
    curr->prev = node;

    return head;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        DoublyLinkedList *llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++)
        {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode *llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, " ");
        cout << "\n";

        free_doubly_linked_list(llist1);
    }

    // fout.close();

    return 0;
}
