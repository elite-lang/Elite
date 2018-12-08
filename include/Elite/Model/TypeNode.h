/* 
* @Author: sxf
* @Date:   2015-11-19 11:22:12
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-25 15:47:07
*/

#ifndef TYPE_NODE_H
#define TYPE_NODE_H

#include "Elite/Model/Node.h"

// namespace llvm {
// 	class Type;
// } // llvm

namespace Elite {
class TypeNode: public Node {
public: 
	static TypeNode* Create(const char* name, bool is_const = false, bool is_source = false);
	// LValue typeGen(CodeGenContext* context); 
	void addDimension();
	bool isArray() {
		return dimension == 0;
	}

	virtual NodeType getType();
	virtual std::string& getStr();
	virtual std::string getTypeName();

	virtual Node* copy() {
		return new TypeNode(*this);
	}
protected:
	virtual void printSelf();
	std::string str;	
	std::string name;
	bool is_const = false;
	bool is_source = false; // 这个只在函数是结构体时有用，来设置真正的原型类型
	int dimension = 0;
	TypeNode(const char* name, bool is_const = false, bool is_source = false);
};

}

#endif // TYPE_NODE_H
