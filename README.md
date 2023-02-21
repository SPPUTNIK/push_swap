
Introduction    :

      The Push swap project is a very simple and a highly straightforward algorithm project:
      
      data must be sorted.
      
      You have at your disposal a set of integer values, 2 stacks, and a set of instructions
      
      to manipulate both stacks.
      
      Your goal? Write a program in C called push_swap which calculates and displays
      
      on the standard output the smallest program, made of Push swap language instructions,
      
      that sorts the integers received as arguments.
      
      Easy?
      
      We’ll see...
      
      
 Description   :

    This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves.
    
    To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.
    
    
 
 The rules    :

    • You have 2 stacks named a and b.
    
    • At the beginning:
    
        ◦ The stack a contains a random amount of negative and/or positive numbers

        which cannot be duplicated.

        ◦ The stack b is empty.
    
    • The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal    :
    
        sa (swap a): Swap the first 2 elements at the top of stack a.

        Do nothing if there is only one or no elements.

        sb (swap b): Swap the first 2 elements at the top of stack b.

        Do nothing if there is only one or no elements.

        ss : sa and sb at the same time.

        pa (push a): Take the first element at the top of b and put it at the top of a.

        Do nothing if b is empty.

        pb (push b): Take the first element at the top of a and put it at the top of b.

        Do nothing if a is empty.

        ra (rotate a): Shift up all elements of stack a by 1.

        The first element becomes the last one.

        rb (rotate b): Shift up all elements of stack b by 1.

        The first element becomes the last one.

        rr : ra and rb at the same time.

        rra (reverse rotate a): Shift down all elements of stack a by 1.

        The last element becomes the first one.

        rrb (reverse rotate b): Shift down all elements of stack b by 1.

        The last element becomes the first one.

        rrr : rra and rrb at the same time.
    
 

Example     :

To illustrate the effect of some of these instructions, let’s sort a random list of integers.

In this example, we’ll consider that both stacks grow from the right.

    ----------------------------------------------------------------------------------------------------------
    Init a and b:
    2
    1
    3
    6
    5
    8
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec sa:
    1
    2
    3
    6
    5
    8
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec pb pb pb:
    6 3
    5 2
    8 1
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec ra rb (equiv. to rr):
    5 2
    8 1
    6 3
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec rra rrb (equiv. to rrr):
    6 3
    5 2
    8 1
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec sa:
    5 3
    6 2
    8 1
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------
    Exec pa pa pa:
    1
    2
    3
    5
    6
    8
    _ _
    a b
    ----------------------------------------------------------------------------------------------------------

Integers from a get sorted in 12 instructions. Can you do better?


Your project must comply with the following rules   :

    • You have to turn in a Makefile which will compile your source files. It must not relink.
    
    • Global variables are forbidden.
    
    • You have to write a program named push_swap that takes as an argument the stack
    
      a formatted as a list of integers. The first argument should be at the top of the
    
      stack (be careful about the order).
    
    • The program must display the smallest list of instructions possible to sort the stack a, the smallest
    
      number being at the top.
    
    • Instructions must be separated by a ’\n’ and nothing else.
    
    • The goal is to sort the stack with the lowest possible number of operations. During
    
      the evaluation process, the number of instructions found by your program will be
      
      compared against a limit: the maximum number of operations tolerated. If your
    
      program either displays a longer list or if the numbers aren’t sorted properly, your
    
      grade will be 0.
    
    • If no parameters are specified, the program must not display anything and give the
    
      prompt back.
    
    • In case of error, it must display "Error" followed by a ’\n’ on the standard error.
      
      Errors include for example: some arguments aren’t integers, some arguments are
      
      bigger than an integer and/or there are duplicates.
      
      
        $>./push_swap 2 1 3 6 5 8
          sa
          pb
          pb
          pb
          sa
          pa
          pa
          pa
          $>./push_swap 0 one 2 3
          Error
          $>
