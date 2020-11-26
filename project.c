#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char title[50];
	char singer[50];
	char genre[50];
} My_p;

void Add(My_p* contend, int num);
void Look(My_p* contend, int num);
void Delete(My_p* contend, int * num, int n);

int Find (My_p* contend, int num)
{
    char search[50];
    int i,search_num;

    if (num>0)
    {
        printf("찾을 노래 : ");
        scanf("%s", search);

        for (i =0; i< num; i++)
        {
            if (strcmp(search, contend[i].title) ==0)
            {
                search_num= i;
                break;
            }
            else
            {
                search_num = -1;
                continue;
            }
        }
    }
    else
    {
    	search_num = -2;
	}
    return search_num;
}

void print_Find (My_p* contend, int num, int(*func)(My_p*, int))
{
	int index = func(contend,num);
    if (index>=0)
    {
        printf("%d. 노래 : %s  가수 : %s  장르 : %s\n\n", index+1, contend[index].title, contend[index].singer, contend[index].genre);
    }
    else if (index==-1)
    {
        printf("찾는 곡이 없습니다.");
    }
    else if (index==-2)
    {
        printf("리스트가 비어있습니다.");
    }
}



int main()
{
	int input;
    My_p p[100];
    int cnt = 0;

	printf("나의 플레이리스트\n\n");	

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
			Look(p,cnt);
		}
        
		else if (input ==2)
		{
			printf("\n[노래 찾기]\n\n");
			print_Find(p,cnt,Find);
		}
        
		else if (input ==3)
		{
			printf("\n[노래 추가하기]\n\n");
			Add(p,cnt);
			cnt++;	
		}
        
        else if (input == 4)
		{
            printf("\n[노래 삭제하기]\n\n");
			Delete(p,&cnt, cnt);
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

void Add(My_p* contend, int num)
{
	int input;
	if (num < 100)
	{
		printf("노래 제목 : ");
		scanf("%s", contend[num].title);
		printf("가수 : ");
		scanf("%s", contend[num].singer);
		printf("장르( 발라드 / 힙합 / 댄스곡 / 팝송) : ");
		scanf("%s", contend[num].genre);
		printf("*완료*\n\n\n");
	}
	else 
	{
		printf("@저장공간이 부족합니다.\n\n\n");
	}
}

void Look(My_p* contend, int num)
{
	if (num > 0)
	{
		for (int i = 0; i <num; i++)
		{
			printf("%d. 노래제목: %s  가수: %s  장르: %s\n\n", i+1, contend[i].title, contend[i].singer,contend[i].genre);
		}
		printf("*완료*\n\n\n");
	}
	else
	{
		printf("@플레이리스트가 비었습니다.");
	}
}

void Delete(My_p* contend, int* num, int n)
{
	char remove[50];
	int j;
	if (n>0)
	{
		printf("삭제할 노래 : ");
		scanf("%s", remove);
		
		for (int i= 0 ; i< n; i++)
		{
			if(strcmp(remove, contend[i].title) == 0)
			{
				for (j = i; j<100; j++)
				{
					strcpy(contend[j].title, contend[j+1].title);
					strcpy(contend[j].singer, contend[j+1].singer);
					strcpy(contend[j].genre, contend[j+1].genre);
				}
				printf("*노래가 삭제되었습니다.\n\n\n");
				(*num)--;
			}
			else {
				printf("삭제할 노래가 없습니다.");
			}
		}

	}
	else{
		printf("@플레이리스트가 비었습니다.");
	}
}







