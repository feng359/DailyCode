#include <iostream>

using namespace std;

//冒泡排序
void bubble_sort(int arr[], int size)
{

    for (int idx = 0; idx < size - 1; idx++)  //少一趟和自己比较
    {

        for (int idy = 0; idy < size - 1 - idx; idy++) //每比较x次，就有x个最大的元素位于后面的x个固定位置，则下一次就相应的少x比较,
        {
            if (arr[idy] > arr[idy + 1])
            {
                int tmp = arr[idy];
                arr[idy] = arr[idy + 1];
                arr[idy + 1] = tmp;
            }
        }
    }
}


//快速排序(基于分治思想，对冒泡排序进行了改进)
int partion(int arr[], int left, int right)
{

    int pivot = arr[left]; //将最左边的一个元素作为中枢值赋给pivit,此时arr[left]这个位置相当于空着，恰好给后面从右往左找到的元素腾出了位置
    while (left < right)
    {
        while (arr[right] >= pivot && left < right) //先从右往左找比中枢值小的元素
            right--;
        arr[left] = arr[right];                 //将从右往左第一个比中枢值（pivot）小的元素放在前面中枢值腾出的位置中arr[left]，此时arr[right]这个位置空着给后面从左往右找到的元素腾出了位置
        while (arr[left] < pivot && left < right) //再从左往右找比中枢值大于等于的元素
            left++;
        arr[right] = arr[left]; //将从左往右找到的元素放在前面从右往左进行时腾出的位置arr[right]中，同时为下一次从右往左找到的元素腾出了位置arr[left]
    }
    arr[right] = pivot; //(最外层的while结束时，此时left和right指向同一位置，此位置空着，将最开始的中枢值元素怒pivit放在此位置，值相同arr[left]=pivot也可
    return left;      // return right也可
}

void quick_sort(int arr[], int left, int right)
{
    if (left < right) //必须加if判断边界条件，防止越界出错
    {
        int piv = partion(arr, left, right); //对初始序列调用排序后，不断地对左右子序列递归调用
        quick_sort(arr, left, piv - 1);
        quick_sort(arr, piv + 1, right);
    }
}

void bubbleSortTest()
{

    int arr[10] = {7, 8, 5, 1, 10, 3, 6, 2, 4, 9};

    cout << "数组初始元素为:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;

    bubble_sort(arr, 10);

    cout << "数组bubble_sort()后元素为:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;
}


void quickSortTest()
{

    int arr[10] = {4, 8, 5, 1, 9, 3, 6, 2, 7, 10};

    cout << "数组初始元素为:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;

    quick_sort(arr, 0, 9);

    cout << "数组quick_sort()后元素为:" << endl;
    for (auto elem : arr)
    {
        cout << elem << " ";
    };
    cout << endl;
}


int main()
{
    //冒泡排序
    bubbleSortTest();

    //快速排顺序
    quickSortTest();

    system("pause");
    return 0;
}