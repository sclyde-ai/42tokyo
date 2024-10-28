#include <stdlib.h>

#define NULL ((void *)0)

size_t
ft_strlen(str)
	const char *str;
{
	register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}

char *
ft_strdup(char *s)
{
	int l;
	char *t;

	if (s == NULL) return NULL;
	l = ft_strlen(s);
	t = malloc(l + 1);
	char dest = t;
	int i = 0;
	while (i < l)
	{
		*t = *s;
		t++;
		s++;
		i++;
	}	
	t[l] = '\0';
	return dest;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // 正常系
    char *str1 = "";
    char *str2 = "a";
    char *str3 = "hello, world!";
    char *str4 = "aabbccddeeff";

    char *dup1 = strdup(str1);
    char *dup2 = strdup(str2);
    char *dup3 = strdup(str3);
    char *dup4 = strdup(str4);

    printf("dup1: %s\n", dup1);
    printf("dup2: %s\n", dup2);
    printf("dup3: %s\n", dup3);
    printf("dup4: %s\n", dup4);

    // 異常系
    char *null_ptr = NULL;
    char *dup_null = strdup(null_ptr);
    if (dup_null == NULL) {
        printf("strdup(NULL) returned NULL\n");
    } else {
        printf("strdup(NULL) did not return NULL\n");
    }

    // メモリ確保失敗のシミュレーション (実際にはmallocの挙動を制御するのは難しい)
    // mallocが常に失敗するように設定するなど、環境依存となる

    // 確保したメモリを解放
    free(dup1);
    free(dup2);
    free(dup3);
    free(dup4);
    if (dup_null != NULL) {
        free(dup_null);
    }

    return 0;
}