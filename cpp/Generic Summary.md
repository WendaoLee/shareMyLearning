# Generic Summary

> This is the **generic summary**,a review of what I have learned and some of my thoughts from *A Tour of C++*.It mainly focuses on what I think should be taken care of.

## 1.0 Chap 1

Chapter 1,*The Basics*,most of it is (almost) insignificant for guys who had learned programming language.The things should be focused on are:

1. Pointer
2. Reference
3. `const` and `constexpr`
4. auto

### 1.1&1.2 Pointer and Reference

The pointer is the most intriguing thing in the C++.I loved it.

It is clear but should be emphasized:

> For a pointer named 'p'
>
> p stored the target object's address.
>
> *p operates the target object

The **advice** listed at the end of chapter is useful and valuable.I take down some of it:

> [28]Keep use of pointers simple and straightforward.

The differences between Pointer and Reference are:

1. No null reference but exists null pointer.
2. When reference created,it unswervingly follow its target object.But the pointer can change.
3. Reference should be initialized when declared.

> For `int i = 0;`
>
> Reference:`int& r = i;`
>
> Pointer:`int* p = &i;`

**Please remember** : Pass an array as arguments to function is created a reference in the function's scope.

For Instance:

```c++
int k[3] = {1,2,3};

show_referenceInFuctionArguments(k);
```

```c++
show_referenceInFuctionArguments(int x[])
{
	//It create a reference named x in its scope
	//The change of x actually changes k.
	x[0] = 100; //In reality,it is k[0] = 100;
}
```

If you just want array read-only,please use `const`:

```C++
show_referenceInFuctionArguments(const int x[])
```

### 1.3 `const`&`constexpr`

