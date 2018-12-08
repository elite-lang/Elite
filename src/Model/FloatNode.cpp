/**
 * Project Untitled
 */


#include "Elite/Model/FloatNode.h"
#include <cstdlib>
/**
 * FloatNode implementation
 */

namespace Elite{

FloatNode::FloatNode(const char* num) {
	value = atof(num);
}

FloatNode* FloatNode::Create(const char* num) {
	return new FloatNode(num);
}

NodeType FloatNode::getType() {
	return float_node_t;
}

std::string FloatNode::getTypeName() {
	return "float_node";
}

float FloatNode::getFloat() {
	return value;
}

void FloatNode::printSelf() {
}

}