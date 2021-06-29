class List:
    def __init__(self, first, last):
        self.first = first;
        self.current = first;
        self.last = last;
     
        
    def __iter__(self):
        return self;
        
    def __next__(self):
        if(self.current > self.last):
            self.current = self.first;
        
        self.current += 1;
        return self.current - 1;
        
Numbers = List(8, 12);

print(next(Numbers));
print(next(Numbers));
print(next(Numbers));
print(next(Numbers));
print(next(Numbers));
print(next(Numbers));
