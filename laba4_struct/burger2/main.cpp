#include <functional>
#include <iostream>

void change_age(int& age, int new_age)
{
    std::printf("\nстарый возраст: %d & новый возраст: %d\n", age, new_age);

    age = new_age;
}

void change_height(int& height, int new_height)
{
    std::printf("\nстарый рост: %d & новый рост: %d\n", height, new_height);

    height = new_height;
}

struct Person
{
    std::string name;
    std::string gender;
    int age;
    int height;

    void PrintInfo()
    {
        std::printf("\nводитель (%s), пол (%s), возраст водителя (%d), рост водителя (%d)\n", name.c_str(), gender.c_str(), age, height);
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
        std::printf("\n(машина) название: (%s) & цена: (%d) & возраст: (%d)\n", get_car_name().c_str(), price, age);

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
    std::function<void(int&, int)> change_value;

    setlocale(LC_ALL, "Rus");

    Person lamba_driver{"Ivan", "man", 20, 180};

    Person toyota_driver{"Andrey", "man", 25, 190};

    car_info lamba(15000, 15, "lambas", lamba_driver);

    car_info toyota(12000, 11, "toyota", toyota_driver);

    print_object_info(lamba);

    print_object_info(toyota);

    change_value = change_age;

    change_value(lamba_driver.age, 40);

    std::printf("\nтекущий возраст водителя ламбы: %d\n", lamba_driver.age);

    change_value = change_height;

    change_value(lamba_driver.height, 150);

    std::printf("\nтекущий возраст водителя ламбы: %d\n", lamba_driver.height);

    system("pause");

    return 0;
}
