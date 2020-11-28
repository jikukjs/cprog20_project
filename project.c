#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char title[50];
	char singer[50];
	char genre[50];
	int like;
	int play_cnt;
} My_p;

void Add(My_p* content, int num);  // 165
void Look(My_p* content, int num);  // 187
void Play(My_p* content, int num);  // 203
void Delete(My_p* content, int * num, int n);  // 222
void Filter(My_p* content, int num);  //257 
void Chart(My_p* content, int num);  // 312
void Save(My_p* content, int num);  // 402
int Open(My_p* content, int* num);  // 418


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
        printf("%d] 노래 : %s  가수 : %s  장르 : %s\n\n", index+1, contend[index].title, contend[index].singer, contend[index].genre);
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
			Open(p,&cnt);
		}
		
		else if (input ==1)
		{
			printf("\n[플레이리스트 보기]\n\n");	
			Look(p,cnt);
		}
        
		else if (input ==2)
		{
			printf("\n[플레이리스트 필터]\n\n");
			Filter(p,cnt);
		}		

		else if (input ==3)
		{
			printf("\n[노래 재생하기]\n\n");
			Play(p,cnt);
		}
		else if (input ==4)
		{
			printf("\n[노래 찾기]\n\n");
			print_Find(p,cnt,Find);
		}
        
		else if (input ==5)
		{
			printf("\n[노래 추가하기]\n\n");
			Add(p,cnt);
			cnt++;	
		}
        
        else if (input == 6)
		{
            printf("\n[노래 삭제하기]\n\n");
			Delete(p,&cnt, cnt);
        }
		
		else if (input == 7)
		{
			printf("\n[나의 노래차트]\n\n");
			Chart(p,cnt);
		}		

		else if (input == 8)
		{
			printf("\n[플레이리스트 저장하기]\n\n");
			Save(p,cnt);
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

void Add(My_p* content, int num)
{
	int input;
	if (num < 100)
	{
		printf("노래 제목 : ");
		scanf("%s", content[num].title);
		printf("가수 : ");
		scanf("%s", content[num].singer);
		printf("장르( 발라드 / 힙합 / 댄스곡 / 팝송) : ");
		scanf("%s", content[num].genre);
		printf("즐겨찾기(좋아요:1, 그 외:0) :  ");
		scanf("%d", &content[num].like);
		content[num].play_cnt =0;
		printf("*완료*\n\n\n");
	}
	else 
	{
		printf("@저장공간이 부족합니다.\n\n\n");
	}
}

void Look(My_p* content, int num)
{
	if (num > 0)
	{
		for (int i = 0; i <num; i++)
		{
			printf("%d] 노래제목: %s  가수: %s  장르: %s\n\n", i+1, content[i].title, content[i].singer,content[i].genre);
		}
		printf("*완료*\n\n\n");
	}
	else
	{
		printf("@플레이리스트가 비었습니다.");
	}
}

void Play(My_p* content, int num)
{
	int play_n;
	printf("재생할 음악의 번호를 입력하세요.: ");
	scanf("%d", &play_n);
	
	if (0< play_n && play_n <=num)
	{
		printf("-%d] %s의 노래 %s 재생 중-\n\n", play_n, content[play_n-1].singer, content[play_n-1].title);
		content[play_n-1].play_cnt ++;
		printf("총 %d번 재생\n\n\n",content[play_n-1].play_cnt);
	} 
	else 
	{
		printf("노래가 없습니다.\n\n\n");
	}
}


void Delete(My_p* content, int* num, int n)
{
	char remove[10];
	int j;
	if (n>0)
	{
		printf("삭제할 노래 : ");
		scanf("%s", remove);
		
		for (int i= 0 ; i< n; i++)
		{
			if(strcmp(remove, content[i].title) == 0)
			{
				for (j = i; j<n-1; j++)
				{
					strcpy(content[j].title, content[j+1].title);
					strcpy(content[j].singer, content[j+1].singer);
					strcpy(content[j].genre, content[j+1].genre);
					content[j].like = content[j+1].like;
					content[j].play_cnt = content[j+1].play_cnt;
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

void Filter (My_p* content, int num)
{
	int input;
	char f_content[10];
	int i;
	
	if (num>0)
	{
		printf("어떤 필터를 적용하시겠습니까? (1. 가수/ 2. 장르/ 3. 즐겨찾기): ");
		scanf("%d", &input);

		if (input ==1)
		{
			printf("가수의 이름 입력: ");
			scanf("%s", f_content);
			for (i=0; i<num; i++)
			{	
				if (strcmp(f_content, content[i].singer)== 0)
				{
					printf("%d] 노래제목: %s  가수: %s  장르: %s\n\n", i+1, content[i].title, content[i].singer,content[i].genre);
				}
			}	
		}
		else if (input == 2)
		{
			printf("장르의 종류 입력: ");
			scanf("%s", f_content);
			for (i=0; i<num; i++)
			{
				if (strcmp(f_content, content[i].genre) == 0)
				{
                	printf("%d] 노래제목: %s  가수: %s  장르: %s\n\n", i+1, content[i].title, content[i].singer,content[i].genre);
				}
			}	
		}
		else if (input == 3)
		{
			for (i = 0; i<num; i++)
			{
				if(content[i].like == 1)
				{
                	printf("%d] 노래제목: %s  가수: %s  장르: %s ->  좋아요\n\n", i+1, content[i].title, content[i].singer,content[i].genre);                
				}
			}
		}
		else 
		{
			printf("잘못 입력하셨습니다.");
		}
	}
	else {
		printf("@플레이리스트가 비었습니다.");
	}
}

void Chart(My_p* content, int num )
{
	int i ;
	if(num>0)
	{
		int *chart_list = malloc(sizeof(int) *num);
		int temp;

		for (i = 0; i<num; i++)
		{
			chart_list[i] = content[i].play_cnt;
		}

		for (i = 0; i<num-1; i++)
		{
			for (int j =i+1; j<num; j++)
			{
				if (chart_list[i]< chart_list[j])
				{
					temp = chart_list[j];
					chart_list[j] = chart_list[i];
					chart_list[i] = temp;
				}
			}
		}
		
		if (num>5)
		{
			for (i=0; i<5; i++)
			{
				if (i ==0)
				{
					for(int j=0; j<num; j++)
					{
						if(chart_list[i] == content[j].play_cnt)
						{
							printf("%d] %s  %s  재생 수:%d\n",j+1,content[j].title, content[j].singer, content[j].play_cnt);
						}
					}
				}
				else 
				{
					if(chart_list[i] == chart_list[i-1])
						continue;
					else
					{
						for(int j=0; j<num; j++)
    	                {
	                        if(chart_list[i] == content[j].play_cnt)
            	            {
        	                    printf("%d] %s  %s  재생 수:%d\n",j+1,content[j].title, content[j].singer, content[j].play_cnt);
                	        }
               			}	
					}
				}
			}
		}
		else 
		{
			for (i=0; i<num; i++)
            {
                if (i ==0)
                {
	                for(int j=0; j<num; j++)
	                {
                        if(chart_list[i] == content[j].play_cnt)
                        {
	                        printf("%d] %s  %s  재생 수:%d\n",j+1,content[j].title, content[j].singer, content[j].play_cnt);
                        }
                    }
                }
                else
                {
                    if(chart_list[i] == chart_list[i-1])
                        continue;
                    else
                    {
                    	for(int j=0; j<num; j++)
                        {
                        	if(chart_list[i] == content[j].play_cnt)
                            {
                                printf("%d] %s  %s  재생 수:%d\n",j+1,content[j].title, content[j].singer, content[j].play_cnt);
                            }
                        }
                    }
                }
            }
		} 
	}	
}
void Save(My_p* content, int num)
{
    if (num > 0)
    {
        int i;
        FILE* f = fopen("Music_Playlist.txt", "w");

        for (i = 0; i < num; i++)
        {
            fprintf(f, "%d %s %s %s %d %d\n",i+1, content[i].title, content[i].singer, content[i].genre,content[i].like, content[i].play_cnt);
        }
        printf("@저장 완료\n\n\n");
    }
   
}

int Open(My_p* content, int* num)
{
    int i;
    FILE* f = fopen("Music_Playlist.txt", "r");

    if (f == NULL)
    {
        printf(" 오류 \n");
        return 1;
    }

    while (1) {
        fscanf(f, "%s %s %s %d %d\n",content[*num].title, content[*num].singer, content[*num].genre, &content[*num].like, &content[*num].play_cnt);
        if (feof(f) != 0)
            break;
        (*num)++;
    }
}



