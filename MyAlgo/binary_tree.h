#ifndef MYALGO_BINARY_TREE_H_
#define MYALGO_BINARY_TREE_H_

#include <stdint.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
struct Node
{
    Node(int64_t num) :data(num), left(nullptr), right(nullptr) {}
    int64_t data;
    Node* left;
    Node* right;
};

struct DNode
{
    DNode(Node* snode) :node(snode), rb(false) {};
    Node* node;
    bool rb;
};

class BinaryTree
{
public:
    BinaryTree() {}
    virtual ~BinaryTree() 
    {
        delete[] root_;
        root_ = nullptr;
    }

public:
    /* original binary tree
    *                   6（root）
    *          5（one）    		7（two）
    *   0(three）	2（four）			  9（five）
    *           8(six)    12(seven)   24(eight)  66(nine)
    *     42(ten)                        26(eleven)     68(twelve)
    *         54(thirteen)            30(fourteen)
    *                                      37(fifteen)
    *                                  77(sixteen)
    *                          79(seventeen)   83(eighteen)
    *                       81(ninteen)
    */

    /* inverted binary tree
    *                   6
    *              7        5
    *          9	     2     0
    *      66    24   12   8
    *    68    26             42
    *            30         54
    *          37
    *            77
    *          83  79
    *                81
    */

    // construct original binary tree
    int Initialize()
    {
        Node* node = new Node[20]{6,5,7,0,2,9,8,12,24,66,42,26,68,54,30,37,77,79,83,81};
        node[0].left = &node[1];
        node[0].right = &node[2];

        node[1].left = &node[3];
        node[1].right = &node[4];

        node[2].right = &node[5];

        node[4].right = &node[7];
        node[4].left = &node[6];

        node[5].left = &node[8];
        node[5].right = &node[9];

        node[6].left = &node[10];

        node[8].right = &node[11];

        node[9].right = &node[12];
        
        node[10].right = &node[13];

        node[11].left = &node[14];

        node[14].right = &node[15];

        node[15].left = &node[16];

        node[16].left = &node[17];

        node[16].right = &node[18];

        node[17].left = &node[19];

        root_ = &node[0];
        
        return 0;
    }

    // front ergodic, recursion
    int FrontErgodic(const Node* node, std::vector<int64_t>& vec, int level = 0)
    {
        //root-left-right
        if (nullptr == node) return 0;

        vec.push_back(level);
        vec.push_back(node->data);

        if (nullptr != node->left)
        {
            FrontErgodic(node->left, vec, level + 1);
        }

        if (nullptr != node->right)
        {
            FrontErgodic(node->right, vec, level + 1);
        }

        return 0;
    }

    // front ergodic, none recursion
    int FrontErgodic_Regular(Node* node, std::vector<int64_t>&vec) //非递归
    {
        if (nullptr == node) return 0;
        //root-left-right
        std::stack<Node*> stack;

        Node* snode = node;

        while (1)
        {
            stack.push(snode);
            vec.push_back(snode->data);

            if (nullptr != snode->left)
            {
                snode = snode->left;
                continue;
            }
            else
            {
                while (1)
                {
                    if (stack.empty())
                    {
                        return 0;
                    }

                    snode = stack.top();
                    stack.pop();
                    if (nullptr != snode->right)
                    {
                        snode = snode->right;
                        break;
                    }
                }
            }
        }
    }

    // mid ergodic, recursion
    int MidErgodic(const Node* node, std::vector<int64_t>& vec, int level = 0)
    {
        //left-root-right
        if (nullptr == node) return 0;

        if (nullptr != node->left)
        {
            MidErgodic(node->left, vec, level + 1);
        }

        vec.push_back(level);
        vec.push_back(node->data);        

        if (nullptr != node->right)
        {
            MidErgodic(node->right, vec, level + 1);
        }

        return 0;
    }

    // mid ergodic, none recursion
    int MidErgodic_Regular(Node* node, std::vector<int64_t>&vec) //非递归
    {
        if (nullptr == node) return 0;
        //root-left-right
        std::stack<Node*> stack;

        Node* snode = node;

        while (1)
        {
            stack.push(snode);
            //vec.push_back(snode->data);

            if (nullptr != snode->left)
            {
                snode = snode->left;
                continue;
            }
            else
            {
                
                while (1)
                {
                    if (stack.empty())
                    {
                        return 0;
                    }
                    snode = stack.top();
                    stack.pop();
                    vec.push_back(snode->data);

                    if (nullptr != snode->right)
                    {
                        snode = snode->right;
                        break;
                    }
                }
            }
        }
    }

    // back ergodic, recursion
    int BackErgodic(const Node* node, std::vector<int64_t>& vec, int level = 0)
    {
        //left-right-root
        if (nullptr == node) return 0;

        if (nullptr != node->left)
        {
            BackErgodic(node->left, vec, level + 1);
        }

        if (nullptr != node->right)
        {
            BackErgodic(node->right, vec, level + 1);
        }

        vec.push_back(level);
        vec.push_back(node->data);
        
        return 0;
    }

    // back ergodic, none recursion
    int BackErgodic_Regular(Node* node, std::vector<int64_t>&vec) //非递归
    {
        if (nullptr == node) return 0;
        //root-left-right
        std::stack<DNode*> stack;
        std::stack<DNode*> stack_base;
        Node* snode = node;
        DNode* dnode = new DNode(snode);
        dnode->rb = false;
        stack.push(dnode);

        while (1)
        {
            if (nullptr != snode->left)
            {
                snode = snode->left;

                DNode* dnode = new DNode(snode);
                dnode->rb = false;
                stack.push(dnode);
            }
            else
            {
                while (1)
                {
                    if (stack.empty())
                    {
                        while (!stack_base.empty())
                        {
                            vec.push_back(stack_base.top()->node->data);
                            stack_base.pop();
                        }
                        return 0;
                    }

                    DNode* dno = stack.top();
                    snode = stack.top()->node;
                    stack.pop();
                    if (nullptr != snode->right)
                    {
                        DNode* dnode = new DNode(snode);
                        stack_base.push(dnode);

                        snode = snode->right;

                        DNode* dnode2 = new DNode(snode);
                        dnode2->rb = true;
                        stack.push(dnode2);
                        break;
                    }
                    else
                    {
                        vec.push_back(snode->data);
                        if (/*弹出节点是右节点*/true == dno->rb)
                        {
                            while (!stack.empty() && !stack_base.empty())
                            {
                                vec.push_back(stack_base.top()->node->data);
                                if ((stack.top()->node->left && stack.top()->node->left == stack_base.top()->node) 
                                    || (stack.top()->node->right && stack.top()->node->right == stack_base.top()->node))
                                {
                                    stack_base.pop();
                                    break;
                                }
                                stack_base.pop();
                            }
                        }
                    }
                }
            }
        }
    }

    // level erodic
    int LevelErgodic(Node* node, std::vector<int64_t>&vec)
    {
        if (nullptr == node) return 0;

        std::queue<Node*> que;
        Node* snode = node;
        que.push(snode);

        while (1)
        {
            if (0 >= que.size())
                return 0;

            snode = que.front();
            if (nullptr != snode->left)
            {
                que.push(snode->left);
            }
            if (nullptr != snode->right)
            {
                que.push(snode->right);
            }
            vec.push_back(snode->data);
            que.pop();
        }

        return 0;
    }

    // left view of binary tree
    int LeftView(std::vector<int64_t>& vec)
    {
        vec.clear();
        std::vector<int64_t> front_vec;
        std::map<int64_t, void*> repeat_checker;
        FrontErgodic(root_, front_vec);

        if (0 >= front_vec.size()) return 0;

        for (size_t i = 0; i < front_vec.size();)
        {
            if (repeat_checker.end() == repeat_checker.find(front_vec[i]))
            {
                vec.push_back(front_vec[i + 1]);
                repeat_checker.insert(std::pair<int64_t, void*>(front_vec[i], nullptr));
            }
            i++; i++;
        }

        return 0;
    }

    // right view of binary tree
    int RightView(std::vector<int64_t>& vec)
    {
        vec.clear();
        std::vector<int64_t> back_vec;
        std::map<int64_t, void*> repeat_checker;
        BackErgodic(root_, back_vec);

        if (0 >= back_vec.size()) return 0;

        for (int32_t i = back_vec.size() - 1; i >= 0;)
        {
            if (repeat_checker.end() == repeat_checker.find(back_vec[i - 1]))
            {
                vec.push_back(back_vec[i]);
                repeat_checker.insert(std::pair<int64_t, void*>(back_vec[i - 1], nullptr));
            }
            i--; i--;
        }

        return 0;
    }

    // invert binary tree
    int Invert(Node* node)
    {
        if (nullptr == node)
        {
            return 0;
        }
        Node* snode = node;
        if (nullptr != snode->left || nullptr != snode->right)
        {
            Node* tmp = snode->left;
            snode->left = snode->right;
            snode->right = tmp;
        }

        if (nullptr != snode->left)
        {
            Invert(snode->left);
        }
        if (nullptr != snode->right)
        {
            Invert(snode->right);
        }

        return 0;

    }

    inline Node* root() { return root_; }

protected:
    Node* root_{ nullptr };
};

#endif //MYALGO_BINARY_TREE_H_