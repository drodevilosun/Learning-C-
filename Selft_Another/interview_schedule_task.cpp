#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <stdint.h>

class Scheduler {
public:
    using Callback = std::function<void()>;

    void UpdateTime(int64_t microseconds) {
        current_time_ = microseconds;

        // Check and execute scheduled tasks
        while (!schedule_.empty()) {
            const auto& task = schedule_.top();
            if (task.time <= current_time_) {
                task.callback();
                schedule_.pop();
            } else {
                break;
            }
        }
    }

    void Schedule(int64_t start, Callback callback) {
        schedule_.push({ start, start, callback });
    }

    void Schedule(int64_t start, int64_t interval, int64_t end, Callback callback) {
        for (int64_t time = start; time <= end; time += interval) {
            Schedule(time, callback);
        }
    }

private:
    struct ScheduledTask {
        int64_t time;       // Absolute time when the task should be executed
        int64_t interval;   // For recurring tasks, the interval between executions
        Callback callback;  // The callback function to execute

        // Operator for comparison based on time (earlier tasks first)
        bool operator>(const ScheduledTask& other) const {
            return time > other.time;
        }
    };

    int64_t current_time_ = 0;
    std::priority_queue<ScheduledTask, std::vector<ScheduledTask>, std::greater<ScheduledTask>> schedule_;
};

int main() {
    Scheduler scheduler;

    // Schedule tasks
    scheduler.Schedule(20, 20, 200, []() { std::cout << "f()" << std::endl; });
    scheduler.Schedule(50, []() { std::cout << "g()" << std::endl; });

    // Update time and execute tasks
    scheduler.UpdateTime(10);
    scheduler.UpdateTime(30);
    scheduler.UpdateTime(100);

    return 0;
}
