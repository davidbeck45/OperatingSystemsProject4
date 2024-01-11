#include "algorithms/rr/rr_algorithm.hpp"
#include <cassert>
#include <stdexcept>
#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

RRScheduler::RRScheduler(int slice){
    this->time_slice = slice;
    if (slice <= 0) {
    throw("RR must have a timeslice of at least 1");
    }
    
}

std::shared_ptr<SchedulingDecision> RRScheduler::get_next_thread() {
    std::shared_ptr<SchedulingDecision> next_thread(new SchedulingDecision);

    if (((int)size()) == 0) {
        next_thread->explanation = "No threads available for scheduling.";
        //return nullptr;
    }else{
        next_thread->explanation = "Selected from " + std::to_string((int)size()) + " threads. Will run for at most " + std::to_string(this->time_slice) + " ticks.";
        next_thread->thread = mReadyQueue.front();
        next_thread->time_slice;
        mReadyQueue.pop();
    }
    return next_thread;


}

void RRScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
   

   
    mReadyQueue.push(thread);
}

size_t RRScheduler::size() const {
    return (size_t)mReadyQueue.size();
}
