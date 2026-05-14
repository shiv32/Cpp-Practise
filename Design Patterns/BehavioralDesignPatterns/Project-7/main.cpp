#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class VIterator
{
    using constVec = const std::vector<T>;

    constVec &data_{};
    size_t idx_{};

public:
    VIterator(constVec &data);
    bool hasNext();
    T next();
};

template <typename T>
VIterator<T>::VIterator(constVec &data): data_(data)
{

}

template <typename T>
bool VIterator<T>::hasNext()
{
    return idx_ < data_.size();
}

template <typename T>
T VIterator<T>::next()
{
    return data_[idx_++];
}

int main()
{
    std::vector<int> data {10, 40, 70};

    /*
        VIterator<int> it(data);

        while (it.hasNext())
        {
        std::clog<<it.next()<<std::endl;
        }
    */
    
    //smart ptr
    auto it = std::make_unique<VIterator<int>>(data);

    while (it->hasNext())
    {
       std::clog<<it->next()<<std::endl;
    }
    
    return 0;
}