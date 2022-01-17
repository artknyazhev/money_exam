#include "libre.h"
/*Файл с реализацией класса родителя и виртуальных функций*/
class Bank
{
public:
	Bank(){}
	virtual int GetBal()=0;
	virtual void PutMoney() = 0;
	virtual void AddCost() = 0;
	virtual bool IsPin() = 0;
	virtual void Read() = 0;
	virtual void Clear() = 0;
	virtual void GetTopMonth(int mon) = 0;
	virtual void GetTopWeek(int mon, int day) = 0;
	virtual void GetTopCatMonth(int mon) = 0;
	virtual void GetTopCatWeek(int mon, int day) = 0;
	virtual void GetCostsDay(int mon, int day) = 0;
	virtual void GetCostsWeek(int mon, int day) = 0;
	virtual void GetCostsMonth(int mon) = 0;
	~Bank() = default;

private:

};