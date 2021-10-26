// algorithm, max()

#include <vector>

#include <set>

#include <algorithm>

#include <iostream>

using namespace std;

 

class CInt;

ostream& operator<<(ostream& osIn, const CInt& rhs);

 

class CInt

{

    public:

       CInt(int n = 0) : m_nVal(n){    }

       CInt(const CInt& rhs) : m_nVal(rhs.m_nVal){    }

       CInt& operator=(const CInt& rhs)

       {    m_nVal = rhs.m_nVal; return *this;    }

       bool operator<( const CInt& rhs ) const

       {    return (m_nVal < rhs.m_nVal);    }

      friend ostream& operator<<(ostream& osIn, const CInt& rhs);

    private:

       int m_nVal;

};

 

inline ostream& operator<<(ostream& osIn, const CInt& rhs)

{

   osIn<<"CInt("<<rhs.m_nVal<<")";

   return osIn;

}

 

// return whether modulus of elem1 is greater than modulus of elem2

bool mod_greater(int elem1, int elem2)

{

   if(elem1 < 0)

      elem1 = - elem1;

   if(elem2 < 0)

      elem2 = - elem2;

   return (elem1 > elem2);

};

 

int main()

{

    // comparing integers directly using the max algorithm

    int a = 11, b = -12, c = 20;

    const int& result1 = max(a, b, mod_greater);

    const int& result2 = max(b, c);

    cout<<"The mod_greater of the integers 11 and -12 is: "<<result1<<endl;

    cout<<"The larger of the integers -12 and 20 is: "<<result2<<endl;

    cout<<endl;

    // comparing set containers with elements of type CInt using the max algorithm

    CInt c1 = 1, c2 = 2, c3 = 3;

    set<CInt> st1, st2, st3;

    set<CInt>::iterator st1_Iter, st2_Iter, st3_Iter;

    st1.insert(c1);

    st1.insert(c2);

    st2.insert(c2);

    st2.insert(c3);

    cout<<"st1 data: (";

    for(st1_Iter = st1.begin(); st1_Iter != --st1.end(); st1_Iter++)

        cout<<*st1_Iter<<",";

    st1_Iter = --st1.end();

    cout<<*st1_Iter<<")."<<endl;

    cout<<"st2 data: (";

    for(st2_Iter = st2.begin(); st2_Iter != --st2.end(); st2_Iter++)

        cout<<*st2_Iter<<",";

    st2_Iter = --st2.end();

    cout<<*st2_Iter<<")."<<endl;

    st3 = max(st1, st2);

    cout<<"st3 = max(st1, st2) = (";

    for(st3_Iter = st3.begin(); st3_Iter != --st3.end(); st3_Iter++)

        cout<<*st3_Iter<<",";

    st3_Iter = --st3.end();

    cout<<*st3_Iter<<")."<<endl;

    // comparing vectors with integer elements using the max algorithm

    vector <int> vec1, vec2, vec3, vec4, vec5;

    vector <int>::iterator Iter1, Iter2, Iter3, Iter4, Iter5;

    int i;

    for(i = 0; i <= 3; i++)

        vec1.push_back(i);

    int j;

    for(j = 0; j <= 4; j++)

        vec2.push_back(j);

    int k;

    for(k = 0; k <= 2; k++)

        vec3.push_back(2*k);

    cout<<"\nVector vec1 data: ";

    for(Iter1 = vec1.begin(); Iter1 != vec1.end(); Iter1++)

        cout<<*Iter1<<" ";

    cout<<endl;

    cout<<"Vector vec2 data: ";

    for(Iter2 = vec2.begin(); Iter2 != vec2.end(); Iter2++)

        cout<<*Iter2<<" ";

    cout<<endl;

    cout<<"Vector vec3 data: ";

    for(Iter3 = vec3.begin(); Iter3 != vec3.end(); Iter3++)

        cout<<*Iter3<<" ";

    cout<<endl;

    vec4 = max(vec1, vec2);

    vec5 = max(vec1, vec3);

    cout<<"Vector vec4 = max(vec1,vec2) is: ";

    for(Iter4 = vec4.begin(); Iter4 != vec4.end(); Iter4++)

        cout<<*Iter4<<" ";

    cout<<endl;

    cout<<"Vector vec5 = max(vec1,vec3) is: ";

    for(Iter5 = vec5.begin(); Iter5 != vec5.end(); Iter5++)

        cout<<*Iter5<<" ";

    cout<<endl;

    return 0;

}
