// Exercise 2.6 from CtCI p.95
// Check to see if two lists intersect
// Timothy Devon Morris
// Mon Jun  1 15:45:29 UTC 2020

/**
 * BCR is O(N + M)
 * The basic concept is iterate to the end and make sure they have to same
 * end. Intersecting lists will do this. As this is done determine the size
 * of the lists. Chop off the difference between the two lists from the longer
 * list and then iterate until the lists are equal. That's the solution!
 */
