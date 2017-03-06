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
