#include<iostream>
#include <string>
#include <clocale>

using namespace std;

//////////////////////////////////////////////////////////////////////
///////////////                 COOLER                 ///////////////
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

	void Print();
	void Refill();
	void Use();
	void operator =(const cooler&);

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

void cooler::operator =(const cooler& c)
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

void cooler::Print()
{
	cout << "����������: " << filling << endl;
	cout << "��������: " << name << endl;
}

void cooler::Refill()
{
	filling++;
}

void cooler::Use()
{
	if (filling != 0)
	{
		filling--;
	}
}

//////////////////////////////////////////////////////////////////////
///////////////                  FAN                   ///////////////
//////////////////////////////////////////////////////////////////////

class fan : public cooler
{
protected:
	double rounds;
public:

	fan();
	fan(const fan& f);
	fan(int s, char* c, double r);
	~fan();

	void Use();
	void SpeedUp(int s);
	void Print();
	void operator =(const fan& f);
};


void fan::Use()
{
	cooler::Use();
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

void fan:: operator =(const fan& f)
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

fan::~fan()
{
	filling = 0;
	delete[] name;
	rounds = 0;
}


void fan::Print()
{
	cout << "����������: " << filling << endl;
	cout << "��������: " << name << endl;
	cout << "�������� � ������: " << rounds << endl;
}

void fan::SpeedUp(int s)
{
	rounds += s;
}

//////////////////////////////////////////////////////////////////////
///////////////                HEATER                  ///////////////
//////////////////////////////////////////////////////////////////////

class heater
{
protected:
	int temperature;
	bool on;
public:

	heater();
	heater(int n);
	heater(bool b);
	heater(int n, bool b);
	heater(const heater& h);

	void Switch();
	void Print();
	void operator =(const heater& h);

};

heater::heater()
{
	temperature = 40;
	on = true;
}
heater::heater(int n)
{
	temperature = n;
	on = true;
}
heater::heater(bool b)
{
	temperature = 40;
	on = b;
}
heater::heater(int n, bool b)
{
	temperature = n;
	on = b;
}
heater::heater(const heater& h)
{
	temperature = h.temperature;
	on = h.on;
}

void heater::Switch()
{
	on = !on;
}

void heater::Print()
{
	cout << "����������� �����������: " << temperature << endl;
	if (on) cout << "����������� �������" << endl;
	else cout << "����������� ��������" << endl;
}

void heater:: operator=(const heater& h)
{
	temperature = h.temperature;
	on = h.on;
}

//////////////////////////////////////////////////////////////////////
///////////////             ClimateControl             ///////////////
//////////////////////////////////////////////////////////////////////

class climateControl : public cooler, public heater
{
private:
	int freezerTemp;
public:
	climateControl();
	climateControl(int f, int t, int ft, char* c, bool b);
	climateControl(const climateControl& cc);
	void operator=(const climateControl& cc);
	void Print();
};

climateControl::climateControl()
{
	filling = 0;
	strcpy(name, "climateControl");
	temperature = 40;
	freezerTemp = -40;
	on = true;
}

climateControl::climateControl(int f, int t, int ft, char* c, bool b)
{
	filling = f;
	strcpy(name, c);
	temperature = t;
	freezerTemp = ft;
	on = b;
}

climateControl::climateControl(const climateControl& cc)
{
	filling = cc.filling;
	name = new char[strlen(name) + 1];
	strcpy(name, cc.name);
	temperature = cc.temperature;
	freezerTemp = cc.freezerTemp;
	on = cc.on;
}

void climateControl:: operator=(const climateControl& cc)

{
	filling = cc.filling;
	name = new char[strlen(name) + 1];
	strcpy(name, cc.name);
	temperature = cc.temperature;
	freezerTemp = cc.freezerTemp;
	on = cc.on;
}

void climateControl::Print()
{
	cooler::Print();
	heater::Print();
	cout << "����������� ����������: " << freezerTemp << endl;
}

//////////////////////////////////////////////////////////////////////
///////////////                  ����                  ///////////////
//////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "rus");
	climateControl cc(10, 90, -60, (char*)"cc2", true);
	cc.Print();
	cc.Refill(); //����� ������� �������� ������
	cout << endl;
	cc.Print();
	system("pause");
	return 0;
}
