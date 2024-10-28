int *ft_range(int min, int max)
{
    int l;

    l = max - min;
    if(min >= max)
        return NULL;
    int *r;
    r = (int *)malloc(sizeof(int)*(l+1));
    int i;
    i = 0;
    while(i < l)
    {
        r[i] = min + i;
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>


void test_ft_range(int min, int max) {
    int *result = ft_range(min, max);
    
    if (result == NULL) {
        printf("ft_range(%d, %d) returned NULL\n", min, max);
    } else {
        printf("ft_range(%d, %d): ", min, max);
        for (int i = 0; i < max - min; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);  // Freeing the allocated memory
    }
}

int main() {
    // Test case 1: Normal range
    test_ft_range(1, 5); // Expected output: 1 2 3 4

    // Test case 2: Negative range
    test_ft_range(-3, 2); // Expected output: -3 -2 -1 0 1

    // Test case 3: Single element range (edge case)
    test_ft_range(5, 6); // Expected output: 5

    // Test case 4: No range (min >= max)
    test_ft_range(10, 10); // Expected output: NULL

    // Test case 5: Large range
    test_ft_range(100, 105); // Expected output: 100 101 102 103 104

    return 0;
}

