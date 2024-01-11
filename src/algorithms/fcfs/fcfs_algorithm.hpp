#ifndef FCFS_ALGORITHM_HPP
#define FCFS_ALGORITHM_HPP

#include <memory>
#include <vector>
#include "algorithms/scheduling_algorithm.hpp"
#include "types/scheduling_decision/scheduling_decision.hpp"

/*
    FCFSScheduler:
        A representation of a scheduling queue that uses first-come, first-served logic.
        
        This is a derived class from the base scheduling algorithm class.

        You are free to add any member functions or member variables that you
        feel are helpful for implementing the algorithm.
*/

class FCFSScheduler : public Scheduler {
public:

    //==================================================
    //  Member variables
    //==================================================
    

    // TODO: Add any member variables you may need.

    //==================================================
    //  Member functions
    //==================================================

    FCFSScheduler(int slice = -1);

    std::shared_ptr<SchedulingDecision> get_next_thread();

    void add_to_ready_queue(std::shared_ptr<Thread> thread);

    size_t size() const;

private:
    std::deque<std::shared_ptr<Thread>> ready_queue; // A deque of threads in the ready queue.
    int mCurrentTime = 0; // The current time of the scheduler.
};

#endif
