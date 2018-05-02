// Written by Steve Weinrich 2018
// This code is given freely and without restriction of any kind to the Arduino community

#include <StringView.h>
#include <ctype.h>
#include <stdlib.h>

StringView::StringView (const_pointer str)
    : mData(str), mLength(strlen(str))
{
}

StringView::StringView (StringView && rval)
    : mData(rval.mData), mLength(rval.mLength)
{
    rval.mData   = nullptr;
    rval.mLength = 0;
}

StringView & StringView::operator = (StringView && rval)
{
    mData   = rval.mData;
    mLength = rval.mLength;

    rval.mData   = nullptr;
    rval.mLength = 0;

    return *this;
}

int StringView::compareTo (StringView rhs) const
{
    if (length() < rhs.length())
        return -1;
    else if (length() > rhs.length())
        return 1;
    else
        return memcmp(begin(), rhs.begin(), length());
}

bool StringView::equalsIgnoreCase (StringView rhs) const
{
    if (length() != rhs.length()) return false;
    if (length() == 0) return true;

    const_pointer p1 = begin();
    const_pointer p2 = rhs.begin();

    for (size_t i = 0; i < length(); ++i)
        if (tolower(*p1++) != tolower(*p2++)) return false;

    return true;
}

bool StringView::startsWith (StringView prefix, size_type offset) const
{
    if (!*this || !prefix || (offset > length() - prefix.length())) return false;
    return 0 == memcmp(begin() + offset, prefix.begin(), prefix.length());
}

bool StringView::endsWith (StringView suffix) const
{
    if (!*this || !suffix || length() < suffix.length()) return false;
    return 0 == memcmp(end() - suffix.length(), suffix.begin(), suffix.length());
}

StringView::value_type StringView::operator [] (size_t index) const
{
    if (index >= length()) return 0;
    return begin()[index];
}

void StringView::getBytes (unsigned char * buf, size_t bufsize, size_t index) const
{
    if (!bufsize || !buf) return;

    if (index >= length())
    {
        buf[0] = '\0';
        return;
    }

    size_t n = bufsize - 1;
    if (n > length() - index) n = length() - index;
    memcpy(buf, begin() + index, n);
    buf[n] = '\0';
}

int StringView::indexOf (value_type ch, size_type fromIndex) const
{
    if (fromIndex >= length()) return -1;

    const_pointer r = memchr(begin() + fromIndex, ch, length() - fromIndex);
    if (r == NULL) return -1;
    return r - begin();
}

int StringView::indexOf (StringView str, size_type fromIndex) const
{
    if (!str || fromIndex >= length() || str.length() > length() - fromIndex) return -1;

    const_pointer p1 = begin() + fromIndex;
    for (size_t i = fromIndex; i < length() - fromIndex; ++i, ++p1)
        if (0 == memcmp(p1, str.begin(), str.length())) return i;

    return -1;
}

int StringView::lastIndexOf (value_type ch, size_type fromIndex) const
{
    if (fromIndex >= length()) return -1;

    const_pointer r = memrchr(begin() + fromIndex, ch, length() - fromIndex);
    if (r == NULL) return -1;
    return r - begin();
}

int StringView::lastIndexOf (StringView str, size_type fromIndex) const
{
    if (!str || fromIndex >= length() || str.length() > length() - fromIndex) return -1;

    const_pointer p1 = end() - str.length();
    for (size_type i = length() - str.length(); i > fromIndex; --i, --p1)
        if (0 == memcmp(p1, str.begin(), str.length())) return i;

    return -1;
}

StringView StringView::substring (size_type beginIndex, size_type endIndex) const
{
    if (beginIndex >= length() || endIndex == 0) return StringView();

    size_type end = endIndex;
    if (end >= length()) end = length() - 1;

    return StringView(begin() + beginIndex, end - beginIndex + 1);
}

void StringView::trim ()
{
    if (!*this) return;

    const_pointer s = begin();
    while (isspace(*s)) ++s;

    const_pointer e = end() - 1;
    while (isspace(*e) && e >= begin()) --e;

    mData = s;
    mLength = e + 1 - s;
}

void StringView::copyForConversion (pointer buffer, size_type bufLength)
{
    --bufLength;

    StringView v(*this);
    v.trim();
    size_type l = v.length();
    if (l > bufLength) l = bufLength;

    memcpy(buffer, v.begin(), l);
    buffer[l] = '\0';
}

long StringView::toInt() const
{
    if (!*this) 0;

    // atol() requires a null terminated C-string.
    value_type cstr[31];
    copyForConversion(cstr, 31);
    return atol(cstr);
}

float StringView::toFloat () const
{
    return float(toDouble());
}

double StringView::toDouble () const
{
    if (!*this) return 0;

    // atof() requires a null terminated C-string.
    value_type cstr[31];
    copyForConversion(cstr, 31);
    return atof(cstr);
}

