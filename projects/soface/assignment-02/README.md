# SOFACE Assignment 2
You are given two implementations of a ShoeShop data structure. One direct implementation (../ShopOrg)
and one using an abstract class to achieve polymorphism (../ShopAbs). The class has a collection
of function members to modify and query the state of a shop. You are not required to
understand what the code is about. Only the structuring of the code and its representation
in C are important. (So now you got to recall the C you have learned from the last semester.)


**Exercise (a)** Implement the code of ShopOrg in C using structs instead of classes.
This code directly links the functions to the ShopOrg class. 
No function pointers are required (but could be used, of course).

**Exercise (b)** Implement the code of ShopAbs in C emulating the polymorphism provided
by means of the abstract class Shop. In this implementation function pointers 
are required. They need to be implemented as members of the struct Shop.
The implementation of ShoeShop must declare the function pointers in exactly 
the same order. A type cast to '(Shop*)' needs to be used to use a ShoeShop via
a Shop pointer:

ShoeShop* shoeshop = malloc(sizeof(ShoeShop));

// do something with shoeshop

Shop* shop = (Shop*) shoeshop;

// do something with shop
