#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_boolean.h"

#define BUF_SIZE 1024*1024

typedef struct s_character
{
    char    empty;
    char    obstacle;
    char    full;
}            t_character;

typedef struct s_matrix
{
    int        row;
    int        col;
    int        rows;
    int        cols;
    int        opt_row;
    int        opt_col;
    int        max;
}            t_matrix;

typedef struct s_input
{
    int        fd;
    char    buffer[BUF_SIZE];
    int        bytes_read;
}            t_input;

typedef struct s_table
{
    char        *map_start;
    char        **map;
    int        **dp;
}            t_table;

int min(int a, int b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

t_bool input_error(int argc)
{
    if (argc < 1)
    {
        write(2, "map error\n", 10);
        return (1);
    }
    else
        return (0);
}

t_bool open_error(t_input input)
{
    if (input.fd == -1)
    {
        write(2, "map error\n", 10);
        return (1);
    }
    else
        return (0);
}

t_bool byte_error(t_input input)
{
    if (input.bytes_read == -1)
    {
        write(2, "map error\n", 10);
        close(input.fd);
        return (1);
    }
    else
        return (0);
}

t_bool corr_error(t_character character)
{
    if (character.empty == character.obstacle
        || character.obstacle == character.full
        || character.full == character.empty)
    {
        write(2, "map error\n", 10);
        return (1);
    }
    else
        return (0);
}

t_bool num_error(char buffer)
{
    if (!(buffer >= '0' && buffer <= '9'))
    {
        write(2, "map error\n", 10);
        return (1);
    }
    else
        return (0);
}

t_bool col_error(char **map, t_matrix matrix)
{
    if (matrix.col != matrix.cols)
    {
        write(2, "map error\n", 10);
        free(map);
        return (1);
    }
    else
        return (0);
}

t_bool row_error(char **map, t_matrix matrix)
{
    if (matrix.row + 1 != matrix.rows)
    {
        write(2, "map error\n", 10);
        free(map);
        return (1);
    }
    else
        return (0);
}

t_bool get_char(t_input input, t_matrix *matrix, t_character *character,
        char **map_start)
{
    int    i;

    i = 0;
    matrix->rows = 0;
    while (input.buffer[i + 3] != '\n')
    {
        if (num_error(input.buffer[i])) return (1);
        matrix->rows = matrix->rows * 10 + (input.buffer[i] - '0');
        i++;
    }
    character->empty = input.buffer[i++];
    character->obstacle = input.buffer[i++];
    character->full = input.buffer[i++];
    *map_start = input.buffer;
    *map_start += i + 1;
    return (0);
}

t_bool map_error(char **map, t_matrix matrix, t_character character)
{
    if (map[matrix.row][matrix.col] != character.empty
        && map[matrix.row][matrix.col] != character.obstacle)
    {
        write(2, "map error\n", 10);
        return (1);
    }
    else
        return (0);
}

void map_malloc(char ***map, t_matrix matrix)
{
    int i;
    *map = (char **)malloc(matrix.rows * sizeof(char *));
    i = 0;
    while (i < matrix.rows)
    {
        (*map)[i] = (char *)malloc((matrix.cols + 1) * sizeof(char));
        i++;
    }
}

t_bool get_map(char *map_start, char ***map, t_matrix matrix,
        t_character character)
{
    int i;

    map_malloc(map, matrix);
    matrix.row = 0;
    matrix.col = 0;
    i = 0;
    while (map_start[i] != '\0' && i < matrix.rows * (matrix.cols + 1))
    {
        if (map_start[i] == '\n')
        {
            (*map)[matrix.row++][matrix.col] = '\0';
            if (col_error(*map, matrix)) return (1);
            matrix.col = 0;
        }
        else
        {
            (*map)[matrix.row][matrix.col] = map_start[i];
            if (map_error(*map, matrix, character)) return (1);
            matrix.col++;
        }
        i++;
    }
    if (row_error(*map, matrix)) return (1);
    return (0);
}

void dynamic_programming(int **dp, t_matrix *matrix, char **map, t_character character)
{
    int i = 0;
    int j = 0;

    i = 1;
    while (i < matrix->rows)
    {
        j = 1;
        while (j < matrix->cols)
        {
            if (map[i][j] == character.empty)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                if (matrix->max < dp[i][j])
                {
                    matrix->max = dp[i][j];
                    matrix->opt_row = i;
                    matrix->opt_col = j+1;
                }
            }
            else
                dp[i][j] = 0;
            j++;
        }
        i++;
    }
}

void draw_map(t_matrix matrix, t_character character, char **map)
{
	int i;
	int j;

	i = 0;
    while(i <= matrix.max)
    {
        j = 0;
        while(j <= matrix.max)
        {           
            map[matrix.opt_row-i][matrix.opt_col-j] = character.full;
            j++;
        }        
        i++;
    }
}


void core(t_input input, t_matrix matrix, t_character character, t_table table)
{
    table.dp = (int **)malloc(matrix.rows * sizeof(int *));
    for (int i = 0; i < matrix.rows; i++)
        table.dp[i] = (int *)malloc(matrix.cols * sizeof(int));

    dynamic_programming(table.dp, &matrix, table.map, character);
    draw_map(matrix, character, table.map);    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
            write(1, &table.map[i][j], 1);
        write(1, "\n", 1);
    }
	
    for (int i = 0; i < matrix.rows; i++)
        free(table.map[i]);
    free(table.map);
}

int main(int argc, char *argv[])
{
    t_input        input;
    t_matrix    matrix;
    t_character    character;
    t_table        table;

    matrix.row = 0;
    matrix.col = 0;
    matrix.max = 0;     
    table.map_start = 0;
    if (input_error(argc)) return (1);
    int i;
    i = 1;
    while(i < argc)
    {
        input.fd = open(argv[i], O_RDONLY);
        i++;
        if (open_error(input)) continue;
        input.bytes_read = read(input.fd, input.buffer, BUF_SIZE - 1);
        if (byte_error(input)) continue;
        close(input.fd);
        input.buffer[input.bytes_read] = '\0';
        if (get_char(input, &matrix, &character, &table.map_start)) continue;
        if (corr_error(character)) continue;
        while (table.map_start[matrix.cols] != '\n' && table.map_start[matrix.cols] != '\0') matrix.cols++;
        if (get_map(table.map_start, &table.map, matrix, character)) continue;
        core(input, matrix, character, table);
    }
}
