#include <thread>
#include <mutex>

using namespace std;
template<typename T>
class TSQueue {

private:
    queue<T> data_queue;
    mutable mutex mut;
    condition_variable data_cond;

public:
    TSQueue() {}
    void push(T new_value) {
        lock_guard<mutex> lock(mut);
        data_queue.push(move(data));
        data_cond.notify_one();
    }    

    void wait_and_pop(T& value) {
        unique_lock<mutex> lock(mut);
        data_cond.wait(lock, [this]{return !data_queue.empty();} );
        value = move(data_queue.front());
        data_queue.pop();
    }

    shared_ptr<T> wait_and_pop() {
        unique_lock<mutex> lock(mut);
        data_cond.wait(lock, [this]{return !data_queue.empty();});
        shared_ptr<T> res(
            make_shared<T>(move(data_queue.front())));
        data_queue.pop();
        return res;
    }

    bool try_pop(T& value) {
        lock_guard<mutex> lock(mut);
        if (data_queue.empty())
            return false;
        value = move(data_queue.front())
        data_queue.pop();
        return true;
    }

    shared_ptr<T> try_pop() {
        lock_guard<mutex> lock(mut);
        if (data_queue.empty()) 
            return shared_ptr<T>();
        shared_ptr<T> res(
            make_shared<T>(move(data_queue.front())));
        data_queue.pop();
        return res;
    }

    bool empty() const {
        lock_guard<mutex> lock(mut);
        return data_queue.empty();
    }
};