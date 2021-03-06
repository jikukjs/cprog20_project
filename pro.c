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
	int year;
	struct music* next;
} My_p;

My_p* Check(My_p* list_head,char* name);
void Add (My_p** list_head, My_p*(*func)(My_p*,char*));
void Look (My_p* list_head);
void Delete (My_p** list_head, My_p*(*func)(My_p*,char*));
void Find (My_p* list_head, My_p*(*func)(My_p*,char*));
void Filter (My_p* list_head);
My_p* Open(My_p* list_head);
void Save(My_p* list_head);
void Play (My_p* list_head, My_p*(*func)(My_p*,char*));
void Chart(My_p* list_head);
void Year(My_p* list_head);

int main()
{
	My_p* list_head = NULL;

	printf("나의 플레이리스트");	

	while (1)
    {
		int chose;
		int input;

		printf("\n\n=========================\n\n");
        printf("{플레이리스트} \n\n");
        printf("0. 플레이리스트 불러오기\n");
        printf("1. 플레이리스트 보기\n");
        printf("2. 노래의 연도\n");
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
			if( list_head == NULL)
			{
				list_head = Open(list_head);
			}
			else 
				printf("이미 불러왔습니다.");
		}
		
		else if (input ==1)
		{
			printf("\n[플레이리스트 보기]\n\n");	
			printf("(1) 전체 리스트 보기  /  (2) 필터 리스트 보기 -> ");
			scanf("%d", &chose);
			printf("\n");
			if(chose == 1){
				Look(list_head);
			}
			else if (chose == 2) {
				Filter(list_head);
			}
			else 
				printf("잘못 입력했습니다.");
		}
        
		else if (input ==2)
		{
			printf("\n[노래의 연도]\n\n");
			Year(list_head);
		}		

		else if (input ==3)
		{
			printf("\n[노래 재생하기]\n\n");
			Play(list_head,Check);
		}
		else if (input ==4)
		{
			printf("\n[노래 찾기]\n\n");
			Find(list_head,Check);
		}
        
		else if (input ==5)
		{
			printf("\n[노래 추가하기]\n\n");
			Add(&list_head,Check);
		}
        
        else if (input == 6)
		{
            printf("\n[노래 삭제하기]\n\n");
			Delete(&list_head, Check);
        }
		
		else if (input == 7)
		{
			printf("\n[나의 노래차트]\n\n");
			Chart(list_head);
		}		

		else if (input == 8)
		{
			printf("\n[플레이리스트 저장하기]\n\n");
			Save(list_head);
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

	char new_title[20];
	char new_singer[20];
	char new_genre[20];
	int new_like,new_year;
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
		printf("연도(ex 2020)*연도를 모른다면 1000을입력하세요 : ");
		scanf("%d", &new_year);
		printf("좋아요(1) / 그 외(0) :");
		scanf("%d", &new_like);
	
		strcpy(new_node -> title , new_title);
		strcpy(new_node -> singer , new_singer);
		strcpy(new_node -> genre , new_genre);
		new_node -> year = new_year;
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

void Delete(My_p** list_head, My_p*(*func)(My_p*,char*))
{
	My_p* pre = NULL;
	My_p* seek = *list_head;
	char name[20];

	 printf("삭제할 노래 :");
     scanf("%s",name);
	 My_p* now = func(*list_head,name);

	 if (*list_head == now)
	 {
     	(*list_head) = now->next;
     	free(now);  
     	return;
     }
 
    while (seek) 
    {
        if (seek == now)
        {
            pre->next = seek->next;
            free(seek);
            return;
        }
        pre = seek;
        seek = seek->next;
    }
} 

void Find(My_p* list_head,My_p*(*func)(My_p*,char*))
{
	My_p* search_node;
	char name[20];

	printf("노래검색: ");
	scanf("%s",name);
	search_node=func(list_head,name);
	
	if(search_node)
	{
		if (search_node->like==1)
		{
			printf("%s의 노래는 %s가 불렀습니다. 장르는 %s이며 당신이 좋아합니다.", search_node->title, search_node->singer, search_node -> genre);
		}

		else
		{
			printf("%s의 노래는 %s가 불렀습니다. 장르는 %s이입니다.", search_node->title, search_node->singer, search_node -> genre);
		}
	}
	else
		printf("존재하지 않는 노래입니다.\n");
}

void Filter (My_p* list_head)
{
	int input;
	char content[20];
	My_p* tmp = list_head;

	printf("필터 선택? (1. 가수 / 2. 장르/ 3. 좋아요)");
	scanf("%d", &input);

	switch (input){
		case 1:
			printf("가수 입력: ");
			scanf("%s", content);

			while(tmp != NULL)
			{
				if (strcmp(tmp->singer, content)==0)
				{
					printf("가수 : %s  노래 제목 : %s  장르: %s\n",tmp->singer, tmp->title, tmp->genre);
				}
				tmp = tmp -> next;
			}
			break;
		
		case 2:
			printf("장르 입력: ");
			scanf("%s", content);

			while(tmp != NULL)
			{
				if (strcmp(tmp->genre, content)==0)
				{
					printf("장르 : %s  노래 제목 : %s  가수 : %s\n",tmp->genre, tmp->title, tmp->singer);
				}
				tmp = tmp -> next;
			}
			break;

		case 3:
			printf("[좋아요 표시 음악]\n\n");

			while(tmp != NULL)
			{
				if (tmp -> like ==1)
				{
					printf("노래 제목 : %s  가수 : %s  장르: %s\n",tmp->title, tmp->singer, tmp->genre);
				}
				tmp = tmp -> next;
			}
			break;

		default:
			printf("잘못입력했습니다");
			break;
	}
}

My_p* Open(My_p* list_head)
{
	My_p* new_node;

	FILE* f =fopen("Music_Playlist.txt","r+");

	if(f == NULL)
	{
		printf("내용없음 \n");
		return NULL;
	}

	while(1)
	{
		new_node=(My_p*) malloc (sizeof(My_p));

		if (feof(f)!=0)
			break;


		fscanf(f, "%s %s %s %d %d %d\n", new_node->title,new_node->singer, new_node-> genre , &new_node->like, &new_node->play_cnt, &new_node->year);

		new_node->next=list_head;
		list_head=new_node;
	}
	fclose(f);
	return list_head;
}

void Save(My_p* list_head)
{
	My_p* tmp;
	FILE* f =fopen("Music_Playlist.txt","w+");
	
	if(f==NULL)
	{
		printf("내용없음\n");
		return;
	}
	while(list_head)
	{
		tmp = list_head;
		fprintf(f, "%s %s %s %d %d %d\n", tmp->title,tmp->singer, tmp-> genre , tmp->like, tmp->play_cnt, tmp->year);
		
		list_head=list_head->next;
		free(tmp);
	}
	fclose(f);
	printf("저장 완료\n");
}

void Play(My_p* list_head,My_p*(*func)(My_p*,char*))
{
	My_p* search_node;
	My_p* tmp = list_head;
	char name[20];

	printf("재생할 노래: ");
	scanf("%s",name);
	search_node=func(list_head,name);

	if(search_node)
	{
		search_node -> play_cnt += 1;
		printf("%s의 %s를 총 %d번 재생했습니다.\n", search_node->singer, search_node->title,search_node->play_cnt);
	}
	else 
	{
		("노래가 존재하지 않습니다\n");
	}
}

void Chart(My_p* list_head)
{
	int num =0;
	int cha;
	My_p* tmp = list_head;
	My_p* node = list_head;
	My_p* n_list = list_head;
	My_p* z_list; 	

	while(tmp != NULL)
	{
		num+=1;
		tmp = tmp -> next;
	}
	
	int *chart_list = malloc(sizeof(int)*num);
	
	for (int i = 0; i<num; i++)
	{
		chart_list[i] = node->play_cnt;
		node = node -> next;
	}
	
	for (int i = 0; i<num-1; i++)
	{
		for (int j =i+1; j<num; j++)
		{
			if (chart_list[i]< chart_list[j])
			{
				cha = chart_list[j];
				chart_list[j] = chart_list[i];
				chart_list[i] = cha;
			}
		}
	}
	
	for (int i=0; i<num; i++)
    {
		z_list = n_list;

        	if (i ==0)
            {
	         	while(z_list!=NULL)
	            {
                	if(chart_list[i] == z_list -> play_cnt)
                    {
	                	printf("%s  %s  재생 수:%d\n",z_list -> title, z_list -> singer, z_list -> play_cnt);
                    }
					z_list = z_list-> next;
				}
            }
            else
            {
            	if(chart_list[i] == chart_list[i-1])
                	continue;
                else
                   	{
                    	while(z_list!=NULL)
                       	{
                       		if(chart_list[i] == z_list->play_cnt)
                            {
                                printf("%s  %s  재생 수:%d\n",z_list -> title, z_list -> singer, z_list -> play_cnt);
                            }
							z_list = z_list->next;
                        }
                    }
             }
            
	} 
	free(chart_list);
}

void Year(My_p* list_head)
{
	My_p* tmp = list_head;
	int age,M_a;

	printf("나이를 입력해주세요 : ");
	scanf("%d",&age);

	while (tmp != NULL)
	{
		M_a = tmp->year - (2020 - age +1) + 1;
		if (M_a > 0)
		{
			printf("[%s]는/은 %d년 노래로 당신이 %d살일 때 나왔습니다.\n", tmp ->title, tmp->year, M_a);
		}
		else 
		{
			printf("[%s]는/은 %d년 노래로 당신이 태어나기 전에 나왔습니다.\n", tmp -> title,tmp->year);
		}
		tmp = tmp -> next;
	}
}	
