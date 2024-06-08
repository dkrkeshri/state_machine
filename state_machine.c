#include<stdio.h>
#include"state_machine.h"
int main()
{

	//Implement state buffer for each process
	StateBuffer State_Buffer[] = {
		{ .current_state = suspend },
		{ .current_state = resume },
		{ .current_state = suspend },
		{ .current_state = suspend }
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
		.event_type = event_4}  //Event for process 4 and current stat
	};

	//Implement state handler for each process with there event
	for(int i=0;i<sizeof(events)/sizeof(events[0]);++i)
	{
		printf("Process Id for Event :%d\n",events[i].process_id);	
		printf("Current state :%d\n",State_Buffer[i].current_state);
		e_state new_state = state_handler(&events[i], &State_Buffer[i]);
		printf("New state :%d\n",State_Buffer[i].current_state);
		printf("\n");
	}

	return 0;
}

//Implemented a function to handle event for every state
e_state state_handler(event *events, StateBuffer *State_Buffer)
{
	e_state next_state = State_Buffer->current_state;
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
		return State_Buffer->current_state = next_state;
}
