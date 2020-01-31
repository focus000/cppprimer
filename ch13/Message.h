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
    Message &operator=(Message const &);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void swap(Message &);

private:
    void add_to_Folders(Message const &);
    void remove_from_Folders();
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

inline void Message::save(Folder &f)
{
    addFldr(&f);
    f.addMsg(this);
}

inline void Message::remove(Folder &f)
{
    remFldr(&f);
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
    remove_from_Folders();
    tmp.remove_from_Folders();
    swap(contents, tmp.contents);
    swap(folders, tmp.folders);
    add_to_Folders(*this);
    tmp.add_to_Folders(tmp);
}

void swap(Message &lhs, Message &rhs)
{
    lhs.swap(rhs);
}

Message &Message::operator=(Message const &rhs) 
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

class Folder
{
private:
    std::set<Message *> messages;

public:
    Folder() = default;
    ~Folder() { remove_from_Messages(); }
    void addMsg(Message *m) { messages.insert(m); }
    void remMsg(Message *m) { messages.erase(m); }

private:
    void remove_from_Messages();
};

void Folder::remove_from_Messages()
{
    for (auto &&m : messages)
    {
        m->remFldr(this);
    }
}

#endif