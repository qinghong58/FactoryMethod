#pragma once
#include<iostream>
#include<string>
#include"FactoryMethodTransport.h"

using namespace std;

//ÎïÁ÷
class Logistics
{
public:
	virtual ~Logistics() {};
	virtual Transport* LogisticsProduct() const = 0;

	string SomeOperation() const
	{
		Transport* transport = this->LogisticsProduct();
		string result = "Creator: The same creator's code has just worked with" + transport->Type();
		delete transport;
		return result;
	}
};

class ConcreteCreator1 :public Logistics
{
public:
	Transport* LogisticsProduct() const override
	{
		return new Truck();
	}
};

class ConcreteCreator2 :public Logistics
{
public:
	Transport* LogisticsProduct() const override
	{
		return new Ship();
	}
};