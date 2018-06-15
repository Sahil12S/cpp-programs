//============================================================================
// Name        : FactoryMethod.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Factory Method design pattern
//============================================================================

#include <iostream>
#include <string>

// Product from which the concrete class will inherit from.
class Coffee {
protected:
	std::string _type;

public:
	Coffee() {
	}

	std::string getType() {
		return _type;
	}
};

// One concrete class
class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		_type = "Espresso";
		std::cout << "\nMaking a cup of espresso" << std::endl;
		std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
	}
};

// Another concrete class
class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee() {
		_type = "Cappuccino";
		std::cout << "\nMaking a cup of cappuccino" << std::endl;
		std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
		std::cout << "Heat and foam milk" << std::endl;
	}
};

class CoffeeMakerFactory {
private:
	Coffee* _coffee;
public:
	Coffee* GetCoffee() {
		int choice;

		std::cout << "Select a coffee type:" << std::endl;
		std::cout << "1. Espresso" << std::endl;
		std::cout << "2. Cappuccino" << std::endl;
		std::cout << "Selection: ";

		std::cin >> choice;

		switch(choice) {
		case 1:
			return new Espresso;
		case 2:
			return new Cappuccino;
		default:
			std::cout << "Invalid entry" << std::endl;
			return nullptr;
		}
	}
};

int main() {
	CoffeeMakerFactory coffeeMachine;
	Coffee* cup;

	cup = coffeeMachine.GetCoffee();

	std::cout << "\nYou have ordered a(n) " << cup -> getType() << std::endl;

	return 0;
}
