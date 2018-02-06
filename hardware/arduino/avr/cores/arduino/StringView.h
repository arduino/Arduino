// Written by Steve Weinrich 2018
// This code is given freely and without restriction of any kind to the Arduino community

#ifndef StringView_H
#define StringView_H

#include <string.h>

class StringView
{
    // Use a function pointer to allow for "if (s)" without the
    // complications of an operator bool(). For more information, see:
    // http://www.artima.com/cppsource/safebool.html
    typedef void (StringView::*StringViewIfHelperType)() const;
    void StringViewIfHelper () const {}

 public:
    // types
    typedef char               value_type;
    typedef value_type *       pointer;
    typedef const value_type * const_pointer;
    typedef const value_type & const_reference;
    typedef size_t             size_type;

    // construction and assignment
    StringView ()
        : mData(nullptr), mLength(0)
    {}

    StringView (const StringView &) = default;
    
    // When constructing from a C-String, the null terminator is dropped.
    StringView (const_pointer str);

    StringView (const_pointer str, size_type len)
        : mData(str), mLength(len)
    {}

    StringView (StringView && rval);

    StringView & operator = (const StringView &) = default;
    StringView & operator = (StringView && rval);

    size_t length () const { return mLength; }

    operator StringViewIfHelperType () const { return length() ? &StringView::StringViewIfHelper : 0; }
    int compareTo (StringView rhs) const; 
    bool equals (StringView rhs) const { return 0 == compareTo(rhs); }
    bool equalsIgnoreCase (StringView rhs) const;
    bool startsWith (StringView prefix, size_type offset = 0) const;
    bool endsWith (StringView suffix) const;

    // character acccess
    value_type charAt (size_type index) const { return operator[](index); }
    value_type operator [] (size_type index) const;
    void getBytes (unsigned char * buf, size_t bufsize, size_t index = 0) const;
    void toCharArray (pointer buf, size_t bufsize) const
    {
        getBytes((unsigned char *)buf, bufsize);
    }
    const_pointer begin () const { return mData; }
    const_pointer end () const { return begin() + length(); }

    // search
    int indexOf (value_type ch, size_type fromIndex = 0) const;
    int indexOf (StringView str, size_type fromIndex = 0) const;
    int lastIndexOf (value_type ch, size_type fromIndex = 0) const;
    int lastIndexOf (StringView str, size_type fromIndex = 0) const;
    StringView substring (size_type beginIndex) const { return substring(beginIndex, length() - 1); } 
    StringView substring (size_type beginIndex, size_type endIndex) const;

    // modification
    void trim ();

    // parsing/conversion
    long toInt () const;
    float toFloat () const;
    double toDouble () const;

 private:
    const_pointer mData;
    size_type     mLength;

    void copyForConversion (pointer buffer, size_type bufLength);
};

// non-member comparison functions
inline bool operator == (StringView x, StringView y) { return x.compareTo(y) == 0; }
inline bool operator != (StringView x, StringView y) { return x.compareTo(y) != 0; }
inline bool operator <  (StringView x, StringView y) { return x.compareTo(y) < 0; }
inline bool operator >  (StringView x, StringView y) { return x.compareTo(y) > 0; }
inline bool operator <= (StringView x, StringView y) { return x.compareTo(y) != 1; }
inline bool operator >= (StringView x, StringView y) { return x.compareTo(y) != -1; }

#endif