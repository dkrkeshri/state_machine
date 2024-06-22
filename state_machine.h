
#include<stdio.h>

typedef enum state{
	suspend,
	waiting,
	resume
}e_state;


typedef enum event{
	event_1,
	event_2,
	event_3,
	event_4
}e_event;

//define a structure for represent process
typedef struct {

	int process_id;
	int core_id;
	e_state current_state;
}Process;

//define a structure for represent a process
typedef struct {
	
	int process_id;
	e_event event_type;
}event;


e_state state_handler(event *events, Process *Processes);
void round_robin_scheduler(Process *Processes, event *events, int processes_num, int events_num, int core);
void stop();
