# C-linked-list

Made as homework for cs comp arch class

C program that maintains and manipulates a sorted linked list according to instructions
received from standard input. The linked list is maintained in order, meaning that the items in the
list are stored in increasing numeric order after every operation.

List supports two operations:
insert n adds an integer n to the list. If n is already present in the list, it does nothing. The
instruction format is an i followed by a space and an integer n.
delete n removes an integer n from the list. If n is not present in the list, it does nothing. The
instruction format is a d followed by a space and an integer n.
After each command, list will print the length of the list followed by the contents of the list, in
order from first (least) to last (greatest)

Input format: Each line of the input contains an instruction. Each line begins with a letter (either
“i” or “d”), followed by a space, and then an integer. A line beginning with “i” indicates that the
integer should be inserted into the list. A line beginning with “d” indicates that the integer should
be deleted from the list
