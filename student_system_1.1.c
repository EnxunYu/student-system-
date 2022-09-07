#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

struct student
{
	char id[10];
	char name[20];
	float grade_chinese;
	float grade_math;
	float grade_english;
	float grade_average;
	float grade_sum; 
};

struct student stu[2000]={0};
int student_counter=0;
struct student *p=stu;
struct student *q=stu;

void home_page()
{
	system("cls");
	printf("				*********************************\n");
	printf("				*       学生信息管理系统        *\n");	
	printf("				*********************************\n");
	printf("				*          1、录入              *\n");	
	printf("				*          2、查询              *\n");
	printf("				*          3、排序              *\n");
	printf("				*          4、平均              *\n");
	printf("				*          5、显示              *\n");
	printf("				*          6、清空              *\n");
	printf("				*          7、增加              *\n");
	printf("				*          8、修改              *\n");
	printf("				*          9、删除              *\n");
	printf("				*          10、退出             *\n");
	printf("				*********************************\n");
	printf("				*       老子天下第一            *\n");
	printf("				*       专治各种不服            *\n");
	printf("				*       喜欢折磨甲方            *\n");
	printf("				*       产品爱用不用            *\n");	
	printf("				*********************************\n");
}

void information_insert()
{
	system("cls");
	printf("                ------------------【信息录入】---------------\n");
	int i;
	printf("请输入录入学生信息的数量："); 
	scanf("%d",&student_counter);
	for(i=0;i<student_counter;i++)
	{
		printf("姓名：");
		scanf("%s",stu[i].name);
		printf("学号：");
		scanf("%s",stu[i].id);
		printf("语文：");
		scanf("%f",&stu[i].grade_chinese);
		printf("数学：");
		scanf("%f",&stu[i].grade_math);
		printf("英语："); 
		scanf("%f",&stu[i].grade_english);
		stu[i].grade_sum=stu[i].grade_chinese+stu[i].grade_math+stu[i].grade_english;
		printf("\n");
		p++;
	}
	printf("输入0返回主界面"); 
}

void information_query()
{
	system("cls");
	printf("                ------------------【信息查询】---------------\n");
	char queried_id[10]; 
	int i;
	if(student_counter==0)
	{
		printf("数据库为空，请输入数据!\n");
	}
	else
	{
		printf("请输入被查询者的学号：");
		scanf("%s",queried_id);
		for(i=0;i<student_counter;i++)
		{
			if(!strcmp(queried_id,stu[i].id))
			{
				printf("姓名：");
				printf("%s\n",stu[i].name);
				printf("学号：");
				printf("%s\n",stu[i].id);
				printf("语文：");
				printf("%f\n",stu[i].grade_chinese);
				printf("数学：");
				printf("%f\n",stu[i].grade_math);
				printf("英语：");
				printf("%f\n",stu[i].grade_english);
				printf("总分：");
				printf("%f\n",stu[i].grade_sum);			
				printf("平均分：");
				printf("%f\n",stu[i].grade_average);
				break; 
			}
		
			else if(strcmp(queried_id,stu[i].id)!=0&&i==student_counter-1)
        	{   
            	printf("查无此人！\n");
        	} 	
		}	
	}
	
	printf("输入0返回主界面");
}

void grade_average()
{
	int i;
	for(i=0;i<student_counter;i++)
	{
		stu[i].grade_average=(stu[i].grade_sum)/3;
	}	
}

void grade_order()
{
	int i;
	int j;
	for(i=0;i<student_counter-1;i++)
	{
		for(j=0;j<student_counter-i-1;j++)
		{
			if(stu[j].grade_sum<stu[j+1].grade_sum)
			{
				struct student temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}

void display()
{
	system("cls");
	printf("                ------------------【信息显示】---------------\n");
	int i;
	if(student_counter==0)
	{
		printf("数据库为空，请输入数据！\n");		
	}
	else
	{ 
		for(i=0;i<student_counter;i++)
		{
			printf("姓名：");
			printf("%s\n",stu[i].name);
			printf("学号：");
			printf("%s\n",stu[i].id);
			printf("语文：");
			printf("%f\n",stu[i].grade_chinese);
			printf("数学：");
			printf("%f\n",stu[i].grade_math);
			printf("英语：");
			printf("%f\n",stu[i].grade_english);
			printf("总分：");
			printf("%f\n",stu[i].grade_sum);			
			printf("平均分：");
			printf("%f\n",stu[i].grade_average);
			printf("\n");
		}
	}
	printf("输入0返回主界面"); 
}

void increase()
{
	system("cls");
	printf("                ------------------【信息添加】---------------\n");
	int a;
	printf("请输入需要增加学生信息的数量："); 
	scanf("%d",&a);
	struct student *q=p+a;
	while(p<q)
	{
		printf("姓名：");
		scanf("%s",p->name);
		printf("学号：");
		scanf("%s",p->id);
		printf("语文：");
		scanf("%f",&p->grade_chinese);
		printf("数学：");
		scanf("%f",&p->grade_math);
		printf("英语："); 
		scanf("%f",&p->grade_english);
		p->grade_sum=p->grade_chinese+p->grade_math+p->grade_english;
		p++;
		student_counter++;	
		printf("\n");
	}	
	printf("输入0返回主界面"); 
} 

void revise()
{
	system("cls");
	printf("                ------------------【信息修改】---------------\n");
	int a;
	if(student_counter==0)
	{
		printf("数据库为空，请输入数据！\n");	
	}
	else
	{
		printf("请输入需要修改信息的学生的名次：");
		scanf("%d",&a);
		q=q+a;
		if((q-stu)>student_counter)
		{
			printf("数据库中没有信息！\n");
		}
		else
		{
			printf("请输入修改后的信息：\n");
			printf("姓名：");
			scanf("%s",q->name);
			printf("学号：");
			scanf("%s",q->id);
			printf("语文：");
			scanf("%f",&q->grade_chinese);
			printf("数学：");
			scanf("%f",&q->grade_math);
			printf("英语："); 
			scanf("%f",&q->grade_english);
			q->grade_sum=q->grade_chinese+q->grade_math+q->grade_english;
		}
		q=stu;
	}
	printf("输入0返回主界面");
} 

void removeing()
{
	system("cls");
	printf("                ------------------【信息删除】---------------\n");
	if(student_counter==0)
	{
		printf("数据库为空，请输入数据！\n");	
	}
	else
	{
		int a=0;
		int i=0;
		int loop_counter=0;
		struct student *k=stu;
		struct student *l=stu+student_counter;
		printf("请输入需要删除学生的名次：");
		scanf("%d",&a);
		p=p+a-loop_counter-1; 
		while(k+i<=l)
		{
			*(k+i)=*(k+i+1);
			i++;		
		}
		l--; 
		k=stu;
		student_counter--;
		p--;	
	}
	printf("输入0返回主界面");	
} 

void clear_zero()
{
	student_counter=0; 
}

void exiting()
{
	system("cls");
	int save_num;
	if(student_counter!=0)
	{
		printf("正在退出是否保存数据？\n");
		printf("1：是           2：否\n");
		scanf("%d",&save_num);
		if(save_num==1)
		{
			student_counter=student_counter;
		}
		else if(save_num==2)
		{
			student_counter=0;
		}		
	} 
	printf("程序已经退出，输入0重新使用\n");
}

void choose()
{
	int choose_num; 
	scanf("%d",&choose_num);
	if(choose_num==0)
	{
		home_page();
	}
	
	else if(choose_num==1)
	{
		information_insert();
	}
	
	else if(choose_num==2)
	{
		information_query();
	}
	
	else if(choose_num==3)
	{
		grade_order();
	}
	
	else if(choose_num==4)
	{
		grade_average();;
	}
	
	else if(choose_num==5)
	{
		display();
	}
	
	else if(choose_num==6)
	{
		clear_zero();
	}
	
	else if(choose_num==7)
	{
		increase();
	}
	
	else if(choose_num==8)
	{
		revise();
	}
	
	else if(choose_num==9)
	{
		removeing();
	}
	
	else if(choose_num==10)
	{
		exiting();
	}
}

int main()
{
	printf("输入0开始使用:"); 
	while(1)
	{
		choose();
	}
	return 0; 
} 
