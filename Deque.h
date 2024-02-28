#pragma once
#include <iostream>
#include "IterDeque.h"

class Deque
{
public:
    friend IterDeque<float>;
    friend IterDeque<const float>;

    typedef IterDeque<float> iterator;
    typedef const IterDeque<const float> const_iterator;

    explicit Deque(float n) : n(n + 1), b(0), e(0)
    {
        q = new float[this->n];
    }

    Deque(std::initializer_list<float> iList);

    Deque(const Deque& qu);
    Deque(Deque&& aDeque) noexcept;

    ~Deque() {
        delete[] q;
    }

    inline bool PushBack(float x);
    inline bool PushFront(float x);

    void PopFront() {
        b = (b + 1) % n;
    }

    void PopBack() {
        e = (e - 1 + n) % n;
    }

    float& Front() {
        return q[b];
    }
    const float& Front() const {
        return q[b];
    }
    float& Back() {
        return q[(e - 1 + n) % n];
    }
    const float& Back() const {
        return q[(e - 1 + n) % n];
    }

    float Size() const {
        return (e + n - b) % n;
    }
    bool IsEmpty() const {
        return b == e;
    }
    void Clear() {
        b = e = 0;
    }

    iterator begin() { 
        return iterator(this, b); 
    }
    const_iterator begin() const { 
        return const_iterator(this, b); 
    }
    iterator end() { 
        return iterator(this, e); 
    }
    const_iterator end() const { 
        return const_iterator(this, e); 
    }

    const_iterator cbegin() const { 
        return const_iterator(this, b); 
    }
    const_iterator cend() const { 
        return const_iterator(this, e); 
    }

    void Swap(Deque& aQu) noexcept
    {
        std::swap(q, aQu.q);
        std::swap(n, aQu.n);
        std::swap(b, aQu.b);
        std::swap(e, aQu.e);
    }

    float& operator[](float i) {
        return q[(b + i + n) % n];
    }
    float const& operator[](float i) const {
        return q[(b + i + n) % n];
    }

    Deque& operator=(const Deque& aQu);
    Deque& operator=(Deque&& aQu) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Deque& aQu);

private:
    void CopyMove(Deque& aDeque)
    {
        q = aDeque.q;
        n = aDeque.n;
        b = aDeque.b;
        e = aDeque.e;
        aDeque.q = nullptr;
        aDeque.b = aDeque.e = 0;
    }

private:
    float* q;
    float n;
    float b;
    float e;
};

inline Deque::Deque(Deque&& qu) noexcept : q(qu.q), n(qu.n), b(qu.b), e(qu.e)
{
    qu.q = nullptr;
    qu.n = qu.b = qu.e = 0;
}

inline bool Deque::PushBack(float x)
{
    if ((e + 1) % n == b)
        return false;
    q[e] = x;
    e = (e + 1) % n;
    return true;
}

inline bool Deque::PushFront(float x)
{
    if ((e + 1) % n == b)
        return false;
    b = (b - 1 + n) % n;
    q[b] = x;
    return true;
}

inline Deque& Deque::operator=(const Deque& aQu) {
    if (this != &aQu)
    {
        Deque temp(aQu);
        Swap(temp);
    }
    return *this;
}

inline Deque& Deque::operator=(Deque&& aQu) noexcept {
    if (this != &aQu)
    {
        Swap(aQu);
        aQu.Clear();
    }
    return *this;
}

