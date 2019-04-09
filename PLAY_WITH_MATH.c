#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include<dos.h>

struct rec
{
    char name[20];
    char name1[20];
    float score;
    int lucky;
    int num;
    char gender[10];
}st;

FILE *f;




struct login{

    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
    };



registe()
{
    FILE *log;
    log=fopen("login12.txt","w");
    struct login l;

    printf("\n\t\t\tEnter first name: ");scanf("%s",l.fname);

    printf("\n\t\t\tEnter last name: ");scanf("%s",l.lname);

    printf("\n\t\t\tEnter Username : ");scanf("%s",l.username);
    printf("\n\t\t\tEnter password : ");scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\n\n\t\t\tyour User name is UserID\n");
    printf("\t\t\tNow login with UserID and Password\n");
    printf("\n\t\t\tPress any key to continue......");
    getch();
    system("CLS");
    adlogin();

}

adlogin()
{
    char username[200],password[20];
    FILE *log;
    log=fopen("login12.txt","r");
    struct login l;
    printf("\n\n\n\n\t\t\t\tUserID: ");
    scanf("%s",&username);
    printf("\t\t\t\tPassword: ");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
        {
           if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
           {
               printf("\t\t\tSuccesful login\n");
               Sleep(2000);
               system("cls");
               admin();
           }
           else {
            printf("\t\t\tPlease Enter correct UserID and Password");
            Sleep(1000);
            system("cls");
            vai();
           }
        }

    fclose(log);
}





admin()
{
    int i;
    home:
   printf("\n\n\n\t\t\t*********************************************************");
   printf("\n\t\t\t*\t\t\tPLAY WITH MATH\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t1.display record\t\t\t\t*");
   printf("\n\t\t\t*\t2.edit record\t\t\t\t\t*");
   printf("\n\t\t\t*\t3.delete record\t\t\t\t\t*");
   printf("\n\t\t\t*\t4.user menu\t\t\t\t\t*");
   printf("\n\t\t\t*\t5.back to home\t\t\t\t\t*");
   printf("\n\t\t\t*\t6.Exit\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*********************************************************");
       i=getch();

    if(i=='1') {
    system("cls");
    display_all();
    getch();
    }
    else if(i=='2') {
        system("cls");
        modify_record();
        getch();
    }
    else if (i=='3'){
        system("cls");
        delete_record();
    }
    else if(i=='4')
    {
        system("cls");
        menu();
    }
    else if (i=='5')
        {
            system("cls");
            vai();
    }
    else if(i=='6')
    {
        system("cls");
        bahir();


    }
    else
    {
        error();
        system("cls");
    goto home;
    }
   system("cls");
    goto home;
}

void gotomenu()
{
    int b;
    Sleep(700);
    hi:

    printf("\n\n\n\t\t\t  1.menu\t\t2:exit");

    b=toupper(getch());

    if (b=='2')
    {
        system("cls");
        bahir ();
    }
    else if(b=='1')

    {   system("cls");
        menu ();
    }
    else
    {

        error();
        system("cls");
        goto hi;
    }

}



void error()
{
    MessageBox(0,"PLEASE ENTER CORRECT ONE..???\n","Error!",1);
}







 void feat()
{
   int i;
   printf("\n\n\n\t\t\t*********************************************************");
   printf("\n\t\t\t*\t\t\tPLAY WITH MATH\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t1.Math IQ Test\t\t\t\t\t*");
   printf("\n\t\t\t*\t2.MIND Reader\t\t\t\t\t*");
   printf("\n\t\t\t*\t3.About\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t4.Setting\t\t\t\t\t*");
   printf("\n\t\t\t*\t5.back page\t\t\t\t\t*");
   printf("\n\t\t\t*\t6.Exit\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*********************************************************");

}







void help()
 {
 system("cls");
 printf("\n\n\n\tThis game is very easy to play. You'll be asked some simple");
 printf("\n\n\tmath questions and the right answer is to be chosen among    ");
 printf("\n\n\tthe four options provided. Your score will be calculated at the");
 printf("\n\n\tend. Your score will be calculated and displayed        ");
 printf("\n\n\tat the end  . If you secure highest score, your score");
 printf("\n\n\twill be recorded. So BEST OF LUCK.");
 }






void quiz()
{
     int countr=0;
     int r,i;
     int nq[11];int w;
     int score;
     int choice;
     system("cls");

     mainhome:
     system("cls");
     puts("\n\t\t WELCOME TO MATH I.Q. TEST\n\n") ;
     puts("\n\t\t-------------------------------");
     puts("\n\t\t  1.  start game               ");
     puts("\n\t\t  2.  score                    ");
     puts("\n\t\t  3.  help                     ");
     puts("\n\t\t  4.  go to menu               ");
     printf("\n\t\t-------------------------------\n\n\t\t  ");
     choice=toupper(getch());
     if (choice=='2')
 {
display_all();
 goto mainhome;
 }
     else if (choice=='4') {
     system("cls");
     menu ();
     }
     else if (choice=='3')
 {
 help();
 getch();
 goto mainhome;
 }
    else if(choice=='1'){
     system("cls");


     home:
    system("cls");

     countr=0;
     i=1;
    start:

     r=rand()%24;
     nq[i]=r;
     for (w=0;w<i;w++)
 if (nq[w]==r) goto start;

     switch(r)
  {
  case 1:
  printf("\n\n\t\t\tWhich number is a prime number?");
  printf("\n\n\t\t\tA. 13\tB. 33\n\n\t\t\tC. 49\tD. 44\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++; Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls") ; break;}

  case 2:
  printf("\n\n\n\t\t\twhat is the summation of a pentangle ?");
  printf("\n\n\t\t\tA. 6*90\tB. 5*90\n\n\t\t\tC. none\tD. 7*90\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;;}
  else
       {

    printf("\n\n\t\t\tWrong!!! ");Sleep(700);
  system("cls");break;}
  case 3:
  printf("\n\n\n\t\t\t .5*.05 =    ?");
  printf("\n\n\t\t\tA. 0.25\tB. 0.0025\n\n\t\t\tC. 2.5\tD. 0.025\n\n");

  if (toupper(getch())=='D')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}




  case 4:
  printf("\n\n\n\t\t\t 20 PERCENT of 2 is equal to?");
  printf("\n\n\t\t\tA. 0.4\tB. 0.2\n\n\t\t\tC.0.04\tD.2\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 5:
  printf("\n\n\n\t\t\texpress 71/1000 as a decimal??");
  printf("\n\n\t\t\tA. 0.071\tB. 0.0071\n\n\t\t\tC. 0.71\tD. 7.1\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 6:
  printf("\n\n\n\t\t\t4.7 + .9 + .01 = ?");
  printf("\n\n\t\t\tA. 5.7\tB. 5.61\n\n\t\t\tC.5.6\tD.6.7\n\n");

  if (toupper(getch())=='B' )
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 7:
  printf("\n\n\n\t\t\t0.87 - 0.48 = ?");
  printf("\n\n\t\t\tA. 0.41\tB. 0.31\n\n\t\t\tC. 0.39\tD. 0.46\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 8:
  printf("\n\n\n\t\t\t0.84 / 0.7 = ?");
  printf("\n\n\t\t\tA. 0.12\tB. 0.012\n\n\t\t\tC. 1.02 \tD. 1.2\n\n");

  if (toupper(getch())=='D')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 9:
  printf("\n\n\n\t\t\twhat is the square root of 100?");
  printf("\n\n\t\t\tA. 10\tB. 1000\n\n\t\t\tC. 10000\t\tD.none\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 10:
  printf("\n\n\n\t\t\thow many prime numbers occur from 11 to 19'?");
  printf("\n\n\t\t\tA. 1\tB. 2\n\n\t\t\tC. 3\tD. 4\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 11:
  printf("\n\n\n\t\t\tConsider the following series: 5,6,11,17.\n\t\t\twhat number should come next?");
  printf("\n\n\t\t\tA.34\tB.36\n\n\t\t\tC.28\tD.27\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 12:
  printf("\n\n\n\t\t\t26,21,__,11,6?");
  printf("\n\n\t\t\tA.27\tB.16\n\n\t\t\tC.23\tD.29\n\n");

  if (toupper(getch())=='B')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 13:
  printf("\n\n\n\t\t\twhat number is the largest?");
  printf("\n\n\t\t\tA. 2/5 of 200\tB. 50 percent of 50\n\n\t\t\tC. 0.2 portion of 20\tD. 1/5 of 30\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 14:
  printf("\n\n\n\t\t\tExpress 2/5 as a decimal ?");
  printf("\n\n\t\t\tA. 0.4\tB. o.3\n\n\t\t\tC. 0.5\tD. 0.33\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++; Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 15:
  printf("\n\n\n\t\t\tWho is the father of mathematics?");
  printf("\n\n\t\t\tA.Archimedes\tB.Hipparchus\n\n\t\t\tC.Antoine Lavoisier\tD.Isaac Newton\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++; Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 16:
  printf("\n\n\n\t\t\tWho is the inventor of zero?");
  printf("\n\n\t\t\tA.Archimedes\tB.Arjo Votto\n\n\t\t\tC.Theofrastos\tD.Hipparchus\n\n");

  if (toupper(getch())=='B')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}


  case 17:
  printf("\n\n\n\t\t\tWhich series is the fibonacci series?");
  printf("\n\n\t\t\tA.1,2,3,4\tB.0,1,2,5\n\n\t\t\tC.1,3,4,7\tD.3,5,7,11\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 18:
  printf("\n\n\n\t\t\tIn a through of coin what is the probability of getting head?");
  printf("\n\n\t\t\tA. 1\tB. 2/5\n\n\t\t\tC. 0\tD. 1/2\n\n");

  if (toupper(getch())=='D')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 19:
  printf("\n\n\n\t\t\tConsider the following series:6,12,24,48. what number should come next?");
  printf("\n\n\t\t\tA. 58\tB. 64\n\n\t\t\tC. 96\tD. 60\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 20:
  printf("\n\n\n\t\t\tConsider the folowing series: 25,33,41,49 what number should come next?");
  printf("\n\n\t\t\tA. 57\tB. 59\n\n\t\t\tC. 55\tD. 51\n\n");

  if (toupper(getch())=='A')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 21:
  printf("\n\n\n\t\t\tWho is the father of geometry?");
  printf("\n\n\t\t\tA.Louis Hamilton\tB. Archimedes\n\n\t\t\tC. Euclid\tD.Fibonacci\n\n");

  if (toupper(getch())=='C')
   {printf("\n\n\t\t\tCorrect!!!");countr++;Sleep(700); system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 22:
  printf("\n\n\n\t\t\t1318 / 2 = ?");
  printf("\n\n\t\t\tA. 664\tB. 669\n\n\t\t\tC. 569\tD. 659\n\n");

  if (toupper(getch())=='D')
   {printf("\n\n\t\t\tCorrect!!!");countr++; Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}

  case 23:
  printf("\n\n\n\t\t\t0.75 is same as ?");
  printf("\n\n\t\t\tA. 7.5 percent\tB. 750 percent\n\t\t\tC. 0.75 percent\tD. 75 percent\n\n");

  if (toupper(getch())=='D')
   {printf("\n\n\t\t\tCorrect!!!");countr++; Sleep(700);system("cls");break;}
  else
        {printf("\n\n\t\t\tWrong!!! ");Sleep(700);system("cls");break;}





 }
 i++;
 if (i<=10) goto start;
 score =countr*10;
 if ( score<0) score=0;
 printf("\n\n\n\t\t\tYour Score: %d", score);
 if      ( score==100) printf("\n\n\t\t\tEXCELLENT!!! KEEP IT UP");
 else if ( score>=80 &&  score<100) printf("\n\n\t\t\tVERY GOOD!!");
 else if ( score>=60 && score<80) printf("\n\n\t\t\tGOOD! BUT YOU NEED TO KNOW MORE.");
 else if ( score>=40 &&  score<60) printf("\n\n\t\t\tSATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");
 else printf("\n\n\t\t\tYOU ARE VERY POOR IN MATH.,WORK HARD");
 puts("\n\n\t\t\tNEXT PLAY?(Y/N)");
 if (toupper(getch())=='Y')
   goto home;
 else
  {

    f=fopen("scorec.txt","a+");
    fflush(stdin);
    printf("\n\n\t\t\tenter your lucky number: ");
   scanf("%d",&st.lucky);
   fflush(stdin);
    printf("\n\n\t\t\tplayer name: ");
    gets(st.name);

    printf("\n\n\t\t\tGender: ");
    gets(st.gender);
     rep:
         fflush(stdin);
    printf("\n\t\t\twrite your score hare:  ");
    scanf("%d",&st.num);

    if(st.num==score)
    fwrite(&st,sizeof(st),1,f);
    else {
        printf("\n\t\t\tenter right score");
        goto rep;
    }
    fclose(f);
    printf("\n\n\t\t\tRecord Has Been Created ");

     goto mainhome;
  }
 }
     else
 {
 error();
 Sleep(700);
 goto mainhome;
 }
 return 0;

 }


void display_all()
{

    system("cls");
    f=fopen("scorec.txt","r");
    fread(&st,sizeof(st),1,f);
    fclose(f);
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    f=fopen("scorec.txt","rb");
    while((fread(&st,sizeof(st),1,f))>0)
    {
      if( st.name != 0 && st.gender !=0 && st.num != 0){
      printf("\n\t\t\tlucky number : %d",st.lucky);
      printf("\n\t\t\tPlayer Name  : %s",st.name);

      printf("\n\n\t\t\tGender: %s",st.gender);
      printf("\n\t\t\tscore : %d",st.num);
      }
      printf("\n\n\t\t\t====================================\n");

    }
    getch();
    fclose(f);
}



void modify_record()
{
    int no,found=0;
    system("cls");
    printf("\n\n\t\t\tTo Modify ");
    printf("\n\n\t\t\tPlease Enter lucky number of player: ");
    scanf("%d",&no);
    f=fopen("scorec.txt","rb+");
     while((fread(&st,sizeof(st),1,f))>0 && found==0)
    {
    if(st.lucky==no)
           {
            printf("\n\t\t\tlucky number: %d",st.lucky);
            printf("\n\t\t\tPlayer name : %s",st.name);
            printf("\n\t\t\tscore : %d",st.num);
            printf("\n\n\t\t\tGender: %s",st.gender);
            printf("\n\t\t\tPlease Enter The New Details of player \n");
            fflush(stdin);
            printf("\n\n\t\t\tEnter The Name of player ");
            gets(st.name);
            printf("\n\t\t\tEnter The score out of 100 : ");
            scanf("%d",&st.num);
            printf("\n\t\t\tEnter The gender of player : ");
            scanf("%s",&st.gender);


            fseek(f,-(long)sizeof(st),1);
            fwrite(&st,sizeof(st),1,f);
            printf("\n\n\t\t\t\t Record Updated");
            found=1;
           }
          else  {
            printf("\n\n\t\t\trecord not found");
            break;
         }
    }

    fclose(f);
   // getch();
}


void delete_record()
   {
    int no;
    FILE *fptr2;
   system("cls");
    printf("\n\n\n\t\t\t\tDelete Record");
    printf("\n\n\t\t\tPlease Enter The lucky number of playerYou Want To Delete");
    scanf("%d",&no);

    f=fopen("scorec.txt","rb");

    fptr2=fopen("Temp.dat","wb");
    rewind(f);
    while((fread(&st,sizeof(st),1,f))>0)
    {
       if(st.lucky!=no)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(f);
    remove("scorec.txt");
    rename("Temp.dat","scorec.txt");
    printf("\n\n\t\t\t\tRecord Deleted ..");
    getch();
    system("cls");
    admin();
}



    bahir()
{

    printf("\n\n\n\t\t\t*****thank you********");

}







minstruction()
{

    printf("\n\n\n\n\n\t************************************************************\n");
    Sleep(500);
    printf("\t************************************************************\n");
    Sleep(500);
    printf("\t!1.choose any two digit number & Add together both digits   !\n");
    Sleep(500);
    printf("\t!                                                           !\n");
    printf("\t!                                                           !\n");
    printf("\t!2.Subtract the total from your original number.            !\n");
    printf("\t!                                                           !\n");
    printf("\t!                                                           !\n");
    Sleep(500);
    printf("\t!3.When you got the final number,look it up on the chart and!\n");
    printf("\t!                                                           !\n");
    printf("\t!find the corresponding symbol.                             !\n");
    Sleep(500);
    printf("\t!                                                           !\n");
    printf("\t!                                                           !\n");
    printf("\t!4.Concentrate on the symbol & tap any key.                 !\n");
    Sleep(500);
    printf("\t!5.EXAMPLE: If you chose 41, then add 4+1 and subtract 5    !\n");
    printf("\t!  from 41                                                  !\n");
    printf("\t!                                                           !\n");
    Sleep(500);
    printf("\t************************************************************\n");
    Sleep(500);
    printf("\t************************************************************\n");
    Sleep(500);


    getch();


}




ready()
  {
    printf("\n\n\n\n\n\t\t\tR");
    Sleep(500);
    printf("E");
    Sleep(500);
    printf("D");
    Sleep(500);
    printf("I");
    Sleep(500);
    printf("N");
    Sleep(500);
    printf("G");
    Sleep(500);
    printf("\n\t\t\t\tY");
    Sleep(500);
    printf("O");
    Sleep(500);
    printf("U");
    Sleep(500);
    printf("R");
    Sleep(500);
    printf("\n\t\t\t\t\tM");
    Sleep(500);
    printf("I");
    Sleep(500);
    printf("N");
    Sleep(500);
    printf("D");
    Sleep(500);


  }




mra()
{
     minstruction();
     Sleep(500);
     system("cls");
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(400);
    printf("\t***************************************************************\n");
    Sleep(400);
    printf("\t!1. ?   2.^   3.$   4.>    5.&   6.*   7.+   8.!   9.>  10.:   !\n");
    Sleep(400);
    printf("\t!11.*  12.*  13.@   14.#   15.^  16.?  17.!  18.>  19.* 20.? !\n");
    Sleep(400);
    printf("\t!21.$  22.!  23.^  24.$  25.@  26.#  27.>  28.+  29.?  30.+  !\n");
    Sleep(400);
    printf("\t!31.@  32.>  33.<  34.?  35.*  36.>  37.$  38.^  39.<  40.*  !\n");
    Sleep(400);
    printf("\t!41.&  42.*  43.#  44.^  45.>  46.&  47.@  48.?  49.&  50.^  !\n");
    Sleep(400);
    printf("\t!51.+  52.$  53.!  54.>  55.?  56.$  57.$  58.&  59.#  60.?  !\n");
    Sleep(400);
    printf("\t!61.>  62.^  63.>  64.@  65.<  66.!  67.?  68.!  69.^  70.$  !\n");
    Sleep(400);
    printf("\t!71.!  72.>  73.*  74.<  75.&  76.+  77.+  78.$  79.?  80.#  !\n");
    Sleep(400);
    printf("\t!81.>  82.*  83.<  84.&  85.$  86.^  87.&  88.*  89.<  90.@  !\n");
    Sleep(400);
    printf("\t!91.@  92.#  93.?  94.#  95.&  96.*  97.!  98.@  99.+ 100.+  !\n");
    Sleep(400);
    printf("\t**************************************************************\n");
    Sleep(400);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
    ready();
    system("cls");

     Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           >                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);

}



mre()
{
     minstruction();
      Sleep(500);
     system ("cls");
    printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(400);
    printf("\t***************************************************************\n");
    Sleep(400);
    printf("\t!1.?  11.^  21.$  31.>  41.&  51.*  61.+  71.!  81.&  91.:  !\n");
    Sleep(400);
    printf("\t!2.*  12.*  22.@  32.#  42.^  52.?  62.!  72.&  82.*  92.?  !\n");
    Sleep(400);
    printf("\t!3.$  13.!  23.^  33.$  43.@  53.#  63.&  73.+  83.?  93.+  !\n");
    Sleep(400);
    printf("\t!4.@  14.>  24.<  34.?  44.*  54.&  64.$  74.^  84.<  94.*  !\n");
    Sleep(400);
    printf("\t!5.&  15.*  25.#  35.^  45.&  55.&  65.@  75.?  85.&  95.^  !\n");
    Sleep(400);
    printf("\t!6.+  16.$  26.!  36.&  46.?  56.$  66.$  76.&  86.#  96.?  !\n");
    Sleep(400);
    printf("\t!7.>  17.^  27.&  37.@  47.<  57.!  67.?  77.!  87.^  97.$  !\n");
    Sleep(400);
    printf("\t!8.!  18.&  28.*  38.<  48.&  58.+  68.+  78.$  88.?  98.#  !\n");
    Sleep(400);
    printf("\t!9.&  19.*  29.<  39.&  49.$  59.^  69.&  79.*  89.<  99.@  !\n");
    Sleep(400);
    printf("\t!10.@ 20.#  30.?  40.#  50.&  60.*  70.!  80.@  90.+ 100.+  !\n");
    Sleep(400);
    printf("\t**************************************************************\n");
    Sleep(400);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
     ready();
    system("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           &                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAIN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);


}
mrf()
{
     minstruction();
      Sleep(500);
     system ("cls");
    printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!1.?  11.^  21.$  31.>  41.&  51.*  61.+  71.!  81.#  91.:  !\n");
    Sleep(300);
    printf("\t!2.*  12.*  22.@  32.#  42.^  52.?  62.!  72.#  82.*  92.?  !\n");
    Sleep(300);
    printf("\t!3.$  13.!  23.^  33.$  43.@  53.$  63.#  73.+  83.?  93.+  !\n");
    Sleep(300);
    printf("\t!4.@  14.>  24.<  34.?  44.*  54.#  64.$  74.^  84.<  94.*  !\n");
    Sleep(300);
    printf("\t!5.&  15.*  25.#  35.^  45.#  55.&  65.@  75.?  85.&  95.^  !\n");
    Sleep(300);
    printf("\t!6.+  16.$  26.!  36.#  46.?  56.$  66.$  76.&  86.#  96.?  !\n");
    Sleep(300);
    printf("\t!7.>  17.^  27.#  37.@  47.<  57.!  67.?  77.!  87.^  97.$  !\n");
    Sleep(300);
    printf("\t!8.!  18.#  28.*  38.<  48.&  58.+  68.+  78.$  88.?  98.#  !\n");
    Sleep(300);
    printf("\t!9.#  19.*  29.<  39.&  49.$  59.^  69.&  79.*  89.<  99.@  !\n");
    Sleep(300);
    printf("\t!10.@ 20.#  30.?  40.#  50.&  60.*  70.!  80.@  90.+ 100.+  !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
     ready();
    system("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           &                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAIN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);


}


mri()
{
     minstruction();
      Sleep(500);
     system("cls");
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!91.?  92.^  93.$  94.>   95.&  96.*  97.+  98.!  99.> 100.: !\n");
    Sleep(300);
    printf("\t!81.+  82.*  83.@   84.#   85.^  86.?  87.!  88.>  89.* 90.? !\n");
    Sleep(300);
    printf("\t!71.$  72.+  73.^  74.$  75.@  76.#  77.>  78.+  79.?  80.+  !\n");
    Sleep(300);
    printf("\t!61.@  62.>  63.+  64.?  65.*  66.>  67.$  68.^  69.<  70.*  !\n");
    Sleep(300);
    printf("\t!51.&  52.*  53.#  54.+  55.>  56.&  57.@  58.?  59.&  60.^  !\n");
    Sleep(300);
    printf("\t!41.+  42.$  43.!  44.>  45.+  46.$  47.$  48.&  49.#  50.?  !\n");
    Sleep(300);
    printf("\t!31.>  32.^  33.>  34.@  35.<  36.+  37.?  38.!  39.^  40.$  !\n");
    Sleep(300);
    printf("\t!21.!  22.>  23.*  24.<  25.&  26.+  27.+  28.$  29.?  30.#  !\n");
    Sleep(300);
    printf("\t!11.>  12.*  13.<  14.&  15.$  16.^  17.&  18.+  19.<  20.@  !\n");
    Sleep(300);
    printf("\t!1 .@  2.#   3.?   4.#    5.&   6.*   7.!   8.@   9.+  10.+  !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");

    Sleep(500);
     ready();
    system("cls");
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           +                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);


}

mrj()
{
     minstruction();
      Sleep(500);
     system("cls");
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!91.?  92.^  93.$  94.>   95.&  96.*  97.+  98.!  99.> 100.: !\n");
    Sleep(300);
    printf("\t!81.^  82.*  83.@   84.#   85.^  86.?  87.!  88.>  89.* 90.? !\n");
    Sleep(300);
    printf("\t!71.$  72.^  73.^  74.$  75.@  76.#  77.>  78.+  79.?  80.+  !\n");
    Sleep(300);
    printf("\t!61.@  62.>  63.^  64.?  65.*  66.>  67.$  68.^  69.<  70.*  !\n");
    Sleep(300);
    printf("\t!51.&  52.*  53.#  54.^  55.>  56.&  57.@  58.?  59.&  60.^  !\n");
    Sleep(300);
    printf("\t!41.+  42.$  43.!  44.>  45.^  46.$  47.$  48.&  49.#  50.?  !\n");
    Sleep(300);
    printf("\t!31.>  32.^  33.>  34.@  35.<  36.^  37.?  38.!  39.^  40.$  !\n");
    Sleep(300);
    printf("\t!21.!  22.>  23.*  24.<  25.&  26.+  27.^  28.$  29.?  30.#  !\n");
    Sleep(300);
    printf("\t!11.>  12.*  13.<  14.&  15.$  16.^  17.&  18.^  19.<  20.@  !\n");
    Sleep(300);
    printf("\t!1 .@  2.#   3.?   4.#    5.&   6.*   7.!   8.@   9.^  10.+  !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
     ready();
    system("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           ^                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);


}



mro()
{
     minstruction();
      Sleep(500);
     system("cls");
    printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!1.?  11.^  21.$  31.>   41.&  51.*  61.+  71.!  81.* 91.:  !\n");
    Sleep(300);
    printf("\t!2.*  12.*  22.@   32.#   42.^  52.?  62.!  72.*  82.* 92.? !\n");
    Sleep(300);
    printf("\t!3.$  13.!  23.^  33.$  43.@  53.#  63.*  73.+  83.?  93.+  !\n");
    Sleep(300);
    printf("\t!4.@  14.>  24.<  34.?  44.*  54.*  64.$  74.^  84.<  94.*  !\n");
    Sleep(300);
    printf("\t!5.&  15.*  25.#  35.^  45.*  55.&  65.@  75.?  85.&  95.^  !\n");
    Sleep(300);
    printf("\t!6.+  16.$  26.!  36.*  46.?  56.$  66.$  76.&  86.#  96.?  !\n");
    Sleep(300);
    printf("\t!7.>  17.^  27.*  37.@  47.<  57.!  67.?  77.!  87.^  97.$  !\n");
    Sleep(300);
    printf("\t!8.!  18.*  28.*  38.<  48.&  58.+  68.+  78.$  88.?  98.#  !\n");
    Sleep(300);
    printf("\t!9.*  19.*  29.<  39.&  49.$  59.^  69.&  79.*  89.<  99.@  !\n");
    Sleep(300);
    printf("\t!10.@ 20.#  30.?  40.#  50.&  60.*  70.!  80.@  90.+ 100.+  !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system("cls");
    ready();

    system ("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           *                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);


}


mru()
{
     minstruction();
      Sleep(500);
     system("cls") ;
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!91.?  81.@  71.$  61.>  41.&  51.*  31.+  21.!  11.>  1.:   !\n");
    Sleep(300);
    printf("\t!92.*  82.*  72.@  62.#  42.^  52.?  32.!  22.>  12.*  2.?   !\n");
    Sleep(300);
    printf("\t!93.$  83.!  73.^  63.@  43.@  53.#  33.>  23.+  13.?   3.+  !\n");
    Sleep(300);
    printf("\t!94.@  84.>  74.<  64.?  44.*  54.@  34.$  24.^  14.<   4.*  !\n");
    Sleep(300);
    printf("\t!95.&  85.*  75.#  65.^  45.@  55.&  35.@  25.?  15.&   5.^  !\n");
    Sleep(300);
    printf("\t!96.+  86.$  76.!  66.>  46.?  56.$  36.@  26.&  16.#   6.?  !\n");
    Sleep(300);
    printf("\t!97.>  87.^  77.>  67.@  47.<  57.!  37.?  27.@  17.^   7.$  !\n");
    Sleep(300);
    printf("\t!98.!  88.>  78.*  68.<  48.&  58.+  38.+  28.$  18.@   8.#  !\n");
    Sleep(300);
    printf("\t!99.>  89.*  79.<  69.&  49.$  59.^  39.&  29.*  19.<   9.@  !\n");
    Sleep(300);
    printf("\t!100.@ 90.#  80.?  70.#  50.&  60.*  40.!  30.@  20.+   10.+ !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
     ready();
    system("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           @                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);

}

mrb()
{
     minstruction();
      Sleep(500);
     system("cls");
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!1. ?   2.^   3.$   4.>    5.&   6.*   7.+   8.!   9.?  10.:   !\n");
    Sleep(300);
    printf("\t!11.*  12.*  13.@   14.#   15.^  16.?  17.!  18.?  19.* 20.? !\n");
    Sleep(300);
    printf("\t!21.$  22.!  23.^  24.$  25.@  26.#  27.?  28.+  29.?  30.+  !\n");
    Sleep(300);
    printf("\t!31.@  32.>  33.<  34.?  35.*  36.?  37.$  38.^  39.<  40.*  !\n");
    Sleep(300);
    printf("\t!41.&  42.*  43.#  44.^  45.?  46.&  47.@  48.?  49.&  50.^  !\n");
    Sleep(300);
    printf("\t!51.+  52.$  53.!  54.?  55.?  56.$  57.$  58.&  59.#  60.?  !\n");
    Sleep(300);
    printf("\t!61.>  62.^  63.?  64.@  65.<  66.!  67.?  68.!  69.^  70.$  !\n");
    Sleep(300);
    printf("\t!71.!  72.?  73.*  74.<  75.&  76.+  77.+  78.$  79.?  80.#  !\n");
    Sleep(300);
    printf("\t!81.?  82.*  83.<  84.&  85.$  86.^  87.&  88.*  89.<  90.@  !\n");
    Sleep(300);
    printf("\t!91.@  92.#  93.?  94.#  95.&  96.*  97.!  98.@  99.+ 100.+  !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
    ready();
    system("cls");

     Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           ?                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);

}


mrv()
{
     minstruction();
      Sleep(500);
     system("cls") ;
     printf("\n\n\n\n\n\t***************************************************************\n");
    Sleep(300);
    printf("\t***************************************************************\n");
    Sleep(300);
    printf("\t!91.?  81.$  71.$  61.>  41.&  51.*  31.+  21.!  11.>  1.:   !\n");
    Sleep(300);
    printf("\t!92.*  82.*  72.$  62.#  42.^  52.?  32.!  22.>  12.*  2.?   !\n");
    Sleep(300);
    printf("\t!93.$  83.!  73.^  63.$  43.@  53.#  33.>  23.+  13.?   3.+  !\n");
    Sleep(300);
    printf("\t!94.@  84.>  74.<  64.?  44.*  54.$  34.$  24.^  14.<   4.*  !\n");
    Sleep(300);
    printf("\t!95.&  85.*  75.#  65.^  45.$  55.&  35.@  25.?  15.&   5.^  !\n");
    Sleep(300);
    printf("\t!96.+  86.$  76.!  66.>  46.?  56.$  36.$  26.&  16.#   6.?  !\n");
    Sleep(300);
    printf("\t!97.>  87.^  77.>  67.@  47.<  57.!  37.?  27.$  17.^   7.$  !\n");
    Sleep(300);
    printf("\t!98.!  88.>  78.*  68.<  48.&  58.+  38.+  28.$  18.$   8.#  !\n");
    Sleep(300);
    printf("\t!99.>  89.*  79.<  69.&  49.$  59.^  39.&  29.*  19.<   9.$  !\n");
    Sleep(300);
    printf("\t!100.@ 90.#  80.?  70.#  50.&  60.*  40.!  30.@  20.+   10.+ !\n");
    Sleep(300);
    printf("\t**************************************************************\n");
    Sleep(300);
    printf("\t**************************************************************\n");


    getch();
    system ("cls");
    ready();
    system ("cls");
    Sleep(500);
                     printf("\n\n\n\n\n\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                     Your symbol is                        !\n");
                     Sleep(300);
                     printf("\t!                                                           !\n");
                     Sleep(300);
                     printf("\t!                           $                               !\n");
                     Sleep(300);
                     printf("\t!                 can't believe this                        !\n");
                     Sleep(300);
                     printf("\t!                 TRY AGAiN press 'Y'                       !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);

}
void mindreader()
{
    int i;
    char b;
    printf("\n\n\n\n\n\t************************************************************\n");
    Sleep(300);
    printf("\t************************************************************\n");
    Sleep(300);
    printf("\t!              Your mind is under surveillance              !\n");
    Sleep(300);
    printf("\t!                                                           !\n");
    Sleep(300);
    printf("\t!                 please think positive                     !\n");
    Sleep(300);
    printf("\t!                                                           !\n");
    Sleep(300);
    printf("\t!                                                           !\n");
    Sleep(300);
    printf("\t!                                                           !\n");
    Sleep(300);
    printf("\t************************************************************\n");
    Sleep(300);
    printf("\t************************************************************\n");
    Sleep(300);
    getch();
    reep:
    system("cls");
    i=rand()%9;
    switch (i)
    {
    case 1:
         Sleep(500);
        mra();
        break;
    case 2:
         Sleep(500);
        mre();
        break;
    case 3:
         Sleep(500);
        mri();
        break;
    case 4:
         Sleep(500);
        mro();
        break;
    case 5:
         Sleep(500);
        mru();
        break;
    case 6:
         Sleep(500);
        mrb();
        break;
    case 7:
         Sleep(500);
        mrv();
        break;
    case 8:
         Sleep(500);
        mri();
        break;
    case 9:
         Sleep(500);
        mrf();
        break;
    }

   if (toupper(getch())=='Y') goto reep;

   else
    gotomenu();


}




about()
{
      system("cls");
                printf("\t\t\t\t*ABOUT ");
                Sleep(400);
                       printf("GAME*\n\n");
                Sleep(500);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t!This project is all about math.Those who are afraid of math!\n");
                     Sleep(300);
                     printf("\t!they should use this. By using this app,they can improve   !\n");
                     Sleep(300);
                     printf("\t!their math  skill.                                         !\n");
                     Sleep(300);
                     printf("\t!I have also added mind reading system.it is magic of math  !\n");
                     Sleep(300);
                     printf("\t!I think this project will increase your curiousity level   !\n");
                     Sleep(300);
                     printf("\t!for math                                                   !\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     printf("\t************************************************************\n");
                     Sleep(300);
                     getch();

                gotomenu ();

}


setting()
{
                 int x2;
                 mainhome:
                 printf("\n\n\n\n\n\t\t\t   ************************\n");
                 printf("\t\t\t   ************************\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   *  1.color             *\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   *                      *\n");
                 printf("\t\t\t   ************************\n");
                 printf("\t\t\t   ************************\n");

                 printf("\t\t\t    Choose your Options :");
                 x2=getch();
                 system ("cls");
                 //.........Theme Color Change.........
                 if(x2=='1')
                 {
                     choice:
                     printf("\n\n\n\n\n\t\t\t   ************************\n");
                     printf("\t\t\t   ************************\n");
                     printf("\t\t\t   *                      *\n");
                     printf("\t\t\t   *  1. Blue             *\n");
                     printf("\t\t\t   *  2. Green            *\n");
                     printf("\t\t\t   *  3. Red              *\n");
                     printf("\t\t\t   *  4. purple           *\n");
                     printf("\t\t\t   *                      *\n");
                     printf("\t\t\t   ************************\n");
                     printf("\t\t\t   ************************\n");
                     int select;
                     printf("\n\t\t\t   FOR EXIT PRESS 'E' ");
                     printf("\n\t\t\t   enter your choice: ");
                     select=getch();

                     switch(select)
                     {
                     case '1':
                        system("color 1");
                        system("cls");
                        goto choice ;
                        break ;
                     case '2':
                        system("color 2");
                        system("cls");
                        goto choice ;
                        break;
                     case '3':
                        system ("color 4");
                        system("cls");
                        goto choice ;
                        break;
                     case '4':
                        system("color 5");
                        system("cls");
                        goto choice ;
                        break;
                     case 'e':

                        gotomenu();
                        break;

                     default :
                            //system("cls");

                       //printf("\n\t\t\t\tWRONG\n\t\t\t\tplease enter again");
                       error();
                        Sleep(500);
                        system("cls");
                        goto choice ;
                     }

                 }
                 else {
                        system("cls");
                       goto mainhome ;
                      }
                 gotomenu();



}

menu()
{


  char i;

    feat();
    mahome:
    printf("\n\n\t\t\tEnter your choice: ");
    i=getch();
    switch(i)
    {
    case '1':
        system("cls");
        quiz();
        break;
    case '2':
        system("cls");
        mindreader();
        break;
    case '3':
        system("cls");
        about ();
        break ;
    case '4':
        system ("cls");
        setting();
        break ;
    case '5':
        system("cls");
        vai() ;
        break;
    case '6':
        system("cls");
        bahir ();
        break;
    default :
        Sleep(100);
        error();
        system ("cls");
        feat();
      goto mahome ;
        break;


    }

}


 void   vai()
    {
        int i,x;
        hp:

   printf("\n\n\n\t\t\t*********************************************************");
   printf("\n\t\t\t*\t\t\tPLAY WITH MATH\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t1.ADMIN MENU\t\t\t\t\t*");
   printf("\n\t\t\t*\t2.USER MENU\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*********************************************************");



       i=getch();
       if(i=='1')
       {
           system("cls");
           printf("\n\n\n\t\t\t*********************************************************");
   printf("\n\t\t\t*\t\t\tPLAY WITH MATH\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t1.REGISTRATION\t\t\t\t\t*");
   printf("\n\t\t\t*\t2.LOGIN\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*\t\t\t\t\t\t\t*");
   printf("\n\t\t\t*********************************************************");
   x=getch();
   if(x=='1') {
       system("cls");
        registe();
        }
    else {
        system("cls");
        adlogin();
    }

          // admin();
       }
       else if (i=='2')
       {
            system("cls");
        menu ();
       }
       else
       {
           error();
           system("cls");
           goto hp;
       }

   }
main()
{
    vai();
}
