// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
    return;
}

void Train::addCage(bool light) {
    Cage* cage = new Cage;
    cage->light = light;
    if (first == nullptr) {
        first = cage;
        first->next = first;
        first->prev = first;
    } else {
        cage->next = first;
        cage->prev = first->prev;
        first->prev->next = cage;
        first->prev = cage;
    }
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
            int i = count;
            while (i--) {
                ptr = ptr->prev;
                countOp++;
            }
            if (ptr->light == false) {
                return count;
            } else {
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
