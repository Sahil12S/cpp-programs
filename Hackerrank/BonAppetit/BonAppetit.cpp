#include <iostream>
#include <string>
#include <vector>
#include <sstream>


// Split string using stringstream.
// std::vector<std::string> split(std::vector<std::string> input, char delim);
std::vector<int> split(std::string line);

// Calculate share of Anna.
int calculate_share(int size, int index, std::vector<int> bill);

int main() {
    std::string line;
    int count = 0;
    std::vector<std::vector<int> > input(3);

    while(count < 3) {
        std::getline(std::cin, line);
        input[count] = split(line);
        count++;
    }

/*
    splitted = split(input, ' ');
    for (std::vector<std::string>::iterator it = splitted.begin(); it != splitted.end(); it++) {
        std::cout << *it << std::endl;
    }
*/

    // for (int i = 0; i < 3; i++) {
    //     for (std::vector<int>::iterator it = input[i].begin(); it != input[i].end(); it++) {
    //         std::cout << *it << std::endl;
    //     }
    // }

    int anna = calculate_share(input[0][0], input[0][1], input[1]);
    // std::cout << "Anna: " << anna << "\n";
    // std::cout << "Calcd share: " << input[2][0] << "\n";

    int adjust = input[2][0] - anna;

    if (adjust == 0) {
        std::cout << "Bon Appetit" << '\n';
    }
    else {
        std::cout << adjust << '\n';
    }


    return 0;
}

// std::vector<std::string> split(std::vector<std::string> input, char delim) {
std::vector<int> split(std::string line) {
    std::vector<int> tokens;
    std::stringstream ss(line);
    std::string item;

    // while(std::getline(ss, item, delim)) {
    //     tokens.push_back(item);
    // }

    while(ss >> item) {
        tokens.push_back(std::stoi(item));
    }
    return tokens;
}


int calculate_share(int size, int index, std::vector<int> bill) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if(i != index)
            sum += bill[i];
    }

    return sum  / 2;
}
