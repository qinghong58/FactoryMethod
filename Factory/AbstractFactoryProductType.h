#pragma once
#include<iostream>
#include<string>
#include"AbstractFactoryProductStyle.h"
using namespace std;


class ProductType
{
public:
	virtual ~ProductType() {};
	virtual string product()const = 0;
	virtual string AnotherProduct(const ProductStyle& product)const = 0;
};

class Chair :public ProductType
{
public:
	string product()const override
	{
		return "你选择了椅子";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "你选择了椅子 (" + result + ")";
	}
};

class Sofa :public ProductType
{
public:
	string product()const override
	{
		return "你选择了沙发";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "你选择了沙发 (" + result + ")";
	}
};


class CoffeeTable :public ProductType
{
public:
	string product()const override
	{
		return "你选择了咖啡桌";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "你选择了咖啡桌 (" + result + ")";
	}
};