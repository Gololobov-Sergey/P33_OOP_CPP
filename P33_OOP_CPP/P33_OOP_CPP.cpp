
#include <iostream>
#include <math.h>
#include <Windows.h>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"Reservoir.h"
#include"Fraction.h"
//#include"String.h"
#include"Stack.h"
#include"Calc.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include"PrintServer.h"
#include"List.h"
#include"BTree.h"
#include"BasePolice.h"
#include"Relation.h"
#include"Inherit.h"
#include"BitString.h"
#include"Animal.h"
#include"Shape.h"
#include"WarOfWorld.h"
#include"Interface.h"
#include"MyException.h"
#include"SmartPointer.h"
#include"Namespace.h"
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<set>
#include <random>


using namespace std;

void printStudent(Student st)
{
	cout << Student::getCount() << endl;
	st.print();
}

Student fffff()
{
	Student s(55);

	//

	return s;
}

template<class T>
void printArr(Array<T> arr)
{
	arr.print();
}


void addOne(int& val)
{
	val++;
}

void print(int& val)
{
	cout << val << " ";
}

Shape* getShape(string type)
{
	if (type == "S")
		return new Square(0, 0, 0);
	if (type == "R")
		return new Rectangle_(0, 0, 0, 0);
	if (type == "C")
		return new Circle(0, 0, 0);
}


double super_func(ILogProvider& log)
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
	{
		log.SaveError("Division by zero!");
		throw "Error";
	}
	if (b == 100)
	{
		throw 999;
	}
	return (double)a / b;
}

void print(Printable& o)
{
	o.print();
}


void GetVoice(Animal a)
{
	a.voice();
}


void fract(Fraction&& f)
{
	f.print();
}

void fract(const Fraction& f)
{
	f.print();
}



void function()
{
	SmartPointer<Student> sm(new Student(99, "Vasya", 30));

	sm->print();

	//SmartPointer<Student> sm1(sm);

	//sm1->print();

	int a;
	cin >> a;
	if (a == 0)
		throw 1;


	//delete st;
}

//using namespace FOO;

namespace BOO = FOO::DOO;

bool num5(int a)
{
	return a > 3;
}

class Comparator
{
public:
	bool operator()(int a)
	{
		return a > 3;
	}
};

template<class Cont>
void PrintContainer(Cont container)
{
	for (auto elem : container)
	{
		cout << elem << " ";
	}
	cout << endl;
}

void PrintContainer(int* a)
{
	for (size_t i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{

	cout.setf(ios::boolalpha);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	///// 09.01.2025  ///////////////////////

	int a[] = { 1,2,3,5,6,7,89 };
	vector<int> v{ 1, -2, 3,-5,7,3,0 };
	list<int> l{ 1,3,1,7,1,1,0, 3, 7 };

	//remove(v.begin(), v.end(), -2);
	//remove(v.begin(), v.end(), -5);
	//remove_if(v.begin(), v.end(), [](int a) { return a < 0; });

	//unique(l.begin(), l.end());
	sort(v.begin(), v.end());
		

	PrintContainer(v);

	std::random_device rd;
	std::mt19937 g(rd());

	shuffle(v.begin(), v.end(), g);
	PrintContainer(v);

	//set<int> s(l.begin(), l.end());

	//PrintContainer(s);


	/*int x = 0;
	vector<int> vv(10);
	generate(vv.begin(), vv.end(), [&x]() {return x += 2; });
	PrintContainer(vv);*/

	//cout << std::quoted("hello", '+') << endl;

	//cout << equal(a, a + 3, v.begin(), v.begin() + 3) << endl;

	//replace(v.begin(), v.end(), 3, 99);
	//replace_if(v.begin(), v.end(), [](int a) { return a < 0; }, 99);
	//PrintContainer(v);

	/*for_each(v.begin(), v.end(), [](int& a) { a++; });
	for_each(a, a+7, [](int& a) { a++; });
	for_each_n(l.begin(), 3, [](int& a) { a+=3; });
	PrintContainer(v);
	PrintContainer(l);
	PrintContainer(a);*/

	//cout << all_of(v.begin(), v.end(), [](int a) { return a > 0; }) << endl;

	//auto it = find(v.begin(), v.end(), -25);
	//auto it = find_if(v.begin(), v.end(), [](int a) { return a < 0; });
	/*auto it = find_if_not(v.begin(), v.end(), [](int a) { return a < 0; });
	if (it != v.end())
		cout << *it << endl;*/


		//cout << count(v.begin(), v.end(), 3) << endl;
		//cout << count_if(v.begin(), v.end(), [](int a) { return a % 2 == 0; }) << endl;



		/*multimap<string, int> mm;

		mm.insert({ "one", 11 });
		mm.insert({ "one", 1 });
		mm.insert({ "one", 111 });

		for (auto e : mm)
		{
			cout << e.first << " " << e.second << endl;
		}

		auto i = mm.find("one");
		if(i != mm.end())
			cout << i->first << " " << i->second << endl;

		cout << mm.count("one") << endl;*/

		//map<string, int> m;
		//string s;
		//ifstream in("test.txt");
		//while (getline(in, s, ' '))
		//    if (s != "")
		//    {
		//        transform(s.begin(), s.end(), s.begin(), tolower);
		//        erase_if(s, [](char t) { return t == '\n' || t == ',' || t == '.' || t == ';'; });
		//        m[s]++;
		//    }

		//multimap<int, string, greater<int>> mm;
		//for (auto e : m)
		//{
		//    mm.insert({ e.second, e.first });
		//}

		////for (auto e : mm)
		////{
		////    cout << e.first << " " << e.second << endl;
		////}

		//for (auto i = mm.begin(); i != next(mm.begin(),5); i++)
		//{
		//    cout << i->first << " " << i->second << endl;
		//}


		/*map<string, int> m;
		m["one"] = 1;
		m["one"] = 99;
		m["zero"] = 0;
		auto i = m.insert({ "one1", 11 });


		cout << m.contains("one1") << endl;
		cout << m.count("one1") << endl;

		pair<string, int> p{ "111", 111 };
		m.insert(p);

		for (auto e : m)
		{
			cout << e.first << " " << e.second << endl;
		}

		auto f = m.find("one87");
		if (f != m.end())
			cout << f->first << " " << f->second << endl;

		cout << (2 % 2 == 0) << endl;
		cout << (2 & 1 == 0) << endl;*/

		/*Comparator cm;
		cm(10);

		vector<int> v({ 1,2,4,6 });*/
		//for (int i : v)
		//{
		//    cout << i << " ";
		//}
		//cout << endl;

		////erase_if(v, [](int a) { return a > 3; });
		//erase_if(v, cm);

		//for (int i : v)
		//{
		//    cout << i << " ";
		//}
		//cout << endl;

		//int b = 9, c = 0;

		//auto f = [&](int a) { cout << a << " " << b++ << endl; };
		//f(10);
		//cout << b << endl;

		//auto l = [](int a) -> int
		//    {
		//        if (a > 10)
		//            return 2;
		//        else
		//            return 2.5;
		//    };

		//auto a = [](int a) { return a > 3; };
		//cout << a(10) << endl;


		/*vector<Fraction> f = {Fraction(1,6)};
		f.push_back(Fraction(3, 5));
		f.emplace(f.begin(), 5, 9);
		PrintContainer(f);*/


		//list<int> l(v.begin() + 1, v.begin() + 3);
		//list<int> l = { 1,4,6,8,6,4,3,2 };
		//PrintContainer(l);

		/*auto i = l.begin();
		advance(i, 2);
		l.insert(i, 999);*/

		//l.insert(next(l.begin(), 2), 999);

		//l.erase(next(l.begin(), 2), next(l.begin(), 5));

		//erase_if(l, [](int a) { return a % 2 == 0; });

		//l.remove(6);

		//l.remove_if([](int a) { return a % 2 == 0; });

		//l.sort([](int a, int b) { return a > b; });

		//PrintContainer(l);



		/*Student st1(1, "Vasya", 20);
		st1.addMark(7);
		st1.addMark(8);
		st1.addMark(12);
		st1.addMark(9);

		Student st2(1, "Olga", 18);
		st2.addMark(11);
		st2.addMark(12);
		st2.addMark(12);
		st2.addMark(10);

		Student st3(1, "Oleg", 22);
		st3.addMark(6);
		st3.addMark(8);
		st3.addMark(10);
		st3.addMark(8);

		Student st4(1, "Petya", 15);
		st4.addMark(12);
		st4.addMark(12);
		st4.addMark(12);
		st4.addMark(9);


		list<Student> students = { st1, st2, st3, st4 };
		for (Student& st : students)
		{
			cout << st << endl;
		}
		cout << endl;

		cout << count_if(students.begin(), students.end(), [](Student& st) { return st.getAge() > 20; }) << endl;
		cout << count_if(students.begin(), students.end(), [](Student& st)
			{
				return any_of(st.getMarks(), st.getMarks() + st.getSizeMarks(), [](int a)
					{
						return a == 12;
					});
			}) << endl;

		cout << count_if(students.begin(), students.end(), [](Student& st)
			{
				return count(st.getMarks(), st.getMarks() + st.getSizeMarks(), 12) > 1;
			}) << endl;*/


			////students.sort();
			////students.sort([](const Student& st1, const Student& st2) { return st1.getAge() < st2.getAge(); });
			//     
			//students.sort([](const Student& st1, const Student& st2) { return st1.getSumMarks() > st2.getSumMarks(); });

			//for (Student& st : students)
			//{
			//    cout << st << endl;
			//}


			/*time_t timestamp;
			time(&timestamp);
			struct tm datetime;
			localtime_s(&datetime , &timestamp);
			cout << datetime.tm_hour << endl;
			char buff[80];
			ctime_s(buff, 80, &timestamp);
			cout << buff << endl;

			strftime(buff, 80, "%d.%m.%Y", &datetime);
			cout << buff;*/

			/*using std::cout;


			vector<int> v({ 1,2,4,6 });
			for (int i : v)
			{
				cout << i << " ";
			}
			cout << endl;

			auto i = v.begin() + 2;
			cout << *i << endl;

			v.insert(v.begin() + 2, 999);
			for (int i : v)
			{
				cout << i << " ";
			}
			cout << endl;*/


			/*cout << endl;
			cout << v.size() << endl;
			cout << v.capacity() << endl;
			cout << v.max_size() << endl;
			v.push_back(99);
			cout << endl;
			cout << v.size() << endl;
			cout << v.capacity() << endl;
			v.push_back(99);
			v.push_back(99);
			cout << endl;
			cout << v.size() << endl;
			cout << v.capacity() << endl;*/

			/*foo();
			FOO::foo();

			FOO::DOO::foo2();


			{
				using namespace FOO;


			}*/

			///// 19.12.2024  ///////////////////////

			/*int b = 9;
			int* pb = &b;
			*pb = 99;

			int a = 9;
			int& ra = a;
			ra = 99;

			int&& r = 9;


			function();

			Fraction f(2, 5);

			fract(f);

			fract(Fraction(3, 7));*/

			//auto_ptr<Fraction> f(new Fraction(1, 5));

			/*unique_ptr<Fraction> f1 = make_unique<Fraction>(1,2);
			unique_ptr<Fraction> f2 = move(f1);

			f2->print();*/





			///// 14.12.2024  ///////////////////////

			//try
			//{
			//    int a, b;
			//    cin >> a >> b;
			//    if (b == 0)
			//    {
			//        //throw invalid_argument("b = 0");
			//        throw MyException(__DATE__, __TIME__, __LINE__, "Value b = 0", __FILE__, "log1.txt");
			//    }

			//    cout << a / b << endl;
			//}
			//catch (int a)
			//{
			//    cout << "Error - " << a << endl;
			//}
			//catch (MyException& err)
			//{
			//    cout << err.getError() << endl;
			//    err.saveToFile();
			//}
			//catch (...)
			//{
			//    cout << "Fatal error" << endl;
			//}




			///// 12.12.2024  ///////////////////////


			/*Router r(123, 456);
			cout << r.LAN::getId() << endl;
			cout << r.WiFi::getId() << endl;*/


			/*Cat cat("Tom", 3);
			GetVoice(cat);*/


			/*ConsoleLog log;

			FileLog flog("log.txt");
			try
			{
				cout << super_func(log) << endl;
				cout << super_func(flog) << endl;
			}
			catch (int err)
			{

			}
			catch (const char* err)
			{
				cout << err << endl;
			}*/




			/*Animal* cat = new Cat("Tom", 3);
			cat->info();
			Cat* c = dynamic_cast<Cat*>(cat);
			if (c)
			{
				c->CatchMouse();
				c->getMouse();
			}
			else
			{
				cout << "Not Cat" << endl;
			}*/
			/*WarOfWorld war(10);
			war.game();*/



			///// 05.12.2024  ///////////////////////


			/*
			const int size = 3;
			Shape* sh[] = { new Square(3,4,5), new Circle(3,4,5)};

			ofstream out("shapes.txt");
			out << size << endl;
			for (size_t i = 0; i < 2; i++)
			{
				sh[i]->save(out);
			}*/


			/*ifstream in("shapes.txt");
			int size;
			in >> size;
			in.get();
			Array<Shape*> sh1;
			for (size_t i = 0; i < size; i++)
			{
				string type;
				getline(in, type);
				Shape* s = getShape(type);
				s->load(in);
				sh1.add(s);
			}*/




			//Animal* a = new Animal("Noname", 0);


			//Animal* c = new Cat("Tom", 3);
			//c->info();
			//c->voice();
			////delete c;



			//Animal* d = new Dog("Spike", 5);
			//d->info();
			//d->voice();
			//cout << endl;


			//Animal* sc = new SiamCat("Tom II", 3);

			//Animal* an[] = { c, d, sc, a };
			//for (size_t i = 0; i < 4; i++)
			//{
			//    an[i]->info();
			//    an[i]->voice();
			//}


			//Human h("Oleg", 16);
			//h.info();
			//h.kill();
			//

			//Stud st("Olga", 17, 100);
			//st.info();
			///*st.kill();*/


			//A a;
			//a.a();

			//B b;
			//b.b();

			//BitString s1("1011");
			//BitString s2;
			////String s3 = s1 + s2;
			//cout << s1 << endl; // 1100




			/*Engine* en = new Engine;
			{
				Car car;
				car.move();
			}*/


			/*Protocol p;
			cin >> p;


			BasePolice base;
			base.menu();*/


			/*BTree<int, int> b;
			b.push_r(30, 30);
			b.push_r(10, 10);
			b.push_r(50, 50);
			b.push_r(5, 5);
			b.push_r(30, 30);

			b.print();

			auto i = b.getValue(20);
			if (i)
			{
				cout << *i << endl;
			}
			else
			{
				cout << "Not found" << endl;
			}

			b.remove(10);

			b.print();*/


			//List<int> l = { 10,2,3,15,6 };
			//l.print();
			//l.insert(999, 2);
			////l.pop_back();
			//l.remove(3);
			//l.print();

			//l.printReverse();

			//l.sort();
			//l.print();


			/*string fname[] = { "file1.doc", "file2.xls", "file3.txt", "file4.pdf", "file5.ppt" };

			PrintServer ps("10.6.6.45");

			int i = 0;
			while (true)
			{
				if (i % 4 == 0)
				{
					ps.addTask(TaskPrint(fname[rand() % 5], rand() % 3 + 5, (DEPARTMENT)(rand() % 4)));
				}
				ps.work();
				i++;
				Sleep(500);
			}*/


			/*PriorityQueue<int> q;
			q.enqueue(10, 1);
			q.enqueue(20, 5);
			q.enqueue(30, 2);
			q.enqueue(40, 2);
			q.enqueue(50, 1);
			q.print();
			q.dequeue();
			q.print();
			q.enqueue(999, 2);
			q.print();*/

			//Queue<int> q = {1,2,3,5};
			//q.enqueue(10);
			//q.enqueue(50);
			//q.enqueue(30);
			//q.enqueue(20);
			//q.enqueue(40);
			//q.print();
			//q.dequeue();
			//q.print();
			////cout << q.peek() << endl;
			//q.ring();
			//q.print();

			//int a[] = { 1,2,3,4, };

		   /* Stack<int, 10> s;
			s.push(50);
			s.push(30);
			s.push(60);
			s.push(80);
			s.print();
			s.pop();
			s.print();
			Stack<int, 10> s2 = s;
			s2.print();
			s2.pop();
			s2.print();*/

			/*string st = "3+3^2*2";
			Calc calc;
			cout << st << " = " << calc(st) << endl;*/

			///// 07.11.2024  ///////////////////////

			//Array<int> a(10, 10);
			//a.fill();
			////a.print();
			//cout << a.capacity() << endl;
			//cout << a.size() << endl;
			//cout << a.grow() << endl;
			////a.getData()[1000] = 9999;
			//cout << a.getData()[1000] << endl;


			/*a.add(99);
			cout << a.capacity() << endl;
			cout << a.size() << endl;
			cout << a.grow() << endl;
			a.add(99);
			a.add(99);
			a.add(99);
			a.add(99);
			cout << a.capacity() << endl;
			cout << a.size() << endl;
			cout << a.grow() << endl;
			a.add(99);
			cout << a.capacity() << endl;
			cout << a.size() << endl;
			cout << a.grow() << endl;*/

			//a.for_each(print);
			//a.print();
			//a.add(Fraction(3, 7));
			//a.print();



		   /* String s1("mamasssa");
			String s2("papacca");
			String s3 = s1 * s2;
			cout << s3 << endl;
			cin >> s3;
			cout << s3 << endl;

			string s;*/




			/*Array a1(10);
			a1.fill();
			a1.print();

			Array a2(5);
			a2.fill();
			a2.print();

			a1 += a2;

			Array a3 = a1 + a2;
			a3.print();

			a1[3] = 100;
			cout << a1[3] << endl;

			a1(15);
			a1.print();


			Fraction f1(1, 2);
			Fraction f2(1, 4);
			cout << (f1 > f2) << endl;
			cout << (f1 < f2) << endl;
			cout << (f1 >= f2) << endl;
			cout << (f1 <= f2) << endl;

			f1(3, 5);

			float f = f1;

			Reservoir r = f1;
			r.info();*/



			///// 31.10.2024  ///////////////////////

			// :: sizeof ?: * .

			// - + ++ -- 
			// = + - * / % += -= *= /= %= 

			// !
			// > < == != >= <=

			// [] 




			//int a = 10;
			//int b = !a;

			//Fraction f1(1, 2);
			//Fraction f2(1, 4);
			////Fraction f3 = f1.min(f2);
			//Fraction f3 = f1 + f2; // f1.operator+(f2)
			//f3.print();
			//Fraction f4 = f1;
			//f4.print();
			//f1.print();
			//f1 = f2 = f4;

			/*Student s1(1, "Vasya", 15);
			{
				Student s2(2);

				s1 = s1;
				s1.print();
			}
			s1.print();*/

			/*String s();
			String s(20);
			String s("mama");

			MyUnion m = { 97 };
			cout << m.a << endl;
			cout << m.b << endl;


			Reservoir r1(TYPE::OCEAN, "Anlantic", 400, 500, 5000);
			Reservoir r2(TYPE::SEA, "Black Sea", 400, 500, 2000);
			r1.info();
			r2.info();

			cout << r1.equalType(r2) << endl;*/


			/*r1.copy(r2);
			r1.info();*/
			//r2.getArea();  //getArea(r2)

			//Color c = Color::Black;
			//Animal a = Animal::CAT;
			//if (c == 0)
			//{
			//    cout << "Yes" << endl;
			//}



			//Time t1;
			//Time t2(20);
			/*Time t3(1, 30);
			Time t4(1, 4, 55);*/

			//t1.print();

			/*Array a(10);
			a.fill();
			a.print();
			a.add(99);
			a.print();*/

			//const int a = 10;
			//a = 100;

			/*int a = 5;
			int b(5.5);
			int c{ 5 };

			Student st(1, "Vasya", 15);*/

			//printArr(20);

			///// 24.10.2024  ///////////////////////

			/*cout << Student::getCount() << endl;
			Student st("Vasya", 15);
			cout << Student::getCount() << endl;
			st.print();
			printStudent(st);
			st.print();
			cout << Student::getCount() << endl;*/


			//cout << Student::getCount() << endl;

			//Student st;
			//cout << st.getCount() << endl;
			////st.age = 2000;

			//st.setAge(2000);
			////char name[] = "Serg";
			//st.setName("Serg II");
			//
			//int* m;
			//st.print();
			//{
			//    Student* st2 = new Student("Vasya", 20);

			//    cout << st2->getCount() << endl;
			//    //st2->setAge(20);
			//    st2->setName("Vasya 2");
			//    st2->print();

			//    st2->addMark(10);
			//    st2->addMark(10);
			//    st2->addMark(10);
			//    st2->addMark(10);

			//    st2->print();
			//    //m = st2->getMarks();
			//    delete st2;
			//}


}

