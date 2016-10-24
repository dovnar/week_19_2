#include <iostream>
using namespace std;

void addDataItem(struct DataItem* cur);
void printDataItem(struct DataItem* dataItem);
void deleteDataUtem(struct DataItem* dataItem);
int averageTemperature(struct DataItem data);
void exitProgramm(struct DataItem* dataItem);
struct DataItem
{
	char* Date;
	int Temperature;
	struct DataItem* AddData;
};

void main()
{
	DataItem data;
	DataItem* dataItem = new DataItem[1];
	DataItem* cur = dataItem;
	int menu = 0;
	do
	{
		cout << "add data = 1;\tprint data = 2\exit = 0\tenter: ";
		cin >> menu; fflush(stdin);
		menu == 1 ? addDataItem(cur) : (menu == 2 ? printDataItem(dataItem) :
			(menu == 3 ? deleteDataUtem(dataItem) : (menu == 4 ? averageTemperature(data) :
				(menu == 5 ? exitProgramm(dataItem) : menu = 0))));
	} while (menu != 0);
	delete[] dataItem;
	delete[] cur;
}

void addDataItem(struct DataItem* cur)
{
	cout << "enter date: dd.mm.yyyy: ";
	cur->Date = new char[11];

	cin.getline(cur->Date, 11); fflush(stdin);
	cout << "enter Temperature: ";

	cin >> cur->Temperature; fflush(stdin);
	cur = (cur->AddData = new DataItem[1]);
	cur->AddData = nullptr;
}

void printDataItem(struct DataItem* dataItem)
{
	DataItem* cur = dataItem;
	cout << "date\t\t" << "Temperature:" << endl;
	for (cur; cur != nullptr && cur->AddData != nullptr; cur = cur->AddData)
	{
		cout << cur->Date << "\t" << cur->Temperature << endl;
	}
}

void deleteDataUtem(DataItem* dataItem)
{
	DataItem* cur = dataItem;
	char* skanDate = new char[11];
	cout << "enter date: ";
	cin.getline(skanDate, 11);
	for (cur; cur != nullptr && cur->AddData != nullptr; cur = cur->AddData)
	{
		if (cur->Date != skanDate)
		{
			cur = cur->AddData;
		}
	}
}

int averageTemperature(DataItem data)
{
	DataItem* cur = data.AddData;
	int temperature = 0;
	int i = 0;
	for (cur; cur != nullptr && cur->AddData != nullptr; cur = cur->AddData, i++)
	{
		temperature += data.Temperature;
	}
	return (temperature / i);
}

void exitProgramm(DataItem * dataItem)
{
	DataItem* cur = dataItem;
	int i = 0;
	for (cur; cur != nullptr && cur->AddData != nullptr; cur = cur->AddData)
	{
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		for (cur; cur != nullptr && cur->AddData != nullptr; cur = cur->AddData)
		{
			if (cur->AddData == nullptr)
			{
				delete[] cur->AddData;
				cur = nullptr;
			}
		}
	}
}



/*+-----------+      
| данные  |       
+-----------+       +-----------+      
|указатель| ---> | данные  |        
+-----------+       +-----------+       +-----------+ 
						  |указатель| ---> | данные  | 
						  +-----------+       +-----------+
													|       0      | 
												    +-----------+

Разработайте	программу	для	работы	с	температурными	измерениями.	Доступные	операции	для	пользователя:	
1. добавление	измерения	(дата	в	формате	ДД.ММ.ГГГГ,	температура	в	формате	XX.X)	
2. просмотр	таблицы	измерений	(2	столбца:	дата,	температура)	
3. удаление	измерения	по	выбранной	дате	(пользователь	вводит	дату	в	формате	ДД.ММ.ГГГГ)	
4. подсчет	средней	температуры	на	основании	данных	в	таблице	
5. выход	из	программы	Программу	реализовывать	с	использованием	вложенных	структур	
(структура	содержит	указатель	на	такой	же	тип	структуры,	как	и	она	сама)	в	виде односвязного	линейного	списка:*/