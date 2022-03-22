#include <iostream>

/*
    This cpp is just a place experimenting my thought.
*/



/*
    My thought:
        The pointers store the address of its target.So how its address be allocated?
*/
void how_pointers_address_allocated()
{
    /*
        Under the Visual Studio 2019,the address of p1,p2,p3 is logic-consecutitve,that means,for instance:
        +		p1	0x009af96c {0x009af978 {0x00000001}}	int * *
        +		p2	0x009af960 {0x009af97c {0x00000002}}	int * *
        +		p3	0x009af954 {0x009af980 {0x00000003}}	int * *

        They are declared with the 8-bytes-interval undeclared space.Consecutive,but just in the logic.
        It isn't influenced by array's definition.

        It seems that the operating system would like to allocate memory consecutively.

    */

    int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    int *p_ori_first = &x[0];
    int *p_ori_second = &x[1];
    int *p_ori_third = &x[2];
    int *p_ori_forth = &x[3];

    int **p1 = &p_ori_first;
    int **p2 = &p_ori_second;
    int **p3 = &p_ori_third;
    int **p4 = &p_ori_forth;
}

/*
    My thought:
        What differences between reference and pointer?
*/
void reference()
{
/*
    Under the Visual Studio 2019,you will find that the reference likes pointer.It also has a place in memory which store the target's address.
    You can recognize it as a convenient way for programmer to create an alias of target.What different between pointer is that it cannot change in the generic condition.

    The instance of mine:
        +		p	0x00d6f9dc {0x00000001}	int *
        +		point	0x00d6f9dc {0x00000001}	int *
	        	ref	0x00000001	int &
        +		view_p	0x00d6f9b8 {0x00d6f9dc {0x00000001}}	int * *
        +		x	0x00d6f9dc {0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008}	int[0x00000008]
    
    The view_p is tagging p's address.You will easily find at 0x00D6F9AC,there also have a unwatched place stored a address,which target to x[0],that is the ref.
    
*/

    int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    int& ref = x[0];
    int* point = &x[0];

    // int*p = &ref;
    // int**view_p = &p;
}

int main()
{
    int *array = new int[9];
    *array = 1;
    
}