#include <iostream>
#include "binary_tree.h"
#include "order_algo.h"

int main()
{   
    //BinaryTree
    {
        std::cout << "BinaryTree:" << std::endl;
        BinaryTree bt;
        bt.Initialize();
        std::vector<int64_t> vec;

        bt.Invert(bt.root());



        bt.FrontErgodic(bt.root(), vec);
        std::cout << "Front ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            if (i % 2 == 0)//level
                std::cout << vec[i] << ":";
            else //node info
                std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.FrontErgodic_Regular(bt.root(), vec);
        std::cout << "Front ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << "0:" << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.MidErgodic(bt.root(), vec);
        std::cout << "Mid   ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            if (i % 2 == 0)//level
                std::cout << vec[i] << ":";
            else //node info
                std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.MidErgodic_Regular(bt.root(), vec);
        std::cout << "Mid   ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << "0:" << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.BackErgodic(bt.root(), vec);
        std::cout << "Back  ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            if (i % 2 == 0)//level
                std::cout << vec[i] << ":";
            else //node info
                std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.BackErgodic_Regular(bt.root(), vec);
        std::cout << "Back  ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << "0:" << vec[i] << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.LeftView(vec);
        std::cout << "Left View: ";
        for (auto a : vec)
        {
            std::cout << a << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.RightView(vec);
        std::cout << "Right View: ";
        for (auto a : vec)
        {
            std::cout << a << " ";
        }
        std::cout << std::endl;

        vec.clear();
        bt.LevelErgodic(bt.root(), vec);
        std::cout << "Level ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << "0:" << vec[i] << " ";
        }
        std::cout << std::endl;

        bt.Invert(bt.root());
        vec.clear();
        bt.LevelErgodic(bt.root(), vec);
        std::cout << "Level ergodic: ";
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << "0:" << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    //OrderAlgo
    {
        std::cout << "OrderAlgo:" << std::endl;
        OrderAlgo ord_algo;

        ord_algo.BubbleSort();

        ord_algo.QuickSort();

        ord_algo.QuickSort_Regular();

        ord_algo.MaxHeapSort();
    }

    system("pause");
    return 0;
}