#include "push_swap.h"
#include <limits.h>



long ft_atoi(const char *str, int *i)
{
    
    int  sign   = 1;
    long result = 0;

    while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;
    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        (*i)++;
    }
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        result = result * 10 + (str[*i] - '0');
        if (result * sign > INT_MAX)
            return LONG_MAX;
        if (result * sign < INT_MIN)
            return LONG_MAX;
        (*i)++;
    }
    if (!(str[*i] == '\0' || str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
        return LONG_MAX;

    return result * sign;
}
/*long ft_atoi(const char *str, int *i)
{
    
    int  sign   = 1;
    long result = 0;

    while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
        (*i)++;
    if (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            sign = -1;
        (*i)++;
    }
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        result = result * 10 + (str[*i] - '0');
        if (result * sign > INT_MAX)
            return LONG_MAX;
        if (result * sign < INT_MIN)
            return LONG_MAX;
        (*i)++;
    }
    if (!(str[*i] == '\0' || str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
        return LONG_MAX;

    return result * sign;
}*/