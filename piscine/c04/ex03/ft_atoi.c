int ft_atoi(char *str)
{
    int sign;
    int value;
    int digit;

    sign = 1;
    value = 0;
    digit = 1;
    while(*str == ' ')
        str++;
    while(*str == '+' || *str == '-')
    {
        if(*str == '-')
            sign *= -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
        str++;
    str--;
    while(*str >= '0' && *str <= '9')
    {
        value += (*str-48)*digit;
        digit*=10;
        str--;
    }
    return value*sign;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[] = "  1++-23";
    char str2[] = "+---456xyz";
    char str3[] = "2147483647";
    
    int num1 = ft_atoi(str1);
    int num2 = ft_atoi(str2);
    int num3 = ft_atoi(str3);
    
    printf("str1: %s -> %d\n", str1, num1);  // 123 -> 123
    printf("str2: %s -> %d\n", str2, num2);  // 456xyz -> 456
    printf("str3: %s -> %d\n", str3, num3);  // abc -> 0  

    // Test case 1: Positive number
    printf("%d\n", ft_atoi("123")); // Expected output: 123
    
    // Test case 2: Negative number
    printf("%d\n", ft_atoi("-123")); // Expected output: -123
    
    // Test case 3: Positive number with spaces
    printf("%d\n", ft_atoi("   456")); // Expected output: 456
    
    // Test case 4: Negative number with spaces
    printf("%d\n", ft_atoi("   -789")); // Expected output: -789
    
    // Test case 5: Number with leading '+' sign
    printf("%d\n", ft_atoi("+321")); // Expected output: 321
    
    // Test case 6: Number with leading spaces and '+'
    printf("%d\n", ft_atoi("   +654")); // Expected output: 654
    
    // Test case 7: String with invalid input
    printf("%d\n", ft_atoi("abc123")); // Expected output: 0
    
    // Test case 8: String with mixed characters
    printf("%d\n", ft_atoi("123abc")); // Expected output: 123

    return 0;
}
   

