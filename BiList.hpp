#ifndef BILIST_HPP
#define BILIST_HPP
#include <cstddef>

template< class T >
struct BiList {
  T data;
  BiList<T>* next;
  BiList<T>* prev;
};

template< class T >
BiList<T>* create() {
  BiList<T>* sent = new BiList<T>;
  sent->next = sent;
  sent->prev = sent;
  return sent;
}

template< class T >
BiList<T>* add(BiList<T>* h, const T& d) {
  BiList<T>* newNode = new BiList<T>{d};
  newN->next = h;
  newN->prev = h->prev;
  h->prev->next = newN;
  h->prev = newN;
  return newN;
}

template< class T >
BiList<T>* insert(BiList<T>* h, const T& d) {
    return add(h->next, d);
}
