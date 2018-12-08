/**
 * Project Untitled
 */


#include "Elite/Model/IntNode.h"
#include <stdlib.h>
#include "Utils/string_formatter.h"
/**
 * IntNode implementation
 */

namespace Elite {

IntNode* IntNode::Create(const char* num) {
	return new IntNode(num);
}

IntNode::IntNode(const char* num) {
	value = atoi(num);
}

void IntNode::printSelf() {
}

NodeType IntNode::getType() {
	return int_node_t;
}

}