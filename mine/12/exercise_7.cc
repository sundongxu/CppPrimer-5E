#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> dynamic_vector_generator()
{
    // return new vector<int>;
    return make_shared<vector<int>>();
}

void dynamic_vector_processor(shared_ptr<vector<int>> sp)
{
    int i = 0;
    while (cin >> i)
        sp->push_back(i);
}

void dynamic_vector_printer(shared_ptr<vector<int>> sp)
{
    for (int i : *sp)
        cout << i << " ";
}

int main()
{
    auto p = dynamic_vector_generator();
    dynamic_vector_processor(p);
    dynamic_vector_printer(p);
    return 0;
}