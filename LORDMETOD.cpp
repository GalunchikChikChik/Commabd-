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
/////////////////методы класса PaymentString///////////////////// 

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

//////////////////методы класса LossList//////////////

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
	cout « "\nДата\tПолучатель\tСумма\tКатегория\n"
		« "----------------------------------------\n" « endl;
	if (vectPtrsExpenses.size() == 0)
		cout « " Расходы отсутствуют \n" « endl;
	else
	{
		iter = vectPtrsExpenses.begin();
		while (iter != vectPtrsExpenses.end())
		{
			cout «(*iter)->month « '/' «(*iter)->day « '\t' «(*iter)->payee « '\t' « '\t';
			cout «(*iter)->amount « '\t' «(*iter)->category « endl;
			iter++;
		}
		cout « endl;
	}
}

float LossList::displaySummary()
{
	float totalLoss = 0;
	if (vectPtrsExpenses.size() == 0)
	{
		cout « "\tВсе категории\t0\n";
		return 0;
	}
	iter = vectPtrsExpenses.begin();
	while (iter != vectPtrsExpenses.end())
	{

		cout « '\t' «((*iter)->category) « '\t' «((*iter)->amount) « endl;
		totalLoss += (*iter)->amount;
		iter++;
	}
	return totalLoss;
}

//////////////методы класса LossInputScreen/////////////


LossInputScreen::LossInputScreen(LossList* per) : ptrLossList(per)
{

}

void LossInputScreen::setLoss()
{
	int month, day;
	string category, payee;
	float amount;
	cout « "Введите месяц (1-12): ";
	cin » month;
	cin.ignore(80, '\n');
	cout « "Введите день (1-31): ";
	cin » day;
	cin.ignore(80, '\n');
	cout « "Введите категорию расходов: ";
	getaLine(category);
	cout « "Введите получателя: ";
	getaLine(payee);
	cout « "Введите сумму: ";
	cin » amount;
	cin.ignore(80, '\n');

	Loss* ptrLoss = new Loss(month, day, category, payee, amount);

	ptrLossList->insertLoss(ptrLoss);
}

////////////////методы класса YearReport/////////////////

YearReport::YearReport(PaymentList* pRR, LossList* pER) : ptrRR(pRR), ptrER(pER)
{

}

void YearReport::display()
{
	cout « "Годовой отчет\n--------------\n" « endl;
	cout « "Доходы\n" « endl;
	cout « "\tОбщая выручка:\t\t";
	payments = ptrRR->getSumOfGeneralPay();
	cout « payments « endl;
	cout « "Расходы\n" « endl;
	loss = ptrER->displaySummary();
	cout « "Общие расходы:\t\t";
	cout « loss « endl;

	cout « "\nПрибыль:\t\t\t" «(payments - loss) « endl;
}

////////////////методы класса UserInterface//////////////

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
		cout « " \n —-------МЕНЮ-----------\n"
			« " Ввод данных 'i', \n"
			« " Отчеты 'd', \n"
			« " Выход 'q': \n"
			« " —----------------------\n";
		ch = getaChar();
		if (ch == 'i')
		{
			cout « " —----------------------\n"
				« " Добавление клиента 't', \n"
				« " Добавление статьи дохода'r', \n"
				« " Добавление статьи расхода 'e': \n"
				« "

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
				cout « " \n-----------------ОШИБКА----------------------";
				cout « " Выберите необходимую функцию из меню \n";
				cout « " —-------------------------------------------";

				break;
			}
		}
		else if (ch == 'd')
		{
			cout « " \n------------------------\n"
				« " Список клиентов 't' \n"
				« " Список доходов 'r' \n"
				« " Список расходов 'e' \n"
				« " Годовой отчет 'a' \n"
				« " —-----------------";
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

				cout « " \n-----------------ОШИБКА----------------------";
				cout « " Выберите необходимую функцию вывода \n";
				cout « " —-------------------------------------------";

				break;
			}
		}
		else if (ch == 'q')
			return;
		else
			cout « " —-----------------";
	}
}