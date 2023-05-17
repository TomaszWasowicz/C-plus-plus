const int x;    // this const applies to x, so it is top-level
int* const ptr; // this const applies to ptr, so it is top-level

const int& ref; // this const applies to the object being referenced, so it is low-level
const int* ptr; // this const applies to the object being pointed to, so it is low-level

const int* const ptr; // the left const is low-level, the right const is top-level