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

class ClientList{};

////////////////����� ClientInputScreen////////////////////

class ClientInputScreen{};

//////////////////// ����� PaymentString //////////////////////////

class PaymentString{};

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

