#include <iostream>
#include <string>
#include <vector>

using namespace std;


string whenOdd(vector<int> maria, vector<int> andrea);
string whenEven(vector<int> maria, vector<int> andrea);

int main() {

	string called = "odd";
	string winner;

	vector<int> maria = {2, 1, 3};
	vector<int> andrea = {1, 2, 3};

	if(called == "odd") {
		winner = whenOdd(maria, andrea);
	} else {
		winner = whenEven(maria, andrea);
	}

	cout << winner << endl;


	return 0;
}


string whenOdd(vector<int> maria, vector<int> andrea) {
	int m, a;
	m = a = 0;
	// int size = sizeof(maria)/sizeof(maria[0]);
	int size = maria.size();

	for(int i = 1; i < size; i += 2) {
		m += (maria[i] - andrea[i]);
		a += (andrea[i] - maria[i]);
		// cout << "m = " << m << "a = " << a << endl;
	}

	if(m > a) {
		cout << "Score: " << m << endl;
		return "Maria";
	}
	else if(a > m) {
		cout << "Score: " << a << endl;
		return "Andrea";
	}
	else
		return "Tie";
}

string whenEven(vector<int> maria, vector<int> andrea) {
	int m, a;
	m = a = 0;
	// int size = sizeof(maria)/sizeof(maria[0]);
	int size = maria.size();

	for(int i = 0; i < size; i += 2) {
		m += (maria[i] - andrea[i]);
		a += (andrea[i] - maria[i]);
	}

	if(m > a) {
		cout << "Score: " << m << endl;
		return "Maria";
	}
	else if(a > m) {
		cout << "Score: " << a << endl;
		return "Andrea";
	}
	else
		return "Tie";
}