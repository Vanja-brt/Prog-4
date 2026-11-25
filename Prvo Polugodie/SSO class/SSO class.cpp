#include <iostream>
#include <cstring>
using namespace std;


class SSOString {
    char small[16];
    char* array;
    short sz;
    short cap;

    void allocate(int n) {
        sz = n;
        if (n < 16) {
            array = small;
            cap = 16 - 1;
        } else {
            array = new char[n + 1];
            cap = n;
        }
    }

    bool isSmall() const {
        return array == small;
    }

public:
    SSOString() {
        allocate(0);
        array[0] = '\0';
    }

    SSOString(const char* s) {
        allocate(strlen(s));
        strcpy(array, s);
    }

    SSOString(const SSOString& other) {
        allocate(other.sz);
        strcpy(array, other.array);
    }

    ~SSOString() {
        if (!isSmall()) {
            delete[] array;
        }
    }

    SSOString& operator=(const SSOString& other) {
        if (this == &other) {
            return *this;
        }
        if (!isSmall()) {
            delete[] array;
        }
        allocate(other.sz);
        strcpy(array, other.array);
        return *this;
    }

    char& operator[](int i) {
        return array[i];
    }

    short size() const {
        return sz;
    }

    short capacity() const {
        return cap;
    }

    SSOString operator+(const SSOString& other) const {
        SSOString result;
        result.allocate(sz + other.sz);
        strcpy(result.array, array);
        strcat(result.array, other.array);
        return result;
    }

    friend ostream& operator<<(ostream& out, const SSOString& s) {
        out << s.array;
        return out;
    }
};

int main() {
    SSOString a("Hello");
    SSOString b(", this is a long string!");
    SSOString c = a + b;
    SSOString d = a + " SSO";
    cout << a << " | size=" << a.size() << " cap=" << a.capacity() << endl;
    cout << b << " | size=" << b.size() << " cap=" << b.capacity() << endl;
    cout << c << " | size=" << c.size() << " cap=" << c.capacity() << endl;
    cout << d << " | size=" << d.size() << " cap=" << d.capacity() << endl;
    SSOString e(c);
    e[0] = 'J';
    cout << e << "  (c is still: " << c << ")" << endl;
    e = a;
    cout << e << endl;
    a = c;
    cout << a << endl;
    a = a;
    cout << a << endl;
    SSOString empty;
    cout << "[" << empty << "] size=" << empty.size() << endl;
    return 0;
}