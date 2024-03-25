#include <iostream>
#include <memory>
#include <vector>

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!\n";
    }
};

class Zoo {
private:
    std::vector<std::unique_ptr<Animal>> animals;
public:
    void addAnimal(std::unique_ptr<Animal> animal) {
        animals.push_back(std::move(animal));
    }
    void makeSounds() {
        for (const auto& animal : animals) {
            animal->makeSound();
        }
    }
    void removeAnimal(int index) { // New method to remove an animal
        if (index < 0 || index >= animals.size()) {
            std::cout << "Index out of range\n";
            return;
        }
        animals.erase(animals.begin() + index);
    }
};

int main() {
    Zoo zoo;
    zoo.addAnimal(std::make_unique<Dog>());
    zoo.addAnimal(std::make_unique<Cat>());
    zoo.makeSounds();
    return 0;
}
