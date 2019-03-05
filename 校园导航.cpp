#define INFINITY 10000 
#define MAX_VERTEX_NUM 40
#define MAX 40
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 

typedef struct ArCell 
{ 
int adj; /*·������ */
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

typedef struct /*ͼ�ж����ʾ��Ҫ�ص�,��ŵص�ı�š����ơ�������Ϣ, */
{ 
char name[30]; 
int num; 
char introduction[100];/*���*/ 
}infotype; 
typedef struct 
{ 
infotype vexs[MAX_VERTEX_NUM]; 
AdjMatrix arcs; 
int vexnum,arcnum; 
}MGraph; 
MGraph b; 

void cmd(void); 
MGraph InitGraph(void); 
void show1();
void list();
void Menu(void); 
void ShortestPath_DIJ(MGraph * G); 
void Search(MGraph *G); 
int LocateVex(MGraph *G,char* v);  
/**********������************************/ 
  main() 
{ 
cmd(); 
} 
/********�Զ��庯��***************/ 
   /* cmd����(����Ŀ¼ѡ��Ҫ���е���Ŀ)*/
void cmd(void) 
{ 
char k; 
b=InitGraph(); 
show1();
Menu(); 
while(1) 
{ 
scanf("\n%c",&k); 
switch(k) 
{ 
case 'x':
	system("cls");
	show1(); 
	Menu();
    list();
    ShortestPath_DIJ(&b);
    printf("---------------------------------��ӭ����ʹ��--------------------------------\n");
    printf("\n��������ѡ�����:");
	break; 
case'y':
	system("cls");
	Menu(); 
	list();
	Search(&b);
	printf("---------------------------------��ӭ����ʹ��--------------------------------\n");
    printf("\n��������ѡ�����:");
	break; 
case 'z':
 system("cls");
printf("               ��������������������������������������������\n");  
printf("               ��                ��лʹ��                ��\n"); 
printf("               ��              ��������ѧ              ��\n"); 
printf("               ��                ����ϵͳ                ��\n"); 
printf("               ��������������������������������������������\n"); 
 exit(0); 
 default:
 printf("������Ϣ����\n������x��y��z.\n"); 
 break;} }
 } 




/* �Ͻ�˹�����㷨���������㵽��������֮������·��,v0Ϊ��� */
void ShortestPath_DIJ(MGraph * G) 
{ 
int v,w,i,min,t=0,x,flag=1,v0,v1,have[100],k; 
int final[20], D[20], p[23][23]; 
while(flag) 
{ 
   printf("��������ʼλ�ñ��:\n"); 
   scanf("%d",&v0);
   if(v0<0||v0>G->vexnum) 
     printf("λ�ñ�Ų�����!");
     
   printf("�������յ�λ�ñ��:\n"); 
   scanf("%d",&v1);
   if(v1<0||v1>G->vexnum) 
     printf("λ�ñ�Ų�����!");
     
   if(v0>=0&&v0<G->vexnum&&v1>=0&&v1<G->vexnum)
   flag=0;
}
	for(v=0;v<G->vexnum;++v)
	{
		final[v]=0;
		D[v]=G->arcs[v0][v].adj;
		for(w=0;w<G->vexnum;++w)
			p[v][w]=INFINITY;
		if(D[v]<INFINITY)
		{
			p[v][v0]=1;
			p[v][v]=1;
		}
	}
	D[v0]=0;
	final[v0]=1;
	have[0]=v0;
	for(i=1;i<G->vexnum;++i)
	{
		min=INFINITY;
		for(w=0;w<G->vexnum;++w)
			if(!final[w])
				if(D[w]<min) 
				{
					v=w;
					min=D[w];
				}
		final[v]=1;
		have[k]=v;
		k++;
		for(w=0;w<G->vexnum;++w)
			if(!final[w]&&((min+(G->arcs[v][w].adj))<D[w]))
			{
				D[w]=min+G->arcs[v][w].adj;
				for(x=0;x<G->vexnum;x++)
					p[w][x]=p[v][x];
				p[w][w]=1;
			}
	}
	for(i=0;i<G->vexnum;i++)
	{
		if(p[v1][have[i]]==1){
		  printf("-->%s",G->vexs[have[i]].name);}
	}
	if((v1-v0)==1)printf("\n·������:%d\n",G->arcs[v0][v1]);
	else printf("\n·������:%d\n",D[v1]);
	
}//ShortestPath_DIJ end

/*���Һ����Ľ��� */
void Search(MGraph *G) 
{ 
int k,flag=1; 
while(flag) 
{ 
printf("������Ҫ��ѯ��λ�ñ��:"); 
scanf("%d",&k); 
if(k<0||k>G->vexnum) 
{ 
printf("λ�ñ�Ų�����!����������λ�ñ��:"); 
scanf("%d",&k); 
} 
if(k>=0&&k<G->vexnum) 
flag=0; 
} 
printf("�������ש����������������ש�����������������������������������������������������������\n"); 
printf("����ũ��ص�����        �����                                                      ��\n"); 
printf("��%-4d��%-16s��%-58s��\n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction); 
printf("�������ߩ����������������ߩ�����������������������������������������������������������\n"); 
}//Search end

void show1()
{   printf("\n");
    printf("\t\t             ��������ѧ����ϵͳ              \n");
    printf("\n");
	printf("\t\t           ��������ѧ���԰�ƽ��ͼ\n\n");
	printf("\t            ������������רҵ��ѧ¥�� ������������\n"); 
	printf("\t            ��               ��                ��\n");
	printf("\t            ��               ��                ��\n");
	printf("\t         ѧУ���� �������� ͼ��� �������� ѧУ����\n");
	printf("\t            ��               ��                ��\n");
	printf("\t            ��               ��             ������\n");
	printf("\t         �ۺ�¥C             ��                ��\n");
	printf("\t         �ۺ�¥B             ��                ��\n");
	printf("\t         �ۺ�¥A             ��                ��\n");
	printf("\t            ��               ��                ��\n");
	printf("\t         ��ٳ�              ��                ��\n");
	printf("\t            ��               ��                ��\n");
	printf("\t         �շ��� ������������ �� ������������ �ٺ�\n");
	printf("\t            ��               ��                ��\n");
	printf("\t        ��ë���             ��                ��\n");
	printf("\t            ��               ��                ��\n");
    printf("\t            ��               ��              ���� \n");
	printf("\t            ��               ��                ��\n");
	printf("\t            ��               ��                ��\n");
	printf("\t            ��               ��            ѧ��ʳ��\n");
	printf("\t          ����               ��                ��  \n");
	printf("\t            ��               ��                ��\n");
	printf("\t            ��               ��                ��\n");
	printf("\t            ������������ ѧ��������  ������������\n");
	
} 
 void list()
 {
 printf("ѧУλ���б�:\n");
 printf("0:ѧУ����");
 printf("1:ѧУ���� ");
 printf("2:ͼ��� ");
 printf("3:������ ");
 printf("4:�ۺ�¥A");
 printf("5:�ۺ�¥B");
 printf("6:�ۺ�¥C");
 printf("7:��ٳ�");
 printf("8:�շ���");
 printf("9:�ٺ�");
 printf("10:����");
 printf("11:ѧ��ʳ��");
 printf("12:��ë���");
 printf("13:����");
 printf("14:רҵ��ѧ¥��");
 printf("15:ѧ��������");
 }
/*Ŀ¼�����Ĺ���*/
void Menu() 
{ 
printf("\n ��������ѧ��ͼ����\n"); 
printf("              ��������������������������������������������\n"); 
printf("              �� x.ѡ��������Ŀ�ĵ�                   ��\n"); 
printf("              �� y.�鿴������Ϣ                         ��\n"); 
printf("              �� z.�˳�ϵͳ                             ��\n"); 
printf("              ��������������������������������������������\n"); 
printf("��ѡ�����"); 
} 
/*MGraph������ͼ�Ĺ�����*/
MGraph InitGraph(void) 
{ 
MGraph G; 
int i,j; 
G.vexnum=14; //������16��
G.arcnum=17; //������17��
for(i=0;i<G.vexnum;i++) 
G.vexs[i].num=i; 
strcpy(G.vexs[0].name,"ѧУ����"); 
strcpy(G.vexs[0].introduction,"ѧУ�����ţ����ƺ�ΰ���óԵĺܶ�"); 
strcpy(G.vexs[1].name,"ѧУ����"); 
strcpy(G.vexs[1].introduction,"ѧУ�ĵڶ������ţ�����Ҳ��ΰ����û�кóԵ�"); 
strcpy(G.vexs[2].name,"ͼ���"); 
strcpy(G.vexs[2].introduction,"ѧϰ��˯�����ĵط�"); 
strcpy(G.vexs[3].name,"������"); 
strcpy(G.vexs[3].introduction,"����ĵط�"); 
strcpy(G.vexs[4].name,"�ۺ�¥A"); 
strcpy(G.vexs[4].introduction,"�Ͽεĵط�"); 
strcpy(G.vexs[5].name,"�ۺ�¥B"); 
strcpy(G.vexs[5].introduction,"������ˣ�ĵط�"); 
strcpy(G.vexs[6].name,"�ۺ�¥C"); 
strcpy(G.vexs[6].introduction,"�Ͽεĵط�"); 
strcpy(G.vexs[7].name,"��ٳ�"); 
strcpy(G.vexs[7].introduction,"��ѵ���˶���"); 
strcpy(G.vexs[8].name,"�շ���"); 
strcpy(G.vexs[8].introduction,"�˶��������ſ���ĵط�"); 
strcpy(G.vexs[9].name,"�ٺ�"); 
strcpy(G.vexs[9].introduction,"���㣬����"); 
strcpy(G.vexs[10].name,"����"); 
strcpy(G.vexs[10].introduction,"������"); 
strcpy(G.vexs[11].name,"ѧ��ʳ��"); 
strcpy(G.vexs[11].introduction,"�Է��ĵط�"); 
strcpy(G.vexs[12].name,"��ë���");
strcpy(G.vexs[12].introduction,"����ë����������ĵط�"); 
strcpy(G.vexs[13].name,"����");
strcpy(G.vexs[13].introduction,"������ϴ�裬ϴ�·����������۾��ĵط�"); 
strcpy(G.vexs[14].name,"רҵ��ѧ¥��");
strcpy(G.vexs[14].introduction,"��רҵ�εĵط�"); 
strcpy(G.vexs[15].name,"ѧ��������");
strcpy(G.vexs[15].introduction,"����˯���ĵط�"); 
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[i][j].adj=INFINITY; 
 G.arcs[0][2].adj=20;
 G.arcs[0][3].adj=15;
 G.arcs[0][14].adj=30;
 G.arcs[1][2].adj=20;
 G.arcs[1][6].adj=40;
 G.arcs[1][14].adj=30;
 G.arcs[2][8].adj=100;
 G.arcs[2][9].adj=95;
 G.arcs[2][14].adj=35;
 G.arcs[2][15].adj=10;
 G.arcs[3][9].adj=60;
 G.arcs[4][7].adj=30;
 G.arcs[4][5].adj=5;
 G.arcs[5][6].adj=5;
 G.arcs[7][8].adj=15;
 G.arcs[8][9].adj=15;
 G.arcs[8][12].adj=20;
 G.arcs[8][15].adj=100;
 G.arcs[9][10].adj=30;
 G.arcs[10][11].adj=55;
 G.arcs[11][15].adj=60;
 G.arcs[12][13].adj=60;
 G.arcs[13][15].adj=40;
for(i=0;i<G.vexnum;i++) 
for(j=0;j<G.vexnum;j++) 
G.arcs[j][i].adj=G.arcs[i][j].adj; 
return G; 
}//InitGraph end  

