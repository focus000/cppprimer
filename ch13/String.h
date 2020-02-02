#ifndef STRING_H
#define STRING_H

#include <memory>
#include <cstring>

class String
{
    friend void swap(String &, String &);
private:
    char *elements;
    char *end_;
    static std::allocator<char> alloc;

public:
    // types:
    typedef size_t size_type;
    // constractor/copy/destructor:
    String() : String("") {}
    String(char const *);
    String(String const &);
    String &operator=(String tmp);
    String(String &&) noexcept;
    ~String();
    // element access:
    char const *c_str() const { return elements; }
    // capacity:
    size_type size() const { return end_ - elements; }
    size_type length() const { return end_ - elements - 1; }
    // iterators
    char *begin() const { return elements; }
    char *end() const { return end_; }
    // modifiers
    void swap(String &);

private:
    std::pair<char *, char *> alloc_n_copy(char const *, char const *);
    void range_initializer(char const *, char const *);
    void free();
};

inline
void String::swap(String &rhs)
{
    using std::swap;
    swap(elements, rhs.elements);
    swap(end_, rhs.end_);
    swap(alloc, rhs.alloc);
}

#endif