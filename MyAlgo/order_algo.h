#ifndef MYALGO_ORDER_ALGO_H_
#define MYALGO_ORDER_ALGO_H_


#include <stdint.h>
#include <iostream>
#include <stack>

#define ARR_NUM 12

class OrderAlgo
{
public:
    OrderAlgo() {};
    virtual ~OrderAlgo() {};

public:
    //bubble sort
    void BubbleSort()
    {
        init_arr();
        show_arr("original:");
        bubblesort();
        show_arr("bubble  :");
    }

    //quick sort, recursion
    void QuickSort()
    {
        init_arr();
        show_arr("original:");
        quicksort(g_origin_arr, 0, ARR_NUM - 1);
        show_arr("quick   :");
    }

    //quick sort, none recursion
    void QuickSort_Regular()
    {
        init_arr();
        show_arr("original:");
        quicksort_regular();
        show_arr("quick   :");
    }

protected:
    void init_arr()
    {
        g_origin_arr[0] = 85;
        g_origin_arr[1] = 32;
        g_origin_arr[2] = 99;
        g_origin_arr[3] = 53;
        g_origin_arr[4] = 18;
        g_origin_arr[5] = 66;
        g_origin_arr[6] = 22;
        g_origin_arr[7] = 36;
        g_origin_arr[8] = 10;
        g_origin_arr[9] = 11;
        g_origin_arr[10] = 1;
        g_origin_arr[11] = 39;
    }

    void show_arr(const char* status)
    {
        std::cout << status;
        for (auto i : g_origin_arr)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    void bubblesort()
    {
        for (int i = 0; i < ARR_NUM - 1; ++i)
        {
            for (int j = 0; j < ARR_NUM - i - 1; ++j)
            {
                if (g_origin_arr[j] > g_origin_arr[j + 1])
                {
                    uint64_t tmp = g_origin_arr[j];
                    g_origin_arr[j] = g_origin_arr[j + 1];
                    g_origin_arr[j + 1] = tmp;
                }
            }
        }
    }

    void quicksort(uint64_t* arr, int begin, int end)
    {
        if (begin >= end)
        {
            return;
        }

        int idx_b = begin, idx_e = end;
        int base_idx = (idx_b + idx_e) / 2;
        while (1)
        {
            while (idx_b < base_idx && arr[idx_b] <= arr[base_idx])
            {
                idx_b++;
                continue;
            }
            while (idx_e > base_idx && arr[idx_e] >= arr[base_idx])
            {
                idx_e--;
                continue;
            }

            if (idx_b == idx_e)//相等时，说明：基点左边的值都小于等于基点的值，基点右边的值都大于等于基点的值.此时idx_b==idx_e==base_idx
            {
                break;
            }

            //数据交换
            uint64_t tmp = arr[idx_b];
            arr[idx_b] = arr[idx_e];
            arr[idx_e] = tmp;

            if (idx_e == base_idx)//说明idx_b和基准点进行了数据交换，此时基准点变化(数值变大)，右半部需要重新比较，所以idx_e需要重置为初始值，重新扫描
            {
                idx_e = end;
            }
            else if (idx_b == base_idx)//说明idx_e和基准点进行了数据交换，此时基准点变化(数值变小)，左半部需要重新比较，所以idx_b需要重置为初始值，重新扫描
            {
                idx_b = begin;
            }
        }
        quicksort(arr, begin, base_idx - 1);
        quicksort(arr, base_idx + 1, end);
    }

    void quicksort_regular()
    {
        std::stack<std::pair<int, int>> stack_pos;

        stack_pos.push(std::pair<int, int>(0, ARR_NUM - 1));

        while (!stack_pos.empty())
        {
            auto pos = stack_pos.top();
            stack_pos.pop();
            int idx_b = pos.first, idx_e = pos.second;
            int base_idx = (idx_b + idx_e) / 2;
            uint64_t* arr = g_origin_arr;

            while (1)
            {
                while (idx_b < base_idx && arr[idx_b] <= arr[base_idx])
                {
                    idx_b++;
                    continue;
                }
                while (idx_e > base_idx && arr[idx_e] >= arr[base_idx])
                {
                    idx_e--;
                    continue;
                }

                if (idx_b == idx_e)//相等时，说明：基点左边的值都小于等于基点的值，基点右边的值都大于等于基点的值.此时idx_b==idx_e==base_idx
                {
                    break;
                }

                //数据交换
                uint64_t tmp = arr[idx_b];
                arr[idx_b] = arr[idx_e];
                arr[idx_e] = tmp;

                if (idx_e == base_idx)//说明idx_b和基准点进行了数据交换，此时基准点变化(数值变大)，右半部需要重新比较，所以idx_e需要重置为初始值，重新扫描
                {
                    idx_e = pos.second;
                }
                else if (idx_b == base_idx)//说明idx_e和基准点进行了数据交换，此时基准点变化(数值变小)，左半部需要重新比较，所以idx_b需要重置为初始值，重新扫描
                {
                    idx_b = pos.first;
                }
            }

            if (base_idx > pos.first)
            {
                stack_pos.push(std::pair<int,int>(pos.first, base_idx - 1));
            }
            if (pos.second > base_idx)
            {
                stack_pos.push(std::pair<int, int>(base_idx + 1, pos.second));
            }
        }
    }
protected:
    uint64_t g_origin_arr[ARR_NUM];
};

#endif //MYALGO_ORDER_ALGO_H_