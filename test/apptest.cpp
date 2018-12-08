/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-11-14
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-11-14
* @License: MIT License
*/

#include <gtest/gtest.h>
#include "Elite/Model/nodes.h"

using namespace Elite;

TEST(ModelTest, Basic) {
    Node* node = FloatNode::Create("3.1415926");
    EXPECT_NE(node, nullptr);
}