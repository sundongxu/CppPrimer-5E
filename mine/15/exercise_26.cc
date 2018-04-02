#include "exercise_26.h"

using namespace std;

int main()
{
    // 顺序构造，逆序销毁
    // Quote q1;
    // Quote q2(q1);
    // Quote q3;
    // q3 = q1;
    Bulk_quote bq1;
    Bulk_quote bq2(bq1);
    Bulk_quote bq3;
    bq3 = bq1;
    return 0;
}