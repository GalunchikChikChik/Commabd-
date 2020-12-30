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

////////////////������ ������ Client/////////////////////// 
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
///////////����� ������ ClientInputScreen////////////////// 

void ClientInputScreen::setClient()
{
	cout � "������� ������������ �������: " � endl;
	getaLine(tName);
	cout � "������� ����� ������: " � endl;
	cin � warehousenumber;
	cin.ignore(80, '\n');
	Client* ptrClient = new Client(tName, warehousenumber);
	ptrClientList->insertClient(ptrClient);
}
void ClientInputScreen::setClient()
{
	cout � "������� ������������ �������: " � endl;
	getaLine(tName);
	cout � "������� ����� ������: " � endl;
	cin � warehousenumber;
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
		cout � "\n����� ������������ ";
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
	cout � "\n����\t������������ �������\n-------------------\n";
	if (setPtrsClients.empty())
		cout � " ������� ����������� \n" � endl;
	else
	{
		iter = setPtrsClients.begin();
		while (iter != setPtrsClients.end())
		{
			cout �(*iter)->getWareHouse() � " || " �(*iter)->getName() � endl;
			*iter++;
		}
	}
}

/////////////////������ ������ PaymentList ///////////////// 

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
	cout � "\n����\t��� ��� ��� ��� ��� ��� ��� ��� ��� ��� ��� ���\n" � endl
		� "------------------------------------------------------------------\n" � endl;
	if (setPtrsRR.empty())
		cout � " ������ ����������� \n" � endl;
	else
	{
		iter = setPtrsRR.begin();
		while (iter != setPtrsRR.end())
		{
			cout �(*iter)->getWareHouseNumber() � '\t';
			for (int j = 0; j < 12; j++)
			{
				if (((*iter)->getPaymentMonth(j)) == 0)
					cout � " 0 ";
				else
					cout �(*iter)->getPaymentMonth(j) � " ";
			}
			cout � endl;
			iter++;
		}
		cout � endl;
		cout � endl;
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

/////////////////������ ������ PayInputScreen///////////// 

void PayInputScreen::setPay()
{
	cout � "������� ������������ �������: ";
	getaLine(nameclient);

	warehousenumber = ptrClientList->getWareHouseNumber(nameclient);
	if (warehousenumber > 0)
	{

		cout � "������� �����: " � endl;
		cin � payment;
		cin.ignore(80, '\n');
		cout � "������� ����� ������ ������ (1-12): " � endl;
		cin � month;
		cin.ignore(80, '\n');
		month--;

		ptrPaymentList->insertPay(warehousenumber, month, payment);
	}
	else
	{
		cout � "\n �-------------------------";
		cout � "\n������ ����������� � ������\n ";
		cout � " �-------------------------";
	}
}