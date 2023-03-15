#include <iostream>
#include <string>
class Human{

public:
    int age;
    int weight;
    std::string name;

    void Print()
    {
        std::cout<<"Имя:"<<name<<"\nage:"<<age<<"\nweight:"<<weight;
    }

};

int main() {
    Human firstHuman;
//
//    Human secondHuman;
//
//    secondHuman.name= "Polina";
//    secondHuman.age = 23;
//    secondHuman.weight = 200;

    firstHuman.name = "Nikita";
    firstHuman.age = 22;
    firstHuman.weight = 100;

firstHuman.Print();

    firstHuman.name = "Nikita";
    firstHuman.age = 22;
    firstHuman.weight = 100;
//
//    std::cout << firstHuman.name << std::endl;
//    std::cout << firstHuman.weight<< std::endl;
//    std::cout << firstHuman.age << std::endl;
//
//    std::cout << secondHuman.name << std::endl;
//    std::cout << secondHuman.weight<< std::endl;
//    std::cout << secondHuman.age << std::endl;
}

