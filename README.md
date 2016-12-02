# project_4

##Files:
 abstract_list.h            -- abstract list to inherit dynamic arrray from
 abstract_priority_queue.h  -- abstract queue to inherit queue from 
 dynamic_array_list.h       -- dynamic array definition
 dynamic_array_list.txx     -- dynamic array implementation
 heap_priority_queue.h      -- priority queue definition
 heap_priority_queue.txx    -- priority queue implementation
 initial.png                -- initial starting image
 propagate.cpp              -- main program
 speed.png                  -- speed image
 test_heap_priority_queue.h -- queue test file


##Usage
./propagate initial.png speed.png output.png 5000
5000 is the timestep

##Known Issues

Currently the output does not match the output of the project. This may be due to an incorrect remove method. After an Item is removed from the queue the reprioritization is not implemented correctly.

