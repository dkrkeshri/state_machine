
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

#define SIZE_MAX 100

//define a structure for state buffer
typedef struct {

	e_state current_state;
}StateBuffer;

//define a structure for represent a process
typedef struct {
	
	int process_id;
	e_event event_type;
}event;


e_state state_handler(event *events, StateBuffer *State_Buffer);
