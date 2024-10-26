
#include <iostream>

#include"Student.h"
#include"Array.h"
#include"Time.h"
#include"Reservoir.h"

using namespace std;

void printStudent(Student st)
{
    cout << Student::getCount() << endl;
    st.print();
}


void printArr(Array arr)
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

int main()
{
    cout.setf(ios::boolalpha);


    String s();
    String s(20);
    String s("mama");

    MyUnion m = { 97 };
    cout << m.a << endl;
    cout << m.b << endl;


    Reservoir r1(TYPE::OCEAN, "Anlantic", 400, 500, 5000);
    Reservoir r2(TYPE::SEA, "Black Sea", 400, 500, 2000);
    r1.info();
    r2.info();

    cout << r1.equalType(r2) << endl;


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

