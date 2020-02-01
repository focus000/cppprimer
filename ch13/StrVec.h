#ifndef STRVEC
#define STRVEC

#include <string>
#include <memory>

class StrVec
{
private:
    std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;

public:
    // types
    typedef size_t size_type;
    // constractor/copy/destructor
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    StrVec(StrVec const &);
    StrVec &operator=(StrVec const &);
    ~StrVec();
    // iterators
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    // capacity
    size_type size() const { return first_free - elements; }
    size_type capacity() const { return cap - elements; }
    void reserve(size_type);
    void resize(size_type);
    void resize(size_type, std::string const &);
    // modifiers
    void push_back(std::string const &);

private:
    void free();
    void alloc_n_move(size_type);
    void reallocate();
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(std::string const *, std::string const *);
    void range_initialize(std::string const *, std::string const *);
};

#endif