#include "credit.h"
/*Главный файл с реализацей меню и обращений к методам классов*/
int main() {
	setlocale(LC_ALL, "rus");
	int choose=1,ind;
	Debit d;
	Credit c;
	Bank* ptr[2] = { &d,&c };
	do {
		cout << "1->Debit Card\n";
		cout << "2->Credit Card\n3->Exit\n>>>";
		cin >> ind;
		ind--;
		system("cls");
		do {
			int mon, day;
			cout << "\n1->Текущий баланс\n";
			cout << "2->Добавить расход по карте\n";
			cout << "3->Топ-3 расходов за месяц\n";
			cout << "4->Топ-3 расходов за неделю\n";
			cout << "5->Топ-3 категорий за месяц\n";
			cout << "6->Топ-3 категорий за неделю\n";
			cout << "7->Все расходы за день\n";
			cout << "8->Все расходы за неделю\n";
			cout << "9->Все расходы за месяц\n";
			cout << "10->Положить деньги на счет\n";
			cout << "0->В меню выбора карт\n";
			cout << ">>>";
			cin >> choose;
			system("cls");
			switch (choose) {
			case 1:
				cout << "\nБаланс: " << ptr[ind]->GetBal() << "uah\n";
				break;
			case 2:
				ptr[ind]->AddCost();
				break;
			case 3:
				cout << "Введите месяц: ";
				cin >> mon;
				ptr[ind]->GetTopMonth(mon);
				break;
			case 4:
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetTopWeek(mon,day);
				break;
			case 5:
				cout << "Введите месяц: ";
				cin >> mon;
				ptr[ind]->GetTopCatMonth(mon);
				break;
			case 6:
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetTopCatWeek(mon, day);
				break;
			case 7:
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день: ";
				cin >> day;
				ptr[ind]->GetCostsDay(mon,day);
				break;
			case 8:
				cout << "Введите месяц: ";
				cin >> mon;
				cout << "Введите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetCostsWeek(mon, day);
				break;
			case 9:
				cout << "Введите месяц: ";
				cin >> mon;
				ptr[ind]->GetCostsMonth(mon);
				break;
			case 10:
				ptr[ind]->PutMoney();
				break;
			default:
				system("cls");
				break;
			}

		} while (choose != 0);

	} while (ind != 2);


}