#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct music
{
	char title[50];
	char singer[50];
	char genre[50];
	int like;
	int play_cnt;
	struct music* next;
} My_p;

My_p* list_head = NULL;

void Add (My_p* list_head);

int main()
{
	int input;

	printf("나의 플레이리스트");	

	while (1)
    {
		printf("\n\n=========================\n\n");
        printf("{플레이리스트} \n\n");
        printf("0. 플레이리스트 불러오기\n");
        printf("1. 플레이리스트 보기\n");
        printf("2. 플레이리스트 필터\n");
		printf("3. 노래 재생하기\n");
		printf("4. 노래 찾기\n");
        printf("5. 노래 추가하기\n");
        printf("6. 노래 삭제하기\n");
        printf("7. 나의 노래 차트보기\n");
		printf("8. 플레이리스트 저장하기\n");
        printf("9. 종료하기\n");
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
			printf("\n[플레이리스트 필터]\n\n");
		}		

		else if (input ==3)
		{
			printf("\n[노래 재생하기]\n\n");
		}
		else if (input ==4)
		{
			printf("\n[노래 찾기]\n\n");
		}
        
		else if (input ==5)
		{
			printf("\n[노래 추가하기]\n\n");
			Add(list_head);
		}
        
        else if (input == 6)
		{
            printf("\n[노래 삭제하기]\n\n");
        }
		
		else if (input == 7)
		{
			printf("\n[나의 노래차트]\n\n");
		}		

		else if (input == 8)
		{
			printf("\n[플레이리스트 저장하기]\n\n");
		}
        
        else if (input == 9)
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

void Add(My_p* list_head)
{
	My_p* new_node;
	char new_title[10];
	char new_singer[10];
	char new_genre[10];
	int new_like;
	int new_cnt = 0;
	
	new_node = (My_p*)malloc (sizeof(My_p));
	
	printf("음악 제목 : ");
	scanf("%s", new_title);
	printf("가수 : ");
	scanf("%s", new_singer);
	printf("장르 : ");
	scanf("%s", new_genre);
	printf("좋아요(1) / 그 외(0) :");
	scanf("%d", &new_like);
	
	strcpy(new_node -> title , new_title);
	strcpy(new_node -> singer , new_singer);
	strcpy(new_node -> genre , new_genre);
	new_node -> like = new_like;
	new_node -> play_cnt = new_cnt;

	new_node -> next = list_head;
	list_head = new_node;
}


