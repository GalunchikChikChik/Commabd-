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