/*
 * @Author: liyunfang
 * @Date: 2020-01-28 19:19:09
 * @LastEditTime : 2020-01-28 19:27:54
 * @Description: 
 */
#include <memory>

int main()
{
    // error: call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
    std::unique_ptr<int> p(new int(1024)), p1, p2(p);
    // error: object of type 'std::__1::unique_ptr<int, std::__1::default_delete<int> >'
    // cannot be assigned because its copy assignment operator is implicitly deleted
    p1 = p;
}