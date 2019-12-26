/*
 * @Author: liyunfang
 * @Date: 2019-12-26 21:02:59
 * @LastEditTime : 2019-12-26 21:21:24
 * @Description: 
 */
#include <iterator>
#include <fstream>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 4) return -1;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
    std::for_each(in, in_eof, [&](int const &i){
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });

   ifs.close();
   ofs_odd.close();
   ofs_even.close();
}