#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 35
#define MAX_NAME 256
typedef struct student  //学生信息
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
/*-----------1输入信息子程序---------*/
void input(STUDENT *data, int *len)
{
    int no;
    putchar('\n');
    printf("%s\n", "请输入新的记录，如果需要退出当前菜单请输入-1.");
    printf("%s\n", "格式：\n学号\n");
    printf("%s\n", "姓名\t程序\t数学\t英语\t物理\t化学");
    putchar('\n');
    printf("如:\n");
    printf("1 ");
    printf("小明\t93\t95\t89\t89\t78\n");
    scanf("%d", &no);
    while(no != -1) {
        data[*len].no = no;
        scanf("%s%lf%lf%lf%lf%lf", data[*len].name, &data[*len].C, &data[*len].math,&data[*len].English,&data[*len].physics,&data[*len].chemistry);        data[*len].mark_ave=(data[*len].C+data[*len].math+data[*len].English+data[*len].physics+data[*len].chemistry)/5.0;        data[*len].mark_tot=data[*len].C+data[*len].math+data[*len].English+data[*len].chemistry+data[*len].chemistry;
        (*len)++;
        scanf("%d", &no);
    }
}
/*---------------2输出信息子程序---------------*/
void output(STUDENT *data, int len)
{
    int i;
    //system("cls");
    printf("%s\t", "学号");
    printf("%s\t", "姓名");
    printf("%s\t", "程序");
    printf("%s\t", "数学");
    printf("%s\t", "英语");
	printf("%s\t","物理");
	printf("%s\t","化学");
    printf("%s\t", "平均分");
    printf("%s\t", "总分");
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
    printf("按回车键继续.");
    getchar();
    getchar();
}
/*--------------3排序子程序------------*/
void sort(STUDENT *data, int *len)
{
    int i,j,k;
    STUDENT *temp,t;
    temp=&t;
    for (i=0; i<*len-1; i++) {
        for (k=i, j=i+1; j<*len; j++)//j是k的下一个
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
	printf("已排好序");
}
/*--------------------4查找子程序-----------------------*/
void find(STUDENT *data, int len)
{
    int find_no, result ;
    int i;
lab: result=0;
    printf("%s\n", "请输入需要查找的学生的学号，退出当前菜单请输入 -1.");
    scanf("%d", &find_no);
    if (find_no == -1) return;     /*exit the fine sub program*/
    while( data[result].no != find_no && result < len) result ++;
    if (result >= len ) {
        printf("%s\n", "未查询到相关信息");
        goto lab;
    }
    else {
        //system("cls");
        printf("%s\n", "查询信息如下：");
        for (i =0; i < 80; i++)
            putchar('*');
        putchar('\n');
        printf("%s\t", "学号");
        printf("%s\t", "姓名");
        printf("%s\t", "程序");
        printf("%s\t", "数学");
        printf("%s\t", "英语");
		printf("%s\t","物理");
		printf("%s\t","化学");
        printf("%s\t", "平均分");
        printf("%s\t", "总分");
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
/*-----------------5插入子程序-------------*/
void insert(STUDENT *data, int *len)
{
    int no, pos;
    double C, math, English,physics,chemistry, mark_ave, mark_tot;
    int i;
    char name[MAX_NAME];
lab: printf("%s\n", "输入新的记录，退出当前菜单请输入-1.");
    printf("%s\n", "格式：学号\t姓名\t程序\t数学\t英语\t物理\t化学");
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
/*-------------删除子程序--------------*/
void delete_item(STUDENT *data, int *len)
{
    int no, i, pos;
lab: pos=0;
    printf("%s\n", "输入需要删除的学生的学号，退出当前菜单请输入-1.");
    scanf("%d", &no);
    if (no == -1) return;
    while( (data[pos].no != no) && (pos < *len) ) pos = pos +1;
    if (pos >= *len) {
        printf("%s\n", "未找到需要删除的学生");
        goto lab;
    }
    else {
        for (i = pos+1;i < *len; i++)
            data[i-1] = data[i];
        *len = *len -1;
        if (*len == 0) {
            printf("%s\n", "没有任何记录，请按回车键返回.");
            getchar();
            getchar();
            return;
        }
        goto lab;
    }
}
 
//---------------统计子程序------------
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
    printf("%s\t", "分数");
    printf("%s\t", "0--59");
    printf("%s\t", "60--69");
    printf("%s\t", "70--79");
    printf("%s\t", "80--89");
    printf("%s\t", "90--100");
    putchar('\n');
    putchar('\n');
    printf("%s\t", "学生");
    printf("%d\t", no_59);
    printf("%d\t", no_69);
    printf("%d\t", no_79);
    printf("%d\t", no_89);
    printf("%d\t", no_100);
    putchar('\n');
    for (i =0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("按回车键返回");
    getchar();
    getchar();
}
//---------------显示信息子程序------------
void paint()
{
    int i;
    //system("cls");
    printf("%55s\n", "学生成绩管理系统\n");
    for (i = 0; i < 80; i++)
        putchar('*');
    putchar('\n');
    printf("             1 输入信息                        2 输出信息\n");
    printf("             3.排序                            4 按学号查找\n");
    printf("             5 插入                            6 按学号删除\n");
    printf("             7 按平均分输出统计信息            8 保存到文件\n");
    for (i = 0; i<= 79; i++)
        putchar('*');
    putchar('\n');
    printf("%s\n", "请输入各操作对应的序号:");
}
void save(STUDENT *data, int len)//将数据保存到文件
{
    int i;
    FILE *fp;
    fp=fopen("成绩统计表.txt","w");
    fprintf(fp,"%s\t", "学号");
    fprintf(fp,"%s\t", "姓名");
    fprintf(fp,"%s\t", "程序");
    fprintf(fp,"%s\t", "数学");
    fprintf(fp,"%s\t", "英语");
	fprintf(fp,"%s\t", "物理");
	fprintf(fp,"%s\t","化学");
    fprintf(fp,"%s\t", "平均分");
    fprintf(fp,"%s\n", "总分");
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
    printf("文件已保存到\"成绩统计表.txt\"");
    getchar();getchar();
}
/*-----------主程序--------------*/
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
                if (ctrl_ch != '\n') printf("%s\n", "输入错误!");
                break;
        }
        if (ctrl_ch != '\n') paint();
        scanf("%c", &ctrl_ch);
    }
}
