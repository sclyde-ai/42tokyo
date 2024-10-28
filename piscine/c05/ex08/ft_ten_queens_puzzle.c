int answer(int column, int row)
{
    if(column == 9 && (row == 1 || row == 10))
        return 2;
    else if(column == 9)
        return 3;
    else if(row == 1)
        return answer(column + 1, row) + answer(column + 1, row + 1);
    else if(row == 10)
        return answer(column + 1, row) + answer(column + 1, row - 1);
    else
        return answer(column + 1, row)  + answer(column + 1, row + 1) + answer(column + 1, row - 1);
}


int ft_ten_queens_puzzle(void)
{
    int row;
    int ans;

    row = 1;
    ans = 0;
    while(row <= 10)
    {
        ans += answer(1, row);
        row++;
    }

    return ans;
}

#include <stdio.h>

int main()
{
    // printf("%d", answer(9, 1));
    // printf("%d", answer(9, 10));
    // printf("%d\n", answer(1, 1));
    // printf("%d\n", answer(1, 2));
    // printf("%d\n", answer(1, 3));
    // printf("%d\n", answer(1, 4));
    // printf("%d\n", answer(1, 5));
    // printf("%d\n", answer(1, 6));
    // printf("%d\n", answer(1, 7));
    // printf("%d\n", answer(1, 8));
    // printf("%d\n", answer(1, 9));
    // printf("%d\n", answer(1, 10));
    printf("%d", ft_ten_queens_puzzle());
}