#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>

using namespace std;


void getaLine(string& inStr);

char getaChar();

//////////////////// ����� Client //////////////////
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

///////////////////����� ClientList //////////////////////// 

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
////////////////����� ClientInputScreen//////////////////// 

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

//////////////////// ����� PaymentString //////////////////////////

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

///////////////////////����� Loss///////////////////////

class Loss{};

///////////////////����� LossList/////////////////////

class LossList{};

////////////////����� LossInputScreen///////////////////

class LossInputScreen{};

//////////////////����� YearReport///////////////////////

class YearReport{};

//////////////////����� UserInterface//////////////////////

class UserInterface{};

