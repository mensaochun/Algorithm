//
// Created by pi on 1/25/18.
//

#ifndef BILINKLIST_H
#define BILINKLIST_H

#include <iostream>
#include <vector>
#include "assert.h"

struct Node {
    double data;
    Node *next;
    Node *prev;
};

class BiLinkList {
private:
    Node *head;

    void append_front(double x);

public:
    BiLinkList(){
        this->head= nullptr;
    };

    ~BiLinkList();

    void append(double x);

    void get_forward_item(int i, int N, std::vector<double> &out);

    void get_forward_item(int i, int N, BiLinkList &out);

    void get_backward_item(int i, int N, BiLinkList &out);

    void get_backward_item(int i, int N, std::vector<double> &out);

    void insert(double x, int i);

    void show();
};

#endif //BILINKLIST_H
