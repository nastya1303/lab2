#include <iostream>
#include <string>
#include <Chrono>
using namespace std;

struct List
{
	int data;
	List* head;
	List* tail;
};

void show_data(List* now)
{
	List* work = now;
	while (work->tail != 0)
	{
		cout << work->data << ' ';
		work = work->tail;
	}
	cout << work->data << ' ';
}

void del(List*& main, int c, int d)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	if (c)
	{
		int a;
		a = d;
		List* now = main;
		if (a == 1)
		{
			main = now->tail->tail->head;
			now=nullptr;
			main->head = 0;
		}
		else
		{
			for (int i = 1; i < a; i++)
			{
				now = now->tail;
			}
			if (now->tail == 0)
			{
				now->head->tail = 0;
				now = nullptr;
			}
			else
			{
				List* next = now->tail, * past = now->head;
				next->head = now->head;
				past->tail = now->tail;
				now = nullptr;
			}
		}
	}
	else
	{
		int a;
		a = d;
		List* now = main;
		while (now->data != a)
		{
			now = now->tail;
		}
		if (now->head == 0)
		{
			main = now->tail->tail->head;
			now = nullptr;
			main->head = 0;
		}
		else
		{
			if (now->tail == 0)
			{
				now->head->tail = 0;
				now = nullptr;
			}
			else
			{
				List* next = now->tail, * past = now->head;
				next->head = now->head;
				past->tail = now->tail;
				now = nullptr;
			}
		}
	}
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << "time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	show_data(main);
}

void insert(List*& main, int a, int r)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	List* now = main, * add=0;
	add = new List;
	add->data=r;
	if (a == 1)
	{
		add->head = 0;
		add->tail = main;
		main->head = add;
		main = add;
	}
	else
	{
		for (int i = 1; i < a-1; i++)
		{
			now = now->tail;
		}
		if (now->tail == 0)
		{
			now->tail = add;
			add->tail = 0;
			add->head = now->head->tail;
		}
		else
		{
			List* next = now->tail;
			add->tail = next;
			add->head = now;
			next->head = add;
			now->tail = add;
		}
	}
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	cout << '\n';
	show_data(main);
}

void swapp(List*& main, int a, int b)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	List* now = main,* nowa=0, * nowb=0;
	for (int i = 1; i < b; i++)
	{
		if (i == a)
			nowa = now;
		now = now->tail;
	}
	nowb = now;
	if (a == b)
	{
		nowa = nowb;
	}
	int c;
	c = nowa->data;
	nowa->data = nowb->data;
	nowb->data=c;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	show_data(main);
}

void add(List*& main, int a, int b)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	if (a)
	{
		List* now = main;
		for (int i = 1; i < b; i++)
		{
			now = now->tail;
		}
		cout << "Element from №" << b << " is " << now->data;
	}
	else
	{
		int c=0, d=0;
		List* now = main;
		while (now->tail != 0)
		{
			if (now->data == b)
			{
				cout << b << " value is in the element №" << c+1;
				d += 1;
				break;
			}
			else
			{
				c += 1;
				now = now->tail;
			}
		}
		if (d==0)
			cout << b << " value is not in the list ";
	}
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
}

int* mass_del(int*& mass, int c, int d, int len)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	int* arr = new int[len - 1];
	int p = 0;
	if (c)
	{
		cout << '\n';
		for (int i = 0; i < len; i++)
		{
			if (i != d -1)
			{
				arr[p] = mass[i];
				p += 1;
			}
		}
	}
	else
	{
		cout << '\n';
		for (int i = 0; i < len; i++)
		{
			if (mass[i] != d)
			{
				arr[p] = mass[i];
				p += 1;
			}
		}
	}
	delete [] mass;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	return arr;
}
	 
int* mass_insert(int*& mass, int c, int d, int len)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	int* arr = new int[len + 1];
	int p = 0;
	for (int i = 0; i < len; i++)
	{
		if (i == c-1)
		{
			arr[p] = d;
			p += 1;
		}
		arr[p] = mass[i];
		p += 1;
	}
	auto ClockEnd = chrono::high_resolution_clock::now();
	
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	return arr;
}

void mass_swapp(int*& mass, int c, int d)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	int a;
	a = mass[c-1];
	mass[c-1] = mass[d-1];
	mass[d-1] = a;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
}

void mass_show(int*& mass, int c, int d, int len)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	if (c)
	{
		//cout << "Element from №" << d << " is " << mass[d -1];
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (mass[i] == d)
			{
				//cout << d << " value is in the element №" << i+1;
				break;
			}
		}
	}
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
}

int* mass_create(List* now, int len)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	int* mass = new int[len];
	int i = 0;
	List* work = now;
	while (work->tail != 0)
	{
		mass[i] = work->data;
		i += 1;
		work = work->tail;
	}
	mass[i] = work->data;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	return mass;
}

void idz_list(List*& main)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	List* now = main;
	int p = 0;
	while (now->tail!= 0)
	{
		if (p % 2 == 1)
		{
			List* next = now->tail, * past = now->head;
			next->head = now->head;
			past->tail = now->tail;
		}
		p += 1;
		now = now->tail;
	}
	if (p % 2 == 1)
	{
		now->head->tail = 0;
	}
	show_data(main);
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << '\n';
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
}

int* idz_mass(int*& mass, int len)
{
	auto ClockStart = chrono::high_resolution_clock::now();
	int* arr = new int[len/2];
	int p = 0;
	for (int i = 0; i < len; i++)
	{
		if (i %2==0)
		{
			arr[p] = mass[i];
			cout << arr[p] << ' ';
			p += 1;
		}
	}
	delete[] mass;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << '\n';
	cout << " time mass ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	return arr;
}

void del_ful_list(List*& main)
{
	List* now = main;
	List* next = now->tail;
	while (next != 0)
	{
		now = nullptr;
		now = next;
		next = now->tail;
	}
	now = nullptr;
}

void change_list(List* now, int length)
{
	List* main = now;
	int* arr = mass_create(now, length);
	system("pause");
	system("cls");
	bool p = true;
	while (p)
	{
		show_data(main);
		cout << '\n' << "Choise action" << '\n';
		cout << "0) exit" << '\n';
		cout << "1) delete element" << '\n';
		cout << "2) insert element" << '\n';
		cout << "3) swapp" << '\n';
		cout << "4) print element" << '\n';
		cout << "5) idz №5"<< '\n';
		int a;
		cin >> a;
		switch (a)
		{
		case 1:
			int b;
			cout << "Enter 1 if yo want to delete by number or enter 0 by vale ";
			cin >> b;
			int d;
			if (b)
			{
				cout << "Enter number element of list which you want to delete start from (1) ";
				cin >> d;
			}
			else
			{
				cout << "Enter value which you want to delete ";
				cin >> d;
			}
			del(main, b, d);
			
			arr=mass_del(arr, b, d, length);
			length -= 1;
			break;
		case 2:
			int e, f;
			cout << "Enter position where you want add vale ";
			cin >> e;
			cout << "Enter value";
			cin >> f;
			insert(main, e, f);
			arr = mass_insert(arr, e, f, length);
			length += 1;
			break;
		case 3:
			int g, h;
			cout << "Enter numbers of 2 elements what you want to swapp" << '\n' << "1 element - ";
			cin >> g;
			cout << "2 element - ";
			cin >> h;
			swapp(main, g, h);
			mass_swapp(arr, g, h);
			break;
		case 4:
			cout << "Enter 1 if you want to find value to element or 0 if you want to find element to value ";
			int j, k;
			cin >> j;
			if (j)
			{
				cout << "Enter number of element ";
				cin >> k;
			}
			else
			{
				cout << "Enter value of element ";
				cin >> k;
			}
			add(main, j, k);
			mass_show(arr, j, k, length);
			break;
		case 5:
			idz_list(main);
			arr=idz_mass(arr, length);
			break;
		default:
			p = false;
			break;
		}
		cout << '\n';
		system("pause");
		system("cls");
	}
	del_ful_list(main);
}

void create_a()
{
	auto ClockStart = chrono::high_resolution_clock::now();
	cout << "Write length of the list ";
	int length;
	cin >> length;
	List* now=0, * next = 0;
	//srand(time(NULL));
	for (int i = 0; i <length; i++)
	{
		now = new List;
		now->data = rand() % 100;
		now->tail = next;
		if (next)
		{
			next->head = now;
		}
		next = now;
	}
	now->head = 0;
	List* sp;
	sp = now;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	show_data(sp);
	change_list(sp, length);
}

void create_b()
{
	auto ClockStart = chrono::high_resolution_clock::now();
	bool p = true;
	List* now = 0, * next = 0;
	List* sp=0;
	int length = 0;
	while (p)
	{
		cout << "Enter number or (end) if you want to stop ";
		string a;
		cin >> a;
		if (a == "end")
		{
			p = false;
		}
		else
		{
			now = new List;
			if (length == 0)
			{
				sp = now;
			}
			length += 1;
			now->data = stoi(a);
			now->head = next;
			if (next)
			{
				next->tail = now;
			}
			next = now;
		}
	}
	now->tail = 0;
	auto ClockEnd = chrono::high_resolution_clock::now();
	cout << " time list ";
	cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << "us\n";
	show_data(sp);
	change_list(sp, length);
}

void menu()
{
	int a;
	cout << "Choise type of creating list" << '\n';
	cout << "1 - you enter length of list " << '\n';
	cout << "2 - you entter all elements of list" << '\n';
	cin >> a;
	switch (a)
	{
	case 1:
		create_a();
		break;
	case 2:
		create_b();
		break;
	}
	
	int p;
	cout << "Do you want to recreate list? (1-yes, 2-no) ";
	cin >> p;
	if (p==1)
	{
		menu();
	}
}

int main()
{
	menu();
}
