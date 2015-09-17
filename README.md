# hps
High Peformance String (functions)

HPS is a php extension designed to be used with large scale data set.
Most of the functions implemented are regular string functions, such as strpos, applied to array.
Nothing you couldn't do in raw php, it just hundred times faster, which is totally unsignificant in daily cases,
but means hours when you work with a lot of data.

This extension does not intend to rewrite string functions algorithms but mostly provide faster internal looping over array using php internal functions.

This is under developement. Use at your own risk.

Functions I'm working on :

- array_pos_grep(string haystack, array needle) :  Return needles that can be find into the haystack. Uses strpos. 
- array_pos(string haystack, array needle) : Return the array key of the first needle found into the haystack, false if none found.
