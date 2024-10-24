
#include <iostream>

#include"Student.h"
#include"Array.h"
#include"Time.h"

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

int main()
{

    Time t1;
    Time t2(20);
    Time t3(1, 30);
    Time t4(1, 4, 55);

    t1.print();

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

