#ifndef SNIPPERS_HPP
#define SNIPPERS_HPP

#include <optional>
#include <vector>
#include <algorithm>

// return the smallest number contained within the vector
template <typename T>
std::optional<T> min(std::vector<T> values)
{

    std::optional<T> cur_min();

    for (auto &v : values)
    {
        if (cur_min.has_value() && v < cur_min.get())
        {
            cur_min = v;
        }
    }
    return min;
}

template <class T>
class SortedVector
{
public:
    void insert(T value)
    {
        if (this->values.empty())
        {
            values.emplace_back(value);
        }
        else
        {
            binary_insert(this->values.begin(), this->values.end(), value);
        }
    }

    bool contains(T value)
    {
        if (this->values.empty())
        {
            return false;
        }
        else
        {
            return binary_search(this->values.begin(), this->values.end(), value).has_value();
        }
    }

private:
    template <typename ForwardIterator>
    std::optional<ForwardIterator> binary_search(ForwardIterator start, ForwardIterator end, T value)
    {

        ForwardIterator mid = start + (end - start) / 2;

        // array contains single element which is not the value
        if (start == end - 1 && value != *mid)
        {
            return {};
        }
        // mid elem is value
        else if (value == *mid)
        {
            return mid;
        }
        // search left part
        else if (value < *mid)
        {
            return binary_search(start, mid, value);
        }
        // search right part
        else
        {
            return binary_search(mid, end, value);
        }
    }

    template <typename ForwardIterator>
    void binary_insert(ForwardIterator start, ForwardIterator end, T value)
    {
        ForwardIterator mid = start + (end - start) / 2;

        // sequence contains more than 1 elem and value is smaller than mid
        if (start != end-1 && value < *mid)
        {
            binary_insert(start, mid, value);
        }
        // sequence contains more than 1 elem and value is greater than mid
        else if (start != end-1 && value > *mid)
        {
            binary_insert(mid, end, value);
        }
        // sequence contains 1 element and value is smaller
        else if (start == end - 1 && value < *start)
        {
            this->values.insert(start, value);
        }
        // sequence contains 1 element and value is greater
        else
        {
            this->values.insert(start + 1, value);
        }
    }

    std::vector<T> values;
};

#endif // SNIPPETS_HPP