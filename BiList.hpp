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
  BiList<T>* r = static_cast<BiList<T>*>(::operator new(sizeof(BiList<T>)));
  r->next = r;
  r->prev = r;
  return r;
}

template< class T >
BiList<T>* add(BiList<T>* h, const T& d) {
  BiList<T>* newN = new BiList<T>{d};
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

template< class T >
BiList<T>* cut(BiList<T>* h) noexcept {
  if (h->next == h) {
    return h;
  }
  BiList<T>* nextN = h->next;
  BiList<T>* prevN = h->prev;
  prevN->next = nextN;
  nextN->prev = prevN;
  delete h;
  return nextN;
}

template< class T >
BiList<T>* erase(BiList<T>* h) noexcept {
  if (h->next == h) return h;
  return cut(h->next);
}

template< class T >
BiList<T>* clear(BiList<T>* b, BiList<T>* e) noexcept {
  while (b != e) {
    b = cut(b);
  }
  return e;
}

template< class T >
void destroy_sent(BiList<T>* h) noexcept {
  ::operator delete(h);
}

template< class T, class F >
F traverse(F f, BiList<T>* b, BiList<T>* e) {
  for (BiList<T>* curr = b; curr != e; curr = curr->next) {
    f(curr->data);
  }
  return f;
}

template< class T >
BiList<T>* convert(const T* arr, size_t size) {
  BiList<T>* sent = create<T>();
  for (size_t i = 0; i < size; ++i) {
    add(sent, arr[i]);
  }
  return sent;
}

#endif
