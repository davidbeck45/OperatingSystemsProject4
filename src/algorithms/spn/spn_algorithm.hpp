#ifndef SPN_ALGORITHM_HPP
#define SPN_ALGORITHM_HPP

#include <memory>
#include "algorithms/scheduling_algorithm.hpp"
#include "utilities/stable_priority_queue/stable_priority_queue.hpp"

/*
    SPNScheduler:
        A representation of a scheduling queue that uses shortest process next (SPN) logic.
        
        This is a derived class from the base scheduling algorithm class.

        You are free to add any member functions or member variables that you
        feel are helpful for implementing the algorithm.
*/

class SPNScheduler : public Scheduler {
public:
    Stable_Priority_Queue<std::shared_ptr<Thread>> ready_queue;

    //==================================================
    //  Member variables
    //==================================================


    //==================================================
    //  Member functions
    //==================================================
 

    SPNScheduler(int slice = -1);

    std::shared_ptr<SchedulingDecision> get_next_thread();

    void add_to_ready_queue(std::shared_ptr<Thread> thread);

    size_t size() const;

private:
    


};

#endif
