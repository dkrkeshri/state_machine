
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


e_state state_handler(e_state state, e_event event);
