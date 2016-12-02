#include <cmath>
#include <cstdlib>
#include <iostream>

#include "image.h"
#include "heap_priority_queue.h"

// Queue Item Def
class QItem
{
public:
	int _i;// i coord
	int _j;// j coord
	int _p;// priority (derrived from speed)

	QItem(int i=0, int j=0, int p=0): _i(i), _j(j), _p(p){};
};

// relational operators for QItem class
bool operator>(const QItem& lhs, const QItem& rhs)
{
	return lhs._p>rhs._p;
}

bool operator<(const QItem& lhs, const QItem& rhs)
{
	return lhs._p<rhs._p;
}

bool operator>=(const QItem& lhs, const QItem& rhs)
{
	return lhs._p>=rhs._p;
}

bool operator<=(const QItem& lhs, const QItem& rhs)
{
	return lhs._p<=rhs._p;
}

bool operator==(const QItem& lhs, const QItem& rhs)
{
	return lhs._p==rhs._p;
}
//end relational operators for QItem class

static const uint BLACK = 0;
static const uint WHITE = 255*3;

int main(int argc, char *argv[]) {

  if (argc != 5) {	
    std::cout << "Usage: propagate "
              << "initial.png speed.png output.png T\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  HeapPriorityQueue<QItem> myQ;

  try {
    Image<Pixel> input = readFromFile(argv[1]);

    Image<Pixel> speed = readFromFile(argv[2]);

    Image<Pixel> output = input;

    uint t = std::stoi(argv[4]);



    // find border values of the black dot in the initial image.
    for (uint i = 0; i < input.width(); ++i)
    {	
      for (uint j = 0; j < input.height(); ++j) 
      {
      	

        // a border value is any black pixel that is adjacent to at least one white pixel. 
        if((uint32_t)input(i,j).red + (uint32_t)input(i,j).green + (uint32_t)input(i,j).blue == BLACK)
        {
        	// find black px and surrounded by at least 1 white pixel
        	if (   ((uint32_t)input(i,j-1).red + (uint32_t)input(i,j-1).green + (uint32_t)input(i,j-1).blue == WHITE) // top pixel
        	    || ((uint32_t)input(i,j+1).red + (uint32_t)input(i,j+1).green + (uint32_t)input(i,j+1).blue == WHITE) // bottom pixel
        	    || ((uint32_t)input(i+1,j).red + (uint32_t)input(i+1,j).green + (uint32_t)input(i+1,j).blue == WHITE) // right pixel
        	    || ((uint32_t)input(i-1,j).red + (uint32_t)input(i-1,j).green + (uint32_t)input(i-1,j).blue == WHITE))// left pixel 
        	{
        		// store those in my queue with the 
        		int priority = (uint32_t)speed(i,j).red + (uint32_t)speed(i,j).green + (uint32_t)speed(i,j).blue;
        		priority=priority/3;
        		QItem pixToAdd(i,j,priority);
        		myQ.add(pixToAdd);
        	}

        }

      }
    }

    for (int i = 0; i < t; ++i)
    {
    	
    	QItem localCopy = myQ.peek();
    	myQ.remove();

    	int _i = localCopy._i;
    	int _j = localCopy._j;

    	output(_i, _j).red = 0;
    	output(_i, _j).green = 0;
    	output(_i, _j).blue = 0;
    	// determine priority from speed image. 
    	int p1 = ((uint32_t)speed(_i-1, _j-1).red + (uint32_t)speed(_i-1, _j-1).green + (uint32_t)speed(_j-1, _j-1).blue)/3;
    	int p2 = ((uint32_t)speed(_i, _j-1).red + (uint32_t)speed(_i, _j-1).green + (uint32_t)speed(_j, _j-1).blue)/3;
    	int p3 = ((uint32_t)speed(_i+1, _j-1).red + (uint32_t)speed(_i+1, _j-1).green + (uint32_t)speed(_j+1, _j-1).blue)/3;
    	int p4 = ((uint32_t)speed(_i-1, _j).red + (uint32_t)speed(_i-1, _j).green + (uint32_t)speed(_j-1, _j).blue)/3;
    	int p5 = ((uint32_t)speed(_i+1, _j).red + (uint32_t)speed(_i+1, _j).green + (uint32_t)speed(_j+1, _j).blue)/3;
    	int p6 = ((uint32_t)speed(_i-1, _j+1).red + (uint32_t)speed(_i-1, _j+1).green + (uint32_t)speed(_j-1, _j+1).blue)/3;
    	int p7 = ((uint32_t)speed(_i, _j+1).red + (uint32_t)speed(_i, _j+1).green + (uint32_t)speed(_j, _j+1).blue)/3;
    	int p8 = ((uint32_t)speed(_i+1, _j+1).red + (uint32_t)speed(_i+1, _j+1).green + (uint32_t)speed(_j+1, _j+1).blue)/3;


    	// create queue items
		QItem item1(_i-1, _j-1, p1);
		QItem item2(_i, _j-1, p2);
		QItem item3(_i+1, _j-1, p3);
		QItem item4(_i-1, _j, p4);
		QItem item5(_i+1, _j, p5);
		QItem item6(_i-1, _j+1, p6);
		QItem item7(_i, _j+1, p7);
		QItem item8(_i+1, _j+1, p8);
		// add items to queue
		myQ.add(item1);
		myQ.add(item2);
		myQ.add(item3);
		myQ.add(item4);
		myQ.add(item5);
		myQ.add(item6);
		myQ.add(item7);
		myQ.add(item8);

	}
    writeToFile(output, argv[3]);// write output file.
  } catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
