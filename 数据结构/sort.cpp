// 多种排序算法，冒泡、插入、选择
// 快排、堆排序、归并

#include <iostream>
#include <vector>
#include <stdio.h>

//冒泡泡，n2 稳定
//不停的交换，两次循环
void Bubble_Sort(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = 0; j < nums.size() - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

//选择排序 n2 不稳定
//找最小交换
void Selection_Sort(std::vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int minidex = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] < nums[minidex])
            {
                minidex = j;
            }
        }
        int tmp = nums[i];
        nums[i] = nums[minidex];
        nums[minidex] = tmp;
    }
}

//插入 n2 稳定
//拉出来，找到合适的位置插入
void Insertion_Sort(std::vector<int> &nums)
{

    for (int i = 1; i < nums.size(); ++i)
    {
        int preindex = i - 1;
        int current = nums[i];
        while (preindex >= 0 && nums[preindex] > current)
        {
            nums[preindex + 1] = nums[preindex];
            preindex--;
        }
        nums[preindex + 1] = current;
    }
}

//快排 不稳定 nlogn
//左右交替移动,挖坑与填坑,分治思想
void help_quick_sort(std::vector<int> &nums, int L, int R)
{
    if (L >= R)
    {
        return;
    }
    int left = L, right = R;
    int pivot = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= pivot)
        {
            right--;
        }
        if (left < right)
        {
            nums[left] = nums[right];
        }
        while (left < right && nums[left] <= pivot)
        {
            left++;
        }
        if (left < right)
        {
            nums[right] = nums[left];
        }
        if (left >= right)
        {
            nums[left] = pivot;
        }
    }
    help_quick_sort(nums, L, right - 1);
    help_quick_sort(nums, right + 1, R);
}

void Quick_Sort(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    help_quick_sort(nums, left, right);
}

//堆排
void swap(std::vector<int> &arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
//从上到下heapify,这个函数默认左右子树已经成为堆，从上往下搞
void heapify(std::vector<int> &nums, int n, int i)
{
    if (i > n)
    {
        return;
    }
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if (c1 < n && nums[c1] > nums[max])
    {
        max = c1;
    }
    if (c2 < n && nums[c2] > nums[max])
    {
        max = c2;
    }

    if (max != i)
    {
        swap(nums, max, i);
        heapify(nums, n, max);
    }
}
//任意数组构建堆，从低往上走
void build_heap(std::vector<int> &nums, int num_heap)
{
    int last_node = num_heap - 1;
    int parent = (last_node - 1) / 2;
    for (int i = parent; i >= 0; --i)
    {
        heapify(nums, num_heap, i);
    }
}
//堆排序,除根，将大的放到数组后面，小的继续构建堆，找最大值
void Heap_Sort(std::vector<int> &nums, int num_heap)
{
    build_heap(nums, num_heap); //建堆
    for (int i = num_heap - 1; i >= 0; --i)
    {
        swap(nums, i, 0);    //去头
        heapify(nums, i, 0); //再整理堆
    }
}

// //归并 有序链表也要试一下
//合并区间的两个子区间

void Merge(std::vector<int> &nums, int left, int mid, int right)
{
    int temp[right - left + 1];
    for (int i = left; i <= right; ++i)
    {
        temp[i - left] = nums[i];
    }
    int i = left, j = mid + 1;
    for (int k = left; k <= right; ++k)
    {
        if (i > mid && j <= right)
        {
            //
            nums[k] = temp[j - left];
            j++;
        }
        else if (j > right && i <= mid)
        {
            //
            nums[k] = temp[i - left];
            i++;
        }
        else if (temp[i - left] > temp[j - left])
        {
            //
            nums[k] = temp[j - left];
            j++;
        }
        else if (temp[i - left] <= temp[j - left])
        {
            //
            nums[k] = temp[i - left];
            i++;
        }
    }
}
void Merge_sort(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    if (left < right)
    {
        int mid = (left + right) / 2; //首先进行分区，然后递归操作
        Merge_sort(nums, left, mid);
        Merge_sort(nums, mid + 1, right); //第一次将其分为两个区间，进行合并操作
        Merge(nums, left, mid, right);
    }
}

void printvector(std::vector<int> &prin_vector)
{
    for (int i = 0; i < prin_vector.size(); ++i)
    {
        std::cout << prin_vector[i];
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<int> nums = {2, 3, 4, 1, 0, 9};
    // std::vector<int> nums = {};//要考虑边界
    printvector(nums);

    //  std::cout<<"冒泡排序"<<std::endl;
    //  Bubble_Sort(nums);

    // std::cout << "选择排序" << std::endl;
    // Selection_Sort(nums);

    // std::cout << "插入排序" << std::endl;
    // Insertion_Sort(nums);

    // std::cout << "快排" << std::endl;
    // Quick_Sort(nums);

    // std::cout << "堆排" << std::endl;
    // Heap_Sort(nums, nums.size());

    std::cout << "归并排" << std::endl;
    Merge_sort(nums, 0, nums.size() - 1);

    printvector(nums);
}
