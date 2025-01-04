#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Храним в `data` нулевой вектор длины `n`
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
            ++first;
        }
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator [] (size_t i) {
        return data[i];
    }

    const T& operator [] (size_t i) const {
        return data[i];
    }
};

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

template <typename T>
MathVector<T>& operator+= (MathVector<T>& v, const MathVector<T>& f) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] += f[i];
    }
    return v;
}

template <typename T>
MathVector<T> operator + (const MathVector<T>& v, const MathVector<T>& f) {
    MathVector<T> tmp(v.Dimension());
    for (size_t i = 0; i != v.Dimension(); ++i) {
        tmp[i] = v[i] + f[i];
    }
    return tmp;
}

#include <iostream>
using namespace std;

int main() {
    // MathVector<int> vect(3);
    // for (int i=0; i<3; ++i) vect[i]=(i+1)*2;
    vector<int> a = {1, 2, 3, 4, 5};
    MathVector<int> vect(a.begin(), a.end());
    MathVector<int> vect2(a.begin(), a.end());
    vect2 *= 2;
    cout<<vect<<endl;
    cout<<vect2<<endl;
    // vect+=vect2;
    MathVector<int> vect3 = vect+vect2;
    cout<<vect3<<endl;
    cout<<vect<<endl;
}