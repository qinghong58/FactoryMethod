#pragma once
#include<iostream>
#include<string>
#include"AbstractFactoryProductStyle.h"
#include"AbstractFactoryProductType.h"
using namespace std;

class AbstractFactoryProduct
{
public:
	virtual ProductStyle* CreateProductStyle()const = 0;
	virtual ProductType* CreateProductType()const = 0;
};

class ChairFactory :public AbstractFactoryProduct
{
public:
	ProductStyle* CreateProductStyle()const override
	{
		return new ModernProductStyle();
	}
	ProductType* CreateProductType()const override
	{
		return new Chair();
	}
};

class SofaFactory :public AbstractFactoryProduct
{
public:
	ProductStyle* CreateProductStyle()const override
	{
		return new VictorianProductStyle();
	}
	ProductType* CreateProductType()const override
	{
		return new Sofa();
	}
};

class CoffeeTableFactory :public AbstractFactoryProduct
{
public:
	ProductStyle* CreateProductStyle()const override
	{
		return new ArtDecoProductStyle();
	}
	ProductType* CreateProductType()const override
	{
		return new CoffeeTable();
	}
};
