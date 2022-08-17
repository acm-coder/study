

#include <atomic>
#include <mutex>

class Singleton {
private:
    Singleton();
    Singleton(const Singleton& other);
    
public: 
    static Singleton* getInstance();

private:
    static Singleton* m_instance;

    static std::atomic<Singleton*> m_ainstance;
    static std::mutex Singleton::m_mutex;
};

Singleton* Singleton::m_instance = nullptr;


#ifdef SingleThread
// 非线程安全版本
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) m_instance = new Singleton();
    return m_instance;
}
#else

#ifdef MultiThreadIgnoreCost
Singleton* Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) m_instance = new Singleton();
    return m_instance;
}

#else
#ifdef MulitThreadDoubleCheckIgnreoReorderProblem
// 双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        Lock lock;
        if (m_instance == nullptr) m_instance = new Singleton();
    }
    return m_instance;
}
#else


std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_ainstance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_ainstance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_relaxed);
            m_ainstance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
#endif
#endif
#endif
