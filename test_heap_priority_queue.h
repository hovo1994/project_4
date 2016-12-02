#include <cxxtest/TestSuite.h>
#include <iostream>
#include "heap_priority_queue.h"

template class HeapPriorityQueue<int>;

class HeapTests : public CxxTest::TestSuite
{
public:
   void testAddRemoveEmpty( void )
   {
     HeapPriorityQueue<int> q;
     q.add(10);
     TS_ASSERT_EQUALS(q.peek(), 10);
     q.add(9);
     TS_ASSERT_EQUALS(q.peek(), 10);
     q.add(15);
     q.add(14);
     TS_ASSERT_EQUALS(q.peek(), 15);
     q.add(100);
     TS_ASSERT_EQUALS(q.peek(), 100);
     q.add(42);
     q.add(99);
     TS_ASSERT_EQUALS(q.peek(), 100);
     // // q.display("Test After Inserting");
     q.remove();
     // // q.display("Test After First Remove");
     // TS_ASSERT_EQUALS(q.peek(), 99);
     q.remove();
     // // q.display("Test After Second Remove");
     // TS_ASSERT_EQUALS(q.peek(), 42);
     q.remove();
     // // q.display("Test After Third Remove");
     // TS_ASSERT_EQUALS(q.peek(), 15);
     q.remove();
     q.remove();
     q.remove();
     q.remove();
     q.add(50);
     q.add(80);
     q.add(40);
     q.add(51);
     q.add(0);
     q.remove();
     q.remove();
     // q.display("Test After Last Remove");
     
     
   }

   void testAscDecOrder(void)
   {
    HeapPriorityQueue<int> q;

    int size = 100000;

    for (int i = 0; i < size; ++i)
    {
      q.add(i);
      TS_ASSERT_EQUALS(q.peek(), i);
    }

    for (int i = 0; i < size; ++i)
    {
      q.remove();
    }
    
    TS_ASSERT(q.isEmpty());

   	
   }

   // void testInsertRandom(void)
   // {
   // 	HeapPriorityQueue<int> q;
   // 	int  randoms[12] = { 2, 1000, 3, 17, 50, 20, 400, 50, 10, 32, 23, 45};
   // 	for (int i = 0; i < 12; ++i)
   // 	{
   // 		q.add(randoms[i]);
   // 		if (i == 0 )
   // 		{
   // 			TS_ASSERT(q.peek() == 2);
   // 		}
   // 		else
   // 		{
   // 			TS_ASSERT(q.peek() == 1000);
   // 		}
   // 	}


   //  // q.display();
   //  q.remove();
   //  // q.display();


   // }

};
