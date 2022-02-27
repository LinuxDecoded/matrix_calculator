#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y);

int main() {
    int arr[3][3], deter, i, j;
    printf("Enter elements of matrix[3x3] :\n");
    for(i=0; i<3; i++){
        for(j=0;j<3; j++){
            arr[i][j]=0;
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            system("cls");
            gotoxy(6, 2);
            printf("__");
            gotoxy(9, 2);
            printf("__");
            gotoxy(12, 2);
            printf("__");
            gotoxy(5, 3);
            printf("|");
            gotoxy(6,3);
            printf("%d",arr[0][0]);
            gotoxy(8, 3);
            printf("|");
            gotoxy(9,3);
            printf("%d",arr[0][1]);
            gotoxy(11, 3);
            printf("|");
            gotoxy(12,3);
            printf("%d",arr[0][2]);
            gotoxy(14, 3);
            printf("|");
            gotoxy(5, 4);
            printf("|");
            gotoxy(6,4);
            printf("%d",arr[1][0]);
            gotoxy(8, 4);
            printf("|");
            gotoxy(9,4);
            printf("%d",arr[1][1]);
            gotoxy(11, 4);
            printf("|");
            gotoxy(12,4);
            printf("%d",arr[1][2]);
            gotoxy(14, 4);
            printf("|");
            gotoxy(5, 5);
            printf("|");
            gotoxy(6,5);
            printf("%d",arr[2][0]);
            gotoxy(8, 5);
            printf("|");
            gotoxy(9,5);
            printf("%d",arr[2][1]);
            gotoxy(11, 5);
            printf("|");
            gotoxy(12,5);
            printf("%d",arr[2][2]);
            gotoxy(14, 5);
            printf("|");
            gotoxy(6, 6);
            printf("--");
            gotoxy(9, 6);
            printf("--");
            gotoxy(12, 6);
            printf("--");
            gotoxy(4, 8);
            printf("Enter %d%d element: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    getch();
    return 0;
}

void gotoxy(int x, int y) {
    COORD co = {0,0};
    co.X=x;
    co.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}