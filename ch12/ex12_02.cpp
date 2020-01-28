/*
 * @Author: liyunfang
 * @Date: 2020-01-29 00:38:42
 * @LastEditTime : 2020-01-29 00:52:48
 * @Description: 
 */
#include "ex12_02.h"
#include "ex12_19.h"

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
