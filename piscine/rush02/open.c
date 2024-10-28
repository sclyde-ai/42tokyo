#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// 構造体の定義
typedef struct {
    int number;
    char string[BUFFER_SIZE];
} Data;

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    int index = 0;
    int number;
    int charIndex;
    int dataIndex = 0;
    
    // ファイルを開く
    fd = open("numbers.dict", O_RDONLY);
    if (fd < 0) {
        perror("ファイルを開けませんでした");
        return 1;
    }

    // Data構造体の配列を作成
    Data dataArray[100];

    while (1) {
        char c;
        int bytesRead = read(fd, &c, 1);
        if (bytesRead == 0) { // EOFに達した場合
            break;
        }
        
        // 数値を読み込む
        if (c >= '0' && c <= '9') {
            number = 0;
            while (c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
                bytesRead = read(fd, &c, 1);
            }
            dataArray[dataIndex].number = number;
        }

        // 文字列を読み込む
        if (c == ' ') {
            charIndex = 0;
            while (read(fd, &c, 1) > 0 && c != '\n') {
                dataArray[dataIndex].string[charIndex++] = c;
            }
            dataArray[dataIndex].string[charIndex] = '\0';  // 終端文字
            dataIndex++;
        }
    }

    // ファイルを閉じる
    close(fd);

    // 読み取ったデータを表示
    for (index = 0; index < dataIndex; index++) {
        printf("数値: %d, 文字列: %s\n", dataArray[index].number, dataArray[index].string);
    }

    return 0;
}

