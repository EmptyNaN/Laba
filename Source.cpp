#include <iostream> 
#include <string>
#include <clocale>

using namespace std;




//////////////////////////////////////////////////////////////////////////////
///////////////                  ПЕРВЫЙ КЛАСС                  ///////////////
//////////////////////////////////////////////////////////////////////////////



template <class T>
class Fridge1
{
private:
	int number;
	T volume;
	char* color;
	bool freezer;

public:
	Fridge1();
	Fridge1(int a, T b, char* c, bool d);
	Fridge1(const Fridge1<T>& a);
	~Fridge1();
	void Print();
	Fridge1 <T> sum(const Fridge1<T>& a);
	bool Cmp(const Fridge1<T>& a);
	void Copy(const Fridge1<T>& a);

	Fridge1<T>operator =(const  Fridge1<T>& a);
	Fridge1<T>operator +(const  Fridge1<T>& a);
	bool operator >(const  Fridge1<T>& a);
	bool operator <(const  Fridge1<T>& a);
	bool operator ==(const  Fridge1<T>& a);
	bool operator !=(const  Fridge1<T>& a);
	bool operator >=(const  Fridge1<T>& a);
	bool operator <=(const  Fridge1<T>& a);

};

template <class T>
void Fridge1<T> ::Print()
{
	cout << "Серийный номер: " << number << endl;
	cout << "Объём: " << volume << endl;
	cout << "Морозильная камера ";
	if (freezer)
	{
		cout << "Имеется";
	}
	else
	{
		cout << "отсутствует";
	}
	cout << endl;
	cout << "цвет: " << color << endl << endl;
}

template <class T>
Fridge1<T> ::Fridge1()
{
	number = 0;
	volume = (T)0;
	freezer = false;
	color = new char[1];
	strcpy(color, "white");
}

template <class T>
Fridge1<T> ::Fridge1(int a, T b, char* c, bool d)
{
	number = a;
	volume = (T)b;
	freezer = d;
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}

template <class T>
Fridge1<T> ::Fridge1(const Fridge1<T>& a)
{
	if (&a != this)
	{
		number = a.number;
		volume = a.volume;
		color = new char[strlen(a.color) + 1];
		strcpy(color, a.color);
		freezer = a.freezer;
	}
}

template <class T>
Fridge1<T> :: ~Fridge1()
{
	delete[] color;
}


template <class T>
bool Fridge1<T> ::Cmp(const Fridge1<T>& a)
{
	return volume == a.volume && number == a.number && freezer == a.freezer && color == a.color;
}


template <class T>
void Fridge1<T> ::Copy(const Fridge1<T>& a)
{
	number = a.number;
	volume = a.volume;
	color = new char[strlen(a.color) + 1];
	strcpy(color, a.color);
	freezer = a.freezer;
}

template <class T>
Fridge1<T> Fridge1<T> ::sum(const Fridge1<T>& a)
{
	Fridge1<T> f;
	char* tmp = new char[strlen(color) + 1];
	strcpy(tmp, color);
	f.number = number + a.number;
	f.volume = volume + a.volume;
	f.freezer = freezer + a.freezer;
	strcat(tmp, "-");
	strcat(tmp, a.color);
	f.color = new char[strlen(tmp) + 1];
	strcpy(f.color, tmp);
	return f;
}

template <class T>
Fridge1<T> Fridge1<T> :: operator=(const Fridge1<T>& a)
{
	if (this == &a)  return *this;
	else
	{
		this->Copy(a);
		return *this;
	}
}

template <class T>
Fridge1<T> Fridge1<T> :: operator+(const Fridge1<T>& a)
{
	Fridge1 f = this->sum(a);
	return f;
}


template <class T>
bool Fridge1<T> :: operator<(const Fridge1<T>& a)
{
	return volume < a.volume && number < a.number;
}

template <class T>
bool Fridge1<T> :: operator>(const Fridge1<T>& a)
{
	return volume > a.volume&& number > a.number;
}

template <class T>
bool Fridge1<T> :: operator==(const Fridge1<T>& a)
{
	return volume == a.volume && number == a.number && color == a.color && freezer == a.freezer;
}

template <class T>
bool Fridge1<T> :: operator!=(const Fridge1<T>& a)
{
	return volume != a.volume || number != a.number || color != a.color || freezer == a.freezer;
}

template <class T>
bool Fridge1<T> :: operator<=(const Fridge1<T>& a)
{
	return (volume < a.volume && number < a.number) || (volume != a.volume || number != a.number || color != a.color || freezer == a.freezer);
}

template <class T>
bool Fridge1<T> :: operator>=(const Fridge1<T>& a)
{
	return (volume > a.volume&& number > a.number) || (volume != a.volume || number != a.number || color != a.color || freezer == a.freezer);
}



//////////////////////////////////////////////////////////////////////////////
///////////////                  ВТОРОЙ КЛАСС                  ///////////////
//////////////////////////////////////////////////////////////////////////////

template <class T1, class  T2>
class Fridge2
{
private:
	T1 number;
	T2 volume;
	char* color;
	bool freezer;

public:
	Fridge2();
	Fridge2(T1 a, T2 b, char* c, bool d);
	Fridge2(const Fridge2<T1, T2>& a);
	~Fridge2();
	void Print();
	Fridge2 <T1, T2> sum(const Fridge2<T1, T2>& a);
	bool Cmp(const Fridge2<T1, T2>& a);
	void Copy(const Fridge2<T1, T2>& a);

	Fridge2<T1, T2>operator =(const  Fridge2<T1, T2>& a);
	Fridge2<T1, T2>operator +(const  Fridge2<T1, T2>& a);
	bool operator >(const  Fridge2<T1, T2>& a);
	bool operator <(const  Fridge2<T1, T2>& a);
	bool operator ==(const  Fridge2<T1, T2>& a);
	bool operator !=(const  Fridge2<T1, T2>& a);
	bool operator >=(const  Fridge2<T1, T2>& a);
	bool operator <=(const  Fridge2<T1, T2>& a);

};

template <class T1, class T2>
void Fridge2<T1, T2> ::Print()
{
	cout << "Серийный номер: " << number << endl;
	cout << "Объём: " << volume << endl;
	cout << "Морозильная камера ";
	if (freezer)
	{
		cout << "Имеется";
	}
	else
	{
		cout << "отсутствует";
	}
	cout << endl;
	cout << "цвет: " << color;
}

template <class T1, class T2>
Fridge2<T1, T2> ::Fridge2()
{
	number = (T1)0;
	volume = (T2)0;
	freezer = false;
	color = new char[1];
	strcpy(color, "");
}

template <class T1, class T2>
Fridge2<T1, T2> ::Fridge2(T1 a, T2 b, char* c, bool d)
{
	number = (T1)a;
	volume = (T2)b;
	freezer = d;
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}

template <class T1, class T2>
Fridge2<T1, T2> ::Fridge2(const Fridge2<T1, T2>& a)
{
	if (&a != this)
	{
		number = a.number;
		volume = a.volume;
		color = new char[strlen(a.color) + 1];
		strcpy(color, a.color);
		freezer = a.freezer;
	}
}

template <class T1, class T2>
Fridge2<T1, T2> ::~Fridge2()
{
	delete[] color;
}


template <class T1, class T2>
bool Fridge2<T1, T2> ::Cmp(const Fridge2<T1, T2>& a)
{
	return volume == a.volume && number == a.number && freezer == a.freezer && color == a.color;
}


template <class T1, class T2>
void Fridge2<T1, T2> ::Copy(const Fridge2<T1, T2>& a)
{
	number = a.number;
	volume = a.volume;
	color = new char[strlen(a.color) + 1];
	strcpy(color, a.color);
	freezer = a.freezer;
}

template <class T1, class T2>
Fridge2<T1, T2> Fridge2<T1, T2> ::sum(const Fridge2<T1, T2>& a)
{
	Fridge2<T1, T2> f;
	char* tmp = new char[strlen(color) + 1];
	strcpy(tmp, color);
	f.number = number + a.number;
	f.volume = volume + a.volume;
	f.freezer = freezer + a.freezer;
	strcat(tmp, "-");
	strcat(tmp, a.color);
	f.color = new char[strlen(tmp) + 1];
	strcpy(f.color, tmp);
	return f;
}

template <class T1, class T2>
Fridge2<T1, T2> Fridge2<T1, T2> :: operator=(const Fridge2<T1, T2>& a)
{
	if (this == &a)  return *this;
	else
	{
		this->Copy(a);
		return *this;
	}
}

template <class T1, class T2>
Fridge2<T1, T2> Fridge2<T1, T2> :: operator+(const Fridge2<T1, T2>& a)
{
	Fridge1 f = this->sum(a);
	return f;
}


template <class T1, class T2>
bool Fridge2<T1, T2> :: operator<(const Fridge2<T1, T2>& a)
{
	return volume < a.volume && number < a.number;
}

template <class T1, class T2>
bool Fridge2<T1, T2> :: operator>(const Fridge2<T1, T2>& a)
{
	return volume > a.volume&& number > a.number;
}

template <class T1, class T2>
bool Fridge2<T1, T2> :: operator==(const Fridge2<T1, T2>& a)
{
	return volume == a.volume && number == a.number && color == a.color && freezer == a.freezer;
}

template <class T1, class T2>
bool Fridge2<T1, T2> :: operator!=(const Fridge2<T1, T2>& a)
{
	return volume != a.volume || number != a.number || color != a.color || freezer == a.freezer;
}

template <class T1, class T2>
bool Fridge2<T1, T2> :: operator<=(const Fridge2<T1, T2>& a)
{
	return (volume < a.volume && number < a.number) || (volume != a.volume || number != a.number || color != a.color || freezer == a.freezer);
}

template <class T1, class T2>
bool Fridge2<T1, T2> :: operator>=(const Fridge2<T1, T2>& a)
{
	return (volume > a.volume&& number > a.number) || (volume != a.volume || number != a.number || color != a.color || freezer == a.freezer);
}

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
	~cooler();

	void virtual print();
	void refill();
	void use();
};

cooler::cooler()
{
	filling = 0;
	name = new char[7];
	strcpy(name, "cooler");
}

cooler::cooler( int s, char* c)
{
	filling = s;
	name = new char[strlen(c) + 1];
	strcpy(name, c);
}

cooler ::~cooler()
{
	filling = 0;
	name = (char*)"";
	delete[] name;
}

void cooler :: print()
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


class fan : cooler
{
private:
	double rounds;
public:
	void virtual print();
	fan();
	void refill();
	void use();
	fan(int s, char* c, double r);
	void speedUp();
};

void fan::refill()
{
	cooler::refill();
}

void fan::use()
{
	cooler::use();
}

fan::fan(int s,char* c,double r) : cooler(s, c)
{
	filling = s;
	name = new char[strlen(c) + 1];
	strcpy(name, c);
	rounds = r;
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

void fan::speedUp()
{
	rounds += 10;
}

//////////////////////////////////////////////////////////////////////
///////////////                  МЭЙН                  ///////////////
//////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "rus");
	cooler c1(), c2(10, (char*)"c2");
	fan f1(), f2(30, (char*)"fanTwo", 22.5);
	c2.print();
	f2.print();
	f2.refill();
	f2.speedUp();
	f2.print();
	system("pause");
	return 0;
}
