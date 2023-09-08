#include<iostream>
#include<string>
#include<ctime>
#include<Windows.h>
#include"FactoryMethodlogistics.h"
#include"FactoryMethodTransport.h"
#include"AbstractFactoryCreateProduct.h"
#include"AbstractFactoryProductStyle.h"
#include"AbstractFactoryProductType.h"


using namespace std;

string TransportMode();
string ProductTypeChoose();
string ModernProduct();
string VictorianProduct();
string ArtDecoProduct();
void worning();

string Style,Type,TypeInt[3];
string ChairProduct, SofaProduct, CoffeeTableProduct;
string ModProductStyle, VicProductStyle, ArtProductStyle;
string ModeofTransportation;
int CountNum = 0;

string ClientCodeStyle(const AbstractFactoryProduct& factory)
{
	const ProductStyle* product_style = factory.CreateProductStyle();
	Style = product_style->UsefulStyle();

	delete product_style;
	return Style;

}

string ClientCodeType(const AbstractFactoryProduct& factory)
{
	const ProductType* product_type = factory.CreateProductType();
	Type = product_type->product();

	delete product_type;
	return Type;
}

void worning()
{
	cout << "Ϊʲô��������Ҫ��ѡ������" << endl;
}

void TypeChoose()
{
	system("cls");
	int flag = 0;
	cout << "��ӭ�����Ҿ�����ϵͳ" << endl;
	cout << "===========================" << endl;
	cout << "1.���䷽ʽ" << endl;
	cout << "2.����ѡ��" << endl;
	cout << "===========================" << endl;


	cout << "�밴˳��ѡ��:";
	cin >> flag;

	if (flag==1)
	{
		TransportMode();
	}


	else if (flag==2)
	{
		ProductTypeChoose();
	}
	else
	{
		worning();
		Sleep(2000);
		TypeChoose();
	}


}


string TransportMode()
{

	system("cls");
	int flag = 0;
	cout << "ѡ���ʺϵ����䷽ʽ" << endl;
	cout << "===========================" << endl;
	cout << "1.��·����" << endl;
	cout << "2.ˮ·����" << endl;
	cout << "===========================" << endl;


	cout << "��ѡ��:(1��2):";
	cin >> flag;

	if (flag == 1)
	{
		Transport* trunk = new Truck();
		ModeofTransportation = trunk->Type();
		ProductTypeChoose();
	}
	if (flag==2)
	{
		Transport* ship = new Ship();
		ModeofTransportation = ship->Type();
		ProductTypeChoose();
	}
	system("cls");
	return ModeofTransportation;
}

string ProductTypeChoose()
{
	system("cls");
	int flag = 0;
	cout << "ѡ��ϲ���Ĳ�Ʒ����" << endl;
	cout << "===========================" << endl;
	cout << "1.�ִ����" << endl;
	cout << "2.ά�����Ƿ��" << endl;
	cout << "3.װ�η��" << endl;
	cout << "===========================" << endl;


	cout << "��ѡ��:(1~3):";
	cin >> flag;
	CountNum++;
	if (CountNum<=2)
	{
		if (flag == 1)
		{
			ChairFactory* chair = new ChairFactory();
			ModProductStyle = ClientCodeStyle(*chair);

			delete chair;
			ModernProduct();
			return ModProductStyle;

		}
		else if (flag == 2)
		{
			SofaFactory* sofa = new SofaFactory();
			VicProductStyle = ClientCodeStyle(*sofa);

			delete sofa;
			VictorianProduct();
			return VicProductStyle;



		}
		else if (flag == 3)
		{
			CoffeeTableFactory* coffeetable = new CoffeeTableFactory();
			ArtProductStyle = ClientCodeStyle(*coffeetable);

			delete coffeetable;
			ArtDecoProduct();
			return ArtProductStyle;

		}
		else
		{
			worning();
			Sleep(2000);
			ProductTypeChoose();
		}
	}
	else
	{
		return "tiaoxuanwanbi";
	}
}

//�����Լ�ѡ����������µĲ�Ʒ������ѡ1->1,1->2,1->3,Ҳ����1->2,2->2,1->3,����Ŀǰֻ�ܰ�˳����������Ҷ���Ĳ������


//���Ż�
string  ModernProduct()
{
	system("cls");
	int flag = 0;
	cout << "ѡ����ϲ�����ִ����͵Ĳ�Ʒ" << endl;
	cout << "===========================" << endl;
	cout << "1.����" << endl;
	cout << "2.ɳ��" << endl;
	cout << "3.������" << endl;
	cout << "===========================" << endl;

	cout << "��ѡ��:(1~3):";
	cin >> flag;

	if (flag == 1)
	{
		ChairFactory* chair = new ChairFactory();
		ChairProduct= ClientCodeType(*chair);

		delete chair;
		ProductTypeChoose();
		return ChairProduct;

	}
	else if (flag == 2)
	{
		SofaFactory* sofa = new SofaFactory();
		SofaProduct = ClientCodeType(*sofa);
		delete sofa;
		ProductTypeChoose();
		return SofaProduct;

	}
	else if (flag == 3)
	{
		CoffeeTableFactory* coffeetable = new CoffeeTableFactory();
		CoffeeTableProduct = ClientCodeType(*coffeetable);
		delete coffeetable;
		ProductTypeChoose();
		return CoffeeTableProduct;

	}
	else
	{
		worning();
		Sleep(2000);
		ModernProduct();
	}

}
string VictorianProduct()
{
	system("cls");
	int flag = 0;
	cout << "ѡ����ϲ����ά���������͵Ĳ�Ʒ" << endl;
	cout << "===========================" << endl;
	cout << "1.����" << endl;
	cout << "2.ɳ��" << endl;
	cout << "3.������" << endl;
	cout << "===========================" << endl;

	cout << "��ѡ��:(1~3):";
	cin >> flag;

	if (flag == 1)
	{
		//ModernProduct();
		ChairFactory* chair = new ChairFactory();
		ChairProduct = ClientCodeType(*chair);
		delete chair;
		ProductTypeChoose();
		return ChairProduct;

	}
	else if (flag == 2)
	{
		//VictorianProduct();
		SofaFactory* sofa = new SofaFactory();
		SofaProduct = ClientCodeType(*sofa);

		delete sofa;
		ProductTypeChoose();
		return SofaProduct;


	}
	else if (flag == 3)
	{

		//ArtDecoProduct();
		CoffeeTableFactory* coffeetable = new CoffeeTableFactory();
		CoffeeTableProduct = ClientCodeType(*coffeetable);
		delete coffeetable;
		ProductTypeChoose();
		return CoffeeTableProduct;

	}
	else
	{
		worning();
		Sleep(2000);
		VictorianProduct();
	}
}

string ArtDecoProduct()
{
	system("cls");
	int flag = 0;
	cout << "ѡ����ϲ�����������Ĳ�Ʒ" << endl;
	cout << "===========================" << endl;
	cout << "1.����" << endl;
	cout << "2.ɳ��" << endl;
	cout << "3.������" << endl;
	cout << "===========================" << endl;

	cout << "��ѡ��:(1~3):";
	cin >> flag;

	if (flag == 1)
	{
		ChairFactory* chair = new ChairFactory();
		ChairProduct = ClientCodeType(*chair);
		delete chair;
		ProductTypeChoose();
		return ChairProduct;
	}
	else if (flag == 2)
	{

		SofaFactory* sofa = new SofaFactory();
		SofaProduct = ClientCodeType(*sofa);

		delete sofa;
		ProductTypeChoose();
		return SofaProduct;

	}
	else if (flag == 3)
	{

		CoffeeTableFactory* coffeetable = new CoffeeTableFactory();
		CoffeeTableProduct = ClientCodeType(*coffeetable);
		delete coffeetable;
		ProductTypeChoose();
		return CoffeeTableProduct;

	}
	else
	{
		worning();
		Sleep(2000);
		ArtDecoProduct();
	}
}


int main()
{
	TypeChoose();
	string modern = ModernProduct();
	cout << ModProductStyle << VicProductStyle << ArtProductStyle << endl;
	cout << ModeofTransportation << endl;
	cout << ChairProduct << CoffeeTableProduct << SofaProduct << endl;

	return 0;
}