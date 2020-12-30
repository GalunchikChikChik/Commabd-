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

class PaymentList
{
private:
	list <PaymentString*> setPtrsRR;
	list <PaymentString*>::iterator iter;
public:
	~PaymentList();
	void insertPay(int, int, float);
	void display();
	float getSumOfGeneralPay();
};
//////////////////// class PayInputScreen ////////////////// 

class PayInputScreen
{
private:
	ClientList* ptrClientList;
	PaymentList* ptrPaymentList;
	string nameclient;
	float payment;
	int month;
	int warehousenumber;

public:
	PayInputScreen(ClientList* ptrTL, PaymentList* ptrRR) : ptrClientList(ptrTL),
		ptrPaymentList(ptrRR)
	{

	}
	void setPay();
};

///////////////////////класс Loss///////////////////////

class Loss{
public:
	int month, day;
	string category;
	string payee;
	float amount;
	Loss()
	{ }
	Loss(int m, int d, string c, string p, float a) :
		month(m), day(d), category(c), payee(p), amount(a)
	{

	}
};

///////////////////класс LossList/////////////////////

class LossList{
private:
	vector<Loss*> vectPtrsLoss;
	vector<Loss*>::iterator iter;
public:
	~LossList();
	void insertLoss(Loss*);
	void display();
	float displaySummary();
};

////////////////класс LossInputScreen///////////////////

class LossInputScreen{
private:
	LossList* ptrLossList;
public:
	LossInputScreen(LossList*);
	void setLoss();
};

//////////////////класс YearReport///////////////////////

class YearReport{
private:
	PaymentList* ptrRR;
	LossList* ptrER;
	float loss, payments;
public:
	YearReport(PaymentList*, LossList*);
	void display();
};

//////////////////Класс UserInterface//////////////////////

class UserInterface{
private:
	ClientList* ptrClientList;
	ClientInputScreen* ptrClientInputScreen;
	PaymentList* ptrPaymentList;
	PayInputScreen* ptrPayInputScreen;
	LossList* ptrLossList;
	LossInputScreen* ptrLossInputScreen;
	YearReport* ptrYearReport;
	char ch;
public:

	UserInterface();
	~UserInterface();
	void interact();
};

