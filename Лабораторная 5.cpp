#include<iostream>
#include <string>
#include <clocale>

using namespace std;



//////////////////////////////////////////////////////////////////////
///////////////              микрокласс                ///////////////
//////////////////////////////////////////////////////////////////////


class cooler
{
protected:
	int filling;
	char* name;
public:
	cooler();
	cooler(int s, char* c);
	cooler(const cooler& c);
	~cooler();

	void virtual print();
	void refill();
	void use();
	void operator =(const cooler);

};

cooler::cooler()
{
	filling = 0;
	name = new char[7];
	strcpy(name, "cooler");
}

cooler::cooler(int s, char* c)
{
	filling = s;
	name = new char[strlen(c) + 1];
	strcpy(name, c);
}

cooler::cooler(const cooler& c)
{
	filling = c.filling;
	name = new char[strlen(c.name) + 1];
	strcpy(name, c.name);

}



cooler ::~cooler()
{
	filling = 0;
	name = (char*)"";
	delete[] name;
}


void cooler::print()
{
	cout << "наполнение: " << filling << endl;
	cout << "название: " << name << endl << endl;
}

void cooler::refill()
{
	filling++;
}

void cooler::use()
{
	if (filling != 0)
	{
		filling--;
	}
}


class fan : public cooler
{
private:
	double rounds;
public:
	void virtual print();
	fan();
	fan(const fan& f);
	fan(int s, char* c, double r);

	void use();
	void speedUp(int s);
	void operator =(const fan f);
};


void fan::use()
{
	cooler::use();
}

fan::fan(int s, char* c, double r) : cooler(s, c)
{
	filling = s;
	name = new char[strlen(c) + 1];
	strcpy(name, c);
	rounds = r;
}

fan::fan(const fan& f)
{
	name = new char[strlen(f.name) + 1];
	strcpy(name, f.name);
	filling = f.filling;
	rounds = f.rounds;
}

void fan:: operator =(const fan f)
{
	name = new char[strlen(f.name) + 1];
	strcpy(name, f.name);
	filling = f.filling;
	rounds = f.rounds;

}
fan::fan()
{
	filling = 0;
	name = new char[4];
	strcpy(name, "fan");
	rounds = 1;
}

void fan::print()
{
	cout << "наполнение: " << filling << endl;
	cout << "название: " << name << endl;
	cout << "оборотов в минуту: " << rounds << endl << endl;
}

void fan::speedUp(int s)
{
	rounds += s;
}



//////////////////////////////////////////////////////////////////////
///////////////                  МЭЙН                  ///////////////
//////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "rus");
	cooler c1(), c2(10, (char*)"c2");
	fan f1(), f2(30, (char*)"fanTwo", 22.5);
	cooler* c3();
	c2.print();
	f2.print();
	f2.refill();
	f2.speedUp(5);
	f2.print();
	system("pause");
	return 0;
}
