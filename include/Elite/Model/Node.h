/*
 * @Author: sxf
 * @Date:   2015-09-22 19:21:10
 * @Last Modified by:   sxf
 * @Last Modified time: 2015-12-14 17:03:53
 */

#ifndef NODE_H
#define NODE_H

// #include "Elite/LLCG/lvalue.h"
#include <string>

namespace Elite {

enum NodeType {
    seq_node_t = 0,
    list_node_t,
    block_node_t,
    int_node_t,
    float_node_t,
    char_node_t,
    id_node_t,
    string_node_t,
    type_node_t
};

class CodeGenContext;

/**
 * @brief List的基本组成元素，表示一个代码中的基本节点
 * @details 编译器后端代码生成时，会构建Node节点串连起来的语法树
 *
 *          Node节点的类型一般有如下几种(char 暂未使用)： \n
 *          id 		- 标识符 	- 对应NodeType为：id_node_t \n
 *          int 	- 整型 		- 对应NodeType为：int_node_t \n
 *          float 	- 浮点型 	- 对应NodeType为：float_node_t \n
 *          string 	- 字符串 	- 对应NodeType为：string_node_t \n
 *          type 	- 类型 		- 对应NodeType为：type_node_t \n
 *          @see NodeType
 *
 *          一般语法解析器在连接这款后端代码生成器时，只需要控制生成Node构造的语法树即可，
 *          语法树的形状符合RedApple中的定义，即可正确编译为后端代码。
 */
class Node {
public:
    /**
     * @brief 判断当前节点是一个元素, 还是一个链表
     * @details 判断当前节点是一个元素, 还是一个链表,
     * 主要用于getList方法和makeList方法
     *          由于构造语法树时,很多情况不知道要添加的是一个节点还是一个链表.
     *          这个方法可以用来判断.\n
     * @return 有下一个元素，返回true
     */
    bool hasNext();

    /**
     * @brief 判断当前节点是否有孩子
     * @details 判断当前节点是否有孩子, 主要依靠类型判断, 如果是list或block会再检测是否有孩子
     * @return 是单一元素返回true, 是链表返回false
     */
    virtual bool hasChild() { return false; }


    /**
     * @brief 获取下一个元素
     */
    virtual Node* getNext() { return next; }

    /**
     * @brief 如果是list或block, 取得其孩子的头指针
     */
    virtual Node* getChild();


    // 便捷的构造list的方法

    /**
     * @brief C++语言版的接口, 用来方便地构造一个列表
     * @details 用来方便地构造一个列表, make_linked里不定参数如果传入空
     *  则认为到达结尾, 使用时请务必注意
     *
     * @param ... 每个是一个 Node* 指针, 使用NULL结尾
     *
     * @return 构造好的列表的首节点指针
     */
    static Node* make_linked(...);

    /**
     * @brief 其他语言的接口, 用来方便地构造一个列表
     * @details 用来方便地构造一个列表, 功能和 make_linked 一样
     *          @see make_linked()
     *
     * @param num 参数的个数
     * @param plist 一个指针数组
     *
     * @return 构造好的列表的首节点指针
     */
    static Node* makeLinked(int num, Node* plist[]);

    /**
     * @brief 构造一个节点, 并为其添加一个子元素链表
     *
     * @param n 子元素链表, 相当于对空节点添加了孩子
     * @return 新构造的节点
     */
    static Node* CreateList(Node* n);

    /**
     * @brief 构造一个节点, 并为其添加一个子元素链表
     *
     * @param n 子元素链表, 相当于对空节点添加了孩子
     * @return 新构造的节点
     */
    static Node* CreateBlock(Node* n);

    // 全局构造析构

    /**
     * @brief 释放一个节点资源
     * @param p 这里是一个指针的引用, 会自动将指针置为NULL
     */
    static void Free(Node*& p);

    /**
     * @brief 递归释放节点资源
     * @param p 要释放的节点, 这里会递归调用子节点
     */
    static void FreeAll(Node*& p);

    // 拷贝函数
    virtual Node* copy() = 0;
    virtual Node* copyAll();

    // 节点的替换
    // void replaceNext(Node* node);
    // void replaceChild(Node* node);
    // void replaceChildFirst(Node* node);

    /**
     * @brief 可用于调试的打印指令
     * @param k 缩进层次, 首次传0或1皆可
     */
    void print(int k);

    /**
     * @brief 重要的代码生成函数
     * @details 重要的代码生成函数, 对于不同的节点, 会有不同的代码生成策略,
     *          这个函数是多态调用的, 在每个Node的子类中都有相关实现
     *          Node的代码生成会按照表处理, 将第一个元素视为宏名
     *          ID会自动去符号表中查找定义, 返回符号表中存储的变量
     *          Type会自动去符号表中查找, 返回一个类型的定义
     *          Int会自动构造常量数字
     *          String会自动构造常量字符串
     *
     * @param context 代码生成上下文类
     * @return 返回代码生成的结果指针LValue
     */
    // virtual LValue codeGen(CodeGenContext* context);

    // 如果是含有字符串的节点，则返回所含字符串，否则将报错
    /**
     * @brief 获取当前节点内存放的字符串
     * @details 只有含有字符串的节点该函数有效, 目前ID和String有效
     *          如果是普通的节点, 则会报异常
     * @return 返回字符串的引用
     */
    virtual std::string& getStr();

    /**
     * @brief 获取类型名
     * @return 节点的名字
     */
    virtual std::string getTypeName() = 0;

    /**
     * @brief 获取节点类型
     * @return 节点类型的枚举
     */
    virtual NodeType getType() = 0;


    bool isSeq();
    bool isList();
    bool isBlock();
    bool isIntNode();
    bool isFloatNode();
    bool isIDNode();
    bool isStringNode();
    bool isCharNode();
    bool isTypeNode();

protected:
    Node();
	Node(const Node& other);
    virtual ~Node();

    virtual void printSelf();

    Node* next;
};

} // Elite

#endif // NODE_H
