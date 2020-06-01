// Exercise 2.6 from CtCI p.95
// Check to see if linked list is palindrome
// Timothy Devon Morris
// Mon Jun  1 15:45:44 UTC 2020

/**
 * BCR is O(N)
 * You use the tortise and hare algorithm for this one. Since I don't have more fine grained control of the C++ list, I won't be doing this one in code.
 * Set two iterators to the beginning, increment one twice as fast as teh other
 * When they meet, set the slower iterator to the beginning and increment both at a speed of 1 until they meet.
 * That is the beginning of the loop
 */
