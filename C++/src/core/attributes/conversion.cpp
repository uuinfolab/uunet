#include "core/attributes/conversion.h"
#include "core/exceptions.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <strstream>

namespace uu {
namespace core {

time_t
timegm(
    std::tm * timeptr
)
{
    timeptr->tm_isdst = 0;
    time_t local_time = mktime(timeptr);

    std::tm * tm_local_time_as_UTC = gmtime(&local_time);
    std::tm * tm_local_time = localtime(&local_time);

    tm_local_time->tm_isdst = 0;
    tm_local_time_as_UTC->tm_isdst = 0;
    time_t diff = mktime(tm_local_time) - mktime(tm_local_time_as_UTC);

    return local_time + diff;
}


std::string
to_string (
    const Time& v,
    const std::string& format
)
{
    std::ostringstream ss;

    std::tm time;

    // gmtime interprets the input as UTC
    time = *gmtime(&v);

    ss << std::put_time(&time, format.data());

    return ss.str();
}


std::string
to_string (
    const Text& v
)
{
    return v.text;
}


Value<std::string>
to_string (
    const Value<Time>& v,
    const std::string& format
)
{
    std::string t = to_string(v.value, format);
    return Value<std::string>(t, v.null);
}


template <>
std::string
to_string (
    const Time& v
)
{
    return to_string(v, kDEFAULT_TIME_FORMAT);
}


template <>
Value<std::string>
to_string (
    const Value<Time>& v
)
{
    std::string t = to_string(v.value, kDEFAULT_TIME_FORMAT);
    return Value<std::string>(t, v.null);
}


double
to_double (
    const std::string& double_as_string
)
{
    std::istringstream double_val(double_as_string);
    double result;
    double_val >> result;

    if (!double_val)
    {
        throw WrongFormatException("Error converting string to double: " + double_as_string);
    }

    return result;
}


int
to_int (
    const std::string& int_as_string
)
{
    std::istringstream int_val(int_as_string);
    int result;
    int_val >> result;

    if (!int_val)
    {
        throw WrongFormatException("Error converting string to integer: " + int_as_string);
    }

    return result;
}


long
to_long (
    const std::string& long_as_string
)
{
    std::istringstream long_val(long_as_string);
    long result;
    long_val >> result;

    if (!long_val)
    {
        throw WrongFormatException("Error converting string to integer: " + long_as_string);
    }

    return result;
}


Time
epoch_to_time (
    const std::string& time_as_string
)
{
    int seconds_since_epoch = to_int(time_as_string);
    
    return epoch_to_time(seconds_since_epoch);
}


Time
epoch_to_time (
    int seconds_since_epoch
)
{
    /*std::tm epoch = {};
    std::istringstream time_epoch("1970-01-01 00:00:00 +0");
    time_epoch >> std::get_time(&epoch, "%F %T %z");
    */
    time_t epoch = to_time("1970-01-01 00:00:00", "%F %T");
    time_t epoch_plus_one = to_time("1970-01-01 00:00:01", "%F %T");
    double one_second = std::difftime(epoch_plus_one, epoch);
    
    return epoch + one_second*seconds_since_epoch;
    
}


Time
to_time (
    const std::string& time_as_string
)
{
    return to_time(time_as_string, kDEFAULT_TIME_FORMAT);
}


Text
to_text (
    const std::string& text_as_string
)
{
    Text t;
    t.text = text_as_string;
    return t;
}


Time
to_time (
    const std::string& time_as_string,
    const std::string& format
)
{
    Time result;

    struct std::tm t = {};
    std::istringstream time_val(time_as_string);

    time_val >> std::get_time(&t, format.data());

    if (time_val.fail())
        throw WrongFormatException("Error converting string to time: " +
                                   time_as_string +
                                   " with format " +
                                   format);

    result = core::timegm(&t);

    if (result == (time_t) - 1)
        throw WrongFormatException("Error converting string to time: " +
                                   time_as_string);

    return result;
}


} // namespace core
} // namespace uu
