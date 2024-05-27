#include<stdio.h>
#include"state_machine.h"
int main()
{

	process processes[] = {
		{.process_id = 1,
		.event_type =  event_1,
		.Buffer = {
			.count = 1,
			.states = {
				suspend}
		}},
		{.process_id = 2,
		.event_type =  event_2,
		.Buffer = {
			.count = 1,
			.states = {
				suspend},
		}},
		{.process_id = 3,
		.event_type =  event_3,
		.Buffer = {
			.count = 1,
			.states = {
				suspend}
		}},
		{.process_id = 4,
		.event_type =  event_4,
		.Buffer = {
			.count = 1,
			.states = {
				suspend}
		}}
	};

	for(int i=0;i<sizeof(processes)/sizeof(processes[0]);++i)
	{
		printf("Process Id :%d\n",processes[i].process_id);	
		printf("current state :%d\n",processes[i].Buffer.states[processes[i].Buffer.count - 1]);
		e_state new_state = state_handler(&processes[i], processes[i].event_type);
		printf("New state :%d\n",new_state);
		printf("\n");
	}

	return 0;
}

e_state state_handler(process *process, e_event event)
{
	e_state next_state = process->Buffer.states[process->Buffer.count -1];

	switch(next_state) {
		case suspend:
			if(event == event_1)
				next_state = waiting;
		       break;	
		case waiting:
			if(event == event_2)
				next_state = suspend;
			else if(event == event_3)
				next_state = resume;
		       break;	
		case resume:
			if(event == event_4)
				 next_state = suspend;
		       break;	       
	}
	
	if(next_state != process->Buffer.states[process->Buffer.count -1] && process->Buffer.count < SIZE_MAX)
	{
		process->Buffer.states[process->Buffer.count++] = next_state;
	}
		return next_state;
}
