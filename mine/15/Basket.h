#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include <set>
#include "Quote.h"

using namespace std;

class Basket
{
public:
  // Basket使用合成的默认构造函数和拷贝控制成员
  void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }
  void add_item(const Quote &sale) { items.insert(shared_ptr<Quote>(sale.clone())); }       // 拷贝给定的对象
  void add_item(Quote &&sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); } // 移动给定的对象
  // 打印每本书的总价和购物篮中所有书的总价
  double total_receipt(ostream &) const;

private:
  // compare函数用于比较shared_ptr，multiset成员会用到它
  static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
  // multiset保存多个报价，按照compare成员排序
  multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
  double sum = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
  {
    // 在当前的Basket中至少有一个该关键字的元素
    // 打印该书籍的项目
    sum += print_total(os, **iter, items.count(*iter));
  }
}

#endif // BASKET_H