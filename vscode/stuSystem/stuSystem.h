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


int power();

int SysMenu();

int StuMenu();

void ExitSystem(pNode head);

void LoadFile(pNode head);

void SaveFile(pNode head);

void ShowInfo(pNode head);

void AddInfo(pNode head);

void FindInfo(pNode head);

//void BubbleSort(pNode head);

void DeleteInfo(pNode head);

void UpdateInfo(pNode head);