#include<stdio.h>
#include"state_machine.h"

int main()
{

	//Implement state buffer
	stateBuffer state_buffer = {
		.current_state = suspend
	};

	printf("current state %d\n",state_buffer.current_state);

	state_buffer.current_state = state_handler(&state_buffer,event_1);

	printf("current state %d\n",state_buffer.current_state);

	state_buffer.current_state = state_handler(&state_buffer,event_2);

	printf("current state %d\n",state_buffer.current_state);

	state_buffer.current_state = state_handler(&state_buffer,event_3);

	printf("current state %d\n",state_buffer.current_state);
	printf("Size of buffer %ld\n", sizeof(state_buffer));

	return 1;
}

//Function to handle state transitions
e_state state_handler(stateBuffer *buffer, e_event event)
{
	switch(buffer->current_state) {
		case suspend:
			if(event == event_1)
			{
				buffer->current_state = waiting;
				return waiting;
			}
		       break;	
		case waiting:
			if(event == event_2)
			{
				buffer->current_state = suspend;
				return suspend;
			}
			else if(event == event_3)
			{
				buffer->current_state = resume;
				return resume;
			}
		       break;	
		case resume:
			if(event == event_4)
			{
				buffer->current_state = suspend;
				return suspend;
			}
		       break;	       
	}
	// if no valid transitions stay in current state;
	return buffer->current_state;
}


