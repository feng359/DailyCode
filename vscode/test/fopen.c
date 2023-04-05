#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stuInfo
{
    char id[20];
    char name[20];
    char sex[10];
    int old;
    float chinese;
    float math;
    float english;

}stuInfo;


typedef struct stuNode
{
    stuInfo info;
    struct stuNode *next;
    
}node,*pNode;


void showInfo(pNode head)
{
    pNode pCur = head;

    if (pCur->next == NULL)
    {
        printf("目前还没录入任何信息\n");
        return;
    }

    while (pCur->next != NULL)
    {

        printf("|-------+-------+-------+-------+-------+-------+-------|\n");
        printf("|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
               pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
        printf("|-------+-------+-------+-------+-------+-------+-------|\n");
        pCur = pCur->next;
    }
}

int main(){


    pNode head = (pNode)malloc(sizeof(node));
    FILE *fp = fopen("stuinfo.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    fseek(fp,0,SEEK_SET);
 
    pNode pCur = head;

    while (!feof(fp))
    {
        pNode pNew = (pNode)malloc(sizeof(node));
        memset(pNew, 0, sizeof(node));

        // 注意中间格式，文件中数据什么格式，eg:id和姓名信息之间空一格，则格式中"%s %s"之间也要严格按照空一格
        fscanf(fp, "%s\t%s\t%s\t%d\t%f\t%f\t%f\n", pNew->info.id, pNew->info.name, pNew->info.sex,
             &pNew->info.old, &pNew->info.chinese, &pNew->info.math, &pNew->info.english);

        pCur->next = pNew;
        pCur = pNew;
    }

    pNode ptr = head;
    if (NULL == ptr->next)
    {
        printf("当前文件中还没有存储信息！\n");
        fclose(fp);
        return -1;
    }

    printf("load file information success!\n");
    fclose(fp);
 
    showInfo(head);
 
 
    system("pause");
    return  0;

}