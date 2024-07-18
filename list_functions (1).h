#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

#endif // LIST_FUNCTIONS_H
#include "message.h"
#include <QTextEdit>
#include <iostream>
#include <string>
#include <vector>
#include <QFileDialog>
#include <algorithm>
#include <QMessageBox>
#include <math.h>
using namespace std;


int count(vector<int> x) {
  int ans = 0;
  for (int i = 0; i < x.size(); ++i) {
    ans += x[i];
  }
  return ans;
}


Node<Elem>* qsort(Node<Elem>*& L, linked_list<Elem> polinomial) {
  if (L == nullptr) {
    return L;
  }
  int mid = count(L->elem.variables);
  Node<Elem>* L_less;  L_less = nullptr;
  Node<Elem>* L_equal; L_equal = nullptr;
  Node<Elem>* L_more;  L_more = nullptr;
  Node<Elem>* p = L;

  for (; p != nullptr && p != polinomial.end;) {
    if (count(p->elem.variables) < mid) {
      if (L_less == nullptr) {
        L_less = p;
        p = p->next;
        L_less->next = nullptr;
      }
      else {
        Node<Elem>* q = p;
        p = p->next;
        q->next = L_less;
        L_less = q;
      }
    }
    else if (count(p->elem.variables) == mid) {
      if (L_equal == nullptr) {
        L_equal = p;
        p = p->next;
        L_equal->next = nullptr;
      }
      else {
        Node<Elem>* q = p;
        p = p->next;
        q->next = L_equal;
        L_equal = q;
      }
    }
    else {
      if (L_more == nullptr) {
        L_more = p;
        p = p->next;
        L_more->next = nullptr;
      }
      else {
        Node<Elem>* q = p;
        p = p->next;
        q->next = L_more;
        L_more = q;
      }
    }
  }

  L_less = qsort(L_less, polinomial);
  L_more = qsort(L_more, polinomial);

  p = L_less;

  if (L_less != nullptr) {
    p = L_less;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = L_equal;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = L_more;

    return L_less;
  }
  else if (L_equal != nullptr) {
    p = L_equal;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = L_more;
    return L_equal;
  }
  else {
    return L_more;
  }

  return L_more;
}


void Easyer(linked_list<Elem> polinomial) {
  for (Node<Elem>* p = polinomial.begin->next; p != polinomial.end; p = p->next) {
    for (Node<Elem>* q = p->next; q != polinomial.end; q = q->next) {
      if (q->elem.variables == p->elem.variables) {
        p->elem.ratio += q->elem.ratio;
        Node<Elem>* w = q->prev;
        polinomial.collapse(q);
        q = w;
      }
    }
  }
  for (Node<Elem>* p = polinomial.begin->next; p != polinomial.end; p = p->next) {
    if (p->elem.ratio == 0) {
      Node<Elem>* w = p->prev;
      polinomial.collapse(p);
      p = w;
    }
  }
  polinomial.begin->next = qsort(polinomial.begin->next, polinomial);
  Node<Elem>* w = polinomial.begin;
  while((w->next != nullptr) && (w->next != polinomial.end)) {
    w->next->prev = w;
    w = w->next;
  }
  w->next = polinomial.end;
  polinomial.end->prev = w;
}


string Round(double f) {
  string str = to_string(f);
  str.erase(str.find_last_not_of('0') + 1, string::npos);
  str.erase(str.find_last_not_of('.') + 1, string::npos);
  return str;
}


string Out(linked_list<Elem> polinomial) {
    Node<Elem>* q = polinomial.end;
    if(q->prev == polinomial.begin){
        return "0";
    }
    else{
        q = q->prev;
        string ans;
        int a = 1;
        if (Round(q->elem.ratio) != "1" && Round(q->elem.ratio) != "-1") {
            ans += Round(q->elem.ratio);
        }
        else {
            for(int i = 0; i < 26; ++i){
                if(q->elem.variables[i] != 0){
                    goto M1;
                }
            }
            a = 0;
            ans += Round(q->elem.ratio);
            M1:;
            if(Round(q->elem.ratio) == "-1" && a != 0){
                ans += '-';
            }
        }
        for (int i = 0; i < 26; ++i) {
          if (q->elem.variables[i] == 1) {
            ans += static_cast<char>(i + 'a');
          }
          else if (q->elem.variables[i] > 1) {
            ans += static_cast<char>(i + 'a');
            ans += '^';
            ans += Round(q->elem.variables[i]);
          }
        }
        q = q->prev;
        while (q != polinomial.begin) {
          if (q->elem.ratio > 0) {
            ans += '+';
          }
          int c = 1;
          if (Round(q->elem.ratio) != "1" && Round(q->elem.ratio) != "-1") {
              ans += Round(q->elem.ratio);
          }
          else {
              int count_vars = 0;
              for(int j = 0; j < q->elem.variables.size(); ++j){
                if(q->elem.variables[j] == 0){
                    count_vars += 1;
                }
              }
              if(Round(q->elem.ratio) == "-1" && count_vars == 26){
                    ans += "-1";
              }
              else if(Round(q->elem.ratio) == "1" && count_vars == 26){
                  ans += "1";
              }
              else if(Round(q->elem.ratio) == "-1"){
                ans += "-";
              }
          }
          for (int i = 0; i < 26; ++i) {
            if (q->elem.variables[i] == 1) {
              ans += static_cast<char>(i + 'a');
            }
            else if (q->elem.variables[i] > 1) {
              ans += static_cast<char>(i + 'a');
              ans += '^';
              ans += Round(q->elem.variables[i]);
            }
          }
          q = q->prev;
        }
        return ans;
    }
}


void Reduction(string x) {
  linked_list<Elem> polinomial;
  x += '+';
  int state = -1;
  int count = 0;
  int curr = -1;
  int curr_count = 0;
  int is_positive = 1;
  Elem p;
  for (int i = 0; i < x.size(); ++i) {
    switch (state)
    {
    case -1:
      if (x[i] >= '0' && x[i] <= '9') {
        p.ratio += x[i] - '0';
        state = 1;
      }
      else if (x[i] == '-') {
        is_positive = 0;
        state = 0;
      }
      else if (x[i] == '+') {
        state = 0;
        is_positive = 1;
      }
      else if (x[i] >= 'a' && x[i] <= 'z') {
        p.ratio = 1;
        curr = x[i] - 'a';
        state = 2;
      }
      break;
    case 0:
      if (x[i] >= '0' && x[i] <= '9') {
        p.ratio *= 10;
        p.ratio += x[i] - '0';
        state = 1;
      }
      else if (x[i] >= 'a' && x[i] <= 'z') {
        p.ratio = 1;
        curr = x[i] - 'a';
        curr_count = 0;
        state = 2;
      }
      break;
    case 1:
      if (x[i] >= '0' && x[i] <= '9') {
        p.ratio *= 10;
        p.ratio += x[i] - '0';
        state = 1;
      }
      else if (x[i] >= 'a' && x[i] <= 'z') {
        curr = x[i] - 'a';
        curr_count = 0;
        state = 2;
      }
      else if (x[i] == '+') {
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
        polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 1;
        state = 0;
      }
      else if (x[i] == '-') {
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
          polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 0;
        state = 0;
      }
      break;
    case 2:
      if (x[i] == '+') {
        p.variables[curr] += 1;
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
          polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 1;
        state = 0;
      }
      else if (x[i] == '-') {
        p.variables[curr] += 1;
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
          polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 0;
        state = 0;
      }
      else if (x[i] >= 'a' && x[i] <= 'z') {
        p.variables[curr] += 1;
        curr = x[i] - 'a';
        state = 2;
      }
      else if (x[i] == '^')
        state = 3;
      break;
    case 3:
      curr_count += x[i] - '0';
      state = 4;
      break;
    case 4:
      if (x[i] >= '0' && x[i] <= '9') {
        curr_count *= 10;
        curr_count += x[i] - '0';
        state = 4;
      }
      else if (x[i] >= 'a' && x[i] <= 'z') {
        p.variables[curr] += curr_count;
        curr = x[i] - 'a';
        curr_count = 0;
        state = 2;
      }
      else if (x[i] == '+') {
        p.variables[curr] += curr_count;
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
          polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 1;
        state = 0;
      }
      else if (x[i] == '-') {
        p.variables[curr] += curr_count;
        ++count;
        if (is_positive == 0) {
          p.ratio *= -1;
        }
        if (p.ratio != 0) {
          polinomial.insert_after(p, polinomial.end->prev);
        }
        p.reset();
        is_positive = 0;
        state = 0;
      }
      break;
    default:
      break;
    }
  }
  Easyer(polinomial);
  base.insert_after(polinomial, base.end->prev);
  string a = Out(polinomial);
  cout << a;
}


int check(string x) {
  int state = -1;
  int error = 0;
  for (int i = 0; i < x.size(); ++i) {
    try {
      switch (state)
      {
      case -1:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] == '-')
          state = 0;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else {
          error = i;
          throw 0;
        }
        break;
      case 0:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else {
          error = i;
          throw 0;
        }
        break;
      case 1:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '+' || x[i] == '-')
          state = 0;
        else {
          error = i;
          throw 0;
        }
        break;
      case 2:
        if (x[i] == '+' || x[i] == '-')
          state = 0;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '^')
          state = 3;
        else {
          error = i;
          throw 0;
        }
        break;
      case 3:
        if (x[i] >= '0' && x[i] <= '9')
          state = 4;
        else {
          error = i;
          throw 0;
        }
        break;
      case 4:
        if (x[i] >= '0' && x[i] <= '9')
          state = 4;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '+' || x[i] == '-')
          state = 0;
        else {
          error = i;
          throw 0;
        }
        break;
      default:
        break;
      }
    }
    catch (...) {
      errorSituation(error);
      return 0;
    }
  }
  switch (state)
  {
  case -1:
    errorSituation(error);
    return 0;
  case 0:
    errorSituation(error);
    return 0;
  case 1:
    Reduction(x);
    return 1;
  case 2:
    Reduction(x);
    return 1;
  case 3:
    errorSituation(error);
    return 0;
  case 4:
    Reduction(x);
    return 1;
  default:
    errorSituation(error);
    return 0;
  }
}


int check_copy(string x) {
  int state = -1;
  int error = 0;
  for (int i = 0; i < x.size(); ++i) {
    try {
      switch (state)
      {
      case -1:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] == '-')
          state = 0;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else {
          error = i;
          throw 0;
        }
        break;
      case 0:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else {
          error = i;
          throw 0;
        }
        break;
      case 1:
        if (x[i] >= '0' && x[i] <= '9')
          state = 1;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '+' || x[i] == '-')
          state = 0;
        else {
          error = i;
          throw 0;
        }
        break;
      case 2:
        if (x[i] == '+' || x[i] == '-')
          state = 0;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '^')
          state = 3;
        else {
          error = i;
          throw 0;
        }
        break;
      case 3:
        if (x[i] >= '0' && x[i] <= '9')
          state = 4;
        else {
          error = i;
          throw 0;
        }
        break;
      case 4:
        if (x[i] >= '0' && x[i] <= '9')
          state = 4;
        else if (x[i] >= 'a' && x[i] <= 'z')
          state = 2;
        else if (x[i] == '+' || x[i] == '-')
          state = 0;
        else {
          error = i;
          throw 0;
        }
        break;
      default:
        break;
      }
    }
    catch (...) {
      return 0;
    }
  }
  switch (state)
  {
  case -1:
    return 0;
  case 0:
    return 0;
  case 1:
    Reduction(x);
    return 1;
  case 2:
    Reduction(x);
    return 1;
  case 3:
    return 0;
  case 4:
    Reduction(x);
    return 1;
  default:
    return 0;
  }
}


int findHigher(linked_list<Elem> polinom){
    vector<int> var = polinom.allVar();
    if(var.size() == 0){
        return 0;
    }
    int max = 0;
    int max_kof = 0;
    for(Node<Elem> *p = polinom.begin->next; p != polinom.end; p = p->next){
        if(max < p->elem.variables[var[0]]){
            max = p->elem.variables[var[0]];
        }
    }
    return max;
}


int findHigherKof(linked_list<Elem> polinom){
    vector<int> var = polinom.allVar();
    double max = 0;
    double max_kof = 0;
    for(Node<Elem> *p = polinom.begin->next; p != polinom.end; p = p->next){
        if(max < p->elem.variables[var[0]]){
            max = p->elem.variables[var[0]];
            max_kof = p->elem.ratio;
        }
    }
    return max_kof;
}


double FindMin(linked_list<Elem> elem){
    Elem min;
    for(Node<Elem> *q = elem.begin->next; q != elem.end; q = q->next){
        if(q == elem.begin->next){
            min = q->elem;
        }
        else{
            if(count(q->elem.variables) < count(min.variables)){
                min = q->elem;
            }
        }
    }
    return min.ratio;
}
