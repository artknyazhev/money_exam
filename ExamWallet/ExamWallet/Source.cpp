#include "credit.h"

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
			cout << "\n1->“екущий баланс\n";
			cout << "2->ƒобавить расход по карте\n";
			cout << "3->“оп-3 расходов за мес€ц\n";
			cout << "4->“оп-3 расходов за неделю\n";
			cout << "5->“оп-3 категорий за мес€ц\n";
			cout << "6->“оп-3 категорий за неделю\n";
			cout << "7->¬се расходы за день\n";
			cout << "8->¬се расходы за неделю\n";
			cout << "9->¬се расходы за мес€ц\n";
			cout << "10->ѕоложить деньги на счет\n";
			cout << "0->¬ меню выбора карт\n";
			cout << ">>>";
			cin >> choose;
			system("cls");
			switch (choose) {
			case 1:
				cout << "\nЅаланс: " << ptr[ind]->GetBal() << "uah\n";
				break;
			case 2:
				ptr[ind]->AddCost();
				break;
			case 3:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				ptr[ind]->GetTopMonth(mon);
				break;
			case 4:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				cout << "¬ведите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetTopWeek(mon,day);
				break;
			case 5:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				ptr[ind]->GetTopCatMonth(mon);
				break;
			case 6:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				cout << "¬ведите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetTopCatWeek(mon, day);
				break;
			case 7:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				cout << "¬ведите день: ";
				cin >> day;
				ptr[ind]->GetCostsDay(mon,day);
				break;
			case 8:
				cout << "¬ведите мес€ц: ";
				cin >> mon;
				cout << "¬ведите день(начало недели): ";
				cin >> day;
				ptr[ind]->GetCostsWeek(mon, day);
				break;
			case 9:
				cout << "¬ведите мес€ц: ";
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