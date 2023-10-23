#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
# define MS (157.2)*5
#include<ctype.h>

//global variables
int xline1,xline2,trackLength,readhighscore=0;
long int score;
char msg[100];
struct enemycarPosition{
	int x1,x2,y1,y2;
} e;
struct mycarPosition{
	int x1,x2,y1,y2;
} m;
struct enemycarPosition1{
	int x1,x2,y1,y2;
} e1;

struct highsc{
	char name[20];
	long int hscore;
}h[5];

struct colors{
	int bgcolor;
	int textcolor;
	int ingame_bgcolor1;
	int ingame_bgcolor2;
	int ingame_textcolor;

}c;
int carShape;
struct previous_player{
    char name[20];
    int len;
}pp;

//user-defined functions
void setgraphics();//set the graphics
void startgame();//start game
void loadingscreen();//show loading screen
void mainmenu();//show main menu
void draw(long int,int);//draw path, display score and speed
void mycar(int);//spawn player car accord to car position
void enemycar(int *);//spawn and move enemy car 1
void enemycar1(int *);//spawn and move enemy car 2
int collisionDetection(struct mycarPosition mc,struct enemycarPosition ec);//check collision detection of enemy car 1 with player car
int collisionDetection1(struct mycarPosition mc,struct enemycarPosition1 ec);//check collision detection of enemy car 2 with player car
int scoreincrease(long int,int);//increase player car speed accord to score
void pause();//show paused screen
void gameover(long int);//show game over screen
void displayControls();//display player controls
void showHighscores();//display highscores
void readHighscore();//read highscores from file
void showCredits();//show credits screen
void takeuserdetails(long int);//take user details
int updateHighscore();//update the highscores in file
int checkifscoredHigh(long int);//check if player scored high
int readgamedata();//read current game data
void defaultColor();//set default color
void colorSelect(int ,int);//set color
int updategamedata();//update current game data
void customize();//show customize screen
void customizeCar();//show customize car screen
void customizeTheme();//show customize theme screen
void resetsettings();//reset all settings to default
void resetgamedata();//reset game data to default
void resetHighscore();//reset highscore to 0
int gamec();

void game();
//for circle
float speed=50;
int sb1=700,sb2=100,sb3=1000,sb4=500;
int f1=25,f2=25;
int x=25,y=25,r=12;
int blx=10,bly=10,bls=10,score1=0;
// for bars
int x2=100,y2=340,rndx,rndy;
int x3=200,y3=380,rndx3,rndy3;
int x4=300,y4=300,rndx4,rndy4;
int x5=200,y5=380,rndx5,rndy5;
int gdriver=DETECT,gmode;
int a,hl=1,ttr=0;
int stack[5]={383,356,329,302,275},j=4,n=5,k=0,bcol=475;
int stack2[12]={383,356,329,302,275,248,221,194,167,140,113,86},n2=0,k2=0,bcol2=575,j2=0;
void move(int a);
void logo(void);
void codding(int score1);
void randomstar(void);
void won(void);
void gover(void);
void security(void);
void main2(void);
void mouse(void);
// mouse functions prototypes
void initmouse();
void showmp();
void hidemp();
int getmp(int *button,int *x,int *y);
void setmp();
int screen();
void button(int x1,int y1,int x2,int y2,char str[]);
int click(int x1,int y1,int x2,int y2,char str[]);
int press(int,int,int,int);
int unpress(int,int,int,int);
void sound1();
void instruction();



void home();
void main()
{
	int count,r,r1,i,n,j;

	int gd=DETECT,gm;

		   // gamec();

	home();


     count=0;
    int marks=0;
     for(i=1;i<=13;i++)     {
    system("cls");
     r1=i;

     if (count==5||marks==50)
     {
	game();
     }
     else if(count==10||marks==100)
     {
	gamec();
     }

     initgraph(&gd,&gm,"C://turboc3//bgi");
      setbkcolor(BROWN);
     switch(r1)
	{

		case 1:
	       outtextxy(120,170,"1. Which of the following is a Palindrome number?");
	       outtextxy(150,200,"A.42042                  B.101010");
	       outtextxy(150,230,"C.23232                  D.01234");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);
		      setcolor(GREEN);

		      outtextxy(250,300,"Correct!!!");count++;

			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is C.23232");
		getch();
		break;
	}

	case 2:
	       outtextxy(120,170,"2. Choose the prefix form of (A+B*C)-D?");
	       outtextxy(150,200,"A. -A+(BC*)D             B.-+AB*CD");
	       outtextxy(150,230,"C.-ABC+*D                D.-+A*BCD");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;

			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is A. -A+(BC*)D");
		getch();
		break;
	}

	case 3:
	 outtextxy(90,170,"3. Choose the sorting techniques which is not stable ");
	 outtextxy(230,180,"sorting algorithm??");
	       outtextxy(150,200,"A.Insertion sort               B.Selection sort");
	       outtextxy(150,230,"C.Bubble Sort                  D.Merge Sort");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is B. Selection Sort");
		getch();
		break;
	}


	case 4:
	 outtextxy(100,170,"4. What is the worst case time complexity of binary search??");
	       outtextxy(150,200,"A.O(Nlog N)              B.O(N*N)");
	       outtextxy(150,230,"C.O(root(N))             D.O(Log N)");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is D.O(Log N)");
		getch();
		break;
	}

	case 5:

	outtextxy(130,170,"5. Select the worst case time complexity of Shell Sort ");
	outtextxy(230,190,"& Merge Sort respectively??");
	       outtextxy(150,220,"A.O(nlogn), O(N)                 B.O(logn), O(N*N)");
	       outtextxy(150,250,"C.O(n), O(logn)                 D.O(n2), O(nlogn)");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is  D.O(n2), O(nlogn)");
		getch();
		break;
	}


	 case 6:
	outtextxy(90,170,"6. What data structure is used when converting an infix notation");
	outtextxy(230,190," to prefix notation?");
	       outtextxy(150,220,"A.Stack                 B.Queue");
	       outtextxy(150,230,"C.B-Trees               D.Linked-list");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is A.Stack");
		getch();
		break;
	}



	case 7:

	outtextxy(80,170,"7. Choose the design technique used in the quick sort algorithm?");
	       outtextxy(150,200,"A.Dynamic programming                B.Backtracking");
	       outtextxy(150,230,"C.Divide-and-conquer                  D.Greedy method");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();

			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is C.Divide-and-conquer");
		getch();
		break;
	}

	case 8:

	outtextxy(80,170,"8. Which of the following properties is associated with a queue?");
	       outtextxy(130,200,"A. First In Last Out             B.First In First Out");
	       outtextxy(130,230,"C.both (a) & (b)                 D.None of above");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is  B.First In First Out");
		getch();
		break;
	}

	case 9:
	       outtextxy(120,150,"9. What are splay trees?");
	       outtextxy(130,180,"A.self adjusting binary search trees");
	       outtextxy(130,205,"B.self adjusting binary trees");
	       outtextxy(130,230,"C.a tree with strings");
	       outtextxy(130,255,"D. a tree with probability distributions");

			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(100,300,"Wrong!!! The correct answer is A.self adjusting binary search trees ");
		getch();
		break;
	}

	case 10:


	  outtextxy(80,170,"10. A B-tree of order 4 and of height 3 will have a maximum ");
	  outtextxy(230,190," of _______ keys.");
	       outtextxy(150,210,"A.255                 B.63");
	       outtextxy(150,240,"C.127                 D.188");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			 break;
		}
		else
	{
	  setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is A.255");
		getch();
		   break;

	}
      case 11:
		outtextxy(120,170,"11.What is the search complexity in direct addressing?");
	       outtextxy(150,200,"A.O(n)                B.O(logn)");
	       outtextxy(150,230,"C.O(nlogn)            D.O(1)");
			if (toupper(getch())=='C')
		{
			marks= marks+10;
			printf("\t\t\t\t\t\t\t\t\n\nMarks: %d ",marks);

		      setcolor(GREEN);
		      outtextxy(250,300,"Correct!!!");count++;
			getch();
			break;
		}
		else
	{              setcolor(YELLOW);

	      outtextxy(180,300,"Wrong!!! The correct answer is  D.O(1)");
		getch();
		break;
	}

    }

    }

	if(count<5||count<50)
	{
	    outtextxy(200,170,"YOU LOOSE THE GAME ! . ! TRY HARDER NEXT TIME");
	}
		closegraph();
	system("cls");
	//printf("\n\n\n\n\n\n\n\n\n\n\n");
    //printf("\t\t\t\t\tYour Score is :%d ",count);
    //getch();
   // score(count);

}


void home()
{
int gd=DETECT,gm;
	char dec;
	char playername[20];

	initgraph(&gd,&gm,"C://turboc3//bgi");

     setbkcolor(RED);
     printf("\n\n\n\n\n\n\t\t\t\tC PROGRAM QUIZ GAME");
     printf("\n\t\t     -------------------------------------------");

     printf("\n\t\t\t\t     WELCOME ");
     printf("\n\t\t\t\t        to ");
     printf("\n\t\t\t\t     THE GAME ");
      printf("\n\t\t     -------------------------------------------");
      printf("\n\t\t     -------------------------------------------");
     printf("\n\t\t\t     BECOME A EINSTINE!!!!!!!!!!!    ") ;
      printf("\n\t\t     -------------------------------------------");
      printf("\n\t\t     -------------------------------------------");
     printf("\n\t\t\t     Press s to start the game");
     printf("\n\t\t\t\t press q to quit             ");
      printf("\n\t\t     -------------------------------------------");
     printf("\n\t\t\tYour Decision: ");
     scanf("%c",&dec);

     getch();
	closegraph();

	if(dec=='s'|| dec=='S')
	{

	 system("cls");
	 initgraph(&gd,&gm,"C://turboc3//bgi");
	 setcolor(RED);
	 setbkcolor(YELLOW);

	outtextxy(220,200,"Resister your name:");
	scanf("%s",&playername);
	getch();
	outtextxy(50,250,"--------------  Welcome to C Program Quiz Game -----------------------");
	getch();

	system("cls");
	}
	else if(dec=='q'|| dec=='Q')
	{
		exit(1);
	}

	closegraph();

}


void game(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"c://turboc3//bgi");
	security();
	closegraph();
}
 void security(){
	int a=0,b=0,c=100;
	setcolor (RED);
	settextstyle (10,HORIZ_DIR,2);
	outtextxy (220,160,"LODDING.....\n");
	settextstyle (1,HORIZ_DIR,2);
	outtextxy (270,218,"%");
	getch();
	while (a<600){
		setcolor (WHITE);
		settextstyle (0,HORIZ_DIR,3);
		outtextxy (a,410," ");
		delay(5);
		a++;
		if (b<=100){
			gotoxy (38,15);
			printf ("%d",b);
			if (a==c||a==c+100||a==c+200||a==c+300||a==c+400||a==c+500)
				b=b+18;
		}
	}
	logo();
}

void logo(){
	cleardevice();
	setbkcolor (0);
	settextstyle (7,HORIZ_DIR,4);
	setcolor (10);
	outtextxy (280,10,"786");
	setcolor (WHITE);
	rectangle (4,50,635,90);
	rectangle (90,95,540,135);
	rectangle (130,140,500,185);
	rectangle (430,250,620,400);
	setcolor (13);
	outtextxy (55,50,"S.B.JAIN COLLEGE");
	setcolor (11);
	outtextxy (120,95,"Computer Science 2K23");
	setcolor (9);
	outtextxy (155,140,"OM SHRIKKHANDE");
	settextstyle (8,HORIZ_DIR,2);
	setcolor (14);
	outtextxy (40,290,"further Please visit given site");
	rectangle (430,200,490,235);line (430,200,490,235);line (430,235,490,200);
	setcolor (2);
	outtextxy (40,370,"vector.com");
	settextstyle (1,HORIZ_DIR,1);
	setcolor (7);
	outtextxy (440,260,"Thoughts:");
	settextstyle (3,HORIZ_DIR,1);
	outtextxy (440,300,"* Life is nothing");
	outtextxy (440,330," without struggle");
	settextstyle(1,HORIZ_DIR,1);
	setcolor(100);
	outtextxy (230,430,"press any to continue");
	getch();
mouse();
}
 void mouse(){
   initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
   cleardevice();
   initmouse();
   showmp();
   screen();
}

void initmouse(){
	union REGS i,o;
	i.x.ax=0x0;
	int86(0x33,&i,&o);
}

void showmp(){
	union REGS i,o;
	i.x.ax=0x1;

	int86(0x33,&i,&o);
}

void hidemp(){
	union REGS i,o;
	i.x.ax=0x2;
	int86(0x33,&i,&o);
}

int getmp(int *button,int *x,int *y){
	union REGS i,o;
	i.x.ax=0x3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
return 0;
}

void setmp(){
	union REGS i,o;
	i.x.ax=0x4;
	i.x.cx=150;
	i.x.dx=150;
	int86(0x33,&i,&o);
}

int screen(){
	settextstyle(1,HORIZ_DIR,7);
	setcolor(14);
	outtextxy(170,8,"Rapid Roll");
	outtextxy(240,350,"Game");
	setmp();
	button(250,100,400,150,"New Game");
	button(250,150,400,200,"Sound");
	button(250,200,400,250,"Instruction");
	button(250,250,400,300,"Developer");
	button(250,300,400,350,"Exit");
	while(1){
		if(click(250,100,400,150,"New Game")==0){
			hidemp();
			cleardevice();
			main2();
			return 0;
		}

		if(click(250,150,400,200,"Sound")==0){
			hidemp();
			cleardevice();
			sound1();
			return 0;
		}
		if(click(250,200,400,250,"Instruction")==0){
			hidemp();
			instruction();
			return 0;
		}
		if(click(250,250,400,300,"Developer")==0){
			hidemp();
			cleardevice();
			logo();
			return 0;
		}
		if(click(250,300,400,350,"Exit")==0)
			exit(0);
	}
}

void button(int x1,int y1,int x2,int y2,char str[]){
	int xc,yc,i1=0,l1=0;
	while(i1<strlen(str)){
		l1+=4;
		i1++;
	}
	xc=(x2-x1)/2+x1-l1;
	yc=(y2-y1)/2+y1;
	unpress(x1,y1,x2,y2);
	settextstyle(0,0,0);
	setcolor(11);
	outtextxy(xc,yc,str);
}

int click(int x1,int y1,int x2,int y2,char str[]){
	int button,x,y;
	int xc,yc,i1=0,l1=0;
	while(i1<strlen(str)){
		l1+=4;
		i1++;
	}
	xc=(x2-x1)/2+x1-l1;
	yc=(y2-y1)/2+y1;
	getmp(&button,&x,&y);
	if( (x>x1 && x<x2) && (y>y1 && y<y2) && button==1){
		hidemp();
		press(x1,y1,x2,y2);
		setcolor(GREEN);
		settextstyle(0,0,0);
		outtextxy(xc,yc,str);
		showmp();
		while((button==1))
			getmp(&button,&x,&y);
		hidemp();
		unpress(x1,y1,x2,y2);
		showmp();
		setcolor(GREEN);
		settextstyle(0,0,0);
		outtextxy(xc,yc,str);
		for(i1=50;i1<500;i1=i1+50){
			delay(10);
			sound(i1+200);
		}
		showmp();
		nosound();
		setcolor(11);
		settextstyle(0,0,0);
		outtextxy(xc,yc,str);
		return 0;
	}else return 1;
}

int unpress(int x1,int y1,int x2,int y2){
	setlinestyle(0,1,1);
	setfillstyle(3,12);
	bar(x1,y1,x2,y2);
	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
return 0;
}

int press(int x1,int y1,int x2,int y2){
	setlinestyle(0,1,1);
	setfillstyle(0,3);
	bar(x1,y1,x2,y2);
	setcolor(0);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(WHITE);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
return 0;
}

void sound1(){
	int ssb;
	settextstyle(1,HORIZ_DIR,2);
	outtextxy (200,200,"Press 1 for Sound on");
	outtextxy (200,100,"Press 0 for Sound off");
	scanf ("%d",&ssb);
	if (ssb==1){
		main2();
	}else if (ssb==0){
		sb1=0;
		sb2=0;
		sb3=0;
		sb4=0;
		main2();
	}else
		mouse();
	getch();
}
void instruction(){
	FILE *fp;
	char string[20];
	closegraph();
	fp=fopen("Instructions.c","r");
	if (fp==0){
		puts ("Can't open");
		getch();
		mouse();
	}
	while (fgets(string,19,fp)!=0)
		printf ("%s",string);
	printf ("\n");
	getch();
	fclose(fp);
	mouse();
}

void main2(){
int c;
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	cleardevice();
	rndx=+x2;
	rndy=+y2;

	rndx3=+x3;
	rndy3=+y3;

	rndx4=+x4;
	rndy4=+y4;

	rndx5=+x5;
	rndy5=+y5;

	randomstar();

	codding(score1);
	while((c=getch())!='\033'){
		//right
		if (c=='\115') a=1;
		//left
		if (c=='\113') a=2;
		move (a);
		}
}

void move (int a){
	void  scorex(int f1,int f2,int ttr);
	while(!kbhit()){
	//clear remaining bars
	setfillstyle(0,0);
	bar (rndx5-198,rndy5-378,rndx5+198,rndy5-365);

	//bar codding
	setfillstyle(0,0);
	bar (rndx-25,rndy-3,rndx+25,rndy+3);
	rndy=rndy-1;
	setfillstyle(1,2);
	bar (rndx-25,rndy-3,rndx+25,rndy+3);
	if (rndy==10){
		rndy=+y2;
	}
	setfillstyle(0,0);
	bar (rndx3-25,rndy3-3,rndx3+25,rndy3+3);
	rndy3=rndy3-1;
	setfillstyle(1,2);
	bar (rndx3-25,rndy3-3,rndx3+25,rndy3+3);
	if (rndy3==10){
		rndy3=+y3;
	}
	setfillstyle(0,0);
	bar (rndx4-25,rndy4-3,rndx4+25,rndy4+3);
	rndy4=rndy4-1;
	setfillstyle(1,2);
	bar (rndx4-25,rndy4-3,rndx4+25,rndy4+3);
	if (rndy4==10){
		rndy4=+y4;
	}

	// food codding
	setfillstyle(5,14);
	bar3d(blx,bly,blx+bls,bly+bls,0,0);
	//circle codding
	setcolor (WHITE);
	circle(f1,f2,r);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(f1,f2,BLACK);

	//clear remaining circle
	bar (rndx5-198,rndy5+18,rndx5+198,rndy5-6);

	setcolor (WHITE);
	circle(f1,f2,r);
	setfillstyle(SOLID_FILL,RED);
	floodfill(f1,f2,WHITE);
	setcolor(0);

	if ((f2==rndy-18) && (f1==75 || f1==85 || f1==95 || f1==105 || f1==115 || f1==125))
	{
	f2=f2-1;
	}
	else if ((f2==rndy4-18) && (f1==275 || f1==285 || f1==295 || f1==305 || f1==315 || f1==325))
	{
	f2=f2-1;
	}
	else if ((f2==rndy3-18)&& (f1==175 || f1==185 || f1==195 || f1==205 || f1==215 || f1==225)){
	f2=f2-1;
	}else
	f2=f2+1;
	delay(speed);
	 scorex (f1,f2,ttr);
	if (f2==387)
	{
	f2=25;
	ttr++;
	}
	else if (f2==14){
		f2=25+1;
		ttr++;
	}

	}
	if(a==1)f1=f1+5;
	if(a==2)f1=f1-5;

	if (f1==10) f1=20;
	if (f1==390) f1=385;
}

void scorex (int f1,int f2,int ttr){
	while (k<n-ttr){
		setcolor (WHITE);
		circle(bcol,stack[k],r);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(bcol,stack[k],WHITE);
		k++;
	}
	if (f2==383 || f2==14){
		setcolor (BLACK);
		circle(bcol,stack[j],r);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(bcol,stack[j],BLACK);
		j--;
		sound(sb4);
		delay(50);
		nosound();
		if (j==-1){
			sound(sb2);
			delay(100);
			nosound();
			gover();
		}
	}
	if ((f2==bly || f2+11==bly || f2-11==bly) && (f1==blx+5 || f1+11==blx+5 || f1-11==blx+5)){
		sound(sb3);
		delay(50);
		score1+=2;
		nosound();
		codding (score1);
	if (score1==10){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==20){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==30){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==40){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==50){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==60){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==70){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==80){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==90){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==100){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==110){
		j2++;
		n2=j2;
		sound(sb1);
		delay(70);
		nosound();
		speed=speed-3.75;
	}else if (score1==120){
		j2++;
		n2=j2;
		sound(sb1);
		delay(100);
		nosound();
		speed=speed-3.75;
	}else if (score1>120){
		won ();
	}
	randomstar();
	}

	while (k2<n2){
		setcolor (WHITE);
		circle(bcol2,stack2[k2],r);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(bcol2,stack2[k2],WHITE);
		k2++;
	}
}

void randomstar(){
	int ic=0,pr=0;
	randomize();
	ic=random(10000)%40;
	ic=ic*bls;
	pr=random(10000)%40;
	pr=pr*bls;
	blx=ic;
	bly=pr;

	if ((bly<30) || (bly>350)){
		bly=40;
	}
	if ((blx<30) || (blx>383)){
		blx=20;
	}
}
void codding (int score1){
	setcolor (WHITE);
	rectangle(0,0,400,400);
	gotoxy (60,5);
	circle (480,70,30);
	setcolor (WHITE);
	printf ("%d ",score1);
//Bonus
	setcolor (7);
	outtextxy (455,165,"BONUS");
	setcolor (WHITE);
	line (500,200,500,400);line (450,200,450,400);line (450,400,500,400);
//Score
	setcolor (7);
	outtextxy (550,25,"SCORE");
	outtextxy (550,40,"10 = 1");
	setcolor (WHITE);
	line (600,60,600,400);line (550,60,550,400);line (550,400,600,400);
}

void won (){
	cleardevice();
	rectangle (40,100,100,135);line (40,100,100,135);line (40,135,100,100);
	settextstyle (7,HORIZ_DIR,5);setcolor (GREEN);
	outtextxy (135,150,"Congratulation!");
	outtextxy (150,200,"You won the GAME");
	settextstyle (7,HORIZ_DIR,1);setcolor (YELLOW);
	outtextxy (300,300,"By: SindhiTutorials.com");
	setcolor (7);
getch();
exit(0);
}

int gamec(){
	setgraphics();
	x=getmaxx();
	y=getmaxy();
	if (readgamedata()==0){//if game is launched first time
				resetgamedata();
	}else
	defaultColor();
	loadingscreen();
	mainmenu();
	closegraph();
	return 0;


}
void gover(){
cleardevice();
	rectangle (40,100,100,135);line (40,100,100,135);line (40,135,100,100);
	settextstyle (7,HORIZ_DIR,5);setcolor (RED);
	outtextxy (200,200,"GAME OVER");
	settextstyle (7,HORIZ_DIR,1);setcolor (YELLOW);
	outtextxy (300,300,"By: VECTORs.com");
getch();
mouse();
}

void defaultColor(){
	setbkcolor(c.bgcolor);
	setcolor(c.textcolor);
}
void colorSelect(int a,int b){
	setbkcolor(a);
	setcolor(b);
}
void setgraphics() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://turboc3//bgi");
}

void loadingscreen(){
	int i=0;
	cleardevice();
	settextstyle(4,0,5);
	outtextxy(x/2-200,y/2,"A 2D Car Racing Game");
	delay(1000);

	settextstyle(3,0,1);
	outtextxy(x/2-100,y-120,"LOADING....");

	while (i!=200){
		rectangle(x/2-100,y-85,x/2-100+i,y-75);
		rectangle(x/2-100,y-85,x/2+100,y-75);
		i++;
		delay(10);
	}
}

void mainmenu(){
	int selection=0;

	cleardevice();

	settextstyle(3,0,3);
	defaultColor();


	while(1){
		cleardevice();

		score=0;//initial score
		speed=1;//initial speed


		outtextxy(x/2-100,100,"Play");
		outtextxy(x/2-100,150,"Controls");
		outtextxy(x/2-100,200,"HighScores");
		outtextxy(x/2-100,250,"Customize");
		outtextxy(x/2-100,300,"Credits");
		outtextxy(x/2-100,350,"Exit");
		circle(x/2-110,125,5);
		circle(x/2-110,175,5);
		circle(x/2-110,225,5);
		circle(x/2-110,275,5);
		circle(x/2-110,325,5);
		circle(x/2-110,375,5);

		setfillstyle(SOLID_FILL,c.textcolor);
		floodfill(x/2-110,125+50*selection,c.textcolor);

		switch(getch()){
			case 'W':
			case 'w':
				if (selection==0)
					selection=5;
				else
					selection--;
				break;
			case 's':
			case 'S':
				if (selection==5)
					selection=0;
				else
					selection++;
				break;
			case 13://enterkey - CR
				if (selection==0){
					startgame();
				}
				else if(selection==1){
					displayControls();
				}
				else if(selection==2){
					showHighscores();
				}
				else if(selection==3){
					customize();
				}
				else if (selection==4){
					showCredits();
				}
				else {
					exit(0);
				}

				break;
			default:
				break;
		}

	}
}


void startgame(){
	int i,mycarLocation,collision=0,activateEnemy1=0;
	int *enemycarPos,*enemycarPos1;

	cleardevice();
	randomize();
	defaultColor();

	for(i=3;i!=0;i--){
		cleardevice();
		sprintf(msg,"Starting in %d...",i);
		outtextxy(x/2-50,100,msg);
		delay(500);
	}

	colorSelect(c.ingame_bgcolor1,c.ingame_textcolor);
	settextstyle(0,0,1);
	xline1=x/2-75;
	xline2=x/2+75;
	trackLength=xline2-xline1;
	mycarLocation=random(100)%3;
	*enemycarPos=0;
	*enemycarPos1=0;

	while(1){
		cleardevice();
		draw(score,speed);
		enemycar(enemycarPos);
		if (activateEnemy1==1){
			enemycar1(enemycarPos1);
			*enemycarPos1=*enemycarPos1+speed+1;
			collision=collisionDetection(m,e)+collisionDetection1(m,e1);
		}else
			collision=collisionDetection(m,e);

		mycar(mycarLocation);


		if (collision==1){
			gameover(score);
		}


		if(kbhit()){
			switch(getch()){
				case 'A':
				case 'a':
					if(mycarLocation!=0)
						mycarLocation--;
					break;
				case 'd':
				case 'D':
					if(mycarLocation!=2)
						mycarLocation++;
					break;
				case 'p':
				case 'P':
					pause();
					break;
				case 'X':
				case 'x':
					exit(0);
					break;
				default:
					break;


			}
		}
		*enemycarPos=*enemycarPos+speed+1;
		score=score+speed*1;
		if (*enemycarPos>y/2)
			activateEnemy1=1;
	      // 	speed=speedincrease(score,speed);//increase speed
		delay(10);

	}
}

void mycar(int carLocation){
	m.x1=xline1+(trackLength/3*carLocation)+3;
	m.x2=xline1+(trackLength/3*(carLocation+1))-3;
	m.y1=y-3;
	m.y2=y-50;
	if (carShape==0){//default shape

		rectangle(m.x1,m.y1-35,m.x2,m.y1);//big block
		rectangle(m.x1+10,m.y2+13,m.x2-10,m.y1);//middle block
		rectangle(m.x1+5,m.y2,m.x2-5,m.y2+13);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(m.x1+3,m.y2+3,m.x1+5,m.y2+13);//left tyre
		bar(m.x2-3,m.y2+3,m.x2-5,m.y2+13);//right tyre

	}
	else if (carShape==1){//rectangle shape

		rectangle(m.x1,m.y1,m.x2,m.y2);

	}else if(carShape==2){//bar

		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(m.x1,m.y1,m.x2,m.y2);

	}else if (carShape==3){//ellipse

		ellipse((m.x1+m.x2)/2,(m.y1+m.y2)/2,0,360,(m.x2-m.x1)/2,(m.y1-m.y2)/2);

	}else{//defaultShape

		rectangle(m.x1,m.y1-35,m.x2,m.y1);//big block
		rectangle(m.x1+10,m.y2+13,m.x2-10,m.y1);//middle block
		rectangle(m.x1+5,m.y2,m.x2-5,m.y2+13);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(m.x1+3,m.y2+3,m.x1+5,m.y2+13);//left tyre
		bar(m.x2-3,m.y2+3,m.x2-5,m.y2+13);//right tyre

	}
}
void enemycar(int *i){
	static int enemycarLoc;
	if (*i==0){
		enemycarLoc=random(100)%3;
		e.x1=xline1+3+(trackLength/3)*enemycarLoc;
		e.x2=xline1+(trackLength/3*(enemycarLoc+1))-3;
	}
	e.y1=*i+3;
	e.y2=*i+48;
	if (carShape==0){//default shape

		rectangle(e.x1,e.y1,e.x2,e.y1+33);//big block
		rectangle(e.x1+5,e.y1+33,e.x2-5,e.y2);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e.x1+3,e.y1+33,e.x1+5,e.y2-3);//left tyre
		bar(e.x2-5,e.y1+33,e.x2-3,e.y2-3);//right tyre
	}
	else if (carShape==1){//rectangle shape

		rectangle(e.x1,e.y1,e.x2,e.y2);

	}else if(carShape==2){//bar

		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e.x1,e.y1,e.x2,e.y2);

	}else if (carShape==3){//ellipse

		ellipse((e.x1+e.x2)/2,(e.y1+e.y2)/2,0,360,(e.x2-e.x1)/2,(e.y2-e.y1)/2);

	}else{//defaultShape

		rectangle(e.x1,e.y1,e.x2,e.y1+33);//big block
		rectangle(e.x1+5,e.y1+33,e.x2-5,e.y2);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e.x1+3,e.y1+33,e.x1+5,e.y2-3);//left tyre
		bar(e.x2-5,e.y1+33,e.x2-3,e.y2-3);//right tyre

	}


	if(e.y1>y)
		*i=-speed-1;
}

void enemycar1(int *j){
	static int enemycarLoc1;
	if (*j==0){
		enemycarLoc1=random(100)%3;
		e1.x1=xline1+3+(trackLength/3)*enemycarLoc1;
		e1.x2=xline1+(trackLength/3*(enemycarLoc1+1))-3;
	}
	e1.y1=*j+3;
	e1.y2=*j+48;
	if (carShape==0){//default shape

		rectangle(e1.x1,e1.y1,e1.x2,e1.y1+33);//big block
		rectangle(e1.x1+5,e1.y1+33,e1.x2-5,e1.y2);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e1.x1+3,e1.y1+33,e1.x1+5,e1.y2-3);//left tyre
		bar(e1.x2-5,e1.y1+33,e1.x2-3,e1.y2-3);//right tyre
	}
	else if (carShape==1){//rectangle shape

		rectangle(e1.x1,e1.y1,e1.x2,e1.y2);

	}else if(carShape==2){//bar

		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e1.x1,e1.y1,e1.x2,e1.y2);

	}else if (carShape==3){//ellipse

		ellipse((e1.x1+e1.x2)/2,(e1.y1+e1.y2)/2,0,360,(e1.x2-e1.x1)/2,(e1.y2-e1.y1)/2);

	}else{//defaultShape

		rectangle(e1.x1,e1.y1,e1.x2,e1.y1+33);//big block
		rectangle(e1.x1+5,e1.y1+33,e1.x2-5,e1.y2);//front block
		setfillstyle(SOLID_FILL,c.ingame_textcolor);
		bar(e1.x1+3,e1.y1+33,e1.x1+5,e1.y2-3);//left tyre
		bar(e1.x2-5,e1.y1+33,e1.x2-3,e1.y2-3);//right tyre

	}
	if(e1.y1>y)
		*j=-speed-1;
}

int collisionDetection(struct mycarPosition mc,struct enemycarPosition ec  ){
	if (ec.x1>mc.x2){
		return 0;
	}
	else{
		if(ec.x2<mc.x1) {
			return 0;
		}else{
			if(ec.y1>mc.y1){
				return 0;
			}else{
				if(ec.y2<mc.y2){
					return 0;
				}else{
					return 1;
				}
			}
		}
	}

}

int collisionDetection1(struct mycarPosition mc,struct enemycarPosition1 ec  ){
	if (ec.x1>mc.x2){
		return 0;
	}
	else{
		if(ec.x2<mc.x1) {
			return 0;
		}else{
			if(ec.y1>mc.y1){
				return 0;
			}else{
				if(ec.y2<mc.y2){
					return 0;
				}else{
					return 1;
				}
			}
		}
	}

}

void draw(long int sc,int sp){
	line(xline1,0,xline1,y);
	line(xline2,0,xline2,y);
	sprintf(msg, "Score : %ld ",sc);
	outtextxy(xline2+20,y/2,msg);
	sprintf(msg,"Speed: %d",sp);
	outtextxy(xline1-100,y/2,msg);

}

int speedincrease(long int sc ,int sp){

	switch(sp){
		case 1:
			if (sc>1000)
				sp++;
			break;
		case 2:
			if (sc>2000)
				sp++;
			break;
		case 3:
			if (sc>4000)
				sp++;
			break;
		case 4:
			if (sc>8000)
				sp++;
			break;
		case 5:
			if (sc>16000)
				sp++;
			break;
		case 6:
			if (sc>32000)
				sp++;
			break;
		case 7:
			if (sc>64000)
				sp++;
			break;
		case 8:
			if (sc>120000)
				sp++;
			break;
		case 9:
			if (sc>240000)
				sp++;
			break;
		default:
			break;
	}
	return sp;


}

void pause(){

	int the_end=0;

	setfillstyle(SOLID_FILL,c.ingame_bgcolor2);//darkgray

	bar(xline1,y/2-210,xline2,y/2-180);

	//pause symbol
	line(xline1+50,y/2-200,xline1+50,y/2-190);//straight line
	line(xline1+50,y/2-200,xline1+60,y/2-195);//back slash line
	line(xline1+50,y/2-190,xline1+60,y/2-195);//front slash line

	outtextxy(xline1+70,y/2-200,"Paused");
	while(!the_end){
		switch(getch()){
			case 'p':
			case 'P':
				the_end=1;
				break;
			case 'm':
			case 'M':
				mainmenu();
				break;
			case 'x':
			case 'X':
				exit(0);
				break;
			default:
				break;
		}
	}
}

void gameover(long int sc){
	setfillstyle(SOLID_FILL,c.ingame_bgcolor2);

	bar(xline1,y/2-210,xline2,y/2-180);

	outtextxy(xline1+40,y/2-200,"Game Over");
	delay(10);
	getch();
	cleardevice();
	sprintf(msg,"Score: %ld",score);
	outtextxy(10,100,msg);
	if (checkifscoredHigh(sc)==1)  {
			outtextxy(10,130,"Congrats! You made your way to the Highscore Table.");
			outtextxy(10,150,"Press any key to continue.");
			getch();
			takeuserdetails(score);
	}
	else{
		outtextxy(10,130,"Sorry! You couldn't made your way to the Highscore Table.");
		outtextxy(10,150,"Press any key to return to mainmenu.");
		getch();
	}
	mainmenu();
}


void displayControls(){
	cleardevice();
	settextstyle(3,0,4);
	outtextxy(x/2-100,100,"CONTROLS");
	settextstyle(3,0,2);
	outtextxy(100,150,"Upward");
	outtextxy(400,150,"W");
	outtextxy(100,175,"Downward");
	outtextxy(400,175,"S");
	outtextxy(100,200,"Left");
	outtextxy(400,200,"A");
	outtextxy(100,225,"Right");
	outtextxy(400,225,"D");
	outtextxy(100,250,"Pause/Resume");
	outtextxy(400,250,"P");
	outtextxy(100,275,"Direct Exit (while playing)");
	outtextxy(400,275,"X");
	outtextxy(100,300,"Mainmenu (when paused)")  ;
	outtextxy(400,300,"M");
	outtextxy(100,400,"Press any key to return to mainmenu.");

	getch();
	mainmenu();

}

void showCredits(){
	cleardevice();
	settextstyle(3,0,4);
	outtextxy(x/2-100,100,"CREDITS");
	settextstyle(3,0,2);
	outtextxy(100,150,"This game is developed by:");
	outtextxy(125,175,"-Rohan Dhimal");
	outtextxy(125,200,"-Prahlad Neupane");
	outtextxy(125,225,"-Puskar Humagain");
	outtextxy(125,250,"-Bibek Dhital");
	outtextxy(100,275,"Special thanks to: Kamal Rana Sir");

	outtextxy(100,350,"Press any key to return to mainmenu.");

	getch();
	mainmenu();

}

void showHighscores(){
	int i;
	cleardevice();

	if (readhighscore==0)
		readHighscore();

	settextstyle(3,0,4);
	outtextxy(x/2-100,100,"HighScore");

	settextstyle(3,0,3);

	for (i=0;i<5;i++){
		sprintf(msg,"%d. %s",i+1,h[i].name);
		outtextxy(100,150+i*25,msg);
		sprintf(msg,"%ld",h[i].hscore);
		outtextxy(400,150+i*25,msg);
	}

	outtextxy(100,150+i*25+100,"Press any key to return to mainmenu.");
	getch();
}

void readHighscore(){

	size_t elements_read;
	FILE *fp;
	fp=fopen("highscore.bin","rb");
	if (fp==NULL){
		resetHighscore();
	}else{

		elements_read=fread(&h,sizeof(struct highsc),5,fp);
		fclose(fp);
		if (elements_read==0){
			outtextxy(x/2-50,y/2,"Error");
			getch();
			mainmenu();
		}
		readhighscore=1;
	}

}

void takeuserdetails(long int sc){

	char inputbuf[20];
	int input_pos = pp.len;
	char c;
	int the_end = 0;

	strcpy(inputbuf,pp.name);

	 do {
		cleardevice();
		outtextxy(10,140,"Enter your name:");
		bar(10,160,300,200);

		outtextxy (15,175, inputbuf);
		c = getch();
		switch (c)
		{
			case 8: /* backspace */
			if (input_pos)
			{
				input_pos--;
				inputbuf[input_pos] = 0;
			}
			break;
			case 13: /* return */
			the_end = 1;
			break;
			case 27: /* Escape = Abort */
			inputbuf[0] = 0;
			the_end = 1;
			break;
			default:
			if (input_pos < 20-1 && c >= ' ' && c <= '~')
			{
				inputbuf[input_pos] = c;
				input_pos++;
				inputbuf[input_pos] = 0;
			}
		}
	} while (!the_end);

	strcpy(pp.name,inputbuf);
	updategamedata();


	h[4].hscore=sc;
	strcpy(h[4].name,inputbuf);
	if (updateHighscore()==0){
		outtextxy(10,220,"Unable to update Highscore.");
		outtextxy(10,240,"Press any key to return to mainmenu.");
	}else{
		outtextxy(10,220,"Highscore successfully updated.");
		outtextxy(10,240,"Press any key to return to mainmenu.");

	}




	getch();

}

int updateHighscore(){
	char ch[20];
	int i,j=4;
	long int k;
	size_t elements_written;
	FILE *fp;

	for(i=3;i>0,j>0;i--){
		if (h[j].hscore>h[i].hscore){

			k=h[j].hscore;
			h[j].hscore=h[i].hscore;
			h[i].hscore=k;

			strcpy(ch,h[j].name);
			strcpy(h[j].name,h[i].name);
			strcpy(h[i].name,ch);

			j=i;

		}else{
			break;
		}
	}

	fp=fopen("highscore.bin","wb");
	if (fp==NULL){
		return 0;
	}else{
		elements_written=fwrite(&h,sizeof(struct highsc),5,fp);
		fclose(fp);
		if (elements_written==0){
			return 0;
		}else{
			return 1;
		}

	}



}


int checkifscoredHigh(long int sc){
	if (readhighscore==0)
		readHighscore();
	if (sc>h[4].hscore)
		return 1;
	else
		return 0;
}

int readgamedata(){
	size_t elements_written;
	int n=0;
	FILE *fp;

	fp=fopen("gamedata.bin","rb");
	if (fp==NULL){
		return 0;
	}else{
		elements_written=fread(&c,sizeof(struct colors),1,fp);
		if (elements_written==0){
			return 0;
		}else{
	    n++;
		}

		elements_written=fread(&carShape,sizeof(int),1,fp);
		if (elements_written==0){
			return 0;
		}else{
			n++;
		}

		elements_written=fread(&pp,sizeof(struct previous_player),1,fp);
		if (elements_written==0){
			return 0;
		}else{
			n++;
		}

		if (n==3){
			return 1;
		}else{
			return 0;
		}

	}

}

int updategamedata(){
	FILE *fp;

	fp=fopen("gamedata.bin","wb");
	if (fp==NULL){
		return 0;
	}else{
		fwrite(&c,sizeof(struct colors),1,fp);
		fwrite(&carShape,sizeof(int),1,fp);
		fwrite(&pp,sizeof(struct previous_player),1,fp);
		return 1;
	}

}

void customize(){

	int i=0;
	while(1){
		defaultColor();
		cleardevice();
		settextstyle(3,0,4);
		outtextxy(x/2-50,100,"Customize");

		settextstyle(3,0,3);
		outtextxy(125,150,"Theme");
		outtextxy(125,200,"Car Shape");
		outtextxy(125,250,"Reset all Settings");
		outtextxy(125,300,"Return");
		circle(100,165,3);
		circle(100,215,3);
		circle(100,265,3);
		circle(100,315,3);
		setfillstyle(SOLID_FILL,c.textcolor);
		floodfill(100,165+i*50,c.textcolor);

		switch(getch()){
			case 'W':
			case 'w':
				if(i!=0)
					i--;
				break;
			case 's':
			case 'S':
				if(i!=3)
					i++;
				break;
			case 'm':
			case 'M':
				mainmenu();
				break;
			case 13:
				if (i==0)
					customizeTheme();
				else if(i==1)
					customizeCar();
				else if (i==2){
					resetsettings();
				}

				else
					mainmenu();
				break;
			default:
				break;
		}
	}

}

void customizeTheme(){

	struct colors c1;
	int i=0,j;

	c1=c;

	while(1){
		cleardevice();
		defaultColor();
		settextstyle(3,0,4);
		outtextxy(x/2-50,100,"Theme");

		settextstyle(3,0,3);
		outtextxy(125,150,"Dark Ocean");
		outtextxy(125,200,"Gray Mountain");
		outtextxy(125,250,"Return");
		circle(100,165,3);
		circle(100,215,3);
		circle(100,265,3);
		setfillstyle(SOLID_FILL,c.textcolor);
		floodfill(100,165+i*50,c.textcolor);


		if (c.bgcolor==1){
			outtextxy(400,150,"(Current Theme)");
		}else{
			outtextxy(400,200,"(Current Theme)");
		}

		switch(getch()){
			case 'W':
			case 'w':
				if(i!=0)
					i--;
				break;
			case 's':
			case 'S':
				if(i!=2)
					i++;
				break;
			case 'm':
			case 'M':
				mainmenu();
				break;
			case 13:
				if (i==2){
					customize();
				}else{
					outtextxy(100,400,"Updating");
					for (j=0;j<5;j++){
						outtextxy(300+j*10,400,".");
						delay(1000);
					}
					if (i==0){


						c.bgcolor=1;//blue
						c.textcolor=15;//white
						c.ingame_bgcolor1=0;//black
						c.ingame_bgcolor2=8;//darkgray
						c.ingame_textcolor=15;//white

					}else if (i==1){

						c.bgcolor=15;//WHITE
						c.textcolor=1;//BLUE
						c.ingame_bgcolor1=7;//lightgray
						c.ingame_bgcolor2=8;//darkgray
						c.ingame_textcolor=15;//white

					}

					if (updategamedata()==0){
						setcolor(RED);
						outtextxy(100,425,"Error try again.");
						c=c1;
					}else{
						outtextxy(100,425,"Successfully updated. Press any key.");
					}
					getch();
				break;
			default:
				break;
			}
		}

	}
}

void customizeCar(){

	int carshape;
	int i=0,j;

	carshape=carShape;

	while(1){
		cleardevice();
		defaultColor();
		settextstyle(3,0,4);
		outtextxy(x/2-50,100,"Car Shape");

		settextstyle(3,0,3);
		outtextxy(125,150,"Normal");
		outtextxy(125,200,"Rectangle");
		outtextxy(125,250,"Block");
		outtextxy(125,300,"Circle");
		outtextxy(125,350,"Return");

		circle(100,165,3);
		circle(100,215,3);
		circle(100,265,3);
		circle(100,315,3);
		circle(100,365,3);

		setfillstyle(SOLID_FILL,c.textcolor);
		floodfill(100,165+i*50,c.textcolor);

		outtextxy(400,150+carShape*50,"(Current Shape)");

		switch(getch()){
			case 'W':
			case 'w':
				if(i!=0)
					i--;
				break;
			case 's':
			case 'S':
				if(i!=4)
					i++;
				break;
			case 'm':
			case 'M':
				mainmenu();
				break;
			case 13:
				if (i==4){
					customize();
				}else{
					outtextxy(100,400,"Updating");
					for (j=0;j<5;j++){
						outtextxy(300+j*10,400,".");
						delay(1000);
					}
					carShape=i;
					if (updategamedata()==0){
						setcolor(RED);
						outtextxy(100,425,"Error try again.");
						carShape=carshape;
					}else{
						outtextxy(100,425,"Successfully updated. Press any key.");
					}
					getch();

				}
				break;
			default:
				break;
		}
	}


}

void resetsettings(){
	int i;
	cleardevice();
	defaultColor();
	outtextxy(100,100,"Resetting all settings.");
	for (i=0;i<5;i++){
		outtextxy(350+i*25,100,".");
		delay(1000);
	}

	resetHighscore();
	resetgamedata();

	outtextxy(100,125,"Successfully updated. Press any key.");
	getch();

}

void resetgamedata()
{
	c.bgcolor=1;//blue
	c.textcolor=15;//white
	c.ingame_bgcolor1=0;//black
	c.ingame_bgcolor2=8;//darkgray
	c.ingame_textcolor=15;//white


	carShape=0;//regular shape

	strcpy(pp.name,"Player");
	pp.len=6;

	updategamedata();
}

void resetHighscore(){
	int i;
	char name[20];
	FILE *fp;

	for (i=0;i<5;i++)
	{
		strcpy(h[i].name,"Player");
		h[i].hscore=0;
	}

	fp=fopen("highscore.bin","wb");
	if (fp!=NULL){
		fwrite(&h,sizeof(struct highsc),5,fp);
		fclose(fp);
	}

}
