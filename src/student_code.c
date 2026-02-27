//
// Created by Sam Ogden on 8/8/23.
//

#include "student_code.h"
#include "stdio.h"

void mark_start(PROCESS* p, SCHEDULER_STATS* stats, float time_started) {
	stats->num_processes_started += 1;
	stats->sum_of_response_time += time_started - p->entry_time;
}

void mark_end(PROCESS* p, SCHEDULER_STATS* stats, float time_completed) {
	stats->num_processes_completed += 1;
	stats->sum_of_turnaround_times += time_completed - p->entry_time; // 1 - 0
}

void finalize_stats(SCHEDULER_STATS* stats) {
	stats->average_response_time = stats->sum_of_response_time / stats->num_processes_started;
	stats->average_turnaround_time = stats->sum_of_turnaround_times / stats->num_processes_completed;
	//stats->completion_time
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
	stats->num_processes_started = pl->num_processes;

	if(!is_empty(pl)) {
	
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->entry_time < curr_process->entry_time) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->entry_time == curr_process->entry_time) && (pl->processes[i]->id < curr_process->id)) {
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

	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();
	stats->num_processes_started = pl->num_processes;

	if(!is_empty(pl)) {
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->duration < curr_process->duration) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->duration == curr_process->duration) && (pl->processes[i]->last_run < curr_process->last_run)) {
				curr_process = pl->processes[i];
			} else if (pl->processes[i]->entry_time < curr_process->entry_time) {
				curr_process = pl->processes[i];
			}
		}	
		float curr_time = curr_process->entry_time;
		run(curr_process, stats, curr_time);
		return curr_process;
	}
return NULL;
}

PROCESS* sjf_process_selector(PROCESS_LIST* pl) {

	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();
	stats->num_processes_started = pl->num_processes;

	if(!is_empty(pl)) {
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->duration < curr_process->duration) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->duration == curr_process->duration) && (pl->processes[i]->id < curr_process->id)) {
				curr_process = pl->processes[i];
			}
		}	
		float curr_time = curr_process->entry_time;
		run(curr_process, stats, curr_time);
		return curr_process;
	}
	return NULL;

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

		run(curr_process, stats, 0);
		return curr_process;

	}

	return NULL;

}

PROCESS* lifo_process_selector(PROCESS_LIST* pl) {
	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();
	stats->num_processes_started = pl->num_processes;

	if(!is_empty(pl)) {
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->entry_time > curr_process->entry_time) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->entry_time == curr_process->entry_time) && (pl->processes[i]->id > curr_process->id)) {
				curr_process = pl->processes[i];
			}
		}	
		float curr_time = curr_process->entry_time;
		run(curr_process, stats, curr_time);
		return curr_process;
	}
	return NULL;
}

PROCESS* stcf_process_selector(PROCESS_LIST* pl) {
	PROCESS* curr_process =	pl->processes[pl->num_processes-1]; 
	SCHEDULER_STATS* stats = get_empty_stats_block();
	stats->num_processes_started = pl->num_processes;

	if(!is_empty(pl)) {
		for(int i=0; i<pl->num_processes; i++) {
			if(pl->processes[i]->duration < curr_process->duration) {
				curr_process = pl->processes[i];
			} else if ((pl->processes[i]->duration == curr_process->duration) && (pl->processes[i]->entry_time < curr_process->entry_time)) {
				curr_process = pl->processes[i];
			}
		}	
		float curr_time = curr_process->entry_time;
		run(curr_process, stats, curr_time);
		return curr_process;
	}
	return NULL;

}
