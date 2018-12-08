/**
 * Project Untitled
 */


#ifndef _INTNODE_H
#define _INTNODE_H

#include "Elite/Model/Node.h"

namespace Elite
{
class IntNode: public Node {
public: 
	static IntNode* Create(const char* num);
	// virtual LValue codeGen(CodeGenContext* context); 
	virtual void printSelf();
	virtual NodeType getType();
	virtual std::string getTypeName();
	virtual Node* copy() {
		return new IntNode(*this);
	}
protected:
	IntNode(const char* num);
	int value;
};
} // Elite

#endif //_INTNODE_H