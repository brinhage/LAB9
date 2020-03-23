#include <iostream>
#include <stdexcept>
#include "picture_hanging.h"

#define TODO(X) cout << "[TODO] " << __FUNCTION__ << ": " << X << endl;

using std::cout, std::endl;
using std::ostream;
using std::out_of_range;

/*
make a copy of src (elements 0..len-1)
*/
int* copy(const int src[], const size_t len) {
   // TODO("implement this function");

    int src_copy[len];
    for (size_t i = 0; i < len; ++i) {
        src_copy[i] = src[i];
    }

    return src_copy;
}

/*
return i such that A[i] = key, or -1 if key is not in A
*/
int find(const int A[], const size_t len, const int key) {
   // TODO("implement this function");

    for (size_t i = 0; i < len; ++i) {
        if (A[i] == key) {
            return i;
        }
    }

    return -1;
}

/*
remove the specified number (cnt) of elements starting at specified index (idx)
*/
void remove(int A[], size_t& len, const size_t idx, const size_t cnt) {
   // TODO("implement this function");

    for (size_t i = 0; i < cnt; ++i) {
        for (size_t j = idx; j < idx + cnt; ++j) {
            A[j] = A[j + 1];
        }
        len -= 1;
    }
    
}

/*
remove all instances of duplicate values in A (including opposites, so 1 and -1 are the same)
*/
void removeDuplicates(int A[], size_t& len) {
   // TODO("implement this function");

    for (int i = 0; i < len; ++i) {
        int search = A[i];
        for (int j = i + 1; j < len; ++j) {
            if (A[j] == search || A[j] == -search) {
                // DELETE
                remove(A, len, i, 1);
                remove(A, len, j, 1);
            }
        }
    }
}

/*
returns true if str is not reducible (no canceling neighbors)
*/
bool isStable(/*const*/ int A[], /*const*/ size_t len) {
   // TODO("implement this function");

    size_t len_change = len;
    removeDuplicates(A, len_change);
    if (len_change == len) {
        return true;
    }

    return false;
}

/*
remove all instances of value
*/
void removeAll(int A[], size_t& len, const int value) {
   // TODO("implement this function");

    for (size_t i = 0; i < len; ++i) {
        if (A[i] == value) {
            remove(A, len, i, 1);
        }
    }
}

/*
repeatedly remove any pair of neighbors which are opposites (e.g. 1 and -1).
*/
void reduce(int A[], size_t& len) {
   // TODO("implement this function");

    for (size_t i = 0; i < len - 1; ++i) {
        if (A[i] == A[i + 1] || A[i] == - A[i + 1]) {
            remove(A, len, i, 1);
        }
    }
}

/*
return true if removing any single value (and it's opposite, e.g. 1 and -1) reduces the sequence to empty.
*/
bool isCorrect(/*const*/ int A[], /*const*/ size_t len) {
   // TODO("implement this function");

    reduce(A, len);
    if (len == 0) {
        return true;
    }

    return false;
}
