
Various Project Specifications:
  Simulation Information:
    The simulation is over a computer with a single CPU and an infinite number of I/O devices.
    Processes consist of one or more kernel-level threads (KLTs).
    Processes have five states: NEW, READY, RUNNING, BLOCKED, EXIT.
    Scheduling tasks incur non-zero OS overhead.
    Threads, processes, and dispatch overhead are specified via the input file.
    Each thread has CPU and I/O bursts of varying lengths.
    Processes have associated priorities.
    Overhead is incurred only when dispatching a thread.
  Scheduling Algorithms:
    FCFS: Tasks are scheduled in the order they are added to the ready queue.
    SPN: Tasks are scheduled based on their next CPU burst length.
    RR: Round-robin scheduling with preemption.
    PRIORITY: Tasks are scheduled based on priority, with defined priority levels.
    MLFQ: Multi-level feedback queues with different priority levels and time slices.
  Required Logging:
    Logging explanations for various scheduling algorithms.
    Performance Metrics
    Number of Threads per Process Priority
    Average Turnaround Time per Process Priority
    Average Response Time per Process Priority
    Total Service Time
    Total I/O Time
    Total Idle Time
    CPU Utilization
    CPU Efficiency
