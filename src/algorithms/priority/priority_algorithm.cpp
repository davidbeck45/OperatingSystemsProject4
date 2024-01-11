#include "algorithms/priority/priority_algorithm.hpp"

#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"


/*
    Here is where you should define the logic for the priority algorithm.
*/

PRIORITYScheduler::PRIORITYScheduler(int slice) {
    if (slice != -1) {
        throw("PRIORITY must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> PRIORITYScheduler::get_next_thread() {
    // TODO: implement me!
    
    auto next_thread = std::make_shared<SchedulingDecision>();
    
    if(!this->size()){
        next_thread -> explanation = "No threads available for scheduling.";
        return next_thread;
    }
    
    next_thread->thread = priority_queue.top();
    priority_queue.pop();
    std::string new_explanation = "[S: " + std::to_string(nums[0]) + " I: " + std::to_string(nums[1])
        + " N: " + std::to_string(nums[2]) + " B: " + std::to_string(nums[3]) + "]";
    
    next_thread->explanation = new_explanation;
    nums[next_thread->thread->priority]--;
    new_explanation += " -> [S: "+ std::to_string(nums[0]) + " I: " + std::to_string(nums[1]) + " N: "
    + std::to_string(nums[2]) + " B: " + std::to_string(nums[3]) + "]. Will run to completion of burst.";
    
    next_thread->explanation = new_explanation;
    return next_thread;
}


void PRIORITYScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    // TODO: implement me!
    priority_queue.push(thread->priority, thread);
    nums[thread->priority]++;
}

size_t PRIORITYScheduler::size() const {
    //TODO: Implement me!!
    return priority_queue.size();
}
