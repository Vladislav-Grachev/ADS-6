// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T array[100];
    int q, k;
 public:
    TPQueue() : q(0), k(0) {}
    void push(T value) {
        int i = k++;
        while ((--i >= q) && (array[i % size].prior < value.prior)) {
            array[(i + 1) % size] = array[i % size];
        }
        array[(i + 1) % size] = value;
    }
    T pop() {
        return array[(q++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
