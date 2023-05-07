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
    } else {
        cage->next = first;
        cage->prev = first->prev;
        first->prev = cage;
        first->prev->next = cage;
    }
    cage->light = light;
    return;
}

int Train::getLength() {
    Cage* ptr = first;
    int count = 1;
    ptr->light = 1;
    if (ptr == nullptr)
        return 0;
    ptr->light = 1;
    countOp++;
    ptr = ptr->next;
    while (ptr) {
        if (ptr->light == 0) {
            ptr = ptr->next;
            count++;
            countOp++;
        } else {
            ptr->light = 0;
            while (count > 0) {
                ptr = ptr->prev;
                count--;
                countOp++;
            }
            if (ptr->light == false) {
                return count;
            }
            else {
                count = 1;
                countOp++;
                ptr = ptr->next;
            }
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
