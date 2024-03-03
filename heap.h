 #ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
    Heap(int m = 2, PComparator c = PComparator()) : m_(m), comp_(c) {}

    ~Heap() = default;

    void push(const T& item) {
        items_.push_back(item);
        size_t index = items_.size() - 1;
        while (index > 0) {
            size_t parent = (index - 1) / m_;
            if (comp_(items_[index], items_[parent])) {
                std::swap(items_[index], items_[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    T const& top() const {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        return items_[0];
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Heap is empty");
        }
        items_[0] = items_.back();
        items_.pop_back();
        size_t index = 0;
        while (true) {
            size_t child = index * m_ + 1;
            if (child >= items_.size()) break;

            size_t minChild = child;
            for (size_t i = 1; i < m_ && child + i < items_.size(); ++i) {
                if (comp_(items_[child + i], items_[minChild])) {
                    minChild = child + i;
                }
            }

            if (comp_(items_[minChild], items_[index])) {
                std::swap(items_[index], items_[minChild]);
                index = minChild;
            } else {
                break;
            }
        }
    }

    bool empty() const {
        return items_.empty();
    }

    size_t size() const {
        return items_.size();
    }

private:
    std::vector<T> items_;
    size_t m_;
    PComparator comp_;
};

#endif // HEAP_H
