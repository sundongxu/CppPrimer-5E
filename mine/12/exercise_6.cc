#include <iostream>
#include <vector>

using namespace std;

vector<int> *dynamic_vector_generator()
{
    return new vector<int>;
}

void dynamic_vector_processor(vector<int> *p)
{
    int i = 0;
    while (cin >> i)
        p->push_back(i);
}

void dynamic_vector_printer(vector<int> *p)
{
    for (int i : *p)
        cout << i << " ";
}

int main()
{
    vector<int> *p = dynamic_vector_generator();
    dynamic_vector_processor(p);
    dynamic_vector_printer(p);
    return 0;
}