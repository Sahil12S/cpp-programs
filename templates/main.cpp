#include <iostream>
#include <string>

/*template<typename T>
void Print(T value) {
	std::cout << value << std::endl;
}*/

template<typename T, int N>
class Array {
private:
	T m_Array[N];

public:
	int GetSize() const {
		return N;
	}
};

int main() {
	// Print<int>(10);
	// Print(5);
	// Print("hello");
	// Print(5.5f);

	Array<std::string, 10> array;
	std::cout << array.GetSize() << std::endl;

	return 0;
}
