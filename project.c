#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char title[50];
	char singer[50];
	char genre[50];
} My_p;

int main()
{
	int input;
    My_p p[100];
    int cnt = 0;

	printf("나의 플레이리스트");	

	while (1)
    {
        printf("{플레이리스트} \n\n");
        printf("0. 플레이리스트 불러오기\n");
        printf("1. 플레이리스트 보기\n");
        printf("2. 노래 찾기\n");
        printf("3. 노래 추가하기\n");
        printf("4. 노래 삭제하기\n");
        printf("5. 플레이리스트 저장하기\n");
        printf("6. 종료하기\n");
        printf("-> 입력 : ");
        scanf("%d", &input);

        if (input == 0)
		{
            printf("\n[플레이리스트 불러오기]\n\n");
		}
		
		else if (input ==1)
		{
			printf("\n[플레이리스트 보기]\n\n");	
		}
        
		else if (input ==2)
		{
			printf("\n[노래 찾기]\n\n");
		}
        
		else if (input ==3)
		{
			printf("\n[노래 추가하기]\n\n");	
		}
        
        else if (input == 4)
		{
            printf("\n[노래 삭제하기]\n\n");
        }
		
		else if (input == 5)
		{
			printf("\n[플레이리스트 저장하기]\n\n");
		}
        
        else if (input == 6)
		{
			printf("\n[종료하기]\n");
            printf("프로그램 종료\n\n\n");
            break;
		}
        
		else {
            printf("@ 잘못 입력했습니다.\n\n\n");
        }
    }
}	




