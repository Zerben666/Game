#include <stdio.h>
#include <.h>
#define N 4         //课程数
struct student         //1.	声明用于表示学生信息的结构体类型
{
    int num;              //学号
    char name[30];
    float c;              //C语言成绩
    float english;        //英语成绩
    float ds;             //数据结构成绩
    float computer;       //计算机基础成绩
}stu[4]={               //为方便测试，先定义好默认数据
    {9606011,"Li ming",87.5,84,36,65},
    {9606012,"Zhang jiangguo",79,79.8,68,89},
    {9606013,"wang ping",90,86,96,86},
    {9606014,"Jia xin",95,74,83,86}
},*p=stu;//为（文）秀（档）操（要）作（求），一部分使用指针变量实现

int aver(int a)
{
    printf(",平均成绩为%.2f\n",(stu[a].c+swindowstu[a].computer+stu[a].ds+stu[a].english)/N);
}
void tip()
{
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*            请选择查询对象:              *\n");
    printf("* 1.据学生学号查询学生成绩及平均成绩      *\n");
    printf("* 2.据课程代号查询学生课程成绩及平均成绩  *\n");
    printf("* 3.据学生学号和课程代号查询学生成绩      *\n");
    printf("* 4.学生原始数据的依次输入                *\n");
    printf("* 5.退出本系统！                     *\n");
}
main()
{
    struct student *p;int M=4;  //定义默认学生信息个数
    int select;                 //定义选择功能号变量
    int i,j,k;
    char mistake[]="抱歉，系统中没有对应的数据";
    
    while (1)              	                                    /*菜单循环显示和功能循环处理*/                    
    {  printf("           欢迎使用学生查询系统!\n\n");            /*菜单显示*/
        printf("* * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*            请选择查询对象:              *\n");
        printf("* 0.查看功能号                           *\n");
        printf("* 1.据学生学号查询学生成绩及平均成绩      *\n");
        printf("* 2.据课程代号查询学生课程成绩及平均成绩  *\n");
        printf("* 3.据学生学号和课程代号查询学生成绩      *\n");
        printf("* 4.学生原始数据的依次输入                *\n");
        printf("* 5.退出本系统！                     *\n");
        INPUT:
        printf("* * * * * * * * * * * * * * * * * * * * * *\n");
        printf("          请选择功能号1—5: ");
        scanf("%d",&select);
        if(select==5)		                /*退出系统*/
        {
            printf("Bye!");
            Sleep(1000);
            break;
        }
        if(select>=6||select<0)		    /*输入功能号有误处理*/
        {  printf("* * * 输入有误，请重输功能号1-5：* * *\n");
            goto INPUT;
        }
        switch(select)
        {   case 0:                /*打出功能号提示*/
                tip();
                goto INPUT;
            case 1:				   /*按学号查询功能*/
                int num;
                printf("请输入查询学生的学号(查询全部：0):");
                scanf("%d",&num);
                /*查询所有*/
                if(num==0)
                {
                    for(i=0;i<M+1;i++)
                    {
                        printf("%d\t %s\t %.2f\t %.2f\t %.2f %.2f  ", stu[i].num,stu[i].name,stu[i].c,stu[i].english,stu[i].ds,stu[i].computer);
                        printf("平均成绩：%f\n",(stu[i].c+stu[i].english+stu[i].ds+stu[i].computer)/N);
                    }
                    goto INPUT;
                }
                /*单个查询*/
                for(p=stu,k=0;stu+N;p++)
                {
                    //循环次数超过学生信息个数后提示没有查询到对应信息
                    k++;
                    if(k>M+1)
                    {
                        printf("%s\n",mistake);
                        goto INPUT;
                    }

                    if(p->num==num)
                    {
                        printf("该学号对应的学生信息是：");
                        printf("%d\t %s\t %.2f\t %.2f\t %.2f %.2f\n", p->num,p->name,p->c,p->english,p->ds,p->computer);
                        printf("平均成绩：%f\n",(p->c+p->computer+p->ds+p->english)/N);
                        goto INPUT;
                    }
                }
            case 2:                /*按课程号查询功能*/
                printf("1.C语言 2.英语 3.数据结构 4.计算机基础\n");
                printf("请输入查询课程的代号(1-%d)：",N);
                scanf("%d",&j);
                if (j==1)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d号学生的成绩为%.2f",stu[i].num,stu[i].c);
                        aver(i);
                    }
                }
                if (j==2)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d号学生的成绩为%.2f",stu[i].num,stu[i].english);
                        aver(i);
                    }
                }
                if (j==3)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d号学生的成绩为%.2f",stu[i].num,stu[i].ds);
                        aver(i);
                    }
                }
                if (j==4)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d号学生的成绩为%.2f",stu[i].num,stu[i].computer);
                        aver(i);
                        printf("\n");
                    }
                }
                goto INPUT;
            case 3:                /*按学号和课程号查询*/
                printf("输入学生的学号：");
                scanf("%d",&num);
                printf("输入课程代号：");
                scanf("%d",&j);
                for(i=0;i<M+1;i++)
                {
                    if(num==stu[i].num)
                    {
                        
                        if (j==1)
                        {
                                printf("%d号学生%d号课程成绩为%.2f\n",num,j,stu[i].c);
                        }
                        if (j==2)
                        {
                                printf("%d号学生%d号课程成绩为%.2f\n",num,j,stu[i].english);
                        }
                        if (j==3)
                        {
                                printf("%d号学生%d号课程成绩为%.2f\n",num,j,stu[i].ds);
                        }
                        if (j==4)
                        {
                                printf("%d号学生%d号课程成绩为%.2f\n",num,j,stu[i].computer);
                        }
                    }
                }
                goto INPUT;
            case 4:                /*学生信息录入功能*/
                int stu_num;
                printf("请键入您要输入的对应学生的信息个数：");
                scanf("%d",&stu_num);
                printf("\n【信息输入格式】（学号） （姓名） （C语言成绩）（英语成绩）（数据结构成绩）（计算机基础成绩）\n");
                for(i=0;i<stu_num;i++)
                {
                    i+=M+1;
                    printf("请键入(%d/%d)学生信息：",i,M+stu_num);
                    scanf("%d %s %f %f %f %f",&stu[i].num,&stu[i].name,&stu[i].c,&stu[i].english,&stu[i].ds,&stu[i].computer);
                    i-=M+1;
                }
                M+=stu_num;     //同步增加系统原本的学生信息数
                printf("录入成功！");
                goto INPUT;
        }
    }
}
