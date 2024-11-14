
#include <iostream>
#include <math.h>
#include <Windows.h>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"Reservoir.h"
#include"Fraction.h"
#include"String.h"
#include"Stack.h"
#include"Calc.h"
#include"Queue.h"
#include"PriorityQueue.h"

using namespace std;

void printStudent(Student st)
{
    cout << Student::getCount() << endl;
    st.print();
}

template<class T>
void printArr(Array<T> arr)
{
    arr.print();
}


enum class Color
{
    Black, White
};

enum class Animal
{
    CAT, DOG, Black
};

union MyUnion
{
    int a;
    char b;
};

void addOne(int& val)
{
    val++;
}

void print(int& val)
{
    cout << val << " ";
}

int main()
{
    cout.setf(ios::boolalpha);


    


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

