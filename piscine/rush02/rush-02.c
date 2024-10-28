#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_str(char *str, int size)
{
	for (int i = 0; i < size / 2; i++)
		ft_swap(&str[i], &str[size - i - 1]);
}

// 縦横両方を反転する関数
void	ft_rev_2d_array(char array[][4], int rows)
{
	// 縦の反転（行を上下逆に）
	for (int i = 0; i < rows / 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ft_swap(&array[i][j], &array[rows - i - 1][j]);
		}
	}
	// 横の反転（各行の列を左右逆に）
	for (int i = 0; i < rows; i++)
	{
		ft_rev_str(array[i], 3);
	}
}

// 右詰めにする関数
void	ft_right_justify(char array[][4], int rows)
{
	int	len;

	for (int i = 0; i < rows; i++)
	{
		len = 0;
		// 各行の長さを計測（右詰めにする対象を見つける）
		while (array[i][len] != '\0' && len < 3)
			len++;
		// 長さが3未満の場合、左側にゼロを追加
		if (len < 3)
		{
			for (int j = 2; j >= 3 - len; j--)
			{
				array[i][j] = array[i][j - (3 - len)];
			}
			// 残りをゼロで埋める
			for (int j = 0; j < 3 - len; j++)
			{
				array[i][j] = '0';
			}
		}
	}
}
// 数字と英語表記を対応させる構造体
typedef struct
{
	char number;   // 数字 (char型)
	char *english; // 英語表記
}		NumberEnglishPair;
#include <stdio.h>

char	*three_output(char *digit)
{
	NumberEnglishPair	pairs[] = {{'0', ""}, {'1', "One"}, {'2', "Two"}, {'3',
			"Three"}, {'4', "Four"}, {'5', "Five"}, {'6', "Six"}, {'7',
			"Seven"}, {'8', "Eight"}, {'9', "Nine"}};
	int					size;
	char				input;
	int					i;

	// printf("%c", digit[2]);
	// printf("%c", pairs[4].number);
	i = 0;
	while (i < 10)
	{
		if (pairs[i].number == digit[0] && digit[0] != '0')
		{
			ft_putstr(pairs[i].english);
			write(1, " ", 1);
			write(1, "handred ", 8);
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pairs[i].number == digit[1] && digit[1] != '0')
		{
			ft_putstr(pairs[i].english);
			write(1, " ", 1);
			write(1, "ten ", 4);
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pairs[i].number == digit[2] && digit[2] != '0')
		{
			ft_putstr(pairs[i].english);
			write(1, " ", 1);
		}
		i++;
	}
	// write(1, "\n", 1);
	return (digit);
}

int	main(void)
{
	char input[] = "1234567";
	int len;
	int rows;
	int i;
	int j;
	char *numbers[] = {"", "thousand", "million", "billion", "trillion",
		"quadrillion", "quintillion", "sextillion", "septillion", "octillion",
		"nonillion", "decillion", "undecillion"};

	// 入力を文字列として初期化
	len = ft_strlen(input);
	ft_rev_str(input, len);
	// 行数（3桁ごとのグループの数）を計算
	rows = (len / 3) + 1;
	char two_dim_array[rows][4]; // +1はヌル文字のため
	// 1次元文字列を2次元配列に変換（3桁ごとにグループ化）
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < 3)
		{
			if (i * 3 + j < len)
				two_dim_array[i][j] = input[i * 3 + j];
			else
				two_dim_array[i][j] = '0';
			j++;
		}
		two_dim_array[i][3] = '\0'; // 各行の最後にヌル文字を追加
		i++;
	}
	// 右詰めにする
	ft_right_justify(two_dim_array, rows);
	// 縦横両方の反転
	ft_rev_2d_array(two_dim_array, rows);
	// 反転後の配列を出力
	i = 0;
	while (i < rows)
	{
		printf("%s\n", two_dim_array[i]);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		three_output(two_dim_array[i]);
		ft_putstr(numbers[rows - i - 1]);
		write(1, " ", 1);
		i++;
	}
	return (0);
}