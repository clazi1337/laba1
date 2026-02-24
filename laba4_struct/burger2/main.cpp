#include <iostream>

struct Person
{
    std::string name;
    std::string gender;
    int age;
    int height;

    void PrintInfo()
    {
        std::printf("водитель (%s), пол (%s), возраст водителя (%d), рост водителя (%d)\n", name.c_str(), gender.c_str(), age, height);
    }
};

class car
{
protected:
    std::string name;

    Person info;

    std::string get_car_name()
    {
        return name;
    }

    Person get_driver_info()
    {
        return info;
    }
public:
    car(std::string name, Person person) : name(name), info(person) {};
};

class car_info : public car
{
protected:
    int price;
    int age;
public:
    car_info(int price, int age, std::string name, Person person) : price(price), age(age), car(name, person) {}

    void print_car_info()
    {
        std::printf("(машина) название: (%s) & цена: (%d) & возраст: (%d)\n", get_car_name().c_str(), price, age);

        get_driver_info().PrintInfo();
    }
};

template <typename T>
void print_object_info(T& obj)
{
    obj.print_car_info();
}

int main()
{
    setlocale(LC_ALL, "Rus");

    Person lamba_driver{"Ivan", "man", 20, 180};

    Person toyota_driver{"Andrey", "man", 25, 190};

    car_info lamba(15000, 15, "lambas", lamba_driver);

    car_info toyota(12000, 11, "toyota", toyota_driver);

    print_object_info(lamba);

    print_object_info(toyota);

    system("pause");

    return 0;
}
