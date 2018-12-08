/*
* @Author: sxf
* @Date:   2015-09-22 19:21:40
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-10 18:19:23
*/

#include "Elite/Model/nodes.h"
#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include "elegantlist.hpp"


Node::Node() {
}

Node::Node(Node* n) {
}

Node::~Node() {

}

Node* Node::Create(Node* n) {
	return new Node(n);
}

Node* Node::Create() {
	return new Node();
}


Node* Node::copy() {
	return new Node(*this);
}

Node* Node::copyAll() {
	Node* n = copy();
	return n;
}


void Node::print(int k) {

}

void Node::printSelf() {
	Node::el.print("Node");
}

NodeType Node::getType() {
	return node_t;
}

bool Node::isSingle() {
	return true;
}

Node* Node::getList(Node* node) {
	if (!node->isSingle()) return new Node(node);
	return node;
}

bool Node::isNode() {
	return getType() == node_t;
}

bool Node::isIntNode() {
	return getType() == int_node_t;
}

bool Node::isFloatNode() {
	return getType() == float_node_t;
}

bool Node::isIDNode() {
	return getType() == id_node_t;
}

bool Node::isStringNode() {
	return getType() == string_node_t;
}

bool Node::isCharNode() {
	return getType() == char_node_t;
}

bool Node::isTypeNode() {
	return getType() == type_node_t;
}


std::string Node::getTypeName() {
	switch (getType()) {
		case node_t: return "Node";
		case int_node_t: return "IntNode";
		case string_node_t: return "StringNode";
		case id_node_t: return "IDNode";
		case char_node_t: return "CharNode";
		case float_node_t: return "FloatNode";
		case type_node_t: return "TypeNode";
	}
}

std::string& Node::getStr() {
	std::cerr << "getStr() - 获取字符串错误, 该类型不正确: " << getTypeName() << std::endl;
	exit(1);
}

ElegantList Node::el;
