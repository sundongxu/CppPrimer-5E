#ifndef EXERCISE_34_H
#define EXERCISE_34_H
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message
{
  friend class Folder;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);

public:
  // folders被隐式初始化为空集合
  explicit Message(const string &str = "") : contents(str) {} // 默认构造
  Message(const Message &);                                   // 拷贝构造
  Message(Message &&);                                        // 移动构造
  Message &operator=(const Message &);                        // 赋值运算符
  Message &operator=(Message &&);                             // 移动赋值
  ~Message();                                                 // 析构

  // 从给定Folder集合中添加/删除本Message
  void save(Folder &);
  void remove(Folder &);
  void print_debug();

  void move_Folders(Message *m); // 从本Message移动Folder指针

private:
  string contents;       // 实际消息文本
  set<Folder *> folders; // 包含本Message的Folder

  void add_to_Folders(const Message &); // 将本Message添加到指向参数的Folder中
  void remove_from_Folders();           // 从folders中的每个Folder中删除本Message

  void addFldr(Folder *f) { folders.insert(f); }
  void remFldr(Folder *f) { folders.erase(f); }
};

class Folder
{
  friend class Message;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);

public:
  Folder() = default;
  Folder(const Folder &);
  Folder &operator=(const Folder &);
  ~Folder();

  void print_debug();

private:
  std::set<Message *> msgs;

  void add_to_Messages(const Folder &);
  void remove_from_Messages();

  void addMsg(Message *m) { msgs.insert(m); }
  void remMsg(Message *m) { msgs.erase(m); }
};

#endif