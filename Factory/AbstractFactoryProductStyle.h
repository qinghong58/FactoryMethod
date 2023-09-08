#pragma once
#include<iostream>
#include <string>
using namespace std;

//��Ʒ������
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
		return "ѡ�����ִ����Ĳ�Ʒ";
	}
};

class VictorianProductStyle :public ProductStyle
{
public:
	string UsefulStyle()const override
	{
		return "ѡ����ά�����Ƿ��Ĳ�Ʒ";
	}
};

class ArtDecoProductStyle :public ProductStyle
{
public:
	string UsefulStyle()const override
	{
		return "ѡ����װ�η��Ĳ�Ʒ";
	}
};