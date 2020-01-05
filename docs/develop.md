# add git submodule

``` bash
$ git submodule add git://some_repository.git some_repository
```

# update git submodule


``` bash
$ cd submodule
$ git checkout v2.4.3
```


# wrapping cgal video

https://www.youtube.com/watch?v=YReJ3pSnNDo
code:
https://github.com/rob-smallshire/mesher

print out the return type:

https://stackoverflow.com/a/20170989/107907

m.def("print_faces_iterator_value_type", [](){
    std::cout << type_name<CDT::Finite_faces_iterator::value_type<();
});

