
#include <iostream>

#include"Student.h"

using namespace std;

int main()
{

    cout << Student::getCount() << endl;

    Student st;
    cout << st.getCount() << endl;
    //st.age = 2000;

    st.setAge(2000);
    //char name[] = "Serg";
    st.setName("Serg II");
    
    int* m;
    st.print();
    {
        Student* st2 = new Student("Vasya", 20);

        cout << st2->getCount() << endl;
        //st2->setAge(20);
        st2->setName("Vasya 2");
        st2->print();

        st2->addMark(10);
        st2->addMark(10);
        st2->addMark(10);
        st2->addMark(10);

        st2->print();
        //m = st2->getMarks();
        delete st2;
    }

    
}

