#include "stuSystem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power()
{

    printf("|-------+-------+-------+-------+-------+-------|\n");
    printf("\t\twelcome to stuSystem!\n");
    printf("|-------+-------+-------+-------+-------+-------|\n");
    printf("请选择择您的用户权限 0-普通用户  |  1-特权用户 : ");
    int pow;
    scanf("%d", &pow);
    return pow;
}

int SysMenu()
{
    printf("\t\t\t\t+-------+--------+--------+--------+-------+\n");
    printf("\t\t\t\t|******************************************|\n");
    printf("\t\t\t\t|-------+- ------+-- -----+--- ----+-------|\n");
    printf("\t\t\t\t|*******|                          |*******|\n");
    printf("\t\t\t\t|*******|      1-显示学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      2-添加学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      3-删除学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      4-查找学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      5-修改学生信息      |*******|\n");
    // printf("\t\t\t****  8-学生信息排序  ****\n");
    printf("\t\t\t\t|*******|      0-退出学生系统      |*******|\n");
    printf("\t\t\t\t|*******|                          |*******|\n");
    printf("\t\t\t\t|-------+--------+--------+--------+-------|\n");
    printf("\t\t\t\t|******************************************|\n");
    printf("\t\t\t\t+-------+--------+--------+--------+-------+\n");
    
    printf("请输入您的选项编号:\n");
    int select;
    scanf("%d", &select);
    return select;
}

int StuMenu()
{

    printf("\t\t\t\t+-------+--------+--------+--------+-------+\n");
    printf("\t\t\t\t|******************************************|\n");
    printf("\t\t\t\t|-------+- ------+-- -----+--- ----+-------|\n");
    printf("\t\t\t\t|*******|                          |*******|\n");
    printf("\t\t\t\t|*******|      1-显示学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      2-添加学生信息      |*******|\n");
    printf("\t\t\t\t|*******|      3-查找学生信息      |*******|\n");
    // printf("\t\t\t****  8-学生信息排序  ****\n");
    printf("\t\t\t\t|*******|      0-退出学生系统      |*******|\n");
    printf("\t\t\t\t|*******|                          |*******|\n");
    printf("\t\t\t\t|-------+--------+--------+--------+-------|\n");
    printf("\t\t\t\t|******************************************|\n");
    printf("\t\t\t\t+-------+--------+--------+--------+-------+\n");
    
    printf("请输入您的选项编号:\n");
    int select;
    scanf("%d", &select);
    return select;
}

void ExitSystem(pNode head)
{
    if(NULL == head ){
        printf("head is null\n");
        return;
    }

    //此处释放所有结点包括头结点，而且要打印所有结点中的name信息，因此在最开始创造头结点时必须进行初始化,否则打印出垃圾信息。
    pNode pCur = head;

    printf("free node: ");
    while(NULL != head){
        pCur = head;
        printf("%s ",pCur->info.name);
        head = head->next; //注意：此语句不可放在free之后，因为此时head和pcur指向同一结点，free(pcur)后再用head访问这块已经释放的内存会造成段错误。
        free(pCur);
    }

    puts("");
    printf("已退出学生管理系统,欢迎您的再次使用!\n");
    return;
}

void LoadFile(pNode head)
{

    //"r" 打开一个用于读取的文件。该文件必须存在rr
    //"w" 创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
    //"a" 追加到一个文件。写操作向文件末尾追加数据。如果文件不存在，则创建文件。
    // 后跟+号，表示读写均可;eg:"r+"打开一个用于更新的文件，可读取也可写入。该文件必须存在。
    FILE *fp = fopen("stuinfo.txt", "r");
    if (NULL == fp)
    {
        perror("fopen");
        return;
    }

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (0 == len)
    {
        printf("当前文件中还没有存储信息！\n");
        fclose(fp);
        return;
    }

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

    printf("load file information success!\n");
    fclose(fp);
}

void SaveFile(pNode head)
{
    FILE *fp = fopen("stuinfo.txt", "w");
    if (NULL == fp)
    {
        perror("fopen");
        return;
    }

    pNode pCur = head;

    while (pCur->next != NULL)
    {

        fprintf(fp, "%s\t%s\t%s\t%d\t%f\t%f\t%f\n", pCur->next->info.id, pCur->next->info.name, pCur->next->info.sex,
                pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
        pCur = pCur->next;
    }
    // fprintf(fp, "%s %s %s %d %f %f %f", pCur->info.id, pCur->info.name, pCur->info.sex,
    //       pCur->info.old, pCur->info.chinese, pCur->info.math, pCur->info.english);

    fclose(fp);
}

void ShowInfo(pNode head)
{
    pNode pCur = head;

    if (pCur->next == NULL)
    {
        printf("目前还没录入任何信息\n");
        return;
    }

    while (pCur->next != NULL)
    {

        printf("\t\t\t\t|-------+-------+-------+-------+-------+-------+-------|\n");
        printf("\t\t\t\t|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
               pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
        printf("\t\t\t\t|-------+-------+-------+-------+-------+-------+-------|\n");
        pCur = pCur->next;
    }
}

void AddInfo(pNode head)
{

    while (1)
    {
        printf("请输入学生信息 id,姓名,性别,年龄,语文,数学,英语:");

        pNode pCur = head; // pCur用来指向尾结点；

        while (pCur->next != NULL)
        {
            pCur = pCur->next;
        }

        pNode pNew = (pNode)malloc(sizeof(node)); // pNew指向的结点用来存储添加的信息
        pNew->next = NULL;
        scanf("%s %s %s %d %f %f %f", pNew->info.id, pNew->info.name, pNew->info.sex,
              &pNew->info.old, &pNew->info.chinese, &pNew->info.math, &pNew->info.english);
        pCur->next = pNew; // 尾插法将新结点链接到尾部
        SaveFile(head);
        printf("add information success!\n");

        printf("1-继续添加  0-不再添加: ");
        int select = 0;
        scanf("%d", &select);
        if (0 == select)
        {
            return;
        }
    }
}

void FindInfo(pNode head)
{
    pNode pCur = head;
    printf("1-根据id查找  2-根据name查找:");
    int select = 0;
    scanf("%d", &select);
    puts("");
    if (1 == select)
    {
        system("cls");
        printf("请输入你要查找学生信息的id号:");
        char findId[20];
        scanf("%s", findId);
        puts("");
        while (NULL != pCur->next)
        {
            if (strcmp(pCur->next->info.id, findId) == 0)
            {
                printf("查到id为 %s 的学生信息如下所示:\n", findId);
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                printf("|%-7s|%-7s|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "Id", "Name", "Sex", "Old", "Chinese", "Math", "English");
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");

                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                printf("|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
                       pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                break;
            }
            pCur = pCur->next;
            if (NULL == pCur->next)
            {
                printf("经过查找id为 %s 的学生信息不存在！\n", findId);
                // 此处无需break跳出循环，因为最后一个结点next=NULL,下一轮NULL != pCur->next不满足条件，自动跳出循环
            }
        }
    }
    else
    {
        system("cls");

        printf("请输入你要查找学生信息的name:");
        char findName[20];
        scanf("%s", findName);
        puts("");

        while (NULL != pCur->next)
        {
            if (strcmp(pCur->next->info.name, findName) == 0)
            {
                printf("查到name为 %s 的学生信息如下所示:\n", findName);
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                printf("|%-7s|%-7s|%-7s|%-7s|%-7s|%-7s|%-7s|\n", "Id", "Name", "Sex", "Old", "Chinese", "Math", "English");
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");

                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                printf("|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
                       pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
                printf("|-------+-------+-------+-------+-------+-------+-------|\n");
                break;
            }
            pCur = pCur->next;
            if (NULL == pCur->next)
            {
                printf("经过查找name为 %s 的学生信息不存在！\n", findName);
            }
        }
    }
}

#if 0
void BubbleSort(pNode head)
{

    int len = 0;
    pNode pCur = head, p, q, pre;
    while (NULL != pCur->next)
    {
        len++;
        pCur = pCur->next;
    }

    for (int idx = 0; idx < len - 1; idx++)
    {
        //外层循环次数是进行排序的趟数，每趟都要从头开始进行后面的这趟次数比较
        pre = head;
        p = head->next;
        q = p->next;

        //内层循环次数是每次排序需要进行比较的次数，随着趟数的增加，每次需要比较的次数也减少
        for (int idy = 0; idy < len - idx - 1; idy++)
        {

            //    if(NULL == pCur->next){break;};
            if (p->info.id > q->info.id)
            {
                p->next = q->next; // 此处交换不同于数组直接进行值交换，而是修改链表指向，间接完成交换
                q->next = p;
                pre->next = p;
            }
            //虽然上面可能交换时将p和q指针次序打乱，但是有了pre指针位置是固定的每次增加一步，pre指针指向不会打乱，p和q指针依据pre指针又将位置重置到开始的次序，
            //pre还有一个作用是p和q若没有上面的交换，每次比较都能根据pre指针的固定位置增加自己的次序。
            pre = pre->next;
            p = pre->next;
            q = p->next;
        }
        //            if(NULL == pCur->next){break;};
    }

    showInfo(head);
}
#endif

void DeleteInfo(pNode head)
{
    pNode pCur = head;
    printf("1-根据id删除  2-根据name删除:");
    int select = 0;
    scanf("%d", &select);
    puts("");

    if (1 == select)
    {

        system("cls");
        printf("请输入你要删除学生信息的id号:");
        char delId[20];
        scanf("%s", delId);
        puts("");

        while (1)
        {

            while (NULL != pCur->next)
            {
                if (strcmp(pCur->next->info.id, delId) == 0)
                {
                    pNode ptr = pCur->next;
                    pCur->next = pCur->next->next;
                    free(ptr);
                    ptr = NULL;
                    printf("已成功删除id为 %s 的学生信息！\n", delId);
                    SaveFile(head);
                    break;
                }
                pCur = pCur->next;
                if (NULL == pCur->next) // 如果要删除的学生信息存在，则一定会在上面删除，如果不存在，则找到最后一个结点其next为NULL
                {
                    printf("经查找不存在id为 %s 的学生信息，你的输入有误\n", delId);
                    // 不用break最后一结点next为NULL在下一轮循环不满足条件自动跳出循环
                }
            }

            break;
        }
    }
    else
    {

        system("cls");
        printf("请输入你要删除学生信息的name:");
        char delName[20];
        scanf("%s", delName);
        puts("");

        while (1)
        {

            while (NULL != pCur->next)
            {
                if (strcmp(pCur->next->info.name, delName) == 0)
                {
                    pNode ptr = pCur->next;
                    pCur->next = pCur->next->next;
                    free(ptr);
                    ptr = NULL;
                    printf("已成功删除name为 %s 的学生信息！\n", delName);
                    SaveFile(head);
                    break;
                }
                pCur = pCur->next;
                if (NULL == pCur->next)
                {
                    printf("经查找不存在name为 %s 的学生信息，你的输入有误\n", delName);
                }
            }

            break;
        }
    }
}

void UpdateInfo(pNode head)
{

    pNode pCur = head;

    printf("请输入你需要修改学生信息的id号:");
    char updateId[20];
    scanf("%s", updateId);

    while (NULL != pCur->next)
    {
        if (strcmp(pCur->next->info.id, updateId) == 0)
        {
            // 打印修改前的学生信息
            printf("id号为 %s 的学生当前信息如下所示：\n", updateId);
            printf("\t\t|-------+-------+-------+-------+-------+-------+-------|\n");
            printf("\t\t|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
                   pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
            printf("\t\t|-------+-------+-------+-------+-------+-------+-------|\n");

            // 进行修改
            char id[20], name[20], sex[10];
            int old;
            float chinese, math, english;
            printf("请输入你需要修改后的学生完整信息:");
            scanf("%s %s %s %d %f %f %f", pCur->next->info.id, pCur->next->info.name, pCur->next->info.sex,
                  &pCur->next->info.old, &pCur->next->info.chinese, &pCur->next->info.math, &pCur->next->info.english);
            printf("已成功修改id号为 %s 的学生信息,且此学生修改后的信息如下所示：\n", updateId);

            //打印修改后的学生信息
            printf("\t\t|-------+-------+-------+-------+-------+-------+-------|\n");
            printf("\t\t|%-7s|%-7s|%-7s|%-7d|%-7.2f|%-7.2f|%-7.2f|\n", pCur->next->info.id, pCur->next->info.name,
                   pCur->next->info.sex, pCur->next->info.old, pCur->next->info.chinese, pCur->next->info.math, pCur->next->info.english);
            printf("\t\t|-------+-------+-------+-------+-------+-------+-------|\n");
            SaveFile(head);
            break;
        }

        pCur = pCur->next;
        if (pCur->next == NULL)
        {
            printf("经查找不存在id号为 %s 的学生学生，你的输入有误！", updateId);
        }
    }
}
