#include <stdio.h>

int main(void)
{
    int i;
    char command;

    printf("Enter an integer: "); // ユーザーが12(enter)を入力
    scanf("%d", &i);
    printf("Enter a command: "); // ユーザーがc (enter)を入力しようとするが
    command = getchar();
    putchar(command); // 改行されて終わる
    return 0;
}
