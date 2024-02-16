#include "Factory.h"

class Derived3 : public Base {
public:
    void printInfo() const override {
        std::cout << "Derived3\n";
    }
};

REGISTER_FACTORY(Derived3);

int main() {
    std::unique_ptr<Base> obj3 = Factory::instance().createObject("Derived3");

    if (obj3) obj3->printInfo();

    return 0;
}
