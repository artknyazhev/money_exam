#include "credit.h"
/*������� ���� � ���������� ���� � ��������� � ������� �������*/
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
			cout << "\n1->������� ������\n";
			cout << "2->�������� ������ �� �����\n";
			cout << "3->���-3 �������� �� �����\n";
			cout << "4->���-3 �������� �� ������\n";
			cout << "5->���-3 ��������� �� �����\n";
			cout << "6->���-3 ��������� �� ������\n";
			cout << "7->��� ������� �� ����\n";
			cout << "8->��� ������� �� ������\n";
			cout << "9->��� ������� �� �����\n";
			cout << "10->�������� ������ �� ����\n";
			cout << "0->� ���� ������ ����\n";
			cout << ">>>";
			cin >> choose;
			system("cls");
			switch (choose) {
			case 1:
				cout << "\n������: " << ptr[ind]->GetBal() << "uah\n";
				break;
			case 2:
				ptr[ind]->AddCost();
				break;
			case 3:
				cout << "������� �����: ";
				cin >> mon;
				ptr[ind]->GetTopMonth(mon);
				break;
			case 4:
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����(������ ������): ";
				cin >> day;
				ptr[ind]->GetTopWeek(mon,day);
				break;
			case 5:
				cout << "������� �����: ";
				cin >> mon;
				ptr[ind]->GetTopCatMonth(mon);
				break;
			case 6:
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����(������ ������): ";
				cin >> day;
				ptr[ind]->GetTopCatWeek(mon, day);
				break;
			case 7:
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����: ";
				cin >> day;
				ptr[ind]->GetCostsDay(mon,day);
				break;
			case 8:
				cout << "������� �����: ";
				cin >> mon;
				cout << "������� ����(������ ������): ";
				cin >> day;
				ptr[ind]->GetCostsWeek(mon, day);
				break;
			case 9:
				cout << "������� �����: ";
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