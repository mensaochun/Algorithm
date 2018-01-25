//
// Created by pi on 1/25/18.
//

#include "BiLinkList.h"

void BiLinkList::append_front(double x) {
    Node *p_new = new Node;
    p_new->data = x;
    if (this->head == NULL) {
        head = p_new;
        head->next = NULL;
    } else {
        this->head->prev = p_new;
        p_new->next = this->head;
        this->head = p_new;
    }
}

void BiLinkList::append(double x) {
    Node *p_new = new Node;
    p_new->data = x;
    if (this->head == NULL) {
        head = p_new;
        head->prev = NULL;
    } else {
        Node *p_cur = this->head;
        while (p_cur->next) {
            p_cur = p_cur->next;
        }
        p_cur->next = p_new;
        p_new->prev = p_cur;
    }

}

//override
void BiLinkList::get_backward_item(int i, int N, std::vector<double> &out) {
    Node *p_i = this->head;
    for (int j = 1; j < i; j++) {
        p_i = p_i->next;
    }

    Node *p_cur = p_i;
    for (int count = 0; count < N; count++) {
        out.push_back(p_cur->data);
        p_cur = p_cur->prev;
    }
}

void BiLinkList::get_backward_item(int i, int N, BiLinkList &out) {
    Node *p_i = this->head;
    for (int j = 1; j < i; j++) {
        p_i = p_i->next;
    }

    Node *p_cur = p_i;
    for (int count = 0; count < N; count++) {
        if (p_cur) {
            out.append_front(p_cur->data);
            p_cur = p_cur->prev;
        } else {
            return;
        }
    }
}

//override
void BiLinkList::get_forward_item(int i, int N, std::vector<double> &out) {

    Node *p_i = this->head;
    for (int j = 1; j < i; j++) {
        p_i = p_i->next;
    }

    Node *p_cur = p_i;
    for (int count = 0; count < N; count++) {
        out.push_back(p_cur->data);
        p_cur = p_cur->next;
    }
}

void BiLinkList::get_forward_item(int i, int N, BiLinkList &out) {

    Node *p_i = this->head;
    for (int j = 1; j < i; j++) {
        p_i = p_i->next;
    }

    Node *p_cur = p_i;
    for (int count = 0; count < N; count++) {
        if (p_cur) {
            out.append_front(p_cur->data);
            p_cur = p_cur->next;
        } else {
            return;
        }
    }
}

void BiLinkList::insert(double x, int i) {
    Node *p_new = new Node;
    p_new->data = x;

    Node *p_i = this->head;
    for (int j = 1; j < i; j++) {
        p_i = p_i->next;
    }
    Node *p_i_prev = p_i->prev;
    p_i_prev->next = p_new;
    p_new->prev = p_i_prev;
    p_new->next = p_i;
    p_i->prev = p_new;
}

void BiLinkList::show() {
    Node *p_cur = this->head;
    int i = 1;
    while (p_cur) {
        std::cout << "Node " << i << ": " << p_cur->data << std::endl;
        p_cur = p_cur->next;
        i++;
    }
}
//
BiLinkList::~BiLinkList() {

    if (this->head == NULL) {
        return;
    } else {
        Node *p_cur = this->head;
        Node *temp = nullptr;
        while (true) {
            temp = p_cur->next;
            delete p_cur;
            p_cur = temp;
            if (p_cur == NULL) {
                break;
            }
        }
    }
}