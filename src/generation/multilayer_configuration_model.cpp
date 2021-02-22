#include "generation/multilayer_configuration_model.hpp"

namespace uu {
namespace net {

double
pearson_correlated_sequences(
    const std::vector<size_t> &x,
    std::vector<size_t> &y,
    double r,
    double tol
)
{
    size_t n = x.size();
    double x_mean = std::accumulate(x.begin(), x.end(), 0.0) / n;
    double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / n;

    std::vector<double> x_v(n), y_v(n);
    std::transform(x.begin(), x.end(), x_v.begin(), [x_mean](size_t v)
    {
        return v - x_mean;
    });
    std::transform(y.begin(), y.end(), y_v.begin(), [y_mean](size_t v)
    {
        return v - y_mean;
    });

    double norm_x_v = sqrt(std::inner_product(x_v.begin(), x_v.end(), x_v.begin(), 0.0));
    double norm_y_v = sqrt(std::inner_product(y_v.begin(), y_v.end(), y_v.begin(), 0.0));
    double c = norm_x_v * norm_y_v;

    size_t k_max = 10 * (size_t) ceil(pow(log(n), 2) * sqrt(n));
    double T = 2.0 * n; // T_0
    double alpha = 0.95;
    double error = std::inner_product(x_v.begin(), x_v.end(), y_v.begin(), 0.0) - c * r;

    for (size_t k = 0; k < k_max; k++)
    {
        T = T * alpha;
        size_t i1 = uu::core::getRandomInt(n), i2 = uu::core::getRandomInt(n);
        double new_error = error - x_v[i1] * y_v[i1] - x_v[i2] * y_v[i2]
                           + x_v[i1] * y_v[i2] + x_v[i2] * y_v[i1];
        double diff = std::abs(new_error) - std::abs(error);
        double p = std::min(1.0, (diff < 0) + exp(- diff / T)); // probability of the swap

        if (p >= uu::core::drand())
        {
            std::swap(y[i1], y[i2]);
            error = new_error;
            double pcc_diff = std::abs((error + c * r) / c - r);

            if (pcc_diff <= tol)
            {
                break;
            }
        }
    }

    return (error + c * r) / c; // Pearson correlation coefficient
}

}
}