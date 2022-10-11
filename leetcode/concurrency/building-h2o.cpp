// https://leetcode.com/problems/building-h2o/
// medium, concurrency

#include <mutex>
#include <functional>

using namespace std;

class H2O {
    mutex m;
    condition_variable cv;
    int h = 0;
    int o = 0;
public:
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock lk(m);
        cv.wait(lk, [this](){ 
            if(h == 2 && o == 0) return false;
            return true;
        });

        // one h and one o already present         
        if(h == 1 && o == 1) {
            h = 0; 
            o = 0;
        } else {
            h++;
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        lk.unlock();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock lk(m);
        cv.wait(lk, [this](){ 
            if(h < 2 && o == 1) return false;
            return true;
        });
        
        if(h == 2 && o == 0) {
            h = 0;
            o = 0;
        } else {
            o++;
        }
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        lk.unlock();
        cv.notify_one();

    }
};