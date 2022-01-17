#include "bank.h"
/*Файл с реализацией дебитовой карты*/
class Debit : public Bank
{
public:
	/*Конструктор*/
	Debit() {
		ifstream fin("dbalance.txt");
		string buf;
		getline(fin, buf);
		balance = stoi(buf);
		fin.close();
	}
	/*Возвращает текущий баланс*/
	int GetBal() { return balance; }
	/*Функция пополнения карты*/
	void PutMoney() {
		int mon;
		if (this->IsPin() == true) {
			cout << "Введите сумму: ";
			cin >> mon;
			if (mon <= 0)
				cout << "\nSystem Error\n";
			else
				balance += mon;
			cout << "\nНовый баланс: " << this->GetBal() << "uah";
		}
	}
	/*Функция добавляющая расход по карте (сумма,категория,дата)*/
	void AddCost() {
		int d, m, ch, mon;
		cout << "---Новый Расход---";
		cout << "\nВведите сумму: ";
		cin >> mon;
		if (mon > this->balance) {
			cout << "\nНедостаточно средств на карте\n";
		}
		else {
			cout << "Введите день: ";
			cin >> d;
			cout << "Введите месяц: ";
			cin >> m;
			cout << "Выберите категорию\n";
			cout << "1->Еда\n";
			cout << "2->Красота и здоровье\n";
			cout << "3->Развлечения\n";
			cout << "4->Техника\n";
			cout << "5->Транспорт\n";
			cout << "6->Кафе\n>>>";
			cin >> ch;
			ofstream fout(files[ch - 1]);
			fout << m << endl;
			fout << d << endl;
			fout << mon << endl;
			balance -= mon;
			fout.close();
		}
	}
	/*Функция проверки пин-кода*/
	bool IsPin() {
		cout << "\nВведите PIN-код: ";
		int buf;
		cin >> buf;
		if (buf == pin)
			return true;
		else {
			cout << "\nНеверный PIN-код\n";
			return false;
		}
	}
	/*Функция считывания затрат по категориям(дата,сумма)*/
	void Read() {
		string str;

		ifstream fin(files[0]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf1.push_back(stoi(str));
		fin.close();

		fin.open(files[1]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf2.push_back(stoi(str));
		fin.close();


		fin.open(files[2]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf3.push_back(stoi(str));
		fin.close();


		fin.open(files[3]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf4.push_back(stoi(str));
		fin.close();


		fin.open(files[4]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf5.push_back(stoi(str));
		fin.close();


		fin.open(files[5]);
		while (getline(fin, str))
			if (str.size() != 0)
				buf6.push_back(stoi(str));
		fin.close();
	}
	/*Функция очистки вектогров хранящих затраты*/
	void Clear() {
		buf.clear();
		buf = { 0,0,0,0,0,0 };
		buf1.clear();
		buf2.clear();
		buf3.clear();
		buf4.clear();
		buf5.clear();
		buf6.clear();
	}
	/*Функция получения топ-3 расхода за определенный месяц*/
	void GetTopMonth(int mon) {
		this->Read();
		
		int max=0;
		int cat=0;
		int index;
		ofstream fout("drating.txt", ios::app);
		cout << "\nТОП-3 затрат за месяц\n";
		fout << "\nТОП-3 затрат за месяц\n";
		for (size_t i = 0; i < 3; i++)
		{
			max = 0;
			if (buf1.empty() == false)
			for (size_t i = 0; i < buf1.size(); i+=3)
			{
				if (buf1[i + 2] > max && buf1[i] == mon) {
					max = buf1[i + 2];
					cat = 0;
					index = i;
				}
			}
			if (buf2.empty() == false)
			for (size_t i = 0; i < buf2.size(); i += 3)
			{
				if (buf2[i + 2] > max && buf2[i] == mon) {
					max = buf2[i + 2];
					cat = 1;
					index = i;
				}
			}
			if (buf3.empty() == false)
			for (size_t i = 0; i < buf3.size(); i += 3)
			{
				if (buf3[i + 2] > max && buf3[i] == mon) {
					max = buf3[i + 2];
					cat = 2;
					index = i;
				}
			}
			if (buf4.empty() == false)
			for (size_t i = 0; i < buf4.size(); i += 3)
			{
				if (buf4[i + 2] > max && buf4[i] == mon) {
					max = buf4[i + 2];
					cat = 3;
					index = i;
				}
			}
			if (buf5.empty() == false)
			for (size_t i = 0; i < buf5.size(); i += 3)
			{
				if (buf5[i + 2] > max && buf5[i] == mon) {
					max = buf5[i + 2];
					cat = 4;
					index = i;
				}
			}
			if (buf6.empty() == false)
			for (size_t i = 0; i < buf6.size(); i += 3)
			{
				if (buf6[i + 2] > max && buf6[i] == mon) {
					max = buf6[i + 2];
					cat = 5;
					index = i;
				}
			}
			if (max == 0)
				cout << "\n--------------------------\n";
			else {
				cout << categories[cat] << " - " << max << " uah\n";
				fout << categories[cat] << " - " << max << " uah\n";
			}
			if (cat == 0 && buf1.empty() == false) {
				buf1.erase(buf1.begin() + index, buf1.begin() + index + 3);
			}
			else if (cat == 1 && buf2.empty() == false) {
				buf2.erase(buf2.begin() + index, buf2.begin() + index + 3);
			}
			else if (cat == 2 && buf3.empty() == false) {
				buf3.erase(buf3.begin() + index, buf3.begin() + index + 3);
			}
			else if (cat == 3 && buf4.empty() == false) {
				buf4.erase(buf4.begin() + index, buf4.begin() + index + 3);
			}
			else if (cat == 4 && buf5.empty() == false) {
				buf5.erase(buf5.begin() + index, buf5.begin() + index + 3);
			}
			else if (cat == 5 && buf6.empty() == false) {
				buf6.erase(buf6.begin() + index, buf6.begin() + index + 3);
			}



		}
		fout.close();
		this->Clear();
	}
	/*Функция получения топ-3 расхода за неделю начиная
	с определенного дня в месяце*/
	void GetTopWeek(int mon,int day) {
		this->Read(); 
		int max;
		int cat;
		int index; 
		ofstream fout("drating.txt", ios::app);
		cout << "\nТОП-3 затрат за неделю\n";
		fout << "\nТОП-3 затрат за неделю\n";
		for (size_t i = 0; i < 3; i++)
		{
			max = 0;
			if (buf1.empty() == false)
				for (size_t i = 0; i < buf1.size(); i += 3)
				{
					if (buf1[i + 2] > max && buf1[i] == mon && day >= buf1[i + 1] && day <= buf1[i + 1] + 7) {
						max = buf1[i + 2];
						cat = 0;
						index = i;
					}
				}
			if (buf2.empty() == false)
				for (size_t i = 0; i < buf2.size(); i += 3)
				{
					if (buf2[i + 2] > max && buf2[i] == mon && day >= buf2[i + 1] && day <= buf2[i + 1] + 7) {
						max = buf2[i + 2];
						cat = 1;
						index = i;
					}
				}
			if (buf3.empty() == false)
				for (size_t i = 0; i < buf3.size(); i += 3)
				{
					if (buf3[i + 2] > max && buf3[i] == mon && day >= buf3[i + 1] && day <= buf3[i + 1] + 7) {
						max = buf3[i + 2];
						cat = 2;
						index = i;
					}
				}
			if (buf4.empty() == false)
				for (size_t i = 0; i < buf4.size(); i += 3)
				{
					if (buf4[i + 2] > max && buf4[i] == mon && day >= buf4[i + 1] && day <= buf4[i + 1] + 7) {
						max = buf4[i + 2];
						cat = 3;
						index = i;
					}
				}
			if (buf5.empty() == false)
				for (size_t i = 0; i < buf5.size(); i += 3)
				{
					if (buf5[i + 2] > max && buf5[i] == mon && day >= buf5[i + 1] && day <= buf5[i + 1] + 7) {
						max = buf5[i + 2];
						cat = 4;
						index = i;
					}
				}
			if (buf6.empty() == false)
				for (size_t i = 0; i < buf6.size(); i += 3)
				{
					if (buf6[i + 2] > max && buf6[i] == mon && day >= buf6[i + 1] && day <= buf6[i + 1] + 7) {
						max = buf6[i + 2];
						cat = 5;
						index = i;
					}
				}
			if (max == 0)
				cout << "\n--------------------------\n";
			else {
				cout << categories[cat] << " - " << max << " uah\n";
				fout << categories[cat] << " - " << max << " uah\n";
			}

			if (cat == 0 && buf1.empty() == false) {
				buf1.erase(buf1.begin() + index, buf1.begin() + index + 3);
			}
			else if (cat == 1 && buf2.empty() == false) {
				buf2.erase(buf2.begin() + index, buf2.begin() + index + 3);
			}
			else if (cat == 2 && buf3.empty() == false) {
				buf3.erase(buf3.begin() + index, buf3.begin() + index + 3);
			}
			else if (cat == 3 && buf4.empty() == false) {
				buf4.erase(buf4.begin() + index, buf4.begin() + index + 3);
			}
			else if (cat == 4 && buf5.empty() == false) {
				buf5.erase(buf5.begin() + index, buf5.begin() + index + 3);
			}
			else if (cat == 5 && buf6.empty() == false) {
				buf6.erase(buf6.begin() + index, buf6.begin() + index + 3);
			}



		}
		fout.close();
		this->Clear();
	}
	/*Функция расчета топ-3 категорий по расходам за месяц*/
	void GetTopCatMonth(int mon) {
		this->Read();
		if (buf1.empty() == false)
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon) {
				buf[0] += buf1[i + 2];
			}
		}
		if (buf2.empty() == false)
		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon) {
				buf[1] += buf2[i + 2];
			}
		}
		if (buf3.empty() == false)
		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon) {
				buf[2] += buf3[i + 2];
			}
		}
		if (buf4.empty() == false)
		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon) {
				buf[3] += buf4[i + 2];
			}
		}
		if (buf5.empty() == false)
		for (size_t i = 0; i < buf5.size(); i += 3)
		{
			if (buf5[i] == mon) {
				buf[4] += buf5[i + 2];
			}
		}
		if (buf6.empty() == false)
		for (size_t i = 0; i < buf6.size(); i += 3)
		{
			if (buf6[i] == mon) {
				buf[5] += buf6[i + 2];
			}
		}
		int cat = 0;
		int max = 0;
		cout << "\nТОП-3 категорий за месяц\n";
		ofstream fout("drating.txt", ios::app);
		fout << "\nТОП-3 категорий за месяц\n";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t i = 0; i < buf.size(); i++)
			{
				if (buf[i] > max) {
					max = buf[i];
					cat = i;
				}
			}
			if (max == 0)
				cout << "\n--------------------------\n";
			else {
				cout << categories[cat] << " - " << max << " uah\n";
				fout << categories[cat] << " - " << max << " uah\n";
			}
			buf[cat] = 0;
			max = 0;
		}
		fout.close();
		this->Clear();
	}
	/*Функция расчета топ-3 категорий по расходам за неделю
	определенного месяца начиная с определенного дня*/
	void GetTopCatWeek(int mon,int day) {
		this->Read();
		if (buf1.empty() == false)
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon && day >= buf1[i + 1] && day <= buf1[i + 1] + 7) {
				buf[0] += buf1[i + 2];
			}
		}
		if (buf2.empty() == false)
		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon && day >= buf2[i + 1] && day <= buf2[i + 1] + 7) {
				buf[1] += buf2[i + 2];
			}
		}
		if (buf3.empty() == false)
		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon && day >= buf3[i + 1] && day <= buf3[i + 1] + 7) {
				buf[2] += buf3[i + 2];
			}
		}
		if (buf4.empty() == false)
		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon && day >= buf4[i + 1] && day <= buf4[i + 1] + 7) {
				buf[3] += buf4[i + 2];
			}
		}
		if (buf5.empty() == false)
		for (size_t i = 0; i < buf5.size(); i += 3)
		{
			if (buf5[i] == mon && day >= buf5[i + 1] && day <= buf5[i + 1] + 7) {
				buf[4] += buf5[i + 2];
			}
		}
		if (buf6.empty() == false)
		for (size_t i = 0; i < buf6.size(); i += 3)
		{
			if (buf6[i] == mon && day >= buf6[i + 1] && day <= buf6 [i + 1] + 7) {
				buf[5] += buf6[i + 2];
			}
		}
		int cat = 0;
		int max = 0;

		cout << "\nТОП-3 категорий за неделю\n";
		ofstream fout("drating.txt", ios::app);
		fout << "\nТОП-3 категорий за неделю\n";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t i = 0; i < buf.size(); i++)
			{
				if (buf[i] > max) {
					max = buf[i];
					cat = i;
				}
			}
			if (max == 0)
				cout << "\n--------------------------\n";
			else {
				cout << categories[cat] << " - " << max << " uah\n";
				fout << categories[cat] << " - " << max << " uah\n";
			}
			buf[cat] = 0;
			max = 0;
			cat = 0;
		}
		fout.close();
		this->Clear();
	}
	/*Функция подсчета всех расходов за определенный день
	определенного месяца*/
	void GetCostsDay(int mon, int day) {
		this->Read();
		if (buf1.empty() == false)
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon && day >= buf1[i + 1] ) {
				buf[0] += buf1[i + 2];
			}
		}
		if (buf2.empty() == false)
		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon && day >= buf2[i + 1] ) {
				buf[1] += buf2[i + 2];
			}
		}
		if (buf3.empty() == false)
		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon && day >= buf3[i + 1] ) {
				buf[2] += buf3[i + 2];
			}
		}
		if (buf4.empty() == false)
		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon && day >= buf4[i + 1]) {
				buf[3] += buf4[i + 2];
			}
		}
		if (buf5.empty() == false)
		for (size_t i = 0; i < buf5.size(); i += 3)
		{
			if (buf5[i] == mon && day >= buf5[i + 1] ) {
				buf[4] += buf5[i + 2];
			}
		}
		if (buf6.empty() == false)
		for (size_t i = 0; i < buf6.size(); i += 3)
		{
			if (buf6[i] == mon && day >= buf6[i + 1] ) {
				buf[5] += buf6[i + 2];
			}
		}

		cout << "\nЗатраты за день\n";
		ofstream fout("drating.txt", ios::app);
		fout << "\nЗатраты за день\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " uah\n";
			fout << categories[i] << " - " << buf[i] << " uah\n";
		}
		fout.close();
		this->Clear();
	}
	/*Функция подсчета всех расходов за неделю
	определенного месяца начиная с определенного дня*/
	void GetCostsWeek(int mon, int day) {
		this->Read();
		if (buf1.empty() == false)
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon && day >= buf1[i + 1] && day <= buf1[i + 1] + 7) {
				buf[0] += buf1[i + 2];
			}
		}
		if (buf2.empty() == false)
		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon && day >= buf2[i + 1] && day <= buf2[i + 1] + 7) {
				buf[1] += buf2[i + 2];
			}
		}
		if (buf3.empty() == false)
		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon && day >= buf3[i + 1] && day <= buf3[i + 1] + 7) {
				buf[2] += buf3[i + 2];
			}
		}
		if (buf4.empty() == false)
		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon && day >= buf4[i + 1] && day <= buf4[i + 1] + 7) {
				buf[3] += buf4[i + 2];
			}
		}
		if (buf5.empty() == false)
		for (size_t i = 0; i < buf5.size(); i += 3)
		{
			if (buf5[i] == mon && day >= buf5[i + 1] && day <= buf5[i + 1] + 7) {
				buf[4] += buf5[i + 2];
			}
		}
		if (buf6.empty() == false)
		for (size_t i = 0; i < buf6.size(); i += 3)
		{
			if (buf6[i] == mon && day >= buf6[i + 1] && day <= buf6[i + 1] + 7) {
				buf[5] += buf6[i + 2];
			}
		}
		ofstream fout("drating.txt", ios::app);
		cout << "\nЗатраты за неделю\n";
		fout << "\nЗатраты за неделю\n";

		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " uah\n";
			fout << categories[i] << " - " << buf[i] << " uah\n";
		}
		fout.close();
		this->Clear();
	}
	/*Функция подсчета всех расходов за определенный месяц*/
	void GetCostsMonth(int mon) {
		this->Read();
		if (buf1.empty() == false)
		for (size_t i = 0; i < buf1.size(); i += 3)
		{
			if (buf1[i] == mon) {
				buf[0] += buf1[i + 2];
			}
		}
		if (buf2.empty() == false)
		for (size_t i = 0; i < buf2.size(); i += 3)
		{
			if (buf2[i] == mon) {
				buf[1] += buf2[i + 2];
			}
		}
		if (buf3.empty() == false)
		for (size_t i = 0; i < buf3.size(); i += 3)
		{
			if (buf3[i] == mon) {
				buf[2] += buf3[i + 2];
			}
		}
		if (buf4.empty() == false)
		for (size_t i = 0; i < buf4.size(); i += 3)
		{
			if (buf4[i] == mon) {
				buf[3] += buf4[i + 2];
			}
		}
		if (buf5.empty() == false)
		for (size_t i = 0; i < buf5.size(); i += 3)
		{
			if (buf5[i] == mon) {
				buf[4] += buf5[i + 2];
			}
		}
		if (buf6.empty() == false)
		for (size_t i = 0; i < buf6.size(); i += 3)
		{
			if (buf6[i] == mon) {
				buf[5] += buf6[i + 2];
			}
		}
		cout << "\nЗатраты за месяц\n";
		ofstream fout("drating.txt", ios::app);
		fout << "\nЗатраты за месяц\n";
		for (size_t i = 0; i < buf.size(); i++)
		{
			cout << categories[i] << " - " << buf[i] << " uah\n";
			fout << categories[i] << " - " << buf[i] << " uah\n";
		}
		fout.close();
		this->Clear();
	}
	/*Деструктор сохраняющий баланс в файл*/
	~Debit() {
		ofstream fout("dbalance.txt");
		fout << to_string(balance);
		fout.close();
		
	}

private:

	int balance;
	int pin = 1111;
	/*Вектор категорий*/
	vector<string> categories = { "Еда","Красота и здоровье","Развлечения","Техника","Транспорт","Кафе" };
	/*Вектор названий файлов с расходами по категориям*/
	vector <string> files = { "dfood.txt","dhealth.txt","dfun.txt","dtech.txt","dtrans.txt","dcafe.txt" };
	/*Векторы хранящие информацию во время выполнения программы */
	vector<int> buf = { 0,0,0,0,0,0 };
	vector<int> buf1;
	vector<int> buf2;
	vector<int> buf3;
	vector<int> buf4;
	vector<int> buf5;
	vector<int> buf6;
};
