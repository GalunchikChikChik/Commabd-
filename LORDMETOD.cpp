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
/////////////////������ ������ PaymentString///////////////////// 

PaymentString::PaymentString(int an) : warehousenumber(an)
{
	fill(&monthpay[0], &monthpay[12], 0);
}

void PaymentString::setPay(int m, float am)
{
	monthpay[m] = am;
}

int PaymentString::getWareHouseNumber()
{
	return warehousenumber;
}

float PaymentString::getPaymentMonth(int month)
{
	return monthpay[month];
}

float PaymentString::getSumOfPayMonth()
{
	return accumulate(&monthpay[0], &monthpay[12], 0);
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

//////////////////������ ������ LossList//////////////

LossList::~LossList()
{

	while (!vectPtrsExpenses.empty())
	{
		iter = vectPtrsExpenses.begin();
		delete *iter;
		vectPtrsExpenses.erase(iter);
	}
}

void LossList::insertLoss(Loss* ptrExp)
{

	vectPtrsExpenses.push_back(ptrExp);
}

void LossList::display()
{
	cout � "\n����\t����������\t�����\t���������\n"
		� "----------------------------------------\n" � endl;
	if (vectPtrsExpenses.size() == 0)
		cout � " ������� ����������� \n" � endl;
	else
	{
		iter = vectPtrsExpenses.begin();
		while (iter != vectPtrsExpenses.end())
		{
			cout �(*iter)->month � '/' �(*iter)->day � '\t' �(*iter)->payee � '\t' � '\t';
			cout �(*iter)->amount � '\t' �(*iter)->category � endl;
			iter++;
		}
		cout � endl;
	}
}

float LossList::displaySummary()
{
	float totalLoss = 0;
	if (vectPtrsExpenses.size() == 0)
	{
		cout � "\t��� ���������\t0\n";
		return 0;
	}
	iter = vectPtrsExpenses.begin();
	while (iter != vectPtrsExpenses.end())
	{

		cout � '\t' �((*iter)->category) � '\t' �((*iter)->amount) � endl;
		totalLoss += (*iter)->amount;
		iter++;
	}
	return totalLoss;
}

//////////////������ ������ LossInputScreen/////////////


LossInputScreen::LossInputScreen(LossList* per) : ptrLossList(per)
{

}

void LossInputScreen::setLoss()
{
	int month, day;
	string category, payee;
	float amount;
	cout � "������� ����� (1-12): ";
	cin � month;
	cin.ignore(80, '\n');
	cout � "������� ���� (1-31): ";
	cin � day;
	cin.ignore(80, '\n');
	cout � "������� ��������� ��������: ";
	getaLine(category);
	cout � "������� ����������: ";
	getaLine(payee);
	cout � "������� �����: ";
	cin � amount;
	cin.ignore(80, '\n');

	Loss* ptrLoss = new Loss(month, day, category, payee, amount);

	ptrLossList->insertLoss(ptrLoss);
}

////////////////������ ������ YearReport/////////////////

YearReport::YearReport(PaymentList* pRR, LossList* pER) : ptrRR(pRR), ptrER(pER)
{

}

void YearReport::display()
{
	cout � "������� �����\n--------------\n" � endl;
	cout � "������\n" � endl;
	cout � "\t����� �������:\t\t";
	payments = ptrRR->getSumOfGeneralPay();
	cout � payments � endl;
	cout � "�������\n" � endl;
	loss = ptrER->displaySummary();
	cout � "����� �������:\t\t";
	cout � loss � endl;

	cout � "\n�������:\t\t\t" �(payments - loss) � endl;
}

////////////////������ ������ UserInterface//////////////

UserInterface::UserInterface()
{
	ptrClientList = new ClientList;
	ptrPaymentList = new PaymentList;
	ptrLossList = new LossList;
}

UserInterface::~UserInterface()
{
	delete ptrClientList;
	delete ptrPaymentList;
	delete ptrLossList;
}

void UserInterface::interact()
{
	while (true)
	{
		cout � " \n �-------����-----------\n"
			� " ���� ������ 'i', \n"
			� " ������ 'd', \n"
			� " ����� 'q': \n"
			� " �----------------------\n";
		ch = getaChar();
		if (ch == 'i')
		{
			cout � " �----------------------\n"
				� " ���������� ������� 't', \n"
				� " ���������� ������ ������'r', \n"
				� " ���������� ������ ������� 'e': \n"
				� "

				------------------------ - ";
				ch = getaChar();
			switch (ch)
			{

			case 't': ptrClientInputScreen =
				new ClientInputScreen(ptrClientList);
				ptrClientInputScreen->setClient();
				delete ptrClientInputScreen;
				break;

			case 'r': ptrPayInputScreen =
				new PayInputScreen(ptrClientList, ptrPaymentList);
				ptrPayInputScreen->setPay();
				delete ptrPayInputScreen;
				break;
			case 'e': ptrLossInputScreen =
				new LossInputScreen(ptrLossList);
				ptrLossInputScreen->setLoss();
				delete ptrLossInputScreen;
				break;
			default:
				cout � " \n-----------------������----------------------";
				cout � " �������� ����������� ������� �� ���� \n";
				cout � " �-------------------------------------------";

				break;
			}
		}
		else if (ch == 'd')
		{
			cout � " \n------------------------\n"
				� " ������ �������� 't' \n"
				� " ������ ������� 'r' \n"
				� " ������ �������� 'e' \n"
				� " ������� ����� 'a' \n"
				� " �-----------------";
			ch = getaChar();
			switch (ch)
			{
			case 't': ptrClientList->display();
				break;
			case 'r': ptrPaymentList->display();
				break;
			case 'e': ptrLossList->display();
				break;
			case 'a':
				ptrYearReport = new YearReport(ptrPaymentList, ptrLossList);
				ptrYearReport->display();
				delete ptrYearReport;
				break;
			default:

				cout � " \n-----------------������----------------------";
				cout � " �������� ����������� ������� ������ \n";
				cout � " �-------------------------------------------";

				break;
			}
		}
		else if (ch == 'q')
			return;
		else
			cout � " �-----------------";
	}
}