#include <iostream>
// #include "matrix.h"
// #include "Vector.h"

template<class T>
class Vector1{
private:
    T* _arr;
    size_t _size;
    size_t _startIndex;
public:

    Vector1(size_t size, size_t SIndex){
        _size = size;
        _startIndex = SIndex;
        _arr = new int[_size];
        for (size_t i = 0; i < _size; i++){
            _arr[i] = 0;
        }
    }       
    Vector1 (const Vector1& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        _arr = new int[_size];
        for (size_t i = 0; i < _size; i++){
            _arr[i] = tmp._arr[i];
        }
}
    Vector1(Vector1&& tmp); // &
    ~Vector1(){
        delete [] _arr;
    }; 
    size_t GetSize() const{
        return _size;
    };
    size_t GetSIndex()const{
        return _startIndex;
    };
    T& operator[](size_t ins){
    return _arr[ins];
    }


    Vector1& operator=(const Vector1& tmp){
    if (this != &tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        for (size_t i = 0; i < _size; i++){
            _arr[i] = tmp._arr[i];
        }
    }
    return *this;
}
    bool operator== (const Vector1& tmp)const{
        for (size_t i = 0; i < _size; i++){
            _arr[i] != tmp._arr[i];
            return 0;
        }
        return 1;
    };




T&  GetElem(size_t pos){
    if (pos < _size){
        return _arr[pos];
    }

}

    Vector1 operator+(const T& tmp) const{
        Vector1 ans(_size);
        for (size_t i = 0; i < _size; i++){
            _arr[i] += tmp;
        }
        return ans
    };
    Vector1 operator-(const T& tmp) const{
        Vector1 ans(_size);
        for (size_t i = 0; i < _size; i++){
            _arr[i] -= tmp;
        }
        return ans
    };

    Vector1 operator+(const Vector1& tmp) const{
        Vector1 ans(_size);
        for (size_t i = 0; i < _size; i++){
            _arr[i] += tmp.arr[i];
        }
        return ans;
    }
    Vector1 operator-(const Vector1& tmp) const{
        Vector1 ans(_size);
        if (_size == tmp._size){
            for (size_t i = 0; i < _size; i++){
                _arr[i] -= tmp.arr[i];
            }
            return ans;     
        }
        throw "size != tmp.size";
    }

    size_t operator*(const Vector1& tmp) const{
        size_t ans;
        if (_size == tmp._size){
            for (size_t i = 0; i < _size; i++){
                ans += _arr[i] * tmp._arr[i];
            }
            return ans;
        }
        throw "size != tmp.size";
    }
    



};


template<class T>
class Matrix : public Vector1<Vector1<T>>
{
public:
    Matrix(size_t size):Vector1<Vector1<T>> (size,0){
        for (size_t i = 0; i < size; i++){
            this->_arr[i] = Vector1<T>(size-i,i);
        }
    }
    ~Matrix();

    Matrix(const Matrix& mt) : Vector1<Vector1<T>>(mt){

    }
 
    Matrix(const Vector1<Vector1<T>>& vv): Vector1<Vector1<T>>(vv);
    Matrix& operator=(const Matrix& mt){
        if (th)
    }
    Matrix operator+(const Matrix& mt){return Vector1<Vector1<T>> :: operator+(mt);};
    Matrix operator-(const Matrix& mt);
    Matrix operator*(const Matrix& mt);
};

int main(){
    Vector1<int> a(10,0);
    return 0;
}