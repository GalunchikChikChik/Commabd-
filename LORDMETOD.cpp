#include <iostream> 
#include <string> 
#include "LORD.h" 

char getaChar()
{
	char ch;
	while (true)
	{
		ch = getchar();
		if (ch != '\n')
		{
			break;
		}
	}
	getchar();
	return ch;
}

void getaLine(string& inStr)
{
	char temp[21];
	cin.get(temp, 20, '\n');
	cin.ignore(20, '\n');
	inStr = temp;
}

////////////////методы класса Client/////////////////////// 
Client::Client(string n, int warehs) : name(n), warehouse(warehs)
{

}

Client::~Client()
{

}

int Client::getWareHouse()
{
	return warehouse;
}

string Client::getName()
{
	return name;
}
///////////метод класса ClientInputScreen////////////////// 

void ClientInputScreen::setClient()
{
	cout « "Введите наименование клиента: " « endl;
	getaLine(tName);
	cout « "Введите номер склада: " « endl;
	cin » warehousenumber;
	cin.ignore(80, '\n');
	Client* ptrClient = new Client(tName, warehousenumber);
	ptrClientList->insertClient(ptrClient);
}
void ClientInputScreen::setClient()
{
	cout « "Введите наименование клиента: " « endl;
	getaLine(tName);
	cout « "Введите номер склада: " « endl;
	cin » warehousenumber;
	cin.ignore(80, '\n');
	Client* ptrClient = new Client(tName, warehousenumber);
	ptrClientList->insertClient(ptrClient);
}
void ClientList::insertClient(Client* ptrT)
{
	bool exists = false;
	for (iter = setPtrsClients.begin(); iter != setPtrsClients.end(); iter++)
	{
		if ((*iter)->getWareHouse() == ptrT->getWareHouse())
		{
			exists = true;
			break;
		}
	}
	if (!exists)
		setPtrsClients.push_back(ptrT);
	else
	{

		delete ptrT;
		cout « "\nСклад забронирован ";
	}
}
int ClientList::getWareHouseNumber(string tName)
{
	int warehousenumber;
	iter = setPtrsClients.begin();
	while (iter != setPtrsClients.end())
	{
		warehousenumber = (*iter)->getWareHouse();
		if (tName == ((*iter)->getName()))
		{
			return warehousenumber;
		}
		iter++;
	}
	return -1;
}


void ClientList::display()
{
	cout « "\n№Скл\tНаименование клиента\n-------------------\n";
	if (setPtrsClients.empty())
		cout « " Клиенты отсутствуют \n" « endl;
	else
	{
		iter = setPtrsClients.begin();
		while (iter != setPtrsClients.end())
		{
			cout «(*iter)->getWareHouse() « " || " «(*iter)->getName() « endl;
			*iter++;
		}
	}
}

/////////////////методы класса PaymentList ///////////////// 

PaymentList::~PaymentList()
{
	while (!setPtrsRR.empty())
	{
		iter = setPtrsRR.begin();
		delete* iter;
		setPtrsRR.erase(iter);
	}
}

void PaymentList::insertPay(int warehousenumber, int month, float amount)
{

	iter = setPtrsRR.begin();
	while (iter != setPtrsRR.end())
	{
		if (warehousenumber == (*iter)->getWareHouseNumber())
		{
			(*iter)->setPay(month, amount);
			return;
		}
		else
			iter++;
	}
	PaymentString* ptrRow = new PaymentString(warehousenumber);
	ptrRow->setPay(month, amount);
	setPtrsRR.push_back(ptrRow);
}

void PaymentList::display()
{
	cout « "\n№Скл\tЯнв Фев Мар Апр Май Июн Июл Авг Сен Окт Ноя Дек\n" « endl
		« "------------------------------------------------------------------\n" « endl;
	if (setPtrsRR.empty())
		cout « " Доходы отсутствуют \n" « endl;
	else
	{
		iter = setPtrsRR.begin();
		while (iter != setPtrsRR.end())
		{
			cout «(*iter)->getWareHouseNumber() « '\t';
			for (int j = 0; j < 12; j++)
			{
				if (((*iter)->getPaymentMonth(j)) == 0)
					cout « " 0 ";
				else
					cout «(*iter)->getPaymentMonth(j) « " ";
			}
			cout « endl;
			iter++;
		}
		cout « endl;
		cout « endl;
	}
}

float PaymentList::getSumOfGeneralPay()
{
	float

		sumRents = 0.0;
	iter = setPtrsRR.begin();

	while (iter != setPtrsRR.end())
	{
		sumRents += (*iter)->getSumOfPayMonth();
		iter++;
	}
	return sumRents;
}

/////////////////методы класса PayInputScreen///////////// 

void PayInputScreen::setPay()
{
	cout « "Введите наименование клиента: ";
	getaLine(nameclient);

	warehousenumber = ptrClientList->getWareHouseNumber(nameclient);
	if (warehousenumber > 0)
	{

		cout « "Введите доход: " « endl;
		cin » payment;
		cin.ignore(80, '\n');
		cout « "Введите номер месяца оплаты (1-12): " « endl;
		cin » month;
		cin.ignore(80, '\n');
		month--;

		ptrPaymentList->insertPay(warehousenumber, month, payment);
	}
	else
	{
		cout « "\n —-------------------------";
		cout « "\nКлиент отсутствует в списке\n ";
		cout « " —-------------------------";
	}
}