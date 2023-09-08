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
		return "{ѡ���ù�·��������䷽ʽ}";
	}

	Truck() = default;
};

class Ship:public Transport
{
public:
	string Type()const override
	{
		return "{ѡ����ˮ����������䷽ʽ}";
	}
};
