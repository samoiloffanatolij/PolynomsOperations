#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H
#include <QTextEdit>
#include <iostream>
#include <string>
#include <vector>
#include <QFileDialog>
#include <algorithm>
#include <QMessageBox>
#include <math.h>
using namespace std;

struct Elem {
  double ratio;

  vector<int> variables;

  Elem() {
    this->variables.resize(26);
    for (int i = 0; i < 26; ++i) {
      this->variables[i] = 0;
    }
    this->ratio = 0;
  }

  void reset() {
    this->variables.resize(26);
    for (int i = 0; i < 26; ++i) {
      this->variables[i] = 0;
    }
    this->ratio = 0;
  }
};

template<typename T>
struct Node {
  T elem;
  Node* prev, * next;

  Node<T>() {}
  Node<T>(T elem) {
    this->elem = elem;
  }
};


template<typename T>
struct linked_list {
  Node<T>* begin, * end;

  linked_list() {
    begin = new Node<T>;
    begin->next = end = new Node<T>;
    end->prev = begin;
  }

  Node<T>* first() {
    return begin->next;
  }

  Node<T>* last() {
    return end->prev;
  }

  void insert_after(T elem, Node<T>* node) {
    Node<T>* nw = new Node<T>(elem);
    nw->next = node->next;
    nw->prev = node;

    node->next->prev = nw;
    node->next = nw;
  }

  void collapse(Node<T>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
  }

  int size() {
    int c = 0;
    for (auto n = begin->next; n != end; n = n->next) c++;
    return c;
  }

  void replace_after(Node<T>* rep, Node<T>* node) {
    rep->next->prev = rep->prev;
    rep->prev->next = rep->next;

    rep->next = node->next;
    rep->prev = node;

    node->next->prev = rep;
    node->next = rep;
  }

  void insert_back(T elem) {
    insert_after(elem, end->prev);
  }

  void push(Node<T>*& L) {
    Node<T>* q = new Node<T>;
    q->elem = rand();
    q->next = L;
    L = q;
  }

  void Cout(Node<T>*& L) {
    Node<T>* p = L;
    for (; p != nullptr; p = p->next) {
      std::cout << p->elem << " ";
    }
  }

  int countVar() {
    vector<int> var;
    for (Node<T>* p = this->begin; p != this->end; p = p->next) {
      for (int i = 0; i < 26; ++i) {
        if (p->elem.variables[i] != 0) {
          for (int j = 0; j < var.size(); ++j) {
            if (var[j] == i) {
              goto M2;
            }
          }
          var.push_back(i);
        M2:;
        }
      }
    }
    return var.size();
  }

  vector<int> allVar() {
    vector<int> var;
    for (Node<T>* p = this->begin; p != this->end; p = p->next) {
      for (int i = 0; i < 26; ++i) {
        if (p->elem.variables[i] != 0) {
          for (int j = 0; j < var.size(); ++j) {
            if (var[j] == i) {
              goto M2;
            }
          }
          var.push_back(i);
        M2:;
        }
      }
    }
    return var;
  }
};
