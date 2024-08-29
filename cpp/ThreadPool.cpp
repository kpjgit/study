#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>
#include <chrono>

namespace ThreadPool {
class ThreadPool {
    private:
    size_t num_threads_;
  
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> jobs_;
        
    std::condition_variable cv_;
    std::mutex m_;

    bool stop_all;

    void WorkerThread();

    public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    void EnqueueJob(std::function<void()> job);
};


ThreadPool::ThreadPool(size_t num_threads) : num_threads_(num_threads), stop_all(false) {
    workers_.reserve(num_threads_);
    for(size_t i = 0; i < num_threads; i++) {
        workers_.emplace_back([this]() { this->WorkerThread(); });
    }
}

void ThreadPool::WorkerThread() {
    std::unique_lock<std::mutex> lock(m_);
    cv_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
    if(stop_all && this->jobs_.empty()) {
        return;
    }

    std::function<void()> job = std::move(jobs_.front());
    jobs_.pop();
    lock.unlock();

    job();
}

ThreadPool::~ThreadPool() {
    stop_all = true;
    cv_.notify_all();

    for (auto& t : workers_) {
        t.join();
    }
}

void ThreadPool::EnqueueJob(std::function<void()> job) {
    if (stop_all){
    throw std::runtime_error("ThreadPool 사용 중지됨");
    }

    std::lock_guard<std::mutex> lock(m_);
    jobs_.push(std::move(job));
    
    cv_.notify_one();
}

}









int main() {


    return 0;
}