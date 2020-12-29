/*
define struct to hold the key and hash value 
define a node for marking the collisions 

coll test: 
for ( i < the first hash table vec size )
hash position value = the hash tables hash at the given poisition
if the value of the hash_value of the coll_node is negativethe position in the table is empty 
  place the hash value from the table to collision table for testing 
else
  find the end of the linked list of a given position at the collision hash table(while loop)
  once found create a new node at the end of the linked list 
  store hash value from hash_table1
  hash_table.ext is set to nullptr to mark end of linked list 
  increment the number of collisions 
*do the same for the second hash_table
  return the amount of collisions

Is Prime returns a bool 
if number is less than one 
  return false
if the number is divisible by any number from 2 to n then the number is not prime 
  other wise true is returned

differential 
for (i < size of table passed in)
  diff is the the absolute value of the difference between the old and new code 
  difference vector is updated with this value at the given position 
  update the list with the rest of the list 
return the vec 

hash_function1
  store fibanocci value  using tail recursive function
  hash vakue fib plus the sum of the list
  return the hash value

oddhashfunction
  store product of all odd values 
   create odd hashtable
   for (list is not empty)
     increase size of the vector 
     store key
     store key + odd prod
     odd list is updated with the rest of the list
  return the odd_hash table 

evenhashfunc
creted even hash table
for (i < odd hashtable size)
  if the hash value is not prime
  add to the non prime sum 
for (even list is not empty)
  resize hashtable by +1 
  store key 
  store k + non_prime sum 
  update the rest of the even list 
  return the hash table

  hashfunction2
    hashtable with the size of the even + odd hash tables size 
    for ( i < the size of the combined hash table)
      places hash values in order based on keys
    return the hash table


main:
  prompt for the amoutn of keys and store 
  use for loop to store n number of keys 
  and store in a list 
  reverse the list to put in order that the user entred them
  
  create a second version of the list 
  hash table created with a size = to the number of keys
  store sum of all keys 

  forr loop to store keys and hash values for hash function 1
  print values of hash 1 

  prompt for old code hash values to be entred into  list
  reverse list to place oldcode hashvalues in order 
  create vector for the differences in the old code 
  print differential using for loop 
  
  // hash test 2
  odd list created 
  even list created 
  odd hash function called and perfomed 
  even hash function performed 
  hashfunction callled and performed 

  print out values of hash table 2

 old code hash value are entered to test for differential 
 differential function performed 

differential vector contents printed


part 2
table made with bucket size of 16
cooltest called and stored for new code 
clear table and repeat process for old code 
collision printed


    

*/

#include <iostream>
#include "hw4.h"
#include "recursive.h"
#include <cmath>
#include <vector>

struct node{
  int key;
  int hash;
}hash_key;

struct coll_node {
  int hash_val = -1;
  coll_node* next;
};

int Coll_Test(std::vector<node> hash_1, std::vector<node> hash_2, std::vector<coll_node> &coll_hash) {
  int collisions = 0;
  int pos = 0;
  for (int i = 0; i < hash_1.size();i++) {
    pos = hash_1[i].hash%16;
     if (coll_hash[pos].hash_val == -1) {
    coll_hash[pos].hash_val = hash_1[i].hash;
    }
    else {
      while (coll_hash[pos].next) {
        coll_hash[pos].next = coll_hash[pos].next->next;
      }
      coll_hash[pos].next = new coll_node;
      coll_hash[pos].next->hash_val = hash_1[i].hash;
      coll_hash[pos].next->next = nullptr;
      collisions++;
    }
  }

  for (int i = 0; i < hash_1.size();i++) {
    pos = hash_2[i].hash%16;
     if (coll_hash[pos].hash_val == -1) {
    coll_hash[pos].hash_val = hash_1[i].hash;
    }
    else {
      while (coll_hash[pos].next) {
        coll_hash[pos].next = coll_hash[pos].next->next;
      }
      coll_hash[pos].next = new coll_node;
      coll_hash[pos].next->hash_val = hash_2[i].hash;
      coll_hash[pos].next->next = nullptr;
      collisions++;
    }
  }
  return collisions;
}

bool IsPrime(int number ) {
   if (number <= 1) {
    return false;
  }
  bool prime = true;
  for ( int i = 2; i < number; i++) {
     if (number%i == 0) {
      prime = false ;
      return prime;
    }
  }
  return prime;
}

std::vector<int> Diff(std::vector<node> table, list_t input) {
  std::vector<int> diff_vec(table.size());
  for (int i = 0; i < table.size(); i++) { 
    int diff = abs(table[i].hash - list_first(input));
    diff_vec[i] = diff;
    input = list_rest(input);
  }
  return diff_vec;
}

int Hash_Function1(list_t l, int k_sum) {
  int fib = fib_tail(list_first(l));
  int hash_value = fib + k_sum;
  return hash_value;
}

std::vector<node> Odd_Hash_Func(list_t odd) {
  int odd_prod= product(odd);
  std::vector<node> odd_hash_table;
  for (int i = 0; !list_isEmpty(odd); i++) {
    odd_hash_table.resize(i+1);
    odd_hash_table[i].key = list_first(odd);
    odd_hash_table[i].hash = odd_hash_table[i].key + odd_prod;
    odd = list_rest(odd);
  }
  return odd_hash_table;;
}

std::vector<node> Even_Hash_Func(std::vector<node> oddhash, list_t even) {
  int non_prime_sum = 0;
  std::vector<node> even_hash_table;
  for (int i = 0; i < oddhash.size(); i++) { 
     if (!IsPrime(oddhash[i].hash)) {
      non_prime_sum += oddhash[i].hash;
    }
  }
  
  for (int i = 0; !list_isEmpty(even); i++) {
    even_hash_table.resize(i+1);
    even_hash_table[i].key = list_first(even);
    even_hash_table[i].hash = even_hash_table[i].key + non_prime_sum;
    even = list_rest(even);
  }
  
  return even_hash_table;
}

std::vector<node> Hash_Function2(std::vector<node> odd_t, std::vector<node> even_t) {
  std::vector<node> h_table(odd_t.size() + even_t.size());
  int o = 0, e = 0;
  for (int i = 0; i < h_table.size(); i++) {
     if (odd_t[o].key < even_t[e].key && o < odd_t.size()) {
      h_table[i].key = odd_t[o].key;
      h_table[i].hash = odd_t[o].hash;
      o++;
    }
    
    else {
      h_table[i].key = even_t[e].key;
      h_table[i].hash = even_t[e].hash;
      e++;
    }
  }
  return h_table;
}
int main() {
  //hash test 1
  std::cout<<"Enter the amount of Keys: ";
  int keys;
  std::cin>>keys;
  list_t list = list_make();
  for (int i = 0;i <keys;i++) {
    std::cout<<"Enter key #"<<i+1<<" ";
    int key = 0;
    std::cin>>key;
    list = list_make(key, list);
  }
  list = reverse(list);
  list_t list2 = list;
  std::vector<node> hash_table1(keys);
  int key_sum = sum(list);
  
  for (int j = 0; j < keys; j++) {
  hash_table1[j].key = list_first(list);
  hash_table1[j].hash = Hash_Function1(list, key_sum);
  list = list_rest(list);
  }

  std::cout<<"Hash Test 1: (";
  for (int x = 0; x < hash_table1.size(); x++) {
    std::cout<<hash_table1[x].hash;
     if ( x < hash_table1.size() - 1) {
      std::cout<<",";
    }
  }
  
  std::cout<<")\nEnter the old code hash values: \n";
  std::vector<node>old_code1 (keys); 

  list_t test_list1 = list_make();
  for (int i = 0; i < keys; i++) { 
    std::cout<<"Enter hash #"<<i+1<<" ";
    int hash= 0;
    std::cin>>hash;
    test_list1 = list_make(hash, test_list1);
   // test_list1 = list_make(hash, test_list1);
    old_code1[keys-(i+1)].key = keys - i;
    old_code1[keys-(i+1)].hash = list_first(test_list1);
  }
  test_list1 = reverse(test_list1);
  std::vector<int> differential1 = Diff(hash_table1,test_list1);

  std::cout<<"Differential Test 1: (";
  for (int x = 0; x < differential1.size(); x++) {
    std::cout<<differential1[x];
     if ( x < differential1.size() - 1) {
      std::cout<<",";
    }
  }
  std::cout<<") \n\n";


  // hash test 2
  std::vector<node> hash_table2(keys);
  list_t odd_list = filter_odd(list2);
  list_t even_list = filter_even(list2);
  std::vector<node> odd_table = Odd_Hash_Func(odd_list);
  std::vector<node> even_table = Even_Hash_Func(odd_table, even_list);
  hash_table2 = Hash_Function2(odd_table, even_table);
  
  std::cout<<"Hash Test 2: (";
  for (int x = 0; x < hash_table2.size(); x++) {
    std::cout<<hash_table2[x].hash;
     if ( x < hash_table2.size() - 1) {
      std::cout<<",";
    }
  }
  std::cout<<") \nEnter the old code hash values: \n";
  list_t test_list2 = list_make();
  std::vector<node>old_code2 (keys); 
  
  for (int i = 0; i < keys; i++) { 
    std::cout<<"Enter hash #"<<i+1<<" ";
    int hash= 0;
    std::cin>>hash;
    test_list2 = list_make(hash, test_list2);
    old_code2[keys-(i+1)].key = keys - i;
    old_code2[keys-(i+1)].hash = list_first(test_list2);
  }
  test_list2 = reverse(test_list2);
  std::vector<int> differential2 = Diff(hash_table2,test_list2);

  std::cout<<"Differential Test 2: (";
  for (int x = 0; x < differential2.size(); x++) {
    std::cout<<differential2[x];
     if ( x < differential2.size() - 1) {
      std::cout<<",";
    }
  }
  std::cout<<") \n\n";

std::vector<coll_node> coll_table(16);
int new_code_coll = 0, old_code_coll = 0;
new_code_coll = Coll_Test(hash_table1, hash_table2, coll_table);
coll_table.clear();
coll_table.resize(16);
old_code_coll = Coll_Test(old_code1, old_code2, coll_table);
std::cout<<new_code_coll<<" "<<old_code_coll<<std::endl;

  return 0;
}
