#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct node
{
    node* prev;
    int data;
    node* next;
};

class Doubly_Linked_List
{
    protected:
        node* m_head;

    public:
        Doubly_Linked_List();
        ~Doubly_Linked_List();

        void print() const;
        node* return_node(int position = -1) const;
        int get_size() const;
        int* add_node(const int data, const int position);
        void remove_node(const int position);
		int* get_element(const int position) const;
};

#endif // DOUBLY_LINKED_LIST_H
