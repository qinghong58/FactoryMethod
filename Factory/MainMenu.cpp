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
	cout << "为什么不听话，要乱选？？？" << endl;
}

void TypeChoose()
{
	system("cls");
	int flag = 0;
	cout << "欢迎来到家具物流系统" << endl;
	cout << "===========================" << endl;
	cout << "1.运输方式" << endl;
	cout << "2.货物选择" << endl;
	cout << "===========================" << endl;


	cout << "请按顺序选择:";
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
	cout << "选择适合的运输方式" << endl;
	cout << "===========================" << endl;
	cout << "1.公路运输" << endl;
	cout << "2.水路运输" << endl;
	cout << "===========================" << endl;


	cout << "请选择:(1和2):";
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
	cout << "选择喜欢的产品类型" << endl;
	cout << "===========================" << endl;
	cout << "1.现代风格" << endl;
	cout << "2.维多利亚风格" << endl;
	cout << "3.装饰风格" << endl;
	cout << "===========================" << endl;


	cout << "请选择:(1~3):";
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

//可以自己选择各自类型下的产品，比如选1->1,1->2,1->3,也可以1->2,2->2,1->3,但是目前只能按顺序输出，并且多余的不会输出


//待优化
string  ModernProduct()
{
	system("cls");
	int flag = 0;
	cout << "选择您喜欢的现代类型的产品" << endl;
	cout << "===========================" << endl;
	cout << "1.椅子" << endl;
	cout << "2.沙发" << endl;
	cout << "3.咖啡桌" << endl;
	cout << "===========================" << endl;

	cout << "请选择:(1~3):";
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
	cout << "选择您喜欢的维多利亚类型的产品" << endl;
	cout << "===========================" << endl;
	cout << "1.椅子" << endl;
	cout << "2.沙发" << endl;
	cout << "3.咖啡桌" << endl;
	cout << "===========================" << endl;

	cout << "请选择:(1~3):";
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
	cout << "选择您喜欢的艺术风格的产品" << endl;
	cout << "===========================" << endl;
	cout << "1.椅子" << endl;
	cout << "2.沙发" << endl;
	cout << "3.咖啡桌" << endl;
	cout << "===========================" << endl;

	cout << "请选择:(1~3):";
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