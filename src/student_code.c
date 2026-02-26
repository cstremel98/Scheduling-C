//
// Created by Sam Ogden on 8/8/23.
//

#include "student_code.h"
#include "stdio.h"

void mark_start(PROCESS* p, SCHEDULER_STATS* stats, float time_started) {
  // todo
}

void mark_end(PROCESS* p, SCHEDULER_STATS* stats, float time_completed) {
  // todo
}

void finalize_stats(SCHEDULER_STATS* stats) {
  // todo
}

int compare_noop(PROCESS p1, PROCESS p2) {
  return 0;
}

int compare_priority(PROCESS p1, PROCESS p2) {
  // todo
}

int compare_arrival_time(PROCESS p1, PROCESS p2) {
  // todo
}

int compare_arrival_time_invert(PROCESS p1, PROCESS p2) {
  // todo
}

int compare_job_duration(PROCESS p1, PROCESS p2) {
  // todo
}

int compare_time_remaining(PROCESS p1, PROCESS p2) {
  // todo
}

int compare_last_run(PROCESS p1, PROCESS p2) {
  // todo
}

PROCESS* fifo_process_selector(PROCESS_LIST* pl) {
	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();

	if(!is_empty(pl)) {
	
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->priority < curr_process->priority) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->priority == curr_process->priority) && (pl->processes[i]->id < curr_process->id)) {
				curr_process = pl->processes[i];
			}
		}	
		
		float curr_time = 0;

		run(curr_process, stats, curr_time);
		
		return curr_process;
	
	}

	return NULL;
}

PROCESS* rr_process_selector(PROCESS_LIST* pl) {
  // todo
}

PROCESS* sjf_process_selector(PROCESS_LIST* pl) {
  // todo
}

PROCESS* priority_process_selector(PROCESS_LIST* pl) {
	
	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();

	if(!is_empty(pl)) {
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->priority < curr_process->priority) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->priority == curr_process->priority) && (pl->processes[i]->id < curr_process->id)) {
				curr_process = pl->processes[i];
			}
		}	
		
		float curr_time = 0;

		run(curr_process, stats, curr_time);
		
		return curr_process;
	}

	return NULL;

}

PROCESS* lifo_process_selector(PROCESS_LIST* pl) {
  // todo
}

PROCESS* stcf_process_selector(PROCESS_LIST* pl) {
  // todo
}
