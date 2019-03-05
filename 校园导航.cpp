#define INFINITY 10000 
#define MAX_VERTEX_NUM 40
#define MAX 40
#include<stdlib.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 

typedef struct ArCell 
{ 
int adj; /*路径长度 */
}ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 

typedef struct /*图中顶点表示主要地点,存放地点的编号、名称、简介等信息, */
{ 
char name[30]; 
int num; 
char introduction[100];/*简介*/ 
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
/**********主函数************************/ 
  main() 
{ 
cmd(); 
} 
/********自定义函数***************/ 
   /* cmd函数(根据目录选择要进行的项目)*/
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
    printf("---------------------------------欢迎您的使用--------------------------------\n");
    printf("\n请您继续选择服务:");
	break; 
case'y':
	system("cls");
	Menu(); 
	list();
	Search(&b);
	printf("---------------------------------欢迎您的使用--------------------------------\n");
    printf("\n请您继续选择服务:");
	break; 
case 'z':
 system("cls");
printf("               ┏━━━━━━━━━━━━━━━━━━━━┓\n");  
printf("               ┃                感谢使用                ┃\n"); 
printf("               ┃              沈阳理工大学              ┃\n"); 
printf("               ┃                导航系统                ┃\n"); 
printf("               ┗━━━━━━━━━━━━━━━━━━━━┛\n"); 
 exit(0); 
 default:
 printf("输入信息错误！\n请输入x或y或z.\n"); 
 break;} }
 } 




/* 迪杰斯特拉算法来计算出起点到各个顶点之间的最短路径,v0为起点 */
void ShortestPath_DIJ(MGraph * G) 
{ 
int v,w,i,min,t=0,x,flag=1,v0,v1,have[100],k; 
int final[20], D[20], p[23][23]; 
while(flag) 
{ 
   printf("请输入起始位置编号:\n"); 
   scanf("%d",&v0);
   if(v0<0||v0>G->vexnum) 
     printf("位置编号不存在!");
     
   printf("请输入终点位置编号:\n"); 
   scanf("%d",&v1);
   if(v1<0||v1>G->vexnum) 
     printf("位置编号不存在!");
     
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
	if((v1-v0)==1)printf("\n路径长度:%d\n",G->arcs[v0][v1]);
	else printf("\n路径长度:%d\n",D[v1]);
	
}//ShortestPath_DIJ end

/*查找函数的建立 */
void Search(MGraph *G) 
{ 
int k,flag=1; 
while(flag) 
{ 
printf("请输入要查询的位置编号:"); 
scanf("%d",&k); 
if(k<0||k>G->vexnum) 
{ 
printf("位置编号不存在!请重新输入位置编号:"); 
scanf("%d",&k); 
} 
if(k>=0&&k<G->vexnum) 
flag=0; 
} 
printf("┏━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"); 
printf("┃编号┃地点名称        ┃简介                                                      ┃\n"); 
printf("┃%-4d┃%-16s┃%-58s┃\n",G->vexs[k].num,G->vexs[k].name,G->vexs[k].introduction); 
printf("┗━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"); 
}//Search end

void show1()
{   printf("\n");
    printf("\t\t             沈阳理工大学导航系统              \n");
    printf("\n");
	printf("\t\t           沈阳理工大学简略版平面图\n\n");
	printf("\t            ┏━━━━━专业教学楼区 ━━━━━┓\n"); 
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t         学校南门 ━━━━ 图书馆 ━━━━ 学校北门\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┃               ┃             孔子像\n");
	printf("\t         综合楼C             ┃                ┃\n");
	printf("\t         综合楼B             ┃                ┃\n");
	printf("\t         综合楼A             ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t         大操场              ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t         艺帆馆 ━━━━━━ ┻ ━━━━━━ 琴湖\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t        羽毛球馆             ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
    printf("\t            ┃               ┃              篮球场 \n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┃               ┃            学生食堂\n");
	printf("\t          超市               ┃                ┃  \n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┃               ┃                ┃\n");
	printf("\t            ┗━━━━━ 学生寝室区  ━━━━━┛\n");
	
} 
 void list()
 {
 printf("学校位置列表:\n");
 printf("0:学校北门");
 printf("1:学校南门 ");
 printf("2:图书馆 ");
 printf("3:孔子像 ");
 printf("4:综合楼A");
 printf("5:综合楼B");
 printf("6:综合楼C");
 printf("7:大操场");
 printf("8:艺帆馆");
 printf("9:琴湖");
 printf("10:篮球场");
 printf("11:学生食堂");
 printf("12:羽毛球馆");
 printf("13:超市");
 printf("14:专业教学楼区");
 printf("15:学生寝室区");
 }
/*目录函数的构建*/
void Menu() 
{ 
printf("\n 沈阳理工大学地图导航\n"); 
printf("              ┏━━━━━━━━━━━━━━━━━━━━┓\n"); 
printf("              ┃ x.选择出发点和目的地                   ┃\n"); 
printf("              ┃ y.查看景点信息                         ┃\n"); 
printf("              ┃ z.退出系统                             ┃\n"); 
printf("              ┗━━━━━━━━━━━━━━━━━━━━┛\n"); 
printf("请选择服务"); 
} 
/*MGraph函数（图的构建）*/
MGraph InitGraph(void) 
{ 
MGraph G; 
int i,j; 
G.vexnum=14; //顶点是16个
G.arcnum=17; //弧线有17个
for(i=0;i<G.vexnum;i++) 
G.vexs[i].num=i; 
strcpy(G.vexs[0].name,"学校北门"); 
strcpy(G.vexs[0].introduction,"学校的正门，气势宏伟，好吃的很多"); 
strcpy(G.vexs[1].name,"学校南门"); 
strcpy(G.vexs[1].introduction,"学校的第二个正门，气势也宏伟，但没有好吃的"); 
strcpy(G.vexs[2].name,"图书馆"); 
strcpy(G.vexs[2].introduction,"学习（睡觉）的地方"); 
strcpy(G.vexs[3].name,"孔子像"); 
strcpy(G.vexs[3].introduction,"照相的地方"); 
strcpy(G.vexs[4].name,"综合楼A"); 
strcpy(G.vexs[4].introduction,"上课的地方"); 
strcpy(G.vexs[5].name,"综合楼B"); 
strcpy(G.vexs[5].introduction,"社团玩耍的地方"); 
strcpy(G.vexs[6].name,"综合楼C"); 
strcpy(G.vexs[6].introduction,"上课的地方"); 
strcpy(G.vexs[7].name,"大操场"); 
strcpy(G.vexs[7].introduction,"军训，运动会"); 
strcpy(G.vexs[8].name,"艺帆馆"); 
strcpy(G.vexs[8].introduction,"运动健身，社团开会的地方"); 
strcpy(G.vexs[9].name,"琴湖"); 
strcpy(G.vexs[9].introduction,"钓鱼，滑冰"); 
strcpy(G.vexs[10].name,"篮球场"); 
strcpy(G.vexs[10].introduction,"打篮球"); 
strcpy(G.vexs[11].name,"学生食堂"); 
strcpy(G.vexs[11].introduction,"吃饭的地方"); 
strcpy(G.vexs[12].name,"羽毛球馆");
strcpy(G.vexs[12].introduction,"打羽毛球，篮球，排球的地方"); 
strcpy(G.vexs[13].name,"超市");
strcpy(G.vexs[13].introduction,"买东西，洗澡，洗衣服，健身，买眼镜的地方"); 
strcpy(G.vexs[14].name,"专业教学楼区");
strcpy(G.vexs[14].introduction,"上专业课的地方"); 
strcpy(G.vexs[15].name,"学生寝室区");
strcpy(G.vexs[15].introduction,"真正睡觉的地方"); 
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

