#include "algorithms/mlfq/mlfq_algorithm.hpp"

#include <cassert>
#include <stdexcept>
#include <cmath>
#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"



/*
    Here is where you should define the logic for the MLFQ algorithm.
*/
#include <string>



enum class Priority {
    SYSTEM,
    INTERACTIVE,
    NORMAL,
    BATCH
};

std::string priorityToString(Priority priority) {
    switch (priority) {
        case Priority::SYSTEM:
            return "SYSTEM";
        case Priority::INTERACTIVE:
            return "INTERACTIVE";
        case Priority::NORMAL:
            return "NORMAL";
        case Priority::BATCH:
            return "BATCH";
        default:
            throw std::invalid_argument("Invalid priority value");
    }
}

MFLQScheduler::MFLQScheduler(int slice) {
    if (slice != -1) {
        throw std::invalid_argument("MLFQ does NOT take a customizable time slice");
    }
}

std::shared_ptr<SchedulingDecision> MFLQScheduler::get_next_thread() {
    auto next_decision = std::make_shared<SchedulingDecision>();
    for (int i = 0; i < 10; ++i) {
        if (!mlfq_queue[i].empty()) {
            next_decision->thread = mlfq_queue[i].top();
            mlfq_queue[i].pop();
            std::string priorityString = PROCESS_PRIORITY_MAP[static_cast<int>(next_decision->thread->priority)];
            
            next_decision->explanation = "Selected from queue " + std::to_string(i)
                + " (priority = " + priorityString
                + ", runtime = " + std::to_string(next_decision->thread->queue_total_time)
                + "). Will run for at most " + std::to_string(static_cast<int>(std::floor(std::pow(2, i)))) + " ticks.";
            next_decision->time_slice = std::pow(2, i);
            this->time_slice = next_decision->time_slice;
            next_decision->thread->queue_total_time += next_decision->thread->get_next_burst(CPU)->length;
            return next_decision;
        }
    }
    next_decision->explanation = "No threads available";
    return next_decision;
}


void MFLQScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    if (thread->queue_total_time >= std::pow(2, thread->queue_num) && thread->queue_num != 9) {
        thread->queue_num += 1;
        thread->queue_total_time = 0;
    }
    mlfq_queue[thread->queue_num].push(thread->priority, thread);
}

size_t MFLQScheduler::size() const {
    size_t total_size = 0;
    for (int i = 0; i < 10; ++i) {
        total_size += mlfq_queue[i].size();
    }
    return total_size;




}
