#ifndef SOMEFUNC_H
#define SOMEFUNC_H

#include <getopt.h>
#include <iostream>
#include <iomanip>
#include "include/word2vec.hpp"

namespace uu
{
    namespace net
    {
            w2v::w2vModel_t train_w2v(std::string trainFile, std::string modelFile, w2v::trainSettings_t trainSettings);

    } // namespace net
} // namespace uu

#endif