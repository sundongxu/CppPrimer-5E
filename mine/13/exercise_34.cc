#include "exercise_34.h"

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    // 将每个消息指针从它原来所在的Folder中删除
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();
    swap(lhs.folders, rhs.folders);   // 使用swap(set&, set&)
    swap(lhs.contents, rhs.contents); // 使用swap(string&. string&)
    // 将每个Message指针添加到它新的Folder中
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    lhs.remove_from_Messages();
    rhs.remove_from_Messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Messages(lhs);
    rhs.add_to_Messages(rhs);
}

// 拷贝构造
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); // 将本消息添加到指向m的Folder中
}

// 移动构造
Message::Message(Message &&m) : contents(std::move(m.contents))
{
    move_Folders(&m);
}

// 拷贝赋值
Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();   // 左侧运算对象先从原folders中删除
    contents = rhs.contents; // 从rhs拷贝消息
    folders = rhs.folders;   // 从rhs拷贝Folder指针
    add_to_Folders(rhs);     // 将本Message添加到那些Folder中
    return *this;
}

// 移动赋值
Message &Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs); // 重置Folders指向本Message
    }
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f); // set存储的是folder指针
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::print_debug()
{
    cout << contents << endl;
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders); // 使用set的移动赋值运算符
    for (auto f : folders)
    {
        f->remMsg(m);    // 从Folder中删除旧Message
        f->addMsg(this); // 将本Message添加到Folder中
    }
    m->folders.clear(); // 确保销毁m是无害的
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::print_debug()
{
    for (auto m : msgs)
        cout << m->contents << " ";
    cout << endl;
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs)
        m->remFldr(this);
}