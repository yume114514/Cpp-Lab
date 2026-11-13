#include "Cat.h"

int Cat::numOfCats = 0;

Cat::Cat() {
    ++numOfCats;
}

Cat::Cat(const Cat& other) {
    ++numOfCats;
}

Cat::~Cat() {
    --numOfCats;
}

int Cat::getNumOfCats() {
    return numOfCats;
}
