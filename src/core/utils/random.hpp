#ifndef UU_CORE_UTILS_RANDOM_H_
#define UU_CORE_UTILS_RANDOM_H_

#include <vector>
#include <set>
#include <time.h>
#include <random>
#include <chrono>

namespace uu {
namespace core {


/**
 * @return a random device shared by all the library
 */
std::mt19937 &
get_random_engine(
);

/**
 * Returns a random integral number in the range [0,max[ using an
 * approximately uniform probability distribution.
 * @param max
 * @throws OperationNotSupprtedException if the range is larger than the number of random numbers that can be returned by the system
 */
size_t
irand(
    size_t max
);

/**
 * Returns a random double number in the range [0,1[ using an
 * approximately uniform probability distribution.
 */
double
drand(
);

/**
 * Returns a random integral number in the range [0,max[ using an
 * approximately uniform probability distribution.
 * @param max
 * @throws OperationNotSupprtedException if the range is larger than the number of random numbers that can be returned by the system
 */
long
lrand(
    long max
);

/**
 * Returns a number from 0 to num_tests with the number of successes in a sequence of num_tests
 * yes/no experiments, each of which succeeds with probability p.
 */
size_t
get_binomial(
    size_t num_tests,
    double p
);


/**
 * Returns a number from 0 to MAX_LEVEL with geometrically decreasing
 * probability (returns 0 with probability (1-P), 1 with probability (1-P)*(1-P), etc.).
 */
size_t
random_level(
    size_t MAX_LEVEL,
    double P
);

/**
 * Returns k random integers (size_t) in the range [0,max[ using an
 * approximately uniform probability distribution.
 * @param max
 * @param k
 * @throw WrongParameterException if k >= max
 */
std::vector<size_t>
get_k_uniform(
    size_t max,
    size_t k
);

/**
 * Random test: returns TRUE with probability probability.
 */
bool
test(
    double probability
);

/**
 * Random test: returns the index of the vector randomly selected,
 * where each element of the vector contains the probability of selecting
 * it. It is assumed that the elements of the vector sum up to 1.
 */
size_t
test(
    const std::vector<double>& options
);

/**
 * Random test: returns the index of the vector randomly selected,
 * where each element of the vector contains the probability of selecting
 * it. It is assumed that the elements of the vector sum up to 1.
 *
 * @todo this function seems useless, as the previous can be used by just passing
 * options.at(row_num). Check in the code where it is used.
 */
size_t
test(
    const std::vector<std::vector<double> >& options,
    int row_num
);

/**
 * @todo add documentation
 */
template <class RandomAccessIterator, class URNG>
void
shuffle (RandomAccessIterator first, RandomAccessIterator last, URNG&& g)
{
    for (auto i=(last-first)-1; i>0; --i)
    {
        std::uniform_int_distribution<decltype(i)> d(0,i);
        std::swap (first[i], first[d(g)]);
    }
}

}
}

#endif
