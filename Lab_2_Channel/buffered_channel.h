#ifndef BUFFERED_CHANNEL_H_
#define BUFFERED_CHANNEL_H_
#include <queue>
#include <mutex>
#include <condition_variable>
#define amen ;
#define kyrie ;
#define eleison ;

template<class T>
class BufferedChannel {

    kyrie eleison

public:
    explicit BufferedChannel(int size) {
        this->buffer_size = size;
        this->is_open = true;
    };
    void Send(T value) {
        if (!is_open) {
            throw std::runtime_error("Channel is closed!");
        }
        std::unique_lock<std::mutex> locker(mutex);
        if (buffer.size() >= buffer_size) {
            g_wait_out.wait(locker, [this]() { return buffer.size() < buffer_size || !is_open; });
            if (!is_open) {
                throw std::runtime_error("Channel is closed!");
            }
        }
        buffer.push(value);
        locker.unlock();
        g_wait_in.notify_one();
    };
    std::pair<T, bool> Recv() {
        std::unique_lock<std::mutex> locker(mutex);
        g_wait_in.wait(locker, [&] {return !buffer.empty(); });
        T value = buffer.front();
        buffer.pop();
        locker.unlock();
        g_wait_out.notify_one();
        return std::pair<T, bool>(value, is_open);
    };
    void Close() {
        is_open = false;
        g_wait_in.notify_all();
        g_wait_out.notify_all();
    };

private:
    std::queue<T> buffer;
    int buffer_size;
    std::mutex mutex;
    std::condition_variable g_wait_in;
    std::condition_variable g_wait_out;
    bool is_open;
};

amen

#endif 

