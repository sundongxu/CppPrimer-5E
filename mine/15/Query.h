#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;

class Query_base
{
    friend class Query;

  protected:
    using line_no = TextQuery::line_no; // 行号
    virtual ~Query_base() = default;

  private:
    virtual QueryResult eval(const TextQuery &) const = 0; // 纯虚，用于求查询的结果
    virtual string rep() const = 0;                        // 纯虚，用于生成查询的string版本
};

class Query
{
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator~(const Query &);

  public:
    Query(const string &); // 构造新的WordQuery，故Query必须生命为Query_base的友元

    // 接口函数，调用对应的Query_base操作
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const { return q->rep(); }

  private:
    Query(shared_ptr<Query_base> query) : q(query) {}

    shared_ptr<Query_base> q;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand)); // 由shared_ptr隐式构造一个Query对象返回
}

inline Query::Query(const string &s) : q(new WordQuery(s)) {}

inline ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query; // 因为Query使用了WordQuery的构造函数
    WordQuery(const string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    string rep() const { return query_word; }
    string query_word; // 要查询的单词
};

class NotQuery : public Query_base
{
    friend Query operator~(const Query &); // 因为~运算符函数要使用NotQuery的构造函数
    NotQuery(const Query &q) : query(q) {}

    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

class BinaryQuery : public Query_base
{
  protected:
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s) {}

    string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

    Query lhs, rhs; // 左右操作对象均为Query
    string opSym;   // 操作符
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &); // 因为&运算符函数要使用AndQuery的构造函数
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}

    QueryResult eval(const TextQuery &) const;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &); // 因为|运算符函数要使用OrQuery的构造函数
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}

    QueryResult eval(const TextQuery &) const;
};

ifstream &open_file(ifstream &, const string &);
TextQuery get_file(int, char **);
bool get_word(string &);
bool get_words(string &, string &);
ostream &print(ostream &, const QueryResult &);

#endif