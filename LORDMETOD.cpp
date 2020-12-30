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