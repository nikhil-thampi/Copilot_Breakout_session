from abc import ABC, abstractmethod


class Animal(ABC):
    @abstractmethod
    def make_sound(self):
        pass


class Dog(Animal):
    def make_sound(self):
        print("Woof!")


class Cat(Animal):
    def make_sound(self):
        print("Meow!")


class Zoo:
    def __init__(self):
        self.animals = []

    def add_animal(self, animal):
        self.animals.append(animal)

    def make_sounds(self):
        for animal in self.animals:
            animal.make_sound()

    def remove_animal(self, index):
        if index < 0 or index >= len(self.animals):
            print("Index out of range")
            return
        del self.animals[index]


def main():
    zoo = Zoo()
    zoo.add_animal(Dog())
    zoo.add_animal(Cat())
    zoo.make_sounds()


if __name__ == "__main__":
    main()
