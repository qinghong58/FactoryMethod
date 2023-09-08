#pragma once
#include<iostream>
#include <string>
using namespace std;

//产品风格基类
class ProductStyle
{
public:
	virtual ~ProductStyle() {};
	virtual string UsefulStyle() const = 0;
};

class ModernProductStyle :public ProductStyle
{
public:
	string UsefulStyle()const override
	{
		return "选择了现代风格的产品";
	}
};

class VictorianProductStyle :public ProductStyle
{
public:
	string UsefulStyle()const override
	{
		return "选择了维多利亚风格的产品";
	}
};

class ArtDecoProductStyle :public ProductStyle
{
public:
	string UsefulStyle()const override
	{
		return "选择了装饰风格的产品";
	}
};