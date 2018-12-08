/* 
* @Author: sxf
* @Date:   2015-09-22 22:00:32
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-25 15:46:49
*/

#ifndef STRING_NODE_H
#define STRING_NODE_H

#include "Elite/Model/Node.h"

namespace Elite {
class StringNode : public Node
{
public:
	static StringNode* Create(const char* _value);
	static StringNode* Create(char _value);
	std::string& getStr() { return value; }
	// virtual LValue codeGen(CodeGenContext* context); 
	virtual NodeType getType();
	virtual std::string getTypeName();
	virtual Node* copy() {
		return new StringNode(*this);
	}
protected:
	virtual void printSelf();
	StringNode(const char* _value);
	StringNode(char _value);
private:
	std::string value;
};

}


#endif // STRING_NODE_H
