#include "../Header files/AccountCollection.h"

void AccountCollection::notify() {
    for (auto observerIterator : observers)
        observerIterator->update();
}

void AccountCollection::registerModelObserver(View *view) {
    this->observers.push_back(view);
}

void AccountCollection::removeModelObserver(View *view) {
    this->observers.remove(view);
}
