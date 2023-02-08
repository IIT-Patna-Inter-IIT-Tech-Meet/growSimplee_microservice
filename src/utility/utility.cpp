#include "utility.h"

std::string to_string(int x) {
    std::string y;
    do {
        y += (x % 10) + '0';
        x /= 10;
    } while (x);
    std::reverse(y.begin(), y.end());
    return y;
}


std::string to_string(float x) {
    std::string y = ".";
    int X = (int)x;

    do {
        y += (X % 10) + '0';
        X /= 10;
    } while (X);
    std::reverse(y.begin(), y.end());
    x = x - (float)X;
    for(int i = 0; i < 3; i++){
        y+= ((int)(x*10))%10 + '0';
        x *= 10;
    }
    
    return y;
}