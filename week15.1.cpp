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
 
/* Kh?i t?o th�ng bucket */
void Initialize ( )
{
      for (int b=0; b<M; b++)
            bucket[b] = NULL;
}
 
/* Th�m m?t n�t I v�o v�o th�ng bucket */
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
 
/* H�m t?o t? di?n */
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
            printf("\n%d Nh?p nghi� :", Hashfunc(word));
            gets(mean);
            p = GetNode(word,mean);
            Insert(p);
      }
      while (1);
}
 
/* H�m t�m m?t t? trong t? di?n */
void FindWord( )
{
      char word[10];
      printf("\n Nh?p t?: ");
      fflush(stdin);
      gets(word);
      LPNODE p = Find(word);
      if(p == NULL)
            printf("Kh�ng c� trong t? di?n");
      else
            printf("\n C� t?: %s \nNghi� l� %s \n ", p->word,p->mean);
}
 
void PrintList(LPNODE List)
{
      LPNODE temp = List;
      while (temp != NULL)
      {
            printf("\n T?: %s",temp->word);
            printf("\n Nghi�: %s\n\n",temp->mean);
            temp = temp->Next;
      }
}
 
void DisplayDictionnary()
{
      for (int i=0; i<M; i++)
            PrintList(bucket[i]);
}
 
/***** Chuong tr�nh ch�nh ****/
int main( )
{
      int chon;
      do
      {
            printf("CHUONG TR�NH T?O M?T T? �I?N\n");
            printf("1.X�Y D?NG T? �I?N                     \n");
            printf("2. TRA T?                                       \n");
            printf("3. XEM TO�N B? T? �I?N             \n");
            printf("4. Quit                                             \n");
            printf("B?n ch?n ch?c nang n�o:                 \n");
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
