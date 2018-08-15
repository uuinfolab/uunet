#include "core/exceptions/assert.h"

namespace uu {
namespace core {

void
assert(
    void* ptr,
    std::string function,
    std::string param
)
{
    if (!ptr)
    {
        std::string msg = "function " + function +
                          ", parameter " + param;
        throw NullPtrException(msg);
    }
}

}
}
