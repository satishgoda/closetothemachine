layout src
focus cmd

set logging file dlist.txt
set logging overwrite on
set logging on

break main
break DList::DList()
break DList::DList(std::initializer_list<int>)
break DList::handle
break DList::push_back
break DList::push_front(DList::Node*)
break DList::push_front(int)
break DList::reverse
break DList::~DList
break DList::Node::Node
break DList::Node::data
break DList::Node::~Node
break dlist.c:128

info breakpoints

commands 1 2 3 4 5 6 7 8 9 10 11 12 13
where
print *this
end
