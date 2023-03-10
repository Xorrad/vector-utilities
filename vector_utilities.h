#ifndef VECTOR_UTILITY_H
#define VECTOR_UTILITY_H

#include <iostream>
#include <vector>

/**
 * Overload the stream writing operator for a vector.
 * @tparam T the type of data stored in the vector.
 * @param stream the stream to write to.
 * @param vec the vector.
 * @return the stream.
*/
template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec);

/**
 * Concatenate two vectors.
 * @param lhs the first vector.
 * @param rhs the second vector.
 * @return a vector containing the values of lhs followed by the values of rhs.
*/
template <typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs);

/**
 * Concatenate two vectors.
 * @param src the source vector.
 * @param rhs the vector containing the values to add.
 * @return the source vector with the values of vec.
*/
template <typename T>
std::vector<T>& operator+=(std::vector<T>& src, const std::vector<T>& vec);

/**
 * Duplicate a vector.
 * @param src the vector.
 * @param n the number of copy of the values to make.
 * @return a vector containing n times the values of src.
*/
template <typename T>
std::vector<T> operator*(const std::vector<T>& src, int n);

/**
 * Duplicate a vector.
 * @param src the vector.
 * @param n the number of copy of the values to make.
 * @return the source vector containing n times its values.
*/
template <typename T>
std::vector<T>& operator*=(std::vector<T>& src, int n);

/**
 * Compare two vectors.
 * @param lhs the first vector.
 * @param rhs the second vector.
 * @return true if the size and the values of lhs match the values of rhs, false otherwise.
*/
template <typename T>
bool operator==(const std::vector<T>& lhs, const std::vector<T>& rhs);


template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec)
{
    stream << "vector<" << typeid(T).name() << ">{ ";

    for(int i = 0; i < vec.size(); i++)
        stream << vec[i] << (i < vec.size()-1 ? ", " : "");

    stream << " }";

    return stream;
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    std::vector<T> vec = std::vector<T>(lhs.size() + rhs.size());
    
    for(int i = 0; i < lhs.size(); i++)
        vec[i] = lhs[i];

    for(int i = 0; i < rhs.size(); i++)
        vec[lhs.size() + i] = rhs[i];

    return vec;
}

template <typename T>
std::vector<T>& operator+=(std::vector<T>& src, const std::vector<T>& vec)
{
    std::size_t size = src.size();
    src.resize(size + vec.size());

    for(int i = 0; i < vec.size(); i++)
        src[size + i] = vec[i];

    return src;
}

template <typename T>
std::vector<T> operator*(const std::vector<T>& src, int n)
{
    if(n < 0)
        throw std::invalid_argument("n must be a positive number.");

    std::vector<T> vec = std::vector<T>(src.size() * n);

    for(int j = 1; j < n; j++)
        for(int i = 0; i < src.size(); i++)
            vec[j*src.size() + i] = src[i];

    return vec;
}

template <typename T>
std::vector<T>& operator*=(std::vector<T>& src, int n)
{
    if(n < 0)
        throw std::invalid_argument("n must be a positive number.");

    std::size_t size = src.size();
    src.resize(size * n);

    for(int j = 1; j < n; j++)
        for(int i = 0; i < size; i++)
            src[j*size + i] = src[i];

    return src;
}

template <typename T>
bool operator==(const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if(lhs.size() != rhs.size())
        return false;

    for(int i = 0; i < std::max(lhs.size(), rhs.size()); i++)
        if(lhs[i] != rhs[i])
            return false;

    return true;
}

#endif