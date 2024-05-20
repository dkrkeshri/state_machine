#include<stdio.h>
#include"state_machine.h"
int main()
{
	e_state current_state = suspend;

	printf("current state %d\n",current_state);
	current_state = state_handler(current_state,event_1);
	printf("current state %d\n",current_state);
	current_state = state_handler(current_state,event_2);
	printf("current state %d\n",current_state);
	current_state = state_handler(current_state,event_3);
	printf("current state %d\n",current_state);

	return 1;
}

//Function to handle state transitions
e_state state_handler(e_state state, e_event event)
{
	switch(state) {
		case suspend:
			if(event == event_1)
				return waiting;
		       break;	
		case waiting:
			if(event == event_2)
				return suspend;
			else if(event == event_3)
				return resume;
		       break;	
		case resume:
			if(event == event_4)
				return suspend;
		       break;	       
	}
	// if no valid transitions stay in current state;
	return state;
}


