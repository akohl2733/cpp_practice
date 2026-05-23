#include <iostream>

int globe_var_y{3};
extern const int globe_var_x{10};

// functions like this are externally linked
void sayHi()
{
    std::cout << "HI!\n";
}