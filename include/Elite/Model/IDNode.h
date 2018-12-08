/**
 * Project Untitled
 */


#ifndef _IDNODE_H
#define _IDNODE_H

#include "Elite/Model/Node.h"
#include <string>

namespace Elite
{
	
class IDNode: public Node {
public: 
	static IDNode* Create(const char* _value);
	static IDNode* Create(char _value);
	std::string& getStr() { return value; }
	// virtual LValue codeGen(CodeGenContext* context); 
	virtual NodeType getType();
	virtual std::string getTypeName();
	virtual Node* copy() {
		return new IDNode(*this);
	}
protected:
	IDNode(const char* _value);
	IDNode(char _value);
	virtual void printSelf();
private:
	std::string value;
};

} // Elite

#endif //_IDNODE_H