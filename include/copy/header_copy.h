#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H

#include "process_scheduling.h"

void finalize_stats(SCHEDULER_STATS* stats);
PROCESS* fifo_process_selector(PROCESS_LIST* pl);
PROCESS* rr_process_selector(PROCESS_LIST* pl);
PROCESS* sjf_process_selector(PROCESS_LIST* pl);
PROCESS* priority_process_selector(PROCESS_LIST* pl);
PROCESS* lifo_process_selector(PROCESS_LIST* pl);
PROCESS* stcf_process_selector(PROCESS_LIST* pl);

#endif //STUDENT_CODE_H
