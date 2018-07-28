#include <iostream>
#include <cstdlib>

int getSetBits(unsigned x) 
{ 
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

int main(int argc, char** argv)
{
    unsigned num = strtoul(argv[1]);
    std::cout << getSetBits(num) << '\n';

    return 0;
}