#include "algorithms/spn/spn_algorithm.hpp"
#include <cassert>
#include <stdexcept>
#include "utilities/fmt/format.h"
#define FMT_HEADER_ONLY

SPNScheduler::SPNScheduler(int slice) {
    if (slice != -1) {
        throw std::invalid_argument("SPN must have a timeslice of -1");
    }
}

std::shared_ptr<SchedulingDecision> SPNScheduler::get_next_thread() {
    // If the ready queue is empty, return nullptr
    if (ready_queue.empty()) {
        auto decision = std::make_shared<SchedulingDecision>();
        decision->thread = nullptr;
        decision->time_slice = -1;
        decision->explanation = "No threads in the ready queue.";
        return decision;
    }

    // Get the thread with the shortest remaining time
    auto nextThread = ready_queue.top();
    

    // Create a scheduling decision with the chosen thread and set its state to running
    auto decision = std::make_shared<SchedulingDecision>();
    decision->thread = nextThread;
    decision->time_slice = -1;
    
    decision->explanation = fmt::format("Selected from {} threads. Will run to completion of burst.", ready_queue.size());
    ready_queue.pop();

    return decision;
}

void SPNScheduler::add_to_ready_queue(std::shared_ptr<Thread> thread) {
    // Add the thread to the ready queue with its remaining time as the priority
    ready_queue.push(thread->get_next_burst(BurstType::CPU)->length,thread);
}


size_t SPNScheduler::size() const {
    return ready_queue.size();
}
