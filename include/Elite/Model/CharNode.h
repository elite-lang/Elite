/**
 * Project Untitled
 */


#ifndef _CHARNODE_H
#define _CHARNODE_H

#include "Elite/Model/Node.h"

namespace Elite
{
class CharNode: public Node {
public: 
	char value;

	CharNode(char* v) {
		value = *v;
	}

	// virtual Value* codeGen(CodeGenContext* context); 
};

}
#endif //_CHARNODE_H