#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 35
#define MAX_NAME 256
typedef struct student  //ѧ����Ϣ
{
    int  no;
    char name[MAX_NAME];
    double  C;
    double  math;
    double  English;
	double  physics;
	double  chemistry;
    double  mark_ave;
	double  mark_tot;
} STUDENT;
/*-----------1������Ϣ�ӳ���---------*/
void input(STUDENT *data, int *len)
{
    int no;
    putchar('\n');
    printf("%s\n", "�������µļ�¼�������Ҫ�˳���ǰ�˵�������-1.");
    printf("%s\n", "��ʽ��\nѧ��\n");
    printf("%s\n", "����\t����\t��ѧ\tӢ��\t����\t��ѧ");
    putchar('\n');
    printf("��:\n");
    printf("1 ");
    printf("С��\t93\t95\t89\t89\t78\n");
    scanf("%d", &no);
    while(no != -1) {
        data[*len].no = no;
        scanf("%s%lf%lf%lf%lf%lf", data[*len].name, &data[*len].C, &data[*len].math,&data[*len].English,&data[*len].physics,&data[*len].chemistry);        data[*len].mark_ave=(data[*len].C+data[*len].math+data[*len].English+data[*len].physics+data[*len].chemistry)/5.0;        data[*len].mark_tot=data[*len].C+data[*len].math+data[*len].English+data[*len].chemistry+data[*len].chemistry;
        (*len)++;
        scanf("%d", &no);
    }
}
/*---------------2�����Ϣ�ӳ���---------------*/
void output(STUDENT *data, int len)
{
    int i;
    //system("cls");
    printf("%s\t", "ѧ��");
    printf("%s\t", "����");
    printf("%s\t", "����");
    printf("%s\t", "��ѧ");
    printf("%s\t", "Ӣ��");
	printf("%s\t","����");
	printf("%s\t","��ѧ");
    printf("%s\t", "ƽ����");
    printf("%s\t", "�ܷ�");
    putchar('\n');
    for (i =0; i < 80; i++)
        putchar('*');
    putchar('\n');
    for (i = 0; i< len; i++)
    {
        printf("%d\t", data[i].no);
        printf("%s\t", data[i].name);
        printf("%.1lf\t", data[i].C);
        printf("%.1lf\t", data[i].math);
        printf("%.1lf\t", data[i].English);
		printf("%.1lf\t",data[i].physics);
		printf("%.1lf\t",data[i].chemistry);
        printf("%.1lf\t", data[i].mark_ave);
        printf("%.1lf\t", data[i].mark_tot);
        putchar('\n');
    }
    for (i =0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("���س�������.");
    getchar();
    getchar();
}
/*--------------3�����ӳ���------------*/
void sort(STUDENT *data, int *len)
{
    int i,j,k;
    STUDENT *temp,t;
    temp=&t;
    for (i=0; i<*len-1; i++) {
        for (k=i, j=i+1; j<*len; j++)//j��k����һ��
            if (data[k].mark_ave < data[j].mark_ave)
            {
                k=j;
            }
        if (k != i) {
            *temp = data[i];
            data[i] = data[k];
            data[k] = *temp;
        }
    }
	printf("���ź���");
}
/*--------------------4�����ӳ���-----------------------*/
void find(STUDENT *data, int len)
{
    int find_no, result ;
    int i;
lab: result=0;
    printf("%s\n", "��������Ҫ���ҵ�ѧ����ѧ�ţ��˳���ǰ�˵������� -1.");
    scanf("%d", &find_no);
    if (find_no == -1) return;     /*exit the fine sub program*/
    while( data[result].no != find_no && result < len) result ++;
    if (result >= len ) {
        printf("%s\n", "δ��ѯ�������Ϣ");
        goto lab;
    }
    else {
        //system("cls");
        printf("%s\n", "��ѯ��Ϣ���£�");
        for (i =0; i < 80; i++)
            putchar('*');
        putchar('\n');
        printf("%s\t", "ѧ��");
        printf("%s\t", "����");
        printf("%s\t", "����");
        printf("%s\t", "��ѧ");
        printf("%s\t", "Ӣ��");
		printf("%s\t","����");
		printf("%s\t","��ѧ");
        printf("%s\t", "ƽ����");
        printf("%s\t", "�ܷ�");
        putchar('\n');
        printf("%d\t", data[result].no);
        printf("%s\t", data[result].name);
        printf("%.1lf\t", data[result].C);
        printf("%.1lf\t", data[result].math);
        printf("%.1lf\t", data[result].English);
		printf("%.11f\t",data[result].physics);
		printf("%.11f\t",data[result].chemistry);
        printf("%.1lf\t", data[result].mark_ave);
        printf("%.1lf\t", data[result].mark_tot);
        putchar('\n');
        for (i =0; i < 80; i++)
            putchar('*');
        putchar('\n');
        goto lab;
    }
}
/*-----------------5�����ӳ���-------------*/
void insert(STUDENT *data, int *len)
{
    int no, pos;
    double C, math, English,physics,chemistry, mark_ave, mark_tot;
    int i;
    char name[MAX_NAME];
lab: printf("%s\n", "�����µļ�¼���˳���ǰ�˵�������-1.");
    printf("%s\n", "��ʽ��ѧ��\t����\t����\t��ѧ\tӢ��\t����\t��ѧ");
    scanf("%d", &no);
    if (no == -1) return;
    data[*len].no = no;
    scanf("%s%lf%lf%lf%lf%lf", name, &C, &math, &English,&physics,&chemistry);
    mark_ave=(C+math+English+physics+chemistry)/5.0;
    mark_tot=C+math+English+physics+chemistry;
    pos = 0;
    while ((data[pos].mark_ave < mark_ave) && (pos < *len) )
        pos ++;
    for (i = *len-1; i >= pos; i--)
        data[i+1] = data[i];
    data[pos].no = no;
    strcpy(data[pos].name, name);
    data[pos].C = C;
    data[pos].math = math;
    data[pos].English = English;
	data[pos].physics=physics;
	data[pos].chemistry=chemistry;
    data[pos].mark_ave = mark_ave;
    data[pos].mark_tot = mark_tot;
    (*len)++;
    goto lab;
}
/*-------------ɾ���ӳ���--------------*/
void delete_item(STUDENT *data, int *len)
{
    int no, i, pos;
lab: pos=0;
    printf("%s\n", "������Ҫɾ����ѧ����ѧ�ţ��˳���ǰ�˵�������-1.");
    scanf("%d", &no);
    if (no == -1) return;
    while( (data[pos].no != no) && (pos < *len) ) pos = pos +1;
    if (pos >= *len) {
        printf("%s\n", "δ�ҵ���Ҫɾ����ѧ��");
        goto lab;
    }
    else {
        for (i = pos+1;i < *len; i++)
            data[i-1] = data[i];
        *len = *len -1;
        if (*len == 0) {
            printf("%s\n", "û���κμ�¼���밴�س�������.");
            getchar();
            getchar();
            return;
        }
        goto lab;
    }
}
 
//---------------ͳ���ӳ���------------
void stat1(STUDENT *data, int *len)
{
    int no_59=0, no_69=0, no_79=0, no_89=0, no_100=0;
    int i;
    for (i = 0;i < *len; i++) {
        if (data[i].mark_ave <=59) no_59++;
        else if (data[i].mark_ave <=69) no_69++;
        else if (data[i].mark_ave <=79) no_79++;
        else if (data[i].mark_ave <= 89) no_89++;
        else no_100++;
    }
    //system("cls");
    for (i =0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("%s\t", "����");
    printf("%s\t", "0--59");
    printf("%s\t", "60--69");
    printf("%s\t", "70--79");
    printf("%s\t", "80--89");
    printf("%s\t", "90--100");
    putchar('\n');
    putchar('\n');
    printf("%s\t", "ѧ��");
    printf("%d\t", no_59);
    printf("%d\t", no_69);
    printf("%d\t", no_79);
    printf("%d\t", no_89);
    printf("%d\t", no_100);
    putchar('\n');
    for (i =0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("���س�������");
    getchar();
    getchar();
}
//---------------��ʾ��Ϣ�ӳ���------------
void paint()
{
    int i;
    //system("cls");
    printf("%55s\n", "ѧ���ɼ�����ϵͳ\n");
    for (i = 0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("             1 ������Ϣ                        2 �����Ϣ\n");
    printf("             3.����                            4 ��ѧ�Ų���\n");
    printf("             5 ����                            6 ��ѧ��ɾ��\n");
    printf("             7 ��ƽ�������ͳ����Ϣ            8 ���浽�ļ�\n");
    for (i = 0; i<= 79; i++)
        putchar('*');
    putchar('\n');
    printf("%s\n", "�������������Ӧ�����:");
}
void save(STUDENT *data, int len)//�����ݱ��浽�ļ�
{
    int i;
    FILE *fp;
    fp=fopen("�ɼ�ͳ�Ʊ�.txt","w");
    fprintf(fp,"%s\t", "ѧ��");
    fprintf(fp,"%s\t", "����");
    fprintf(fp,"%s\t", "����");
    fprintf(fp,"%s\t", "��ѧ");
    fprintf(fp,"%s\t", "Ӣ��");
	fprintf(fp,"%s\t", "����");
	fprintf(fp,"%s\t","��ѧ");
    fprintf(fp,"%s\t", "ƽ����");
    fprintf(fp,"%s\n", "�ܷ�");
    fprintf(fp,"========================================================================\n");
    putchar('\n');
    for (i = 0; i< len; i++)
    {
        fprintf(fp,"%d\t", data[i].no);
        fprintf(fp,"%s\t", data[i].name);
        fprintf(fp,"%.1lf\t", data[i].C);
        fprintf(fp,"%.1lf\t", data[i].math);
        fprintf(fp,"%.1lf\t", data[i].English);
		fprintf(fp,"%.11f\t",data[i].physics);
		fprintf(fp,"%.11f\t",data[i].chemistry);
        fprintf(fp,"%.1lf\t", data[i].mark_ave);
        fprintf(fp,"%.1lf\n", data[i].mark_tot);
    }
    fprintf(fp,"========================================================================\n");
    fclose(fp);
    printf("�ļ��ѱ��浽\"�ɼ�ͳ�Ʊ�.txt\"");
    getchar();getchar();
}
/*-----------������--------------*/
int main()
{
    STUDENT data[MAXN];
    int len = 0;
    char ctrl_ch;
    paint();
    scanf("%c", &ctrl_ch);
    while (ctrl_ch != '0') {
        switch(ctrl_ch) {
            case '1':
                input(data, &len);
                break;
            case '2':
                output(data, len);
                break;
            case '3':
                sort(data, &len);
                break;
            case '4':
                find(data, len);
                break;
            case '5':
                insert(data, &len);
                break;
            case '6':
                delete_item(data, &len);
                break;
            case '7':
                stat1(data, &len);
                break;
            case '8':
                save(data, len);
                break;
            default:
                if (ctrl_ch != '\n') printf("%s\n", "�������!");
                break;
        }
        if (ctrl_ch != '\n') paint();
        scanf("%c", &ctrl_ch);
    }
}
