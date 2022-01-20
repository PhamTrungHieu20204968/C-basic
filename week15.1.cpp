#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
//#include<alloc.h>
#define TRUE       1
#define FALSE     0
#define M             26
 
typedef struct tagNODE
{
      char  word [10] ;
      char  mean[50];
      tagNODE *Next;
}NODE, *LPNODE;
 
LPNODE bucket[M];
 
LPNODE GetNode(char word[], char mean[])
{
      LPNODE p = new NODE;
      strcpy(p->word, word);
      strcpy(p->mean, mean);
      p->Next = NULL;
      return p;
}
 
/*-----------------------------------------------------*/
int Hashfunc(char word [])
{
      char ch = toupper(word[0]);
      return ((ch-65) % M);
}
 
/* Kh?i t?o thùng bucket */
void Initialize ( )
{
      for (int b=0; b<M; b++)
            bucket[b] = NULL;
}
 
/* Thêm m?t nút I vào vào thùng bucket */
void Insert (LPNODE p)
{
      int i=Hashfunc(p->word);
      p->Next=bucket[i];
      bucket[i]=p;
}
 
/*--------------------------------------------------------*/
LPNODE Find(char word[])
{
      int done = 1;
      int i = Hashfunc(word);
      LPNODE temp = bucket[i];
      while (done && temp!=NULL)
      {
            if (strcmp(temp->word,word) == 0)
                  done = 0;
            else
                  temp = temp->Next;
      }
      if (done == 0)
            return temp;
      else
            return NULL;
}
 
/* Hàm t?o t? di?n */
void MakeDictionary( )
{
      LPNODE p;
      char word[10];
      char mean[50];
      do
      {
            fflush(stdin);
            printf("\n Nh?p t? c?n tra :");
            gets(word);
            if (!strcmp(word,""))
                  break;
            fflush(stdin);
            printf("\n%d Nh?p nghiã :", Hashfunc(word));
            gets(mean);
            p = GetNode(word,mean);
            Insert(p);
      }
      while (1);
}
 
/* Hàm tìm m?t t? trong t? di?n */
void FindWord( )
{
      char word[10];
      printf("\n Nh?p t?: ");
      fflush(stdin);
      gets(word);
      LPNODE p = Find(word);
      if(p == NULL)
            printf("Không có trong t? di?n");
      else
            printf("\n Có t?: %s \nNghiã là %s \n ", p->word,p->mean);
}
 
void PrintList(LPNODE List)
{
      LPNODE temp = List;
      while (temp != NULL)
      {
            printf("\n T?: %s",temp->word);
            printf("\n Nghiã: %s\n\n",temp->mean);
            temp = temp->Next;
      }
}
 
void DisplayDictionnary()
{
      for (int i=0; i<M; i++)
            PrintList(bucket[i]);
}
 
/***** Chuong trình chính ****/
int main( )
{
      int chon;
      do
      {
            printf("CHUONG TRÌNH T?O M?T T? ÐI?N\n");
            printf("1.XÂY D?NG T? ÐI?N                     \n");
            printf("2. TRA T?                                       \n");
            printf("3. XEM TOÀN B? T? ÐI?N             \n");
            printf("4. Quit                                             \n");
            printf("B?n ch?n ch?c nang nào:                 \n");
            scanf("%d", &chon);
           
            switch ( chon )
            {
                  case 1: MakeDictionary( );        break;
                  case 2: FindWord( );                break;
                  case 3: DisplayDictionnary( );   break;
            }
 
            getch( );
      } while (chon != 4);
      return 0;
}
