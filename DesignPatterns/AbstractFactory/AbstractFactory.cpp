//============================================================================
// Name        : AbstractFactory.cpp
// Author      : Sahil Sharma
// Version     :
// Copyright   : 
// Description : Abstract Factory Design Pattern
//============================================================================

#include <iostream>
#include <string>

// Door objects
class Door {
public:
	Door() {
	}
	virtual ~Door() {
	}

	virtual void Open() = 0;
};

class GasCarDoor : public Door {
public:
	GasCarDoor() {
		std::cout << "Making a door for a gas car." << std::endl;
	}

	void Open() {
		std::cout << "Click!!" << std::endl;
	}
};

class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() {
		std::cout << "Making a door for an electric car" << std::endl;
	}

	void Open() {
		std::cout << "shhhhh" << std::endl;
	}
};

// Engine objects
class Engine {
protected:
	std::string _sound;

public:
	Engine() {
		_sound = "";
	}
	virtual ~Engine() {
	}

	virtual void Run() = 0;
};

class GasEngine : public Engine {
public:
	GasEngine() {
		_sound = "vroom";
		std::cout << "Making gas engine." << std::endl;
	}

	void Run() {
		std::cout << _sound << std::endl;
	}
};

class ElectricEngine : public Engine {
public:
	ElectricEngine() {
		_sound = "SHHHH";
		std::cout << "Making an electric car engine." << std::endl;
	}

	void Run() {
		std::cout << _sound << std::endl;
	}
};

// Factories
class CarFactory {
public:
	virtual ~CarFactory() {
	}

	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class GasCarFactory : public CarFactory {
public:
	Door* BuildDoor() {
		return new GasCarDoor();
	}

	Engine* BuildEngine() {
		return new GasEngine();
	}
};

class ElectricCarFactory : public CarFactory {
public:
	Door* BuildDoor() {
		return new ElectricCarDoor();
	}

	Engine* BuildEngine() {
		return new ElectricEngine();
	}
};

int main() {

	CarFactory* carPlant;
	int choice;

	std::cout << "Select a car type: " << std::endl;
	std::cout << "1: Gasoline" << std::endl;
	std::cout << "2: Electric" << std::endl;
	std::cout << "Selection: ";
	std::cin >> choice;

	std::cout << std::endl;

	switch(choice) {
	case 1:
		carPlant = new GasCarFactory;
		break;
	case 2:
		carPlant = new ElectricCarFactory;
		break;
	default:
		std::cout << "Invalid selection." << std::endl;
		carPlant = nullptr;
		break;
	}

	if(carPlant != nullptr) {
		Door* myDoor = carPlant -> BuildDoor();
		Engine* myEngine = carPlant -> BuildEngine();

		myDoor -> Open();
		myEngine -> Run();
	}

	return 0;
}
