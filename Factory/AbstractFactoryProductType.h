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
		return "��ѡ��������";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "��ѡ�������� (" + result + ")";
	}
};

class Sofa :public ProductType
{
public:
	string product()const override
	{
		return "��ѡ����ɳ��";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "��ѡ����ɳ�� (" + result + ")";
	}
};


class CoffeeTable :public ProductType
{
public:
	string product()const override
	{
		return "��ѡ���˿�����";
	}

	string AnotherProduct(const ProductStyle& collaborator)const override
	{
		const string result = collaborator.UsefulStyle();
		return "��ѡ���˿����� (" + result + ")";
	}
};