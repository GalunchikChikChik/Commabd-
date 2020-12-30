#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>

using namespace std;


void getaLine(string& inStr);

char getaChar();

//////////////////// класс Client //////////////////
class Client
{
private:
	string name;
	int warehouse;


public:
	Client(string n, int warehs);
	~Client();
	int getWareHouse();
	string getName();
};

///////////////////класс ClientList //////////////////////// 

class ClientList
{
private:

	list <Client*> setPtrsClients;
	list <Client*>::iterator iter;
public:
	~ClientList();
	void insertClient(Client*);
	int getWareHouseNumber(string);
	void display();
};
////////////////класс ClientInputScreen//////////////////// 

class ClientInputScreen

{
private:
	ClientList* ptrClientList;
	string tName;
	int warehousenumber;
public:
	ClientInputScreen(ClientList* ptrTL) : ptrClientList(ptrTL)
	{

	}
	void setClient();
};

//////////////////// класс PaymentString //////////////////////////

class PaymentString
{
private:

	int warehousenumber;

	float monthpay[12];
public:
	PaymentString(int);
	void setPay(int, float);
	float getSumOfPayMonth();

	int getWareHouseNumber();

	float getPaymentMonth(int);
};

//////////////////// class PaymentList ///////////////////////

class PaymentList{};

//////////////////// class PayInputScreen //////////////////

class PayInputScreen{};

///////////////////////класс Loss///////////////////////

class Loss{};

///////////////////класс LossList/////////////////////

class LossList{};

////////////////класс LossInputScreen///////////////////

class LossInputScreen{};

//////////////////класс YearReport///////////////////////

class YearReport{};

//////////////////Класс UserInterface//////////////////////

class UserInterface{};

