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