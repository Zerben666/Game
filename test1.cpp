#include <stdio.h>
#include <.h>
#define N 4         //�γ���
struct student         //1.	�������ڱ�ʾѧ����Ϣ�Ľṹ������
{
    int num;              //ѧ��
    char name[30];
    float c;              //C���Գɼ�
    float english;        //Ӣ��ɼ�
    float ds;             //���ݽṹ�ɼ�
    float computer;       //����������ɼ�
}stu[4]={               //Ϊ������ԣ��ȶ����Ĭ������
    {9606011,"Li ming",87.5,84,36,65},
    {9606012,"Zhang jiangguo",79,79.8,68,89},
    {9606013,"wang ping",90,86,96,86},
    {9606014,"Jia xin",95,74,83,86}
},*p=stu;//Ϊ���ģ��㣨�����٣�Ҫ�������󣩣�һ����ʹ��ָ�����ʵ��

int aver(int a)
{
    printf(",ƽ���ɼ�Ϊ%.2f\n",(stu[a].c+swindowstu[a].computer+stu[a].ds+stu[a].english)/N);
}
void tip()
{
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*            ��ѡ���ѯ����:              *\n");
    printf("* 1.��ѧ��ѧ�Ų�ѯѧ���ɼ���ƽ���ɼ�      *\n");
    printf("* 2.�ݿγ̴��Ų�ѯѧ���γ̳ɼ���ƽ���ɼ�  *\n");
    printf("* 3.��ѧ��ѧ�źͿγ̴��Ų�ѯѧ���ɼ�      *\n");
    printf("* 4.ѧ��ԭʼ���ݵ���������                *\n");
    printf("* 5.�˳���ϵͳ��                     *\n");
}
main()
{
    struct student *p;int M=4;  //����Ĭ��ѧ����Ϣ����
    int select;                 //����ѡ���ܺű���
    int i,j,k;
    char mistake[]="��Ǹ��ϵͳ��û�ж�Ӧ������";
    
    while (1)              	                                    /*�˵�ѭ����ʾ�͹���ѭ������*/                    
    {  printf("           ��ӭʹ��ѧ����ѯϵͳ!\n\n");            /*�˵���ʾ*/
        printf("* * * * * * * * * * * * * * * * * * * * * *\n");
        printf("*            ��ѡ���ѯ����:              *\n");
        printf("* 0.�鿴���ܺ�                           *\n");
        printf("* 1.��ѧ��ѧ�Ų�ѯѧ���ɼ���ƽ���ɼ�      *\n");
        printf("* 2.�ݿγ̴��Ų�ѯѧ���γ̳ɼ���ƽ���ɼ�  *\n");
        printf("* 3.��ѧ��ѧ�źͿγ̴��Ų�ѯѧ���ɼ�      *\n");
        printf("* 4.ѧ��ԭʼ���ݵ���������                *\n");
        printf("* 5.�˳���ϵͳ��                     *\n");
        INPUT:
        printf("* * * * * * * * * * * * * * * * * * * * * *\n");
        printf("          ��ѡ���ܺ�1��5: ");
        scanf("%d",&select);
        if(select==5)		                /*�˳�ϵͳ*/
        {
            printf("Bye!");
            Sleep(1000);
            break;
        }
        if(select>=6||select<0)		    /*���빦�ܺ�������*/
        {  printf("* * * �������������书�ܺ�1-5��* * *\n");
            goto INPUT;
        }
        switch(select)
        {   case 0:                /*������ܺ���ʾ*/
                tip();
                goto INPUT;
            case 1:				   /*��ѧ�Ų�ѯ����*/
                int num;
                printf("�������ѯѧ����ѧ��(��ѯȫ����0):");
                scanf("%d",&num);
                /*��ѯ����*/
                if(num==0)
                {
                    for(i=0;i<M+1;i++)
                    {
                        printf("%d\t %s\t %.2f\t %.2f\t %.2f %.2f  ", stu[i].num,stu[i].name,stu[i].c,stu[i].english,stu[i].ds,stu[i].computer);
                        printf("ƽ���ɼ���%f\n",(stu[i].c+stu[i].english+stu[i].ds+stu[i].computer)/N);
                    }
                    goto INPUT;
                }
                /*������ѯ*/
                for(p=stu,k=0;stu+N;p++)
                {
                    //ѭ����������ѧ����Ϣ��������ʾû�в�ѯ����Ӧ��Ϣ
                    k++;
                    if(k>M+1)
                    {
                        printf("%s\n",mistake);
                        goto INPUT;
                    }

                    if(p->num==num)
                    {
                        printf("��ѧ�Ŷ�Ӧ��ѧ����Ϣ�ǣ�");
                        printf("%d\t %s\t %.2f\t %.2f\t %.2f %.2f\n", p->num,p->name,p->c,p->english,p->ds,p->computer);
                        printf("ƽ���ɼ���%f\n",(p->c+p->computer+p->ds+p->english)/N);
                        goto INPUT;
                    }
                }
            case 2:                /*���γ̺Ų�ѯ����*/
                printf("1.C���� 2.Ӣ�� 3.���ݽṹ 4.���������\n");
                printf("�������ѯ�γ̵Ĵ���(1-%d)��",N);
                scanf("%d",&j);
                if (j==1)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d��ѧ���ĳɼ�Ϊ%.2f",stu[i].num,stu[i].c);
                        aver(i);
                    }
                }
                if (j==2)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d��ѧ���ĳɼ�Ϊ%.2f",stu[i].num,stu[i].english);
                        aver(i);
                    }
                }
                if (j==3)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d��ѧ���ĳɼ�Ϊ%.2f",stu[i].num,stu[i].ds);
                        aver(i);
                    }
                }
                if (j==4)
                {
                    for(i=0;i<M+1;i++)
                    {  
                        printf("%d��ѧ���ĳɼ�Ϊ%.2f",stu[i].num,stu[i].computer);
                        aver(i);
                        printf("\n");
                    }
                }
                goto INPUT;
            case 3:                /*��ѧ�źͿγ̺Ų�ѯ*/
                printf("����ѧ����ѧ�ţ�");
                scanf("%d",&num);
                printf("����γ̴��ţ�");
                scanf("%d",&j);
                for(i=0;i<M+1;i++)
                {
                    if(num==stu[i].num)
                    {
                        
                        if (j==1)
                        {
                                printf("%d��ѧ��%d�ſγ̳ɼ�Ϊ%.2f\n",num,j,stu[i].c);
                        }
                        if (j==2)
                        {
                                printf("%d��ѧ��%d�ſγ̳ɼ�Ϊ%.2f\n",num,j,stu[i].english);
                        }
                        if (j==3)
                        {
                                printf("%d��ѧ��%d�ſγ̳ɼ�Ϊ%.2f\n",num,j,stu[i].ds);
                        }
                        if (j==4)
                        {
                                printf("%d��ѧ��%d�ſγ̳ɼ�Ϊ%.2f\n",num,j,stu[i].computer);
                        }
                    }
                }
                goto INPUT;
            case 4:                /*ѧ����Ϣ¼�빦��*/
                int stu_num;
                printf("�������Ҫ����Ķ�Ӧѧ������Ϣ������");
                scanf("%d",&stu_num);
                printf("\n����Ϣ�����ʽ����ѧ�ţ� �������� ��C���Գɼ�����Ӣ��ɼ��������ݽṹ�ɼ���������������ɼ���\n");
                for(i=0;i<stu_num;i++)
                {
                    i+=M+1;
                    printf("�����(%d/%d)ѧ����Ϣ��",i,M+stu_num);
                    scanf("%d %s %f %f %f %f",&stu[i].num,&stu[i].name,&stu[i].c,&stu[i].english,&stu[i].ds,&stu[i].computer);
                    i-=M+1;
                }
                M+=stu_num;     //ͬ������ϵͳԭ����ѧ����Ϣ��
                printf("¼��ɹ���");
                goto INPUT;
        }
    }
}
