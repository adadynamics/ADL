

fn main()->int:

    puts("hello world")


    puts("bad compiler")
    return 110 + 90
:



struct Test:
    int age
:

impl Test:
    fn __init__(Test s,int x)->Test:
        int age = x
        return s
    :


    fn __fini__()->void:
        return
    :

    fn add(int x,int y)->int:
        return x + y
    :
:
fn add(int x,int y)->int:
    return x + y
:

fn test()->void:
    Test t
    Test t1
    add(7,8)
    int i = add(7,8)
    int z = add(add(7,9),add(i,add(1,i)))
    Test tt = Test::new(z)
    tt.add(7,8)
    int x = Test::add(i,z)
    tt.age
: