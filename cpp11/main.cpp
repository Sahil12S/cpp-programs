/**
 * This programs uses features that were introduced in C++11
 * 
 * 1. auto
 * 2. nullptr
 * 3. range based for loops
 * 4. override and final
 * 5. Strongly typed enums
 * 
 * 
 * 
 * References:
 *      https://www.codeguru.com/cpp/cpp/article.php/c19083/C-2011-Stronglytyped-Enums.htm
 *      https://www.codeproject.com/Articles/570638/Ten-Cplusplus11-Features-Every-Cplusplus-Developer
 *      https://smartbear.com/blog/develop/the-biggest-changes-in-c11-and-why-you-should-care/
 */

#include <iostream>
#include <map>
#include <vector>

class foo
{
public:
    foo()
    {
    }
    ~foo()
    {
    }
};

class B
{
public:
    virtual void f(short) { std::cout << "B::f" << std::endl; }
};

class D : public B
{
public:
    /**
     * This is okay
            virtual void f(int) { std::cout << "D::f" << std::endl; }
    /**/
    /**
     * This is not okay
            virtual void f(int) override { std::cout << "D::f" << std::endl; }
    /**/

    // This is okay
    virtual void f(short) override final { std::cout << "D::f" << std::endl; }
};

class F : public D
{
public:
    /**
     * Error: Cannot override final function
        virtual void f(short) override { std::cout << "F::f" << std::endl; }
    /**/
    virtual void f(int) { std::cout << "F::f" << std::endl; }
};

// Forward declaration
enum class Selection;

void funcfoo(Selection s)
{
    // something
}

enum class Selection
{
    None,
    Single,
    Multiple
};

enum class Border
{
    None, // No problem with similar enum value
    Flat,
    Raised
};

int main()
{
    /* auto */
    // Telling compiler to deduce data type from its initializer
    auto i = 1;         // i is int
    auto l = 42LL;      // l is long long
    auto p = new foo(); // p is foo*

    // Less code
    std::map<std::string, std::vector<int>> map;
    for (auto it = begin(map); it != end(map); it++)
    {
        // do something
    }

    /* Range based for loops */

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    map["one"] = v;

    for (const auto &val : map)
    {
        std::cout << val.first << std::endl;
        for (auto v : val.second)
        {
            std::cout << v << std::endl;
        }
    }
    /* Strongly typed enums */
    // For normal - Selection s = Multiple; & below one will throw error
    Selection s = Selection::Multiple;
}