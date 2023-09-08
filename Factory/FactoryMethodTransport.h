#pragma once
#include<iostream>
#include<string>

using namespace std;

class Transport
  {
public:
	virtual ~Transport() {}
	virtual string Type() const = 0;

};

class Truck : public Transport
{
public:
	string Type()const override
	{
		return "{选择用公路运输的运输方式}";
	}

	Truck() = default;
};

class Ship:public Transport
{
public:
	string Type()const override
	{
		return "{选择用水运运输的运输方式}";
	}
};
