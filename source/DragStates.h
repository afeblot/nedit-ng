
#ifndef DRAG_STATES_H_
#define DRAG_STATES_H_

enum DragStates {
	NOT_CLICKED, 
	PRIMARY_CLICKED, 
	SECONDARY_CLICKED,
	CLICKED_IN_SELECTION,  
	PRIMARY_DRAG, 
	PRIMARY_RECT_DRAG, 
	SECONDARY_DRAG,
	SECONDARY_RECT_DRAG, 
	PRIMARY_BLOCK_DRAG, 
	DRAG_CANCELED, 
	MOUSE_PAN
};

#endif
