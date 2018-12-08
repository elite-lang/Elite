/**
 * Project Untitled
 */


#ifndef _FLOATNODE_H
#define _FLOATNODE_H

#include "Elite/Model/Node.h"
#include <string>

namespace Elite
{
class FloatNode: public Node {
public:
	static FloatNode* Create(const char* num);
	// virtual LValue codeGen(CodeGenContext* context);
	virtual NodeType getType();
	virtual std::string getTypeName();
	
	float getFloat();
	virtual Node* copy() {
		return new FloatNode(*this);
	}
protected:
	void printSelf();
	float value;
	FloatNode(const char* num);
};

}
#endif //_FLOATNODE_H
