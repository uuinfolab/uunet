#include "core/exceptions/ExternalLibException.h"


namespace uu {
namespace core {

ExternalLibException::ExternalLibException(std::string value)
{
    ExternalLibException::value = "Problem in a call to external library: " + value;
}

ExternalLibException::~ExternalLibException() throw () {}

const char*
ExternalLibException::what() const throw()
{
    return value.data();
}

} // namespace core
} // namespace uu
