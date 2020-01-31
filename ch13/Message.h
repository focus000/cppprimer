#ifndef MESSAGE
#define MESSAGE

#include <string>
#include <set>

class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

private:
    std::string contents;
    std::set<Folder *> folders;

public:
    explicit Message(std::string const &str = "") : contents(str) {}
    Message(Message const &);
    Message &operator=(Message tmp);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void swap(Message &);

private:
    void add_to_Folders(Message const &);
    void remove_from_Folders();
};

inline void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

inline void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(Message const &m)
{
    for (auto &&f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto &&f : folders)
    {
        f->remMsg(this);
    }
}

Message::Message(Message const &m) : contents(m.contents), folders(m.folders) { add_to_Folders(m); }

Message::~Message() { remove_from_Folders(); }

void Message::swap(Message &tmp)
{
    using std::swap;
    for (auto &&f : folders)
    {
        f->remMsg(this);
    }
    for (auto &&f : tmp.folders)
    {
        f->remMsg(&tmp);
    }
    swap(contents, tmp.contents);
    swap(folders, tmp.folders);
    for (auto &&f : folders)
    {
        f->addMsg(this);
    }
    for (auto &&f : tmp.folders)
    {
        f->addMsg(&tmp);
    }
}

void swap(Message &lhs, Message &rhs)
{
    lhs.swap(rhs);
}

Message &Message::operator=(Message tmp)
{
    this->swap(tmp);
    return *this;
}

class Folder
{
private:
    std::set<Message *> messages;

public:
    Folder() {}
    ~Folder() {}
    void addMsg(Message const *);
    void remMsg(Message const *);
};

#endif