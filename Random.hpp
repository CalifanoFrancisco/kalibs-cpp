#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <time.h>

size_t seed = time(NULL);

int random(const int min, const int max) {
    srand(seed);
    return (rand() % max + min);
}

template <typename R_VAL>
int random(const int min, const int max) {
    srand(seed);
    return (R_VAL)(rand() % max + min);
}

#endif