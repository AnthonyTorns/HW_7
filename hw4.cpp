/*
PSEUDOCODE:
Insert Helper returnss pointer to a list, takes in two list, a empty list and int value n
n = the amount of elements being inserted first from the first element
if n = 0 { 
  if second list is empty{
    if first list is empty{
    return the inserted list
    }
    inserted list = a new list composed of first element first and inserted list
    first = the rest of first list
    recursive call to insert helper
  }
  inserted = new list made up of first elemeent of second and amd inserted 
  second list =  the rest of the second list
  recursive call to Insert Helper
}
inserted = new list of first element and inserted list
first = the rest of first
de-increment n

insert_list: returns a list take in two list and int n
make int variable pointer for size size 
 make a new list 
 find the size of the second list 
 if n > size{
 call the append function 
}
call Insert Helper


SumHelper: returns int takes in a list and int to hold the sum 
if list is emepty {
  return the sum
}
sum  = sum + first elemernt of the list
list = the rest of the list 
recursive call to SumHelper

sum: returns an int takes in a list
int intialized to 0
if the list is empty {
return zero
}
return value of SumHelper

ProductHelepr: returns int takes in a list and int to hold the product
if list is emepty {
  return the sum
}
product = product * first elemernt of the list
list = the rest of the list 
recursive call to ProductHelper

product: returns an int takes in a list
if the list is empty {
return 1
}
else {
  int initialized to the first element of the list 
  list = the rest of the list
}
return value of ProductHelper

ListSize returns pointer to int  takes in a list and an int
if list is empty{
  return int pointer 
}
else {
 value of int pointer is incremented
 recursive cal to List Size but list is adjusted to the remaining parts of the list
}

Rotate Helper returns list takes in two list and unsigned int
  make new list 
  if the amount of roations is zero { 
    rotated list calls reverse function taking in roatated list
    return value of the append function 
  }
  rotated = newlist with the first element of the original and stored into rotated 
  original = rest of list besides first element 
  recursive call to Rotate Helper

rotate returns a list takes in a list and unsigned int with num of rotations 
  if list is empty return the list 
  int intialized to zero 
  find size 
  make new list 
  if size is grater than the num of rotations {
    return RotateHelper w list, new list and rotations 
  }
  return RotatHelper 



ChopHelper takes in tow list and an int retunrns a list
if count is equal rto zero 
  returrn chopped list 
chopped list = a new list with the first element of original 
original = the rest of the list 
de-increment count and recursively call ChopHelper

chop_pos: returns a list takes in a list and an int 
size and size pointer created 
call to ListSize
create new list 
new list equal return calue of ChopHelper
return calue of reverse


ReverseHelper: returns a list takes in two list 
if the original list is empty 
  return the new list 

int to store the first element of the fisrt element
original list updated with the rest of the list 
nelist is made up of the new list and itself
Recurrsive call to Reversehelper

reverse: returns a list takes in a list 
make a new list 
call reverse helper 
return the newlist 

EvenHelper: returns a list takes in two list
if the original list is empty 
  return the even list 

int to hold the first element of the original list
original updated with the rest of the list 
check if num is even if so store in the even list 
recursive call to EvenHelper

filter_even: returns a list and takes in a list
  make a new list 
  call reverse(EvenHelper)

Oddelper: returns a list takes in two list
if the original list is empty 
  return the odd list 
int to hold the first element of the original list
original updated with the rest of the list 
check if num is odd if so store in the odd list 
recursive call to OddHelper

filter_odd: returns a list and takes in a list
make a new list 
call reverse(OddHelper)

AppendHelper returns a list takes in three list 
if the firs tlist is empty 
  if the second list is empty
    return reversed appended list
  new list made of first element of the secondlist and the appended list
  take rest of second list 
  recursive call 
new liat made of first element of first list and the appended list 
first list updated witht rest of the first list 
recursive call


append: returns a list and takes in two list 
  make new list 
  call to helper function
insert returns a list takes in two list and an interger
size intialised to zero 
size ptr created;
size of list function 
newlist created ;
if(the int passed is less than the size)
  return the list made in the append function 
return the result of the reverse of the insert helper function

  FilterHelper returns a list takes in two list and a bool function pointer
  if the original list is empty 
    return the revrese list of the filtred list 
  store first elemetn of the original list 
  update the original list with the rest of its list 
  if the function pointer return value is true 
    add to filter list 
  recursive call
filter returns a list 
new list made 
call the helper 

accumulate returns a int takes in a list int function pointer with two int praameters and amother int 
if the list is empty return the int 
recursive call

Fib_tail uses tail recursion to solve fibbonacci sequence 
  if the the sequence number is less than 1 return the sequence number 
    collect sum of num1 and 2 
    num2 equals num1 
    second number is stored as well as the sum
    recursive call

fib:
  if the sequence number is zero return 0
  else if the sequence number is 1 
  return 1
  first num is zero 
  second num is zero 
  sum is 0 
  call to the fib tail helper function 

fib does not use tail recursion 
uses same base cases as tail version 
return fib(n-1) and fib(n-2)
*/


#include "hw4.h"
#include "recursive.h"
#include <iostream>

int* ListSize(list_t list, int *count) {
  
  if (list_isEmpty(list)) {
    return count;
  }
  else{
    *count = *count + 1;
      return(ListSize(list_rest(list), count));
  }
}

list_t InsertHelper(list_t first, list_t second, list_t inserted, int n) {
  if (n==0) {
    if (list_isEmpty(second)) {
      if (list_isEmpty(first)) {
        return inserted;
      }
      inserted = list_make(list_first(first), inserted);
      first = list_rest(first);
      return InsertHelper(first, second, inserted, n);
    }
    inserted = list_make(list_first(second), inserted);
    second = list_rest(second);
    return(InsertHelper(first, second, inserted, n));
  }
  inserted = list_make(list_first(first), inserted);
  first = list_rest(first);
  n--;
  return InsertHelper(first, second, inserted, n);



}
int SumHelper(list_t list, int sum) {
  if (list_isEmpty(list)) {
    return sum;
  }
  sum += list_first(list);
  list = list_rest(list);
  return SumHelper(list, sum);
}

int sum(list_t list) {
  int num = 0;
  if (list_isEmpty(list)) {
    return 0;
  }
  return SumHelper(list, num);
}

int ProductHelper(list_t list, int product) {
  if (list_isEmpty(list)) {
    return product;
  }
  product *= list_first(list);
  list = list_rest(list);
  return ProductHelper(list, product);
}

int product(list_t list) {
  if (list_isEmpty(list)) {
    return 1;
  }
  int num = list_first(list);
  list = list_rest(list);
  
  return ProductHelper(list, num);
}

list_t RotateHelper(list_t original, list_t rotated, unsigned int rotations) {
  list_t newlist = list_make();
  if (rotations == 0) {
    original = reverse(original);
    
    return InsertHelper(original, rotated, newlist, rotations);

  }
  rotated = list_make(list_first(original), rotated);
  original = list_rest(original);
  rotations--;
  return RotateHelper(original, rotated, rotations);
}

list_t rotate(list_t list, unsigned int n) {
if (list_isEmpty(list)) {
  return list;
}
int size = 0;
ListSize(list, &size);
list_t newlist = list_make();
if (size > n) {
  return RotateHelper(list, newlist, n);
}
return RotateHelper(list, newlist,n - size);
}



list_t ChopHelper(list_t original, list_t chopped_list, int count) {
  if (count == 0) {
    return chopped_list;
  }
  chopped_list = list_make(list_first(original), chopped_list);
  original = list_rest(original);
  count--;
  return ChopHelper(original, chopped_list, count);
}
list_t chop(list_t l, unsigned n) {
  int size = 0;
  int* sizeptr = &size;
  ListSize(l, sizeptr);
  //list_t testlist_T = l;
  if (size < n) {
    return l;
  }
  int chop_pos = size - n;
  list_t newlist = list_make();
  newlist = ChopHelper(l, newlist, chop_pos);
  return reverse(newlist);
}

list_t ReverseHelper(list_t originallist_t, list_t newlist_t) {
  if (list_isEmpty(originallist_t)) {
    return newlist_t;
  }
  int element = list_first(originallist_t);
  originallist_t = list_rest(originallist_t);
  newlist_t  = list_make(element, newlist_t);
  return ReverseHelper(originallist_t, newlist_t);
}

list_t reverse(list_t list) {
  list_t newlist = list_make();
  newlist = ReverseHelper(list, newlist);
  return(newlist);

}
list_t EvenHelper(list_t original, list_t even) {
  if (list_isEmpty(original)) {
    return even;
  }
  int num = list_first(original);
  original = list_rest(original);
  if (num%2 == 0) {
    even = list_make(num, even);
  }
  return EvenHelper(original, even);
}

list_t filter_even(list_t list) {
  list_t newlist = list_make();
  return reverse(EvenHelper(list, newlist));
}

list_t OddHelper(list_t original, list_t odd) {
  if (list_isEmpty(original)) {
    return odd;
  }
  int num = list_first(original);
  original = list_rest(original);
  if (num%2 != 0) {
    odd = list_make(num, odd);
  }
  return OddHelper(original, odd);
}

list_t filter_odd(list_t list) {
  list_t newlist = list_make();
  return reverse(OddHelper(list, newlist));
}

list_t AppendHelper(list_t first, list_t second, list_t append) {
  if (list_isEmpty(first)) {
    if (list_isEmpty(second)) {
      return reverse(append);
    }
    append = list_make(list_first(second), append);
    second = list_rest(second);
    return AppendHelper(first, second, append);
    
  }
  append = list_make(list_first(first), append);
  first = list_rest(first);
  return AppendHelper(first, second, append);
}

list_t append(list_t first, list_t second) {
  list_t newlist = list_make();
  return AppendHelper(first, second, newlist);
}

list_t insert_list(list_t first, list_t second, unsigned int n) {
  int size = 0;
  int* sizeptr = &size;
  list_t newlist = list_make();
  ListSize(first, sizeptr);
  
  if (n > size) {
    return append(first, second);
  }
  return reverse(InsertHelper(first, second, newlist, n));

  
}

list_t FilterHelper(list_t original, list_t filtered, bool(*fn)(int)) {
  if (list_isEmpty(original)) {
    return reverse(filtered);
  }
  int num = list_first(original);
  original = list_rest(original);
  if (fn(num)) {
    filtered = list_make(num, filtered);
  }
  return FilterHelper(original, filtered, fn);
}

list_t filter(list_t list, bool(*fn)(int)) {
  list_t newlist = list_make();
    return FilterHelper(list, newlist, fn);
}

int accumulate(list_t list, int(*fn)(int x, int y), int identity) {
  if (list_isEmpty(list)) {
    return identity;
  }
  return fn(list_first(list), accumulate(list_rest(list), fn, identity));
}

int Fib_Tail_Helper(int n, int num1, int num2, int fib_sum) {
  if (n < 1) {
    return num1;
  }
  fib_sum = num1 + num2;
  num1 = num2;
  num2 = fib_sum;
  n--;
  return Fib_Tail_Helper(n, num1, num2, fib_sum);
}

int fib_tail(int num) {
  if (num == 0) {
    return 0;
  }
  else if (num == 1) {
    return 1;
  }
  int firstnum = 0;
  int secondnum = 1;
  int fib_sum = 0;
  return Fib_Tail_Helper(num, firstnum, secondnum, fib_sum);
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }

  return fib(n-1) + fib(n-2);
}
/*
int Fibonacci_Tail_Helper(tree_t lefttree, tree_t rigthttree, tree_t newtree, int n){
  if(n <= 1){
    return tree_elt(newtree);
  }
  int num = tree_elt(lefttree) + tree_elt(rigthttree);
  newtree = tree_make(num, lefttree, rigthttree);
  lefttree =rigthttree;
  rigthttree = newtree;
  n--;
  return Fibonacci_Tail_Helper(lefttree, rigthttree, newtree,n );
}
int fib_tail(int n){
 if(n ==0)
    return 0;
  
  if (n == 1)
    return 1;

  tree_t zerotree = tree_make(0, tree_make(), tree_make());
  tree_t onetree = tree_make(1, tree_make(), tree_make());
  tree_t newtree = tree_make();
  return Fibonacci_Tail_Helper(zerotree, onetree, newtree,n);
  return  0;                           
}
*/

