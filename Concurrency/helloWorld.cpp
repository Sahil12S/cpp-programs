#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout << "Hello concurrent world!" << endl;
}

int main(int argc, char const *argv[])
{
    thread t(hello);

    t.join();

    return 0;
}
