#include <iostream>

class car
{
protected:
    std::string car_name;

    void print_name()
    {
        std::printf("car name: %s\n", car_name.c_str());
    }
public:
    car(std::string name) : car_name(name) {}
};

class car_info : public car
{
protected:
    int age;
    int price;

public:
    car_info(int a1, int a2, std::string name) : age(a1), price(a2), car(name) {}

    void print_info()
    {
        std::printf("\nage : %d & price: %d\n", age, price);
        print_name();
    }
};

int main()
{
    car_info toyota_info(5, 10000, "toyota1337");

    car_info lamba_info(10, 7000, "lamba1337");

    toyota_info.print_info();

    lamba_info.print_info();

    system("pause");

    return 0;
}

