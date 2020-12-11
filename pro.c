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


My_p* Check(My_p* list_head,char* name);
void Add (My_p** list_head, My_p*(*func)(My_p*,char*));
void Look (My_p* list_head);
void Delete (My_p* list_head, My_p*(*func)(My_p*,char*));


int main()
{
	int input;
	My_p* list_head = NULL;

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
			Look(list_head);
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
			Add(&list_head,Check);
		}
        
        else if (input == 6)
		{
            printf("\n[노래 삭제하기]\n\n");
			Delete(list_head, Check);
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

My_p* Check(My_p* list_head, char* name)
{
	My_p* tmp=list_head;
	while(tmp)
	{
		if(strcmp(tmp->title, name)==0)
			return tmp;
		tmp=tmp->next;
	}
	return tmp;
}


void Add(My_p** list_head, My_p*(*func)(My_p*,char* ))
{
	My_p* new_node;
	My_p* check_node;

	char new_title[10];
	char new_singer[10];
	char new_genre[10];
	int new_like;
	int new_cnt = 0;
	char name[20];
		
	new_node = (My_p*)malloc (sizeof(My_p));
	
	printf("노래 유무 확인 :");
	scanf("%s",name);
	check_node = func(*list_head,name);

	if(check_node)
	{
		printf("이미 존재하는 곡입니다.\n");
	}
	else
	{
		printf("\n추가하실 곡의 정보를 입력해주세요\n");
		printf("곡 제목 : ");
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
	
		new_node -> next =*list_head;
		*list_head = new_node;
	}
}

void Look(My_p* list_head)
{	
	My_p* tmp = list_head;

	while(tmp != NULL)
	{
		printf("%s - ", tmp->title);
		printf("%s - ", tmp->singer);
		printf("%s - ", tmp->genre);
		printf("좋아요 : %d\n", tmp->like);
		tmp = tmp -> next;
	}
}

void Delete(My_p* list_head, My_p*(*func)(My_p*,char*))
{
	My_p* check_node;
	My_p* pre = list_head;
	My_p* now = pre->next;

	char name[30];
	int del_choice;
	int num=0;
	printf("삭제할 노래 : ");
	scanf("%s",name);
	check_node=func(list_head,name);
	if(check_node==NULL)
	{
		printf("존재하지 않는 옷입니다.\n");
	}

	else
	{
		while (now != NULL)
		{
			if(strcmp(list_head->title, check_node->title)==0)
			{
				list_head = list_head->next;
				free(list_head);
				break;
			}
			else if (strcmp(now->title, name)==0)
			{
				pre->next = now->next;
				free(now);
				break;
			}
			pre = now;
			now = now->next;
		}
	}

}

