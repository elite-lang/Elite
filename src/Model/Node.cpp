/*
* @Author: sxf
* @Date:   2015-09-22 19:21:40
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-10 18:19:23
*/

#include "Elite/Model/nodes.h"
#include <iostream>
#include <stdarg.h>
#include <stdio.h>

namespace Elite {

Node::Node()
{
    next = nullptr;
}

Node::Node(const Node& other)
{
    next = other.next;
}

Node::~Node()
{
}

Node* Node::copyAll()
{
    Node* n = copyAll();
    if (n->next)
        n->next = next->copyAll();
    return n;
}

void Node::print(int k)
{
}

void Node::printSelf()
{
}

bool Node::hasNext()
{
    return next != nullptr;
}

bool Node::isSeq()
{
    return getType() == seq_node_t;
}

bool Node::isBlock()
{
    return getType() == block_node_t;
}

bool Node::isList()
{
    return getType() == list_node_t;
}

bool Node::isIntNode()
{
    return getType() == int_node_t;
}

bool Node::isFloatNode()
{
    return getType() == float_node_t;
}

bool Node::isIDNode()
{
    return getType() == id_node_t;
}

bool Node::isStringNode()
{
    return getType() == string_node_t;
}

bool Node::isCharNode()
{
    return getType() == char_node_t;
}

bool Node::isTypeNode()
{
    return getType() == type_node_t;
}

Node* Node::getChild() { throw FunctionNotImplement("getChild", "Element didn't have children"); }

std::string& Node::getStr()
{
    std::cerr << "getStr() - 获取字符串错误, 该类型不正确: " << getTypeName() << std::endl;
    exit(1);
}


Node* Node::make_linked(...) {
	return nullptr;
}

Node* Node::makeLinked(int num, Node* plist[]) {

	return nullptr;
}


Node* Node::CreateList(Node* n) {
	return nullptr;

}

Node* Node::CreateBlock(Node* n) {

	return nullptr;
}

void Node::Free(Node*& p) {

}

void Node::FreeAll(Node*& p) {

}


} // Elite
