#ifndef UU_OLAP_DISCRETIZATION_H_
#define UU_OLAP_DISCRETIZATION_H_


namespace uu {
namespace net {

template <class O>
class
    UniformDiscretization
{

  private:

    size_t n_;
    bool val_;

  public:

    UniformDiscretization(
        size_t n,
        bool val
    ) : n_(n), val_(val)
    {}

    UniformDiscretization(
        size_t n
    ) : n_(n), val_(true)
    {}

    std::vector<bool>
    operator()(
        const O* obj
    ) const
    {
        (void)obj;
        return std::vector<bool>(n_, val_);
    }


};


}
}

#endif
