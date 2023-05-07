// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
    return;
}

void Train::addCage(bool light) {
    Cage* cage = new Cage;
    if (first == nullptr) {
        first = cage;
        first->next = first;
        first->prev = first;
        first->light = light;
    } else {
        Cage* last = first->prev;
        first->next = first;
        first->prev = last;
        last->next = cage;
        first->prev = cage;
    }
    return;
}

int Train::getLength() {
    Cage* ptr = first;
    int count = 1;
    ptr->light = true;
    while (1) {
        ptr = ptr->next;
        if (ptr->light == 0) {
            ptr->light = 1;
            count++;
            countOp++;
        } else {
            ptr->light = 0;
            while (count > 0) {
                ptr = ptr->prev;
                count--;
                countOp++;
            }
            countOp++;
            if (ptr->light == 0)
                return count;
            else {
                count = 1;
            }
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
