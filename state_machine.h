
#include<stdio.h>

//state Define
typedef enum state{
	suspend,
	waiting,
	resume
}e_state;

//Event Define
typedef enum event{
	event_1,
	event_2,
	event_3,
	event_4
}e_event;

//Buffer define for capture the state changes

typedef struct {
	e_state current_state; 
}stateBuffer;

e_state state_handler(stateBuffer * buffer, e_event event);
