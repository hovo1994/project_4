#include <cxxtest/TestSuite.h>

#include "heap_priority_queue.h"

template class HeapPriorityQueue<int>;

class HeapTests : public CxxTest::TestSuite
{
public:
   void testAdd( void )
   {
     HeapPriorityQueue<int> q;
     q.add(1);
     // TS_ASSERT();
   }  
};
