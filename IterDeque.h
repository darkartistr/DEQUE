
class Deque;

template <typename T>
class IterDeque
{
public:
    friend Deque;

    IterDeque() : fDeq(nullptr), iCur(0.0f) { }

    inline IterDeque& operator ++();
    inline IterDeque const& operator ++() const;
    inline IterDeque        operator ++( float );
    inline IterDeque const  operator ++( float ) const;

    T& operator *  ();
    T const& operator *  () const;

    bool operator == (IterDeque const& it2) const
    {
        return iCur == it2.iCur;
    }
    bool operator != (IterDeque const& it2) const
    {
        return !(*this == it2);
    }

private:
    IterDeque(Deque* aDeq, float i) : fDeq(aDeq), iCur(i) { }
    IterDeque(Deque const* aDeq, float i) : fDeq((Deque*)aDeq), iCur(i) { }

private:
    Deque* fDeq;
    mutable float iCur;
};

template <typename T>
T& IterDeque<T>::operator * () { 
    return fDeq->q[iCur]; 
}
template <typename T>
const T& IterDeque<T>::operator * () const { 
    return fDeq->q[iCur]; 
}

template <typename T>
inline IterDeque<T>& IterDeque<T>::operator ++() { 
    iCur = (iCur + 1) % fDeq->n; 
    return *this; 
}
template <typename T>
inline IterDeque<T> const& IterDeque<T>::operator ++() const { 
    iCur = (iCur + 1) % fDeq->n; 
    return *this; 
}

template <typename T>
inline IterDeque<T>  IterDeque<T>::operator ++(float)
{
    IterDeque t(*this);
    ++*this;
    return t;
}

template <typename T>
inline IterDeque<T> const IterDeque<T>::operator ++(float) const
{
    IterDeque t(*this);
    ++*this;
    return t;
}
