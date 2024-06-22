#include<stdio.h>
#include"state_machine.h"
#include <unistd.h>


//Implament a function for round robin scheduler
void round_robin_scheduler(Process *Processes, event *events, int processes_num, int events_num, int core)
{
	int event_index = 0;
	while(event_index < events_num)
	{
		int flag=0;
		for(int i=0; i<processes_num; i++)
		{
			Process *process = &Processes[i];
			if (process->core_id == core) {
				// Handle the event for the current process
				event *Event = &events[event_index];

				// Check if the event is for the current process
				if(Event->process_id == process->process_id)
				{
					printf("Event for Process: %d on core: %d\n",Event->process_id, Processes[i].core_id);			     
					printf("Current state :%d\n",process->current_state);
					e_state new_state = state_handler(Event, process);
					printf("New state :%d\n\n",process->current_state);
					sleep(1);
					event_index++;
					flag =1;
				}
				// If the event was handled, break out of the loop to process the next event
				if (flag) 
					break;
			}
		}
		// If no process on the current core is found for the event, move to the next event
		if (!flag) 
			event_index++;
	}
}

//Implemented a function to handle event for every state
e_state state_handler(event *events, Process *Processes)
{
	e_state next_state = Processes->current_state;
	switch(next_state) {
		case suspend:
			if(events->event_type == event_1)
				next_state = waiting;
		       break;	
		case waiting:
			if(events->event_type == event_2)
				next_state = suspend;
			else if(events->event_type == event_3)
				next_state = resume;
		       break;	
		case resume:
			if(events->event_type == event_4)
				 next_state = suspend;
		       break;	       
	}
	
	//store into buffer
		return Processes->current_state = next_state;
}

int main()
{

	//Implement state buffer for each process
	Process Processes[] = {
		{ .process_id = 1,
		  .core_id = 0, 
		  .current_state = suspend },
		{ .process_id = 3,
		  .core_id = 0,
		  .current_state = resume },
		{ .process_id = 2,
		  .core_id = 1,
		  .current_state = suspend },
		{ .process_id = 4,
		  .core_id = 1,
		  .current_state = suspend }
	};

	//Implament event for process
	event events[] = { {
		.process_id = 1,
		.event_type = event_1},  //Event for process 1 and current state
	      {
	      	.process_id = 2,
		.event_type = event_2},  //Event for process 2 and current stat
	      {
	      	.process_id = 3,
		.event_type = event_3}, //Event for process 3 and current stat
	      {
	      	.process_id = 4,
		.event_type = event_4},  //Event for process 4 and current stat
	      {
	      	.process_id = 1,
		.event_type = event_1},  //Event for process 1 and current stat
	      {
	      	.process_id = 2,
		.event_type = event_2},  //Event for process 2 and current stat
	      {
	      	.process_id = 3,
		.event_type = event_3}, //Event for process 3 and current stat
	      {
	      	.process_id = 4,
		.event_type = event_4}  //Event for process 4 and current stat
	};

	int processes_num = sizeof(Processes)/sizeof(Processes[0]);
	int events_num = sizeof(events)/sizeof(events[0]);

	//Call round robine scheduler for core 0
		
	printf("1st scheduler for core 0\n");	
	round_robin_scheduler(Processes,events,processes_num,events_num,0);

	//Call round robine scheduler for core 1
	printf("2st scheduler for core 1\n");	
	round_robin_scheduler(Processes,events,processes_num,events_num,1);
	return 0;
}

