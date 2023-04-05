#include "stuSystem.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 202x-3-18
int main()
{

    pNode head = (pNode)malloc(sizeof(node));
    memset(head, 0, sizeof(node));
    strcpy(head->info.name, "头结点");
    LoadFile(head);

    int pow = power();

    if (1 == pow)
    {

        int select = 100;
        while (1)
        {

            printf("请输入您的用户名和密码：");
            char name[20];
            char code[20];
            scanf("%s %s", name, code);
            if ((strcmp(name, "sys") == 0) && (strcmp(code, "235") == 0))
            {

                while (1)
                {
                    select = SysMenu();

                    switch (select)
                    {

                    case 1:
                        ShowInfo(head);
                        break;
                    case 2:
                        AddInfo(head);
                        break;
                    case 3:
                        DeleteInfo(head);
                        break;
                    case 4:
                        FindInfo(head);
                        break;
                    case 5:
                        UpdateInfo(head);
                        break;
                    case 8:
                        // BubbleSort(head);
                       //  break;
                    case 0:
                        ExitSystem(head);
                        break;
                    default:
                        printf("你的输入选项不存在,请重新输入你的选项!\n");
                        break;
                    }
                    if (0 == select)
                    {
                        break;
                    }
                }
            }
            else
            {
                if (strcmp(name, "sys") != 0 && strcmp(code, "235") != 0)
                {
                    printf("您输入的用户名和密码均错误,请重新输入!\n");
                }
                else if (strcmp(name, "sys") != 0)
                {
                    printf("您输入的用户名错误，请重新输入!\n");
                }
                else
                {
                    printf("您输入的密码错误,请重新输入!\n");
                }
            }

            if (0 == select)
            {
                break;
            }
        }
    }
    else
    {

        int select = 100;
        while (1)
        {

            printf("请输入您的用户名和密码：");
            char name[20];
            char code[20];
            scanf("%s %s", name, code);
            if ((strcmp(name, "stu") == 0) && (strcmp(code, "357") == 0))
            {

                while (1)
                {
                    select = StuMenu();
                    switch (select)
                    {

                    case 1:
                        ShowInfo(head);
                        break;
                    case 2:
                        AddInfo(head);
                        break;
                    case 3:
                        FindInfo(head);
                        break;
                    case 0:
                        ExitSystem(head);
                        break;
                    default:
                        printf("你的输入选项不存在,请重新输入你的选项!\n");
                        break;
                    }

                    if (0 == select)
                    {
                        break;
                    }
                }
            }
            else
            {

                if (strcmp(name, "stu") != 0 && strcmp(code, "357") != 0)
                {
                    printf("您输入的用户名和密码均错误,请重新输入!\n");
                }
                else if (strcmp(name, "stu") != 0)
                {

                    printf("您输入的用户名错误，请重新输入!\n");
                }
                else
                {
                    printf("您输入的密码错误,请重新输入!\n");
                }
            }

            if (0 == select)
            {
                break;
            }
        }
    }
    system("pause");
    return 0;
}