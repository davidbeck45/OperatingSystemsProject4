#ifndef MFLQ_ALGORITHM_HPP
#define MFLQ_ALGORITHM_HPP

#include <map>
#include <memory>
#include "algorithms/scheduling_algorithm.hpp"
#include "utilities/stable_priority_queue/stable_priority_queue.hpp"

/*
    MFLQScheduler:
        A representation of a multi-level feedback queue scheduling algorithm.

        You are free to add any member functions or member variables that you
        feel are helpful for implementing the algorithm.
*/

using MLFQQueue = Stable_Priority_Queue<std::shared_ptr<Thread>>;

class MFLQScheduler : public Scheduler {
public:
    
    //==================================================
    //  Member variables
    //==================================================

    // TODO: Add any member variables you may need.

    //==================================================
    //  Member functions
    //==================================================

    MFLQScheduler(int slice = -1);

    std::shared_ptr<SchedulingDecision> get_next_thread() override;

    void add_to_ready_queue(std::shared_ptr<Thread> thread) override;

    size_t size() const override;

private:

    MLFQQueue mlfq_queue[10];
    // std::vector<std::priority_queue<std::shared_ptr<Thread>, std::deque<std::shared_ptr<Thread>>, EventComparator>> mlfq_queue{10};
};

#endif
