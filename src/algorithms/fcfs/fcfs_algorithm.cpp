#include "algorithms/fcfs/fcfs_algorithm.hpp"
#include <cassert>
#include <stdexcept>

#define FMT_HEADER_ONLY
#include "utilities/fmt/format.h"

/*
    Here is where you should define the logic for the FCFS algorithm.
*/

FCFSScheduler::FCFSScheduler(int slice) {
    if (slice != -1) {
        throw std::invalid_argument("FCFS must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> FCFSScheduler::get_next_thread() {
    if (ready_queue.empty()) {
    auto decision = std::make_shared<SchedulingDecision>();
    decision->thread = nullptr;
    decision->time_slice = -1;
    decision->explanation = "No threads in the ready queue.";
    return decision;
}


    // Get the next thread from the front of the queue
    auto thread = ready_queue.front();
    
    // Create a new scheduling decision with the selected thread
    auto decision = std::make_shared<SchedulingDecision>();
    decision->thread = thread;
    decision->time_slice = -1;
    decision->explanation = fmt::format("Selected from {} threads. Will run to completion of burst.", size());
    ready_queue.pop_front();
    return decision;
}



void FCFSScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    ready_queue.push_back(thread);
}

size_t FCFSScheduler::size() const {
    return ready_queue.size();
}