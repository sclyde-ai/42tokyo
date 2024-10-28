#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

int	main(int argc, char *argv[])
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		bytes_read;
	int		i;
	int		rows;
	char	empty_char;
	char	obstacle_char;
	char	full_char;
	char	*map_start;
	int		cols;
	char	**map;
	int		row;
	int		col;

	row = 0;
	col = 0;
	if (argc != 2)
	{
		write(2, "Usage: ./program filename\n", 26);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: cannot open file\n", 24);
		return (1);
	}
	bytes_read = read(fd, buffer, BUF_SIZE - 1);
	if (bytes_read == -1)
	{
		write(2, "Error: cannot read file\n", 24);
		close(fd);
		return (1);
	}
	close(fd);
	buffer[bytes_read] = '\0'; // Null-terminate the buffer
	// 数値と文字3つを手動で抽出
	i = 0;
	rows = 0;
	while (buffer[i + 3] != '\n')
	{
		if (!(buffer[i] >= '0' && buffer[i] <= '9'))
		{
			write(2, "a map error\n", 10);
			return (0);
		}
		rows = rows * 10 + (buffer[i] - '0');
		i++;
	}
	empty_char = buffer[i++];
	obstacle_char = buffer[i++];
	full_char = buffer[i++];
	// when there are same characer, return 0
	if (empty_char == obstacle_char || obstacle_char == full_char
		|| full_char == empty_char)
	{
		write(2, "b map error\n", 10);
		return (0);
	}
	// ファイルの2行目以降を探すために改行の位置を取得
	map_start = &buffer[i];
	while (*map_start != '\n' && *map_start != '\0')
	{
		map_start++;
	}
	map_start++; // 改行の次の文字から開始
	// 列の数（最初のデータ行の長さ）を計算
	cols = 0;
	while (map_start[cols] != '\n' && map_start[cols] != '\0')
	{
		cols++;
	}
	// 列数と行数を表示（デバッグ用）
	printf("Rows: %d\n", rows);
	printf("Cols: %d\n", cols);
	printf("Empty: %c\n", empty_char);
	printf("Obstacle: %c\n", obstacle_char);
	printf("Full: %c\n", full_char);
	// 2次元配列の動的メモリ確保（行と列の大きさに応じて）
	map = (char **)malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; i++)
	{
		map[i] = (char *)malloc((cols + 1) * sizeof(char)); // +1 は NULL 終端用
	}
	// バッファから2次元配列にデータを格納
	row = 0, col = 0;
	for (int i = 0; map_start[i] != '\0' && row < rows; i++)
	{
		if (map_start[i] == '\n')
		{
			map[row][col] = '\0'; // 行の終端
			row++;
			if (col != cols)
			{
				write(2, "c map error\n", 10);
				free(map);
				return (0);
			}
			col = 0;
		}
		else
		{
			map[row][col] = map_start[i];
			if (map[row][col] != empty_char && map[row][col] != obstacle_char)
			{
				write(2, "d map error\n", 10);
				free(map);
				return (0);
			}
			col++;
		}
	}
	if (row + 1 != rows)
	{
		printf("%d\n", row);
		printf("%d\n", rows);
		write(2, "e map error\n", 10);
		free(map);
		return (0);
	}
	// 2次元配列の内容を表示
	for (int i = 0; i < rows; i++)
	{
		write(1, map[i], cols);
		write(1, "\n", 1);
	}
	// メモリ解放
	for (int i = 0; i < rows; i++)
	{
		free(map[i]);
	}
	free(map);
	return (0);
}
