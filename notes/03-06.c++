// -----------
// Mon,  6 Mar
// -----------

int s = ...;
T   v = ...;

T* a = new T[s];   // T(),  s times
fill(a, a + s, v); // =(T), s times
...
delete [] a;       // ~T(), s times

allocator<T> x;
T* a = x.allocate(s);      // <nothing>
loop                       // T(T), s times
    x.construct(&a[i], v);
...
loop                       // ~T(), s times
    x.destroy(&a[i]);
x.deallocate(a);           // <nothing>

my_allocator<double, 100> x;
T* a = x.allocate(5);      // <nothing>
loop                       // T(T), s times
    x.construct(&a[i], v);
...
loop                       // ~T(), s times
    x.destroy(&a[i]);
x.deallocate(a);           // <nothing>
