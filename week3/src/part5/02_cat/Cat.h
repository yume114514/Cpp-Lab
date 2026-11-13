#ifndef CAT_H
#define CAT_H

class Cat {
private:
    static int numOfCats;
public:
    Cat();
    Cat(const Cat& other);
    ~Cat();

    static int getNumOfCats();
};

#endif
