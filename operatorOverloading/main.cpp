#include <iostream>
#include <string>

using namespace std;

struct Vector {
	float x, y;

	Vector(float x, float y) : x(x), y(y) {}

	Vector Add(const Vector& other) const {
		return Vector(x + other.x, y + other.y);
	}

	Vector Multiply(const Vector& other) const {
		return Vector(x * other.x, y * other.y);
	}

	Vector operator +(const Vector& other) const {
		return Add(other);
	}

	Vector operator *(const Vector& other) const {
		return Multiply(other);
	}

	
};

ostream& operator <<(ostream& stream, const Vector& other) {
	stream << other.x << ", " << other.y;
	return stream;
}

int main() {

	Vector position(4.0f, 4.0f);
	Vector speed(0.5f, 1.5f);
	Vector powerup(1.1f, 1.1f);

	Vector result1 = position.Add(speed.Multiply(powerup));
	Vector result2 = position + speed * powerup;

	cout << result2 << endl;

	return 0;
}