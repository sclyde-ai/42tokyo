unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{

}

// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <bsd/string.h>

// int main()
// {
//     char dst[10] = "Hello";
//     const char *src = "World";
//     size_t size = sizeof(dst);

//     size_t result = strlcat(dst, src, size);

//     printf("Resulting string: %s\n", dst);
//     printf("Total length: %zu\n", result);

// }

#include <stdio.h>

int main() {
    // 1. 基本的な使用例
    char dest1[20] = "Hello";
    char src1[] = "World";
    size_t result1 = (size_t)ft_strlcat(dest1, src1, sizeof(dest1));
    printf("Test 1: %s (length: %zu)\n", dest1, result1); // 結果: "HelloWorld" (length: 10)

    // 2. バッファのサイズがちょうど十分な場合
    char dest2[11] = "Hello";
    char src2[] = "World";
    size_t result2 = (size_t)ft_strlcat(dest2, src2, sizeof(dest2));
    printf("Test 2: %s (length: %zu)\n", dest2, result2); // 結果: "HelloWorld" (length: 10)

    // 3. バッファのサイズが不十分な場合
    char dest3[10] = "Hello";
    char src3[] = "World";
    size_t result3 = (size_t)ft_strlcat(dest3, src3, sizeof(dest3));
    printf("Test 3: %s (length: %zu)\n", dest3, result3); // 結果: "HelloWorl" (length: 10)

    // 4. 空のバッファに文字列を結合する場合
    char dest4[10] = "";
    char src4[] = "World";
    size_t result4 = (size_t)ft_strlcat(dest4, src4, sizeof(dest4));
    printf("Test 4: %s (length: %zu)\n", dest4, result4); // 結果: "World" (length: 5)

    // 5. `src` が空文字列の場合
    char dest5[10] = "Hello";
    char src5[] = "";
    size_t result5 = (size_t)ft_strlcat(dest5, src5, sizeof(dest5));
    printf("Test 5: %s (length: %zu)\n", dest5, result5); // 結果: "Hello" (length: 5)

    // 6. `dest` が空文字列の場合
    char dest6[20] = "";
    char src6[] = "HelloWorld";
    size_t result6 = (size_t)ft_strlcat(dest6, src6, sizeof(dest6));
    printf("Test 6: %s (length: %zu)\n", dest6, result6); // 結果: "HelloWorld" (length: 10)

    // 7. バッファサイズが1の場合
    char dest7[1] = "";
    char src7[] = "Hello";
    size_t result7 = (size_t)ft_strlcat(dest7, src7, sizeof(dest7));
    printf("Test 7: %s (length: %zu)\n", dest7, result7); // 結果: "" (length: 5)

    return 0;
}