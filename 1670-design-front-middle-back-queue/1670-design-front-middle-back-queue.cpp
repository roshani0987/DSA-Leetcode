class FrontMiddleBackQueue {
    deque<int> left, right;

public:
    FrontMiddleBackQueue() {}

    void balance() {
        while (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }

        while (right.size() > left.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (left.empty()) return -1;

        int val = left.front();
        left.pop_front();
        balance();
        return val;
    }

    int popMiddle() {
        if (left.empty()) return -1;

        int val = left.back();
        left.pop_back();
        balance();
        return val;
    }

    int popBack() {
        if (left.empty()) return -1;

        int val;

        if (!right.empty()) {
            val = right.back();
            right.pop_back();
        } else {
            val = left.back();
            left.pop_back();
        }

        balance();
        return val;
    }
};