#include <iostream>
#include <string>
#include <memory>

class Entity {
public:
	Entity() {
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity() {
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print() {
		std::cout << "Checking Pointer!" << std::endl;
	}
};

int main() {

	{
		std::shared_ptr<Entity> e0;
		{
			// Two ways to create pointers.
			// std::unique_ptr<Entity> entity(new Entity());
			// std::unique_ptr<Entity> entity = std::make_unique<Entity>();

			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

			e0 = sharedEntity;

			std::weak_ptr<Entity> weakEntity = sharedEntity;
			// Can't do this with unique pointer.
			// std::shared_ptr<Entity> e0 = sharedEntity;

			e0 -> Print();
		}
	}

	return 0;
}


/** 
***		Notes		***

* We cannot cope unique pointer. It doesn't allow function of copying a pointer.
* If we want to make a copy of pointer we use Shared Pointer.
* Shared pointer also keeps a count of references about how many pointers exists 
	and incerement or decrement it according to pointers created or deleted.
* Weak Pointer can be used to store shared pointer except it does not incresase the reference count.

*/
