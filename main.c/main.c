#include <stdio.h>
#include <stdlib.h>

int rend();
int rend2();
int right(int a, int b, int r, int box1[10][10]);
void pos(int box[10][10],int u1,int u2,int rew);

int main()
{
   int i,j,n=0,x=0,y,u1,u2,p,d,q1,q2,rew,f,g,h,r,a[7],box[10][10]={0};
   for (i=0; i<10; i++)
   {
       for (j=0; j<10; j++)
       {
           x=x+1;
           box[i][j]=x;
       }
   }

   printf("Press 'start' to get into this game:\n");
   while (1) {
   scanf("%s",a);
   if (strcmp(a,"start")==0)
    break;
   else
   {
       printf("Wrong keyword! Enter again:\n");
       continue;
   }
   }

   printf("\nLet's Gooooo!!\n\n");

   f=rend();
   g=rend2();
   h=rend();

   u1=f+f;
   u2=g;
   rew=(f+g+h);
   if (rew>100)
    rew=rew/2;

   printf("Choose the difficulty level(Press 1 or 2):\n1.Easy\n2.Hard\n");
   scanf("%d",&d);

   printf("\nInitial Position:\nUser1 is in box %d.\nUser2 is in box %d.\n",u1,u2);
      if (d==1)
          printf("And the gem is in box %d!\n",rew);
          else
            printf("And the gem is somewhere inside box!\n");

   while (1)
   {
       pos(box,u1,u2,rew); {
       printf("\nUser1 will spin the wheel(press 1 to spin):\n");
       scanf("%d",&p);
       if (p==1){
        y=rend();
       //printf("%d\n",y);
       printf("Choose your direction:\n1.Right\n2.Left\n3.Up\n4.Down\n");
       scanf("%d",&r);
       q1=right(u1,y,r,box);
       u1=q1;
        if (u1==rew)
       {
           printf("User1 is in box %d!\n",q1);
           printf("\nYou got it! User1 won the game!!!\n\n");
           break;
       }
       printf("User1 is in box %d!\n",q1);
       }

        printf("\nUser2 will spin the wheel(press 1 to spin):\n");
       scanf("%d",&p);
       if (p==1){
        y=rend();
       //printf("%d\n",y);
       printf("Choose your direction:\n1.Right\n2.Left\n3.Up\n4.Down\n");
       scanf("%d",&r);
       q2=right(u2,y,r,box);
       u2=q2;
          if (u2==rew)
       {
           printf("User2 is in box %d!\n",q2);
           printf("\nYou got it! User2 won the game!!!\n\n");
           break;
       }
       printf("User2 is in box %d!\n",q2);
       }
       }
   }
   getch();
}

int rend()
{
    int ren;
    srand(time(NULL));
   ren=rand()%10;
   return ren;
}

int rend2()
{
    int ren;
    srand(time(NULL));
   ren=rand()%100;
   return ren;
}

int right(int a, int b, int r, int box1[10][10])
{
     int i,j,x,y,p=0,q=0;

     for (i=0; i<10; i++)
   {
       for (j=0; j<10; j++)
       {
           if (box1[i][j]==a && r==1){
            if (j+b>9)
            {
                p=j+b-10;
                y=box1[i][p];
            }
            else  {
               p=j+b;
            y=box1[i][p];
           }
       }

          if (box1[i][j]==a && r==2){
            if (j-b<0)
            {
                p=j-b+10;
                y=box1[i][p];
            }
            else  {
               p=j-b;
            y=box1[i][p];
           }
       }

        if (box1[i][j]==a && r==3){
            if (i-b<0)
            {
                p=i-b+10;
                y=box1[p][j];
            }
            else  {
               p=i-b;
            y=box1[p][j];
           }
       }

        if (box1[i][j]==a && r==4){
            if (i+b>9)
            {
                p=i+b-10;
                y=box1[p][j];
            }
            else  {
               p=i+b;
            y=box1[p][j];
           }
       }
       }
   }
       return y;
}

void pos(int box[10][10],int u1,int u2,int rew)
{
    int i,j;
    printf("\n");
       for (i=0; i<10; i++)
       {
           for (j=0; j<10; j++)
           {
               if (box[i][j]==u1){
                    //box[i][j]='A';
                  printf("A  ");
                  goto go;
               }
            //   else printf("*  ");
               if (box[i][j]==u2){
                  //  box[i][j]='B';
                printf("B  ");
                goto go;
               }
            //   else printf("*  ");
               if (box[i][j]==rew){
                 //   box[i][j]='R';
                  printf("R  ");
                  goto go;
                 }
          //     else printf("*  ");
               printf("*  ");
               go:;
           }
           printf("\n");
       }
}
